#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_uint num_platforms;
	cl_platform_id platform;
    if(nrhs!=1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","1 inputs required.");
    }
    if(nlhs!=3)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","3 output required.");
    }

    plhs[0]=mxCreateDoubleScalar((double)clGetPlatformIDs((int)mxGetScalar(prhs[0]),
                                                    &platform,
                                                    &num_platforms
                                ));
/*    *((double*)(mxGetData(prhs[2]))) = (double)num_platforms*/
    mexPrintf("\nplatform id %p\n",(void *)platform);
    int	Size=sizeof(platform);
     if(Size==1)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT8_CLASS,mxREAL);
            *((int8_T *)mxGetData(plhs[1]))=(int8_T )platform;
        }
        else if(Size==2)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT16_CLASS,mxREAL);
            *((int16_T *)mxGetData(plhs[1]))=(int16_T)platform;
        }
        else if(Size==4)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
            *((int32_T *)mxGetData(plhs[1]))=(int32_T )platform;
        }
        else if(Size==8)
        {
            plhs[1]=mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
            *((int64_T *)mxGetData(plhs[1]))=(int64_T)platform;
        }
 
	plhs[2]=mxCreateDoubleScalar((double)num_platforms);
    

    return;
}

