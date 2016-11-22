#include <stdio.h>
#include "mex.h"
#include <stdlib.h>
#include "mpi.h"
#include "adios.h"
#include "adios_types.h"
#include <string.h>
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
	
	#ifdef DEBUG
	mexPrintf("%s\n",file);
	mexPrintf("%s\n",name);
	mexPrintf("%s\n",global);
	mexPrintf("%s\n",offset);
	mexPrintf("%s\n",local);
	#endif
	
	

	
	char workspace[]="base";
	int rank,size;
	double *l_pt;
	int64_t m_adios_group,m_adios_file,adios_varid;
	uint64_t adios_groupsize,adios_totalsize;
	const mxArray *varpt=mexGetVariablePtr(workspace,name);
	l_pt=(double *)mxGetData(varpt);
	
	
	int MPI_flag=0;
	MPI_Initialized(&MPI_flag);
	if(!MPI_flag)
	{
		MPI_Init(0,0);
	}
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);


////////////Equal to adios_init
	adios_init_noxml(MPI_COMM_WORLD);
	adios_allocate_buffer(ADIOS_BUFFER_ALLOC_NOW,10);
	adios_declare_group(&m_adios_group,"saveadios","",adios_flag_no);
	
	
	//adios_select_method(m_adios_group,"MPI","","");
	//adios_select_method(m_adios_group,"MPI_LUSTRE", \
	//"stripe_count =32 , stripe_size =10485760 , block_size =41943040","");
	adios_select_method(m_adios_group,"MPI_LUSTRE","","");
	
	
	adios_varid=adios_define_var(m_adios_group,name,"",adios_double,local,global,offset);
	adios_open(&m_adios_file,"saveadios",file,"w",MPI_COMM_WORLD);
	adios_groupsize=mxGetNumberOfElements(varpt)*8;
	adios_group_size(m_adios_file,adios_groupsize,&adios_totalsize);
	
	adios_write_byid(m_adios_file,adios_varid,l_pt);

	adios_close(m_adios_file);
	
	
	
	MPI_Barrier(MPI_COMM_WORLD);
	adios_finalize(rank);
	if(!MPI_flag)
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
