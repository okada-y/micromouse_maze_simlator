/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init_mex_data.c
 *
 * Code generation for function 'maze_init_mex_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "maze_init_mex_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
b_struct_T matrix_dir;
struct_T g_direction;
c_struct_T g_d_direction;
d_struct_T l_direction;
e_struct_T move_dir_property;
h_struct_T turn_pattern;
int16_T wall_sensor_front_th;
int16_T wall_sensor_right_th;
int16_T wall_sensor_left_th;
uint32_T matrix_dir_dirty;
uint32_T g_direction_dirty;
uint32_T g_d_direction_dirty;
uint32_T l_direction_dirty;
uint32_T move_dir_property_dirty;
uint32_T turn_pattern_dirty;
uint32_T wall_sensor_front_th_dirty;
uint32_T wall_sensor_right_th_dirty;
uint32_T wall_sensor_left_th_dirty;
covrtInstance emlrtCoverageInstance;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "maze_init_mex",                     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo emlrtRSI = { 21,           /* lineNo */
  "maze_init",                         /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m"/* pathName */
};

emlrtRSInfo b_emlrtRSI = { 20,         /* lineNo */
  "maze_init",                         /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m"/* pathName */
};

emlrtRSInfo c_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 7,          /* lineNo */
  "ref/ref",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\ref.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 41,        /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 153,       /* lineNo */
  "eml_find",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 397,       /* lineNo */
  "find_first_indices",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 43,        /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 2146,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 2159,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 2163,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 2167,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 2177,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 2181,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 2185,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 2198,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 2210,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 2214,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 2218,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 2228,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 2232,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 2236,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 2248,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 2260,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 2264,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 2268,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 2278,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 2282,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 2286,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 2299,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 2311,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 2315,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 2319,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 2329,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 2333,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 2337,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 2418,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 2434,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 2445,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 2462,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 2469,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 2487,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 2508,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ie_emlrtRSI = { 2524,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 2551,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo le_emlrtRSI = { 2558,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo me_emlrtRSI = { 2569,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 2580,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 2587,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 2594,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 2601,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 2608,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

/* End of code generation (maze_init_mex_data.c) */
