
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_int errcode_ret;
    if(nrhs!=3)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Three inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    if(sizeof(cl_kernel)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_kernel)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_kernel)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_kernel)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    }

    *((cl_kernel *)mxGetData(plhs[0]))=((cl_kernel)clCreateKernel(*((cl_program *)(mxGetData(prhs[0]))),
                                                    mxArrayToString(prhs[1]),
                                                    &errcode_ret
                                ));
    *(mxGetPr(prhs[2]))=(double)errcode_ret;

    nlhs=1;

    return;
}
