/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rem.c
 *
 * Code generation for function 'rem'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "rem.h"

/* Function Definitions */
uint8_T b_rem(uint8_T x)
{
  return (uint8_T)(x % 4);
}

uint8_T c_rem(uint8_T x)
{
  return (uint8_T)(x % 8);
}

/* End of code generation (rem.c) */
