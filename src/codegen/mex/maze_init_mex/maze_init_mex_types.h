/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init_mex_types.h
 *
 * Code generation for function 'maze_init'
 *
 */

#ifndef MAZE_INIT_MEX_TYPES_H
#define MAZE_INIT_MEX_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  uint8_T Row;
  uint8_T Col;
  uint8_T section;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  uint8_T North;
  uint8_T North_East;
  uint8_T East;
  uint8_T South_East;
  uint8_T South;
  uint8_T South_West;
  uint8_T West;
  uint8_T North_West;
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  uint8_T front;
  uint8_T right;
  uint8_T back;
  uint8_T left;
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef typedef_e_struct_T
#define typedef_e_struct_T

typedef struct {
  uint8_T straight;
  uint8_T diagonal;
} e_struct_T;

#endif                                 /*typedef_e_struct_T*/

#ifndef typedef_h_struct_T
#define typedef_h_struct_T

typedef struct {
  uint8_T b_default;
  uint8_T r_45;
  uint8_T l_45;
  uint8_T r_90;
  uint8_T l_90;
  uint8_T r_135;
  uint8_T l_135;
  uint8_T r_180;
  uint8_T l_180;
} h_struct_T;

#endif                                 /*typedef_h_struct_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  uint8_T North;
  uint8_T East;
  uint8_T South;
  uint8_T West;
} struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/* End of code generation (maze_init_mex_types.h) */
