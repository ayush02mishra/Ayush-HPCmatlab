
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

    if((*(mxGetPr(prhs[7])))==0)
    {
        if((*(mxGetPr(prhs[8])))==0)
        {
            plhs[0]=mxCreateDoubleScalar((double)clEnqueueCopyBuffer(*((cl_command_queue *)(mxGetData(prhs[0]))),
                                                    *((cl_mem *)(mxGetData(prhs[1]))),
                                                    *((cl_mem *)(mxGetData(prhs[2]))),
                                                    (size_t)mxGetScalar(prhs[3]),
                                                    (size_t)mxGetScalar(prhs[4]),
                                                    (size_t)mxGetScalar(prhs[5]),
                                                    (cl_uint)mxGetScalar(prhs[6]),
                                                    NULL,
                                                    NULL
                                ));
        }
        else
        {
            plhs[0]=mxCreateDoubleScalar((double)clEnqueueCopyBuffer(*((cl_command_queue *)(mxGetData(prhs[0]))),
                                                    *((cl_mem *)(mxGetData(prhs[1]))),
                                                    *((cl_mem *)(mxGetData(prhs[2]))),
                                                    (size_t)mxGetScalar(prhs[3]),
                                                    (size_t)mxGetScalar(prhs[4]),
                                                    (size_t)mxGetScalar(prhs[5]),
                                                    (cl_uint)mxGetScalar(prhs[6]),
                                                    NULL,
                                                    (cl_event *)(mxGetData(prhs[8]))
                                ));
        }

    }
    else
    {
        if((*(mxGetPr(prhs[8])))==0)
        {
            plhs[0]=mxCreateDoubleScalar((double)clEnqueueCopyBuffer(*((cl_command_queue *)(mxGetData(prhs[0]))),
                                                    *((cl_mem *)(mxGetData(prhs[1]))),
                                                    *((cl_mem *)(mxGetData(prhs[2]))),
                                                    (size_t)mxGetScalar(prhs[3]),
                                                    (size_t)mxGetScalar(prhs[4]),
                                                    (size_t)mxGetScalar(prhs[5]),
                                                    (cl_uint)mxGetScalar(prhs[6]),
                                                    (const cl_event *)(mxGetData(prhs[7])),
                                                    NULL
                                ));
        }
        else
        {
            plhs[0]=mxCreateDoubleScalar((double)clEnqueueCopyBuffer(*((cl_command_queue *)(mxGetData(prhs[0]))),
                                                    *((cl_mem *)(mxGetData(prhs[1]))),
                                                    *((cl_mem *)(mxGetData(prhs[2]))),
                                                    (size_t)mxGetScalar(prhs[3]),
                                                    (size_t)mxGetScalar(prhs[4]),
                                                    (size_t)mxGetScalar(prhs[5]),
                                                    (cl_uint)mxGetScalar(prhs[6]),
                                                    (const cl_event *)(mxGetData(prhs[7])),
                                                    (cl_event *)(mxGetData(prhs[8]))
                                ));
        }

    }

    nlhs=1;

    return;
}
