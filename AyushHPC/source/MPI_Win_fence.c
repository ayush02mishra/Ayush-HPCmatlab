/*
	Perform an MPI fence synchronization on a MPI window
        Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Win_fence.html
*/

#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_fence:nrhs","2 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_fence:nlhs","1 output required.");
	}
	/* No support for asserts */	
	plhs[0]=mxCreateDoubleScalar((double)MPI_Win_fence(	
													(int)mxGetScalar(prhs[0]), /* assert */
													(MPI_Win)mxGetScalar(prhs[1]) /*win*/
												    ));
	return; 
}
