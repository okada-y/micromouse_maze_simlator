/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init_mex_mexutil.c
 *
 * Code generation for function 'maze_init_mex_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "maze_init_mex_mexutil.h"
#include "maze_init_mex_data.h"

/* Function Declarations */
static b_struct_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static struct_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_g_direction, const char_T *identifier);
static const mxArray *d_emlrt_marshallOut(const b_struct_T u);
static struct_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *e_emlrt_marshallOut(const struct_T u);
static b_struct_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_matrix_dir, const char_T *identifier);
static c_struct_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_g_d_direction, const char_T *identifier);
static const mxArray *f_emlrt_marshallOut(const c_struct_T u);
static c_struct_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static const mxArray *g_emlrt_marshallOut(const d_struct_T u);
static d_struct_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_l_direction, const char_T *identifier);
static const mxArray *h_emlrt_marshallOut(const e_struct_T u);
static d_struct_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static const mxArray *i_emlrt_marshallOut(const i_struct_T u);
static e_struct_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_move_dir_property, const char_T *identifier);
static const mxArray *j_emlrt_marshallOut(const int16_T u);
static e_struct_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static i_struct_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_turn_pattern, const char_T *identifier);
static i_struct_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static int16_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_wall_sensor_front_th, const char_T *identifier);
static int16_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static uint8_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static int16_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static b_struct_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  b_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "Row", "Col", "section" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Row";
  y.Row = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "Row")), &thisId);
  thisId.fIdentifier = "Col";
  y.Col = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "Col")), &thisId);
  thisId.fIdentifier = "section";
  y.section = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "section")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static struct_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_g_direction, const char_T *identifier)
{
  struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(b_g_direction), &thisId);
  emlrtDestroyArray(&b_g_direction);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const b_struct_T u)
{
  const mxArray *y;
  static const char * sv0[3] = { "Row", "Col", "section" };

  const mxArray *b_y;
  const mxArray *m7;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv0));
  b_y = NULL;
  m7 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m7) = u.Row;
  emlrtAssign(&b_y, m7);
  emlrtSetFieldR2017b(y, 0, "Row", b_y, 0);
  b_y = NULL;
  m7 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m7) = u.Col;
  emlrtAssign(&b_y, m7);
  emlrtSetFieldR2017b(y, 0, "Col", b_y, 1);
  b_y = NULL;
  m7 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m7) = u.section;
  emlrtAssign(&b_y, m7);
  emlrtSetFieldR2017b(y, 0, "section", b_y, 2);
  return y;
}

static struct_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "North", "East", "South", "West" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "North";
  y.North = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "North")), &thisId);
  thisId.fIdentifier = "East";
  y.East = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "East")), &thisId);
  thisId.fIdentifier = "South";
  y.South = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "South")), &thisId);
  thisId.fIdentifier = "West";
  y.West = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "West")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const struct_T u)
{
  const mxArray *y;
  static const char * sv1[4] = { "North", "East", "South", "West" };

  const mxArray *b_y;
  const mxArray *m8;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, sv1));
  b_y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m8) = u.North;
  emlrtAssign(&b_y, m8);
  emlrtSetFieldR2017b(y, 0, "North", b_y, 0);
  b_y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m8) = u.East;
  emlrtAssign(&b_y, m8);
  emlrtSetFieldR2017b(y, 0, "East", b_y, 1);
  b_y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m8) = u.South;
  emlrtAssign(&b_y, m8);
  emlrtSetFieldR2017b(y, 0, "South", b_y, 2);
  b_y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m8) = u.West;
  emlrtAssign(&b_y, m8);
  emlrtSetFieldR2017b(y, 0, "West", b_y, 3);
  return y;
}

static b_struct_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_matrix_dir, const char_T *identifier)
{
  b_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_matrix_dir), &thisId);
  emlrtDestroyArray(&b_matrix_dir);
  return y;
}

