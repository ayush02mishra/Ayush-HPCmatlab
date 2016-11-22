
#include <CL/cl.h>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    cl_mem_flags *pt;

    if(sizeof(cl_mem_flags)==1)
    {
        plhs[0]=mxCreateNumericMatrix(1,6,mxINT8_CLASS,mxREAL);
    }
    else if(sizeof(cl_mem_flags)==2)
    {
        plhs[0]=mxCreateNumericMatrix(1,6,mxINT16_CLASS,mxREAL);
    }
    else if(sizeof(cl_mem_flags)==4)
    {
        plhs[0]=mxCreateNumericMatrix(1,6,mxINT32_CLASS,mxREAL);
    }
    else if(sizeof(cl_mem_flags)==8)
    {
        plhs[0]=mxCreateNumericMatrix(1,6,mxINT64_CLASS,mxREAL);
    }
    nlhs=1;
    
    pt=(cl_mem_flags *)mxGetData(plhs[0]);
    pt[0]=CL_MEM_READ_WRITE;
    pt[1]=CL_MEM_WRITE_ONLY;
    pt[2]=CL_MEM_READ_ONLY;
    pt[3]=CL_MEM_USE_HOST_PTR;
    pt[4]=CL_MEM_ALLOC_HOST_PTR;
    pt[5]=CL_MEM_COPY_HOST_PTR;

    return;
}

