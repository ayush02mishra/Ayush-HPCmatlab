/*
	Get data from a memory window on a remote process
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Get.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
        MPI_Win win = mxGetScalar(prhs[7]);
	if(nrhs!=8) 
	{
		mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","8 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Get(	mxGetData(prhs[0]),  /*origin_addr*/
													(int)mxGetScalar(prhs[1]),  /*origin_count */
													*((MPI_Datatype *)mxGetData(prhs[2])),  /*origin_datatype*/
													(int)mxGetScalar(prhs[3]),  /*target_rank*/
													*((MPI_Aint *)mxGetData(prhs[4])), /*target_disp*/
													(int)mxGetScalar(prhs[5]),  /*target_count*/
													*((MPI_Datatype *)mxGetData(prhs[6])),  /*target_datatype*/
													win /*win*/
												));
	return; 
}
