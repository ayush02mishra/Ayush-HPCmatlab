/*
	Removes an existing buffer (for use in MPI_Bsend etc)
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_Buffer_detach.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=0) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Buffer_detach:nrhs","no input required.");
	}
	if(nlhs!=3) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Buffer_detach:nlhs","3 output required.");
	}

    	void *buff;
    	int size;
	plhs[0]=mxCreateDoubleScalar((double)MPI_Buffer_detach(	
													&buff,
													&size
													));	
        double *d = (double *)buff;
	mxSetData(plhs[1],buff);
	plhs[2] = mxCreateDoubleScalar((double)size);
	return; 
}
