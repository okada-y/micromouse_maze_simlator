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

emlrtRSInfo yb_emlrtRSI = { 947,       /* lineNo */
  "maze_solve/make_new_goal_all",      /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 1069,      /* lineNo */
  "maze_solve/make_new_goal_sh",       /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 2872,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 2885,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 2889,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 2893,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 2903,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 2907,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 2911,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 2924,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 2936,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 2940,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 2944,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 2954,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 2958,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 2962,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 2974,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 2986,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qd_emlrtRSI = { 2990,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 2994,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 3004,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 3008,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 3012,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 3025,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 3037,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 3041,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 3045,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 3055,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 3059,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 3063,      /* lineNo */
  "maze_solve/decide_goal_section",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 3153,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 3176,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 3187,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ie_emlrtRSI = { 3208,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 3219,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 3262,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo le_emlrtRSI = { 3278,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 3309,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 3320,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 3340,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 3359,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo re_emlrtRSI = { 3370,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 3381,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo te_emlrtRSI = { 3392,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

emlrtRSInfo ue_emlrtRSI = { 3403,      /* lineNo */
  "maze_solve/make_route_diagonal",    /* fcnName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m"/* pathName */
};

/* End of code generation (maze_init_mex_data.c) */
