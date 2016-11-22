#include <stdio.h>
#include "mex.h"
#include <stdlib.h>
#include "mpi.h"
#include "adios.h"
#include "adios_read_v2.h"
#include <string.h>

uint64_t atouint64(char * str)
{
    uint64_t result=0;
    int ii=0;
    unsigned int len=strlen(str);
    /*
    #ifdef DEBUG
    	printf("%d %s\n",len,str);
    #endif
    */
    for (ii=0;ii<len;++ii)
    {
        result=result*10;
        result=result+str[ii]-'0';//atoi(&str[ii]);
    }
    return result;
}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

    /*
        prhs[0] file name
        prhs[1] variable name
        prhs[2] total size of global array
        prhs[3] offset
        prhs[4] local size
    */
    size_t filelen=mxGetNumberOfElements(prhs[0])+1;
    size_t namelen=mxGetNumberOfElements(prhs[1])+1;
    size_t globallen=mxGetNumberOfElements(prhs[2])+1;
    size_t offsetlen=mxGetNumberOfElements(prhs[3])+1;
    size_t locallen=mxGetNumberOfElements(prhs[4])+1;

    char *file,*name,*global,*offset,*local;

    file=(char *)calloc(filelen,sizeof(char));
    mxGetString(prhs[0],file,filelen);
    name=(char *)calloc(namelen,sizeof(char));
    mxGetString(prhs[1],name,namelen);
    global=(char *)calloc(globallen,sizeof(char));
    mxGetString(prhs[2],global,globallen);
    offset=(char *)calloc(offsetlen,sizeof(char));
    mxGetString(prhs[3],offset,offsetlen);
    local=(char *)calloc(locallen,sizeof(char));
    mxGetString(prhs[4],local,locallen);

    int rank,size,ii;
    char workspace[]="base";
    double *l_pt;

    const mxArray *varpt=mexGetVariablePtr(workspace,name);

    if (varpt==NULL)
    {
        printf("Error: can not find %s in base workspace\n",name);
        return;
    }
    l_pt=(double *)mxGetData(varpt);

    uint64_t start=atouint64(offset), count=atouint64(local);




#ifdef DEBUG
    mexPrintf("filename=%s\n",file);
    mexPrintf("varname=%s\n",name);
    mexPrintf("global_str=%s\n",global);
    mexPrintf("offset_str=%s\n",offset);
    mexPrintf("offset=%ld\n",start);
    mexPrintf("local_str=%s\n",local);
    mexPrintf("local=%ld\n",count);
#endif


    int MPI_flag=0;
    MPI_Initialized(&MPI_flag);
    if (!MPI_flag)
    {
        MPI_Init(0,0);
    }
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    ////////////Equal to adios_init

    ADIOS_FILE *fp;
    ADIOS_VARINFO *v;
    ADIOS_SELECTION * sel;


    adios_read_init_method (ADIOS_READ_METHOD_BP,MPI_COMM_WORLD, "verbose=3");
    fp=adios_read_open_file(file,ADIOS_READ_METHOD_BP,MPI_COMM_WORLD);
    v=adios_inq_var(fp,name);

    sel = adios_selection_boundingbox (v->ndim, &start, &count);
    adios_schedule_read(fp,sel,name,0,1,l_pt);
    adios_perform_reads(fp,1);
    adios_free_varinfo(v);
    adios_read_close(fp);

    MPI_Barrier(MPI_COMM_WORLD);
/*
    for (unsigned int ii=0;ii<count;++ii)
    {
        printf("%g ",l_pt[ii]);
    }
*/
    adios_read_finalize_method (ADIOS_READ_METHOD_BP);
    if (!MPI_flag)
    {
        MPI_Finalize();
    }

    free(file);
    free(name);
    free(global);
    free(offset);
    free(local);

    return;
}

