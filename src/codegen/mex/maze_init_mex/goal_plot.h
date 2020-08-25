/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * goal_plot.h
 *
 * Code generation for function 'goal_plot'
 *
 */

#ifndef GOAL_PLOT_H
#define GOAL_PLOT_H

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
extern void b_goal_plot(const emlrtStack *sp, const uint8_T maze_goal[2]);
extern void goal_plot(const emlrtStack *sp, uint8_T goal_size, const uint8_T
                      maze_goal[18]);

#endif

/* End of code generation (goal_plot.h) */
