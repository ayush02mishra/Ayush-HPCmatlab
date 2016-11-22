/*
	Begin an RMA access epoch at the target process.
        Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Win_lock.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=4) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_lock:nrhs","4 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_lock:nlhs","1 output required.");
	}
/* No support for asserts */	
	plhs[0]=mxCreateDoubleScalar((double)MPI_Win_lock(	
													(int)mxGetScalar(prhs[0]), /* lock_type */
													(int)mxGetScalar(prhs[1]), /* rank */
													(int)mxGetScalar(prhs[2]), /* assert */
													(MPI_Win)mxGetScalar(prhs[3]) /*win*/
												));

	return; 
}
