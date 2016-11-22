
#include <CL/cl.h>
#include "mex.h"

#define N 9

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_mem mem;
    cl_program program;
    cl_kernel kernel;
    cl_event event;
    cl_sampler sampler;

    int Size[N],ii;
    Size[0]=sizeof(platform);
    Size[1]=sizeof(device);
    Size[2]=sizeof(context);
    Size[3]=sizeof(queue);
    Size[4]=sizeof(mem);
    Size[5]=sizeof(program);
    Size[6]=sizeof(kernel);
    Size[7]=sizeof(event);
    Size[8]=sizeof(sampler);
    for(ii=0;ii<N;ii++)
    {
        if(Size[ii]==1)
        {
            plhs[ii]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
            *((int8_T *)mxGetData(plhs[ii]))=0;
        }
        else if(Size[ii]==2)
        {
            plhs[ii]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
            *((int16_T *)mxGetData(plhs[ii]))=0;
        }
        else if(Size[ii]==4)
        {
            plhs[ii]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
            *((int32_T *)mxGetData(plhs[ii]))=0;
        }
        else if(Size[ii]==8)
        {
            plhs[ii]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
            *((int64_T *)mxGetData(plhs[ii]))=0;
        }
    }
    nlhs = N;

    return;
}
