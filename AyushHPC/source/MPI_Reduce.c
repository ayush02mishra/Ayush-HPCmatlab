/*
	Reduces values on all processes to a single value
	Check documentation at:
	http://www.mpich.org/static/docs/latest/www3/MPI_Reduce.html
	The following variables havee been moved to the left hand side in the same order, to conform with the MATLAB standards:
        recvbuf.
*/
#include "mex.h"
#include "mpi.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if(nrhs!=6) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Reduce:nrhs","6 inputs required.");
	}
	if(nlhs!=2) 
	{
		mexErrMsgIdAndTxt("HPCmatlab:MPI_Reduce:nlhs","2 output required.");
	}
	switch(*((MPI_Datatype *)mxGetData(prhs[2])))
{
        case MPI_DOUBLE:
        plhs[1] = mxCreateNumericMatrix((int)mxGetScalar(prhs[1]),1,mxDOUBLE_CLASS,mxREAL);
        break;
        case MPI_FLOAT:
        plhs[1] = mxCreateNumericMatrix((int)mxGetScalar(prhs[1]),1,mxSINGLE_CLASS,mxREAL);
        break;
        case MPI_INT:
        plhs[1] = mxCreateNumericMatrix((int)mxGetScalar(prhs[1]),1,mxINT16_CLASS,mxREAL);
        break;
        default:
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:MPI_DATATYPE","Incompatible Datatype");
}

	plhs[0]=mxCreateDoubleScalar((double)MPI_Reduce(						mxGetData(prhs[0]),
													mxGetData(plhs[1]),
													(int)mxGetScalar(prhs[1]), 
													*((MPI_Datatype *)mxGetData(prhs[2])), 
													*((MPI_Op *)mxGetData(prhs[3])),
						                                                    	(int)mxGetScalar(prhs[4]), 
													*((MPI_Comm *)mxGetData(prhs[5])) 
												));							
	
	return;
}
