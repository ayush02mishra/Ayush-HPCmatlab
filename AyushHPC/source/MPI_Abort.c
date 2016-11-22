/*
	Terminates all MPI processes associated with the communicator comm; in most systems (all to date), terminates all processes.
	Check link for documentation
	http://www.mpich.org/static/docs/v3.2/www3/MPI_Abort.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Abort:nrhs","2 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Abort:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Abort(*((MPI_Comm *)mxGetData(prhs[0])),
													(int)mxGetScalar(prhs[1])
													));							
	nlhs=1;
	return;
}
