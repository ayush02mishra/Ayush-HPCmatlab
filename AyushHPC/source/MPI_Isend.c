/*
        Begins a nonblocking send
        Check documentation at:
        http://www.mpich.org/static/docs/latest/www3/MPI_Isend.html
        The following variables havee been moved to the left hand side in the same order, to conform with the MATLAB standards:
        request.
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=6) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Isend:nrhs","6 inputs required.");
	}
	if(nlhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Isend:nlhs","2 output required.");
	}
	MPI_Request request;
	plhs[0]=mxCreateDoubleScalar((double)MPI_Isend(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])), 
													(int)mxGetScalar(prhs[3]),  
													(int)mxGetScalar(prhs[4]), 
													*((MPI_Comm *)mxGetData(prhs[5])),
													&request
												));	
	plhs[1] = mxCreateDoubleScalar((double)request);
	return; 
}
