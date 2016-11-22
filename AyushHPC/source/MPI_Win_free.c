/*
	Free an MPI RMA window
        Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Win_free.html
*/

#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    MPI_Win win = mxGetScalar(prhs[0]);
	if(nrhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_free:nrhs","1 inputs required.");
	}   
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_free:nlhs","1 output required.");
	}
	
	plhs[0]=mxCreateDoubleScalar((double)MPI_Win_free( &win /*win*/
												    ));
	return; 
}
