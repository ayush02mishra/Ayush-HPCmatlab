
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_uint num_platforms;
    if(nrhs!=3)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Three inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    plhs[0]=mxCreateDoubleScalar((double)clGetPlatformIDs((int)mxGetScalar(prhs[0]),
                                                    (cl_platform_id *)(mxGetData(prhs[1])),
                                                    &num_platforms
                                ));
    *((double *)(mxGetData(prhs[2])))=(double)num_platforms;
    nlhs=1;

    return;
}
