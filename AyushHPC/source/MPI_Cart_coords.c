/*
	Determines process coords in cartesian topology given rank in group
	Check documentation at:
	http://www.mpich.org/static/docs/v3.1/www3/MPI_Cart_coords.html
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=4) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Cart_coords:nrhs","4 inputs required.");
	}
	if(nlhs!=1) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Cart_coords:nlhs","1 output required.");
	}

    	int i=(int)mxGetScalar(prhs[2]);
    	int coords[i];

	plhs[0]=mxCreateDoubleScalar((double)MPI_Cart_coords(*((MPI_Comm *)mxGetData(prhs[0])),
                                                            (int)mxGetScalar(prhs[1]),
                                                            i,
                                                            coords
                                                        ));

    	int j;
    	double* pr = mxGetPr(prhs[3]);
    	for(j=0;j<i;j++)
    	{
        	pr[j]=(double)coords[j];
    	}
	return;
}