static c_struct_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_g_d_direction, const char_T *identifier)
{
  c_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = g_emlrt_marshallIn(sp, emlrtAlias(b_g_d_direction), &thisId);
  emlrtDestroyArray(&b_g_d_direction);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const c_struct_T u)
{
  const mxArray *y;
  static const char * sv2[8] = { "North", "North_East", "East", "South_East",
    "South", "South_West", "West", "North_West" };

  const mxArray *b_y;
  const mxArray *m9;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv2));
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.North;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "North", b_y, 0);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.North_East;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "North_East", b_y, 1);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.East;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "East", b_y, 2);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.South_East;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "South_East", b_y, 3);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.South;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "South", b_y, 4);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.South_West;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "South_West", b_y, 5);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.West;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "West", b_y, 6);
  b_y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m9) = u.North_West;
  emlrtAssign(&b_y, m9);
  emlrtSetFieldR2017b(y, 0, "North_West", b_y, 7);
  return y;
}

static c_struct_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  c_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[8] = { "North", "North_East", "East",
    "South_East", "South", "South_West", "West", "North_West" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 8, fieldNames, 0U, &dims);
  thisId.fIdentifier = "North";
  y.North = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "North")), &thisId);
  thisId.fIdentifier = "North_East";
  y.North_East = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    1, "North_East")), &thisId);
  thisId.fIdentifier = "East";
  y.East = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "East")), &thisId);
  thisId.fIdentifier = "South_East";
  y.South_East = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    3, "South_East")), &thisId);
  thisId.fIdentifier = "South";
  y.South = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "South")), &thisId);
  thisId.fIdentifier = "South_West";
  y.South_West = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "South_West")), &thisId);
  thisId.fIdentifier = "West";
  y.West = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "West")), &thisId);
  thisId.fIdentifier = "North_West";
  y.North_West = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    7, "North_West")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *g_emlrt_marshallOut(const d_struct_T u)
{
  const mxArray *y;
  static const char * sv3[4] = { "front", "right", "back", "left" };

  const mxArray *b_y;
  const mxArray *m10;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, sv3));
  b_y = NULL;
  m10 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m10) = u.front;
  emlrtAssign(&b_y, m10);
  emlrtSetFieldR2017b(y, 0, "front", b_y, 0);
  b_y = NULL;
  m10 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m10) = u.right;
  emlrtAssign(&b_y, m10);
  emlrtSetFieldR2017b(y, 0, "right", b_y, 1);
  b_y = NULL;
  m10 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m10) = u.back;
  emlrtAssign(&b_y, m10);
  emlrtSetFieldR2017b(y, 0, "back", b_y, 2);
  b_y = NULL;
  m10 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m10) = u.left;
  emlrtAssign(&b_y, m10);
  emlrtSetFieldR2017b(y, 0, "left", b_y, 3);
  return y;
}

static d_struct_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_l_direction, const char_T *identifier)
{
  d_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = i_emlrt_marshallIn(sp, emlrtAlias(b_l_direction), &thisId);
  emlrtDestroyArray(&b_l_direction);
  return y;
}

static const mxArray *h_emlrt_marshallOut(const e_struct_T u)
{
  const mxArray *y;
  static const char * sv4[2] = { "straight", "diagonal" };

  const mxArray *b_y;
  const mxArray *m11;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, sv4));
  b_y = NULL;
  m11 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m11) = u.straight;
  emlrtAssign(&b_y, m11);
  emlrtSetFieldR2017b(y, 0, "straight", b_y, 0);
  b_y = NULL;
  m11 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m11) = u.diagonal;
  emlrtAssign(&b_y, m11);
  emlrtSetFieldR2017b(y, 0, "diagonal", b_y, 1);
  return y;
}

