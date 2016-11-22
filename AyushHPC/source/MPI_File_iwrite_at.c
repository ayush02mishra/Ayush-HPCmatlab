/*
	Nonblocking write using individual file pointer
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_File_iwrite.html
	The 'request' output parameter has been move to the left in accordance with the MATLAB norms.
*/
#include "mex.h"
#include "mpi.h"
#include <string.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	MPI_File fh;
	if(nrhs!=5) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_iwrite_at:nrhs","5 inputs required.");
	}
	if(nlhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_iwrite_at:nlhs","2 output required.");
	}
	memcpy(&fh,mxGetData(prhs[0]),sizeof(MPI_File));
    	MPI_Request request;
	plhs[0]=mxCreateDoubleScalar((double)MPI_File_iwrite_at(					fh,  /*file handle*/
													(MPI_Offset)mxGetScalar(prhs[1]),/* offset*/
													mxGetData(prhs[2]), /*buff*/
													(int)mxGetScalar(prhs[3]),  /*count*/
													*((MPI_Datatype *)mxGetData(prhs[4])),  /*datatype*/
												        &request
												));

    	memcpy(mxGetData(prhs[0]),&fh,sizeof(MPI_File));
    	plhs[1] = mxCreateDoubleScalar((double)request);
	return; 
}
