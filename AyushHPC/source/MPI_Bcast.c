/*
	To Broadcast a set of data across all the processes
	Check link for documentation:
	http://www.mpich.org/static/docs/v3.2/www3/MPI_Bcast.html	
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=5) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Bcast:nrhs","5 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Bcast:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Bcast(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])), 
													(int)mxGetScalar(prhs[3]),  
													*((MPI_Comm *)mxGetData(prhs[4])) 
												));		
	return;
}
