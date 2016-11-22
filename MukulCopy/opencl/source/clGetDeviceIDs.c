
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_uint num_devices;
    if(nrhs!=5)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Five inputs required.");
    }
    if(nlhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }

    plhs[0]=mxCreateDoubleScalar((double)clGetDeviceIDs(*((cl_platform_id *)(mxGetData(prhs[0]))),
                                                    *((cl_device_type *)mxGetData(prhs[1])),
                                                    (int)mxGetScalar(prhs[2]),
                                                    (cl_device_id *)(mxGetData(prhs[3])),
                                                    &num_devices
                                ));
    *((double *)(mxGetData(prhs[4])))=(double)num_devices;

    nlhs=1;

    return;
}
