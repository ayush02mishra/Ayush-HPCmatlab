/*
	Attaches a user-provided buffer for sending
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_Buffer_attach.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Buffer_attach:nrhs","2 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Buffer_attach:nlhs","1 output required.");
	}
	plhs[0]=mxCreateDoubleScalar((double)MPI_Buffer_attach(	
													mxGetData(prhs[0]),  
													(int)mxGetScalar(prhs[1])
													));	
	double *d = (double *)mxGetData(prhs[0]);
	mexPrintf("\nBuff inside attach:\t%d\t%d\n",d[0],d[1]);
        mexPrintf("\nSize inside attach:\t%d\n",(int)mxGetScalar(prhs[1]));
	return; 
}
