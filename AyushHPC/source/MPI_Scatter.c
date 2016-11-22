/*
	Sends data from one process to all other processes in a communicator
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Scatter.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=8) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Scatter:nrhs","8 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Scatter:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Scatter(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])),
													mxGetData(prhs[3]),
													(int)mxGetScalar(prhs[4]),
													*((MPI_Datatype *)mxGetData(prhs[5])),
                                                    (int)mxGetScalar(prhs[6]),
													*((MPI_Comm *)mxGetData(prhs[7])) 
												));							
	return;
}
