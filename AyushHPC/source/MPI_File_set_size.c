/*
	Sets the file size
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_File_set_size.html
*/
#include "mex.h"
#include "mpi.h"
#include <string.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    MPI_File fh;
    if(nrhs!=2)
    {
        mexErrMsgIdAndTxt("HPCmatlab:http:MPI_File_set_size:nrhs","2 inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("HPCmatlab:http:MPI_File_set_size:nlhs","1 output required.");
    }
    memcpy(&fh,mxGetData(prhs[0]),sizeof(MPI_File));

    plhs[0]=mxCreateDoubleScalar((double)MPI_File_set_size( fh,  /*file handle*/
                                                    (MPI_Offset)mxGetScalar(prhs[1]) /* size */
                                                ));

    memcpy(mxGetData(prhs[0]),&fh,sizeof(MPI_File));

    nlhs=1;
    return;
}
