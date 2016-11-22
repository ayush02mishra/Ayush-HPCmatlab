
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

    if(sizeof(cl_program)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_program)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_program)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_program)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    }

    char *programSource;
    programSource=mxArrayToString(prhs[2]);

    if((mxGetScalar(prhs[3]))==0)
    {
        *((cl_program *)mxGetData(plhs[0]))=
                                ((cl_program)clCreateProgramWithSource(*((cl_context *)(mxGetData(prhs[0]))),
                                                    (cl_uint)(mxGetScalar(prhs[1])),
                                                    (const char **)(&programSource),
                                                    NULL,
                                                    &errcode_ret
                                ));
    }
    else
    {
        size_t *lengths;
        *lengths=(size_t)(mxGetScalar(prhs[3]));

        *((cl_program *)mxGetData(plhs[0]))=
                                ((cl_program)clCreateProgramWithSource(*((cl_context *)(mxGetData(prhs[0]))),
                                                    (cl_uint)(mxGetScalar(prhs[1])),
                                                    (const char **)(&programSource),
                                                    lengths,
                                                    &errcode_ret
                                ));
    }

    *(mxGetPr(prhs[4]))=(double)errcode_ret;

    nlhs=1;

    return;
}
