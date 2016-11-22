/*
        Makes a new communicator to which topology information has been attached
        Check documentation at:
        http://www.mpich.org/static/docs/v3.1/www3/MPI_Cart_create.html
*/

#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=6) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Cart_create:nrhs","6 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Cart_create:nlhs","1 output required.");
	}

    int i=(int)mxGetScalar(prhs[1]);
    int j;
    double* pr1 = mxGetPr(prhs[2]);
    int dims[i];
    for(j=0;j<i;j++)
    {
        dims[j]=(int)pr1[j];
    }

    double* pr2 = mxGetPr(prhs[3]);
    int periods[i];
    for(j=0;j<i;j++)
    {
        periods[j]=(int)pr2[j];
    }
    
	plhs[0]=mxCreateDoubleScalar((double)MPI_Cart_create(*((MPI_Comm *)(mxGetData(prhs[0]))),
                                                            i,
                                                            dims,
                                                            periods,
                                                            (int)mxGetScalar(prhs[4]),
                                                            (MPI_Comm *)(mxGetData(prhs[5]))
                                                        ));
	return;
}
