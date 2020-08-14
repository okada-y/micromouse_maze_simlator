/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init_mex_mexutil.h
 *
 * Code generation for function 'maze_init_mex_mexutil'
 *
 */

#ifndef MAZE_INIT_MEX_MEXUTIL_H
#define MAZE_INIT_MEX_MEXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "maze_init_mex_types.h"

/* Function Declarations */
extern void MEXGlobalSyncInFunction(const emlrtStack *sp);
extern void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);
extern uint8_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
extern void emlrt_synchGlobalsFromML(const emlrtStack *sp);
extern void emlrt_synchGlobalsToML(const emlrtStack *sp);

#endif

/* End of code generation (maze_init_mex_mexutil.h) */
