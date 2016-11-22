#define N 64

__kernel void vecadd(__global double *A, __global double *B, __global double *C)
{
    int idx = get_global_id(0);
    if(idx<N)
        C[idx] = A[idx] + B[idx];
}
