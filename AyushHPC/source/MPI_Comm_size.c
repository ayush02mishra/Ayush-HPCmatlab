/*
	Determines the size of the group associated with a communicator
        Check link for documentation:
        http://www.mpich.org/static/docs/v3.2/www3/MPI_Comm_size.html
        The 'size' output variable is moved to the left in accordance with MATLAB norms
*/

#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int size;
	MPI_Comm commtemp;
	if(nrhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Comm_size:nrhs","1 inputs required.");
	}
	if(nlhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Comm_size:nlhs","2 output required.");
	}
	commtemp=*((MPI_Comm *)mxGetData(prhs[0]));
	plhs[0]=mxCreateDoubleScalar((double)MPI_Comm_size(commtemp,&size));
	plhs[1]=mxCreateDoubleScalar((double)size);
	return;
}