static d_struct_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  d_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "front", "right", "back", "left" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "front";
  y.front = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "front")), &thisId);
  thisId.fIdentifier = "right";
  y.right = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "right")), &thisId);
  thisId.fIdentifier = "back";
  y.back = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "back")), &thisId);
  thisId.fIdentifier = "left";
  y.left = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "left")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *i_emlrt_marshallOut(const i_struct_T u)
{
  const mxArray *y;
  static const char * sv5[9] = { "default", "r_45", "l_45", "r_90", "l_90",
    "r_135", "l_135", "r_180", "l_180" };

  const mxArray *b_y;
  const mxArray *m12;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 9, sv5));
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.b_default;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "default", b_y, 0);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.r_45;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "r_45", b_y, 1);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.l_45;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "l_45", b_y, 2);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.r_90;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "r_90", b_y, 3);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.l_90;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "l_90", b_y, 4);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.r_135;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "r_135", b_y, 5);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.l_135;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "l_135", b_y, 6);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.r_180;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "r_180", b_y, 7);
  b_y = NULL;
  m12 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m12) = u.l_180;
  emlrtAssign(&b_y, m12);
  emlrtSetFieldR2017b(y, 0, "l_180", b_y, 8);
  return y;
}

static e_struct_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_move_dir_property, const char_T *identifier)
{
  e_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = k_emlrt_marshallIn(sp, emlrtAlias(b_move_dir_property), &thisId);
  emlrtDestroyArray(&b_move_dir_property);
  return y;
}

static const mxArray *j_emlrt_marshallOut(const int16_T u)
{
  const mxArray *y;
  const mxArray *m13;
  y = NULL;
  m13 = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m13) = u;
  emlrtAssign(&y, m13);
  return y;
}

static e_struct_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  e_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "straight", "diagonal" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "straight";
  y.straight = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "straight")), &thisId);
  thisId.fIdentifier = "diagonal";
  y.diagonal = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "diagonal")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static i_struct_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_turn_pattern, const char_T *identifier)
{
  i_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = m_emlrt_marshallIn(sp, emlrtAlias(b_turn_pattern), &thisId);
  emlrtDestroyArray(&b_turn_pattern);
  return y;
}

static i_struct_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  i_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[9] = { "default", "r_45", "l_45", "r_90",
    "l_90", "r_135", "l_135", "r_180", "l_180" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 9, fieldNames, 0U, &dims);
  thisId.fIdentifier = "default";
  y.b_default = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    0, "default")), &thisId);
  thisId.fIdentifier = "r_45";
  y.r_45 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "r_45")), &thisId);
  thisId.fIdentifier = "l_45";
  y.l_45 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "l_45")), &thisId);
  thisId.fIdentifier = "r_90";
  y.r_90 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "r_90")), &thisId);
  thisId.fIdentifier = "l_90";
  y.l_90 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "l_90")), &thisId);
  thisId.fIdentifier = "r_135";
  y.r_135 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "r_135")), &thisId);
  thisId.fIdentifier = "l_135";
  y.l_135 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "l_135")), &thisId);
  thisId.fIdentifier = "r_180";
  y.r_180 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "r_180")), &thisId);
  thisId.fIdentifier = "l_180";
  y.l_180 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "l_180")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static int16_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_wall_sensor_front_th, const char_T *identifier)
{
  int16_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = o_emlrt_marshallIn(sp, emlrtAlias(b_wall_sensor_front_th), &thisId);
  emlrtDestroyArray(&b_wall_sensor_front_th);
  return y;
}

