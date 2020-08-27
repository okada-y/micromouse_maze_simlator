/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init_mex_initialize.c
 *
 * Code generation for function 'maze_init_mex_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "maze_init_mex_mexutil.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "maze_init_mex_initialize.h"
#include "_coder_maze_init_mex_mex.h"
#include "maze_init_mex_data.h"

/* Function Declarations */
static void maze_init_mex_once(const emlrtStack *sp);

/* Function Definitions */
static void maze_init_mex_once(const emlrtStack *sp)
{
  const int32_T cond_starts_1_0[1] = { 3784 };

  const int32_T cond_ends_1_0[1] = { 3806 };

  const int32_T postfix_exprs_1_0[2] = { 0, -1 };

  const int32_T cond_starts_1_1[1] = { 5694 };

  const int32_T cond_ends_1_1[1] = { 5716 };

  const int32_T postfix_exprs_1_1[2] = { 0, -1 };

  const int32_T cond_starts_1_2[1] = { 7312 };

  const int32_T cond_ends_1_2[1] = { 7334 };

  const int32_T postfix_exprs_1_2[2] = { 0, -1 };

  const int32_T cond_starts_1_3[1] = { 10245 };

  const int32_T cond_ends_1_3[1] = { 10267 };

  const int32_T postfix_exprs_1_3[2] = { 0, -1 };

  const int32_T cond_starts_1_4[2] = { 13437, 13477 };

  const int32_T cond_ends_1_4[2] = { 13471, 13511 };

  const int32_T postfix_exprs_1_4[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_5[1] = { 14138 };

  const int32_T cond_ends_1_5[1] = { 14160 };

  const int32_T postfix_exprs_1_5[2] = { 0, -1 };

  const int32_T cond_starts_1_6[1] = { 14762 };

  const int32_T cond_ends_1_6[1] = { 14784 };

  const int32_T postfix_exprs_1_6[2] = { 0, -1 };

  const int32_T cond_starts_1_7[1] = { 15287 };

  const int32_T cond_ends_1_7[1] = { 15309 };

  const int32_T postfix_exprs_1_7[2] = { 0, -1 };

  const int32_T cond_starts_1_8[1] = { 15807 };

  const int32_T cond_ends_1_8[1] = { 15829 };

  const int32_T postfix_exprs_1_8[2] = { 0, -1 };

  const int32_T cond_starts_1_9[1] = { 16332 };

  const int32_T cond_ends_1_9[1] = { 16354 };

  const int32_T postfix_exprs_1_9[2] = { 0, -1 };

  const int32_T cond_starts_1_10[2] = { 24561, 24701 };

  const int32_T cond_ends_1_10[2] = { 24676, 24814 };

  const int32_T postfix_exprs_1_10[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_11[2] = { 24879, 24990 };

  const int32_T cond_ends_1_11[2] = { 24962, 25105 };

  const int32_T postfix_exprs_1_11[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_12[2] = { 25800, 25912 };

  const int32_T cond_ends_1_12[2] = { 25884, 26029 };

  const int32_T postfix_exprs_1_12[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_13[2] = { 26749, 26889 };

  const int32_T cond_ends_1_13[2] = { 26864, 27002 };

  const int32_T postfix_exprs_1_13[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_14[2] = { 27054, 27165 };

  const int32_T cond_ends_1_14[2] = { 27137, 27280 };

  const int32_T postfix_exprs_1_14[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_15[2] = { 27988, 28100 };

  const int32_T cond_ends_1_15[2] = { 28072, 28217 };

  const int32_T postfix_exprs_1_15[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_16[2] = { 28911, 29049 };

  const int32_T cond_ends_1_16[2] = { 29024, 29164 };

  const int32_T postfix_exprs_1_16[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_17[2] = { 29216, 29327 };

  const int32_T cond_ends_1_17[2] = { 29299, 29442 };

  const int32_T postfix_exprs_1_17[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_18[2] = { 30137, 30249 };

  const int32_T cond_ends_1_18[2] = { 30221, 30366 };

  const int32_T postfix_exprs_1_18[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_19[2] = { 31068, 31206 };

  const int32_T cond_ends_1_19[2] = { 31181, 31321 };

  const int32_T postfix_exprs_1_19[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_20[2] = { 31373, 31484 };

  const int32_T cond_ends_1_20[2] = { 31456, 31599 };

  const int32_T postfix_exprs_1_20[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_21[2] = { 32302, 32414 };

  const int32_T cond_ends_1_21[2] = { 32386, 32531 };

  const int32_T postfix_exprs_1_21[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_22[2] = { 39216, 39244 };

  const int32_T cond_ends_1_22[2] = { 39239, 39259 };

  const int32_T postfix_exprs_1_22[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_23[2] = { 45502, 45530 };

  const int32_T cond_ends_1_23[2] = { 45525, 45545 };

  const int32_T postfix_exprs_1_23[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_24[2] = { 45992, 46029 };

  const int32_T cond_ends_1_24[2] = { 46024, 46060 };

  const int32_T postfix_exprs_1_24[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_25[2] = { 51130, 51158 };

  const int32_T cond_ends_1_25[2] = { 51153, 51204 };

  const int32_T postfix_exprs_1_25[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_26[2] = { 54261, 54295 };

  const int32_T cond_ends_1_26[2] = { 54289, 54323 };

  const int32_T postfix_exprs_1_26[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_27[1] = { 54470 };

  const int32_T cond_ends_1_27[1] = { 54492 };

  const int32_T postfix_exprs_1_27[2] = { 0, -1 };

  const int32_T cond_starts_1_28[1] = { 56797 };

  const int32_T cond_ends_1_28[1] = { 56819 };

  const int32_T postfix_exprs_1_28[2] = { 0, -1 };

  const int32_T cond_starts_1_29[1] = { 57375 };

  const int32_T cond_ends_1_29[1] = { 57397 };

  const int32_T postfix_exprs_1_29[2] = { 0, -1 };

  const int32_T cond_starts_1_30[1] = { 57948 };

  const int32_T cond_ends_1_30[1] = { 57970 };

  const int32_T postfix_exprs_1_30[2] = { 0, -1 };

  const int32_T cond_starts_1_31[1] = { 58543 };

  const int32_T cond_ends_1_31[1] = { 58565 };

  const int32_T postfix_exprs_1_31[2] = { 0, -1 };

  const int32_T cond_starts_1_32[3] = { 61112, 61278, 61429 };

  const int32_T cond_ends_1_32[3] = { 61249, 61423, 61445 };

  const int32_T postfix_exprs_1_32[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_33[3] = { 63931, 64095, 64244 };

  const int32_T cond_ends_1_33[3] = { 64067, 64239, 64260 };

  const int32_T postfix_exprs_1_33[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_34[3] = { 67259, 67424, 67574 };

  const int32_T cond_ends_1_34[3] = { 67396, 67569, 67590 };

  const int32_T postfix_exprs_1_34[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_35[3] = { 70292, 70456, 70605 };

  const int32_T cond_ends_1_35[3] = { 70428, 70600, 70621 };

  const int32_T postfix_exprs_1_35[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_36[2] = { 73341, 73362 };

  const int32_T cond_ends_1_36[2] = { 73357, 73393 };

  const int32_T postfix_exprs_1_36[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_37[1] = { 75073 };

  const int32_T cond_ends_1_37[1] = { 75164 };

  const int32_T postfix_exprs_1_37[2] = { 0, -1 };

  const int32_T cond_starts_1_38[1] = { 75744 };

  const int32_T cond_ends_1_38[1] = { 75834 };

  const int32_T postfix_exprs_1_38[2] = { 0, -1 };

  const int32_T cond_starts_1_39[1] = { 76413 };

  const int32_T cond_ends_1_39[1] = { 76504 };

  const int32_T postfix_exprs_1_39[2] = { 0, -1 };

  const int32_T cond_starts_1_40[1] = { 77076 };

  const int32_T cond_ends_1_40[1] = { 77166 };

  const int32_T postfix_exprs_1_40[2] = { 0, -1 };

  const int32_T cond_starts_1_41[1] = { 77914 };

  const int32_T cond_ends_1_41[1] = { 77999 };

  const int32_T postfix_exprs_1_41[2] = { 0, -1 };

  const int32_T cond_starts_1_42[1] = { 78476 };

  const int32_T cond_ends_1_42[1] = { 78560 };

  const int32_T postfix_exprs_1_42[2] = { 0, -1 };

  const int32_T cond_starts_1_43[1] = { 79037 };

  const int32_T cond_ends_1_43[1] = { 79122 };

  const int32_T postfix_exprs_1_43[2] = { 0, -1 };

  const int32_T cond_starts_1_44[1] = { 79593 };

  const int32_T cond_ends_1_44[1] = { 79677 };

  const int32_T postfix_exprs_1_44[2] = { 0, -1 };

  const int32_T cond_starts_1_45[2] = { 80565, 80725 };

  const int32_T cond_ends_1_45[2] = { 80698, 80866 };

  const int32_T postfix_exprs_1_45[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_46[2] = { 84285, 84444 };

  const int32_T cond_ends_1_46[2] = { 84417, 84584 };

  const int32_T postfix_exprs_1_46[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_47[2] = { 88065, 88226 };

  const int32_T cond_ends_1_47[2] = { 88199, 88368 };

  const int32_T postfix_exprs_1_47[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_48[2] = { 91845, 92007 };

  const int32_T cond_ends_1_48[2] = { 91980, 92150 };

  const int32_T postfix_exprs_1_48[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_49[2] = { 95619, 95780 };

  const int32_T cond_ends_1_49[2] = { 95753, 95922 };

  const int32_T postfix_exprs_1_49[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_50[2] = { 99372, 99531 };

  const int32_T cond_ends_1_50[2] = { 99504, 99671 };

  const int32_T postfix_exprs_1_50[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_51[2] = { 103260, 103420 };

  const int32_T cond_ends_1_51[2] = { 103393, 103561 };

  const int32_T postfix_exprs_1_51[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_52[2] = { 106985, 107144 };

  const int32_T cond_ends_1_52[2] = { 107117, 107284 };

  const int32_T postfix_exprs_1_52[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_53[2] = { 110694, 110854 };

  const int32_T cond_ends_1_53[2] = { 110827, 110995 };

  const int32_T postfix_exprs_1_53[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_54[2] = { 114419, 114581 };

  const int32_T cond_ends_1_54[2] = { 114554, 114724 };

  const int32_T postfix_exprs_1_54[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_55[2] = { 118123, 118284 };

  const int32_T cond_ends_1_55[2] = { 118257, 118426 };

  const int32_T postfix_exprs_1_55[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_56[2] = { 121790, 121952 };

  const int32_T cond_ends_1_56[2] = { 121925, 122095 };

  const int32_T postfix_exprs_1_56[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_57[3] = { 126899, 126974, 127011 };

  const int32_T cond_ends_1_57[3] = { 126932, 127007, 127046 };

  const int32_T postfix_exprs_1_57[5] = { 0, 1, 2, -2, -3 };

  const int32_T cond_starts_1_58[2] = { 127168, 127247 };

  const int32_T cond_ends_1_58[2] = { 127212, 127303 };

  const int32_T postfix_exprs_1_58[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_59[2] = { 127423, 127502 };

  const int32_T cond_ends_1_59[2] = { 127467, 127560 };

  const int32_T postfix_exprs_1_59[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_60[2] = { 127680, 127759 };

  const int32_T cond_ends_1_60[2] = { 127724, 127815 };

  const int32_T postfix_exprs_1_60[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_61[2] = { 127935, 128014 };

  const int32_T cond_ends_1_61[2] = { 127979, 128068 };

  const int32_T postfix_exprs_1_61[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_62[3] = { 128332, 128369, 128446 };

  const int32_T cond_ends_1_62[3] = { 128365, 128404, 128479 };

  const int32_T postfix_exprs_1_62[5] = { 0, 1, -2, 2, -3 };

  const int32_T cond_starts_1_63[2] = { 128601, 128680 };

  const int32_T cond_ends_1_63[2] = { 128645, 128736 };

  const int32_T postfix_exprs_1_63[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_64[2] = { 128855, 128934 };

  const int32_T cond_ends_1_64[2] = { 128899, 128988 };

  const int32_T postfix_exprs_1_64[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_65[2] = { 129107, 129186 };

  const int32_T cond_ends_1_65[2] = { 129151, 129242 };

  const int32_T postfix_exprs_1_65[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_66[2] = { 129361, 129440 };

  const int32_T cond_ends_1_66[2] = { 129405, 129498 };

  const int32_T postfix_exprs_1_66[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_67[5] = { 151003, 151036, 151105, 151148, 151180 };

  const int32_T cond_ends_1_67[5] = { 151031, 151075, 151144, 151176, 151208 };

  const int32_T postfix_exprs_1_67[9] = { 0, 1, -3, 2, 3, -3, 4, -3, -2 };

  const int32_T cond_starts_1_68[2] = { 151278, 151311 };

  const int32_T cond_ends_1_68[2] = { 151306, 151350 };

  const int32_T postfix_exprs_1_68[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_69[2] = { 158633, 158658 };

  const int32_T cond_ends_1_69[2] = { 158654, 158664 };

  const int32_T postfix_exprs_1_69[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_70[2] = { 162446, 162483 };

  const int32_T cond_ends_1_70[2] = { 162478, 162526 };

  const int32_T postfix_exprs_1_70[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_71[2] = { 166397, 166433 };

  const int32_T cond_ends_1_71[2] = { 166429, 166471 };

  const int32_T postfix_exprs_1_71[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_72[2] = { 166575, 166611 };

  const int32_T cond_ends_1_72[2] = { 166607, 166643 };

  const int32_T postfix_exprs_1_72[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_73[2] = { 167043, 167079 };

  const int32_T cond_ends_1_73[2] = { 167075, 167111 };

  const int32_T postfix_exprs_1_73[3] = { 0, 1, -3 };

  const int32_T caseStarts_1_0[3] = { 8424, 5425, 6703 };

  const int32_T caseExprEnds_1_0[3] = { 8433, 5449, 6729 };

  const int32_T caseStarts_1_1[5] = { 16637, 14604, 15068, 15593, 16112 };

  const int32_T caseExprEnds_1_1[5] = { 16646, 14626, 15090, 15614, 16133 };

  const int32_T caseStarts_1_2[5] = { 58867, 56599, 57122, 57700, 58289 };

  const int32_T caseExprEnds_1_2[5] = { 58876, 56621, 57144, 57721, 58310 };

  wall_sensor_left_th = 0;
  wall_sensor_left_th_dirty = 1U;
  wall_sensor_right_th = 0;
  wall_sensor_right_th_dirty = 1U;
  wall_sensor_front_th = 0;
  wall_sensor_front_th_dirty = 1U;
  turn_pattern.b_default = 0U;
  turn_pattern.r_45 = 1U;
  turn_pattern.l_45 = 2U;
  turn_pattern.r_90 = 3U;
  turn_pattern.l_90 = 4U;
  turn_pattern.r_135 = 5U;
  turn_pattern.l_135 = 6U;
  turn_pattern.r_180 = 7U;
  turn_pattern.l_180 = 8U;
  turn_pattern_dirty = 1U;
  move_dir_property.straight = 0U;
  move_dir_property.diagonal = 1U;
  move_dir_property_dirty = 1U;
  l_direction.front = 0U;
  l_direction.right = 1U;
  l_direction.back = 2U;
  l_direction.left = 3U;
  l_direction_dirty = 1U;
  g_d_direction.North = 0U;
  g_d_direction.North_East = 1U;
  g_d_direction.East = 2U;
  g_d_direction.South_East = 3U;
  g_d_direction.South = 4U;
  g_d_direction.South_West = 5U;
  g_d_direction.West = 6U;
  g_d_direction.North_West = 7U;
  g_d_direction_dirty = 1U;
  g_direction.North = 0U;
  g_direction.East = 1U;
  g_direction.South = 2U;
  g_direction.West = 3U;
  g_direction_dirty = 1U;
  matrix_dir.Row = 0U;
  matrix_dir.Col = 1U;
  matrix_dir.section = 2U;
  matrix_dir_dirty = 1U;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m", 0U, 1U, 8U,
                  6U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "maze_init", 0, -1, 1868);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 1809, -1, 1857);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 1726, -1, 1777);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1206, -1, 1652);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1062, -1, 1136);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 922, -1, 997);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 783, -1, 857);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 626, -1, 701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 143, -1, 480);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 590, 613, -1, 717);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 747, 770, -1, 870);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 900, 909, -1, 1010);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 1040, 1049, -1, 1149);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 1700, 1721, -1, 1782);
  covrtIfInit(&emlrtCoverageInstance, 0U, 5U, 1783, 1804, -1, 1862);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 510, 538, 1161);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 542, 570, 1157);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m", 1U, 30U,
                  436U, 546U, 0U, 0U, 3U, 24U, 6U, 135U, 74U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "maze_solve", 0, -1, 204513);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 1U, "search_adachi", 11649, -1, 17110);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 2U, "move_step", 17152, -1, 17722);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 3U, "turn_180deg", 17763, -1, 17900);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 4U, "turn_clk_90deg", 17948, -1,
               18086);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 5U, "turn_conclk_90deg", 18135, -1,
               18273);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 6U, "wall_set", 18306, -1, 33207);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 7U, "make_new_goal_all", 33261, -1,
               39336);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 8U, "make_new_goal_sh", 39402, -1,
               46219);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 9U, "sh_route_unexp_sq_jud", 45676,
               -1, 46206);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 10U, "make_map_find", 46271, -1,
               51275);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 11U, "get_nextdir2", 51324, -1, 52772);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 12U, "fust_run", 52810, -1, 59357);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 13U, "make_map_fustrun", 59406, -1,
               73440);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 14U, "make_map_fustrun_diagonal",
               73498, -1, 126189);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 15U, "decide_goal_node_dir", 126294,
               -1, 138322);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 16U, "decide_goal_section", 138414,
               -1, 149415);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 17U, "goal_judge", 149096, -1, 149407);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 18U, "make_route_diagonal", 149468,
               -1, 165999);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 19U, "get_turn_pattern_num", 163263,
               -1, 165991);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 20U, "get_next_dir_diagonal", 166048,
               -1, 175135);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 21U, "move_straight", 175167, -1,
               181945);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 22U, "turn_r_45", 181961, -1, 185062);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 23U, "turn_l_45", 185083, -1, 188184);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 24U, "turn_r_90", 188205, -1, 191312);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 25U, "turn_l_90", 191333, -1, 194439);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 26U, "turn_r_135", 194461, -1, 197577);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 27U, "turn_l_135", 197599, -1, 200714);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 28U, "turn_r_180", 200736, -1, 202609);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 29U, "turn_l_180", 202631, -1, 204504);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 31U, 10745, -1, 11578);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 30U, 10386, -1, 10594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 29U, 10280, -1, 10364);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 28U, 9476, -1, 10210);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 27U, 9286, -1, 9300);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 26U, 9149, -1, 9213);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 25U, 8550, -1, 9066);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 23U, 8371, -1, 8391);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 21U, 7488, -1, 7493);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 20U, 7359, -1, 7442);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 22U, 7564, -1, 8288);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 19U, 6828, -1, 7168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 18U, 6612, -1, 6632);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 16U, 5870, -1, 5875);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 15U, 5741, -1, 5824);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 17U, 5953, -1, 6511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 14U, 5486, -1, 5587);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 24U, 8466, -1, 8486);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 12U, 4834, -1, 5200);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 13U, 5240, -1, 5245);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 4648, -1, 4765);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 4556, -1, 4607);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 4492, -1, 4514);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 3913, -1, 4437);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 3815, -1, 3899);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 3565, -1, 3757);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 3176, -1, 3478);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 3004, -1, 3087);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 1330, -1, 2938);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 1091, -1, 1164);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 696, -1, 879);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 319, -1, 679);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 42U, 14356, -1, 14361);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 41U, 14181, -1, 14264);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 56U, 16762, -1, 16951);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 55U, 16523, -1, 16606);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 54U, 16375, -1, 16454);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 53U, 16150, -1, 16280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 52U, 15998, -1, 16081);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 51U, 15850, -1, 15929);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 50U, 15631, -1, 15755);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 49U, 15479, -1, 15562);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 48U, 15330, -1, 15410);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 47U, 15107, -1, 15234);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 46U, 14954, -1, 15037);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 45U, 14805, -1, 14885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 44U, 14643, -1, 14709);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 43U, 14430, -1, 14504);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 40U, 13900, -1, 13946);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 39U, 13690, -1, 13709);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 38U, 13529, -1, 13548);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 37U, 13245, -1, 13336);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 36U, 13070, -1, 13143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 35U, 12955, -1, 12979);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 34U, 12868, -1, 12890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 33U, 12558, -1, 12746);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 32U, 12058, -1, 12456);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 60U, 17656, -1, 17673);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 59U, 17541, -1, 17558);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 58U, 17426, -1, 17443);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 57U, 17311, -1, 17328);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 61U, 17848, -1, 17886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 62U, 18034, -1, 18072);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 63U, 18219, -1, 18259);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 89U, 32587, -1, 33162);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 88U, 31655, -1, 32234);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 87U, 30422, -1, 30997);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 86U, 29498, -1, 30069);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 85U, 28273, -1, 28840);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 84U, 27336, -1, 27907);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 83U, 26085, -1, 26652);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 82U, 25161, -1, 25732);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 81U, 24319, -1, 24456);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 80U, 23967, -1, 24282);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 79U, 23586, -1, 23905);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 78U, 23209, -1, 23524);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 77U, 22819, -1, 23138);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 76U, 21343, -1, 22732);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 75U, 21171, -1, 21304);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 74U, 20997, -1, 21048);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 73U, 20870, -1, 20932);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 72U, 20569, -1, 20635);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 71U, 20397, -1, 20530);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 70U, 20219, -1, 20272);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 69U, 20092, -1, 20154);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 68U, 19827, -1, 19891);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 67U, 19648, -1, 19779);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 66U, 19470, -1, 19523);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 65U, 19345, -1, 19405);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 64U, 18814, -1, 19044);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 101U, 39297, -1, 39302);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 100U, 38939, -1, 39160);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 93U, 35282, -1, 35385);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 92U, 34647, -1, 35086);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 95U, 36429, -1, 36532);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 94U, 35794, -1, 36233);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 97U, 37577, -1, 37680);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 96U, 36942, -1, 37381);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 99U, 38724, -1, 38827);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 98U, 38089, -1, 38528);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 91U, 34199, -1, 34221);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 90U, 33397, -1, 34049);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 113U, 45583, -1, 45588);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 112U, 45225, -1, 45446);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 105U, 41469, -1, 41572);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 104U, 40797, -1, 41236);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 107U, 42649, -1, 42752);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 106U, 41981, -1, 42420);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 109U, 43830, -1, 43933);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 108U, 43162, -1, 43601);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 111U, 45010, -1, 45113);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 110U, 44342, -1, 44781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 103U, 40349, -1, 40371);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 102U, 39548, -1, 40200);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 115U, 46086, -1, 46134);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 114U, 45785, -1, 45802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 124U, 51241, -1, 51246);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 123U, 50861, -1, 51082);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 122U, 50346, -1, 50772);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 121U, 49510, -1, 49936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 120U, 48673, -1, 49099);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 119U, 47839, -1, 48263);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 118U, 47267, -1, 47289);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 117U, 46941, -1, 47154);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 116U, 46459, -1, 46879);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 129U, 52716, -1, 52743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 128U, 52383, -1, 52468);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 127U, 52104, -1, 52188);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 126U, 51805, -1, 51915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 125U, 51483, -1, 51532);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 135U, 54622, -1, 54627);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 134U, 54509, -1, 54592);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 156U, 59232, -1, 59280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 155U, 58988, -1, 59164);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 154U, 58755, -1, 58816);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 153U, 58590, -1, 58669);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 152U, 58327, -1, 58436);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 151U, 58160, -1, 58221);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 150U, 57995, -1, 58074);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 149U, 57738, -1, 57841);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 148U, 57588, -1, 57649);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 147U, 57422, -1, 57502);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 146U, 57161, -1, 57267);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 145U, 57010, -1, 57071);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 144U, 56844, -1, 56924);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 143U, 56638, -1, 56689);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 142U, 56432, -1, 56468);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 141U, 56277, -1, 56313);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 140U, 56122, -1, 56158);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 139U, 55870, -1, 55952);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 138U, 55572, -1, 55655);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 137U, 55274, -1, 55356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 136U, 54947, -1, 55059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 133U, 54341, -1, 54361);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 132U, 54064, -1, 54176);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 131U, 53860, -1, 53892);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 130U, 53130, -1, 53742);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 169U, 73406, -1, 73411);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 168U, 73068, -1, 73289);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 167U, 72233, -1, 72955);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 166U, 71088, -1, 71804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 165U, 69407, -1, 70130);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 164U, 68286, -1, 69003);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 163U, 66375, -1, 67097);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 162U, 64955, -1, 65671);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 161U, 63034, -1, 63757);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 160U, 61913, -1, 62630);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 159U, 60901, -1, 60923);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 158U, 60333, -1, 60809);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 157U, 59639, -1, 60216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 230U, 126089, -1, 126160);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 229U, 125534, -1, 126002);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 228U, 125215, -1, 125411);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 227U, 124202, -1, 124929);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 226U, 123607, -1, 123803);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 225U, 122561, -1, 123292);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 224U, 121467, -1, 121653);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 223U, 120469, -1, 121184);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 222U, 119888, -1, 120074);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 221U, 118882, -1, 119601);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 220U, 117795, -1, 117987);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 219U, 116790, -1, 117511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 218U, 116201, -1, 116393);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 217U, 115188, -1, 115913);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 216U, 114063, -1, 114251);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 215U, 113066, -1, 113781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 214U, 112462, -1, 112650);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 213U, 111457, -1, 112176);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 212U, 110350, -1, 110536);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 211U, 109352, -1, 110067);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 210U, 108771, -1, 108957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 209U, 107740, -1, 108459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 208U, 106657, -1, 106849);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 207U, 105627, -1, 106348);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 206U, 105038, -1, 105230);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 205U, 104025, -1, 104750);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 204U, 102768, -1, 102956);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 203U, 101746, -1, 102461);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 202U, 101163, -1, 101351);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 201U, 100133, -1, 100852);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 200U, 99043, -1, 99235);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 199U, 98013, -1, 98734);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 198U, 97424, -1, 97616);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 197U, 96386, -1, 97111);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 196U, 95295, -1, 95482);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 195U, 94271, -1, 94987);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 194U, 93664, -1, 93851);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 193U, 92607, -1, 93352);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 192U, 91513, -1, 91709);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 191U, 90475, -1, 91202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 190U, 89880, -1, 90076);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 189U, 88834, -1, 89565);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 188U, 87705, -1, 87897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 187U, 86675, -1, 87396);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 186U, 86086, -1, 86278);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 185U, 85048, -1, 85773);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 184U, 83961, -1, 84148);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 183U, 82937, -1, 83653);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 182U, 82355, -1, 82542);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 181U, 81323, -1, 82043);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 180U, 80361, -1, 80383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 179U, 79716, -1, 80085);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 178U, 79161, -1, 79530);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 177U, 78599, -1, 78974);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 176U, 78038, -1, 78413);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 175U, 77197, -1, 77690);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 174U, 76535, -1, 77029);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 173U, 75865, -1, 76366);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 172U, 75195, -1, 75697);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 171U, 74978, -1, 75009);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 170U, 73773, -1, 74946);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 243U, 130259, -1, 130264);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 257U, 138206, -1, 138280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 256U, 137687, -1, 138053);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 255U, 137091, -1, 137446);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 254U, 136496, -1, 136858);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 253U, 135817, -1, 136175);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 252U, 135225, -1, 135580);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 251U, 134630, -1, 134992);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 250U, 133877, -1, 134234);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 249U, 133198, -1, 133559);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 248U, 132603, -1, 132959);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 247U, 132004, -1, 132369);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 246U, 131321, -1, 131682);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 245U, 130726, -1, 131082);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 244U, 130404, -1, 130438);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 242U, 129631, -1, 129651);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 241U, 129523, -1, 129560);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 240U, 129267, -1, 129304);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 239U, 129013, -1, 129050);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 238U, 128761, -1, 128798);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 237U, 128223, -1, 128243);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 236U, 128093, -1, 128131);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 235U, 127840, -1, 127878);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 234U, 127585, -1, 127623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 233U, 127328, -1, 127366);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 232U, 126749, -1, 126769);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 231U, 126439, -1, 126718);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 298U, 148855, -1, 149014);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 297U, 148659, -1, 148820);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 296U, 148407, -1, 148572);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 295U, 148153, -1, 148318);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 294U, 147882, -1, 148039);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 293U, 147686, -1, 147847);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 292U, 147440, -1, 147599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 291U, 147188, -1, 147353);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 290U, 146823, -1, 146982);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 289U, 146627, -1, 146788);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 288U, 146250, -1, 146409);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 287U, 146054, -1, 146215);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 286U, 145804, -1, 145967);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 285U, 145550, -1, 145715);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 284U, 145277, -1, 145436);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 283U, 145081, -1, 145242);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 282U, 144831, -1, 144994);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 281U, 144577, -1, 144742);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 280U, 144212, -1, 144371);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 279U, 144016, -1, 144177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 278U, 143660, -1, 143817);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 277U, 143464, -1, 143625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 276U, 143218, -1, 143377);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 275U, 142966, -1, 143131);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 274U, 142693, -1, 142852);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 273U, 142497, -1, 142658);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 272U, 142245, -1, 142410);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 271U, 141991, -1, 142156);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 270U, 141628, -1, 141785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 269U, 141432, -1, 141593);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 268U, 141057, -1, 141214);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 267U, 140861, -1, 141022);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 266U, 140613, -1, 140774);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 265U, 140361, -1, 140526);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 264U, 140090, -1, 140247);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 263U, 139894, -1, 140055);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 262U, 139646, -1, 139807);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 261U, 139394, -1, 139559);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 260U, 139011, -1, 139168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 259U, 138815, -1, 138976);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 258U, 138540, -1, 138643);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 299U, 149177, -1, 149381);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 330U, 162885, -1, 162890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 331U, 162961, -1, 163153);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 329U, 162622, -1, 162786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 328U, 162544, -1, 162557);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 327U, 162077, -1, 162256);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 326U, 161704, -1, 161883);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 325U, 161330, -1, 161509);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 324U, 160957, -1, 161136);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 323U, 160584, -1, 160762);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 322U, 159997, -1, 160175);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 321U, 159408, -1, 159586);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 320U, 159038, -1, 159216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 318U, 158264, -1, 158269);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 317U, 158119, -1, 158218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 319U, 158345, -1, 158552);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 316U, 157733, -1, 157925);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 315U, 157415, -1, 157443);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 314U, 156973, -1, 157184);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 313U, 156797, -1, 156896);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 312U, 156518, -1, 156531);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 311U, 156046, -1, 156265);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 310U, 155846, -1, 155945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 309U, 155075, -1, 155265);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 308U, 154621, -1, 154811);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 307U, 153842, -1, 153941);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 306U, 153365, -1, 153725);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 305U, 152914, -1, 153137);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 304U, 152702, -1, 152801);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 303U, 151772, -1, 152104);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 302U, 151419, -1, 151623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 301U, 150748, -1, 150956);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 300U, 149597, -1, 150455);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 346U, 165728, -1, 165765);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 345U, 165615, -1, 165651);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 344U, 165459, -1, 165495);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 343U, 165301, -1, 165338);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 342U, 165188, -1, 165224);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 341U, 165032, -1, 165068);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 340U, 164732, -1, 164769);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 339U, 164610, -1, 164647);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 338U, 164442, -1, 164478);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 337U, 164329, -1, 164365);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 336U, 164079, -1, 164116);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 335U, 163957, -1, 163994);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 334U, 163789, -1, 163825);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 333U, 163676, -1, 163712);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 332U, 163396, -1, 163435);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 365U, 174618, -1, 174979);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 364U, 173962, -1, 174312);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 363U, 173307, -1, 173664);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 362U, 172624, -1, 172957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 361U, 172077, -1, 172407);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 360U, 171527, -1, 171864);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 359U, 170838, -1, 171171);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 358U, 170211, -1, 170548);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 357U, 169661, -1, 169992);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 356U, 169106, -1, 169447);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 355U, 168475, -1, 168812);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 354U, 167925, -1, 168256);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 353U, 167627, -1, 167661);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 352U, 167538, -1, 167561);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 351U, 167308, -1, 167455);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 350U, 167128, -1, 167273);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 349U, 166822, -1, 166970);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 348U, 166660, -1, 166787);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 347U, 166257, -1, 166358);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 379U, 181911, -1, 181936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 378U, 181215, -1, 181482);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 377U, 180842, -1, 181121);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 376U, 180155, -1, 180428);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 375U, 179788, -1, 180061);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 374U, 179095, -1, 179374);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 373U, 178734, -1, 179001);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 372U, 178047, -1, 178320);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 371U, 177680, -1, 177953);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 370U, 177405, -1, 177542);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 369U, 176769, -1, 176995);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 368U, 176348, -1, 176575);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 367U, 175928, -1, 176154);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 366U, 175507, -1, 175734);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 387U, 184572, -1, 184788);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 386U, 184272, -1, 184485);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 385U, 183973, -1, 184185);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 384U, 183673, -1, 183886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 383U, 183172, -1, 183393);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 382U, 182872, -1, 183091);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 381U, 182571, -1, 182790);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 380U, 182269, -1, 182490);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 395U, 187699, -1, 187910);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 394U, 187398, -1, 187612);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 393U, 187096, -1, 187311);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 392U, 186795, -1, 187009);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 391U, 186296, -1, 186515);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 390U, 185994, -1, 186215);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 389U, 185691, -1, 185912);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 388U, 185391, -1, 185610);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 403U, 190827, -1, 191046);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 402U, 190521, -1, 190740);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 401U, 190215, -1, 190434);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 400U, 189909, -1, 190128);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 399U, 189399, -1, 189615);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 398U, 189105, -1, 189318);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 397U, 188809, -1, 189023);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 396U, 188513, -1, 188728);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 411U, 193955, -1, 194174);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 410U, 193649, -1, 193868);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 409U, 193343, -1, 193562);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 408U, 193037, -1, 193256);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 407U, 192529, -1, 192743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 406U, 192233, -1, 192448);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 405U, 191935, -1, 192151);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 404U, 191641, -1, 191854);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 419U, 197089, -1, 197302);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 418U, 196788, -1, 197002);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 417U, 196488, -1, 196701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 416U, 196187, -1, 196401);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 415U, 195677, -1, 195898);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 414U, 195375, -1, 195596);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 413U, 195072, -1, 195293);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 412U, 194770, -1, 194991);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 427U, 200226, -1, 200440);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 426U, 199926, -1, 200139);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 425U, 199625, -1, 199839);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 424U, 199325, -1, 199538);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 423U, 198815, -1, 199036);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 422U, 198513, -1, 198734);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 421U, 198210, -1, 198431);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 420U, 197908, -1, 198129);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 431U, 201936, -1, 202151);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 430U, 201639, -1, 201855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 429U, 201342, -1, 201557);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 428U, 201045, -1, 201261);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 435U, 203831, -1, 204046);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 434U, 203534, -1, 203750);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 433U, 203237, -1, 203452);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 432U, 202940, -1, 203156);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 284, 309, 310, 684);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 1061, 1086, -1, 1169);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 2946, 2978, 9319, 9357);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 3098, 3123, 3511, 3542);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 3780, 3806, -1, 3908);
  covrtIfInit(&emlrtCoverageInstance, 1U, 5U, 4621, 4631, 4790, 4793);
  covrtIfInit(&emlrtCoverageInstance, 1U, 6U, 4802, 4821, 5223, 5257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 7U, 5605, 5625, 5928, 6545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 8U, 5690, 5716, -1, 5849);
  covrtIfInit(&emlrtCoverageInstance, 1U, 9U, 7219, 7243, 8315, 8318);
  covrtIfInit(&emlrtCoverageInstance, 1U, 10U, 7308, 7334, -1, 7467);
  covrtIfInit(&emlrtCoverageInstance, 1U, 11U, 9077, 9102, 9219, 9260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 12U, 9319, 9357, -1, 9357);
  covrtIfInit(&emlrtCoverageInstance, 1U, 13U, 9362, 9404, 10637, 10683);
  covrtIfInit(&emlrtCoverageInstance, 1U, 14U, 10241, 10267, -1, 10377);
  covrtIfInit(&emlrtCoverageInstance, 1U, 15U, 10637, 10683, -1, 10683);
  covrtIfInit(&emlrtCoverageInstance, 1U, 16U, 12523, 12545, 12916, 13005);
  covrtIfInit(&emlrtCoverageInstance, 1U, 17U, 12800, 12851, -1, 12907);
  covrtIfInit(&emlrtCoverageInstance, 1U, 18U, 13032, 13057, -1, 13156);
  covrtIfInit(&emlrtCoverageInstance, 1U, 19U, 13217, 13232, -1, 13349);
  covrtIfInit(&emlrtCoverageInstance, 1U, 20U, 13433, 13512, -1, 13565);
  covrtIfInit(&emlrtCoverageInstance, 1U, 21U, 13632, 13677, -1, 13994);
  covrtIfInit(&emlrtCoverageInstance, 1U, 22U, 13807, 13879, -1, 13966);
  covrtIfInit(&emlrtCoverageInstance, 1U, 23U, 14028, 14044, -1, 14373);
  covrtIfInit(&emlrtCoverageInstance, 1U, 24U, 14057, 14073, -1, 14301);
  covrtIfInit(&emlrtCoverageInstance, 1U, 25U, 14134, 14160, -1, 14285);
  covrtIfInit(&emlrtCoverageInstance, 1U, 26U, 14758, 14784, -1, 14906);
  covrtIfInit(&emlrtCoverageInstance, 1U, 27U, 15283, 15309, -1, 15431);
  covrtIfInit(&emlrtCoverageInstance, 1U, 28U, 15803, 15829, -1, 15950);
  covrtIfInit(&emlrtCoverageInstance, 1U, 29U, 16328, 16354, -1, 16475);
  covrtIfInit(&emlrtCoverageInstance, 1U, 30U, 16676, 16701, 17045, 17094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 31U, 17270, 17302, -1, 17365);
  covrtIfInit(&emlrtCoverageInstance, 1U, 32U, 17386, 17417, -1, 17479);
  covrtIfInit(&emlrtCoverageInstance, 1U, 33U, 17500, 17532, -1, 17595);
  covrtIfInit(&emlrtCoverageInstance, 1U, 34U, 17616, 17647, -1, 17709);
  covrtIfInit(&emlrtCoverageInstance, 1U, 35U, 19146, 19171, 19423, 19809);
  covrtIfInit(&emlrtCoverageInstance, 1U, 36U, 19229, 19304, -1, 19418);
  covrtIfInit(&emlrtCoverageInstance, 1U, 37U, 19559, 19616, -1, 19792);
  covrtIfInit(&emlrtCoverageInstance, 1U, 38U, 19912, 19937, 20172, 20551);
  covrtIfInit(&emlrtCoverageInstance, 1U, 39U, 19995, 20079, -1, 20167);
  covrtIfInit(&emlrtCoverageInstance, 1U, 40U, 20308, 20365, -1, 20543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 41U, 20690, 20715, 20950, 21325);
  covrtIfInit(&emlrtCoverageInstance, 1U, 42U, 20773, 20857, -1, 20945);
  covrtIfInit(&emlrtCoverageInstance, 1U, 43U, 21084, 21139, -1, 21317);
  covrtIfInit(&emlrtCoverageInstance, 1U, 44U, 22780, 22810, -1, 23147);
  covrtIfInit(&emlrtCoverageInstance, 1U, 45U, 23170, 23200, -1, 23533);
  covrtIfInit(&emlrtCoverageInstance, 1U, 46U, 23561, 23577, -1, 23914);
  covrtIfInit(&emlrtCoverageInstance, 1U, 47U, 23942, 23958, -1, 24291);
  covrtIfInit(&emlrtCoverageInstance, 1U, 48U, 24462, 24470, -1, 33199);
  covrtIfInit(&emlrtCoverageInstance, 1U, 49U, 24557, 24815, -1, 26707);
  covrtIfInit(&emlrtCoverageInstance, 1U, 50U, 24876, 25106, -1, 25749);
  covrtIfInit(&emlrtCoverageInstance, 1U, 51U, 25797, 26030, -1, 26669);
  covrtIfInit(&emlrtCoverageInstance, 1U, 52U, 26745, 27003, -1, 28869);
  covrtIfInit(&emlrtCoverageInstance, 1U, 53U, 27051, 27281, -1, 27924);
  covrtIfInit(&emlrtCoverageInstance, 1U, 54U, 27985, 28218, -1, 28857);
  covrtIfInit(&emlrtCoverageInstance, 1U, 55U, 28907, 29165, -1, 31026);
  covrtIfInit(&emlrtCoverageInstance, 1U, 56U, 29213, 29443, -1, 30086);
  covrtIfInit(&emlrtCoverageInstance, 1U, 57U, 30134, 30367, -1, 31014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 58U, 31064, 31322, -1, 33191);
  covrtIfInit(&emlrtCoverageInstance, 1U, 59U, 31370, 31600, -1, 32251);
  covrtIfInit(&emlrtCoverageInstance, 1U, 60U, 32299, 32532, -1, 33179);
  covrtIfInit(&emlrtCoverageInstance, 1U, 61U, 34339, 34472, -1, 35445);
  covrtIfInit(&emlrtCoverageInstance, 1U, 62U, 34537, 34626, -1, 35429);
  covrtIfInit(&emlrtCoverageInstance, 1U, 63U, 35171, 35257, -1, 35409);
  covrtIfInit(&emlrtCoverageInstance, 1U, 64U, 35487, 35619, -1, 36592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 65U, 35684, 35773, -1, 36576);
  covrtIfInit(&emlrtCoverageInstance, 1U, 66U, 36318, 36404, -1, 36556);
  covrtIfInit(&emlrtCoverageInstance, 1U, 67U, 36634, 36767, -1, 37740);
  covrtIfInit(&emlrtCoverageInstance, 1U, 68U, 36832, 36921, -1, 37724);
  covrtIfInit(&emlrtCoverageInstance, 1U, 69U, 37466, 37552, -1, 37704);
  covrtIfInit(&emlrtCoverageInstance, 1U, 70U, 37782, 37914, -1, 38887);
  covrtIfInit(&emlrtCoverageInstance, 1U, 71U, 37979, 38068, -1, 38871);
  covrtIfInit(&emlrtCoverageInstance, 1U, 72U, 38613, 38699, -1, 38851);
  covrtIfInit(&emlrtCoverageInstance, 1U, 73U, 39213, 39259, -1, 39315);
  covrtIfInit(&emlrtCoverageInstance, 1U, 74U, 40489, 40622, -1, 41632);
  covrtIfInit(&emlrtCoverageInstance, 1U, 75U, 40687, 40776, -1, 41616);
  covrtIfInit(&emlrtCoverageInstance, 1U, 76U, 41325, 41444, -1, 41596);
  covrtIfInit(&emlrtCoverageInstance, 1U, 77U, 41674, 41806, -1, 42812);
  covrtIfInit(&emlrtCoverageInstance, 1U, 78U, 41871, 41960, -1, 42796);
  covrtIfInit(&emlrtCoverageInstance, 1U, 79U, 42505, 42624, -1, 42776);
  covrtIfInit(&emlrtCoverageInstance, 1U, 80U, 42854, 42987, -1, 43993);
  covrtIfInit(&emlrtCoverageInstance, 1U, 81U, 43052, 43141, -1, 43977);
  covrtIfInit(&emlrtCoverageInstance, 1U, 82U, 43686, 43805, -1, 43957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 83U, 44035, 44167, -1, 45173);
  covrtIfInit(&emlrtCoverageInstance, 1U, 84U, 44232, 44321, -1, 45157);
  covrtIfInit(&emlrtCoverageInstance, 1U, 85U, 44866, 44985, -1, 45137);
  covrtIfInit(&emlrtCoverageInstance, 1U, 86U, 45499, 45545, -1, 45601);
  covrtIfInit(&emlrtCoverageInstance, 1U, 87U, 45816, 45845, 45858, 46194);
  covrtIfInit(&emlrtCoverageInstance, 1U, 88U, 45988, 46061, -1, 46158);
  covrtIfInit(&emlrtCoverageInstance, 1U, 89U, 47507, 47664, -1, 48300);
  covrtIfInit(&emlrtCoverageInstance, 1U, 90U, 47729, 47818, -1, 48284);
  covrtIfInit(&emlrtCoverageInstance, 1U, 91U, 48342, 48498, -1, 49136);
  covrtIfInit(&emlrtCoverageInstance, 1U, 92U, 48563, 48652, -1, 49120);
  covrtIfInit(&emlrtCoverageInstance, 1U, 93U, 49178, 49335, -1, 49973);
  covrtIfInit(&emlrtCoverageInstance, 1U, 94U, 49400, 49489, -1, 49957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 95U, 50015, 50171, -1, 50809);
  covrtIfInit(&emlrtCoverageInstance, 1U, 96U, 50236, 50325, -1, 50793);
  covrtIfInit(&emlrtCoverageInstance, 1U, 97U, 51127, 51204, -1, 51259);
  covrtIfInit(&emlrtCoverageInstance, 1U, 98U, 51596, 51679, -1, 51936);
  covrtIfInit(&emlrtCoverageInstance, 1U, 99U, 51717, 51763, -1, 51928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 100U, 51954, 52036, -1, 52209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 101U, 52045, 52091, -1, 52201);
  covrtIfInit(&emlrtCoverageInstance, 1U, 102U, 52232, 52315, -1, 52489);
  covrtIfInit(&emlrtCoverageInstance, 1U, 103U, 52324, 52370, -1, 52481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 104U, 52507, 52589, -1, 52764);
  covrtIfInit(&emlrtCoverageInstance, 1U, 105U, 52598, 52644, -1, 52756);
  covrtIfInit(&emlrtCoverageInstance, 1U, 106U, 53796, 53821, -1, 53901);
  covrtIfInit(&emlrtCoverageInstance, 1U, 107U, 53969, 54009, -1, 54189);
  covrtIfInit(&emlrtCoverageInstance, 1U, 108U, 54257, 54324, -1, 54378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 109U, 54408, 54425, -1, 54639);
  covrtIfInit(&emlrtCoverageInstance, 1U, 110U, 54466, 54492, -1, 54609);
  covrtIfInit(&emlrtCoverageInstance, 1U, 111U, 54724, 54811, -1, 55088);
  covrtIfInit(&emlrtCoverageInstance, 1U, 112U, 54857, 54897, -1, 55076);
  covrtIfInit(&emlrtCoverageInstance, 1U, 113U, 55118, 55204, -1, 55385);
  covrtIfInit(&emlrtCoverageInstance, 1U, 114U, 55217, 55257, -1, 55373);
  covrtIfInit(&emlrtCoverageInstance, 1U, 115U, 55415, 55502, -1, 55684);
  covrtIfInit(&emlrtCoverageInstance, 1U, 116U, 55515, 55555, -1, 55672);
  covrtIfInit(&emlrtCoverageInstance, 1U, 117U, 55714, 55800, -1, 55981);
  covrtIfInit(&emlrtCoverageInstance, 1U, 118U, 55813, 55853, -1, 55969);
  covrtIfInit(&emlrtCoverageInstance, 1U, 119U, 56038, 56109, -1, 56171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 120U, 56191, 56264, -1, 56326);
  covrtIfInit(&emlrtCoverageInstance, 1U, 121U, 56346, 56419, -1, 56481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 122U, 56738, 56752, -1, 57092);
  covrtIfInit(&emlrtCoverageInstance, 1U, 123U, 56793, 56819, -1, 56949);
  covrtIfInit(&emlrtCoverageInstance, 1U, 124U, 57316, 57330, -1, 57670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 125U, 57371, 57397, -1, 57527);
  covrtIfInit(&emlrtCoverageInstance, 1U, 126U, 57889, 57903, -1, 58242);
  covrtIfInit(&emlrtCoverageInstance, 1U, 127U, 57944, 57970, -1, 58099);
  covrtIfInit(&emlrtCoverageInstance, 1U, 128U, 58484, 58498, -1, 58837);
  covrtIfInit(&emlrtCoverageInstance, 1U, 129U, 58539, 58565, -1, 58694);
  covrtIfInit(&emlrtCoverageInstance, 1U, 130U, 58906, 58931, 59174, 59223);
  covrtIfInit(&emlrtCoverageInstance, 1U, 131U, 61109, 61446, -1, 63818);
  covrtIfInit(&emlrtCoverageInstance, 1U, 132U, 61512, 61640, 62730, 63802);
  covrtIfInit(&emlrtCoverageInstance, 1U, 133U, 61705, 61855, -1, 62655);
  covrtIfInit(&emlrtCoverageInstance, 1U, 134U, 62804, 62968, -1, 63782);
  covrtIfInit(&emlrtCoverageInstance, 1U, 135U, 63928, 64261, -1, 67158);
  covrtIfInit(&emlrtCoverageInstance, 1U, 136U, 64327, 64454, 65771, 67142);
  covrtIfInit(&emlrtCoverageInstance, 1U, 137U, 64519, 64669, -1, 65696);
  covrtIfInit(&emlrtCoverageInstance, 1U, 138U, 65845, 66009, -1, 67122);
  covrtIfInit(&emlrtCoverageInstance, 1U, 139U, 67256, 67591, -1, 70191);
  covrtIfInit(&emlrtCoverageInstance, 1U, 140U, 67657, 67785, 69103, 70175);
  covrtIfInit(&emlrtCoverageInstance, 1U, 141U, 67850, 68000, -1, 69028);
  covrtIfInit(&emlrtCoverageInstance, 1U, 142U, 69177, 69341, -1, 70155);
  covrtIfInit(&emlrtCoverageInstance, 1U, 143U, 70289, 70622, -1, 73016);
  covrtIfInit(&emlrtCoverageInstance, 1U, 144U, 70688, 70815, 71929, 73000);
  covrtIfInit(&emlrtCoverageInstance, 1U, 145U, 70880, 71030, -1, 71854);
  covrtIfInit(&emlrtCoverageInstance, 1U, 146U, 72003, 72167, -1, 72980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 147U, 73337, 73393, -1, 73424);
  covrtIfInit(&emlrtCoverageInstance, 1U, 148U, 74952, 74969, 77745, 80277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 149U, 75069, 75164, -1, 75710);
  covrtIfInit(&emlrtCoverageInstance, 1U, 150U, 75740, 75834, -1, 76379);
  covrtIfInit(&emlrtCoverageInstance, 1U, 151U, 76409, 76504, -1, 77042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 152U, 77072, 77166, -1, 77703);
  covrtIfInit(&emlrtCoverageInstance, 1U, 153U, 77910, 77999, -1, 78430);
  covrtIfInit(&emlrtCoverageInstance, 1U, 154U, 78472, 78560, -1, 78991);
  covrtIfInit(&emlrtCoverageInstance, 1U, 155U, 79033, 79122, -1, 79547);
  covrtIfInit(&emlrtCoverageInstance, 1U, 156U, 79589, 79677, -1, 80102);
  covrtIfInit(&emlrtCoverageInstance, 1U, 157U, 80562, 80866, -1, 84209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 158U, 80915, 81041, 82642, 84193);
  covrtIfInit(&emlrtCoverageInstance, 1U, 159U, 81107, 81265, 82134, 82297);
  covrtIfInit(&emlrtCoverageInstance, 1U, 160U, 82134, 82297, -1, 82297);
  covrtIfInit(&emlrtCoverageInstance, 1U, 161U, 82717, 82871, 83744, 83903);
  covrtIfInit(&emlrtCoverageInstance, 1U, 162U, 83744, 83903, -1, 83903);
  covrtIfInit(&emlrtCoverageInstance, 1U, 163U, 84282, 84584, -1, 87958);
  covrtIfInit(&emlrtCoverageInstance, 1U, 164U, 84634, 84765, 86379, 87942);
  covrtIfInit(&emlrtCoverageInstance, 1U, 165U, 84832, 84990, 85865, 86028);
  covrtIfInit(&emlrtCoverageInstance, 1U, 166U, 85865, 86028, -1, 86028);
  covrtIfInit(&emlrtCoverageInstance, 1U, 167U, 86455, 86609, 87488, 87647);
  covrtIfInit(&emlrtCoverageInstance, 1U, 168U, 87488, 87647, -1, 87647);
  covrtIfInit(&emlrtCoverageInstance, 1U, 169U, 88062, 88368, -1, 91770);
  covrtIfInit(&emlrtCoverageInstance, 1U, 170U, 88418, 88549, 90177, 91754);
  covrtIfInit(&emlrtCoverageInstance, 1U, 171U, 88616, 88776, 89657, 89822);
  covrtIfInit(&emlrtCoverageInstance, 1U, 172U, 89657, 89822, -1, 89822);
  covrtIfInit(&emlrtCoverageInstance, 1U, 173U, 90253, 90409, 91294, 91455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 174U, 91294, 91455, -1, 91455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 175U, 91842, 92150, -1, 95543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 176U, 92199, 92325, 93951, 95527);
  covrtIfInit(&emlrtCoverageInstance, 1U, 177U, 92391, 92549, 93443, 93606);
  covrtIfInit(&emlrtCoverageInstance, 1U, 178U, 93443, 93606, -1, 93606);
  covrtIfInit(&emlrtCoverageInstance, 1U, 179U, 94026, 94180, 95078, 95237);
  covrtIfInit(&emlrtCoverageInstance, 1U, 180U, 95078, 95237, -1, 95237);
  covrtIfInit(&emlrtCoverageInstance, 1U, 181U, 95616, 95922, -1, 99296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 182U, 95972, 96103, 97717, 99280);
  covrtIfInit(&emlrtCoverageInstance, 1U, 183U, 96170, 96328, 97203, 97366);
  covrtIfInit(&emlrtCoverageInstance, 1U, 184U, 97203, 97366, -1, 97366);
  covrtIfInit(&emlrtCoverageInstance, 1U, 185U, 97793, 97947, 98826, 98985);
  covrtIfInit(&emlrtCoverageInstance, 1U, 186U, 98826, 98985, -1, 98985);
  covrtIfInit(&emlrtCoverageInstance, 1U, 187U, 99369, 99671, -1, 103017);
  covrtIfInit(&emlrtCoverageInstance, 1U, 188U, 99721, 99852, 101452, 103001);
  covrtIfInit(&emlrtCoverageInstance, 1U, 189U, 99919, 100075, 100944, 101105);
  covrtIfInit(&emlrtCoverageInstance, 1U, 190U, 100944, 101105, -1, 101105);
  covrtIfInit(&emlrtCoverageInstance, 1U, 191U, 101528, 101680, 102553, 102710);
  covrtIfInit(&emlrtCoverageInstance, 1U, 192U, 102553, 102710, -1, 102710);
  covrtIfInit(&emlrtCoverageInstance, 1U, 193U, 103257, 103561, -1, 106910);
  covrtIfInit(&emlrtCoverageInstance, 1U, 194U, 103611, 103742, 105331, 106894);
  covrtIfInit(&emlrtCoverageInstance, 1U, 195U, 103809, 103967, 104817, 104980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 196U, 104817, 104980, -1, 104980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 197U, 105407, 105561, 106440, 106599);
  covrtIfInit(&emlrtCoverageInstance, 1U, 198U, 106440, 106599, -1, 106599);
  covrtIfInit(&emlrtCoverageInstance, 1U, 199U, 106982, 107284, -1, 110618);
  covrtIfInit(&emlrtCoverageInstance, 1U, 200U, 107333, 107458, 109057, 110602);
  covrtIfInit(&emlrtCoverageInstance, 1U, 201U, 107524, 107682, 108550, 108713);
  covrtIfInit(&emlrtCoverageInstance, 1U, 202U, 108550, 108713, -1, 108713);
  covrtIfInit(&emlrtCoverageInstance, 1U, 203U, 109132, 109286, 110133, 110292);
  covrtIfInit(&emlrtCoverageInstance, 1U, 204U, 110133, 110292, -1, 110292);
  covrtIfInit(&emlrtCoverageInstance, 1U, 205U, 110691, 110995, -1, 114312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 206U, 111045, 111176, 112772, 114296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 207U, 111243, 111399, 112243, 112404);
  covrtIfInit(&emlrtCoverageInstance, 1U, 208U, 112243, 112404, -1, 112404);
  covrtIfInit(&emlrtCoverageInstance, 1U, 209U, 112848, 113000, 113848, 114005);
  covrtIfInit(&emlrtCoverageInstance, 1U, 210U, 113848, 114005, -1, 114005);
  covrtIfInit(&emlrtCoverageInstance, 1U, 211U, 114416, 114724, -1, 118048);
  covrtIfInit(&emlrtCoverageInstance, 1U, 212U, 114774, 114905, 116494, 118032);
  covrtIfInit(&emlrtCoverageInstance, 1U, 213U, 114972, 115130, 115980, 116143);
  covrtIfInit(&emlrtCoverageInstance, 1U, 214U, 115980, 116143, -1, 116143);
  covrtIfInit(&emlrtCoverageInstance, 1U, 215U, 116570, 116724, 117578, 117737);
  covrtIfInit(&emlrtCoverageInstance, 1U, 216U, 117578, 117737, -1, 117737);
  covrtIfInit(&emlrtCoverageInstance, 1U, 217U, 118120, 118426, -1, 121714);
  covrtIfInit(&emlrtCoverageInstance, 1U, 218U, 118475, 118600, 120174, 121698);
  covrtIfInit(&emlrtCoverageInstance, 1U, 219U, 118666, 118824, 119667, 119830);
  covrtIfInit(&emlrtCoverageInstance, 1U, 220U, 119667, 119830, -1, 119830);
  covrtIfInit(&emlrtCoverageInstance, 1U, 221U, 120249, 120403, 121250, 121409);
  covrtIfInit(&emlrtCoverageInstance, 1U, 222U, 121250, 121409, -1, 121409);
  covrtIfInit(&emlrtCoverageInstance, 1U, 223U, 121787, 122095, -1, 125472);
  covrtIfInit(&emlrtCoverageInstance, 1U, 224U, 122145, 122276, 123904, 125456);
  covrtIfInit(&emlrtCoverageInstance, 1U, 225U, 122343, 122503, 123384, 123549);
  covrtIfInit(&emlrtCoverageInstance, 1U, 226U, 123384, 123549, -1, 123549);
  covrtIfInit(&emlrtCoverageInstance, 1U, 227U, 123980, 124136, 124996, 125157);
  covrtIfInit(&emlrtCoverageInstance, 1U, 228U, 124996, 125157, -1, 125157);
  covrtIfInit(&emlrtCoverageInstance, 1U, 229U, 126057, 126076, -1, 126173);
  covrtIfInit(&emlrtCoverageInstance, 1U, 230U, 126839, 126878, 128307, 129688);
  covrtIfInit(&emlrtCoverageInstance, 1U, 231U, 126895, 127047, -1, 128264);
  covrtIfInit(&emlrtCoverageInstance, 1U, 232U, 127165, 127303, 127416, 127560);
  covrtIfInit(&emlrtCoverageInstance, 1U, 233U, 127416, 127560, 127673, 128156);
  covrtIfInit(&emlrtCoverageInstance, 1U, 234U, 127673, 127815, 127928, 128156);
  covrtIfInit(&emlrtCoverageInstance, 1U, 235U, 127928, 128068, -1, 128068);
  covrtIfInit(&emlrtCoverageInstance, 1U, 236U, 128328, 128480, -1, 129672);
  covrtIfInit(&emlrtCoverageInstance, 1U, 237U, 128598, 128736, 128848, 128988);
  covrtIfInit(&emlrtCoverageInstance, 1U, 238U, 128848, 128988, 129100, 129585);
  covrtIfInit(&emlrtCoverageInstance, 1U, 239U, 129100, 129242, 129354, 129585);
  covrtIfInit(&emlrtCoverageInstance, 1U, 240U, 129354, 129498, -1, 129498);
  covrtIfInit(&emlrtCoverageInstance, 1U, 241U, 130063, 130080, 130310, 138306);
  covrtIfInit(&emlrtCoverageInstance, 1U, 242U, 130486, 130525, 134338, 138147);
  covrtIfInit(&emlrtCoverageInstance, 1U, 243U, 130546, 130576, 131132, 131171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 244U, 130601, 130661, -1, 131111);
  covrtIfInit(&emlrtCoverageInstance, 1U, 245U, 131132, 131171, 131732, 134287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 246U, 131196, 131256, -1, 131711);
  covrtIfInit(&emlrtCoverageInstance, 1U, 247U, 131732, 131765, 131813, 134287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 248U, 131813, 131852, 132419, 134287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 249U, 131877, 131939, -1, 132398);
  covrtIfInit(&emlrtCoverageInstance, 1U, 250U, 132419, 132453, 133009, 134287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 251U, 132478, 132538, -1, 132988);
  covrtIfInit(&emlrtCoverageInstance, 1U, 252U, 133009, 133048, 133609, 134287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 253U, 133073, 133133, -1, 133588);
  covrtIfInit(&emlrtCoverageInstance, 1U, 254U, 133609, 133642, 133690, 134287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 255U, 133690, 133729, -1, 133729);
  covrtIfInit(&emlrtCoverageInstance, 1U, 256U, 133754, 133812, -1, 134263);
  covrtIfInit(&emlrtCoverageInstance, 1U, 257U, 134363, 134393, 134441, 134480);
  covrtIfInit(&emlrtCoverageInstance, 1U, 258U, 134441, 134480, 135042, 138106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 259U, 134505, 134565, -1, 135021);
  covrtIfInit(&emlrtCoverageInstance, 1U, 260U, 135042, 135075, 135630, 138106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 261U, 135100, 135160, -1, 135609);
  covrtIfInit(&emlrtCoverageInstance, 1U, 262U, 135630, 135669, 136225, 138106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 263U, 135694, 135752, -1, 136204);
  covrtIfInit(&emlrtCoverageInstance, 1U, 264U, 136225, 136259, 136307, 138106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 265U, 136307, 136346, 136908, 138106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 266U, 136371, 136431, -1, 136887);
  covrtIfInit(&emlrtCoverageInstance, 1U, 267U, 136908, 136941, 137496, 138106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 268U, 136966, 137026, -1, 137475);
  covrtIfInit(&emlrtCoverageInstance, 1U, 269U, 137496, 137535, -1, 137535);
  covrtIfInit(&emlrtCoverageInstance, 1U, 270U, 137560, 137622, -1, 138082);
  covrtIfInit(&emlrtCoverageInstance, 1U, 271U, 138654, 138688, 139222, 139265);
  covrtIfInit(&emlrtCoverageInstance, 1U, 272U, 138697, 138733, -1, 139197);
  covrtIfInit(&emlrtCoverageInstance, 1U, 273U, 138746, 138798, 138990, 139185);
  covrtIfInit(&emlrtCoverageInstance, 1U, 274U, 139222, 139265, 141248, 149064);
  covrtIfInit(&emlrtCoverageInstance, 1U, 275U, 139274, 139310, 140273, 141243);
  covrtIfInit(&emlrtCoverageInstance, 1U, 276U, 139323, 139377, 139573, 140264);
  covrtIfInit(&emlrtCoverageInstance, 1U, 277U, 139573, 139629, 139821, 140264);
  covrtIfInit(&emlrtCoverageInstance, 1U, 278U, 139821, 139877, 140069, 140264);
  covrtIfInit(&emlrtCoverageInstance, 1U, 279U, 140290, 140344, 140540, 141231);
  covrtIfInit(&emlrtCoverageInstance, 1U, 280U, 140540, 140596, 140788, 141231);
  covrtIfInit(&emlrtCoverageInstance, 1U, 281U, 140788, 140844, 141036, 141231);
  covrtIfInit(&emlrtCoverageInstance, 1U, 282U, 141248, 141285, 141819, 149064);
  covrtIfInit(&emlrtCoverageInstance, 1U, 283U, 141314, 141350, -1, 141814);
  covrtIfInit(&emlrtCoverageInstance, 1U, 284U, 141363, 141415, 141607, 141802);
  covrtIfInit(&emlrtCoverageInstance, 1U, 285U, 141819, 141862, 143851, 149064);
  covrtIfInit(&emlrtCoverageInstance, 1U, 286U, 141871, 141907, 142878, 143846);
  covrtIfInit(&emlrtCoverageInstance, 1U, 287U, 141920, 141974, 142170, 142869);
  covrtIfInit(&emlrtCoverageInstance, 1U, 288U, 142170, 142228, 142424, 142869);
  covrtIfInit(&emlrtCoverageInstance, 1U, 289U, 142424, 142480, 142672, 142869);
  covrtIfInit(&emlrtCoverageInstance, 1U, 290U, 142895, 142949, 143145, 143834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 291U, 143145, 143201, 143391, 143834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 292U, 143391, 143447, 143639, 143834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 293U, 143851, 143889, 144405, 149064);
  covrtIfInit(&emlrtCoverageInstance, 1U, 294U, 143898, 143934, -1, 144400);
  covrtIfInit(&emlrtCoverageInstance, 1U, 295U, 143947, 143999, 144191, 144388);
  covrtIfInit(&emlrtCoverageInstance, 1U, 296U, 144405, 144448, 146443, 149064);
  covrtIfInit(&emlrtCoverageInstance, 1U, 297U, 144457, 144493, 145462, 146438);
  covrtIfInit(&emlrtCoverageInstance, 1U, 298U, 144506, 144560, 144756, 145453);
  covrtIfInit(&emlrtCoverageInstance, 1U, 299U, 144756, 144814, 145008, 145453);
  covrtIfInit(&emlrtCoverageInstance, 1U, 300U, 145008, 145064, 145256, 145453);
  covrtIfInit(&emlrtCoverageInstance, 1U, 301U, 145479, 145533, 145729, 146426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 302U, 145729, 145787, 145981, 146426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 303U, 145981, 146037, 146229, 146426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 304U, 146443, 146480, 147016, 149064);
  covrtIfInit(&emlrtCoverageInstance, 1U, 305U, 146509, 146545, -1, 147011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 306U, 146558, 146610, 146802, 146999);
  covrtIfInit(&emlrtCoverageInstance, 1U, 307U, 147016, 147059, -1, 147059);
  covrtIfInit(&emlrtCoverageInstance, 1U, 308U, 147068, 147104, 148065, 149056);
  covrtIfInit(&emlrtCoverageInstance, 1U, 309U, 147117, 147171, 147367, 148056);
  covrtIfInit(&emlrtCoverageInstance, 1U, 310U, 147367, 147423, 147613, 148056);
  covrtIfInit(&emlrtCoverageInstance, 1U, 311U, 147613, 147669, 147861, 148056);
  covrtIfInit(&emlrtCoverageInstance, 1U, 312U, 148082, 148136, 148332, 149031);
  covrtIfInit(&emlrtCoverageInstance, 1U, 313U, 148332, 148390, 148586, 149031);
  covrtIfInit(&emlrtCoverageInstance, 1U, 314U, 148586, 148642, 148834, 149031);
  covrtIfInit(&emlrtCoverageInstance, 1U, 315U, 150666, 150698, 156609, 162812);
  covrtIfInit(&emlrtCoverageInstance, 1U, 316U, 150999, 151209, -1, 156548);
  covrtIfInit(&emlrtCoverageInstance, 1U, 317U, 151274, 151352, 155586, 156310);
  covrtIfInit(&emlrtCoverageInstance, 1U, 318U, 151678, 151710, 152355, 155532);
  covrtIfInit(&emlrtCoverageInstance, 1U, 319U, 152557, 152578, -1, 153166);
  covrtIfInit(&emlrtCoverageInstance, 1U, 320U, 152644, 152669, -1, 152834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 321U, 153788, 153813, -1, 153970);
  covrtIfInit(&emlrtCoverageInstance, 1U, 322U, 154039, 154063, -1, 154352);
  covrtIfInit(&emlrtCoverageInstance, 1U, 323U, 154092, 154117, -1, 154324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 324U, 154415, 154455, 154866, 155508);
  covrtIfInit(&emlrtCoverageInstance, 1U, 325U, 154484, 154509, -1, 154592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 326U, 154866, 154910, 155291, 155508);
  covrtIfInit(&emlrtCoverageInstance, 1U, 327U, 154939, 154964, -1, 155046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 328U, 155324, 155349, -1, 155480);
  covrtIfInit(&emlrtCoverageInstance, 1U, 329U, 155713, 155734, -1, 156290);
  covrtIfInit(&emlrtCoverageInstance, 1U, 330U, 155792, 155817, -1, 155974);
  covrtIfInit(&emlrtCoverageInstance, 1U, 331U, 156688, 156709, -1, 157362);
  covrtIfInit(&emlrtCoverageInstance, 1U, 332U, 156751, 156776, -1, 156917);
  covrtIfInit(&emlrtCoverageInstance, 1U, 333U, 157992, 158016, 158287, 158573);
  covrtIfInit(&emlrtCoverageInstance, 1U, 334U, 158069, 158094, -1, 158243);
  covrtIfInit(&emlrtCoverageInstance, 1U, 335U, 158630, 158664, -1, 158814);
  covrtIfInit(&emlrtCoverageInstance, 1U, 336U, 158685, 158710, -1, 158794);
  covrtIfInit(&emlrtCoverageInstance, 1U, 337U, 158880, 158920, 159247, 159291);
  covrtIfInit(&emlrtCoverageInstance, 1U, 338U, 158937, 158962, -1, 159021);
  covrtIfInit(&emlrtCoverageInstance, 1U, 339U, 159247, 159291, 159617, 162273);
  covrtIfInit(&emlrtCoverageInstance, 1U, 340U, 159308, 159333, -1, 159391);
  covrtIfInit(&emlrtCoverageInstance, 1U, 341U, 159617, 159661, 160206, 162273);
  covrtIfInit(&emlrtCoverageInstance, 1U, 342U, 159678, 159703, -1, 159980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 343U, 159724, 159774, 159838, 159892);
  covrtIfInit(&emlrtCoverageInstance, 1U, 344U, 159838, 159892, -1, 159892);
  covrtIfInit(&emlrtCoverageInstance, 1U, 345U, 160206, 160250, 160793, 162273);
  covrtIfInit(&emlrtCoverageInstance, 1U, 346U, 160267, 160292, -1, 160567);
  covrtIfInit(&emlrtCoverageInstance, 1U, 347U, 160313, 160363, 160426, 160480);
  covrtIfInit(&emlrtCoverageInstance, 1U, 348U, 160426, 160480, -1, 160480);
  covrtIfInit(&emlrtCoverageInstance, 1U, 349U, 160793, 160838, 161167, 162273);
  covrtIfInit(&emlrtCoverageInstance, 1U, 350U, 160855, 160880, -1, 160940);
  covrtIfInit(&emlrtCoverageInstance, 1U, 351U, 161167, 161212, 161540, 162273);
  covrtIfInit(&emlrtCoverageInstance, 1U, 352U, 161229, 161254, -1, 161313);
  covrtIfInit(&emlrtCoverageInstance, 1U, 353U, 161540, 161585, 161914, 162273);
  covrtIfInit(&emlrtCoverageInstance, 1U, 354U, 161602, 161627, -1, 161687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 355U, 161914, 161959, -1, 161959);
  covrtIfInit(&emlrtCoverageInstance, 1U, 356U, 161976, 162001, -1, 162060);
  covrtIfInit(&emlrtCoverageInstance, 1U, 357U, 162443, 162527, -1, 162574);
  covrtIfInit(&emlrtCoverageInstance, 1U, 358U, 162855, 162872, -1, 162903);
  covrtIfInit(&emlrtCoverageInstance, 1U, 359U, 163479, 163525, 164894, 165979);
  covrtIfInit(&emlrtCoverageInstance, 1U, 360U, 163578, 163604, 164227, 164257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 361U, 163625, 163651, 163734, 163764);
  covrtIfInit(&emlrtCoverageInstance, 1U, 362U, 163734, 163764, 163847, 164169);
  covrtIfInit(&emlrtCoverageInstance, 1U, 363U, 163847, 163877, -1, 163877);
  covrtIfInit(&emlrtCoverageInstance, 1U, 364U, 163902, 163928, 164020, 164050);
  covrtIfInit(&emlrtCoverageInstance, 1U, 365U, 164020, 164050, -1, 164050);
  covrtIfInit(&emlrtCoverageInstance, 1U, 366U, 164227, 164257, -1, 164257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 367U, 164278, 164304, 164387, 164417);
  covrtIfInit(&emlrtCoverageInstance, 1U, 368U, 164387, 164417, 164500, 164822);
  covrtIfInit(&emlrtCoverageInstance, 1U, 369U, 164500, 164530, -1, 164530);
  covrtIfInit(&emlrtCoverageInstance, 1U, 370U, 164555, 164581, 164673, 164703);
  covrtIfInit(&emlrtCoverageInstance, 1U, 371U, 164673, 164703, -1, 164703);
  covrtIfInit(&emlrtCoverageInstance, 1U, 372U, 164894, 164944, 165840, 165979);
  covrtIfInit(&emlrtCoverageInstance, 1U, 373U, 164985, 165011, 165086, 165116);
  covrtIfInit(&emlrtCoverageInstance, 1U, 374U, 165086, 165116, 165408, 165810);
  covrtIfInit(&emlrtCoverageInstance, 1U, 375U, 165137, 165163, 165246, 165276);
  covrtIfInit(&emlrtCoverageInstance, 1U, 376U, 165246, 165276, -1, 165276);
  covrtIfInit(&emlrtCoverageInstance, 1U, 377U, 165408, 165438, 165513, 165810);
  covrtIfInit(&emlrtCoverageInstance, 1U, 378U, 165513, 165543, -1, 165543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 379U, 165564, 165590, 165673, 165703);
  covrtIfInit(&emlrtCoverageInstance, 1U, 380U, 165673, 165703, -1, 165703);
  covrtIfInit(&emlrtCoverageInstance, 1U, 381U, 165861, 165886, -1, 165963);
  covrtIfInit(&emlrtCoverageInstance, 1U, 382U, 166394, 166471, 167489, 175127);
  covrtIfInit(&emlrtCoverageInstance, 1U, 383U, 166522, 166559, 166996, 167484);
  covrtIfInit(&emlrtCoverageInstance, 1U, 384U, 166572, 166643, 166801, 166987);
  covrtIfInit(&emlrtCoverageInstance, 1U, 385U, 167040, 167111, 167287, 167472);
  covrtIfInit(&emlrtCoverageInstance, 1U, 386U, 167701, 167740, 171259, 175085);
  covrtIfInit(&emlrtCoverageInstance, 1U, 387U, 167757, 167787, 168298, 168337);
  covrtIfInit(&emlrtCoverageInstance, 1U, 388U, 167808, 167868, -1, 168281);
  covrtIfInit(&emlrtCoverageInstance, 1U, 389U, 168298, 168337, 168854, 171216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 390U, 168358, 168418, -1, 168837);
  covrtIfInit(&emlrtCoverageInstance, 1U, 391U, 168854, 168887, 168927, 171216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 392U, 168927, 168966, 169489, 171216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 393U, 168987, 169049, -1, 169472);
  covrtIfInit(&emlrtCoverageInstance, 1U, 394U, 169489, 169523, 170034, 171216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 395U, 169544, 169604, -1, 170017);
  covrtIfInit(&emlrtCoverageInstance, 1U, 396U, 170034, 170073, 170590, 171216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 397U, 170094, 170154, -1, 170573);
  covrtIfInit(&emlrtCoverageInstance, 1U, 398U, 170590, 170623, 170663, 171216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 399U, 170663, 170702, -1, 170702);
  covrtIfInit(&emlrtCoverageInstance, 1U, 400U, 170723, 170781, -1, 171196);
  covrtIfInit(&emlrtCoverageInstance, 1U, 401U, 171280, 171310, 171350, 171389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 402U, 171350, 171389, 171906, 175052);
  covrtIfInit(&emlrtCoverageInstance, 1U, 403U, 171410, 171470, -1, 171889);
  covrtIfInit(&emlrtCoverageInstance, 1U, 404U, 171906, 171939, 172449, 175052);
  covrtIfInit(&emlrtCoverageInstance, 1U, 405U, 171960, 172020, -1, 172432);
  covrtIfInit(&emlrtCoverageInstance, 1U, 406U, 172449, 172488, 172999, 175052);
  covrtIfInit(&emlrtCoverageInstance, 1U, 407U, 172509, 172567, -1, 172982);
  covrtIfInit(&emlrtCoverageInstance, 1U, 408U, 172999, 173033, 173073, 175052);
  covrtIfInit(&emlrtCoverageInstance, 1U, 409U, 173073, 173112, 173734, 175052);
  covrtIfInit(&emlrtCoverageInstance, 1U, 410U, 173133, 173157, -1, 173717);
  covrtIfInit(&emlrtCoverageInstance, 1U, 411U, 173182, 173242, -1, 173693);
  covrtIfInit(&emlrtCoverageInstance, 1U, 412U, 173734, 173767, 174382, 175052);
  covrtIfInit(&emlrtCoverageInstance, 1U, 413U, 173788, 173812, -1, 174365);
  covrtIfInit(&emlrtCoverageInstance, 1U, 414U, 173837, 173897, -1, 174341);
  covrtIfInit(&emlrtCoverageInstance, 1U, 415U, 174382, 174421, -1, 174421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 416U, 174442, 174466, -1, 175032);
  covrtIfInit(&emlrtCoverageInstance, 1U, 417U, 174491, 174553, -1, 175008);
  covrtIfInit(&emlrtCoverageInstance, 1U, 418U, 175393, 175443, 177282, 181884);
  covrtIfInit(&emlrtCoverageInstance, 1U, 419U, 175452, 175494, 175870, 177260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 420U, 175748, 175773, -1, 175861);
  covrtIfInit(&emlrtCoverageInstance, 1U, 421U, 175870, 175915, 176289, 177260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 422U, 176168, 176193, -1, 176280);
  covrtIfInit(&emlrtCoverageInstance, 1U, 423U, 176289, 176335, 176711, 177260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 424U, 176589, 176614, -1, 176702);
  covrtIfInit(&emlrtCoverageInstance, 1U, 425U, 176711, 176756, 177135, 177260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 426U, 177009, 177034, -1, 177126);
  covrtIfInit(&emlrtCoverageInstance, 1U, 427U, 177152, 177177, -1, 177248);
  covrtIfInit(&emlrtCoverageInstance, 1U, 428U, 177282, 177336, 181780, 181884);
  covrtIfInit(&emlrtCoverageInstance, 1U, 429U, 177561, 177608, 178611, 178662);
  covrtIfInit(&emlrtCoverageInstance, 1U, 430U, 177621, 177663, 177984, 178471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 431U, 177984, 178030, 178334, 178471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 432U, 178355, 178380, -1, 178455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 433U, 178484, 178509, -1, 178602);
  covrtIfInit(&emlrtCoverageInstance, 1U, 434U, 178611, 178662, 179665, 181775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 435U, 178675, 178717, 179032, 179525);
  covrtIfInit(&emlrtCoverageInstance, 1U, 436U, 179032, 179078, 179388, 179525);
  covrtIfInit(&emlrtCoverageInstance, 1U, 437U, 179409, 179434, -1, 179509);
  covrtIfInit(&emlrtCoverageInstance, 1U, 438U, 179538, 179563, -1, 179656);
  covrtIfInit(&emlrtCoverageInstance, 1U, 439U, 179665, 179716, 180719, 181775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 440U, 179729, 179771, 180092, 180579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 441U, 180092, 180138, 180442, 180579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 442U, 180463, 180488, -1, 180563);
  covrtIfInit(&emlrtCoverageInstance, 1U, 443U, 180592, 180617, -1, 180710);
  covrtIfInit(&emlrtCoverageInstance, 1U, 444U, 180719, 180770, -1, 180770);
  covrtIfInit(&emlrtCoverageInstance, 1U, 445U, 180783, 180825, 181152, 181633);
  covrtIfInit(&emlrtCoverageInstance, 1U, 446U, 181152, 181198, 181496, 181633);
  covrtIfInit(&emlrtCoverageInstance, 1U, 447U, 181517, 181542, -1, 181617);
  covrtIfInit(&emlrtCoverageInstance, 1U, 448U, 181646, 181671, -1, 181763);
  covrtIfInit(&emlrtCoverageInstance, 1U, 449U, 181793, 181818, -1, 181876);
  covrtIfInit(&emlrtCoverageInstance, 1U, 450U, 182155, 182205, 183550, 185049);
  covrtIfInit(&emlrtCoverageInstance, 1U, 451U, 182214, 182256, 182513, 183545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 452U, 182513, 182558, 182813, 183545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 453U, 182813, 182859, 183114, 183545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 454U, 183114, 183159, 183403, 183545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 455U, 183420, 183445, -1, 183533);
  covrtIfInit(&emlrtCoverageInstance, 1U, 456U, 183550, 183604, 184945, 185049);
  covrtIfInit(&emlrtCoverageInstance, 1U, 457U, 183613, 183660, 183909, 184940);
  covrtIfInit(&emlrtCoverageInstance, 1U, 458U, 183909, 183960, 184208, 184940);
  covrtIfInit(&emlrtCoverageInstance, 1U, 459U, 184208, 184259, 184508, 184940);
  covrtIfInit(&emlrtCoverageInstance, 1U, 460U, 184508, 184559, 184798, 184940);
  covrtIfInit(&emlrtCoverageInstance, 1U, 461U, 184815, 184840, -1, 184928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 462U, 184958, 184983, -1, 185041);
  covrtIfInit(&emlrtCoverageInstance, 1U, 463U, 185277, 185327, 186672, 188171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 464U, 185336, 185378, 185633, 186667);
  covrtIfInit(&emlrtCoverageInstance, 1U, 465U, 185633, 185678, 185935, 186667);
  covrtIfInit(&emlrtCoverageInstance, 1U, 466U, 185935, 185981, 186238, 186667);
  covrtIfInit(&emlrtCoverageInstance, 1U, 467U, 186238, 186283, 186525, 186667);
  covrtIfInit(&emlrtCoverageInstance, 1U, 468U, 186542, 186567, -1, 186655);
  covrtIfInit(&emlrtCoverageInstance, 1U, 469U, 186672, 186726, 188067, 188171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 470U, 186735, 186782, 187032, 188062);
  covrtIfInit(&emlrtCoverageInstance, 1U, 471U, 187032, 187083, 187334, 188062);
  covrtIfInit(&emlrtCoverageInstance, 1U, 472U, 187334, 187385, 187635, 188062);
  covrtIfInit(&emlrtCoverageInstance, 1U, 473U, 187635, 187686, 187920, 188062);
  covrtIfInit(&emlrtCoverageInstance, 1U, 474U, 187937, 187962, -1, 188050);
  covrtIfInit(&emlrtCoverageInstance, 1U, 475U, 188080, 188105, -1, 188163);
  covrtIfInit(&emlrtCoverageInstance, 1U, 476U, 188399, 188449, 189786, 191299);
  covrtIfInit(&emlrtCoverageInstance, 1U, 477U, 188458, 188500, 188751, 189758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 478U, 188751, 188796, 189046, 189758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 479U, 189046, 189092, 189341, 189758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 480U, 189341, 189386, 189625, 189758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 481U, 189642, 189667, -1, 189746);
  covrtIfInit(&emlrtCoverageInstance, 1U, 482U, 189786, 189840, 191195, 191299);
  covrtIfInit(&emlrtCoverageInstance, 1U, 483U, 189849, 189896, 190151, 191190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 484U, 190151, 190202, 190457, 191190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 485U, 190457, 190508, 190763, 191190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 486U, 190763, 190814, 191056, 191190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 487U, 191073, 191098, -1, 191178);
  covrtIfInit(&emlrtCoverageInstance, 1U, 488U, 191208, 191233, -1, 191291);
  covrtIfInit(&emlrtCoverageInstance, 1U, 489U, 191527, 191577, 192914, 194426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 490U, 191586, 191628, 191877, 192886);
  covrtIfInit(&emlrtCoverageInstance, 1U, 491U, 191877, 191922, 192174, 192886);
  covrtIfInit(&emlrtCoverageInstance, 1U, 492U, 192174, 192220, 192471, 192886);
  covrtIfInit(&emlrtCoverageInstance, 1U, 493U, 192471, 192516, 192753, 192886);
  covrtIfInit(&emlrtCoverageInstance, 1U, 494U, 192770, 192795, -1, 192874);
  covrtIfInit(&emlrtCoverageInstance, 1U, 495U, 192914, 192968, 194322, 194426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 496U, 192977, 193024, 193279, 194317);
  covrtIfInit(&emlrtCoverageInstance, 1U, 497U, 193279, 193330, 193585, 194317);
  covrtIfInit(&emlrtCoverageInstance, 1U, 498U, 193585, 193636, 193891, 194317);
  covrtIfInit(&emlrtCoverageInstance, 1U, 499U, 193891, 193942, 194184, 194317);
  covrtIfInit(&emlrtCoverageInstance, 1U, 500U, 194201, 194226, -1, 194305);
  covrtIfInit(&emlrtCoverageInstance, 1U, 501U, 194335, 194360, -1, 194418);
  covrtIfInit(&emlrtCoverageInstance, 1U, 502U, 194656, 194706, 196064, 197564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 503U, 194715, 194757, 195014, 196041);
  covrtIfInit(&emlrtCoverageInstance, 1U, 504U, 195014, 195059, 195316, 196041);
  covrtIfInit(&emlrtCoverageInstance, 1U, 505U, 195316, 195362, 195619, 196041);
  covrtIfInit(&emlrtCoverageInstance, 1U, 506U, 195619, 195664, 195908, 196041);
  covrtIfInit(&emlrtCoverageInstance, 1U, 507U, 195925, 195950, -1, 196029);
  covrtIfInit(&emlrtCoverageInstance, 1U, 508U, 196064, 196118, 197460, 197564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 509U, 196127, 196174, 196424, 197455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 510U, 196424, 196475, 196724, 197455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 511U, 196724, 196775, 197025, 197455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 512U, 197025, 197076, 197312, 197455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 513U, 197329, 197354, -1, 197443);
  covrtIfInit(&emlrtCoverageInstance, 1U, 514U, 197473, 197498, -1, 197556);
  covrtIfInit(&emlrtCoverageInstance, 1U, 515U, 197794, 197844, 199202, 200701);
  covrtIfInit(&emlrtCoverageInstance, 1U, 516U, 197853, 197895, 198152, 199179);
  covrtIfInit(&emlrtCoverageInstance, 1U, 517U, 198152, 198197, 198454, 199179);
  covrtIfInit(&emlrtCoverageInstance, 1U, 518U, 198454, 198500, 198757, 199179);
  covrtIfInit(&emlrtCoverageInstance, 1U, 519U, 198757, 198802, 199046, 199179);
  covrtIfInit(&emlrtCoverageInstance, 1U, 520U, 199063, 199088, -1, 199167);
  covrtIfInit(&emlrtCoverageInstance, 1U, 521U, 199202, 199256, 200597, 200701);
  covrtIfInit(&emlrtCoverageInstance, 1U, 522U, 199265, 199312, 199561, 200592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 523U, 199561, 199612, 199862, 200592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 524U, 199862, 199913, 200162, 200592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 525U, 200162, 200213, 200450, 200592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 526U, 200467, 200492, -1, 200580);
  covrtIfInit(&emlrtCoverageInstance, 1U, 527U, 200610, 200635, -1, 200693);
  covrtIfInit(&emlrtCoverageInstance, 1U, 528U, 200931, 200981, 202318, 202596);
  covrtIfInit(&emlrtCoverageInstance, 1U, 529U, 200990, 201032, 201284, 202295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 530U, 201284, 201329, 201580, 202295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 531U, 201580, 201626, 201878, 202295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 532U, 201878, 201923, 202161, 202295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 533U, 202178, 202203, -1, 202283);
  covrtIfInit(&emlrtCoverageInstance, 1U, 534U, 202318, 202372, 202492, 202596);
  covrtIfInit(&emlrtCoverageInstance, 1U, 535U, 202381, 202406, -1, 202487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 536U, 202505, 202530, -1, 202588);
  covrtIfInit(&emlrtCoverageInstance, 1U, 537U, 202826, 202876, 204213, 204491);
  covrtIfInit(&emlrtCoverageInstance, 1U, 538U, 202885, 202927, 203179, 204190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 539U, 203179, 203224, 203475, 204190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 540U, 203475, 203521, 203773, 204190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 541U, 203773, 203818, 204056, 204190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 542U, 204073, 204098, -1, 204178);
  covrtIfInit(&emlrtCoverageInstance, 1U, 543U, 204213, 204267, 204387, 204491);
  covrtIfInit(&emlrtCoverageInstance, 1U, 544U, 204276, 204301, -1, 204382);
  covrtIfInit(&emlrtCoverageInstance, 1U, 545U, 204400, 204425, -1, 204483);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 3783, 3806, 1, 0,
                cond_starts_1_0, cond_ends_1_0, 2, postfix_exprs_1_0);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 5693, 5716, 1, 1,
                cond_starts_1_1, cond_ends_1_1, 2, postfix_exprs_1_1);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 7311, 7334, 1, 2,
                cond_starts_1_2, cond_ends_1_2, 2, postfix_exprs_1_2);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 3U, 10244, 10267, 1, 3,
                cond_starts_1_3, cond_ends_1_3, 2, postfix_exprs_1_3);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 4U, 13436, 13512, 2, 4,
                cond_starts_1_4, cond_ends_1_4, 3, postfix_exprs_1_4);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 5U, 14137, 14160, 1, 6,
                cond_starts_1_5, cond_ends_1_5, 2, postfix_exprs_1_5);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 6U, 14761, 14784, 1, 7,
                cond_starts_1_6, cond_ends_1_6, 2, postfix_exprs_1_6);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 7U, 15286, 15309, 1, 8,
                cond_starts_1_7, cond_ends_1_7, 2, postfix_exprs_1_7);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 8U, 15806, 15829, 1, 9,
                cond_starts_1_8, cond_ends_1_8, 2, postfix_exprs_1_8);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 9U, 16331, 16354, 1, 10,
                cond_starts_1_9, cond_ends_1_9, 2, postfix_exprs_1_9);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 10U, 24560, 24815, 2, 11,
                cond_starts_1_10, cond_ends_1_10, 3, postfix_exprs_1_10);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 11U, 24879, 25106, 2, 13,
                cond_starts_1_11, cond_ends_1_11, 3, postfix_exprs_1_11);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 12U, 25800, 26030, 2, 15,
                cond_starts_1_12, cond_ends_1_12, 3, postfix_exprs_1_12);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 13U, 26748, 27003, 2, 17,
                cond_starts_1_13, cond_ends_1_13, 3, postfix_exprs_1_13);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 14U, 27054, 27281, 2, 19,
                cond_starts_1_14, cond_ends_1_14, 3, postfix_exprs_1_14);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 15U, 27988, 28218, 2, 21,
                cond_starts_1_15, cond_ends_1_15, 3, postfix_exprs_1_15);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 16U, 28910, 29165, 2, 23,
                cond_starts_1_16, cond_ends_1_16, 3, postfix_exprs_1_16);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 17U, 29216, 29443, 2, 25,
                cond_starts_1_17, cond_ends_1_17, 3, postfix_exprs_1_17);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 18U, 30137, 30367, 2, 27,
                cond_starts_1_18, cond_ends_1_18, 3, postfix_exprs_1_18);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 19U, 31067, 31322, 2, 29,
                cond_starts_1_19, cond_ends_1_19, 3, postfix_exprs_1_19);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 20U, 31373, 31600, 2, 31,
                cond_starts_1_20, cond_ends_1_20, 3, postfix_exprs_1_20);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 21U, 32302, 32532, 2, 33,
                cond_starts_1_21, cond_ends_1_21, 3, postfix_exprs_1_21);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 22U, 39216, 39259, 2, 35,
                cond_starts_1_22, cond_ends_1_22, 3, postfix_exprs_1_22);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 23U, 45502, 45545, 2, 37,
                cond_starts_1_23, cond_ends_1_23, 3, postfix_exprs_1_23);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 24U, 45991, 46061, 2, 39,
                cond_starts_1_24, cond_ends_1_24, 3, postfix_exprs_1_24);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 25U, 51130, 51204, 2, 41,
                cond_starts_1_25, cond_ends_1_25, 3, postfix_exprs_1_25);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 26U, 54260, 54324, 2, 43,
                cond_starts_1_26, cond_ends_1_26, 3, postfix_exprs_1_26);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 27U, 54469, 54492, 1, 45,
                cond_starts_1_27, cond_ends_1_27, 2, postfix_exprs_1_27);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 28U, 56796, 56819, 1, 46,
                cond_starts_1_28, cond_ends_1_28, 2, postfix_exprs_1_28);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 29U, 57374, 57397, 1, 47,
                cond_starts_1_29, cond_ends_1_29, 2, postfix_exprs_1_29);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 30U, 57947, 57970, 1, 48,
                cond_starts_1_30, cond_ends_1_30, 2, postfix_exprs_1_30);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 31U, 58542, 58565, 1, 49,
                cond_starts_1_31, cond_ends_1_31, 2, postfix_exprs_1_31);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 32U, 61112, 61446, 3, 50,
                cond_starts_1_32, cond_ends_1_32, 6, postfix_exprs_1_32);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 33U, 63931, 64261, 3, 53,
                cond_starts_1_33, cond_ends_1_33, 6, postfix_exprs_1_33);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 34U, 67259, 67591, 3, 56,
                cond_starts_1_34, cond_ends_1_34, 6, postfix_exprs_1_34);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 35U, 70292, 70622, 3, 59,
                cond_starts_1_35, cond_ends_1_35, 6, postfix_exprs_1_35);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 36U, 73340, 73393, 2, 62,
                cond_starts_1_36, cond_ends_1_36, 3, postfix_exprs_1_36);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 37U, 75072, 75164, 1, 64,
                cond_starts_1_37, cond_ends_1_37, 2, postfix_exprs_1_37);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 38U, 75743, 75834, 1, 65,
                cond_starts_1_38, cond_ends_1_38, 2, postfix_exprs_1_38);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 39U, 76412, 76504, 1, 66,
                cond_starts_1_39, cond_ends_1_39, 2, postfix_exprs_1_39);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 40U, 77075, 77166, 1, 67,
                cond_starts_1_40, cond_ends_1_40, 2, postfix_exprs_1_40);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 41U, 77913, 77999, 1, 68,
                cond_starts_1_41, cond_ends_1_41, 2, postfix_exprs_1_41);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 42U, 78475, 78560, 1, 69,
                cond_starts_1_42, cond_ends_1_42, 2, postfix_exprs_1_42);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 43U, 79036, 79122, 1, 70,
                cond_starts_1_43, cond_ends_1_43, 2, postfix_exprs_1_43);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 44U, 79592, 79677, 1, 71,
                cond_starts_1_44, cond_ends_1_44, 2, postfix_exprs_1_44);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 45U, 80565, 80866, 2, 72,
                cond_starts_1_45, cond_ends_1_45, 3, postfix_exprs_1_45);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 46U, 84285, 84584, 2, 74,
                cond_starts_1_46, cond_ends_1_46, 3, postfix_exprs_1_46);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 47U, 88065, 88368, 2, 76,
                cond_starts_1_47, cond_ends_1_47, 3, postfix_exprs_1_47);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 48U, 91845, 92150, 2, 78,
                cond_starts_1_48, cond_ends_1_48, 3, postfix_exprs_1_48);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 49U, 95619, 95922, 2, 80,
                cond_starts_1_49, cond_ends_1_49, 3, postfix_exprs_1_49);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 50U, 99372, 99671, 2, 82,
                cond_starts_1_50, cond_ends_1_50, 3, postfix_exprs_1_50);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 51U, 103260, 103561, 2, 84,
                cond_starts_1_51, cond_ends_1_51, 3, postfix_exprs_1_51);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 52U, 106985, 107284, 2, 86,
                cond_starts_1_52, cond_ends_1_52, 3, postfix_exprs_1_52);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 53U, 110694, 110995, 2, 88,
                cond_starts_1_53, cond_ends_1_53, 3, postfix_exprs_1_53);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 54U, 114419, 114724, 2, 90,
                cond_starts_1_54, cond_ends_1_54, 3, postfix_exprs_1_54);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 55U, 118123, 118426, 2, 92,
                cond_starts_1_55, cond_ends_1_55, 3, postfix_exprs_1_55);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 56U, 121790, 122095, 2, 94,
                cond_starts_1_56, cond_ends_1_56, 3, postfix_exprs_1_56);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 57U, 126898, 127047, 3, 96,
                cond_starts_1_57, cond_ends_1_57, 5, postfix_exprs_1_57);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 58U, 127168, 127303, 2, 99,
                cond_starts_1_58, cond_ends_1_58, 3, postfix_exprs_1_58);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 59U, 127423, 127560, 2, 101,
                cond_starts_1_59, cond_ends_1_59, 3, postfix_exprs_1_59);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 60U, 127680, 127815, 2, 103,
                cond_starts_1_60, cond_ends_1_60, 3, postfix_exprs_1_60);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 61U, 127935, 128068, 2, 105,
                cond_starts_1_61, cond_ends_1_61, 3, postfix_exprs_1_61);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 62U, 128331, 128480, 3, 107,
                cond_starts_1_62, cond_ends_1_62, 5, postfix_exprs_1_62);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 63U, 128601, 128736, 2, 110,
                cond_starts_1_63, cond_ends_1_63, 3, postfix_exprs_1_63);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 64U, 128855, 128988, 2, 112,
                cond_starts_1_64, cond_ends_1_64, 3, postfix_exprs_1_64);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 65U, 129107, 129242, 2, 114,
                cond_starts_1_65, cond_ends_1_65, 3, postfix_exprs_1_65);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 66U, 129361, 129498, 2, 116,
                cond_starts_1_66, cond_ends_1_66, 3, postfix_exprs_1_66);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 67U, 151002, 151209, 5, 118,
                cond_starts_1_67, cond_ends_1_67, 9, postfix_exprs_1_67);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 68U, 151278, 151351, 2, 123,
                cond_starts_1_68, cond_ends_1_68, 3, postfix_exprs_1_68);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 69U, 158633, 158664, 2, 125,
                cond_starts_1_69, cond_ends_1_69, 3, postfix_exprs_1_69);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 70U, 162446, 162527, 2, 127,
                cond_starts_1_70, cond_ends_1_70, 3, postfix_exprs_1_70);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 71U, 166397, 166471, 2, 129,
                cond_starts_1_71, cond_ends_1_71, 3, postfix_exprs_1_71);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 72U, 166575, 166643, 2, 131,
                cond_starts_1_72, cond_ends_1_72, 3, postfix_exprs_1_72);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 73U, 167043, 167111, 2, 133,
                cond_starts_1_73, cond_ends_1_73, 3, postfix_exprs_1_73);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 4524, 4544, 4793);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 13397, 13421, 13577);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 13723, 13747, 13982);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 34120, 34149, 39323);
  covrtForInit(&emlrtCoverageInstance, 1U, 4U, 34271, 34311, 38899);
  covrtForInit(&emlrtCoverageInstance, 1U, 5U, 40270, 40299, 45609);
  covrtForInit(&emlrtCoverageInstance, 1U, 6U, 40421, 40461, 45185);
  covrtForInit(&emlrtCoverageInstance, 1U, 7U, 45879, 45913, 46178);
  covrtForInit(&emlrtCoverageInstance, 1U, 8U, 46906, 46933, 47163);
  covrtForInit(&emlrtCoverageInstance, 1U, 9U, 47188, 47217, 51267);
  covrtForInit(&emlrtCoverageInstance, 1U, 10U, 47328, 47368, 50821);
  covrtForInit(&emlrtCoverageInstance, 1U, 11U, 53911, 53938, 59289);
  covrtForInit(&emlrtCoverageInstance, 1U, 12U, 54219, 54245, 54390);
  covrtForInit(&emlrtCoverageInstance, 1U, 13U, 60299, 60325, 60818);
  covrtForInit(&emlrtCoverageInstance, 1U, 14U, 60828, 60857, 73432);
  covrtForInit(&emlrtCoverageInstance, 1U, 15U, 60972, 61012, 73028);
  covrtForInit(&emlrtCoverageInstance, 1U, 16U, 77849, 77869, 80127);
  covrtForInit(&emlrtCoverageInstance, 1U, 17U, 80292, 80317, 126181);
  covrtForInit(&emlrtCoverageInstance, 1U, 18U, 80464, 80504, 103029);
  covrtForInit(&emlrtCoverageInstance, 1U, 19U, 103114, 103154, 125484);
  covrtForInit(&emlrtCoverageInstance, 1U, 20U, 126779, 126801, 129700);
  covrtForInit(&emlrtCoverageInstance, 1U, 21U, 130376, 130388, 138180);
  covrtForInit(&emlrtCoverageInstance, 1U, 22U, 157495, 157509, 158830);
  covrtForInit(&emlrtCoverageInstance, 1U, 23U, 167603, 167615, 175110);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 1U, 0U, 4476, 4484, 5274);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 1U, 5462, 5470, 6561);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 2U, 6742, 6750, 8318);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 3U, 12467, 12475, 17102);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 4U, 126724, 126732, 138314);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 5U, 150471, 150479, 163232);

  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 5399, 5417, 8503, 3U,
                  caseStarts_1_0, caseExprEnds_1_0);
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 1U, 14549, 14592, 16658, 5U,
                  caseStarts_1_1, caseExprEnds_1_1);
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 2U, 56534, 56574, 58888, 5U,
                  caseStarts_1_2, caseExprEnds_1_2);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m", 2U, 1U, 2U,
                  2U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "goal_plot", 0, -1, 478);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 280, -1, 422);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 166, -1, 191);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 63, 88, -1, 474);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 197, 213, -1, 470);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 222, 242, 462);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  emlrtSetGlobalSyncFcn(sp, (void (*)(const void *))emlrt_synchGlobalsToML);
}

void maze_init_mex_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    maze_init_mex_once(&st);
  }
}

/* End of code generation (maze_init_mex_initialize.c) */
