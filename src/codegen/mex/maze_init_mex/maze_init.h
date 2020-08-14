/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init.h
 *
 * Code generation for function 'maze_init'
 *
 */

#ifndef MAZE_INIT_H
#define MAZE_INIT_H

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
extern void maze_init(const emlrtStack *sp, uint8_T maze_row_size, uint8_T
                      maze_col_size, uint8_T maze_wall[1024], uint8_T
                      maze_wall_search[1024]);

#endif

/* End of code generation (maze_init.h) */
