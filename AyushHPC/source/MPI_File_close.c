/*
	Closes a file
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_File_close.html
*/
#include "mex.h"
#include "mpi.h"
#include <string.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	MPI_File fh;
	
	if(nrhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_close:nrhs","1 input required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_close:nlhs","1 output required.");
	}
	memcpy(&fh,mxGetData(prhs[0]),sizeof(MPI_File));
	
	plhs[0]=mxCreateDoubleScalar((double)MPI_File_close(
								                        &fh /*MPI_File*/
								                    ));

    	memcpy(mxGetData(prhs[0]),&fh,sizeof(MPI_File));
	return; 
}
