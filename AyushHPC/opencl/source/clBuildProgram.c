
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if(nrhs!=6)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Six inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    if((*(mxGetPr(prhs[2])))==0)
    {
        plhs[0]=mxCreateDoubleScalar((double)clBuildProgram(*((cl_program *)(mxGetData(prhs[0]))),
                                                    (cl_uint)(mxGetScalar(prhs[1])),
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL
                                ));
    }
    else
    {
        plhs[0]=mxCreateDoubleScalar((double)clBuildProgram(*((cl_program *)(mxGetData(prhs[0]))),
                                                    (cl_uint)(mxGetScalar(prhs[1])),
                                                    (const cl_device_id *)(mxGetData(prhs[2])),
                                                    NULL,
                                                    NULL,
                                                    NULL
                                ));
    /*size_t log_size;
    clGetProgramBuildInfo(*((cl_program *)(mxGetData(prhs[0]))),*((cl_device_id *)(mxGetData(prhs[2]))), CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

    char *log = (char *) malloc(log_size);

    clGetProgramBuildInfo(*((cl_program *)(mxGetData(prhs[0]))),*((cl_device_id *)(mxGetData(prhs[2]))), CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

    mexPrintf("%s\n",log);*/
    }
    nlhs=1;

    return;
}
