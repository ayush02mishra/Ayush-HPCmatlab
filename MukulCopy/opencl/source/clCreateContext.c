
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_int errcode_ret;
    if(nrhs!=6)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Six inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    if(sizeof(cl_context)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_context)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_context)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_context)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    }

    *((cl_context *)mxGetData(plhs[0]))=((cl_context)clCreateContext(NULL,
                                                    (int)(mxGetScalar(prhs[1])),
                                                    (const cl_device_id *)(mxGetData(prhs[2])),
                                                    NULL,
                                                    NULL,
                                                    &errcode_ret
                                ));
    *(mxGetPr(prhs[5]))=(double)errcode_ret;

    nlhs=1;

    return;
}
