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

emlrtRSInfo hc_emlrtRSI = { 923,       /* lineNo */
  "maze_solve/make_new_goal_sh",       /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 2626,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 2639,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 2643,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 2647,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 2657,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 2661,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 2665,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 2678,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 2690,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 2694,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 2698,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 2708,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 2712,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 2716,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 2728,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 2740,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 2744,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 2748,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 2758,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 2762,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 2766,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 2779,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 2791,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 2795,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 2799,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 2809,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 2813,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 2817,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 2898,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 2914,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 2925,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 2942,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 2949,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 2967,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 2988,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 3004,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 3031,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 3038,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ie_emlrtRSI = { 3049,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 3060,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 3067,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo le_emlrtRSI = { 3074,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo me_emlrtRSI = { 3081,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 3088,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

/* End of code generation (maze_init_mex_data.c) */
