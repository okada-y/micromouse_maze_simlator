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
i_struct_T turn_pattern;
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

emlrtRSInfo eb_emlrtRSI = { 7,         /* lineNo */
  "ref/ref",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\ref.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 801,       /* lineNo */
  "maze_solve/make_new_goal_all",      /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 923,       /* lineNo */
  "maze_solve/make_new_goal_sh",       /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 2714,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 2727,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 2731,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 2735,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 2745,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 2749,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 2753,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 2766,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 2778,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 2782,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 2786,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 2796,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 2800,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 2804,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 2816,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 2828,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 2832,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 2836,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 2846,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 2850,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 2854,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 2867,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 2879,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 2883,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 2887,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 2897,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 2901,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 2905,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 2986,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 3002,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 3013,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 3030,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 3037,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 3055,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ie_emlrtRSI = { 3076,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 3092,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo le_emlrtRSI = { 3119,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo me_emlrtRSI = { 3126,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 3137,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 3148,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 3155,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 3162,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 3169,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 3176,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

/* End of code generation (maze_init_mex_data.c) */
