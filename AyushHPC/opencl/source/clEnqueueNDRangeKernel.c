
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if(nrhs!=9)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Nine inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    int i=(int)mxGetScalar(prhs[2]);
    int j;
    double* pr1 = mxGetPr(prhs[4]);

    size_t global_size[i];
    for(j=0;j<i;j++)
    {
        global_size[j]=(size_t)pr1[j];
    }

    double* pr2 = mxGetPr(prhs[5]);
    size_t local_size[i];
    for(j=0;j<i;j++)
    {
        local_size[j]=(size_t)pr2[j];
    }

    plhs[0]=mxCreateDoubleScalar((double)clEnqueueNDRangeKernel(*((cl_command_queue *)(mxGetData(prhs[0]))),
                                                    *((cl_kernel *)(mxGetData(prhs[1]))),
                                                    (cl_uint)(mxGetScalar(prhs[2])),
                                                    NULL,
                                                    global_size,
                                                    local_size,
                                                    (cl_uint)(mxGetScalar(prhs[6])),
                                                    NULL,
                                                    NULL
                                ));
    nlhs=1;

    return;
}
