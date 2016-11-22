/*
	Blocks until all processes in the communicator have reached this routine.
        Check link for documentation:
	http://www.mpich.org/static/docs/v3.2/www3/MPI_Barrier.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int size;
	if(nrhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Barrier:nrhs","1 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Barrier:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Barrier(*((MPI_Comm *)mxGetData(prhs[0]))));
	return;
}
