/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_solve.h
 *
 * Code generation for function 'maze_solve'
 *
 */

#ifndef MAZE_SOLVE_H
#define MAZE_SOLVE_H

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
extern void maze_solve(const emlrtStack *sp, uint8_T maze_wall[1024], uint8_T
  maze_wall_search[1024], uint8_T maze_row_size, uint8_T maze_col_size, uint8_T
  goal_size, const uint8_T maze_goal[18], uint8_T run_mode_1, uint8_T run_mode_2,
  uint16_T contour_map[1024], uint16_T row_num_node[1056], uint16_T
  col_num_node[1056]);

#endif

/* End of code generation (maze_solve.h) */
