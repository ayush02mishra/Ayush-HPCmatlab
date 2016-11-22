
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_int errcode_ret;
    if(nrhs!=5)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Five inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    
    if(sizeof(cl_mem)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_mem)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_mem)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_mem)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    }

    if((*(mxGetPr(prhs[3])))==0)
    {
        *((cl_mem *)mxGetData(plhs[0]))=
                                ((cl_mem)clCreateBuffer(*((cl_context *)(mxGetData(prhs[0]))),
                                                    (cl_mem_flags)mxGetScalar(prhs[1]),
                                                    (size_t)mxGetScalar(prhs[2]),
                                                    NULL,
                                                    &errcode_ret
                                ));
    }
    else
    {
        *((cl_mem *)mxGetData(plhs[0]))=
                                ((cl_mem)clCreateBuffer(*((cl_context *)(mxGetData(prhs[0]))),
                                                    (cl_mem_flags)mxGetScalar(prhs[1]),
                                                    (size_t)mxGetScalar(prhs[2]),
                                                    mxGetData(prhs[3]),
                                                    &errcode_ret
                                ));
    }

    *(mxGetPr(prhs[4]))=(double)errcode_ret;
    nlhs=1;

    return;
}
