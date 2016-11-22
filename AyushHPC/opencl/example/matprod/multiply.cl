/* kernel.cl 
 * Matrix multiplication: C = A * B.
 * Device code.
 */
 
// OpenCL Kernel
__kernel void
multiply(__global double* C, 
        __global double* A, 
        __global double* B)
{
   int wA = 4096;
   int wB = 4096;
   int tx = get_global_id(0); 
   int ty = get_global_id(1);
 
   // value stores the element that is 
   // computed by the thread
   double value = 0;
   for (int k = 0; k < wA; ++k)
   {
      double elementA = A[ty * wA + k];
      double elementB = B[k * wB + tx];
      value += elementA * elementB;
   }
 
   // Write the matrix to device memory each 
   // thread writes one element
   C[ty * wA + tx] = value;
}
