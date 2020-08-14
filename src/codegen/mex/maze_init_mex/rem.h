/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rem.h
 *
 * Code generation for function 'rem'
 *
 */

#ifndef REM_H
#define REM_H

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
extern uint8_T b_rem(uint8_T x);
extern void c_rem(const emlrtStack *sp, const emxArray_uint16_T *x,
                  emxArray_uint16_T *r);
extern uint16_T d_rem(uint16_T x);
extern void e_rem(const emlrtStack *sp, const emxArray_uint16_T *x,
                  emxArray_uint16_T *r);
extern uint8_T f_rem(uint8_T x);

#endif

/* End of code generation (rem.h) */
