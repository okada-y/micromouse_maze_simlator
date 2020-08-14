/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * idivide.h
 *
 * Code generation for function 'idivide'
 *
 */

#ifndef IDIVIDE_H
#define IDIVIDE_H

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
extern uint16_T b_idivide(uint16_T a);
extern void idivide(const emlrtStack *sp, const emxArray_uint16_T *a, real_T b,
                    emxArray_uint16_T *c);

#endif

/* End of code generation (idivide.h) */
