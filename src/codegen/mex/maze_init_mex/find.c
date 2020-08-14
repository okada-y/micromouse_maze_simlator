/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "find.h"
#include "indexShapeCheck.h"

/* Function Definitions */
void b_eml_find(const boolean_T x[1056], int32_T i_data[], int32_T i_size[1])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 1056)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 1056) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  indexShapeCheck();
  i_size[0] = idx;
}

void eml_find(const boolean_T x[1024], int32_T i_data[], int32_T i_size[1])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 1024)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 1024) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  indexShapeCheck();
  i_size[0] = idx;
}

/* End of code generation (find.c) */
