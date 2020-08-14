/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * goal_plot.c
 *
 * Code generation for function 'goal_plot'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "goal_plot.h"
#include "eml_int_forloop_overflow_check.h"
#include "maze_init_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 3,   /* lineNo */
  "goal_plot",                         /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 4,     /* lineNo */
  5,                                   /* colNo */
  "goal_plot",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 5,   /* lineNo */
  5,                                   /* colNo */
  "goal_plot",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 6,   /* lineNo */
  5,                                   /* colNo */
  "goal_plot",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  9,                                   /* iLast */
  5,                                   /* lineNo */
  27,                                  /* colNo */
  "maze_goal",                         /* aName */
  "goal_plot",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo te_emlrtRSI = { 6,  /* lineNo */
  "goal_plot",                         /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 4,  /* lineNo */
  "goal_plot",                         /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 5,  /* lineNo */
  "goal_plot",                         /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m"/* pathName */
};

/* Function Declarations */
static void hold(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static void plot(const emlrtStack *sp, const mxArray *b, const mxArray *c, const
                 mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo
                 *location);

/* Function Definitions */
static void hold(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "hold", true, location);
}

static void plot(const emlrtStack *sp, const mxArray *b, const mxArray *c, const
                 mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo
                 *location)
{
  const mxArray *pArrays[5];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  emlrtCallMATLABR2012b(sp, 0, NULL, 5, pArrays, "plot", true, location);
}

void goal_plot(const emlrtStack *sp, uint8_T goal_size, const uint8_T maze_goal
               [18])
{
  boolean_T overflow;
  int32_T i2;
  int32_T i;
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 2 };

  static const char_T u[2] = { 'o', 'n' };

  int32_T i3;
  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 4 };

  static const char_T b_u[4] = { '-', '-', 'o', 'b' };

  const mxArray *d_y;
  static const int32_T iv2[2] = { 1, 10 };

  static const char_T c_u[10] = { 'M', 'a', 'r', 'k', 'e', 'r', 'S', 'i', 'z',
    'e' };

  const mxArray *e_y;
  static const int32_T iv3[2] = { 1, 3 };

  static const char_T d_u[3] = { 'o', 'f', 'f' };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0U);
  st.site = &u_emlrtRSI;
  overflow = ((1 <= goal_size) && (goal_size > 254));
  if (overflow) {
    b_st.site = &c_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  i2 = goal_size;
  for (i = 0; i < i2; i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 0, 1);
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(sp, 2, m0, &u[0]);
    emlrtAssign(&y, m0);
    st.site = &ue_emlrtRSI;
    hold(&st, y, &emlrtMCI);
    i3 = 1 + i;
    if (i3 > 9) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, 9, &i_emlrtBCI, sp);
    }

    y = NULL;
    m0 = emlrtCreateDoubleScalar((real_T)maze_goal[i] * 9.0 - 4.5);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = emlrtCreateDoubleScalar((real_T)maze_goal[i + 9] * 9.0 - 4.5);
    emlrtAssign(&b_y, m0);
    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(sp, 4, m0, &b_u[0]);
    emlrtAssign(&c_y, m0);
    d_y = NULL;
    m0 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(sp, 10, m0, &c_u[0]);
    emlrtAssign(&d_y, m0);
    e_y = NULL;
    m0 = emlrtCreateDoubleScalar(10.0);
    emlrtAssign(&e_y, m0);
    st.site = &ve_emlrtRSI;
    plot(&st, y, b_y, c_y, d_y, e_y, &b_emlrtMCI);
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(sp, 3, m0, &d_u[0]);
    emlrtAssign(&y, m0);
    st.site = &te_emlrtRSI;
    hold(&st, y, &c_emlrtMCI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 0, 0);
}

/* End of code generation (goal_plot.c) */
