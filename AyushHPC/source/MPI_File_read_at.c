/*
	Read using explicit offset
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_File_read_at.html
*/
#include "mex.h"
#include "mpi.h"
#include <string.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	MPI_Status status;
	MPI_File fh;
	if(nrhs!=6) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_read_at:nrhs","6 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_File_read_at:nlhs","1 output required.");
	}
	memcpy(&fh,mxGetData(prhs[0]),sizeof(MPI_File));
	
	plhs[0]=mxCreateDoubleScalar((double)MPI_File_read_at(	fh,  /*file handle*/
													(MPI_Offset)mxGetScalar(prhs[1]),/* offset*/
													mxGetData(prhs[2]), /*buff*/
													(int)mxGetScalar(prhs[3]),  /*count*/
													*((MPI_Datatype *)mxGetData(prhs[4])),  /*datatype*/
													&status /*status*/
												));
	return; 
}
