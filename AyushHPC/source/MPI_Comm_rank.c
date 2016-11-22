/*
        Used to get the rank of each process
        Check link for documentation:
        http://www.mpich.org/static/docs/v3.2/www3/MPI_Comm_rank.html
	The 'rank' output variable is moved to the left in accordance with MATLAB norms
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int rank;
	if(nrhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Comm_rank:nrhs","1 inputs required.");
	}
	if(nlhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Comm_rank:nlhs","2 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Comm_rank(*((MPI_Comm *)mxGetData(prhs[0])),&rank));
	plhs[1]=mxCreateDoubleScalar((double)rank);
	return;
}
