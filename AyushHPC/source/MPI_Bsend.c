/*
	Basic send with user-provided buffering
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1.3/www3/MPI_Bsend.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=6) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Bsend:nrhs","6 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Bsend:nlhs","1 output required.");
	}

	plhs[0]=mxCreateDoubleScalar((double)MPI_Bsend(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])), 
													(int)mxGetScalar(prhs[3]),  
													(int)mxGetScalar(prhs[4]), 
													*((MPI_Comm *)mxGetData(prhs[5])) 
												));	
	return; 
}
