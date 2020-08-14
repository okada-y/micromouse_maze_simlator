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
#include "maze_init_mex_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "maze_init_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo qb_emlrtRSI = { 43, /* lineNo */
  "rem",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\rem.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 65, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 187,/* lineNo */
  "flatIter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 43,/* lineNo */
  13,                                  /* colNo */
  "rem",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\rem.m"/* pName */
};

/* Function Definitions */
uint8_T b_rem(uint8_T x)
{
  return (uint8_T)(x % 4);
}

void c_rem(const emlrtStack *sp, const emxArray_uint16_T *x, emxArray_uint16_T
           *r)
{
  uint32_T x_idx_0;
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_idx_0 = (uint32_T)x->size[0];
  nx = r->size[0];
  r->size[0] = (int32_T)x_idx_0;
  emxEnsureCapacity_uint16_T(&st, r, nx, &j_emlrtRTEI);
  b_st.site = &rb_emlrtRSI;
  x_idx_0 = (uint32_T)x->size[0];
  nx = (int32_T)x_idx_0;
  c_st.site = &sb_emlrtRSI;
  overflow = ((1 <= r->size[0]) && (r->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &c_emlrtRSI;
    b_check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < nx; k++) {
    r->data[k] = (uint16_T)(x->data[k] % 32);
  }
}

uint16_T d_rem(uint16_T x)
{
  return (uint16_T)(x % 32);
}

void e_rem(const emlrtStack *sp, const emxArray_uint16_T *x, emxArray_uint16_T
           *r)
{
  uint32_T x_idx_0;
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_idx_0 = (uint32_T)x->size[0];
  nx = r->size[0];
  r->size[0] = (int32_T)x_idx_0;
  emxEnsureCapacity_uint16_T(&st, r, nx, &j_emlrtRTEI);
  b_st.site = &rb_emlrtRSI;
  x_idx_0 = (uint32_T)x->size[0];
  nx = (int32_T)x_idx_0;
  c_st.site = &sb_emlrtRSI;
  overflow = ((1 <= r->size[0]) && (r->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &c_emlrtRSI;
    b_check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < nx; k++) {
    r->data[k] = (uint16_T)(x->data[k] % 33);
  }
}

uint8_T f_rem(uint8_T x)
{
  return (uint8_T)(x % 8);
}

/* End of code generation (rem.c) */
