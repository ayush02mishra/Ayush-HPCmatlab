
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_uint num_devices;
    cl_device_id device;
    if(nrhs!=3)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","3 inputs required.");
    }
    if(nlhs!=3)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","3 output required.");
    }

    plhs[0]=mxCreateDoubleScalar((double)clGetDeviceIDs(*((cl_platform_id *)(mxGetData(prhs[0]))),
                                                    *((cl_device_type *)mxGetData(prhs[1])),
                                                    (int)mxGetScalar(prhs[2]),
/*                                                    (cl_device_id *)(mxGetData(prhs[3])),*/
						    &device,
                                                    &num_devices
                                ));
/*    *((double *)(mxGetData(prhs[4])))=(double)num_devices;*/
 mexPrintf("\ndevice id and number of devices:  %p,  %d\n",(void *)device,sizeof(device));
    int Size=sizeof(device);
     if(Size==1)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
            *((int8_T *)mxGetData(plhs[1]))=(int8_T )device;
        }
        else if(Size==2)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
            *((int16_T *)mxGetData(plhs[1]))=(int16_T)device;
        }
        else if(Size==4)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
            *((int32_T *)mxGetData(plhs[1]))=(int32_T )device;
        }
        else if(Size==8)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
            *((int64_T *)mxGetData(plhs[1]))=(int64_T)device;
        }

    plhs[2]=mxCreateDoubleScalar((double)num_devices);
    return;
}
