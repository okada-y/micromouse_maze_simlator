/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init_mex_terminate.c
 *
 * Code generation for function 'maze_init_mex_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "maze_init_mex_terminate.h"
#include "maze_init_mex_mexutil.h"
#include "_coder_maze_init_mex_mex.h"
#include "maze_init_mex_data.h"

/* Function Definitions */
void maze_init_mex_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrt_synchGlobalsFromML(&st);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrt_synchGlobalsToML(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void maze_init_mex_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (maze_init_mex_terminate.c) */
