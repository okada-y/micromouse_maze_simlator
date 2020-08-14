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
  const int32_T cond_starts_1_0[1] = { 5157 };

  const int32_T cond_ends_1_0[1] = { 5179 };

  const int32_T postfix_exprs_1_0[2] = { 0, -1 };

  const int32_T cond_starts_1_1[2] = { 9635, 9653 };

  const int32_T cond_ends_1_1[2] = { 9649, 9672 };

  const int32_T postfix_exprs_1_1[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_2[2] = { 10518, 10558 };

  const int32_T cond_ends_1_2[2] = { 10552, 10592 };

  const int32_T postfix_exprs_1_2[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_3[1] = { 10827 };

  const int32_T cond_ends_1_3[1] = { 10849 };

  const int32_T postfix_exprs_1_3[2] = { 0, -1 };

  const int32_T cond_starts_1_4[1] = { 11532 };

  const int32_T cond_ends_1_4[1] = { 11554 };

  const int32_T postfix_exprs_1_4[2] = { 0, -1 };

  const int32_T cond_starts_1_5[1] = { 12015 };

  const int32_T cond_ends_1_5[1] = { 12037 };

  const int32_T postfix_exprs_1_5[2] = { 0, -1 };

  const int32_T cond_starts_1_6[1] = { 12541 };

  const int32_T cond_ends_1_6[1] = { 12563 };

  const int32_T postfix_exprs_1_6[2] = { 0, -1 };

  const int32_T cond_starts_1_7[1] = { 13068 };

  const int32_T cond_ends_1_7[1] = { 13090 };

  const int32_T postfix_exprs_1_7[2] = { 0, -1 };

  const int32_T cond_starts_1_8[2] = { 21696, 21836 };

  const int32_T cond_ends_1_8[2] = { 21811, 21949 };

  const int32_T postfix_exprs_1_8[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_9[2] = { 22002, 22113 };

  const int32_T cond_ends_1_9[2] = { 22085, 22228 };

  const int32_T postfix_exprs_1_9[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_10[2] = { 22939, 23051 };

  const int32_T cond_ends_1_10[2] = { 23023, 23168 };

  const int32_T postfix_exprs_1_10[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_11[2] = { 23871, 24011 };

  const int32_T cond_ends_1_11[2] = { 23986, 24124 };

  const int32_T postfix_exprs_1_11[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_12[2] = { 24176, 24283 };

  const int32_T cond_ends_1_12[2] = { 24259, 24398 };

  const int32_T postfix_exprs_1_12[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_13[2] = { 25094, 25202 };

  const int32_T cond_ends_1_13[2] = { 25178, 25319 };

  const int32_T postfix_exprs_1_13[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_14[2] = { 26009, 26143 };

  const int32_T cond_ends_1_14[2] = { 26122, 26258 };

  const int32_T postfix_exprs_1_14[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_15[2] = { 26310, 26417 };

  const int32_T cond_ends_1_15[2] = { 26393, 26532 };

  const int32_T postfix_exprs_1_15[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_16[2] = { 27228, 27336 };

  const int32_T cond_ends_1_16[2] = { 27312, 27453 };

  const int32_T postfix_exprs_1_16[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_17[2] = { 28150, 28284 };

  const int32_T cond_ends_1_17[2] = { 28263, 28399 };

  const int32_T postfix_exprs_1_17[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_18[2] = { 28451, 28558 };

  const int32_T cond_ends_1_18[2] = { 28534, 28673 };

  const int32_T postfix_exprs_1_18[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_19[2] = { 29377, 29485 };

  const int32_T cond_ends_1_19[2] = { 29461, 29602 };

  const int32_T postfix_exprs_1_19[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_20[2] = { 36454, 36491 };

  const int32_T cond_ends_1_20[2] = { 36485, 36522 };

  const int32_T postfix_exprs_1_20[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_21[2] = { 41892, 42028 };

  const int32_T cond_ends_1_21[2] = { 41993, 42137 };

  const int32_T postfix_exprs_1_21[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_22[2] = { 44215, 44350 };

  const int32_T cond_ends_1_22[2] = { 44315, 44458 };

  const int32_T postfix_exprs_1_22[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_23[2] = { 46512, 46648 };

  const int32_T cond_ends_1_23[2] = { 46613, 46757 };

  const int32_T postfix_exprs_1_23[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_24[2] = { 48834, 48969 };

  const int32_T cond_ends_1_24[2] = { 48934, 49077 };

  const int32_T postfix_exprs_1_24[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_25[1] = { 52221 };

  const int32_T cond_ends_1_25[1] = { 52312 };

  const int32_T postfix_exprs_1_25[2] = { 0, -1 };

  const int32_T cond_starts_1_26[1] = { 52763 };

  const int32_T cond_ends_1_26[1] = { 52853 };

  const int32_T postfix_exprs_1_26[2] = { 0, -1 };

  const int32_T cond_starts_1_27[1] = { 53303 };

  const int32_T cond_ends_1_27[1] = { 53394 };

  const int32_T postfix_exprs_1_27[2] = { 0, -1 };

  const int32_T cond_starts_1_28[1] = { 53837 };

  const int32_T cond_ends_1_28[1] = { 53927 };

  const int32_T postfix_exprs_1_28[2] = { 0, -1 };

  const int32_T cond_starts_1_29[1] = { 54538 };

  const int32_T cond_ends_1_29[1] = { 54623 };

  const int32_T postfix_exprs_1_29[2] = { 0, -1 };

  const int32_T cond_starts_1_30[1] = { 54853 };

  const int32_T cond_ends_1_30[1] = { 54937 };

  const int32_T postfix_exprs_1_30[2] = { 0, -1 };

  const int32_T cond_starts_1_31[1] = { 55168 };

  const int32_T cond_ends_1_31[1] = { 55253 };

  const int32_T postfix_exprs_1_31[2] = { 0, -1 };

  const int32_T cond_starts_1_32[1] = { 55480 };

  const int32_T cond_ends_1_32[1] = { 55564 };

  const int32_T postfix_exprs_1_32[2] = { 0, -1 };

  const int32_T cond_starts_1_33[2] = { 56557, 56681 };

  const int32_T cond_ends_1_33[2] = { 56650, 56782 };

  const int32_T postfix_exprs_1_33[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_34[2] = { 59180, 59303 };

  const int32_T cond_ends_1_34[2] = { 59272, 59403 };

  const int32_T postfix_exprs_1_34[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_35[2] = { 61831, 61956 };

  const int32_T cond_ends_1_35[2] = { 61925, 62058 };

  const int32_T postfix_exprs_1_35[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_36[2] = { 64491, 64617 };

  const int32_T cond_ends_1_36[2] = { 64586, 64720 };

  const int32_T postfix_exprs_1_36[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_37[2] = { 67094, 67219 };

  const int32_T cond_ends_1_37[2] = { 67188, 67321 };

  const int32_T postfix_exprs_1_37[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_38[2] = { 69726, 69849 };

  const int32_T cond_ends_1_38[2] = { 69818, 69949 };

  const int32_T postfix_exprs_1_38[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_39[2] = { 72864, 72988 };

  const int32_T cond_ends_1_39[2] = { 72957, 73089 };

  const int32_T postfix_exprs_1_39[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_40[2] = { 75493, 75616 };

  const int32_T cond_ends_1_40[2] = { 75585, 75716 };

  const int32_T postfix_exprs_1_40[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_41[2] = { 78086, 78210 };

  const int32_T cond_ends_1_41[2] = { 78179, 78311 };

  const int32_T postfix_exprs_1_41[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_42[2] = { 80744, 80870 };

  const int32_T cond_ends_1_42[2] = { 80839, 80973 };

  const int32_T postfix_exprs_1_42[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_43[2] = { 83393, 83518 };

  const int32_T cond_ends_1_43[2] = { 83487, 83620 };

  const int32_T postfix_exprs_1_43[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_44[2] = { 85989, 86115 };

  const int32_T cond_ends_1_44[2] = { 86084, 86218 };

  const int32_T postfix_exprs_1_44[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_45[3] = { 89531, 89610, 89647 };

  const int32_T cond_ends_1_45[3] = { 89564, 89643, 89682 };

  const int32_T postfix_exprs_1_45[5] = { 0, 1, 2, -2, -3 };

  const int32_T cond_starts_1_46[2] = { 89816, 89899 };

  const int32_T cond_ends_1_46[2] = { 89860, 89955 };

  const int32_T postfix_exprs_1_46[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_47[2] = { 90083, 90166 };

  const int32_T cond_ends_1_47[2] = { 90127, 90224 };

  const int32_T postfix_exprs_1_47[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_48[2] = { 90352, 90435 };

  const int32_T cond_ends_1_48[2] = { 90396, 90491 };

  const int32_T postfix_exprs_1_48[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_49[2] = { 90619, 90702 };

  const int32_T cond_ends_1_49[2] = { 90663, 90756 };

  const int32_T postfix_exprs_1_49[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_50[3] = { 91080, 91117, 91198 };

  const int32_T cond_ends_1_50[3] = { 91113, 91152, 91231 };

  const int32_T postfix_exprs_1_50[5] = { 0, 1, -2, 2, -3 };

  const int32_T cond_starts_1_51[2] = { 91365, 91448 };

  const int32_T cond_ends_1_51[2] = { 91409, 91504 };

  const int32_T postfix_exprs_1_51[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_52[2] = { 91631, 91714 };

  const int32_T cond_ends_1_52[2] = { 91675, 91768 };

  const int32_T postfix_exprs_1_52[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_53[2] = { 91895, 91978 };

  const int32_T cond_ends_1_53[2] = { 91939, 92034 };

  const int32_T postfix_exprs_1_53[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_54[2] = { 92161, 92244 };

  const int32_T cond_ends_1_54[2] = { 92205, 92302 };

  const int32_T postfix_exprs_1_54[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_55[5] = { 115923, 115956, 116025, 116068, 116100 };

  const int32_T cond_ends_1_55[5] = { 115951, 115995, 116064, 116096, 116128 };

  const int32_T postfix_exprs_1_55[9] = { 0, 1, -3, 2, 3, -3, 4, -3, -2 };

  const int32_T cond_starts_1_56[2] = { 116198, 116231 };

  const int32_T cond_ends_1_56[2] = { 116226, 116270 };

  const int32_T postfix_exprs_1_56[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_57[2] = { 123170, 123195 };

  const int32_T cond_ends_1_57[2] = { 123191, 123201 };

  const int32_T postfix_exprs_1_57[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_58[2] = { 126973, 127010 };

  const int32_T cond_ends_1_58[2] = { 127005, 127053 };

  const int32_T postfix_exprs_1_58[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_59[2] = { 130909, 130945 };

  const int32_T cond_ends_1_59[2] = { 130941, 130983 };

  const int32_T postfix_exprs_1_59[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_60[2] = { 131099, 131135 };

  const int32_T cond_ends_1_60[2] = { 131131, 131167 };

  const int32_T postfix_exprs_1_60[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_61[2] = { 131607, 131643 };

  const int32_T cond_ends_1_61[2] = { 131639, 131675 };

  const int32_T postfix_exprs_1_61[3] = { 0, 1, -3 };

  const int32_T caseStarts_1_0[5] = { 13329, 11362, 11780, 12281, 12802 };

  const int32_T caseExprEnds_1_0[5] = { 13338, 11384, 11802, 12302, 12823 };

  const int32_T caseStarts_1_1[5] = { 39134, 38291, 38454, 38682, 38905 };

  const int32_T caseExprEnds_1_1[5] = { 39143, 38313, 38476, 38703, 38926 };

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
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "maze_init", 0, -1, 1867);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 1807, -1, 1856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 1726, -1, 1775);
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
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 1700, 1721, -1, 1780);
  covrtIfInit(&emlrtCoverageInstance, 0U, 5U, 1781, 1802, -1, 1861);

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
                  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m", 1U, 27U,
                  383U, 498U, 0U, 0U, 2U, 19U, 9U, 115U, 62U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "maze_solve", 0, -1, 172733);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 1U, "search_adachi", 8977, -1, 14266);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 2U, "move_step", 14292, -1, 14883);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 3U, "turn_180deg", 14916, -1, 15051);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 4U, "turn_clk_90deg", 15092, -1,
               15229);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 5U, "turn_conclk_90deg", 15271, -1,
               15413);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 6U, "wall_set", 15435, -1, 30275);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 7U, "make_map_find", 30313, -1, 33544);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 8U, "get_nextdir2", 33585, -1, 35312);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 9U, "fust_run", 35336, -1, 39907);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 10U, "make_map_fustrun", 39944, -1,
               51132);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 11U, "make_map_fustrun_diagonal",
               51178, -1, 88787);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 12U, "decide_goal_node_dir", 88875,
               -1, 102218);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 13U, "decide_goal_section", 102298,
               -1, 114374);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 14U, "goal_judge", 114055, -1, 114366);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 15U, "make_route_diagonal", 114419,
               -1, 130486);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 16U, "get_turn_pattern_num", 127762,
               -1, 130482);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 17U, "get_next_dir_diagonal", 130531,
               -1, 140893);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 18U, "move_straight", 140913, -1,
               148258);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 19U, "turn_r_45", 148270, -1, 151642);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 20U, "turn_l_45", 151655, -1, 155027);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 21U, "turn_r_90", 155039, -1, 158421);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 22U, "turn_l_90", 158433, -1, 161813);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 23U, "turn_r_135", 161826, -1, 165216);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 24U, "turn_l_135", 165229, -1, 168614);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 25U, "turn_r_180", 168627, -1, 170670);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 26U, "turn_l_180", 170683, -1, 172728);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 18U, 7197, -1, 8935);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 17U, 6896, -1, 6981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 16U, 6672, -1, 6781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 15U, 6476, -1, 6540);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 14U, 5943, -1, 6388);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 12U, 5309, -1, 5314);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 5196, -1, 5279);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 13U, 5353, -1, 5845);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 4459, -1, 5037);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 3993, -1, 4303);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 4343, -1, 4348);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 3798, -1, 3915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 3705, -1, 3756);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 3640, -1, 3662);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 2930, -1, 3573);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 2563, -1, 2855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 2386, -1, 2469);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 692, -1, 2327);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 309, -1, 672);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 26U, 11081, -1, 11086);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 25U, 10874, -1, 10957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 36U, 13466, -1, 13663);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 35U, 13115, -1, 13273);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 34U, 12844, -1, 12978);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 33U, 12588, -1, 12746);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 32U, 12323, -1, 12451);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 31U, 12062, -1, 12221);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 30U, 11823, -1, 11954);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 29U, 11579, -1, 11738);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 28U, 11405, -1, 11471);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 27U, 11185, -1, 11259);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 24U, 10614, -1, 10633);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 23U, 10317, -1, 10420);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 22U, 10070, -1, 10143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 21U, 9882, -1, 9958);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 20U, 9685, -1, 9812);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 19U, 9362, -1, 9544);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 40U, 14819, -1, 14842);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 39U, 14698, -1, 14721);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 38U, 14577, -1, 14600);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 37U, 14457, -1, 14480);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 41U, 15001, -1, 15039);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 42U, 15180, -1, 15218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 43U, 15361, -1, 15401);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 69U, 29659, -1, 30234);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 68U, 28730, -1, 29309);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 67U, 27510, -1, 28085);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 66U, 26589, -1, 27160);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 65U, 25376, -1, 25943);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 64U, 24454, -1, 25025);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 63U, 23226, -1, 23805);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 62U, 22288, -1, 22871);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 61U, 21466, -1, 21603);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 60U, 21118, -1, 21433);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 59U, 20741, -1, 21060);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 58U, 20364, -1, 20679);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 57U, 19974, -1, 20293);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 56U, 18514, -1, 19891);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 55U, 18342, -1, 18475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 54U, 18168, -1, 18219);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 53U, 18041, -1, 18103);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 52U, 17748, -1, 17814);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 51U, 17572, -1, 17705);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 50U, 17394, -1, 17447);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 49U, 17267, -1, 17329);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 48U, 17006, -1, 17070);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 47U, 16823, -1, 16954);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 46U, 16645, -1, 16698);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 45U, 16520, -1, 16580);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 44U, 15989, -1, 16219);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 79U, 33507, -1, 33512);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 74U, 31430, -1, 31435);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 78U, 33240, -1, 33342);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 77U, 32783, -1, 32885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 76U, 32325, -1, 32427);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 75U, 31868, -1, 31970);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 73U, 31021, -1, 31318);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 72U, 30834, -1, 30856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 71U, 30742, -1, 30802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 70U, 30506, -1, 30684);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 84U, 35237, -1, 35264);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 83U, 34843, -1, 34936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 82U, 34515, -1, 34607);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 81U, 34155, -1, 34281);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 80U, 33756, -1, 33825);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 90U, 36650, -1, 36655);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 100U, 39840, -1, 39894);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 99U, 39262, -1, 39388);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 98U, 38947, -1, 39081);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 97U, 38724, -1, 38852);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 96U, 38497, -1, 38628);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 95U, 38334, -1, 38400);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 94U, 38057, -1, 38149);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 93U, 37721, -1, 37814);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 92U, 37384, -1, 37476);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 91U, 37015, -1, 37141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 89U, 36544, -1, 36564);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 88U, 36057, -1, 36170);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 87U, 35700, -1, 35964);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 86U, 35624, -1, 35670);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 85U, 35470, -1, 35559);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 114U, 51099, -1, 51104);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 113U, 50398, -1, 50918);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 112U, 49495, -1, 50001);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 111U, 48080, -1, 48601);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 110U, 47176, -1, 47683);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 109U, 45779, -1, 46299);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 108U, 44876, -1, 45382);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 107U, 43460, -1, 43981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 106U, 42556, -1, 43063);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 105U, 41380, -1, 41685);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 104U, 41171, -1, 41193);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 103U, 41116, -1, 41148);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 102U, 40600, -1, 41072);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 101U, 40161, -1, 40482);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 177U, 88684, -1, 88755);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 176U, 88386, -1, 88502);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 175U, 87710, -1, 88168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 174U, 87268, -1, 87384);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 173U, 86592, -1, 87046);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 172U, 85734, -1, 85840);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 171U, 85073, -1, 85519);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 170U, 84645, -1, 84751);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 169U, 83984, -1, 84426);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 168U, 83117, -1, 83229);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 167U, 82449, -1, 82901);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 166U, 82013, -1, 82125);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 165U, 81345, -1, 81793);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 164U, 80432, -1, 80540);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 163U, 79772, -1, 80218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 162U, 79341, -1, 79449);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 161U, 78681, -1, 79123);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 160U, 77830, -1, 77936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 159U, 77169, -1, 77615);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 158U, 76741, -1, 76847);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 157U, 76080, -1, 76522);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 156U, 75233, -1, 75345);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 155U, 74565, -1, 75017);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 154U, 74129, -1, 74241);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 153U, 73461, -1, 73909);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 152U, 72395, -1, 72670);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 151U, 72069, -1, 72177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 150U, 71409, -1, 71855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 149U, 70979, -1, 71087);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 148U, 70319, -1, 70761);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 147U, 69465, -1, 69577);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 146U, 68797, -1, 69249);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 145U, 68361, -1, 68473);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 144U, 67693, -1, 68141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 143U, 66838, -1, 66945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 142U, 66176, -1, 66623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 141U, 65747, -1, 65854);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 140U, 65085, -1, 65528);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 139U, 64227, -1, 64343);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 138U, 63551, -1, 64009);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 137U, 63108, -1, 63224);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 136U, 62432, -1, 62886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 135U, 61547, -1, 61659);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 134U, 60879, -1, 61331);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 133U, 60443, -1, 60555);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 132U, 59775, -1, 60223);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 131U, 58924, -1, 59031);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 130U, 58262, -1, 58709);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 129U, 57809, -1, 57916);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 128U, 57147, -1, 57590);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 127U, 56140, -1, 56415);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 126U, 55915, -1, 55937);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 125U, 55809, -1, 55883);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 124U, 55603, -1, 55739);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 123U, 55292, -1, 55428);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 122U, 54976, -1, 55116);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 121U, 54662, -1, 54802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 120U, 53958, -1, 54322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 119U, 53425, -1, 53790);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 118U, 52884, -1, 53256);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 117U, 52343, -1, 52716);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 116U, 52126, -1, 52157);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 115U, 51439, -1, 52094);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 190U, 93119, -1, 93124);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 204U, 102106, -1, 102180);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 203U, 101571, -1, 101977);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 202U, 100895, -1, 101290);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 201U, 100220, -1, 100622);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 200U, 99445, -1, 99843);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 199U, 98773, -1, 99168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 198U, 98098, -1, 98500);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 197U, 97209, -1, 97606);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 196U, 96426, -1, 96827);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 195U, 95751, -1, 96147);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 194U, 95072, -1, 95477);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 193U, 94293, -1, 94694);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 192U, 93618, -1, 94014);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 191U, 93256, -1, 93290);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 189U, 92479, -1, 92499);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 188U, 92331, -1, 92368);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 187U, 92063, -1, 92100);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 186U, 91797, -1, 91834);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 185U, 91533, -1, 91570);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 184U, 90959, -1, 90979);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 183U, 90785, -1, 90823);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 182U, 90520, -1, 90558);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 181U, 90253, -1, 90291);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 180U, 89984, -1, 90022);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 179U, 89363, -1, 89383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 178U, 89033, -1, 89332);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 245U, 113778, -1, 113945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 244U, 113566, -1, 113735);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 243U, 113298, -1, 113471);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 242U, 113028, -1, 113201);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 241U, 112713, -1, 112878);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 240U, 112501, -1, 112670);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 239U, 112239, -1, 112406);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 238U, 111971, -1, 112144);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 237U, 111572, -1, 111739);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 236U, 111360, -1, 111529);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 235U, 110926, -1, 111093);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 234U, 110694, -1, 110863);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 233U, 110427, -1, 110598);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 232U, 110157, -1, 110330);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 231U, 109858, -1, 110025);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 230U, 109624, -1, 109793);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 229U, 109354, -1, 109525);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 228U, 109064, -1, 109237);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 227U, 108667, -1, 108834);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 226U, 108455, -1, 108624);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 225U, 108067, -1, 108232);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 224U, 107831, -1, 108000);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 223U, 107545, -1, 107712);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 222U, 107257, -1, 107430);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 221U, 106960, -1, 107127);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 220U, 106748, -1, 106917);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 219U, 106480, -1, 106653);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 218U, 106210, -1, 106383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 217U, 105815, -1, 105980);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 216U, 105603, -1, 105772);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 215U, 105189, -1, 105354);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 214U, 104974, -1, 105143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 213U, 104707, -1, 104876);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 212U, 104433, -1, 104606);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 211U, 104136, -1, 104301);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 210U, 103920, -1, 104089);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 209U, 103654, -1, 103823);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 208U, 103366, -1, 103539);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 207U, 102947, -1, 103112);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 206U, 102735, -1, 102904);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 205U, 102432, -1, 102543);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 246U, 114136, -1, 114340);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 277U, 127400, -1, 127405);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 278U, 127476, -1, 127668);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 276U, 127149, -1, 127313);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 275U, 127071, -1, 127084);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 274U, 126623, -1, 126802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 273U, 126249, -1, 126428);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 272U, 125872, -1, 126051);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 271U, 125487, -1, 125666);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 270U, 125118, -1, 125296);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 269U, 124531, -1, 124709);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 268U, 123946, -1, 124124);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 267U, 123576, -1, 123754);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 265U, 122801, -1, 122806);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 264U, 122656, -1, 122755);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 266U, 122882, -1, 123089);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 263U, 122286, -1, 122478);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 262U, 122000, -1, 122028);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 261U, 121606, -1, 121817);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 260U, 121425, -1, 121524);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 259U, 121162, -1, 121175);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 258U, 120738, -1, 120957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 257U, 120538, -1, 120637);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 256U, 119791, -1, 119981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 255U, 119365, -1, 119555);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 254U, 118612, -1, 118711);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 253U, 118135, -1, 118495);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 252U, 117732, -1, 117955);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 251U, 117518, -1, 117617);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 250U, 116694, -1, 117024);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 249U, 116339, -1, 116545);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 248U, 115668, -1, 115876);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 247U, 114551, -1, 115408);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 293U, 130213, -1, 130250);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 292U, 130100, -1, 130136);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 291U, 129945, -1, 129981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 290U, 129782, -1, 129819);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 289U, 129669, -1, 129705);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 288U, 129514, -1, 129550);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 287U, 129221, -1, 129258);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 286U, 129098, -1, 129135);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 285U, 128930, -1, 128966);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 284U, 128817, -1, 128853);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 283U, 128567, -1, 128604);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 282U, 128444, -1, 128481);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 281U, 128276, -1, 128312);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 280U, 128163, -1, 128199);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 279U, 127895, -1, 127934);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 312U, 140336, -1, 140737);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 311U, 139584, -1, 139974);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 310U, 138833, -1, 139230);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 309U, 138046, -1, 138419);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 308U, 137419, -1, 137789);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 307U, 136789, -1, 137166);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 306U, 135964, -1, 136337);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 305U, 135233, -1, 135610);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 304U, 134603, -1, 134974);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 303U, 133968, -1, 134349);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 302U, 133241, -1, 133618);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 301U, 132611, -1, 132982);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 300U, 132273, -1, 132307);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 299U, 132172, -1, 132195);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 298U, 131912, -1, 132067);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 297U, 131696, -1, 131849);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 296U, 131366, -1, 131522);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 295U, 131188, -1, 131323);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 294U, 130745, -1, 130854);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 326U, 148224, -1, 148249);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 325U, 147445, -1, 147724);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 324U, 147048, -1, 147339);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 323U, 146300, -1, 146585);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 322U, 145909, -1, 146194);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 321U, 145158, -1, 145449);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 320U, 144773, -1, 145052);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 319U, 144025, -1, 144310);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 318U, 143634, -1, 143919);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 317U, 143335, -1, 143480);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 316U, 142635, -1, 142873);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 315U, 142182, -1, 142421);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 314U, 141730, -1, 141968);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 313U, 141277, -1, 141516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 334U, 151094, -1, 151322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 333U, 150769, -1, 150994);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 332U, 150445, -1, 150669);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 331U, 150120, -1, 150345);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 330U, 149573, -1, 149806);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 329U, 149249, -1, 149480);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 328U, 148924, -1, 149155);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 327U, 148598, -1, 148831);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 342U, 154483, -1, 154706);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 341U, 154157, -1, 154383);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 340U, 153830, -1, 154057);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 339U, 153504, -1, 153730);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 338U, 152960, -1, 153191);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 337U, 152634, -1, 152867);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 336U, 152307, -1, 152540);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 335U, 151983, -1, 152214);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 350U, 157878, -1, 158109);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 349U, 157547, -1, 157778);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 348U, 157216, -1, 157447);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 347U, 156885, -1, 157116);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 346U, 156325, -1, 156553);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 345U, 156007, -1, 156232);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 344U, 155687, -1, 155913);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 343U, 155367, -1, 155594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 358U, 161272, -1, 161503);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 357U, 160941, -1, 161172);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 356U, 160610, -1, 160841);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 355U, 160279, -1, 160510);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 354U, 159721, -1, 159947);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 353U, 159401, -1, 159628);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 352U, 159079, -1, 159307);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 351U, 158761, -1, 158986);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 366U, 164671, -1, 164896);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 365U, 164345, -1, 164571);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 364U, 164020, -1, 164245);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 363U, 163694, -1, 163920);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 362U, 163134, -1, 163367);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 361U, 162808, -1, 163041);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 360U, 162481, -1, 162714);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 359U, 162155, -1, 162388);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 374U, 168070, -1, 168296);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 373U, 167745, -1, 167970);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 372U, 167419, -1, 167645);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 371U, 167094, -1, 167319);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 370U, 166537, -1, 166770);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 369U, 166211, -1, 166444);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 368U, 165884, -1, 166117);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 367U, 165558, -1, 165791);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 378U, 169919, -1, 170146);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 377U, 169598, -1, 169826);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 376U, 169277, -1, 169504);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 375U, 168956, -1, 169184);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 382U, 171975, -1, 172202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 381U, 171654, -1, 171882);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 380U, 171333, -1, 171560);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 379U, 171012, -1, 171240);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 272, 297, 299, 678);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 2336, 2364, -1, 6604);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 2485, 2510, 2878, 2908);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 3771, 3781, 3949, 3952);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 3961, 3980, 4326, 4360);
  covrtIfInit(&emlrtCoverageInstance, 1U, 5U, 5056, 5104, 5335, 5871);
  covrtIfInit(&emlrtCoverageInstance, 1U, 6U, 5153, 5179, -1, 5296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 7U, 6403, 6428, 6550, 6595);
  covrtIfInit(&emlrtCoverageInstance, 1U, 8U, 6614, 6644, -1, 7096);
  covrtIfInit(&emlrtCoverageInstance, 1U, 9U, 6808, 6833, -1, 7018);
  covrtIfInit(&emlrtCoverageInstance, 1U, 10U, 7111, 7150, -1, 8949);
  covrtIfInit(&emlrtCoverageInstance, 1U, 11U, 9632, 9672, 9826, 9988);
  covrtIfInit(&emlrtCoverageInstance, 1U, 12U, 10027, 10052, -1, 10160);
  covrtIfInit(&emlrtCoverageInstance, 1U, 13U, 10514, 10593, -1, 10655);
  covrtIfInit(&emlrtCoverageInstance, 1U, 14U, 10705, 10721, -1, 11110);
  covrtIfInit(&emlrtCoverageInstance, 1U, 15U, 10738, 10754, -1, 11018);
  covrtIfInit(&emlrtCoverageInstance, 1U, 16U, 10823, 10849, -1, 10998);
  covrtIfInit(&emlrtCoverageInstance, 1U, 17U, 11528, 11554, -1, 11763);
  covrtIfInit(&emlrtCoverageInstance, 1U, 18U, 12011, 12037, -1, 12246);
  covrtIfInit(&emlrtCoverageInstance, 1U, 19U, 12537, 12563, -1, 12771);
  covrtIfInit(&emlrtCoverageInstance, 1U, 20U, 13064, 13090, -1, 13298);
  covrtIfInit(&emlrtCoverageInstance, 1U, 21U, 13368, 13393, 13752, 13809);
  covrtIfInit(&emlrtCoverageInstance, 1U, 22U, 14413, 14448, -1, 14517);
  covrtIfInit(&emlrtCoverageInstance, 1U, 23U, 14534, 14568, -1, 14637);
  covrtIfInit(&emlrtCoverageInstance, 1U, 24U, 14654, 14689, -1, 14759);
  covrtIfInit(&emlrtCoverageInstance, 1U, 25U, 14776, 14810, -1, 14878);
  covrtIfInit(&emlrtCoverageInstance, 1U, 26U, 16321, 16346, 16598, 16984);
  covrtIfInit(&emlrtCoverageInstance, 1U, 27U, 16404, 16479, -1, 16593);
  covrtIfInit(&emlrtCoverageInstance, 1U, 28U, 16734, 16791, -1, 16967);
  covrtIfInit(&emlrtCoverageInstance, 1U, 29U, 17087, 17112, 17347, 17726);
  covrtIfInit(&emlrtCoverageInstance, 1U, 30U, 17170, 17254, -1, 17342);
  covrtIfInit(&emlrtCoverageInstance, 1U, 31U, 17483, 17540, -1, 17718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 32U, 17861, 17886, 18121, 18496);
  covrtIfInit(&emlrtCoverageInstance, 1U, 33U, 17944, 18028, -1, 18116);
  covrtIfInit(&emlrtCoverageInstance, 1U, 34U, 18255, 18310, -1, 18488);
  covrtIfInit(&emlrtCoverageInstance, 1U, 35U, 19935, 19965, -1, 20302);
  covrtIfInit(&emlrtCoverageInstance, 1U, 36U, 20325, 20355, -1, 20688);
  covrtIfInit(&emlrtCoverageInstance, 1U, 37U, 20716, 20732, -1, 21069);
  covrtIfInit(&emlrtCoverageInstance, 1U, 38U, 21093, 21109, -1, 21442);
  covrtIfInit(&emlrtCoverageInstance, 1U, 39U, 21609, 21617, -1, 30271);
  covrtIfInit(&emlrtCoverageInstance, 1U, 40U, 21692, 21950, -1, 23836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 41U, 21999, 22229, -1, 22888);
  covrtIfInit(&emlrtCoverageInstance, 1U, 42U, 22936, 23169, -1, 23822);
  covrtIfInit(&emlrtCoverageInstance, 1U, 43U, 23867, 24125, -1, 25974);
  covrtIfInit(&emlrtCoverageInstance, 1U, 44U, 24173, 24399, -1, 25042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 45U, 25091, 25320, -1, 25961);
  covrtIfInit(&emlrtCoverageInstance, 1U, 46U, 26005, 26259, -1, 28116);
  covrtIfInit(&emlrtCoverageInstance, 1U, 47U, 26307, 26533, -1, 27177);
  covrtIfInit(&emlrtCoverageInstance, 1U, 48U, 27225, 27454, -1, 28103);
  covrtIfInit(&emlrtCoverageInstance, 1U, 49U, 28146, 28400, -1, 30263);
  covrtIfInit(&emlrtCoverageInstance, 1U, 50U, 28448, 28674, -1, 29326);
  covrtIfInit(&emlrtCoverageInstance, 1U, 51U, 29374, 29603, -1, 30251);
  covrtIfInit(&emlrtCoverageInstance, 1U, 52U, 31386, 31409, -1, 31456);
  covrtIfInit(&emlrtCoverageInstance, 1U, 53U, 31611, 31708, -1, 32023);
  covrtIfInit(&emlrtCoverageInstance, 1U, 54U, 31789, 31842, -1, 31999);
  covrtIfInit(&emlrtCoverageInstance, 1U, 55U, 32069, 32165, -1, 32480);
  covrtIfInit(&emlrtCoverageInstance, 1U, 56U, 32246, 32299, -1, 32456);
  covrtIfInit(&emlrtCoverageInstance, 1U, 57U, 32526, 32623, -1, 32938);
  covrtIfInit(&emlrtCoverageInstance, 1U, 58U, 32704, 32757, -1, 32914);
  covrtIfInit(&emlrtCoverageInstance, 1U, 59U, 32984, 33080, -1, 33395);
  covrtIfInit(&emlrtCoverageInstance, 1U, 60U, 33161, 33214, -1, 33371);
  covrtIfInit(&emlrtCoverageInstance, 1U, 61U, 33468, 33494, -1, 33525);
  covrtIfInit(&emlrtCoverageInstance, 1U, 62U, 33913, 33996, -1, 34318);
  covrtIfInit(&emlrtCoverageInstance, 1U, 63U, 34051, 34097, -1, 34302);
  covrtIfInit(&emlrtCoverageInstance, 1U, 64U, 34348, 34430, -1, 34644);
  covrtIfInit(&emlrtCoverageInstance, 1U, 65U, 34448, 34494, -1, 34628);
  covrtIfInit(&emlrtCoverageInstance, 1U, 66U, 34675, 34758, -1, 34973);
  covrtIfInit(&emlrtCoverageInstance, 1U, 67U, 34776, 34822, -1, 34957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 68U, 35003, 35085, -1, 35301);
  covrtIfInit(&emlrtCoverageInstance, 1U, 69U, 35103, 35149, -1, 35285);
  covrtIfInit(&emlrtCoverageInstance, 1U, 70U, 35590, 35615, -1, 35679);
  covrtIfInit(&emlrtCoverageInstance, 1U, 71U, 35999, 36024, -1, 36204);
  covrtIfInit(&emlrtCoverageInstance, 1U, 72U, 36450, 36523, -1, 36586);
  covrtIfInit(&emlrtCoverageInstance, 1U, 73U, 36616, 36633, -1, 36679);
  covrtIfInit(&emlrtCoverageInstance, 1U, 74U, 36764, 36857, -1, 37178);
  covrtIfInit(&emlrtCoverageInstance, 1U, 75U, 36911, 36957, -1, 37162);
  covrtIfInit(&emlrtCoverageInstance, 1U, 76U, 37208, 37300, -1, 37513);
  covrtIfInit(&emlrtCoverageInstance, 1U, 77U, 37317, 37363, -1, 37497);
  covrtIfInit(&emlrtCoverageInstance, 1U, 78U, 37543, 37636, -1, 37851);
  covrtIfInit(&emlrtCoverageInstance, 1U, 79U, 37654, 37700, -1, 37835);
  covrtIfInit(&emlrtCoverageInstance, 1U, 80U, 37881, 37973, -1, 38186);
  covrtIfInit(&emlrtCoverageInstance, 1U, 81U, 37990, 38036, -1, 38170);
  covrtIfInit(&emlrtCoverageInstance, 1U, 82U, 39181, 39206, 39777, 39822);
  covrtIfInit(&emlrtCoverageInstance, 1U, 83U, 41889, 42137, -1, 44066);
  covrtIfInit(&emlrtCoverageInstance, 1U, 84U, 42227, 42319, 43195, 44042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 85U, 42400, 42478, -1, 43096);
  covrtIfInit(&emlrtCoverageInstance, 1U, 86U, 43285, 43377, -1, 44014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 87U, 44212, 44458, -1, 46384);
  covrtIfInit(&emlrtCoverageInstance, 1U, 88U, 44548, 44639, 45514, 46360);
  covrtIfInit(&emlrtCoverageInstance, 1U, 89U, 44720, 44798, -1, 45415);
  covrtIfInit(&emlrtCoverageInstance, 1U, 90U, 45604, 45696, -1, 46332);
  covrtIfInit(&emlrtCoverageInstance, 1U, 91U, 46509, 46757, -1, 48686);
  covrtIfInit(&emlrtCoverageInstance, 1U, 92U, 46847, 46939, 47815, 48662);
  covrtIfInit(&emlrtCoverageInstance, 1U, 93U, 47020, 47098, -1, 47716);
  covrtIfInit(&emlrtCoverageInstance, 1U, 94U, 47905, 47997, -1, 48634);
  covrtIfInit(&emlrtCoverageInstance, 1U, 95U, 48831, 49077, -1, 51003);
  covrtIfInit(&emlrtCoverageInstance, 1U, 96U, 49167, 49258, 50133, 50979);
  covrtIfInit(&emlrtCoverageInstance, 1U, 97U, 49339, 49417, -1, 50034);
  covrtIfInit(&emlrtCoverageInstance, 1U, 98U, 50223, 50315, -1, 50951);
  covrtIfInit(&emlrtCoverageInstance, 1U, 99U, 51067, 51086, -1, 51117);
  covrtIfInit(&emlrtCoverageInstance, 1U, 100U, 52100, 52117, 54377, 55893);
  covrtIfInit(&emlrtCoverageInstance, 1U, 101U, 52217, 52312, -1, 52729);
  covrtIfInit(&emlrtCoverageInstance, 1U, 102U, 52759, 52853, -1, 53269);
  covrtIfInit(&emlrtCoverageInstance, 1U, 103U, 53299, 53394, -1, 53803);
  covrtIfInit(&emlrtCoverageInstance, 1U, 104U, 53833, 53927, -1, 54335);
  covrtIfInit(&emlrtCoverageInstance, 1U, 105U, 54534, 54623, -1, 54819);
  covrtIfInit(&emlrtCoverageInstance, 1U, 106U, 54849, 54937, -1, 55133);
  covrtIfInit(&emlrtCoverageInstance, 1U, 107U, 55164, 55253, -1, 55445);
  covrtIfInit(&emlrtCoverageInstance, 1U, 108U, 55476, 55564, -1, 55756);
  covrtIfInit(&emlrtCoverageInstance, 1U, 109U, 56554, 56782, -1, 59104);
  covrtIfInit(&emlrtCoverageInstance, 1U, 110U, 56839, 56925, 58032, 59084);
  covrtIfInit(&emlrtCoverageInstance, 1U, 111U, 56999, 57077, 57660, 57743);
  covrtIfInit(&emlrtCoverageInstance, 1U, 112U, 57660, 57743, -1, 57743);
  covrtIfInit(&emlrtCoverageInstance, 1U, 113U, 58115, 58189, 58779, 58858);
  covrtIfInit(&emlrtCoverageInstance, 1U, 114U, 58779, 58858, -1, 58858);
  covrtIfInit(&emlrtCoverageInstance, 1U, 115U, 59177, 59403, -1, 61732);
  covrtIfInit(&emlrtCoverageInstance, 1U, 116U, 59461, 59552, 60648, 61712);
  covrtIfInit(&emlrtCoverageInstance, 1U, 117U, 59627, 59705, 60294, 60377);
  covrtIfInit(&emlrtCoverageInstance, 1U, 118U, 60294, 60377, -1, 60377);
  covrtIfInit(&emlrtCoverageInstance, 1U, 119U, 60732, 60806, 61402, 61481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 120U, 61402, 61481, -1, 61481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 121U, 61828, 62058, -1, 64416);
  covrtIfInit(&emlrtCoverageInstance, 1U, 122U, 62116, 62207, 63318, 64396);
  covrtIfInit(&emlrtCoverageInstance, 1U, 123U, 62282, 62362, 62957, 63042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 124U, 62957, 63042, -1, 63042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 125U, 63402, 63478, 64080, 64161);
  covrtIfInit(&emlrtCoverageInstance, 1U, 126U, 64080, 64161, -1, 64161);
  covrtIfInit(&emlrtCoverageInstance, 1U, 127U, 64488, 64720, -1, 67018);
  covrtIfInit(&emlrtCoverageInstance, 1U, 128U, 64777, 64863, 65946, 66998);
  covrtIfInit(&emlrtCoverageInstance, 1U, 129U, 64937, 65015, 65598, 65681);
  covrtIfInit(&emlrtCoverageInstance, 1U, 130U, 65598, 65681, -1, 65681);
  covrtIfInit(&emlrtCoverageInstance, 1U, 131U, 66029, 66103, 66693, 66772);
  covrtIfInit(&emlrtCoverageInstance, 1U, 132U, 66693, 66772, -1, 66772);
  covrtIfInit(&emlrtCoverageInstance, 1U, 133U, 67091, 67321, -1, 69650);
  covrtIfInit(&emlrtCoverageInstance, 1U, 134U, 67379, 67470, 68566, 69630);
  covrtIfInit(&emlrtCoverageInstance, 1U, 135U, 67545, 67623, 68212, 68295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 136U, 68212, 68295, -1, 68295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 137U, 68650, 68724, 69320, 69399);
  covrtIfInit(&emlrtCoverageInstance, 1U, 138U, 69320, 69399, -1, 69399);
  covrtIfInit(&emlrtCoverageInstance, 1U, 139U, 69723, 69949, -1, 72250);
  covrtIfInit(&emlrtCoverageInstance, 1U, 140U, 70007, 70098, 71180, 72230);
  covrtIfInit(&emlrtCoverageInstance, 1U, 141U, 70173, 70249, 70832, 70913);
  covrtIfInit(&emlrtCoverageInstance, 1U, 142U, 70832, 70913, -1, 70913);
  covrtIfInit(&emlrtCoverageInstance, 1U, 143U, 71264, 71336, 71926, 72003);
  covrtIfInit(&emlrtCoverageInstance, 1U, 144U, 71926, 72003, -1, 72003);
  covrtIfInit(&emlrtCoverageInstance, 1U, 145U, 72861, 73089, -1, 75418);
  covrtIfInit(&emlrtCoverageInstance, 1U, 146U, 73147, 73238, 74334, 75398);
  covrtIfInit(&emlrtCoverageInstance, 1U, 147U, 73313, 73391, 73980, 74063);
  covrtIfInit(&emlrtCoverageInstance, 1U, 148U, 73980, 74063, -1, 74063);
  covrtIfInit(&emlrtCoverageInstance, 1U, 149U, 74418, 74492, 75088, 75167);
  covrtIfInit(&emlrtCoverageInstance, 1U, 150U, 75088, 75167, -1, 75167);
  covrtIfInit(&emlrtCoverageInstance, 1U, 151U, 75490, 75716, -1, 78010);
  covrtIfInit(&emlrtCoverageInstance, 1U, 152U, 75773, 75858, 76939, 77990);
  covrtIfInit(&emlrtCoverageInstance, 1U, 153U, 75932, 76010, 76592, 76675);
  covrtIfInit(&emlrtCoverageInstance, 1U, 154U, 76592, 76675, -1, 76675);
  covrtIfInit(&emlrtCoverageInstance, 1U, 155U, 77022, 77096, 77685, 77764);
  covrtIfInit(&emlrtCoverageInstance, 1U, 156U, 77685, 77764, -1, 77764);
  covrtIfInit(&emlrtCoverageInstance, 1U, 157U, 78083, 78311, -1, 80613);
  covrtIfInit(&emlrtCoverageInstance, 1U, 158U, 78369, 78460, 79543, 80593);
  covrtIfInit(&emlrtCoverageInstance, 1U, 159U, 78535, 78611, 79194, 79275);
  covrtIfInit(&emlrtCoverageInstance, 1U, 160U, 79194, 79275, -1, 79275);
  covrtIfInit(&emlrtCoverageInstance, 1U, 161U, 79627, 79699, 80289, 80366);
  covrtIfInit(&emlrtCoverageInstance, 1U, 162U, 80289, 80366, -1, 80366);
  covrtIfInit(&emlrtCoverageInstance, 1U, 163U, 80741, 80973, -1, 83302);
  covrtIfInit(&emlrtCoverageInstance, 1U, 164U, 81031, 81122, 82218, 83282);
  covrtIfInit(&emlrtCoverageInstance, 1U, 165U, 81197, 81275, 81864, 81947);
  covrtIfInit(&emlrtCoverageInstance, 1U, 166U, 81864, 81947, -1, 81947);
  covrtIfInit(&emlrtCoverageInstance, 1U, 167U, 82302, 82376, 82972, 83051);
  covrtIfInit(&emlrtCoverageInstance, 1U, 168U, 82972, 83051, -1, 83051);
  covrtIfInit(&emlrtCoverageInstance, 1U, 169U, 83390, 83620, -1, 85913);
  covrtIfInit(&emlrtCoverageInstance, 1U, 170U, 83677, 83762, 84843, 85893);
  covrtIfInit(&emlrtCoverageInstance, 1U, 171U, 83836, 83914, 84496, 84579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 172U, 84496, 84579, -1, 84579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 173U, 84926, 85000, 85589, 85668);
  covrtIfInit(&emlrtCoverageInstance, 1U, 174U, 85589, 85668, -1, 85668);
  covrtIfInit(&emlrtCoverageInstance, 1U, 175U, 85986, 86218, -1, 88575);
  covrtIfInit(&emlrtCoverageInstance, 1U, 176U, 86276, 86367, 87477, 88555);
  covrtIfInit(&emlrtCoverageInstance, 1U, 177U, 86442, 86522, 87117, 87202);
  covrtIfInit(&emlrtCoverageInstance, 1U, 178U, 87117, 87202, -1, 87202);
  covrtIfInit(&emlrtCoverageInstance, 1U, 179U, 87561, 87637, 88239, 88320);
  covrtIfInit(&emlrtCoverageInstance, 1U, 180U, 88239, 88320, -1, 88320);
  covrtIfInit(&emlrtCoverageInstance, 1U, 181U, 88652, 88671, -1, 88768);
  covrtIfInit(&emlrtCoverageInstance, 1U, 182U, 89465, 89504, 91051, 92544);
  covrtIfInit(&emlrtCoverageInstance, 1U, 183U, 89527, 89683, -1, 91004);
  covrtIfInit(&emlrtCoverageInstance, 1U, 184U, 89813, 89955, 90076, 90224);
  covrtIfInit(&emlrtCoverageInstance, 1U, 185U, 90076, 90224, 90345, 90880);
  covrtIfInit(&emlrtCoverageInstance, 1U, 186U, 90345, 90491, 90612, 90880);
  covrtIfInit(&emlrtCoverageInstance, 1U, 187U, 90612, 90756, -1, 90756);
  covrtIfInit(&emlrtCoverageInstance, 1U, 188U, 91076, 91232, -1, 92524);
  covrtIfInit(&emlrtCoverageInstance, 1U, 189U, 91362, 91504, 91624, 91768);
  covrtIfInit(&emlrtCoverageInstance, 1U, 190U, 91624, 91768, 91888, 92425);
  covrtIfInit(&emlrtCoverageInstance, 1U, 191U, 91888, 92034, 92154, 92425);
  covrtIfInit(&emlrtCoverageInstance, 1U, 192U, 92154, 92302, -1, 92302);
  covrtIfInit(&emlrtCoverageInstance, 1U, 193U, 92895, 92912, 93166, 102198);
  covrtIfInit(&emlrtCoverageInstance, 1U, 194U, 93346, 93385, 97762, 102071);
  covrtIfInit(&emlrtCoverageInstance, 1U, 195U, 93414, 93444, 94080, 94119);
  covrtIfInit(&emlrtCoverageInstance, 1U, 196U, 93477, 93537, -1, 94051);
  covrtIfInit(&emlrtCoverageInstance, 1U, 197U, 94080, 94119, 94760, 97699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 198U, 94152, 94212, -1, 94731);
  covrtIfInit(&emlrtCoverageInstance, 1U, 199U, 94760, 94793, 94857, 97699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 200U, 94857, 94896, 95543, 97699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 201U, 94929, 94991, -1, 95514);
  covrtIfInit(&emlrtCoverageInstance, 1U, 202U, 95543, 95577, 96213, 97699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 203U, 95610, 95670, -1, 96184);
  covrtIfInit(&emlrtCoverageInstance, 1U, 204U, 96213, 96252, 96893, 97699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 205U, 96285, 96345, -1, 96864);
  covrtIfInit(&emlrtCoverageInstance, 1U, 206U, 96893, 96926, 96990, 97699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 207U, 96990, 97029, -1, 97029);
  covrtIfInit(&emlrtCoverageInstance, 1U, 208U, 97070, 97128, -1, 97643);
  covrtIfInit(&emlrtCoverageInstance, 1U, 209U, 97795, 97825, 97885, 97924);
  covrtIfInit(&emlrtCoverageInstance, 1U, 210U, 97885, 97924, 98566, 102046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 211U, 97957, 98017, -1, 98537);
  covrtIfInit(&emlrtCoverageInstance, 1U, 212U, 98566, 98599, 99234, 102046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 213U, 98632, 98692, -1, 99205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 214U, 99234, 99273, 99909, 102046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 215U, 99306, 99364, -1, 99880);
  covrtIfInit(&emlrtCoverageInstance, 1U, 216U, 99909, 99943, 100007, 102046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 217U, 100007, 100046, 100688, 102046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 218U, 100079, 100139, -1, 100659);
  covrtIfInit(&emlrtCoverageInstance, 1U, 219U, 100688, 100721, 101356, 102046);
  covrtIfInit(&emlrtCoverageInstance, 1U, 220U, 100754, 100814, -1, 101327);
  covrtIfInit(&emlrtCoverageInstance, 1U, 221U, 101356, 101395, -1, 101395);
  covrtIfInit(&emlrtCoverageInstance, 1U, 222U, 101428, 101490, -1, 102014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 223U, 102562, 102596, 103182, 103225);
  covrtIfInit(&emlrtCoverageInstance, 1U, 224U, 102609, 102645, -1, 103149);
  covrtIfInit(&emlrtCoverageInstance, 1U, 225U, 102662, 102714, 102922, 103133);
  covrtIfInit(&emlrtCoverageInstance, 1U, 226U, 103182, 103225, 105403, 114011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 227U, 103238, 103274, 104337, 105394);
  covrtIfInit(&emlrtCoverageInstance, 1U, 228U, 103291, 103345, 103577, 104324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 229U, 103577, 103633, 103843, 104324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 230U, 103843, 103899, 104111, 104324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 231U, 104358, 104412, 104630, 105378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 232U, 104630, 104686, 104897, 105378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 233U, 104897, 104953, 105164, 105378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 234U, 105403, 105440, 106026, 114011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 235U, 105477, 105513, -1, 106017);
  covrtIfInit(&emlrtCoverageInstance, 1U, 236U, 105530, 105582, 105790, 106001);
  covrtIfInit(&emlrtCoverageInstance, 1U, 237U, 106026, 106069, 108278, 114011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 238U, 106082, 106118, 107161, 108269);
  covrtIfInit(&emlrtCoverageInstance, 1U, 239U, 106135, 106189, 106401, 107148);
  covrtIfInit(&emlrtCoverageInstance, 1U, 240U, 106401, 106459, 106671, 107148);
  covrtIfInit(&emlrtCoverageInstance, 1U, 241U, 106671, 106727, 106935, 107148);
  covrtIfInit(&emlrtCoverageInstance, 1U, 242U, 107182, 107236, 107468, 108253);
  covrtIfInit(&emlrtCoverageInstance, 1U, 243U, 107468, 107524, 107754, 108253);
  covrtIfInit(&emlrtCoverageInstance, 1U, 244U, 107754, 107810, 108042, 108253);
  covrtIfInit(&emlrtCoverageInstance, 1U, 245U, 108278, 108316, 108880, 114011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 246U, 108329, 108365, -1, 108871);
  covrtIfInit(&emlrtCoverageInstance, 1U, 247U, 108382, 108434, 108642, 108855);
  covrtIfInit(&emlrtCoverageInstance, 1U, 248U, 108880, 108923, 111160, 114011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 249U, 108936, 108972, 110061, 111151);
  covrtIfInit(&emlrtCoverageInstance, 1U, 250U, 108989, 109043, 109275, 110048);
  covrtIfInit(&emlrtCoverageInstance, 1U, 251U, 109275, 109333, 109547, 110048);
  covrtIfInit(&emlrtCoverageInstance, 1U, 252U, 109547, 109603, 109833, 110048);
  covrtIfInit(&emlrtCoverageInstance, 1U, 253U, 110082, 110136, 110348, 111135);
  covrtIfInit(&emlrtCoverageInstance, 1U, 254U, 110348, 110406, 110617, 111135);
  covrtIfInit(&emlrtCoverageInstance, 1U, 255U, 110617, 110673, 110901, 111135);
  covrtIfInit(&emlrtCoverageInstance, 1U, 256U, 111160, 111197, 111787, 114011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 257U, 111234, 111270, -1, 111776);
  covrtIfInit(&emlrtCoverageInstance, 1U, 258U, 111287, 111339, 111547, 111760);
  covrtIfInit(&emlrtCoverageInstance, 1U, 259U, 111787, 111830, -1, 111830);
  covrtIfInit(&emlrtCoverageInstance, 1U, 260U, 111843, 111879, 112932, 113999);
  covrtIfInit(&emlrtCoverageInstance, 1U, 261U, 111896, 111950, 112162, 112919);
  covrtIfInit(&emlrtCoverageInstance, 1U, 262U, 112162, 112218, 112424, 112919);
  covrtIfInit(&emlrtCoverageInstance, 1U, 263U, 112424, 112480, 112688, 112919);
  covrtIfInit(&emlrtCoverageInstance, 1U, 264U, 112953, 113007, 113219, 113966);
  covrtIfInit(&emlrtCoverageInstance, 1U, 265U, 113219, 113277, 113489, 113966);
  covrtIfInit(&emlrtCoverageInstance, 1U, 266U, 113489, 113545, 113753, 113966);
  covrtIfInit(&emlrtCoverageInstance, 1U, 267U, 115598, 115630, 121249, 127327);
  covrtIfInit(&emlrtCoverageInstance, 1U, 268U, 115919, 116129, -1, 121192);
  covrtIfInit(&emlrtCoverageInstance, 1U, 269U, 116194, 116272, 120298, 121002);
  covrtIfInit(&emlrtCoverageInstance, 1U, 270U, 116600, 116632, 117219, 120248);
  covrtIfInit(&emlrtCoverageInstance, 1U, 271U, 117373, 117394, -1, 117984);
  covrtIfInit(&emlrtCoverageInstance, 1U, 272U, 117460, 117485, -1, 117652);
  covrtIfInit(&emlrtCoverageInstance, 1U, 273U, 118558, 118583, -1, 118740);
  covrtIfInit(&emlrtCoverageInstance, 1U, 274U, 118809, 118833, -1, 119094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 275U, 118862, 118887, -1, 119066);
  covrtIfInit(&emlrtCoverageInstance, 1U, 276U, 119157, 119197, 119582, 120224);
  covrtIfInit(&emlrtCoverageInstance, 1U, 277U, 119227, 119252, -1, 119336);
  covrtIfInit(&emlrtCoverageInstance, 1U, 278U, 119582, 119626, 120007, 120224);
  covrtIfInit(&emlrtCoverageInstance, 1U, 279U, 119655, 119680, -1, 119762);
  covrtIfInit(&emlrtCoverageInstance, 1U, 280U, 120040, 120065, -1, 120196);
  covrtIfInit(&emlrtCoverageInstance, 1U, 281U, 120405, 120426, -1, 120982);
  covrtIfInit(&emlrtCoverageInstance, 1U, 282U, 120484, 120509, -1, 120666);
  covrtIfInit(&emlrtCoverageInstance, 1U, 283U, 121316, 121337, -1, 121947);
  covrtIfInit(&emlrtCoverageInstance, 1U, 284U, 121379, 121404, -1, 121550);
  covrtIfInit(&emlrtCoverageInstance, 1U, 285U, 122529, 122553, 122824, 123110);
  covrtIfInit(&emlrtCoverageInstance, 1U, 286U, 122606, 122631, -1, 122780);
  covrtIfInit(&emlrtCoverageInstance, 1U, 287U, 123167, 123201, -1, 123352);
  covrtIfInit(&emlrtCoverageInstance, 1U, 288U, 123222, 123247, -1, 123332);
  covrtIfInit(&emlrtCoverageInstance, 1U, 289U, 123418, 123458, 123781, 123825);
  covrtIfInit(&emlrtCoverageInstance, 1U, 290U, 123475, 123500, -1, 123559);
  covrtIfInit(&emlrtCoverageInstance, 1U, 291U, 123781, 123825, 124151, 126836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 292U, 123842, 123867, -1, 123925);
  covrtIfInit(&emlrtCoverageInstance, 1U, 293U, 124151, 124195, 124740, 126836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 294U, 124212, 124237, -1, 124514);
  covrtIfInit(&emlrtCoverageInstance, 1U, 295U, 124258, 124308, 124372, 124426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 296U, 124372, 124426, -1, 124426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 297U, 124740, 124784, 125323, 126836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 298U, 124801, 124826, -1, 125101);
  covrtIfInit(&emlrtCoverageInstance, 1U, 299U, 124847, 124897, 124960, 125014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 300U, 124960, 125014, -1, 125014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 301U, 125323, 125368, 125709, 126836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 302U, 125385, 125410, -1, 125470);
  covrtIfInit(&emlrtCoverageInstance, 1U, 303U, 125709, 125754, 126083, 126836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 304U, 125771, 125796, -1, 125855);
  covrtIfInit(&emlrtCoverageInstance, 1U, 305U, 126083, 126128, 126460, 126836);
  covrtIfInit(&emlrtCoverageInstance, 1U, 306U, 126147, 126172, -1, 126232);
  covrtIfInit(&emlrtCoverageInstance, 1U, 307U, 126460, 126505, -1, 126505);
  covrtIfInit(&emlrtCoverageInstance, 1U, 308U, 126522, 126547, -1, 126606);
  covrtIfInit(&emlrtCoverageInstance, 1U, 309U, 126970, 127054, -1, 127101);
  covrtIfInit(&emlrtCoverageInstance, 1U, 310U, 127370, 127387, -1, 127418);
  covrtIfInit(&emlrtCoverageInstance, 1U, 311U, 127966, 128012, 129376, 130470);
  covrtIfInit(&emlrtCoverageInstance, 1U, 312U, 128065, 128091, 128715, 128745);
  covrtIfInit(&emlrtCoverageInstance, 1U, 313U, 128112, 128138, 128221, 128251);
  covrtIfInit(&emlrtCoverageInstance, 1U, 314U, 128221, 128251, 128334, 128657);
  covrtIfInit(&emlrtCoverageInstance, 1U, 315U, 128334, 128364, -1, 128364);
  covrtIfInit(&emlrtCoverageInstance, 1U, 316U, 128389, 128415, 128507, 128537);
  covrtIfInit(&emlrtCoverageInstance, 1U, 317U, 128507, 128537, -1, 128537);
  covrtIfInit(&emlrtCoverageInstance, 1U, 318U, 128715, 128745, -1, 128745);
  covrtIfInit(&emlrtCoverageInstance, 1U, 319U, 128766, 128792, 128875, 128905);
  covrtIfInit(&emlrtCoverageInstance, 1U, 320U, 128875, 128905, 128988, 129311);
  covrtIfInit(&emlrtCoverageInstance, 1U, 321U, 128988, 129018, -1, 129018);
  covrtIfInit(&emlrtCoverageInstance, 1U, 322U, 129043, 129069, 129161, 129191);
  covrtIfInit(&emlrtCoverageInstance, 1U, 323U, 129161, 129191, -1, 129191);
  covrtIfInit(&emlrtCoverageInstance, 1U, 324U, 129376, 129426, 130326, 130470);
  covrtIfInit(&emlrtCoverageInstance, 1U, 325U, 129467, 129493, 129568, 129598);
  covrtIfInit(&emlrtCoverageInstance, 1U, 326U, 129568, 129598, 129890, 130296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 327U, 129619, 129645, 129728, 129758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 328U, 129728, 129758, -1, 129758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 329U, 129890, 129920, 129999, 130296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 330U, 129999, 130029, -1, 130029);
  covrtIfInit(&emlrtCoverageInstance, 1U, 331U, 130050, 130076, 130159, 130189);
  covrtIfInit(&emlrtCoverageInstance, 1U, 332U, 130159, 130189, -1, 130189);
  covrtIfInit(&emlrtCoverageInstance, 1U, 333U, 130347, 130372, -1, 130449);
  covrtIfInit(&emlrtCoverageInstance, 1U, 334U, 130906, 130983, 132115, 140885);
  covrtIfInit(&emlrtCoverageInstance, 1U, 335U, 131042, 131079, 131556, 132106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 336U, 131096, 131167, 131341, 131543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 337U, 131604, 131675, 131887, 132090);
  covrtIfInit(&emlrtCoverageInstance, 1U, 338U, 132355, 132394, 136477, 140855);
  covrtIfInit(&emlrtCoverageInstance, 1U, 339U, 132419, 132449, 133040, 133079);
  covrtIfInit(&emlrtCoverageInstance, 1U, 340U, 132478, 132538, -1, 133015);
  covrtIfInit(&emlrtCoverageInstance, 1U, 341U, 133040, 133079, 133676, 136422);
  covrtIfInit(&emlrtCoverageInstance, 1U, 342U, 133108, 133168, -1, 133651);
  covrtIfInit(&emlrtCoverageInstance, 1U, 343U, 133676, 133709, 133765, 136422);
  covrtIfInit(&emlrtCoverageInstance, 1U, 344U, 133765, 133804, 134407, 136422);
  covrtIfInit(&emlrtCoverageInstance, 1U, 345U, 133833, 133895, -1, 134382);
  covrtIfInit(&emlrtCoverageInstance, 1U, 346U, 134407, 134441, 135032, 136422);
  covrtIfInit(&emlrtCoverageInstance, 1U, 347U, 134470, 134530, -1, 135007);
  covrtIfInit(&emlrtCoverageInstance, 1U, 348U, 135032, 135071, 135668, 136422);
  covrtIfInit(&emlrtCoverageInstance, 1U, 349U, 135100, 135160, -1, 135643);
  covrtIfInit(&emlrtCoverageInstance, 1U, 350U, 135668, 135701, 135757, 136422);
  covrtIfInit(&emlrtCoverageInstance, 1U, 351U, 135757, 135796, -1, 135796);
  covrtIfInit(&emlrtCoverageInstance, 1U, 352U, 135833, 135891, -1, 136370);
  covrtIfInit(&emlrtCoverageInstance, 1U, 353U, 136506, 136536, 136588, 136627);
  covrtIfInit(&emlrtCoverageInstance, 1U, 354U, 136588, 136627, 137224, 140834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 355U, 136656, 136716, -1, 137199);
  covrtIfInit(&emlrtCoverageInstance, 1U, 356U, 137224, 137257, 137847, 140834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 357U, 137286, 137346, -1, 137822);
  covrtIfInit(&emlrtCoverageInstance, 1U, 358U, 137847, 137886, 138477, 140834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 359U, 137915, 137973, -1, 138452);
  covrtIfInit(&emlrtCoverageInstance, 1U, 360U, 138477, 138511, 138567, 140834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 361U, 138567, 138606, 139324, 140834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 362U, 138635, 138659, -1, 139299);
  covrtIfInit(&emlrtCoverageInstance, 1U, 363U, 138692, 138752, -1, 139267);
  covrtIfInit(&emlrtCoverageInstance, 1U, 364U, 139324, 139357, 140068, 140834);
  covrtIfInit(&emlrtCoverageInstance, 1U, 365U, 139386, 139410, -1, 140043);
  covrtIfInit(&emlrtCoverageInstance, 1U, 366U, 139443, 139503, -1, 140011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 367U, 140068, 140107, -1, 140107);
  covrtIfInit(&emlrtCoverageInstance, 1U, 368U, 140136, 140160, -1, 140806);
  covrtIfInit(&emlrtCoverageInstance, 1U, 369U, 140193, 140255, -1, 140774);
  covrtIfInit(&emlrtCoverageInstance, 1U, 370U, 141155, 141205, 143200, 148189);
  covrtIfInit(&emlrtCoverageInstance, 1U, 371U, 141218, 141260, 141668, 143170);
  covrtIfInit(&emlrtCoverageInstance, 1U, 372U, 141534, 141559, -1, 141655);
  covrtIfInit(&emlrtCoverageInstance, 1U, 373U, 141668, 141713, 142119, 143170);
  covrtIfInit(&emlrtCoverageInstance, 1U, 374U, 141986, 142011, -1, 142106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 375U, 142119, 142165, 142573, 143170);
  covrtIfInit(&emlrtCoverageInstance, 1U, 376U, 142439, 142464, -1, 142560);
  covrtIfInit(&emlrtCoverageInstance, 1U, 377U, 142573, 142618, 143029, 143170);
  covrtIfInit(&emlrtCoverageInstance, 1U, 378U, 142891, 142916, -1, 143016);
  covrtIfInit(&emlrtCoverageInstance, 1U, 379U, 143050, 143075, -1, 143154);
  covrtIfInit(&emlrtCoverageInstance, 1U, 380U, 143200, 143254, 148067, 148189);
  covrtIfInit(&emlrtCoverageInstance, 1U, 381U, 143507, 143554, 144642, 144693);
  covrtIfInit(&emlrtCoverageInstance, 1U, 382U, 143571, 143613, 143958, 144483);
  covrtIfInit(&emlrtCoverageInstance, 1U, 383U, 143958, 144004, 144328, 144483);
  covrtIfInit(&emlrtCoverageInstance, 1U, 384U, 144354, 144379, -1, 144463);
  covrtIfInit(&emlrtCoverageInstance, 1U, 385U, 144501, 144526, -1, 144629);
  covrtIfInit(&emlrtCoverageInstance, 1U, 386U, 144642, 144693, 145778, 148058);
  covrtIfInit(&emlrtCoverageInstance, 1U, 387U, 144710, 144752, 145091, 145622);
  covrtIfInit(&emlrtCoverageInstance, 1U, 388U, 145091, 145137, 145467, 145622);
  covrtIfInit(&emlrtCoverageInstance, 1U, 389U, 145493, 145518, -1, 145602);
  covrtIfInit(&emlrtCoverageInstance, 1U, 390U, 145639, 145664, -1, 145765);
  covrtIfInit(&emlrtCoverageInstance, 1U, 391U, 145778, 145829, 146917, 148058);
  covrtIfInit(&emlrtCoverageInstance, 1U, 392U, 145846, 145888, 146233, 146758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 393U, 146233, 146279, 146603, 146758);
  covrtIfInit(&emlrtCoverageInstance, 1U, 394U, 146629, 146654, -1, 146738);
  covrtIfInit(&emlrtCoverageInstance, 1U, 395U, 146776, 146801, -1, 146904);
  covrtIfInit(&emlrtCoverageInstance, 1U, 396U, 146917, 146968, -1, 146968);
  covrtIfInit(&emlrtCoverageInstance, 1U, 397U, 146985, 147027, 147378, 147899);
  covrtIfInit(&emlrtCoverageInstance, 1U, 398U, 147378, 147424, 147742, 147899);
  covrtIfInit(&emlrtCoverageInstance, 1U, 399U, 147768, 147793, -1, 147879);
  covrtIfInit(&emlrtCoverageInstance, 1U, 400U, 147917, 147942, -1, 148042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 401U, 148085, 148110, -1, 148177);
  covrtIfInit(&emlrtCoverageInstance, 1U, 402U, 148476, 148526, 149989, 151629);
  covrtIfInit(&emlrtCoverageInstance, 1U, 403U, 148539, 148581, 148862, 149980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 404U, 148862, 148907, 149186, 149980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 405U, 149186, 149232, 149511, 149980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 406U, 149511, 149556, 149820, 149980);
  covrtIfInit(&emlrtCoverageInstance, 1U, 407U, 149842, 149867, -1, 149964);
  covrtIfInit(&emlrtCoverageInstance, 1U, 408U, 149989, 150043, 151506, 151629);
  covrtIfInit(&emlrtCoverageInstance, 1U, 409U, 150056, 150103, 150377, 151497);
  covrtIfInit(&emlrtCoverageInstance, 1U, 410U, 150377, 150428, 150701, 151497);
  covrtIfInit(&emlrtCoverageInstance, 1U, 411U, 150701, 150752, 151026, 151497);
  covrtIfInit(&emlrtCoverageInstance, 1U, 412U, 151026, 151077, 151337, 151497);
  covrtIfInit(&emlrtCoverageInstance, 1U, 413U, 151359, 151384, -1, 151481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 414U, 151524, 151549, -1, 151617);
  covrtIfInit(&emlrtCoverageInstance, 1U, 415U, 151861, 151911, 153373, 155014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 416U, 151924, 151966, 152245, 153364);
  covrtIfInit(&emlrtCoverageInstance, 1U, 417U, 152245, 152290, 152571, 153364);
  covrtIfInit(&emlrtCoverageInstance, 1U, 418U, 152571, 152617, 152898, 153364);
  covrtIfInit(&emlrtCoverageInstance, 1U, 419U, 152898, 152943, 153205, 153364);
  covrtIfInit(&emlrtCoverageInstance, 1U, 420U, 153227, 153252, -1, 153348);
  covrtIfInit(&emlrtCoverageInstance, 1U, 421U, 153373, 153427, 154891, 155014);
  covrtIfInit(&emlrtCoverageInstance, 1U, 422U, 153440, 153487, 153762, 154882);
  covrtIfInit(&emlrtCoverageInstance, 1U, 423U, 153762, 153813, 154089, 154882);
  covrtIfInit(&emlrtCoverageInstance, 1U, 424U, 154089, 154140, 154415, 154882);
  covrtIfInit(&emlrtCoverageInstance, 1U, 425U, 154415, 154466, 154721, 154882);
  covrtIfInit(&emlrtCoverageInstance, 1U, 426U, 154743, 154768, -1, 154866);
  covrtIfInit(&emlrtCoverageInstance, 1U, 427U, 154909, 154934, -1, 155002);
  covrtIfInit(&emlrtCoverageInstance, 1U, 428U, 155245, 155295, 156754, 158409);
  covrtIfInit(&emlrtCoverageInstance, 1U, 429U, 155308, 155350, 155625, 156718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 430U, 155625, 155670, 155944, 156718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 431U, 155944, 155990, 156263, 156718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 432U, 156263, 156308, 156567, 156718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 433U, 156589, 156614, -1, 156702);
  covrtIfInit(&emlrtCoverageInstance, 1U, 434U, 156754, 156808, 158286, 158409);
  covrtIfInit(&emlrtCoverageInstance, 1U, 435U, 156821, 156868, 157148, 158277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 436U, 157148, 157199, 157479, 158277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 437U, 157479, 157530, 157810, 158277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 438U, 157810, 157861, 158124, 158277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 439U, 158146, 158171, -1, 158261);
  covrtIfInit(&emlrtCoverageInstance, 1U, 440U, 158304, 158329, -1, 158397);
  covrtIfInit(&emlrtCoverageInstance, 1U, 441U, 158639, 158689, 160148, 161801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 442U, 158702, 158744, 159017, 160112);
  covrtIfInit(&emlrtCoverageInstance, 1U, 443U, 159017, 159062, 159338, 160112);
  covrtIfInit(&emlrtCoverageInstance, 1U, 444U, 159338, 159384, 159659, 160112);
  covrtIfInit(&emlrtCoverageInstance, 1U, 445U, 159659, 159704, 159961, 160112);
  covrtIfInit(&emlrtCoverageInstance, 1U, 446U, 159983, 160008, -1, 160096);
  covrtIfInit(&emlrtCoverageInstance, 1U, 447U, 160148, 160202, 161679, 161801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 448U, 160215, 160262, 160542, 161670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 449U, 160542, 160593, 160873, 161670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 450U, 160873, 160924, 161204, 161670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 451U, 161204, 161255, 161518, 161670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 452U, 161540, 161565, -1, 161654);
  covrtIfInit(&emlrtCoverageInstance, 1U, 453U, 161697, 161722, -1, 161789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 454U, 162033, 162083, 163563, 165204);
  covrtIfInit(&emlrtCoverageInstance, 1U, 455U, 162096, 162138, 162419, 163532);
  covrtIfInit(&emlrtCoverageInstance, 1U, 456U, 162419, 162464, 162745, 163532);
  covrtIfInit(&emlrtCoverageInstance, 1U, 457U, 162745, 162791, 163072, 163532);
  covrtIfInit(&emlrtCoverageInstance, 1U, 458U, 163072, 163117, 163381, 163532);
  covrtIfInit(&emlrtCoverageInstance, 1U, 459U, 163403, 163428, -1, 163516);
  covrtIfInit(&emlrtCoverageInstance, 1U, 460U, 163563, 163617, 165082, 165204);
  covrtIfInit(&emlrtCoverageInstance, 1U, 461U, 163630, 163677, 163952, 165073);
  covrtIfInit(&emlrtCoverageInstance, 1U, 462U, 163952, 164003, 164277, 165073);
  covrtIfInit(&emlrtCoverageInstance, 1U, 463U, 164277, 164328, 164603, 165073);
  covrtIfInit(&emlrtCoverageInstance, 1U, 464U, 164603, 164654, 164911, 165073);
  covrtIfInit(&emlrtCoverageInstance, 1U, 465U, 164933, 164958, -1, 165057);
  covrtIfInit(&emlrtCoverageInstance, 1U, 466U, 165100, 165125, -1, 165192);
  covrtIfInit(&emlrtCoverageInstance, 1U, 467U, 165436, 165486, 166963, 168602);
  covrtIfInit(&emlrtCoverageInstance, 1U, 468U, 165499, 165541, 165822, 166935);
  covrtIfInit(&emlrtCoverageInstance, 1U, 469U, 165822, 165867, 166148, 166935);
  covrtIfInit(&emlrtCoverageInstance, 1U, 470U, 166148, 166194, 166475, 166935);
  covrtIfInit(&emlrtCoverageInstance, 1U, 471U, 166475, 166520, 166784, 166935);
  covrtIfInit(&emlrtCoverageInstance, 1U, 472U, 166806, 166831, -1, 166919);
  covrtIfInit(&emlrtCoverageInstance, 1U, 473U, 166963, 167017, 168480, 168602);
  covrtIfInit(&emlrtCoverageInstance, 1U, 474U, 167030, 167077, 167351, 168471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 475U, 167351, 167402, 167677, 168471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 476U, 167677, 167728, 168002, 168471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 477U, 168002, 168053, 168311, 168471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 478U, 168333, 168358, -1, 168455);
  covrtIfInit(&emlrtCoverageInstance, 1U, 479U, 168498, 168523, -1, 168590);
  covrtIfInit(&emlrtCoverageInstance, 1U, 480U, 168834, 168884, 170343, 170658);
  covrtIfInit(&emlrtCoverageInstance, 1U, 481U, 168897, 168939, 169215, 170312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 482U, 169215, 169260, 169535, 170312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 483U, 169535, 169581, 169857, 170312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 484U, 169857, 169902, 170160, 170312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 485U, 170182, 170207, -1, 170296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 486U, 170343, 170397, 170535, 170658);
  covrtIfInit(&emlrtCoverageInstance, 1U, 487U, 170411, 170436, -1, 170526);
  covrtIfInit(&emlrtCoverageInstance, 1U, 488U, 170553, 170578, -1, 170646);
  covrtIfInit(&emlrtCoverageInstance, 1U, 489U, 170890, 170940, 172397, 172716);
  covrtIfInit(&emlrtCoverageInstance, 1U, 490U, 170953, 170995, 171271, 172369);
  covrtIfInit(&emlrtCoverageInstance, 1U, 491U, 171271, 171316, 171591, 172369);
  covrtIfInit(&emlrtCoverageInstance, 1U, 492U, 171591, 171637, 171913, 172369);
  covrtIfInit(&emlrtCoverageInstance, 1U, 493U, 171913, 171958, 172216, 172369);
  covrtIfInit(&emlrtCoverageInstance, 1U, 494U, 172238, 172263, -1, 172353);
  covrtIfInit(&emlrtCoverageInstance, 1U, 495U, 172397, 172451, 172590, 172716);
  covrtIfInit(&emlrtCoverageInstance, 1U, 496U, 172465, 172490, -1, 172581);
  covrtIfInit(&emlrtCoverageInstance, 1U, 497U, 172608, 172633, -1, 172704);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 5156, 5179, 1, 0,
                cond_starts_1_0, cond_ends_1_0, 2, postfix_exprs_1_0);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 9635, 9672, 2, 1,
                cond_starts_1_1, cond_ends_1_1, 3, postfix_exprs_1_1);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 10517, 10593, 2, 3,
                cond_starts_1_2, cond_ends_1_2, 3, postfix_exprs_1_2);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 3U, 10826, 10849, 1, 5,
                cond_starts_1_3, cond_ends_1_3, 2, postfix_exprs_1_3);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 4U, 11531, 11554, 1, 6,
                cond_starts_1_4, cond_ends_1_4, 2, postfix_exprs_1_4);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 5U, 12014, 12037, 1, 7,
                cond_starts_1_5, cond_ends_1_5, 2, postfix_exprs_1_5);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 6U, 12540, 12563, 1, 8,
                cond_starts_1_6, cond_ends_1_6, 2, postfix_exprs_1_6);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 7U, 13067, 13090, 1, 9,
                cond_starts_1_7, cond_ends_1_7, 2, postfix_exprs_1_7);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 8U, 21695, 21950, 2, 10,
                cond_starts_1_8, cond_ends_1_8, 3, postfix_exprs_1_8);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 9U, 22002, 22229, 2, 12,
                cond_starts_1_9, cond_ends_1_9, 3, postfix_exprs_1_9);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 10U, 22939, 23169, 2, 14,
                cond_starts_1_10, cond_ends_1_10, 3, postfix_exprs_1_10);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 11U, 23870, 24125, 2, 16,
                cond_starts_1_11, cond_ends_1_11, 3, postfix_exprs_1_11);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 12U, 24176, 24399, 2, 18,
                cond_starts_1_12, cond_ends_1_12, 3, postfix_exprs_1_12);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 13U, 25094, 25320, 2, 20,
                cond_starts_1_13, cond_ends_1_13, 3, postfix_exprs_1_13);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 14U, 26008, 26259, 2, 22,
                cond_starts_1_14, cond_ends_1_14, 3, postfix_exprs_1_14);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 15U, 26310, 26533, 2, 24,
                cond_starts_1_15, cond_ends_1_15, 3, postfix_exprs_1_15);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 16U, 27228, 27454, 2, 26,
                cond_starts_1_16, cond_ends_1_16, 3, postfix_exprs_1_16);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 17U, 28149, 28400, 2, 28,
                cond_starts_1_17, cond_ends_1_17, 3, postfix_exprs_1_17);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 18U, 28451, 28674, 2, 30,
                cond_starts_1_18, cond_ends_1_18, 3, postfix_exprs_1_18);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 19U, 29377, 29603, 2, 32,
                cond_starts_1_19, cond_ends_1_19, 3, postfix_exprs_1_19);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 20U, 36453, 36523, 2, 34,
                cond_starts_1_20, cond_ends_1_20, 3, postfix_exprs_1_20);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 21U, 41892, 42137, 2, 36,
                cond_starts_1_21, cond_ends_1_21, 3, postfix_exprs_1_21);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 22U, 44215, 44458, 2, 38,
                cond_starts_1_22, cond_ends_1_22, 3, postfix_exprs_1_22);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 23U, 46512, 46757, 2, 40,
                cond_starts_1_23, cond_ends_1_23, 3, postfix_exprs_1_23);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 24U, 48834, 49077, 2, 42,
                cond_starts_1_24, cond_ends_1_24, 3, postfix_exprs_1_24);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 25U, 52220, 52312, 1, 44,
                cond_starts_1_25, cond_ends_1_25, 2, postfix_exprs_1_25);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 26U, 52762, 52853, 1, 45,
                cond_starts_1_26, cond_ends_1_26, 2, postfix_exprs_1_26);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 27U, 53302, 53394, 1, 46,
                cond_starts_1_27, cond_ends_1_27, 2, postfix_exprs_1_27);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 28U, 53836, 53927, 1, 47,
                cond_starts_1_28, cond_ends_1_28, 2, postfix_exprs_1_28);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 29U, 54537, 54623, 1, 48,
                cond_starts_1_29, cond_ends_1_29, 2, postfix_exprs_1_29);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 30U, 54852, 54937, 1, 49,
                cond_starts_1_30, cond_ends_1_30, 2, postfix_exprs_1_30);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 31U, 55167, 55253, 1, 50,
                cond_starts_1_31, cond_ends_1_31, 2, postfix_exprs_1_31);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 32U, 55479, 55564, 1, 51,
                cond_starts_1_32, cond_ends_1_32, 2, postfix_exprs_1_32);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 33U, 56557, 56782, 2, 52,
                cond_starts_1_33, cond_ends_1_33, 3, postfix_exprs_1_33);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 34U, 59180, 59403, 2, 54,
                cond_starts_1_34, cond_ends_1_34, 3, postfix_exprs_1_34);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 35U, 61831, 62058, 2, 56,
                cond_starts_1_35, cond_ends_1_35, 3, postfix_exprs_1_35);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 36U, 64491, 64720, 2, 58,
                cond_starts_1_36, cond_ends_1_36, 3, postfix_exprs_1_36);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 37U, 67094, 67321, 2, 60,
                cond_starts_1_37, cond_ends_1_37, 3, postfix_exprs_1_37);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 38U, 69726, 69949, 2, 62,
                cond_starts_1_38, cond_ends_1_38, 3, postfix_exprs_1_38);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 39U, 72864, 73089, 2, 64,
                cond_starts_1_39, cond_ends_1_39, 3, postfix_exprs_1_39);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 40U, 75493, 75716, 2, 66,
                cond_starts_1_40, cond_ends_1_40, 3, postfix_exprs_1_40);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 41U, 78086, 78311, 2, 68,
                cond_starts_1_41, cond_ends_1_41, 3, postfix_exprs_1_41);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 42U, 80744, 80973, 2, 70,
                cond_starts_1_42, cond_ends_1_42, 3, postfix_exprs_1_42);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 43U, 83393, 83620, 2, 72,
                cond_starts_1_43, cond_ends_1_43, 3, postfix_exprs_1_43);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 44U, 85989, 86218, 2, 74,
                cond_starts_1_44, cond_ends_1_44, 3, postfix_exprs_1_44);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 45U, 89530, 89683, 3, 76,
                cond_starts_1_45, cond_ends_1_45, 5, postfix_exprs_1_45);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 46U, 89816, 89955, 2, 79,
                cond_starts_1_46, cond_ends_1_46, 3, postfix_exprs_1_46);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 47U, 90083, 90224, 2, 81,
                cond_starts_1_47, cond_ends_1_47, 3, postfix_exprs_1_47);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 48U, 90352, 90491, 2, 83,
                cond_starts_1_48, cond_ends_1_48, 3, postfix_exprs_1_48);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 49U, 90619, 90756, 2, 85,
                cond_starts_1_49, cond_ends_1_49, 3, postfix_exprs_1_49);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 50U, 91079, 91232, 3, 87,
                cond_starts_1_50, cond_ends_1_50, 5, postfix_exprs_1_50);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 51U, 91365, 91504, 2, 90,
                cond_starts_1_51, cond_ends_1_51, 3, postfix_exprs_1_51);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 52U, 91631, 91768, 2, 92,
                cond_starts_1_52, cond_ends_1_52, 3, postfix_exprs_1_52);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 53U, 91895, 92034, 2, 94,
                cond_starts_1_53, cond_ends_1_53, 3, postfix_exprs_1_53);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 54U, 92161, 92302, 2, 96,
                cond_starts_1_54, cond_ends_1_54, 3, postfix_exprs_1_54);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 55U, 115922, 116129, 5, 98,
                cond_starts_1_55, cond_ends_1_55, 9, postfix_exprs_1_55);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 56U, 116198, 116271, 2, 103,
                cond_starts_1_56, cond_ends_1_56, 3, postfix_exprs_1_56);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 57U, 123170, 123201, 2, 105,
                cond_starts_1_57, cond_ends_1_57, 3, postfix_exprs_1_57);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 58U, 126973, 127054, 2, 107,
                cond_starts_1_58, cond_ends_1_58, 3, postfix_exprs_1_58);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 59U, 130909, 130983, 2, 109,
                cond_starts_1_59, cond_ends_1_59, 3, postfix_exprs_1_59);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 60U, 131099, 131167, 2, 111,
                cond_starts_1_60, cond_ends_1_60, 3, postfix_exprs_1_60);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 61U, 131607, 131675, 2, 113,
                cond_starts_1_61, cond_ends_1_61, 3, postfix_exprs_1_61);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 3672, 3692, 3952);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 6842, 6855, 7010);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 6867, 6880, 6998);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 10474, 10498, 10671);
  covrtForInit(&emlrtCoverageInstance, 1U, 4U, 30707, 30734, 30811);
  covrtForInit(&emlrtCoverageInstance, 1U, 5U, 30880, 30909, 33431);
  covrtForInit(&emlrtCoverageInstance, 1U, 6U, 31542, 31567, 33415);
  covrtForInit(&emlrtCoverageInstance, 1U, 7U, 36408, 36434, 36602);
  covrtForInit(&emlrtCoverageInstance, 1U, 8U, 40566, 40592, 41081);
  covrtForInit(&emlrtCoverageInstance, 1U, 9U, 41217, 41246, 51039);
  covrtForInit(&emlrtCoverageInstance, 1U, 10U, 41740, 41765, 51023);
  covrtForInit(&emlrtCoverageInstance, 1U, 11U, 54485, 54505, 55769);
  covrtForInit(&emlrtCoverageInstance, 1U, 12U, 55960, 55985, 88603);
  covrtForInit(&emlrtCoverageInstance, 1U, 13U, 56462, 56483, 72266);
  covrtForInit(&emlrtCoverageInstance, 1U, 14U, 72729, 72750, 88591);
  covrtForInit(&emlrtCoverageInstance, 1U, 15U, 89397, 89419, 92560);
  covrtForInit(&emlrtCoverageInstance, 1U, 16U, 93224, 93236, 102092);
  covrtForInit(&emlrtCoverageInstance, 1U, 17U, 122080, 122094, 123368);
  covrtForInit(&emlrtCoverageInstance, 1U, 18U, 132245, 132257, 140872);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 1U, 0U, 3624, 3632, 4369);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 1U, 4423, 4431, 5880);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 2U, 9554, 9562, 13821);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 3U, 30818, 30826, 33534);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 4U, 36362, 36370, 39903);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 5U, 41155, 41163, 51126);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 6U, 55899, 55907, 88780);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 7U, 89342, 89350, 102210);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 8U, 115420, 115428, 127731);

  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 11303, 11346, 13354, 5U,
                  caseStarts_1_0, caseExprEnds_1_0);
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 1U, 38232, 38275, 39159, 5U,
                  caseStarts_1_1, caseExprEnds_1_1);

  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\work\\matlab\\maze_sim_git\\src\\goal_plot.m", 2U, 1U, 0U,
                  0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "goal_plot", 0, -1, 191);

  /* Initialize Basic Block Information */
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 46, 66, 185);

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
