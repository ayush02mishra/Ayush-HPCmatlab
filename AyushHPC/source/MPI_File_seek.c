/*
	Updates the individual file pointer
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_File_seek.html
*/
#include "mex.h"
#include "mpi.h"
#include <string.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	MPI_File fh;
	if(nrhs!=3) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_seek:nrhs","3 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_seek:nlhs","1 output required.");
	}
	memcpy(&fh,mxGetData(prhs[0]),sizeof(MPI_File));
	
	plhs[0]=mxCreateDoubleScalar((double)MPI_File_seek(	fh,  /*file handle*/
													(MPI_Offset)mxGetScalar(prhs[1]),/* offset*/
													(int)mxGetScalar(prhs[2])  /*whence*/
												));
    	memcpy(mxGetData(prhs[0]),&fh,sizeof(MPI_File));
	return; 
}
