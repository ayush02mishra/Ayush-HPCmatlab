
/* As such this is deprecated but still in use for CUDA 7.0 implementation */
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_int errcode_ret;
    if(nrhs!=4)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Four inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    if(sizeof(cl_command_queue)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_command_queue)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_command_queue)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_command_queue)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    }

    *((cl_command_queue *)mxGetData(plhs[0]))=
                        ((cl_command_queue)clCreateCommandQueue(*((cl_context *)(mxGetData(prhs[0]))),
                                                    *((cl_device_id *)(mxGetData(prhs[1]))),
                                                    0,
                                                    &errcode_ret
                                ));
    *(mxGetPr(prhs[3]))=(double)errcode_ret;

    nlhs=1;

    return;
}
