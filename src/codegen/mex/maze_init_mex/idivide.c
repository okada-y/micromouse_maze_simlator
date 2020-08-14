/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * idivide.c
 *
 * Code generation for function 'idivide'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "idivide.h"
#include "maze_init_mex_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "maze_init_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 23, /* lineNo */
  "idivide",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\idivide.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 64, /* lineNo */
  "idivide_fix",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\idivide.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 10, /* lineNo */
  "fix",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\fix.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 31, /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = { 64,/* lineNo */
  20,                                  /* colNo */
  "idivide",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\idivide.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "idivide",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\idivide.m"/* pName */
};

/* Function Definitions */
uint16_T b_idivide(uint16_T a)
{
  return (uint16_T)muDoubleScalarFloor((real_T)a / 32.0);
}

void idivide(const emlrtStack *sp, const emxArray_uint16_T *a, real_T b,
             emxArray_uint16_T *c)
{
  emxArray_real_T *x;
  int32_T nx;
  int32_T loop_ub;
  boolean_T overflow;
  real_T d0;
  uint16_T u1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &x, 1, &k_emlrtRTEI, true);
  st.site = &tb_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  nx = x->size[0];
  x->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&b_st, x, nx, &k_emlrtRTEI);
  loop_ub = a->size[0];
  for (nx = 0; nx < loop_ub; nx++) {
    x->data[nx] = (real_T)a->data[nx] / b;
  }

  c_st.site = &vb_emlrtRSI;
  nx = x->size[0];
  d_st.site = &wb_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &c_emlrtRSI;
    b_check_forloop_overflow_error(&e_st);
  }

  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    if (x->data[loop_ub] < 0.0) {
      x->data[loop_ub] = muDoubleScalarCeil(x->data[loop_ub]);
    } else {
      x->data[loop_ub] = muDoubleScalarFloor(x->data[loop_ub]);
    }
  }

  nx = c->size[0];
  c->size[0] = x->size[0];
  emxEnsureCapacity_uint16_T(&st, c, nx, &l_emlrtRTEI);
  loop_ub = x->size[0];
  for (nx = 0; nx < loop_ub; nx++) {
    d0 = muDoubleScalarRound(x->data[nx]);
    if (d0 < 65536.0) {
      if (d0 >= 0.0) {
        u1 = (uint16_T)d0;
      } else {
        u1 = 0U;
      }
    } else if (d0 >= 65536.0) {
      u1 = MAX_uint16_T;
    } else {
      u1 = 0U;
    }

    c->data[nx] = u1;
  }

  emxFree_real_T(&x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (idivide.c) */
