/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * isequal.c
 *
 * Code generation for function 'isequal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "isequal.h"

/* Function Definitions */
boolean_T isequal(const uint8_T varargin_1[2], const uint8_T varargin_2[2])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (varargin_1[k] != varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/* End of code generation (isequal.c) */
