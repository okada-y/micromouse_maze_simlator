/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_maze_init_mex_api.c
 *
 * Code generation for function '_coder_maze_init_mex_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "_coder_maze_init_mex_api.h"
#include "maze_init_mex_mexutil.h"
#include "maze_init_mex_data.h"

/* Function Declarations */
static const mxArray *k_emlrt_marshallOut(const uint8_T u[1024]);
static void l_emlrt_marshallOut(const uint8_T u[1024], const mxArray *y);
static const mxArray *m_emlrt_marshallOut(const uint16_T u[1024]);
static const mxArray *n_emlrt_marshallOut(const uint16_T u[1056]);
static const mxArray *o_emlrt_marshallOut(const uint16_T u[1056]);
static uint8_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *maze_row_size, const char_T *identifier);
static uint8_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *maze_wall, const char_T *identifier))[1024];
static uint8_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1024];
static uint8_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *maze_goal, const char_T *identifier))[18];
static uint8_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[18];
static uint8_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1024];
static uint8_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[18];

/* Function Definitions */
static const mxArray *k_emlrt_marshallOut(const uint8_T u[1024])
{
  const mxArray *y;
  const mxArray *m14;
  static const int32_T iv5[2] = { 0, 0 };

  static const int32_T iv6[2] = { 32, 32 };

  y = NULL;
  m14 = emlrtCreateNumericArray(2, iv5, mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m14, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m14, iv6, 2);
  emlrtAssign(&y, m14);
  return y;
}

static void l_emlrt_marshallOut(const uint8_T u[1024], const mxArray *y)
{
  static const int32_T iv7[2] = { 32, 32 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, iv7, 2);
}

static const mxArray *m_emlrt_marshallOut(const uint16_T u[1024])
{
  const mxArray *y;
  const mxArray *m15;
  static const int32_T iv8[2] = { 0, 0 };

  static const int32_T iv9[2] = { 32, 32 };

  y = NULL;
  m15 = emlrtCreateNumericArray(2, iv8, mxUINT16_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m15, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m15, iv9, 2);
  emlrtAssign(&y, m15);
  return y;
}

static const mxArray *n_emlrt_marshallOut(const uint16_T u[1056])
{
  const mxArray *y;
  const mxArray *m16;
  static const int32_T iv10[2] = { 0, 0 };

  static const int32_T iv11[2] = { 33, 32 };

  y = NULL;
  m16 = emlrtCreateNumericArray(2, iv10, mxUINT16_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m16, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m16, iv11, 2);
  emlrtAssign(&y, m16);
  return y;
}

static const mxArray *o_emlrt_marshallOut(const uint16_T u[1056])
{
  const mxArray *y;
  const mxArray *m17;
  static const int32_T iv12[2] = { 0, 0 };

  static const int32_T iv13[2] = { 32, 33 };

  y = NULL;
  m17 = emlrtCreateNumericArray(2, iv12, mxUINT16_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m17, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m17, iv13, 2);
  emlrtAssign(&y, m17);
  return y;
}

static uint8_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *maze_row_size, const char_T *identifier)
{
  uint8_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(maze_row_size), &thisId);
  emlrtDestroyArray(&maze_row_size);
  return y;
}

static uint8_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *maze_wall, const char_T *identifier))[1024]
{
  uint8_T (*y)[1024];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = r_emlrt_marshallIn(sp, emlrtAlias(maze_wall), &thisId);
  emlrtDestroyArray(&maze_wall);
  return y;
}
  static uint8_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1024]
{
  uint8_T (*y)[1024];
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *maze_goal, const char_T *identifier))[18]
{
  uint8_T (*y)[18];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = t_emlrt_marshallIn(sp, emlrtAlias(maze_goal), &thisId);
  emlrtDestroyArray(&maze_goal);
  return y;
}
  static uint8_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[18]
{
  uint8_T (*y)[18];
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1024]
{
  uint8_T (*ret)[1024];
  static const int32_T dims[2] = { 32, 32 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, dims);
  ret = (uint8_T (*)[1024])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static uint8_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[18]
{
  uint8_T (*ret)[18];
  static const int32_T dims[2] = { 9, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, dims);
  ret = (uint8_T (*)[18])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void maze_init_api(const mxArray * const prhs[2], int32_T nlhs, const mxArray
                   *plhs[2])
{
  uint8_T (*maze_wall)[1024];
  uint8_T (*maze_wall_search)[1024];
  uint8_T maze_row_size;
  uint8_T maze_col_size;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  maze_wall = (uint8_T (*)[1024])mxMalloc(sizeof(uint8_T [1024]));
  maze_wall_search = (uint8_T (*)[1024])mxMalloc(sizeof(uint8_T [1024]));

  /* Marshall function inputs */
  maze_row_size = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "maze_row_size");
  maze_col_size = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "maze_col_size");

  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);

  /* Invoke the target function */
  maze_init(&st, maze_row_size, maze_col_size, *maze_wall, *maze_wall_search);

  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);

  /* Marshall function outputs */
  plhs[0] = k_emlrt_marshallOut(*maze_wall);
  if (nlhs > 1) {
    plhs[1] = k_emlrt_marshallOut(*maze_wall_search);
  }
}

void maze_solve_api(const mxArray *prhs[8], int32_T nlhs, const mxArray *plhs[5])
{
  uint16_T (*contour_map)[1024];
  uint16_T (*row_num_node)[1056];
  uint16_T (*col_num_node)[1056];
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  uint8_T (*maze_wall)[1024];
  uint8_T (*maze_wall_search)[1024];
  uint8_T maze_row_size;
  uint8_T maze_col_size;
  uint8_T goal_size;
  uint8_T (*maze_goal)[18];
  uint8_T run_mode_1;
  uint8_T run_mode_2;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  contour_map = (uint16_T (*)[1024])mxMalloc(sizeof(uint16_T [1024]));
  row_num_node = (uint16_T (*)[1056])mxMalloc(sizeof(uint16_T [1056]));
  col_num_node = (uint16_T (*)[1056])mxMalloc(sizeof(uint16_T [1056]));
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, true, -1);

  /* Marshall function inputs */
  maze_wall = q_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "maze_wall");
  maze_wall_search = q_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1),
    "maze_wall_search");
  maze_row_size = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "maze_row_size");
  maze_col_size = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "maze_col_size");
  goal_size = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "goal_size");
  maze_goal = s_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "maze_goal");
  run_mode_1 = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "run_mode_1");
  run_mode_2 = p_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "run_mode_2");

  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);

  /* Invoke the target function */
  maze_solve(&st, *maze_wall, *maze_wall_search, maze_row_size, maze_col_size,
             goal_size, *maze_goal, run_mode_1, run_mode_2, *contour_map,
             *row_num_node, *col_num_node);

  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);

  /* Marshall function outputs */
  l_emlrt_marshallOut(*maze_wall, prhs_copy_idx_0);
  plhs[0] = prhs_copy_idx_0;
  if (nlhs > 1) {
    l_emlrt_marshallOut(*maze_wall_search, prhs_copy_idx_1);
    plhs[1] = prhs_copy_idx_1;
  }

  if (nlhs > 2) {
    plhs[2] = m_emlrt_marshallOut(*contour_map);
  }

  if (nlhs > 3) {
    plhs[3] = n_emlrt_marshallOut(*row_num_node);
  }

  if (nlhs > 4) {
    plhs[4] = o_emlrt_marshallOut(*col_num_node);
  }
}

/* End of code generation (_coder_maze_init_mex_api.c) */