static int16_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  uint8_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 0U, &dims);
  ret = *(uint8_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int16_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int16_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int16", false, 0U, &dims);
  ret = *(int16_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;
  const mxArray *b_tmp;
  const mxArray *c_tmp;
  const mxArray *d_tmp;
  const mxArray *e_tmp;
  const mxArray *f_tmp;
  const mxArray *g_tmp;
  const mxArray *h_tmp;
  const mxArray *i_tmp;

  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable("matrix_dir");
  if (tmp != NULL) {
    matrix_dir = emlrt_marshallIn(sp, tmp, "matrix_dir");
    matrix_dir_dirty = 0U;
  }

  b_tmp = emlrtGetGlobalVariable("g_direction");
  if (b_tmp != NULL) {
    g_direction = d_emlrt_marshallIn(sp, b_tmp, "g_direction");
    g_direction_dirty = 0U;
  }

  c_tmp = emlrtGetGlobalVariable("g_d_direction");
  if (c_tmp != NULL) {
    g_d_direction = f_emlrt_marshallIn(sp, c_tmp, "g_d_direction");
    g_d_direction_dirty = 0U;
  }

  d_tmp = emlrtGetGlobalVariable("l_direction");
  if (d_tmp != NULL) {
    l_direction = h_emlrt_marshallIn(sp, d_tmp, "l_direction");
    l_direction_dirty = 0U;
  }

  e_tmp = emlrtGetGlobalVariable("move_dir_property");
  if (e_tmp != NULL) {
    move_dir_property = j_emlrt_marshallIn(sp, e_tmp, "move_dir_property");
    move_dir_property_dirty = 0U;
  }

  f_tmp = emlrtGetGlobalVariable("turn_pattern");
  if (f_tmp != NULL) {
    turn_pattern = l_emlrt_marshallIn(sp, f_tmp, "turn_pattern");
    turn_pattern_dirty = 0U;
  }

  g_tmp = emlrtGetGlobalVariable("wall_sensor_front_th");
  if (g_tmp != NULL) {
    wall_sensor_front_th = n_emlrt_marshallIn(sp, g_tmp, "wall_sensor_front_th");
    wall_sensor_front_th_dirty = 0U;
  }

  h_tmp = emlrtGetGlobalVariable("wall_sensor_right_th");
  if (h_tmp != NULL) {
    wall_sensor_right_th = n_emlrt_marshallIn(sp, h_tmp, "wall_sensor_right_th");
    wall_sensor_right_th_dirty = 0U;
  }

  i_tmp = emlrtGetGlobalVariable("wall_sensor_left_th");
  if (i_tmp != NULL) {
    wall_sensor_left_th = n_emlrt_marshallIn(sp, i_tmp, "wall_sensor_left_th");
    wall_sensor_left_th_dirty = 0U;
  }
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (matrix_dir_dirty != 0U)) {
    emlrtPutGlobalVariable("matrix_dir", d_emlrt_marshallOut(matrix_dir));
  }

  if (skipDirtyCheck || (g_direction_dirty != 0U)) {
    emlrtPutGlobalVariable("g_direction", e_emlrt_marshallOut(g_direction));
  }

  if (skipDirtyCheck || (g_d_direction_dirty != 0U)) {
    emlrtPutGlobalVariable("g_d_direction", f_emlrt_marshallOut(g_d_direction));
  }

  if (skipDirtyCheck || (l_direction_dirty != 0U)) {
    emlrtPutGlobalVariable("l_direction", g_emlrt_marshallOut(l_direction));
  }

  if (skipDirtyCheck || (move_dir_property_dirty != 0U)) {
    emlrtPutGlobalVariable("move_dir_property", h_emlrt_marshallOut
      (move_dir_property));
  }

  if (skipDirtyCheck || (turn_pattern_dirty != 0U)) {
    emlrtPutGlobalVariable("turn_pattern", i_emlrt_marshallOut(turn_pattern));
  }

  if (skipDirtyCheck || (wall_sensor_front_th_dirty != 0U)) {
    emlrtPutGlobalVariable("wall_sensor_front_th", j_emlrt_marshallOut
      (wall_sensor_front_th));
  }

  if (skipDirtyCheck || (wall_sensor_right_th_dirty != 0U)) {
    emlrtPutGlobalVariable("wall_sensor_right_th", j_emlrt_marshallOut
      (wall_sensor_right_th));
  }

  if (skipDirtyCheck || (wall_sensor_left_th_dirty != 0U)) {
    emlrtPutGlobalVariable("wall_sensor_left_th", j_emlrt_marshallOut
      (wall_sensor_left_th));
  }
}

uint8_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint8_T y;
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  MEXGlobalSyncInFunction(sp);
  matrix_dir_dirty = 0U;
  g_direction_dirty = 0U;
  g_d_direction_dirty = 0U;
  l_direction_dirty = 0U;
  move_dir_property_dirty = 0U;
  turn_pattern_dirty = 0U;
  wall_sensor_front_th_dirty = 0U;
  wall_sensor_right_th_dirty = 0U;
  wall_sensor_left_th_dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  MEXGlobalSyncOutFunction(false);
}

/* End of code generation (maze_init_mex_mexutil.c) */
