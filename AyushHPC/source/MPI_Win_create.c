/*
	Create an MPI Window object for one-sided communication
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Win_create.html
	The following variables havee been moved to the left hand side in the same order, to conform with the MATLAB standards:
        win.
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=5) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_create:nrhs","5 inputs required.");
	}
	if(nlhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Win_create:nlhs","2 output required.");
	}
    MPI_Win Win;
	plhs[0]=mxCreateDoubleScalar((double)MPI_Win_create(mxGetData(prhs[0]),     /* *baseptr*/
														  (MPI_Aint)mxGetScalar(prhs[1]),  /*size*/
														  (int)mxGetScalar(prhs[2]),  /*disp_unit*/
														  *((MPI_Aint *)mxGetData(prhs[3])), /*info*/
														  *((MPI_Comm *)mxGetData(prhs[4])), /*comm*/
														  &Win /*win*/
												));

    plhs[1] = mxCreateDoubleScalar(Win);
	return; 
}
