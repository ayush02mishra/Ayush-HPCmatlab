/*
 *  Currently does not support arguments
 *  Check the documentation at:
 *  http://www.mpich.org/static/docs/latest/www3/MPI_Init.html
 */

#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int rank,size;
	if(nrhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Init:nrhs","2 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Init:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Init(0,0));
	nlhs=1;
	return;
}
