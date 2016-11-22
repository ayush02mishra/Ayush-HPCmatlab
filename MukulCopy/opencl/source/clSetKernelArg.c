
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if(nrhs!=4)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Four inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    plhs[0]=mxCreateDoubleScalar((double)clSetKernelArg(*((cl_kernel *)(mxGetData(prhs[0]))),
                                                    (cl_uint)(mxGetScalar(prhs[1]))-1,
                                                    (size_t)(mxGetScalar(prhs[2])),
                                                    (const void *)(mxGetData(prhs[3]))
                                ));
    nlhs=1;

    return;
}
