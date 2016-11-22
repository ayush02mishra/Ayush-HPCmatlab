/*
	Gathers data from all tasks and distribute the combined data to all tasks
	Check the documentation at:
	http://www.mpich.org/static/docs/v3.2/www3/MPI_Allgather.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=7) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Allgather:nrhs","7 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Allgather:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Allgather(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])),
													mxGetData(prhs[3]),
													(int)mxGetScalar(prhs[4]),
													*((MPI_Datatype *)mxGetData(prhs[5])),
													*((MPI_Comm *)mxGetData(prhs[6])) 
												));							
	nlhs=1;
	return;
}
