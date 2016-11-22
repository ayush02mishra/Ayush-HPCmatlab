#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void vecadd(__global double *A, __global double *B, __global double *C)
{
    int idx = get_global_id(0);
    if(idx<128)
        C[idx] = A[idx] + B[idx];
}
