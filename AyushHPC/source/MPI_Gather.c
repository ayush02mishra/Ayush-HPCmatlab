/*
	Gathers together values from a group of processes
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Gather.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=8) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Gather:nrhs","8 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Gather:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Gather(	mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])),
													mxGetData(prhs[3]),
													(int)mxGetScalar(prhs[4]),
													*((MPI_Datatype *)mxGetData(prhs[5])),
                                                    (int)mxGetScalar(prhs[6]),
													*((MPI_Comm *)mxGetData(prhs[7])) 
												));							
	nlhs=1;
	return;
}
