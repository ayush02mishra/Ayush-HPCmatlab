#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
*(int *)mxGetData(prhs[0]) = 10;
return;
}
