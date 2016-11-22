/*
	Put data into a memory window on a remote process
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Put.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

	if(nrhs!=8) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Put:nrhs","8 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Put:nlhs","1 output required.");
	}
	
	plhs[0]=mxCreateDoubleScalar((double)MPI_Put(	mxGetData(prhs[0]),  /*origin_addr*/
													(int)mxGetScalar(prhs[1]),  /*origin_count */
													*((MPI_Datatype *)mxGetData(prhs[2])),  /*origin_datatype*/
													(int)mxGetScalar(prhs[3]),  /*target_rank*/
													*((MPI_Aint *)mxGetData(prhs[4])), /*target_disp*/
													(int)mxGetScalar(prhs[5]),  /*target_count*/
													*((MPI_Datatype *)mxGetData(prhs[6])),  /*target_datatype*/
													*((MPI_Win *)mxGetData(prhs[7])) /*win*/
												));
	return; 
}
