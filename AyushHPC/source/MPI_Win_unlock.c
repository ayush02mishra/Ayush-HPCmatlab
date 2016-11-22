/*
	Completes an RMA access epoch at the target process
        Check documentation at:
        http://www.mpich.org/static/docs/latest/www3/MPI_Win_unlock.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_unlock:nrhs","2 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_unlock:nlhs","1 output required.");
	}
	
	plhs[0]=mxCreateDoubleScalar((double)MPI_Win_unlock(	
													(int)mxGetScalar(prhs[0]), /* rank */
													(MPI_Win)mxGetScalar(prhs[1]) /*win*/
												));

	return; 
}
