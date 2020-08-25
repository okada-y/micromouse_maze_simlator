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

emlrtRSInfo u_emlrtRSI = { 7,          /* lineNo */
  "ref/ref",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\ref.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 706,       /* lineNo */
  "maze_solve/make_map_new_goal",      /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 2351,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 2364,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 2368,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 2372,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 2382,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 2386,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 2390,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 2403,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 2415,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 2419,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 2423,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 2433,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 2437,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 2441,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 2453,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 2465,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 2469,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 2473,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 2483,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 2487,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 2491,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 2504,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 2516,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 2520,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 2524,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 2534,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 2538,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 2542,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 2623,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 2639,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 2650,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 2667,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 2674,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 2692,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 2713,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 2729,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 2756,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 2763,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 2774,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 2785,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 2792,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 2799,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 2806,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 2813,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

/* End of code generation (maze_init_mex_data.c) */
