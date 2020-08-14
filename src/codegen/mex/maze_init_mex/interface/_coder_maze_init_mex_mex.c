/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_maze_init_mex_mex.c
 *
 * Code generation for function '_coder_maze_init_mex_mex'
 *
 */

/* Include files */
#include "maze_init.h"
#include "maze_solve.h"
#include "_coder_maze_init_mex_mex.h"
#include "maze_init_mex_terminate.h"
#include "_coder_maze_init_mex_api.h"
#include "maze_init_mex_initialize.h"
#include "maze_init_mex_data.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[2] = { "maze_init", "maze_solve" };

/* Function Declarations */
static void maze_init_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[2]);
static void maze_solve_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T nrhs,
  const mxArray *prhs[7]);

/* Function Definitions */
static void maze_init_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[2])
{
  const mxArray *outputs[2];
  int32_T nOutputs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 9,
                        "maze_init");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "maze_init");
  }

  /* Call the function. */
  maze_init_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    nOutputs = 1;
  } else {
    nOutputs = nlhs;
  }

  emlrtReturnArrays(nOutputs, plhs, outputs);
}

static void maze_solve_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T nrhs,
  const mxArray *prhs[7])
{
  const mxArray *outputs[5];
  int32_T nOutputs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        10, "maze_solve");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "maze_solve");
  }

  /* Call the function. */
  maze_solve_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    nOutputs = 1;
  } else {
    nOutputs = nlhs;
  }

  emlrtReturnArrays(nOutputs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexAtExit(maze_init_mex_atexit);

  /* Module initialization. */
  maze_init_mex_initialize();
  st.tls = emlrtRootTLSGlobal;

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(&st, nrhs, prhs, emlrtEntryPoints, 2)) {
   case 0:
    maze_init_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[2])&prhs[1]);
    break;

   case 1:
    maze_solve_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[7])&prhs[1]);
    break;
  }

  /* Module termination. */
  maze_init_mex_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_maze_init_mex_mex.c) */
