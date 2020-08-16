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
  const int32_T cond_starts_1_0[1] = { 3155 };

  const int32_T cond_ends_1_0[1] = { 3177 };

  const int32_T postfix_exprs_1_0[2] = { 0, -1 };

  const int32_T cond_starts_1_1[1] = { 5355 };

  const int32_T cond_ends_1_1[1] = { 5377 };

  const int32_T postfix_exprs_1_1[2] = { 0, -1 };

  const int32_T cond_starts_1_2[2] = { 10645, 10685 };

  const int32_T cond_ends_1_2[2] = { 10679, 10719 };

  const int32_T postfix_exprs_1_2[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_3[1] = { 10954 };

  const int32_T cond_ends_1_3[1] = { 10976 };

  const int32_T postfix_exprs_1_3[2] = { 0, -1 };

  const int32_T cond_starts_1_4[1] = { 11659 };

  const int32_T cond_ends_1_4[1] = { 11681 };

  const int32_T postfix_exprs_1_4[2] = { 0, -1 };

  const int32_T cond_starts_1_5[1] = { 12233 };

  const int32_T cond_ends_1_5[1] = { 12255 };

  const int32_T postfix_exprs_1_5[2] = { 0, -1 };

  const int32_T cond_starts_1_6[1] = { 12819 };

  const int32_T cond_ends_1_6[1] = { 12841 };

  const int32_T postfix_exprs_1_6[2] = { 0, -1 };

  const int32_T cond_starts_1_7[1] = { 13373 };

  const int32_T cond_ends_1_7[1] = { 13395 };

  const int32_T postfix_exprs_1_7[2] = { 0, -1 };

  const int32_T cond_starts_1_8[2] = { 22071, 22211 };

  const int32_T cond_ends_1_8[2] = { 22186, 22324 };

  const int32_T postfix_exprs_1_8[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_9[2] = { 22377, 22488 };

  const int32_T cond_ends_1_9[2] = { 22460, 22603 };

  const int32_T postfix_exprs_1_9[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_10[2] = { 23314, 23426 };

  const int32_T cond_ends_1_10[2] = { 23398, 23543 };

  const int32_T postfix_exprs_1_10[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_11[2] = { 24246, 24386 };

  const int32_T cond_ends_1_11[2] = { 24361, 24499 };

  const int32_T postfix_exprs_1_11[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_12[2] = { 24551, 24658 };

  const int32_T cond_ends_1_12[2] = { 24634, 24773 };

  const int32_T postfix_exprs_1_12[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_13[2] = { 25469, 25577 };

  const int32_T cond_ends_1_13[2] = { 25553, 25694 };

  const int32_T postfix_exprs_1_13[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_14[2] = { 26384, 26518 };

  const int32_T cond_ends_1_14[2] = { 26497, 26633 };

  const int32_T postfix_exprs_1_14[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_15[2] = { 26685, 26792 };

  const int32_T cond_ends_1_15[2] = { 26768, 26907 };

  const int32_T postfix_exprs_1_15[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_16[2] = { 27603, 27711 };

  const int32_T cond_ends_1_16[2] = { 27687, 27828 };

  const int32_T postfix_exprs_1_16[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_17[2] = { 28525, 28659 };

  const int32_T cond_ends_1_17[2] = { 28638, 28774 };

  const int32_T postfix_exprs_1_17[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_18[2] = { 28826, 28933 };

  const int32_T cond_ends_1_18[2] = { 28909, 29048 };

  const int32_T postfix_exprs_1_18[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_19[2] = { 29752, 29860 };

  const int32_T cond_ends_1_19[2] = { 29836, 29977 };

  const int32_T postfix_exprs_1_19[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_20[2] = { 36829, 36866 };

  const int32_T cond_ends_1_20[2] = { 36860, 36897 };

  const int32_T postfix_exprs_1_20[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_21[2] = { 42267, 42403 };

  const int32_T cond_ends_1_21[2] = { 42368, 42512 };

  const int32_T postfix_exprs_1_21[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_22[2] = { 44590, 44725 };

  const int32_T cond_ends_1_22[2] = { 44690, 44833 };

  const int32_T postfix_exprs_1_22[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_23[2] = { 46887, 47023 };

  const int32_T cond_ends_1_23[2] = { 46988, 47132 };

  const int32_T postfix_exprs_1_23[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_24[2] = { 49209, 49344 };

  const int32_T cond_ends_1_24[2] = { 49309, 49452 };

  const int32_T postfix_exprs_1_24[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_25[1] = { 52596 };

  const int32_T cond_ends_1_25[1] = { 52687 };

  const int32_T postfix_exprs_1_25[2] = { 0, -1 };

  const int32_T cond_starts_1_26[1] = { 53138 };

  const int32_T cond_ends_1_26[1] = { 53228 };

  const int32_T postfix_exprs_1_26[2] = { 0, -1 };

  const int32_T cond_starts_1_27[1] = { 53678 };

  const int32_T cond_ends_1_27[1] = { 53769 };

  const int32_T postfix_exprs_1_27[2] = { 0, -1 };

  const int32_T cond_starts_1_28[1] = { 54212 };

  const int32_T cond_ends_1_28[1] = { 54302 };

  const int32_T postfix_exprs_1_28[2] = { 0, -1 };

  const int32_T cond_starts_1_29[1] = { 54913 };

  const int32_T cond_ends_1_29[1] = { 54998 };

  const int32_T postfix_exprs_1_29[2] = { 0, -1 };

  const int32_T cond_starts_1_30[1] = { 55228 };

  const int32_T cond_ends_1_30[1] = { 55312 };

  const int32_T postfix_exprs_1_30[2] = { 0, -1 };

  const int32_T cond_starts_1_31[1] = { 55543 };

  const int32_T cond_ends_1_31[1] = { 55628 };

  const int32_T postfix_exprs_1_31[2] = { 0, -1 };

  const int32_T cond_starts_1_32[1] = { 55855 };

  const int32_T cond_ends_1_32[1] = { 55939 };

  const int32_T postfix_exprs_1_32[2] = { 0, -1 };

  const int32_T cond_starts_1_33[2] = { 56932, 57056 };

  const int32_T cond_ends_1_33[2] = { 57025, 57157 };

  const int32_T postfix_exprs_1_33[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_34[2] = { 59555, 59678 };

  const int32_T cond_ends_1_34[2] = { 59647, 59778 };

  const int32_T postfix_exprs_1_34[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_35[2] = { 62206, 62331 };

  const int32_T cond_ends_1_35[2] = { 62300, 62433 };

  const int32_T postfix_exprs_1_35[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_36[2] = { 64866, 64992 };

  const int32_T cond_ends_1_36[2] = { 64961, 65095 };

  const int32_T postfix_exprs_1_36[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_37[2] = { 67469, 67594 };

  const int32_T cond_ends_1_37[2] = { 67563, 67696 };

  const int32_T postfix_exprs_1_37[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_38[2] = { 70101, 70224 };

  const int32_T cond_ends_1_38[2] = { 70193, 70324 };

  const int32_T postfix_exprs_1_38[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_39[2] = { 73239, 73363 };

  const int32_T cond_ends_1_39[2] = { 73332, 73464 };

  const int32_T postfix_exprs_1_39[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_40[2] = { 75868, 75991 };

  const int32_T cond_ends_1_40[2] = { 75960, 76091 };

  const int32_T postfix_exprs_1_40[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_41[2] = { 78461, 78585 };

  const int32_T cond_ends_1_41[2] = { 78554, 78686 };

  const int32_T postfix_exprs_1_41[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_42[2] = { 81119, 81245 };

  const int32_T cond_ends_1_42[2] = { 81214, 81348 };

  const int32_T postfix_exprs_1_42[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_43[2] = { 83768, 83893 };

  const int32_T cond_ends_1_43[2] = { 83862, 83995 };

  const int32_T postfix_exprs_1_43[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_44[2] = { 86364, 86490 };

  const int32_T cond_ends_1_44[2] = { 86459, 86593 };

  const int32_T postfix_exprs_1_44[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_45[3] = { 89906, 89985, 90022 };

  const int32_T cond_ends_1_45[3] = { 89939, 90018, 90057 };

  const int32_T postfix_exprs_1_45[5] = { 0, 1, 2, -2, -3 };

  const int32_T cond_starts_1_46[2] = { 90191, 90274 };

  const int32_T cond_ends_1_46[2] = { 90235, 90330 };

  const int32_T postfix_exprs_1_46[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_47[2] = { 90458, 90541 };

  const int32_T cond_ends_1_47[2] = { 90502, 90599 };

  const int32_T postfix_exprs_1_47[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_48[2] = { 90727, 90810 };

  const int32_T cond_ends_1_48[2] = { 90771, 90866 };

  const int32_T postfix_exprs_1_48[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_49[2] = { 90994, 91077 };

  const int32_T cond_ends_1_49[2] = { 91038, 91131 };

  const int32_T postfix_exprs_1_49[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_50[3] = { 91455, 91492, 91573 };

  const int32_T cond_ends_1_50[3] = { 91488, 91527, 91606 };

  const int32_T postfix_exprs_1_50[5] = { 0, 1, -2, 2, -3 };

  const int32_T cond_starts_1_51[2] = { 91740, 91823 };

  const int32_T cond_ends_1_51[2] = { 91784, 91879 };

  const int32_T postfix_exprs_1_51[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_52[2] = { 92006, 92089 };

  const int32_T cond_ends_1_52[2] = { 92050, 92143 };

  const int32_T postfix_exprs_1_52[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_53[2] = { 92270, 92353 };

  const int32_T cond_ends_1_53[2] = { 92314, 92409 };

  const int32_T postfix_exprs_1_53[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_54[2] = { 92536, 92619 };

  const int32_T cond_ends_1_54[2] = { 92580, 92677 };

  const int32_T postfix_exprs_1_54[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_55[5] = { 116298, 116331, 116400, 116443, 116475 };

  const int32_T cond_ends_1_55[5] = { 116326, 116370, 116439, 116471, 116503 };

  const int32_T postfix_exprs_1_55[9] = { 0, 1, -3, 2, 3, -3, 4, -3, -2 };

  const int32_T cond_starts_1_56[2] = { 116573, 116606 };

  const int32_T cond_ends_1_56[2] = { 116601, 116645 };

  const int32_T postfix_exprs_1_56[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_57[2] = { 123545, 123570 };

  const int32_T cond_ends_1_57[2] = { 123566, 123576 };

  const int32_T postfix_exprs_1_57[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_58[2] = { 127348, 127385 };

  const int32_T cond_ends_1_58[2] = { 127380, 127428 };

  const int32_T postfix_exprs_1_58[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_59[2] = { 131284, 131320 };

  const int32_T cond_ends_1_59[2] = { 131316, 131358 };

  const int32_T postfix_exprs_1_59[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_60[2] = { 131474, 131510 };

  const int32_T cond_ends_1_60[2] = { 131506, 131542 };

  const int32_T postfix_exprs_1_60[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_61[2] = { 131982, 132018 };

  const int32_T cond_ends_1_61[2] = { 132014, 132050 };

  const int32_T postfix_exprs_1_61[3] = { 0, 1, -3 };

  const int32_T caseStarts_1_0[5] = { 13704, 11489, 11998, 12589, 13137 };

  const int32_T caseExprEnds_1_0[5] = { 13713, 11511, 12020, 12610, 13158 };

  const int32_T caseStarts_1_1[5] = { 39509, 38666, 38829, 39057, 39280 };

  const int32_T caseExprEnds_1_1[5] = { 39518, 38688, 38851, 39078, 39301 };

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
                  389U, 499U, 0U, 0U, 2U, 19U, 9U, 114U, 62U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "maze_solve", 0, -1, 173108);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 1U, "search_adachi", 9183, -1, 14641);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 2U, "move_step", 14667, -1, 15258);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 3U, "turn_180deg", 15291, -1, 15426);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 4U, "turn_clk_90deg", 15467, -1,
               15604);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 5U, "turn_conclk_90deg", 15646, -1,
               15788);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 6U, "wall_set", 15810, -1, 30650);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 7U, "make_map_find", 30688, -1, 33919);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 8U, "get_nextdir2", 33960, -1, 35687);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 9U, "fust_run", 35711, -1, 40282);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 10U, "make_map_fustrun", 40319, -1,
               51507);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 11U, "make_map_fustrun_diagonal",
               51553, -1, 89162);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 12U, "decide_goal_node_dir", 89250,
               -1, 102593);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 13U, "decide_goal_section", 102673,
               -1, 114749);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 14U, "goal_judge", 114430, -1, 114741);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 15U, "make_route_diagonal", 114794,
               -1, 130861);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 16U, "get_turn_pattern_num", 128137,
               -1, 130857);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 17U, "get_next_dir_diagonal", 130906,
               -1, 141268);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 18U, "move_straight", 141288, -1,
               148633);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 19U, "turn_r_45", 148645, -1, 152017);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 20U, "turn_l_45", 152030, -1, 155402);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 21U, "turn_r_90", 155414, -1, 158796);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 22U, "turn_l_90", 158808, -1, 162188);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 23U, "turn_r_135", 162201, -1, 165591);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 24U, "turn_l_135", 165604, -1, 168989);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 25U, "turn_r_180", 169002, -1, 171045);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 26U, "turn_l_180", 171058, -1, 173103);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 20U, 7403, -1, 9141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 19U, 7102, -1, 7187);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 18U, 6878, -1, 6987);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 17U, 6682, -1, 6746);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 16U, 6151, -1, 6594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 14U, 5507, -1, 5512);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 13U, 5394, -1, 5477);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 15U, 5551, -1, 6053);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 12U, 4657, -1, 5235);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 4181, -1, 4501);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 4541, -1, 4546);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 3986, -1, 4103);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 3893, -1, 3944);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 3828, -1, 3850);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 3284, -1, 3773);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 3186, -1, 3270);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 2931, -1, 3124);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 2563, -1, 2855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 2386, -1, 2469);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 692, -1, 2327);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 309, -1, 672);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 28U, 11208, -1, 11213);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 27U, 11001, -1, 11084);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 42U, 13841, -1, 14038);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 41U, 13594, -1, 13685);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 40U, 13420, -1, 13499);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 39U, 13179, -1, 13313);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 38U, 13027, -1, 13118);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 37U, 12866, -1, 12945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 36U, 12631, -1, 12759);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 35U, 12459, -1, 12550);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 34U, 12280, -1, 12360);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 33U, 12041, -1, 12172);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 32U, 11868, -1, 11959);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 31U, 11706, -1, 11786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 30U, 11532, -1, 11598);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 29U, 11312, -1, 11386);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 26U, 10741, -1, 10760);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 25U, 10444, -1, 10547);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 24U, 10197, -1, 10270);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 23U, 10061, -1, 10085);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 22U, 9873, -1, 10000);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 21U, 9578, -1, 9760);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 46U, 15194, -1, 15217);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 45U, 15073, -1, 15096);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 44U, 14952, -1, 14975);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 43U, 14832, -1, 14855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 47U, 15376, -1, 15414);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 48U, 15555, -1, 15593);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 49U, 15736, -1, 15776);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 75U, 30034, -1, 30609);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 74U, 29105, -1, 29684);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 73U, 27885, -1, 28460);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 72U, 26964, -1, 27535);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 71U, 25751, -1, 26318);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 70U, 24829, -1, 25400);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 69U, 23601, -1, 24180);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 68U, 22663, -1, 23246);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 67U, 21841, -1, 21978);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 66U, 21493, -1, 21808);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 65U, 21116, -1, 21435);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 64U, 20739, -1, 21054);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 63U, 20349, -1, 20668);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 62U, 18889, -1, 20266);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 61U, 18717, -1, 18850);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 60U, 18543, -1, 18594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 59U, 18416, -1, 18478);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 58U, 18123, -1, 18189);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 57U, 17947, -1, 18080);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 56U, 17769, -1, 17822);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 55U, 17642, -1, 17704);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 54U, 17381, -1, 17445);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 53U, 17198, -1, 17329);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 52U, 17020, -1, 17073);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 51U, 16895, -1, 16955);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 50U, 16364, -1, 16594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 85U, 33882, -1, 33887);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 80U, 31805, -1, 31810);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 84U, 33615, -1, 33717);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 83U, 33158, -1, 33260);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 82U, 32700, -1, 32802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 81U, 32243, -1, 32345);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 79U, 31396, -1, 31693);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 78U, 31209, -1, 31231);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 77U, 31117, -1, 31177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 76U, 30881, -1, 31059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 90U, 35612, -1, 35639);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 89U, 35218, -1, 35311);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 88U, 34890, -1, 34982);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 87U, 34530, -1, 34656);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 86U, 34131, -1, 34200);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 96U, 37025, -1, 37030);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 106U, 40215, -1, 40269);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 105U, 39637, -1, 39763);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 104U, 39322, -1, 39456);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 103U, 39099, -1, 39227);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 102U, 38872, -1, 39003);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 101U, 38709, -1, 38775);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 100U, 38432, -1, 38524);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 99U, 38096, -1, 38189);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 98U, 37759, -1, 37851);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 97U, 37390, -1, 37516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 95U, 36919, -1, 36939);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 94U, 36432, -1, 36545);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 93U, 36075, -1, 36339);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 92U, 35999, -1, 36045);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 91U, 35845, -1, 35934);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 120U, 51474, -1, 51479);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 119U, 50773, -1, 51293);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 118U, 49870, -1, 50376);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 117U, 48455, -1, 48976);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 116U, 47551, -1, 48058);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 115U, 46154, -1, 46674);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 114U, 45251, -1, 45757);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 113U, 43835, -1, 44356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 112U, 42931, -1, 43438);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 111U, 41755, -1, 42060);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 110U, 41546, -1, 41568);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 109U, 41491, -1, 41523);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 108U, 40975, -1, 41447);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 107U, 40536, -1, 40857);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 183U, 89059, -1, 89130);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 182U, 88761, -1, 88877);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 181U, 88085, -1, 88543);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 180U, 87643, -1, 87759);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 179U, 86967, -1, 87421);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 178U, 86109, -1, 86215);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 177U, 85448, -1, 85894);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 176U, 85020, -1, 85126);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 175U, 84359, -1, 84801);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 174U, 83492, -1, 83604);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 173U, 82824, -1, 83276);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 172U, 82388, -1, 82500);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 171U, 81720, -1, 82168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 170U, 80807, -1, 80915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 169U, 80147, -1, 80593);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 168U, 79716, -1, 79824);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 167U, 79056, -1, 79498);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 166U, 78205, -1, 78311);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 165U, 77544, -1, 77990);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 164U, 77116, -1, 77222);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 163U, 76455, -1, 76897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 162U, 75608, -1, 75720);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 161U, 74940, -1, 75392);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 160U, 74504, -1, 74616);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 159U, 73836, -1, 74284);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 158U, 72770, -1, 73045);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 157U, 72444, -1, 72552);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 156U, 71784, -1, 72230);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 155U, 71354, -1, 71462);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 154U, 70694, -1, 71136);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 153U, 69840, -1, 69952);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 152U, 69172, -1, 69624);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 151U, 68736, -1, 68848);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 150U, 68068, -1, 68516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 149U, 67213, -1, 67320);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 148U, 66551, -1, 66998);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 147U, 66122, -1, 66229);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 146U, 65460, -1, 65903);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 145U, 64602, -1, 64718);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 144U, 63926, -1, 64384);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 143U, 63483, -1, 63599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 142U, 62807, -1, 63261);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 141U, 61922, -1, 62034);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 140U, 61254, -1, 61706);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 139U, 60818, -1, 60930);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 138U, 60150, -1, 60598);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 137U, 59299, -1, 59406);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 136U, 58637, -1, 59084);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 135U, 58184, -1, 58291);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 134U, 57522, -1, 57965);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 133U, 56515, -1, 56790);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 132U, 56290, -1, 56312);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 131U, 56184, -1, 56258);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 130U, 55978, -1, 56114);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 129U, 55667, -1, 55803);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 128U, 55351, -1, 55491);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 127U, 55037, -1, 55177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 126U, 54333, -1, 54697);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 125U, 53800, -1, 54165);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 124U, 53259, -1, 53631);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 123U, 52718, -1, 53091);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 122U, 52501, -1, 52532);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 121U, 51814, -1, 52469);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 196U, 93494, -1, 93499);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 210U, 102481, -1, 102555);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 209U, 101946, -1, 102352);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 208U, 101270, -1, 101665);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 207U, 100595, -1, 100997);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 206U, 99820, -1, 100218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 205U, 99148, -1, 99543);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 204U, 98473, -1, 98875);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 203U, 97584, -1, 97981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 202U, 96801, -1, 97202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 201U, 96126, -1, 96522);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 200U, 95447, -1, 95852);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 199U, 94668, -1, 95069);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 198U, 93993, -1, 94389);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 197U, 93631, -1, 93665);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 195U, 92854, -1, 92874);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 194U, 92706, -1, 92743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 193U, 92438, -1, 92475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 192U, 92172, -1, 92209);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 191U, 91908, -1, 91945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 190U, 91334, -1, 91354);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 189U, 91160, -1, 91198);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 188U, 90895, -1, 90933);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 187U, 90628, -1, 90666);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 186U, 90359, -1, 90397);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 185U, 89738, -1, 89758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 184U, 89408, -1, 89707);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 251U, 114153, -1, 114320);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 250U, 113941, -1, 114110);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 249U, 113673, -1, 113846);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 248U, 113403, -1, 113576);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 247U, 113088, -1, 113253);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 246U, 112876, -1, 113045);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 245U, 112614, -1, 112781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 244U, 112346, -1, 112519);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 243U, 111947, -1, 112114);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 242U, 111735, -1, 111904);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 241U, 111301, -1, 111468);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 240U, 111069, -1, 111238);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 239U, 110802, -1, 110973);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 238U, 110532, -1, 110705);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 237U, 110233, -1, 110400);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 236U, 109999, -1, 110168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 235U, 109729, -1, 109900);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 234U, 109439, -1, 109612);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 233U, 109042, -1, 109209);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 232U, 108830, -1, 108999);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 231U, 108442, -1, 108607);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 230U, 108206, -1, 108375);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 229U, 107920, -1, 108087);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 228U, 107632, -1, 107805);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 227U, 107335, -1, 107502);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 226U, 107123, -1, 107292);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 225U, 106855, -1, 107028);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 224U, 106585, -1, 106758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 223U, 106190, -1, 106355);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 222U, 105978, -1, 106147);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 221U, 105564, -1, 105729);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 220U, 105349, -1, 105518);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 219U, 105082, -1, 105251);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 218U, 104808, -1, 104981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 217U, 104511, -1, 104676);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 216U, 104295, -1, 104464);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 215U, 104029, -1, 104198);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 214U, 103741, -1, 103914);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 213U, 103322, -1, 103487);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 212U, 103110, -1, 103279);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 211U, 102807, -1, 102918);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 252U, 114511, -1, 114715);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 283U, 127775, -1, 127780);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 284U, 127851, -1, 128043);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 282U, 127524, -1, 127688);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 281U, 127446, -1, 127459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 280U, 126998, -1, 127177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 279U, 126624, -1, 126803);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 278U, 126247, -1, 126426);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 277U, 125862, -1, 126041);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 276U, 125493, -1, 125671);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 275U, 124906, -1, 125084);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 274U, 124321, -1, 124499);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 273U, 123951, -1, 124129);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 271U, 123176, -1, 123181);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 270U, 123031, -1, 123130);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 272U, 123257, -1, 123464);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 269U, 122661, -1, 122853);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 268U, 122375, -1, 122403);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 267U, 121981, -1, 122192);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 266U, 121800, -1, 121899);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 265U, 121537, -1, 121550);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 264U, 121113, -1, 121332);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 263U, 120913, -1, 121012);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 262U, 120166, -1, 120356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 261U, 119740, -1, 119930);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 260U, 118987, -1, 119086);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 259U, 118510, -1, 118870);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 258U, 118107, -1, 118330);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 257U, 117893, -1, 117992);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 256U, 117069, -1, 117399);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 255U, 116714, -1, 116920);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 254U, 116043, -1, 116251);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 253U, 114926, -1, 115783);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 299U, 130588, -1, 130625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 298U, 130475, -1, 130511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 297U, 130320, -1, 130356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 296U, 130157, -1, 130194);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 295U, 130044, -1, 130080);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 294U, 129889, -1, 129925);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 293U, 129596, -1, 129633);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 292U, 129473, -1, 129510);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 291U, 129305, -1, 129341);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 290U, 129192, -1, 129228);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 289U, 128942, -1, 128979);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 288U, 128819, -1, 128856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 287U, 128651, -1, 128687);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 286U, 128538, -1, 128574);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 285U, 128270, -1, 128309);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 318U, 140711, -1, 141112);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 317U, 139959, -1, 140349);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 316U, 139208, -1, 139605);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 315U, 138421, -1, 138794);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 314U, 137794, -1, 138164);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 313U, 137164, -1, 137541);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 312U, 136339, -1, 136712);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 311U, 135608, -1, 135985);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 310U, 134978, -1, 135349);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 309U, 134343, -1, 134724);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 308U, 133616, -1, 133993);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 307U, 132986, -1, 133357);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 306U, 132648, -1, 132682);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 305U, 132547, -1, 132570);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 304U, 132287, -1, 132442);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 303U, 132071, -1, 132224);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 302U, 131741, -1, 131897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 301U, 131563, -1, 131698);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 300U, 131120, -1, 131229);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 332U, 148599, -1, 148624);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 331U, 147820, -1, 148099);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 330U, 147423, -1, 147714);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 329U, 146675, -1, 146960);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 328U, 146284, -1, 146569);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 327U, 145533, -1, 145824);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 326U, 145148, -1, 145427);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 325U, 144400, -1, 144685);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 324U, 144009, -1, 144294);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 323U, 143710, -1, 143855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 322U, 143010, -1, 143248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 321U, 142557, -1, 142796);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 320U, 142105, -1, 142343);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 319U, 141652, -1, 141891);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 340U, 151469, -1, 151697);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 339U, 151144, -1, 151369);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 338U, 150820, -1, 151044);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 337U, 150495, -1, 150720);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 336U, 149948, -1, 150181);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 335U, 149624, -1, 149855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 334U, 149299, -1, 149530);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 333U, 148973, -1, 149206);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 348U, 154858, -1, 155081);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 347U, 154532, -1, 154758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 346U, 154205, -1, 154432);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 345U, 153879, -1, 154105);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 344U, 153335, -1, 153566);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 343U, 153009, -1, 153242);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 342U, 152682, -1, 152915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 341U, 152358, -1, 152589);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 356U, 158253, -1, 158484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 355U, 157922, -1, 158153);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 354U, 157591, -1, 157822);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 353U, 157260, -1, 157491);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 352U, 156700, -1, 156928);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 351U, 156382, -1, 156607);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 350U, 156062, -1, 156288);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 349U, 155742, -1, 155969);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 364U, 161647, -1, 161878);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 363U, 161316, -1, 161547);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 362U, 160985, -1, 161216);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 361U, 160654, -1, 160885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 360U, 160096, -1, 160322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 359U, 159776, -1, 160003);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 358U, 159454, -1, 159682);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 357U, 159136, -1, 159361);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 372U, 165046, -1, 165271);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 371U, 164720, -1, 164946);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 370U, 164395, -1, 164620);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 369U, 164069, -1, 164295);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 368U, 163509, -1, 163742);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 367U, 163183, -1, 163416);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 366U, 162856, -1, 163089);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 365U, 162530, -1, 162763);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 380U, 168445, -1, 168671);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 379U, 168120, -1, 168345);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 378U, 167794, -1, 168020);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 377U, 167469, -1, 167694);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 376U, 166912, -1, 167145);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 375U, 166586, -1, 166819);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 374U, 166259, -1, 166492);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 373U, 165933, -1, 166166);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 384U, 170294, -1, 170521);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 383U, 169973, -1, 170201);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 382U, 169652, -1, 169879);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 381U, 169331, -1, 169559);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 388U, 172350, -1, 172577);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 387U, 172029, -1, 172257);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 386U, 171708, -1, 171935);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 385U, 171387, -1, 171615);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 272, 297, 299, 678);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 2336, 2364, -1, 6810);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 2485, 2510, 2878, 2908);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 3151, 3177, -1, 3279);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 3959, 3969, 4137, 4140);
  covrtIfInit(&emlrtCoverageInstance, 1U, 5U, 4149, 4168, 4524, 4558);
  covrtIfInit(&emlrtCoverageInstance, 1U, 6U, 5254, 5302, 5533, 6079);
  covrtIfInit(&emlrtCoverageInstance, 1U, 7U, 5351, 5377, -1, 5494);
  covrtIfInit(&emlrtCoverageInstance, 1U, 8U, 6609, 6634, 6756, 6801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 9U, 6820, 6850, -1, 7302);
  covrtIfInit(&emlrtCoverageInstance, 1U, 10U, 7014, 7039, -1, 7224);
  covrtIfInit(&emlrtCoverageInstance, 1U, 11U, 7317, 7356, -1, 9155);
  covrtIfInit(&emlrtCoverageInstance, 1U, 12U, 9838, 9860, 10014, 10115);
  covrtIfInit(&emlrtCoverageInstance, 1U, 13U, 10154, 10179, -1, 10287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 14U, 10641, 10720, -1, 10782);
  covrtIfInit(&emlrtCoverageInstance, 1U, 15U, 10832, 10848, -1, 11237);
  covrtIfInit(&emlrtCoverageInstance, 1U, 16U, 10865, 10881, -1, 11145);
  covrtIfInit(&emlrtCoverageInstance, 1U, 17U, 10950, 10976, -1, 11125);
  covrtIfInit(&emlrtCoverageInstance, 1U, 18U, 11655, 11681, -1, 11811);
  covrtIfInit(&emlrtCoverageInstance, 1U, 19U, 12229, 12255, -1, 12385);
  covrtIfInit(&emlrtCoverageInstance, 1U, 20U, 12815, 12841, -1, 12970);
  covrtIfInit(&emlrtCoverageInstance, 1U, 21U, 13369, 13395, -1, 13524);
  covrtIfInit(&emlrtCoverageInstance, 1U, 22U, 13743, 13768, 14127, 14184);
  covrtIfInit(&emlrtCoverageInstance, 1U, 23U, 14788, 14823, -1, 14892);
  covrtIfInit(&emlrtCoverageInstance, 1U, 24U, 14909, 14943, -1, 15012);
  covrtIfInit(&emlrtCoverageInstance, 1U, 25U, 15029, 15064, -1, 15134);
  covrtIfInit(&emlrtCoverageInstance, 1U, 26U, 15151, 15185, -1, 15253);
  covrtIfInit(&emlrtCoverageInstance, 1U, 27U, 16696, 16721, 16973, 17359);
  covrtIfInit(&emlrtCoverageInstance, 1U, 28U, 16779, 16854, -1, 16968);
  covrtIfInit(&emlrtCoverageInstance, 1U, 29U, 17109, 17166, -1, 17342);
  covrtIfInit(&emlrtCoverageInstance, 1U, 30U, 17462, 17487, 17722, 18101);
  covrtIfInit(&emlrtCoverageInstance, 1U, 31U, 17545, 17629, -1, 17717);
  covrtIfInit(&emlrtCoverageInstance, 1U, 32U, 17858, 17915, -1, 18093);
  covrtIfInit(&emlrtCoverageInstance, 1U, 33U, 18236, 18261, 18496, 18871);
  covrtIfInit(&emlrtCoverageInstance, 1U, 34U, 18319, 18403, -1, 18491);
  covrtIfInit(&emlrtCoverageInstance, 1U, 35U, 18630, 18685, -1, 18863);
  covrtIfInit(&emlrtCoverageInstance, 1U, 36U, 20310, 20340, -1, 20677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 37U, 20700, 20730, -1, 21063);
  covrtIfInit(&emlrtCoverageInstance, 1U, 38U, 21091, 21107, -1, 21444);
  covrtIfInit(&emlrtCoverageInstance, 1U, 39U, 21468, 21484, -1, 21817);
  covrtIfInit(&emlrtCoverageInstance, 1U, 40U, 21984, 21992, -1, 30646);
  covrtIfInit(&emlrtCoverageInstance, 1U, 41U, 22067, 22325, -1, 24211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 42U, 22374, 22604, -1, 23263);
  covrtIfInit(&emlrtCoverageInstance, 1U, 43U, 23311, 23544, -1, 24197);
  covrtIfInit(&emlrtCoverageInstance, 1U, 44U, 24242, 24500, -1, 26349);
  covrtIfInit(&emlrtCoverageInstance, 1U, 45U, 24548, 24774, -1, 25417);
  covrtIfInit(&emlrtCoverageInstance, 1U, 46U, 25466, 25695, -1, 26336);
  covrtIfInit(&emlrtCoverageInstance, 1U, 47U, 26380, 26634, -1, 28491);
  covrtIfInit(&emlrtCoverageInstance, 1U, 48U, 26682, 26908, -1, 27552);
  covrtIfInit(&emlrtCoverageInstance, 1U, 49U, 27600, 27829, -1, 28478);
  covrtIfInit(&emlrtCoverageInstance, 1U, 50U, 28521, 28775, -1, 30638);
  covrtIfInit(&emlrtCoverageInstance, 1U, 51U, 28823, 29049, -1, 29701);
  covrtIfInit(&emlrtCoverageInstance, 1U, 52U, 29749, 29978, -1, 30626);
  covrtIfInit(&emlrtCoverageInstance, 1U, 53U, 31761, 31784, -1, 31831);
  covrtIfInit(&emlrtCoverageInstance, 1U, 54U, 31986, 32083, -1, 32398);
  covrtIfInit(&emlrtCoverageInstance, 1U, 55U, 32164, 32217, -1, 32374);
  covrtIfInit(&emlrtCoverageInstance, 1U, 56U, 32444, 32540, -1, 32855);
  covrtIfInit(&emlrtCoverageInstance, 1U, 57U, 32621, 32674, -1, 32831);
  covrtIfInit(&emlrtCoverageInstance, 1U, 58U, 32901, 32998, -1, 33313);
  covrtIfInit(&emlrtCoverageInstance, 1U, 59U, 33079, 33132, -1, 33289);
  covrtIfInit(&emlrtCoverageInstance, 1U, 60U, 33359, 33455, -1, 33770);
  covrtIfInit(&emlrtCoverageInstance, 1U, 61U, 33536, 33589, -1, 33746);
  covrtIfInit(&emlrtCoverageInstance, 1U, 62U, 33843, 33869, -1, 33900);
  covrtIfInit(&emlrtCoverageInstance, 1U, 63U, 34288, 34371, -1, 34693);
  covrtIfInit(&emlrtCoverageInstance, 1U, 64U, 34426, 34472, -1, 34677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 65U, 34723, 34805, -1, 35019);
  covrtIfInit(&emlrtCoverageInstance, 1U, 66U, 34823, 34869, -1, 35003);
  covrtIfInit(&emlrtCoverageInstance, 1U, 67U, 35050, 35133, -1, 35348);
  covrtIfInit(&emlrtCoverageInstance, 1U, 68U, 35151, 35197, -1, 35332);
  covrtIfInit(&emlrtCoverageInstance, 1U, 69U, 35378, 35460, -1, 35676);
  covrtIfInit(&emlrtCoverageInstance, 1U, 70U, 35478, 35524, -1, 35660);
  covrtIfInit(&emlrtCoverageInstance, 1U, 71U, 35965, 35990, -1, 36054);
  covrtIfInit(&emlrtCoverageInstance, 1U, 72U, 36374, 36399, -1, 36579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 73U, 36825, 36898, -1, 36961);
  covrtIfInit(&emlrtCoverageInstance, 1U, 74U, 36991, 37008, -1, 37054);
  covrtIfInit(&emlrtCoverageInstance, 1U, 75U, 37139, 37232, -1, 37553);
  covrtIfInit(&emlrtCoverageInstance, 1U, 76U, 37286, 37332, -1, 37537);
  covrtIfInit(&emlrtCoverageInstance, 1U, 77U, 37583, 37675, -1, 37888);
  covrtIfInit(&emlrtCoverageInstance, 1U, 78U, 37692, 37738, -1, 37872);
  covrtIfInit(&emlrtCoverageInstance, 1U, 79U, 37918, 38011, -1, 38226);
  covrtIfInit(&emlrtCoverageInstance, 1U, 80U, 38029, 38075, -1, 38210);
  covrtIfInit(&emlrtCoverageInstance, 1U, 81U, 38256, 38348, -1, 38561);
  covrtIfInit(&emlrtCoverageInstance, 1U, 82U, 38365, 38411, -1, 38545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 83U, 39556, 39581, 40152, 40197);
  covrtIfInit(&emlrtCoverageInstance, 1U, 84U, 42264, 42512, -1, 44441);
  covrtIfInit(&emlrtCoverageInstance, 1U, 85U, 42602, 42694, 43570, 44417);
  covrtIfInit(&emlrtCoverageInstance, 1U, 86U, 42775, 42853, -1, 43471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 87U, 43660, 43752, -1, 44389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 88U, 44587, 44833, -1, 46759);
  covrtIfInit(&emlrtCoverageInstance, 1U, 89U, 44923, 45014, 45889, 46735);
  covrtIfInit(&emlrtCoverageInstance, 1U, 90U, 45095, 45173, -1, 45790);
  covrtIfInit(&emlrtCoverageInstance, 1U, 91U, 45979, 46071, -1, 46707);
  covrtIfInit(&emlrtCoverageInstance, 1U, 92U, 46884, 47132, -1, 49061);
  covrtIfInit(&emlrtCoverageInstance, 1U, 93U, 47222, 47314, 48190, 49037);
  covrtIfInit(&emlrtCoverageInstance, 1U, 94U, 47395, 47473, -1, 48091);
  covrtIfInit(&emlrtCoverageInstance, 1U, 95U, 48280, 48372, -1, 49009);
  covrtIfInit(&emlrtCoverageInstance, 1U, 96U, 49206, 49452, -1, 51378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 97U, 49542, 49633, 50508, 51354);
  covrtIfInit(&emlrtCoverageInstance, 1U, 98U, 49714, 49792, -1, 50409);
  covrtIfInit(&emlrtCoverageInstance, 1U, 99U, 50598, 50690, -1, 51326);
  covrtIfInit(&emlrtCoverageInstance, 1U, 100U, 51442, 51461, -1, 51492);
  covrtIfInit(&emlrtCoverageInstance, 1U, 101U, 52475, 52492, 54752, 56268);
  covrtIfInit(&emlrtCoverageInstance, 1U, 102U, 52592, 52687, -1, 53104);
  covrtIfInit(&emlrtCoverageInstance, 1U, 103U, 53134, 53228, -1, 53644);
  covrtIfInit(&emlrtCoverageInstance, 1U, 104U, 53674, 53769, -1, 54178);
  covrtIfInit(&emlrtCoverageInstance, 1U, 105U, 54208, 54302, -1, 54710);
  covrtIfInit(&emlrtCoverageInstance, 1U, 106U, 54909, 54998, -1, 55194);
  covrtIfInit(&emlrtCoverageInstance, 1U, 107U, 55224, 55312, -1, 55508);
  covrtIfInit(&emlrtCoverageInstance, 1U, 108U, 55539, 55628, -1, 55820);
  covrtIfInit(&emlrtCoverageInstance, 1U, 109U, 55851, 55939, -1, 56131);
  covrtIfInit(&emlrtCoverageInstance, 1U, 110U, 56929, 57157, -1, 59479);
  covrtIfInit(&emlrtCoverageInstance, 1U, 111U, 57214, 57300, 58407, 59459);
  covrtIfInit(&emlrtCoverageInstance, 1U, 112U, 57374, 57452, 58035, 58118);
  covrtIfInit(&emlrtCoverageInstance, 1U, 113U, 58035, 58118, -1, 58118);
  covrtIfInit(&emlrtCoverageInstance, 1U, 114U, 58490, 58564, 59154, 59233);
  covrtIfInit(&emlrtCoverageInstance, 1U, 115U, 59154, 59233, -1, 59233);
  covrtIfInit(&emlrtCoverageInstance, 1U, 116U, 59552, 59778, -1, 62107);
  covrtIfInit(&emlrtCoverageInstance, 1U, 117U, 59836, 59927, 61023, 62087);
  covrtIfInit(&emlrtCoverageInstance, 1U, 118U, 60002, 60080, 60669, 60752);
  covrtIfInit(&emlrtCoverageInstance, 1U, 119U, 60669, 60752, -1, 60752);
  covrtIfInit(&emlrtCoverageInstance, 1U, 120U, 61107, 61181, 61777, 61856);
  covrtIfInit(&emlrtCoverageInstance, 1U, 121U, 61777, 61856, -1, 61856);
  covrtIfInit(&emlrtCoverageInstance, 1U, 122U, 62203, 62433, -1, 64791);
  covrtIfInit(&emlrtCoverageInstance, 1U, 123U, 62491, 62582, 63693, 64771);
  covrtIfInit(&emlrtCoverageInstance, 1U, 124U, 62657, 62737, 63332, 63417);
  covrtIfInit(&emlrtCoverageInstance, 1U, 125U, 63332, 63417, -1, 63417);
  covrtIfInit(&emlrtCoverageInstance, 1U, 126U, 63777, 63853, 64455, 64536);
  covrtIfInit(&emlrtCoverageInstance, 1U, 127U, 64455, 64536, -1, 64536);
  covrtIfInit(&emlrtCoverageInstance, 1U, 128U, 64863, 65095, -1, 67393);
  covrtIfInit(&emlrtCoverageInstance, 1U, 129U, 65152, 65238, 66321, 67373);
  covrtIfInit(&emlrtCoverageInstance, 1U, 130U, 65312, 65390, 65973, 66056);
  covrtIfInit(&emlrtCoverageInstance, 1U, 131U, 65973, 66056, -1, 66056);
  covrtIfInit(&emlrtCoverageInstance, 1U, 132U, 66404, 66478, 67068, 67147);
  covrtIfInit(&emlrtCoverageInstance, 1U, 133U, 67068, 67147, -1, 67147);
  covrtIfInit(&emlrtCoverageInstance, 1U, 134U, 67466, 67696, -1, 70025);
  covrtIfInit(&emlrtCoverageInstance, 1U, 135U, 67754, 67845, 68941, 70005);
  covrtIfInit(&emlrtCoverageInstance, 1U, 136U, 67920, 67998, 68587, 68670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 137U, 68587, 68670, -1, 68670);
  covrtIfInit(&emlrtCoverageInstance, 1U, 138U, 69025, 69099, 69695, 69774);
  covrtIfInit(&emlrtCoverageInstance, 1U, 139U, 69695, 69774, -1, 69774);
  covrtIfInit(&emlrtCoverageInstance, 1U, 140U, 70098, 70324, -1, 72625);
  covrtIfInit(&emlrtCoverageInstance, 1U, 141U, 70382, 70473, 71555, 72605);
  covrtIfInit(&emlrtCoverageInstance, 1U, 142U, 70548, 70624, 71207, 71288);
  covrtIfInit(&emlrtCoverageInstance, 1U, 143U, 71207, 71288, -1, 71288);
  covrtIfInit(&emlrtCoverageInstance, 1U, 144U, 71639, 71711, 72301, 72378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 145U, 72301, 72378, -1, 72378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 146U, 73236, 73464, -1, 75793);
  covrtIfInit(&emlrtCoverageInstance, 1U, 147U, 73522, 73613, 74709, 75773);
  covrtIfInit(&emlrtCoverageInstance, 1U, 148U, 73688, 73766, 74355, 74438);
  covrtIfInit(&emlrtCoverageInstance, 1U, 149U, 74355, 74438, -1, 74438);
  covrtIfInit(&emlrtCoverageInstance, 1U, 150U, 74793, 74867, 75463, 75542);
  covrtIfInit(&emlrtCoverageInstance, 1U, 151U, 75463, 75542, -1, 75542);
  covrtIfInit(&emlrtCoverageInstance, 1U, 152U, 75865, 76091, -1, 78385);
  covrtIfInit(&emlrtCoverageInstance, 1U, 153U, 76148, 76233, 77314, 78365);
  covrtIfInit(&emlrtCoverageInstance, 1U, 154U, 76307, 76385, 76967, 77050);
  covrtIfInit(&emlrtCoverageInstance, 1U, 155U, 76967, 77050, -1, 77050);
  covrtIfInit(&emlrtCoverageInstance, 1U, 156U, 77397, 77471, 78060, 78139);
  covrtIfInit(&emlrtCoverageInstance, 1U, 157U, 78060, 78139, -1, 78139);
  covrtIfInit(&emlrtCoverageInstance, 1U, 158U, 78458, 78686, -1, 80988);
  covrtIfInit(&emlrtCoverageInstance, 1U, 159U, 78744, 78835, 79918, 80968);
  covrtIfInit(&emlrtCoverageInstance, 1U, 160U, 78910, 78986, 79569, 79650);
  covrtIfInit(&emlrtCoverageInstance, 1U, 161U, 79569, 79650, -1, 79650);
  covrtIfInit(&emlrtCoverageInstance, 1U, 162U, 80002, 80074, 80664, 80741);
  covrtIfInit(&emlrtCoverageInstance, 1U, 163U, 80664, 80741, -1, 80741);
  covrtIfInit(&emlrtCoverageInstance, 1U, 164U, 81116, 81348, -1, 83677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 165U, 81406, 81497, 82593, 83657);
  covrtIfInit(&emlrtCoverageInstance, 1U, 166U, 81572, 81650, 82239, 82322);
  covrtIfInit(&emlrtCoverageInstance, 1U, 167U, 82239, 82322, -1, 82322);
  covrtIfInit(&emlrtCoverageInstance, 1U, 168U, 82677, 82751, 83347, 83426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 169U, 83347, 83426, -1, 83426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 170U, 83765, 83995, -1, 86288);
  covrtIfInit(&emlrtCoverageInstance, 1U, 171U, 84052, 84137, 85218, 86268);
  covrtIfInit(&emlrtCoverageInstance, 1U, 172U, 84211, 84289, 84871, 84954);
  covrtIfInit(&emlrtCoverageInstance, 1U, 173U, 84871, 84954, -1, 84954);
  covrtIfInit(&emlrtCoverageInstance, 1U, 174U, 85301, 85375, 85964, 86043);
  covrtIfInit(&emlrtCoverageInstance, 1U, 175U, 85964, 86043, -1, 86043);
  covrtIfInit(&emlrtCoverageInstance, 1U, 176U, 86361, 86593, -1, 88950);
  covrtIfInit(&emlrtCoverageInstance, 1U, 177U, 86651, 86742, 87852, 88930);
  covrtIfInit(&emlrtCoverageInstance, 1U, 178U, 86817, 86897, 87492, 87577);
  covrtIfInit(&emlrtCoverageInstance, 1U, 179U, 87492, 87577, -1, 87577);
  covrtIfInit(&emlrtCoverageInstance, 1U, 180U, 87936, 88012, 88614, 88695);
  covrtIfInit(&emlrtCoverageInstance, 1U, 181U, 88614, 88695, -1, 88695);
  covrtIfInit(&emlrtCoverageInstance, 1U, 182U, 89027, 89046, -1, 89143);
  covrtIfInit(&emlrtCoverageInstance, 1U, 183U, 89840, 89879, 91426, 92919);
  covrtIfInit(&emlrtCoverageInstance, 1U, 184U, 89902, 90058, -1, 91379);
  covrtIfInit(&emlrtCoverageInstance, 1U, 185U, 90188, 90330, 90451, 90599);
  covrtIfInit(&emlrtCoverageInstance, 1U, 186U, 90451, 90599, 90720, 91255);
  covrtIfInit(&emlrtCoverageInstance, 1U, 187U, 90720, 90866, 90987, 91255);
  covrtIfInit(&emlrtCoverageInstance, 1U, 188U, 90987, 91131, -1, 91131);
  covrtIfInit(&emlrtCoverageInstance, 1U, 189U, 91451, 91607, -1, 92899);
  covrtIfInit(&emlrtCoverageInstance, 1U, 190U, 91737, 91879, 91999, 92143);
  covrtIfInit(&emlrtCoverageInstance, 1U, 191U, 91999, 92143, 92263, 92800);
  covrtIfInit(&emlrtCoverageInstance, 1U, 192U, 92263, 92409, 92529, 92800);
  covrtIfInit(&emlrtCoverageInstance, 1U, 193U, 92529, 92677, -1, 92677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 194U, 93270, 93287, 93541, 102573);
  covrtIfInit(&emlrtCoverageInstance, 1U, 195U, 93721, 93760, 98137, 102446);
  covrtIfInit(&emlrtCoverageInstance, 1U, 196U, 93789, 93819, 94455, 94494);
  covrtIfInit(&emlrtCoverageInstance, 1U, 197U, 93852, 93912, -1, 94426);
  covrtIfInit(&emlrtCoverageInstance, 1U, 198U, 94455, 94494, 95135, 98074);
  covrtIfInit(&emlrtCoverageInstance, 1U, 199U, 94527, 94587, -1, 95106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 200U, 95135, 95168, 95232, 98074);
  covrtIfInit(&emlrtCoverageInstance, 1U, 201U, 95232, 95271, 95918, 98074);
  covrtIfInit(&emlrtCoverageInstance, 1U, 202U, 95304, 95366, -1, 95889);
  covrtIfInit(&emlrtCoverageInstance, 1U, 203U, 95918, 95952, 96588, 98074);
  covrtIfInit(&emlrtCoverageInstance, 1U, 204U, 95985, 96045, -1, 96559);
  covrtIfInit(&emlrtCoverageInstance, 1U, 205U, 96588, 96627, 97268, 98074);
  covrtIfInit(&emlrtCoverageInstance, 1U, 206U, 96660, 96720, -1, 97239);
  covrtIfInit(&emlrtCoverageInstance, 1U, 207U, 97268, 97301, 97365, 98074);
  covrtIfInit(&emlrtCoverageInstance, 1U, 208U, 97365, 97404, -1, 97404);
  covrtIfInit(&emlrtCoverageInstance, 1U, 209U, 97445, 97503, -1, 98018);
  covrtIfInit(&emlrtCoverageInstance, 1U, 210U, 98170, 98200, 98260, 98299);
  covrtIfInit(&emlrtCoverageInstance, 1U, 211U, 98260, 98299, 98941, 102421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 212U, 98332, 98392, -1, 98912);
  covrtIfInit(&emlrtCoverageInstance, 1U, 213U, 98941, 98974, 99609, 102421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 214U, 99007, 99067, -1, 99580);
  covrtIfInit(&emlrtCoverageInstance, 1U, 215U, 99609, 99648, 100284, 102421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 216U, 99681, 99739, -1, 100255);
  covrtIfInit(&emlrtCoverageInstance, 1U, 217U, 100284, 100318, 100382, 102421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 218U, 100382, 100421, 101063, 102421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 219U, 100454, 100514, -1, 101034);
  covrtIfInit(&emlrtCoverageInstance, 1U, 220U, 101063, 101096, 101731, 102421);
  covrtIfInit(&emlrtCoverageInstance, 1U, 221U, 101129, 101189, -1, 101702);
  covrtIfInit(&emlrtCoverageInstance, 1U, 222U, 101731, 101770, -1, 101770);
  covrtIfInit(&emlrtCoverageInstance, 1U, 223U, 101803, 101865, -1, 102389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 224U, 102937, 102971, 103557, 103600);
  covrtIfInit(&emlrtCoverageInstance, 1U, 225U, 102984, 103020, -1, 103524);
  covrtIfInit(&emlrtCoverageInstance, 1U, 226U, 103037, 103089, 103297, 103508);
  covrtIfInit(&emlrtCoverageInstance, 1U, 227U, 103557, 103600, 105778, 114386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 228U, 103613, 103649, 104712, 105769);
  covrtIfInit(&emlrtCoverageInstance, 1U, 229U, 103666, 103720, 103952, 104699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 230U, 103952, 104008, 104218, 104699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 231U, 104218, 104274, 104486, 104699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 232U, 104733, 104787, 105005, 105753);
  covrtIfInit(&emlrtCoverageInstance, 1U, 233U, 105005, 105061, 105272, 105753);
  covrtIfInit(&emlrtCoverageInstance, 1U, 234U, 105272, 105328, 105539, 105753);
  covrtIfInit(&emlrtCoverageInstance, 1U, 235U, 105778, 105815, 106401, 114386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 236U, 105852, 105888, -1, 106392);
  covrtIfInit(&emlrtCoverageInstance, 1U, 237U, 105905, 105957, 106165, 106376);
  covrtIfInit(&emlrtCoverageInstance, 1U, 238U, 106401, 106444, 108653, 114386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 239U, 106457, 106493, 107536, 108644);
  covrtIfInit(&emlrtCoverageInstance, 1U, 240U, 106510, 106564, 106776, 107523);
  covrtIfInit(&emlrtCoverageInstance, 1U, 241U, 106776, 106834, 107046, 107523);
  covrtIfInit(&emlrtCoverageInstance, 1U, 242U, 107046, 107102, 107310, 107523);
  covrtIfInit(&emlrtCoverageInstance, 1U, 243U, 107557, 107611, 107843, 108628);
  covrtIfInit(&emlrtCoverageInstance, 1U, 244U, 107843, 107899, 108129, 108628);
  covrtIfInit(&emlrtCoverageInstance, 1U, 245U, 108129, 108185, 108417, 108628);
  covrtIfInit(&emlrtCoverageInstance, 1U, 246U, 108653, 108691, 109255, 114386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 247U, 108704, 108740, -1, 109246);
  covrtIfInit(&emlrtCoverageInstance, 1U, 248U, 108757, 108809, 109017, 109230);
  covrtIfInit(&emlrtCoverageInstance, 1U, 249U, 109255, 109298, 111535, 114386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 250U, 109311, 109347, 110436, 111526);
  covrtIfInit(&emlrtCoverageInstance, 1U, 251U, 109364, 109418, 109650, 110423);
  covrtIfInit(&emlrtCoverageInstance, 1U, 252U, 109650, 109708, 109922, 110423);
  covrtIfInit(&emlrtCoverageInstance, 1U, 253U, 109922, 109978, 110208, 110423);
  covrtIfInit(&emlrtCoverageInstance, 1U, 254U, 110457, 110511, 110723, 111510);
  covrtIfInit(&emlrtCoverageInstance, 1U, 255U, 110723, 110781, 110992, 111510);
  covrtIfInit(&emlrtCoverageInstance, 1U, 256U, 110992, 111048, 111276, 111510);
  covrtIfInit(&emlrtCoverageInstance, 1U, 257U, 111535, 111572, 112162, 114386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 258U, 111609, 111645, -1, 112151);
  covrtIfInit(&emlrtCoverageInstance, 1U, 259U, 111662, 111714, 111922, 112135);
  covrtIfInit(&emlrtCoverageInstance, 1U, 260U, 112162, 112205, -1, 112205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 261U, 112218, 112254, 113307, 114374);
  covrtIfInit(&emlrtCoverageInstance, 1U, 262U, 112271, 112325, 112537, 113294);
  covrtIfInit(&emlrtCoverageInstance, 1U, 263U, 112537, 112593, 112799, 113294);
  covrtIfInit(&emlrtCoverageInstance, 1U, 264U, 112799, 112855, 113063, 113294);
  covrtIfInit(&emlrtCoverageInstance, 1U, 265U, 113328, 113382, 113594, 114341);
  covrtIfInit(&emlrtCoverageInstance, 1U, 266U, 113594, 113652, 113864, 114341);
  covrtIfInit(&emlrtCoverageInstance, 1U, 267U, 113864, 113920, 114128, 114341);
  covrtIfInit(&emlrtCoverageInstance, 1U, 268U, 115973, 116005, 121624, 127702);
  covrtIfInit(&emlrtCoverageInstance, 1U, 269U, 116294, 116504, -1, 121567);
  covrtIfInit(&emlrtCoverageInstance, 1U, 270U, 116569, 116647, 120673, 121377);
  covrtIfInit(&emlrtCoverageInstance, 1U, 271U, 116975, 117007, 117594, 120623);
  covrtIfInit(&emlrtCoverageInstance, 1U, 272U, 117748, 117769, -1, 118359);
  covrtIfInit(&emlrtCoverageInstance, 1U, 273U, 117835, 117860, -1, 118027);
  covrtIfInit(&emlrtCoverageInstance, 1U, 274U, 118933, 118958, -1, 119115);
  covrtIfInit(&emlrtCoverageInstance, 1U, 275U, 119184, 119208, -1, 119469);
  covrtIfInit(&emlrtCoverageInstance, 1U, 276U, 119237, 119262, -1, 119441);
  covrtIfInit(&emlrtCoverageInstance, 1U, 277U, 119532, 119572, 119957, 120599);
  covrtIfInit(&emlrtCoverageInstance, 1U, 278U, 119602, 119627, -1, 119711);
  covrtIfInit(&emlrtCoverageInstance, 1U, 279U, 119957, 120001, 120382, 120599);
  covrtIfInit(&emlrtCoverageInstance, 1U, 280U, 120030, 120055, -1, 120137);
  covrtIfInit(&emlrtCoverageInstance, 1U, 281U, 120415, 120440, -1, 120571);
  covrtIfInit(&emlrtCoverageInstance, 1U, 282U, 120780, 120801, -1, 121357);
  covrtIfInit(&emlrtCoverageInstance, 1U, 283U, 120859, 120884, -1, 121041);
  covrtIfInit(&emlrtCoverageInstance, 1U, 284U, 121691, 121712, -1, 122322);
  covrtIfInit(&emlrtCoverageInstance, 1U, 285U, 121754, 121779, -1, 121925);
  covrtIfInit(&emlrtCoverageInstance, 1U, 286U, 122904, 122928, 123199, 123485);
  covrtIfInit(&emlrtCoverageInstance, 1U, 287U, 122981, 123006, -1, 123155);
  covrtIfInit(&emlrtCoverageInstance, 1U, 288U, 123542, 123576, -1, 123727);
  covrtIfInit(&emlrtCoverageInstance, 1U, 289U, 123597, 123622, -1, 123707);
  covrtIfInit(&emlrtCoverageInstance, 1U, 290U, 123793, 123833, 124156, 124200);
  covrtIfInit(&emlrtCoverageInstance, 1U, 291U, 123850, 123875, -1, 123934);
  covrtIfInit(&emlrtCoverageInstance, 1U, 292U, 124156, 124200, 124526, 127211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 293U, 124217, 124242, -1, 124300);
  covrtIfInit(&emlrtCoverageInstance, 1U, 294U, 124526, 124570, 125115, 127211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 295U, 124587, 124612, -1, 124889);
  covrtIfInit(&emlrtCoverageInstance, 1U, 296U, 124633, 124683, 124747, 124801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 297U, 124747, 124801, -1, 124801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 298U, 125115, 125159, 125698, 127211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 299U, 125176, 125201, -1, 125476);
  covrtIfInit(&emlrtCoverageInstance, 1U, 300U, 125222, 125272, 125335, 125389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 301U, 125335, 125389, -1, 125389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 302U, 125698, 125743, 126084, 127211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 303U, 125760, 125785, -1, 125845);
  covrtIfInit(&emlrtCoverageInstance, 1U, 304U, 126084, 126129, 126458, 127211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 305U, 126146, 126171, -1, 126230);
  covrtIfInit(&emlrtCoverageInstance, 1U, 306U, 126458, 126503, 126835, 127211);
  covrtIfInit(&emlrtCoverageInstance, 1U, 307U, 126522, 126547, -1, 126607);
  covrtIfInit(&emlrtCoverageInstance, 1U, 308U, 126835, 126880, -1, 126880);
  covrtIfInit(&emlrtCoverageInstance, 1U, 309U, 126897, 126922, -1, 126981);
  covrtIfInit(&emlrtCoverageInstance, 1U, 310U, 127345, 127429, -1, 127476);
  covrtIfInit(&emlrtCoverageInstance, 1U, 311U, 127745, 127762, -1, 127793);
  covrtIfInit(&emlrtCoverageInstance, 1U, 312U, 128341, 128387, 129751, 130845);
  covrtIfInit(&emlrtCoverageInstance, 1U, 313U, 128440, 128466, 129090, 129120);
  covrtIfInit(&emlrtCoverageInstance, 1U, 314U, 128487, 128513, 128596, 128626);
  covrtIfInit(&emlrtCoverageInstance, 1U, 315U, 128596, 128626, 128709, 129032);
  covrtIfInit(&emlrtCoverageInstance, 1U, 316U, 128709, 128739, -1, 128739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 317U, 128764, 128790, 128882, 128912);
  covrtIfInit(&emlrtCoverageInstance, 1U, 318U, 128882, 128912, -1, 128912);
  covrtIfInit(&emlrtCoverageInstance, 1U, 319U, 129090, 129120, -1, 129120);
  covrtIfInit(&emlrtCoverageInstance, 1U, 320U, 129141, 129167, 129250, 129280);
  covrtIfInit(&emlrtCoverageInstance, 1U, 321U, 129250, 129280, 129363, 129686);
  covrtIfInit(&emlrtCoverageInstance, 1U, 322U, 129363, 129393, -1, 129393);
  covrtIfInit(&emlrtCoverageInstance, 1U, 323U, 129418, 129444, 129536, 129566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 324U, 129536, 129566, -1, 129566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 325U, 129751, 129801, 130701, 130845);
  covrtIfInit(&emlrtCoverageInstance, 1U, 326U, 129842, 129868, 129943, 129973);
  covrtIfInit(&emlrtCoverageInstance, 1U, 327U, 129943, 129973, 130265, 130671);
  covrtIfInit(&emlrtCoverageInstance, 1U, 328U, 129994, 130020, 130103, 130133);
  covrtIfInit(&emlrtCoverageInstance, 1U, 329U, 130103, 130133, -1, 130133);
  covrtIfInit(&emlrtCoverageInstance, 1U, 330U, 130265, 130295, 130374, 130671);
  covrtIfInit(&emlrtCoverageInstance, 1U, 331U, 130374, 130404, -1, 130404);
  covrtIfInit(&emlrtCoverageInstance, 1U, 332U, 130425, 130451, 130534, 130564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 333U, 130534, 130564, -1, 130564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 334U, 130722, 130747, -1, 130824);
  covrtIfInit(&emlrtCoverageInstance, 1U, 335U, 131281, 131358, 132490, 141260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 336U, 131417, 131454, 131931, 132481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 337U, 131471, 131542, 131716, 131918);
  covrtIfInit(&emlrtCoverageInstance, 1U, 338U, 131979, 132050, 132262, 132465);
  covrtIfInit(&emlrtCoverageInstance, 1U, 339U, 132730, 132769, 136852, 141230);
  covrtIfInit(&emlrtCoverageInstance, 1U, 340U, 132794, 132824, 133415, 133454);
  covrtIfInit(&emlrtCoverageInstance, 1U, 341U, 132853, 132913, -1, 133390);
  covrtIfInit(&emlrtCoverageInstance, 1U, 342U, 133415, 133454, 134051, 136797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 343U, 133483, 133543, -1, 134026);
  covrtIfInit(&emlrtCoverageInstance, 1U, 344U, 134051, 134084, 134140, 136797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 345U, 134140, 134179, 134782, 136797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 346U, 134208, 134270, -1, 134757);
  covrtIfInit(&emlrtCoverageInstance, 1U, 347U, 134782, 134816, 135407, 136797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 348U, 134845, 134905, -1, 135382);
  covrtIfInit(&emlrtCoverageInstance, 1U, 349U, 135407, 135446, 136043, 136797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 350U, 135475, 135535, -1, 136018);
  covrtIfInit(&emlrtCoverageInstance, 1U, 351U, 136043, 136076, 136132, 136797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 352U, 136132, 136171, -1, 136171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 353U, 136208, 136266, -1, 136745);
  covrtIfInit(&emlrtCoverageInstance, 1U, 354U, 136881, 136911, 136963, 137002);
  covrtIfInit(&emlrtCoverageInstance, 1U, 355U, 136963, 137002, 137599, 141209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 356U, 137031, 137091, -1, 137574);
  covrtIfInit(&emlrtCoverageInstance, 1U, 357U, 137599, 137632, 138222, 141209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 358U, 137661, 137721, -1, 138197);
  covrtIfInit(&emlrtCoverageInstance, 1U, 359U, 138222, 138261, 138852, 141209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 360U, 138290, 138348, -1, 138827);
  covrtIfInit(&emlrtCoverageInstance, 1U, 361U, 138852, 138886, 138942, 141209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 362U, 138942, 138981, 139699, 141209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 363U, 139010, 139034, -1, 139674);
  covrtIfInit(&emlrtCoverageInstance, 1U, 364U, 139067, 139127, -1, 139642);
  covrtIfInit(&emlrtCoverageInstance, 1U, 365U, 139699, 139732, 140443, 141209);
  covrtIfInit(&emlrtCoverageInstance, 1U, 366U, 139761, 139785, -1, 140418);
  covrtIfInit(&emlrtCoverageInstance, 1U, 367U, 139818, 139878, -1, 140386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 368U, 140443, 140482, -1, 140482);
  covrtIfInit(&emlrtCoverageInstance, 1U, 369U, 140511, 140535, -1, 141181);
  covrtIfInit(&emlrtCoverageInstance, 1U, 370U, 140568, 140630, -1, 141149);
  covrtIfInit(&emlrtCoverageInstance, 1U, 371U, 141530, 141580, 143575, 148564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 372U, 141593, 141635, 142043, 143545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 373U, 141909, 141934, -1, 142030);
  covrtIfInit(&emlrtCoverageInstance, 1U, 374U, 142043, 142088, 142494, 143545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 375U, 142361, 142386, -1, 142481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 376U, 142494, 142540, 142948, 143545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 377U, 142814, 142839, -1, 142935);
  covrtIfInit(&emlrtCoverageInstance, 1U, 378U, 142948, 142993, 143404, 143545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 379U, 143266, 143291, -1, 143391);
  covrtIfInit(&emlrtCoverageInstance, 1U, 380U, 143425, 143450, -1, 143529);
  covrtIfInit(&emlrtCoverageInstance, 1U, 381U, 143575, 143629, 148442, 148564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 382U, 143882, 143929, 145017, 145068);
  covrtIfInit(&emlrtCoverageInstance, 1U, 383U, 143946, 143988, 144333, 144858);
  covrtIfInit(&emlrtCoverageInstance, 1U, 384U, 144333, 144379, 144703, 144858);
  covrtIfInit(&emlrtCoverageInstance, 1U, 385U, 144729, 144754, -1, 144838);
  covrtIfInit(&emlrtCoverageInstance, 1U, 386U, 144876, 144901, -1, 145004);
  covrtIfInit(&emlrtCoverageInstance, 1U, 387U, 145017, 145068, 146153, 148433);
  covrtIfInit(&emlrtCoverageInstance, 1U, 388U, 145085, 145127, 145466, 145997);
  covrtIfInit(&emlrtCoverageInstance, 1U, 389U, 145466, 145512, 145842, 145997);
  covrtIfInit(&emlrtCoverageInstance, 1U, 390U, 145868, 145893, -1, 145977);
  covrtIfInit(&emlrtCoverageInstance, 1U, 391U, 146014, 146039, -1, 146140);
  covrtIfInit(&emlrtCoverageInstance, 1U, 392U, 146153, 146204, 147292, 148433);
  covrtIfInit(&emlrtCoverageInstance, 1U, 393U, 146221, 146263, 146608, 147133);
  covrtIfInit(&emlrtCoverageInstance, 1U, 394U, 146608, 146654, 146978, 147133);
  covrtIfInit(&emlrtCoverageInstance, 1U, 395U, 147004, 147029, -1, 147113);
  covrtIfInit(&emlrtCoverageInstance, 1U, 396U, 147151, 147176, -1, 147279);
  covrtIfInit(&emlrtCoverageInstance, 1U, 397U, 147292, 147343, -1, 147343);
  covrtIfInit(&emlrtCoverageInstance, 1U, 398U, 147360, 147402, 147753, 148274);
  covrtIfInit(&emlrtCoverageInstance, 1U, 399U, 147753, 147799, 148117, 148274);
  covrtIfInit(&emlrtCoverageInstance, 1U, 400U, 148143, 148168, -1, 148254);
  covrtIfInit(&emlrtCoverageInstance, 1U, 401U, 148292, 148317, -1, 148417);
  covrtIfInit(&emlrtCoverageInstance, 1U, 402U, 148460, 148485, -1, 148552);
  covrtIfInit(&emlrtCoverageInstance, 1U, 403U, 148851, 148901, 150364, 152004);
  covrtIfInit(&emlrtCoverageInstance, 1U, 404U, 148914, 148956, 149237, 150355);
  covrtIfInit(&emlrtCoverageInstance, 1U, 405U, 149237, 149282, 149561, 150355);
  covrtIfInit(&emlrtCoverageInstance, 1U, 406U, 149561, 149607, 149886, 150355);
  covrtIfInit(&emlrtCoverageInstance, 1U, 407U, 149886, 149931, 150195, 150355);
  covrtIfInit(&emlrtCoverageInstance, 1U, 408U, 150217, 150242, -1, 150339);
  covrtIfInit(&emlrtCoverageInstance, 1U, 409U, 150364, 150418, 151881, 152004);
  covrtIfInit(&emlrtCoverageInstance, 1U, 410U, 150431, 150478, 150752, 151872);
  covrtIfInit(&emlrtCoverageInstance, 1U, 411U, 150752, 150803, 151076, 151872);
  covrtIfInit(&emlrtCoverageInstance, 1U, 412U, 151076, 151127, 151401, 151872);
  covrtIfInit(&emlrtCoverageInstance, 1U, 413U, 151401, 151452, 151712, 151872);
  covrtIfInit(&emlrtCoverageInstance, 1U, 414U, 151734, 151759, -1, 151856);
  covrtIfInit(&emlrtCoverageInstance, 1U, 415U, 151899, 151924, -1, 151992);
  covrtIfInit(&emlrtCoverageInstance, 1U, 416U, 152236, 152286, 153748, 155389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 417U, 152299, 152341, 152620, 153739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 418U, 152620, 152665, 152946, 153739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 419U, 152946, 152992, 153273, 153739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 420U, 153273, 153318, 153580, 153739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 421U, 153602, 153627, -1, 153723);
  covrtIfInit(&emlrtCoverageInstance, 1U, 422U, 153748, 153802, 155266, 155389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 423U, 153815, 153862, 154137, 155257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 424U, 154137, 154188, 154464, 155257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 425U, 154464, 154515, 154790, 155257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 426U, 154790, 154841, 155096, 155257);
  covrtIfInit(&emlrtCoverageInstance, 1U, 427U, 155118, 155143, -1, 155241);
  covrtIfInit(&emlrtCoverageInstance, 1U, 428U, 155284, 155309, -1, 155377);
  covrtIfInit(&emlrtCoverageInstance, 1U, 429U, 155620, 155670, 157129, 158784);
  covrtIfInit(&emlrtCoverageInstance, 1U, 430U, 155683, 155725, 156000, 157093);
  covrtIfInit(&emlrtCoverageInstance, 1U, 431U, 156000, 156045, 156319, 157093);
  covrtIfInit(&emlrtCoverageInstance, 1U, 432U, 156319, 156365, 156638, 157093);
  covrtIfInit(&emlrtCoverageInstance, 1U, 433U, 156638, 156683, 156942, 157093);
  covrtIfInit(&emlrtCoverageInstance, 1U, 434U, 156964, 156989, -1, 157077);
  covrtIfInit(&emlrtCoverageInstance, 1U, 435U, 157129, 157183, 158661, 158784);
  covrtIfInit(&emlrtCoverageInstance, 1U, 436U, 157196, 157243, 157523, 158652);
  covrtIfInit(&emlrtCoverageInstance, 1U, 437U, 157523, 157574, 157854, 158652);
  covrtIfInit(&emlrtCoverageInstance, 1U, 438U, 157854, 157905, 158185, 158652);
  covrtIfInit(&emlrtCoverageInstance, 1U, 439U, 158185, 158236, 158499, 158652);
  covrtIfInit(&emlrtCoverageInstance, 1U, 440U, 158521, 158546, -1, 158636);
  covrtIfInit(&emlrtCoverageInstance, 1U, 441U, 158679, 158704, -1, 158772);
  covrtIfInit(&emlrtCoverageInstance, 1U, 442U, 159014, 159064, 160523, 162176);
  covrtIfInit(&emlrtCoverageInstance, 1U, 443U, 159077, 159119, 159392, 160487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 444U, 159392, 159437, 159713, 160487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 445U, 159713, 159759, 160034, 160487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 446U, 160034, 160079, 160336, 160487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 447U, 160358, 160383, -1, 160471);
  covrtIfInit(&emlrtCoverageInstance, 1U, 448U, 160523, 160577, 162054, 162176);
  covrtIfInit(&emlrtCoverageInstance, 1U, 449U, 160590, 160637, 160917, 162045);
  covrtIfInit(&emlrtCoverageInstance, 1U, 450U, 160917, 160968, 161248, 162045);
  covrtIfInit(&emlrtCoverageInstance, 1U, 451U, 161248, 161299, 161579, 162045);
  covrtIfInit(&emlrtCoverageInstance, 1U, 452U, 161579, 161630, 161893, 162045);
  covrtIfInit(&emlrtCoverageInstance, 1U, 453U, 161915, 161940, -1, 162029);
  covrtIfInit(&emlrtCoverageInstance, 1U, 454U, 162072, 162097, -1, 162164);
  covrtIfInit(&emlrtCoverageInstance, 1U, 455U, 162408, 162458, 163938, 165579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 456U, 162471, 162513, 162794, 163907);
  covrtIfInit(&emlrtCoverageInstance, 1U, 457U, 162794, 162839, 163120, 163907);
  covrtIfInit(&emlrtCoverageInstance, 1U, 458U, 163120, 163166, 163447, 163907);
  covrtIfInit(&emlrtCoverageInstance, 1U, 459U, 163447, 163492, 163756, 163907);
  covrtIfInit(&emlrtCoverageInstance, 1U, 460U, 163778, 163803, -1, 163891);
  covrtIfInit(&emlrtCoverageInstance, 1U, 461U, 163938, 163992, 165457, 165579);
  covrtIfInit(&emlrtCoverageInstance, 1U, 462U, 164005, 164052, 164327, 165448);
  covrtIfInit(&emlrtCoverageInstance, 1U, 463U, 164327, 164378, 164652, 165448);
  covrtIfInit(&emlrtCoverageInstance, 1U, 464U, 164652, 164703, 164978, 165448);
  covrtIfInit(&emlrtCoverageInstance, 1U, 465U, 164978, 165029, 165286, 165448);
  covrtIfInit(&emlrtCoverageInstance, 1U, 466U, 165308, 165333, -1, 165432);
  covrtIfInit(&emlrtCoverageInstance, 1U, 467U, 165475, 165500, -1, 165567);
  covrtIfInit(&emlrtCoverageInstance, 1U, 468U, 165811, 165861, 167338, 168977);
  covrtIfInit(&emlrtCoverageInstance, 1U, 469U, 165874, 165916, 166197, 167310);
  covrtIfInit(&emlrtCoverageInstance, 1U, 470U, 166197, 166242, 166523, 167310);
  covrtIfInit(&emlrtCoverageInstance, 1U, 471U, 166523, 166569, 166850, 167310);
  covrtIfInit(&emlrtCoverageInstance, 1U, 472U, 166850, 166895, 167159, 167310);
  covrtIfInit(&emlrtCoverageInstance, 1U, 473U, 167181, 167206, -1, 167294);
  covrtIfInit(&emlrtCoverageInstance, 1U, 474U, 167338, 167392, 168855, 168977);
  covrtIfInit(&emlrtCoverageInstance, 1U, 475U, 167405, 167452, 167726, 168846);
  covrtIfInit(&emlrtCoverageInstance, 1U, 476U, 167726, 167777, 168052, 168846);
  covrtIfInit(&emlrtCoverageInstance, 1U, 477U, 168052, 168103, 168377, 168846);
  covrtIfInit(&emlrtCoverageInstance, 1U, 478U, 168377, 168428, 168686, 168846);
  covrtIfInit(&emlrtCoverageInstance, 1U, 479U, 168708, 168733, -1, 168830);
  covrtIfInit(&emlrtCoverageInstance, 1U, 480U, 168873, 168898, -1, 168965);
  covrtIfInit(&emlrtCoverageInstance, 1U, 481U, 169209, 169259, 170718, 171033);
  covrtIfInit(&emlrtCoverageInstance, 1U, 482U, 169272, 169314, 169590, 170687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 483U, 169590, 169635, 169910, 170687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 484U, 169910, 169956, 170232, 170687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 485U, 170232, 170277, 170535, 170687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 486U, 170557, 170582, -1, 170671);
  covrtIfInit(&emlrtCoverageInstance, 1U, 487U, 170718, 170772, 170910, 171033);
  covrtIfInit(&emlrtCoverageInstance, 1U, 488U, 170786, 170811, -1, 170901);
  covrtIfInit(&emlrtCoverageInstance, 1U, 489U, 170928, 170953, -1, 171021);
  covrtIfInit(&emlrtCoverageInstance, 1U, 490U, 171265, 171315, 172772, 173091);
  covrtIfInit(&emlrtCoverageInstance, 1U, 491U, 171328, 171370, 171646, 172744);
  covrtIfInit(&emlrtCoverageInstance, 1U, 492U, 171646, 171691, 171966, 172744);
  covrtIfInit(&emlrtCoverageInstance, 1U, 493U, 171966, 172012, 172288, 172744);
  covrtIfInit(&emlrtCoverageInstance, 1U, 494U, 172288, 172333, 172591, 172744);
  covrtIfInit(&emlrtCoverageInstance, 1U, 495U, 172613, 172638, -1, 172728);
  covrtIfInit(&emlrtCoverageInstance, 1U, 496U, 172772, 172826, 172965, 173091);
  covrtIfInit(&emlrtCoverageInstance, 1U, 497U, 172840, 172865, -1, 172956);
  covrtIfInit(&emlrtCoverageInstance, 1U, 498U, 172983, 173008, -1, 173079);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 3154, 3177, 1, 0,
                cond_starts_1_0, cond_ends_1_0, 2, postfix_exprs_1_0);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 5354, 5377, 1, 1,
                cond_starts_1_1, cond_ends_1_1, 2, postfix_exprs_1_1);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 10644, 10720, 2, 2,
                cond_starts_1_2, cond_ends_1_2, 3, postfix_exprs_1_2);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 3U, 10953, 10976, 1, 4,
                cond_starts_1_3, cond_ends_1_3, 2, postfix_exprs_1_3);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 4U, 11658, 11681, 1, 5,
                cond_starts_1_4, cond_ends_1_4, 2, postfix_exprs_1_4);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 5U, 12232, 12255, 1, 6,
                cond_starts_1_5, cond_ends_1_5, 2, postfix_exprs_1_5);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 6U, 12818, 12841, 1, 7,
                cond_starts_1_6, cond_ends_1_6, 2, postfix_exprs_1_6);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 7U, 13372, 13395, 1, 8,
                cond_starts_1_7, cond_ends_1_7, 2, postfix_exprs_1_7);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 8U, 22070, 22325, 2, 9,
                cond_starts_1_8, cond_ends_1_8, 3, postfix_exprs_1_8);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 9U, 22377, 22604, 2, 11,
                cond_starts_1_9, cond_ends_1_9, 3, postfix_exprs_1_9);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 10U, 23314, 23544, 2, 13,
                cond_starts_1_10, cond_ends_1_10, 3, postfix_exprs_1_10);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 11U, 24245, 24500, 2, 15,
                cond_starts_1_11, cond_ends_1_11, 3, postfix_exprs_1_11);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 12U, 24551, 24774, 2, 17,
                cond_starts_1_12, cond_ends_1_12, 3, postfix_exprs_1_12);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 13U, 25469, 25695, 2, 19,
                cond_starts_1_13, cond_ends_1_13, 3, postfix_exprs_1_13);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 14U, 26383, 26634, 2, 21,
                cond_starts_1_14, cond_ends_1_14, 3, postfix_exprs_1_14);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 15U, 26685, 26908, 2, 23,
                cond_starts_1_15, cond_ends_1_15, 3, postfix_exprs_1_15);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 16U, 27603, 27829, 2, 25,
                cond_starts_1_16, cond_ends_1_16, 3, postfix_exprs_1_16);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 17U, 28524, 28775, 2, 27,
                cond_starts_1_17, cond_ends_1_17, 3, postfix_exprs_1_17);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 18U, 28826, 29049, 2, 29,
                cond_starts_1_18, cond_ends_1_18, 3, postfix_exprs_1_18);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 19U, 29752, 29978, 2, 31,
                cond_starts_1_19, cond_ends_1_19, 3, postfix_exprs_1_19);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 20U, 36828, 36898, 2, 33,
                cond_starts_1_20, cond_ends_1_20, 3, postfix_exprs_1_20);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 21U, 42267, 42512, 2, 35,
                cond_starts_1_21, cond_ends_1_21, 3, postfix_exprs_1_21);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 22U, 44590, 44833, 2, 37,
                cond_starts_1_22, cond_ends_1_22, 3, postfix_exprs_1_22);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 23U, 46887, 47132, 2, 39,
                cond_starts_1_23, cond_ends_1_23, 3, postfix_exprs_1_23);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 24U, 49209, 49452, 2, 41,
                cond_starts_1_24, cond_ends_1_24, 3, postfix_exprs_1_24);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 25U, 52595, 52687, 1, 43,
                cond_starts_1_25, cond_ends_1_25, 2, postfix_exprs_1_25);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 26U, 53137, 53228, 1, 44,
                cond_starts_1_26, cond_ends_1_26, 2, postfix_exprs_1_26);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 27U, 53677, 53769, 1, 45,
                cond_starts_1_27, cond_ends_1_27, 2, postfix_exprs_1_27);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 28U, 54211, 54302, 1, 46,
                cond_starts_1_28, cond_ends_1_28, 2, postfix_exprs_1_28);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 29U, 54912, 54998, 1, 47,
                cond_starts_1_29, cond_ends_1_29, 2, postfix_exprs_1_29);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 30U, 55227, 55312, 1, 48,
                cond_starts_1_30, cond_ends_1_30, 2, postfix_exprs_1_30);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 31U, 55542, 55628, 1, 49,
                cond_starts_1_31, cond_ends_1_31, 2, postfix_exprs_1_31);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 32U, 55854, 55939, 1, 50,
                cond_starts_1_32, cond_ends_1_32, 2, postfix_exprs_1_32);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 33U, 56932, 57157, 2, 51,
                cond_starts_1_33, cond_ends_1_33, 3, postfix_exprs_1_33);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 34U, 59555, 59778, 2, 53,
                cond_starts_1_34, cond_ends_1_34, 3, postfix_exprs_1_34);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 35U, 62206, 62433, 2, 55,
                cond_starts_1_35, cond_ends_1_35, 3, postfix_exprs_1_35);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 36U, 64866, 65095, 2, 57,
                cond_starts_1_36, cond_ends_1_36, 3, postfix_exprs_1_36);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 37U, 67469, 67696, 2, 59,
                cond_starts_1_37, cond_ends_1_37, 3, postfix_exprs_1_37);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 38U, 70101, 70324, 2, 61,
                cond_starts_1_38, cond_ends_1_38, 3, postfix_exprs_1_38);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 39U, 73239, 73464, 2, 63,
                cond_starts_1_39, cond_ends_1_39, 3, postfix_exprs_1_39);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 40U, 75868, 76091, 2, 65,
                cond_starts_1_40, cond_ends_1_40, 3, postfix_exprs_1_40);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 41U, 78461, 78686, 2, 67,
                cond_starts_1_41, cond_ends_1_41, 3, postfix_exprs_1_41);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 42U, 81119, 81348, 2, 69,
                cond_starts_1_42, cond_ends_1_42, 3, postfix_exprs_1_42);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 43U, 83768, 83995, 2, 71,
                cond_starts_1_43, cond_ends_1_43, 3, postfix_exprs_1_43);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 44U, 86364, 86593, 2, 73,
                cond_starts_1_44, cond_ends_1_44, 3, postfix_exprs_1_44);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 45U, 89905, 90058, 3, 75,
                cond_starts_1_45, cond_ends_1_45, 5, postfix_exprs_1_45);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 46U, 90191, 90330, 2, 78,
                cond_starts_1_46, cond_ends_1_46, 3, postfix_exprs_1_46);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 47U, 90458, 90599, 2, 80,
                cond_starts_1_47, cond_ends_1_47, 3, postfix_exprs_1_47);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 48U, 90727, 90866, 2, 82,
                cond_starts_1_48, cond_ends_1_48, 3, postfix_exprs_1_48);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 49U, 90994, 91131, 2, 84,
                cond_starts_1_49, cond_ends_1_49, 3, postfix_exprs_1_49);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 50U, 91454, 91607, 3, 86,
                cond_starts_1_50, cond_ends_1_50, 5, postfix_exprs_1_50);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 51U, 91740, 91879, 2, 89,
                cond_starts_1_51, cond_ends_1_51, 3, postfix_exprs_1_51);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 52U, 92006, 92143, 2, 91,
                cond_starts_1_52, cond_ends_1_52, 3, postfix_exprs_1_52);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 53U, 92270, 92409, 2, 93,
                cond_starts_1_53, cond_ends_1_53, 3, postfix_exprs_1_53);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 54U, 92536, 92677, 2, 95,
                cond_starts_1_54, cond_ends_1_54, 3, postfix_exprs_1_54);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 55U, 116297, 116504, 5, 97,
                cond_starts_1_55, cond_ends_1_55, 9, postfix_exprs_1_55);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 56U, 116573, 116646, 2, 102,
                cond_starts_1_56, cond_ends_1_56, 3, postfix_exprs_1_56);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 57U, 123545, 123576, 2, 104,
                cond_starts_1_57, cond_ends_1_57, 3, postfix_exprs_1_57);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 58U, 127348, 127429, 2, 106,
                cond_starts_1_58, cond_ends_1_58, 3, postfix_exprs_1_58);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 59U, 131284, 131358, 2, 108,
                cond_starts_1_59, cond_ends_1_59, 3, postfix_exprs_1_59);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 60U, 131474, 131542, 2, 110,
                cond_starts_1_60, cond_ends_1_60, 3, postfix_exprs_1_60);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 61U, 131982, 132050, 2, 112,
                cond_starts_1_61, cond_ends_1_61, 3, postfix_exprs_1_61);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 3860, 3880, 4140);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 7048, 7061, 7216);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 7073, 7086, 7204);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 10601, 10625, 10798);
  covrtForInit(&emlrtCoverageInstance, 1U, 4U, 31082, 31109, 31186);
  covrtForInit(&emlrtCoverageInstance, 1U, 5U, 31255, 31284, 33806);
  covrtForInit(&emlrtCoverageInstance, 1U, 6U, 31917, 31942, 33790);
  covrtForInit(&emlrtCoverageInstance, 1U, 7U, 36783, 36809, 36977);
  covrtForInit(&emlrtCoverageInstance, 1U, 8U, 40941, 40967, 41456);
  covrtForInit(&emlrtCoverageInstance, 1U, 9U, 41592, 41621, 51414);
  covrtForInit(&emlrtCoverageInstance, 1U, 10U, 42115, 42140, 51398);
  covrtForInit(&emlrtCoverageInstance, 1U, 11U, 54860, 54880, 56144);
  covrtForInit(&emlrtCoverageInstance, 1U, 12U, 56335, 56360, 88978);
  covrtForInit(&emlrtCoverageInstance, 1U, 13U, 56837, 56858, 72641);
  covrtForInit(&emlrtCoverageInstance, 1U, 14U, 73104, 73125, 88966);
  covrtForInit(&emlrtCoverageInstance, 1U, 15U, 89772, 89794, 92935);
  covrtForInit(&emlrtCoverageInstance, 1U, 16U, 93599, 93611, 102467);
  covrtForInit(&emlrtCoverageInstance, 1U, 17U, 122455, 122469, 123743);
  covrtForInit(&emlrtCoverageInstance, 1U, 18U, 132620, 132632, 141247);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 1U, 0U, 3812, 3820, 4567);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 1U, 4621, 4629, 6088);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 2U, 9770, 9778, 14196);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 3U, 31193, 31201, 33909);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 4U, 36737, 36745, 40278);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 5U, 41530, 41538, 51501);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 6U, 56274, 56282, 89155);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 7U, 89717, 89725, 102585);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 8U, 115795, 115803, 128106);

  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 11430, 11473, 13729, 5U,
                  caseStarts_1_0, caseExprEnds_1_0);
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 1U, 38607, 38650, 39534, 5U,
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
