/*
	Performs a blocking send
        Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Send.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=6) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Send:nrhs","6 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Send:nlhs","1 output required.");
	}

	plhs[0]=mxCreateDoubleScalar((double)MPI_Send(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])), 
													(int)mxGetScalar(prhs[3]),  
													(int)mxGetScalar(prhs[4]), 
													*((MPI_Comm *)mxGetData(prhs[5])) 
												));	
	
	nlhs=1;
	return; 
}
