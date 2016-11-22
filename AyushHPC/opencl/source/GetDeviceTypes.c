
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int size=0;
    cl_device_type *pt;
    size=sizeof(cl_device_type);
    if(sizeof(cl_device_type)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,5,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_device_type)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,5,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_device_type)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,5,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_device_type)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,5,mxINT64_CLASS,mxREAL);
    }
    nlhs=1;

    pt=(cl_device_type *)mxGetData(plhs[0]);
    pt[0]=CL_DEVICE_TYPE_CPU;
    pt[1]=CL_DEVICE_TYPE_GPU;
    pt[2]=CL_DEVICE_TYPE_ACCELERATOR;
    pt[3]=CL_DEVICE_TYPE_DEFAULT;
    pt[4]=CL_DEVICE_TYPE_ALL;

    return;
}
