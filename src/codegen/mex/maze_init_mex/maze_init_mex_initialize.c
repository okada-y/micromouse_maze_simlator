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
  const int32_T cond_starts_1_0[1] = { 3831 };

  const int32_T cond_ends_1_0[1] = { 3853 };

  const int32_T postfix_exprs_1_0[2] = { 0, -1 };

  const int32_T cond_starts_1_1[1] = { 5741 };

  const int32_T cond_ends_1_1[1] = { 5763 };

  const int32_T postfix_exprs_1_1[2] = { 0, -1 };

  const int32_T cond_starts_1_2[1] = { 7359 };

  const int32_T cond_ends_1_2[1] = { 7381 };

  const int32_T postfix_exprs_1_2[2] = { 0, -1 };

  const int32_T cond_starts_1_3[1] = { 10292 };

  const int32_T cond_ends_1_3[1] = { 10314 };

  const int32_T postfix_exprs_1_3[2] = { 0, -1 };

  const int32_T cond_starts_1_4[2] = { 13625, 13665 };

  const int32_T cond_ends_1_4[2] = { 13659, 13699 };

  const int32_T postfix_exprs_1_4[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_5[1] = { 14310 };

  const int32_T cond_ends_1_5[1] = { 14332 };

  const int32_T postfix_exprs_1_5[2] = { 0, -1 };

  const int32_T cond_starts_1_6[1] = { 14752 };

  const int32_T cond_ends_1_6[1] = { 14774 };

  const int32_T postfix_exprs_1_6[2] = { 0, -1 };

  const int32_T cond_starts_1_7[1] = { 15925 };

  const int32_T cond_ends_1_7[1] = { 15947 };

  const int32_T postfix_exprs_1_7[2] = { 0, -1 };

  const int32_T cond_starts_1_8[1] = { 16414 };

  const int32_T cond_ends_1_8[1] = { 16436 };

  const int32_T postfix_exprs_1_8[2] = { 0, -1 };

  const int32_T cond_starts_1_9[1] = { 16930 };

  const int32_T cond_ends_1_9[1] = { 16952 };

  const int32_T postfix_exprs_1_9[2] = { 0, -1 };

  const int32_T cond_starts_1_10[1] = { 17540 };

  const int32_T cond_ends_1_10[1] = { 17562 };

  const int32_T postfix_exprs_1_10[2] = { 0, -1 };

  const int32_T cond_starts_1_11[1] = { 18165 };

  const int32_T cond_ends_1_11[1] = { 18187 };

  const int32_T postfix_exprs_1_11[2] = { 0, -1 };

  const int32_T cond_starts_1_12[1] = { 18774 };

  const int32_T cond_ends_1_12[1] = { 18796 };

  const int32_T postfix_exprs_1_12[2] = { 0, -1 };

  const int32_T cond_starts_1_13[1] = { 19365 };

  const int32_T cond_ends_1_13[1] = { 19387 };

  const int32_T postfix_exprs_1_13[2] = { 0, -1 };

  const int32_T cond_starts_1_14[1] = { 19974 };

  const int32_T cond_ends_1_14[1] = { 19996 };

  const int32_T postfix_exprs_1_14[2] = { 0, -1 };

  const int32_T cond_starts_1_15[2] = { 28923, 29063 };

  const int32_T cond_ends_1_15[2] = { 29038, 29176 };

  const int32_T postfix_exprs_1_15[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_16[2] = { 29241, 29352 };

  const int32_T cond_ends_1_16[2] = { 29324, 29467 };

  const int32_T postfix_exprs_1_16[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_17[2] = { 30162, 30274 };

  const int32_T cond_ends_1_17[2] = { 30246, 30391 };

  const int32_T postfix_exprs_1_17[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_18[2] = { 31111, 31251 };

  const int32_T cond_ends_1_18[2] = { 31226, 31364 };

  const int32_T postfix_exprs_1_18[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_19[2] = { 31416, 31527 };

  const int32_T cond_ends_1_19[2] = { 31499, 31642 };

  const int32_T postfix_exprs_1_19[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_20[2] = { 32350, 32462 };

  const int32_T cond_ends_1_20[2] = { 32434, 32579 };

  const int32_T postfix_exprs_1_20[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_21[2] = { 33273, 33411 };

  const int32_T cond_ends_1_21[2] = { 33386, 33526 };

  const int32_T postfix_exprs_1_21[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_22[2] = { 33578, 33689 };

  const int32_T cond_ends_1_22[2] = { 33661, 33804 };

  const int32_T postfix_exprs_1_22[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_23[2] = { 34499, 34611 };

  const int32_T cond_ends_1_23[2] = { 34583, 34728 };

  const int32_T postfix_exprs_1_23[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_24[2] = { 35430, 35568 };

  const int32_T cond_ends_1_24[2] = { 35543, 35683 };

  const int32_T postfix_exprs_1_24[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_25[2] = { 35735, 35846 };

  const int32_T cond_ends_1_25[2] = { 35818, 35961 };

  const int32_T postfix_exprs_1_25[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_26[2] = { 36664, 36776 };

  const int32_T cond_ends_1_26[2] = { 36748, 36893 };

  const int32_T postfix_exprs_1_26[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_27[2] = { 43578, 43606 };

  const int32_T cond_ends_1_27[2] = { 43601, 43621 };

  const int32_T postfix_exprs_1_27[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_28[2] = { 49864, 49892 };

  const int32_T cond_ends_1_28[2] = { 49887, 49907 };

  const int32_T postfix_exprs_1_28[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_29[2] = { 50354, 50391 };

  const int32_T cond_ends_1_29[2] = { 50386, 50422 };

  const int32_T postfix_exprs_1_29[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_30[2] = { 55492, 55520 };

  const int32_T cond_ends_1_30[2] = { 55515, 55566 };

  const int32_T postfix_exprs_1_30[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_31[1] = { 58366 };

  const int32_T cond_ends_1_31[1] = { 58375 };

  const int32_T postfix_exprs_1_31[2] = { 0, -1 };

  const int32_T cond_starts_1_32[2] = { 58736, 58770 };

  const int32_T cond_ends_1_32[2] = { 58764, 58798 };

  const int32_T postfix_exprs_1_32[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_33[1] = { 59056 };

  const int32_T cond_ends_1_33[1] = { 59078 };

  const int32_T postfix_exprs_1_33[2] = { 0, -1 };

  const int32_T cond_starts_1_34[1] = { 59563 };

  const int32_T cond_ends_1_34[1] = { 59585 };

  const int32_T postfix_exprs_1_34[2] = { 0, -1 };

  const int32_T cond_starts_1_35[1] = { 62694 };

  const int32_T cond_ends_1_35[1] = { 62716 };

  const int32_T postfix_exprs_1_35[2] = { 0, -1 };

  const int32_T cond_starts_1_36[1] = { 63472 };

  const int32_T cond_ends_1_36[1] = { 63494 };

  const int32_T postfix_exprs_1_36[2] = { 0, -1 };

  const int32_T cond_starts_1_37[1] = { 63956 };

  const int32_T cond_ends_1_37[1] = { 63978 };

  const int32_T postfix_exprs_1_37[2] = { 0, -1 };

  const int32_T cond_starts_1_38[1] = { 64731 };

  const int32_T cond_ends_1_38[1] = { 64753 };

  const int32_T postfix_exprs_1_38[2] = { 0, -1 };

  const int32_T cond_starts_1_39[1] = { 65231 };

  const int32_T cond_ends_1_39[1] = { 65253 };

  const int32_T postfix_exprs_1_39[2] = { 0, -1 };

  const int32_T cond_starts_1_40[1] = { 66026 };

  const int32_T cond_ends_1_40[1] = { 66048 };

  const int32_T postfix_exprs_1_40[2] = { 0, -1 };

  const int32_T cond_starts_1_41[3] = { 69614, 69780, 69931 };

  const int32_T cond_ends_1_41[3] = { 69751, 69925, 69947 };

  const int32_T postfix_exprs_1_41[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_42[3] = { 72433, 72597, 72746 };

  const int32_T cond_ends_1_42[3] = { 72569, 72741, 72762 };

  const int32_T postfix_exprs_1_42[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_43[3] = { 75761, 75926, 76076 };

  const int32_T cond_ends_1_43[3] = { 75898, 76071, 76092 };

  const int32_T postfix_exprs_1_43[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_44[3] = { 78794, 78958, 79107 };

  const int32_T cond_ends_1_44[3] = { 78930, 79102, 79123 };

  const int32_T postfix_exprs_1_44[6] = { 0, 1, 2, -1, -2, -3 };

  const int32_T cond_starts_1_45[2] = { 81843, 81864 };

  const int32_T cond_ends_1_45[2] = { 81859, 81895 };

  const int32_T postfix_exprs_1_45[3] = { 0, 1, -2 };

  const int32_T cond_starts_1_46[1] = { 83575 };

  const int32_T cond_ends_1_46[1] = { 83666 };

  const int32_T postfix_exprs_1_46[2] = { 0, -1 };

  const int32_T cond_starts_1_47[1] = { 84246 };

  const int32_T cond_ends_1_47[1] = { 84336 };

  const int32_T postfix_exprs_1_47[2] = { 0, -1 };

  const int32_T cond_starts_1_48[1] = { 84915 };

  const int32_T cond_ends_1_48[1] = { 85006 };

  const int32_T postfix_exprs_1_48[2] = { 0, -1 };

  const int32_T cond_starts_1_49[1] = { 85578 };

  const int32_T cond_ends_1_49[1] = { 85668 };

  const int32_T postfix_exprs_1_49[2] = { 0, -1 };

  const int32_T cond_starts_1_50[1] = { 86416 };

  const int32_T cond_ends_1_50[1] = { 86501 };

  const int32_T postfix_exprs_1_50[2] = { 0, -1 };

  const int32_T cond_starts_1_51[1] = { 86978 };

  const int32_T cond_ends_1_51[1] = { 87062 };

  const int32_T postfix_exprs_1_51[2] = { 0, -1 };

  const int32_T cond_starts_1_52[1] = { 87539 };

  const int32_T cond_ends_1_52[1] = { 87624 };

  const int32_T postfix_exprs_1_52[2] = { 0, -1 };

  const int32_T cond_starts_1_53[1] = { 88095 };

  const int32_T cond_ends_1_53[1] = { 88179 };

  const int32_T postfix_exprs_1_53[2] = { 0, -1 };

  const int32_T cond_starts_1_54[2] = { 89067, 89227 };

  const int32_T cond_ends_1_54[2] = { 89200, 89368 };

  const int32_T postfix_exprs_1_54[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_55[2] = { 92787, 92946 };

  const int32_T cond_ends_1_55[2] = { 92919, 93086 };

  const int32_T postfix_exprs_1_55[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_56[2] = { 96567, 96728 };

  const int32_T cond_ends_1_56[2] = { 96701, 96870 };

  const int32_T postfix_exprs_1_56[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_57[2] = { 100347, 100509 };

  const int32_T cond_ends_1_57[2] = { 100482, 100652 };

  const int32_T postfix_exprs_1_57[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_58[2] = { 104121, 104282 };

  const int32_T cond_ends_1_58[2] = { 104255, 104424 };

  const int32_T postfix_exprs_1_58[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_59[2] = { 107874, 108033 };

  const int32_T cond_ends_1_59[2] = { 108006, 108173 };

  const int32_T postfix_exprs_1_59[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_60[2] = { 111762, 111922 };

  const int32_T cond_ends_1_60[2] = { 111895, 112063 };

  const int32_T postfix_exprs_1_60[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_61[2] = { 115487, 115646 };

  const int32_T cond_ends_1_61[2] = { 115619, 115786 };

  const int32_T postfix_exprs_1_61[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_62[2] = { 119196, 119356 };

  const int32_T cond_ends_1_62[2] = { 119329, 119497 };

  const int32_T postfix_exprs_1_62[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_63[2] = { 122921, 123083 };

  const int32_T cond_ends_1_63[2] = { 123056, 123226 };

  const int32_T postfix_exprs_1_63[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_64[2] = { 126625, 126786 };

  const int32_T cond_ends_1_64[2] = { 126759, 126928 };

  const int32_T postfix_exprs_1_64[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_65[2] = { 130292, 130454 };

  const int32_T cond_ends_1_65[2] = { 130427, 130597 };

  const int32_T postfix_exprs_1_65[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_66[3] = { 135401, 135476, 135513 };

  const int32_T cond_ends_1_66[3] = { 135434, 135509, 135548 };

  const int32_T postfix_exprs_1_66[5] = { 0, 1, 2, -2, -3 };

  const int32_T cond_starts_1_67[2] = { 135670, 135749 };

  const int32_T cond_ends_1_67[2] = { 135714, 135805 };

  const int32_T postfix_exprs_1_67[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_68[2] = { 135925, 136004 };

  const int32_T cond_ends_1_68[2] = { 135969, 136062 };

  const int32_T postfix_exprs_1_68[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_69[2] = { 136182, 136261 };

  const int32_T cond_ends_1_69[2] = { 136226, 136317 };

  const int32_T postfix_exprs_1_69[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_70[2] = { 136437, 136516 };

  const int32_T cond_ends_1_70[2] = { 136481, 136570 };

  const int32_T postfix_exprs_1_70[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_71[3] = { 136834, 136871, 136948 };

  const int32_T cond_ends_1_71[3] = { 136867, 136906, 136981 };

  const int32_T postfix_exprs_1_71[5] = { 0, 1, -2, 2, -3 };

  const int32_T cond_starts_1_72[2] = { 137103, 137182 };

  const int32_T cond_ends_1_72[2] = { 137147, 137238 };

  const int32_T postfix_exprs_1_72[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_73[2] = { 137357, 137436 };

  const int32_T cond_ends_1_73[2] = { 137401, 137490 };

  const int32_T postfix_exprs_1_73[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_74[2] = { 137609, 137688 };

  const int32_T cond_ends_1_74[2] = { 137653, 137744 };

  const int32_T postfix_exprs_1_74[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_75[2] = { 137863, 137942 };

  const int32_T cond_ends_1_75[2] = { 137907, 138000 };

  const int32_T postfix_exprs_1_75[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_76[5] = { 159505, 159538, 159607, 159650, 159682 };

  const int32_T cond_ends_1_76[5] = { 159533, 159577, 159646, 159678, 159710 };

  const int32_T postfix_exprs_1_76[9] = { 0, 1, -3, 2, 3, -3, 4, -3, -2 };

  const int32_T cond_starts_1_77[2] = { 159780, 159813 };

  const int32_T cond_ends_1_77[2] = { 159808, 159852 };

  const int32_T postfix_exprs_1_77[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_78[2] = { 167135, 167160 };

  const int32_T cond_ends_1_78[2] = { 167156, 167166 };

  const int32_T postfix_exprs_1_78[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_79[2] = { 170948, 170985 };

  const int32_T cond_ends_1_79[2] = { 170980, 171028 };

  const int32_T postfix_exprs_1_79[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_80[2] = { 174899, 174935 };

  const int32_T cond_ends_1_80[2] = { 174931, 174973 };

  const int32_T postfix_exprs_1_80[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_81[2] = { 175077, 175113 };

  const int32_T cond_ends_1_81[2] = { 175109, 175145 };

  const int32_T postfix_exprs_1_81[3] = { 0, 1, -3 };

  const int32_T cond_starts_1_82[2] = { 175545, 175581 };

  const int32_T cond_ends_1_82[2] = { 175577, 175613 };

  const int32_T postfix_exprs_1_82[3] = { 0, 1, -3 };

  const int32_T caseStarts_1_0[3] = { 8471, 5472, 6750 };

  const int32_T caseExprEnds_1_0[3] = { 8480, 5496, 6776 };

  const int32_T caseStarts_1_1[5] = { 20455, 15218, 16813, 18019, 19249 };

  const int32_T caseExprEnds_1_1[5] = { 20464, 15240, 16835, 18040, 19270 };

  const int32_T caseStarts_1_2[5] = { 66350, 61825, 62534, 63797, 65072 };

  const int32_T caseExprEnds_1_2[5] = { 66359, 61847, 62556, 63818, 65093 };

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
                  "C:\\work\\matlab\\maze_sim_git\\src\\maze_solve.m", 1U, 31U,
                  462U, 577U, 0U, 0U, 3U, 24U, 6U, 144U, 83U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "maze_solve", 0, -1, 213015);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 1U, "search_adachi", 11696, -1, 21470);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 2U, "move_step", 21514, -1, 22084);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 3U, "turn_180deg", 22125, -1, 22262);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 4U, "turn_clk_90deg", 22310, -1,
               22448);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 5U, "turn_conclk_90deg", 22497, -1,
               22635);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 6U, "wall_set", 22668, -1, 37569);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 7U, "make_new_goal_all", 37623, -1,
               43698);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 8U, "make_new_goal_sh", 43764, -1,
               50581);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 9U, "sh_route_unexp_sq_jud", 50038,
               -1, 50568);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 10U, "make_map_find", 50633, -1,
               55637);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 11U, "get_nextdir2", 55686, -1, 57134);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 12U, "fust_run", 57172, -1, 67277);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 13U, "fust_run_wallset", 67301, -1,
               67863);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 14U, "make_map_fustrun", 67908, -1,
               81942);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 15U, "make_map_fustrun_diagonal",
               82000, -1, 134691);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 16U, "decide_goal_node_dir", 134796,
               -1, 146824);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 17U, "decide_goal_section", 146916,
               -1, 157917);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 18U, "goal_judge", 157598, -1, 157909);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 19U, "make_route_diagonal", 157970,
               -1, 174501);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 20U, "get_turn_pattern_num", 171765,
               -1, 174493);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 21U, "get_next_dir_diagonal", 174550,
               -1, 183637);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 22U, "move_straight", 183669, -1,
               190447);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 23U, "turn_r_45", 190463, -1, 193564);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 24U, "turn_l_45", 193585, -1, 196686);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 25U, "turn_r_90", 196707, -1, 199814);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 26U, "turn_l_90", 199835, -1, 202941);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 27U, "turn_r_135", 202963, -1, 206079);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 28U, "turn_l_135", 206101, -1, 209216);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 29U, "turn_r_180", 209238, -1, 211111);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 30U, "turn_l_180", 211133, -1, 213006);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 31U, 10792, -1, 11625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 30U, 10433, -1, 10641);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 29U, 10327, -1, 10411);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 28U, 9523, -1, 10257);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 27U, 9333, -1, 9347);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 26U, 9196, -1, 9260);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 25U, 8597, -1, 9113);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 23U, 8418, -1, 8438);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 21U, 7535, -1, 7540);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 20U, 7406, -1, 7489);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 22U, 7611, -1, 8335);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 19U, 6875, -1, 7215);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 18U, 6659, -1, 6679);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 16U, 5917, -1, 5922);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 15U, 5788, -1, 5871);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 17U, 6000, -1, 6558);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 14U, 5533, -1, 5634);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 24U, 8513, -1, 8533);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 12U, 4881, -1, 5247);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 13U, 5287, -1, 5292);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 4695, -1, 4812);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 4603, -1, 4654);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 4539, -1, 4561);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 3960, -1, 4484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 3862, -1, 3946);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 3612, -1, 3804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 3219, -1, 3525);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 3047, -1, 3130);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 1373, -1, 2981);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 1134, -1, 1207);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 696, -1, 879);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 319, -1, 679);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 44U, 14970, -1, 14975);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 43U, 14795, -1, 14878);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 42U, 14491, -1, 14641);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 41U, 14353, -1, 14453);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 69U, 21227, -1, 21260);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 68U, 21056, -1, 21137);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 67U, 20869, -1, 21005);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 66U, 20703, -1, 20834);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 65U, 20580, -1, 20653);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 64U, 20162, -1, 20424);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 63U, 20017, -1, 20096);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 62U, 19611, -1, 19902);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 61U, 19465, -1, 19565);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 60U, 18962, -1, 19218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 59U, 18817, -1, 18896);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 58U, 18411, -1, 18702);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 57U, 18265, -1, 18365);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 56U, 17729, -1, 17988);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 55U, 17583, -1, 17663);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 54U, 17176, -1, 17467);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 53U, 17030, -1, 17130);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 52U, 16638, -1, 16737);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 51U, 16465, -1, 16545);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 50U, 16132, -1, 16321);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 49U, 15976, -1, 16078);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 48U, 15685, -1, 15720);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 47U, 15468, -1, 15534);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 46U, 15337, -1, 15397);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 45U, 15044, -1, 15118);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 40U, 14088, -1, 14134);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 39U, 13878, -1, 13897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 38U, 13717, -1, 13736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 37U, 13433, -1, 13524);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 36U, 13258, -1, 13331);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 35U, 13144, -1, 13168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 34U, 13037, -1, 13059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 33U, 12711, -1, 12903);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 32U, 12105, -1, 12534);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 73U, 22018, -1, 22035);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 72U, 21903, -1, 21920);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 71U, 21788, -1, 21805);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 70U, 21673, -1, 21690);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 74U, 22210, -1, 22248);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 75U, 22396, -1, 22434);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 76U, 22581, -1, 22621);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 102U, 36949, -1, 37524);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 101U, 36017, -1, 36596);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 100U, 34784, -1, 35359);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 99U, 33860, -1, 34431);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 98U, 32635, -1, 33202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 97U, 31698, -1, 32269);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 96U, 30447, -1, 31014);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 95U, 29523, -1, 30094);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 94U, 28681, -1, 28818);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 93U, 28329, -1, 28644);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 92U, 27948, -1, 28267);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 91U, 27571, -1, 27886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 90U, 27181, -1, 27500);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 89U, 25705, -1, 27094);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 88U, 25533, -1, 25666);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 87U, 25359, -1, 25410);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 86U, 25232, -1, 25294);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 85U, 24931, -1, 24997);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 84U, 24759, -1, 24892);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 83U, 24581, -1, 24634);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 82U, 24454, -1, 24516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 81U, 24189, -1, 24253);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 80U, 24010, -1, 24141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 79U, 23832, -1, 23885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 78U, 23707, -1, 23767);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 77U, 23176, -1, 23406);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 114U, 43659, -1, 43664);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 113U, 43301, -1, 43522);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 106U, 39644, -1, 39747);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 105U, 39009, -1, 39448);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 108U, 40791, -1, 40894);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 107U, 40156, -1, 40595);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 110U, 41939, -1, 42042);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 109U, 41304, -1, 41743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 112U, 43086, -1, 43189);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 111U, 42451, -1, 42890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 104U, 38561, -1, 38583);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 103U, 37759, -1, 38411);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 126U, 49945, -1, 49950);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 125U, 49587, -1, 49808);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 118U, 45831, -1, 45934);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 117U, 45159, -1, 45598);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 120U, 47011, -1, 47114);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 119U, 46343, -1, 46782);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 122U, 48192, -1, 48295);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 121U, 47524, -1, 47963);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 124U, 49372, -1, 49475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 123U, 48704, -1, 49143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 116U, 44711, -1, 44733);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 115U, 43910, -1, 44562);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 128U, 50448, -1, 50496);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 127U, 50147, -1, 50164);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 137U, 55603, -1, 55608);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 136U, 55223, -1, 55444);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 135U, 54708, -1, 55134);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 134U, 53872, -1, 54298);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 133U, 53035, -1, 53461);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 132U, 52201, -1, 52625);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 131U, 51629, -1, 51651);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 130U, 51303, -1, 51516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 129U, 50821, -1, 51241);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 142U, 57078, -1, 57105);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 141U, 56745, -1, 56830);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 140U, 56466, -1, 56550);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 139U, 56167, -1, 56277);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 138U, 55845, -1, 55894);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 178U, 67135, -1, 67168);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 151U, 59740, -1, 59745);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 150U, 59606, -1, 59689);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 149U, 59423, -1, 59448);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 148U, 59289, -1, 59350);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 147U, 59103, -1, 59203);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 177U, 67009, -1, 67057);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 176U, 66749, -1, 66925);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 175U, 66538, -1, 66714);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 174U, 66238, -1, 66299);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 173U, 66073, -1, 66152);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 172U, 65694, -1, 65919);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 171U, 65630, -1, 65656);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 170U, 65480, -1, 65545);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 169U, 65282, -1, 65382);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 168U, 64943, -1, 65004);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 167U, 64778, -1, 64857);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 166U, 64418, -1, 64637);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 165U, 64355, -1, 64380);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 164U, 64205, -1, 64270);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 163U, 64007, -1, 64107);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 162U, 63685, -1, 63746);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 161U, 63519, -1, 63599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 160U, 63156, -1, 63378);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 159U, 63093, -1, 63118);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 158U, 62943, -1, 63008);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 157U, 62745, -1, 62845);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 156U, 61885, -1, 62073);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 155U, 60988, -1, 61070);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 154U, 60690, -1, 60773);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 153U, 60392, -1, 60474);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 152U, 60065, -1, 60177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 146U, 58816, -1, 58836);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 145U, 58519, -1, 58635);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 144U, 58246, -1, 58278);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 143U, 57492, -1, 58128);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 182U, 67806, -1, 67842);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 181U, 67651, -1, 67687);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 180U, 67496, -1, 67532);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 179U, 67372, -1, 67391);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 195U, 81908, -1, 81913);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 194U, 81570, -1, 81791);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 193U, 80735, -1, 81457);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 192U, 79590, -1, 80306);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 191U, 77909, -1, 78632);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 190U, 76788, -1, 77505);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 189U, 74877, -1, 75599);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 188U, 73457, -1, 74173);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 187U, 71536, -1, 72259);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 186U, 70415, -1, 71132);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 185U, 69403, -1, 69425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 184U, 68835, -1, 69311);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 183U, 68141, -1, 68718);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 256U, 134591, -1, 134662);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 255U, 134036, -1, 134504);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 254U, 133717, -1, 133913);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 253U, 132704, -1, 133431);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 252U, 132109, -1, 132305);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 251U, 131063, -1, 131794);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 250U, 129969, -1, 130155);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 249U, 128971, -1, 129686);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 248U, 128390, -1, 128576);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 247U, 127384, -1, 128103);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 246U, 126297, -1, 126489);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 245U, 125292, -1, 126013);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 244U, 124703, -1, 124895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 243U, 123690, -1, 124415);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 242U, 122565, -1, 122753);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 241U, 121568, -1, 122283);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 240U, 120964, -1, 121152);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 239U, 119959, -1, 120678);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 238U, 118852, -1, 119038);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 237U, 117854, -1, 118569);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 236U, 117273, -1, 117459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 235U, 116242, -1, 116961);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 234U, 115159, -1, 115351);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 233U, 114129, -1, 114850);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 232U, 113540, -1, 113732);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 231U, 112527, -1, 113252);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 230U, 111270, -1, 111458);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 229U, 110248, -1, 110963);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 228U, 109665, -1, 109853);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 227U, 108635, -1, 109354);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 226U, 107545, -1, 107737);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 225U, 106515, -1, 107236);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 224U, 105926, -1, 106118);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 223U, 104888, -1, 105613);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 222U, 103797, -1, 103984);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 221U, 102773, -1, 103489);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 220U, 102166, -1, 102353);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 219U, 101109, -1, 101854);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 218U, 100015, -1, 100211);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 217U, 98977, -1, 99704);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 216U, 98382, -1, 98578);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 215U, 97336, -1, 98067);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 214U, 96207, -1, 96399);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 213U, 95177, -1, 95898);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 212U, 94588, -1, 94780);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 211U, 93550, -1, 94275);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 210U, 92463, -1, 92650);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 209U, 91439, -1, 92155);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 208U, 90857, -1, 91044);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 207U, 89825, -1, 90545);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 206U, 88863, -1, 88885);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 205U, 88218, -1, 88587);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 204U, 87663, -1, 88032);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 203U, 87101, -1, 87476);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 202U, 86540, -1, 86915);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 201U, 85699, -1, 86192);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 200U, 85037, -1, 85531);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 199U, 84367, -1, 84868);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 198U, 83697, -1, 84199);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 197U, 83480, -1, 83511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 196U, 82275, -1, 83448);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 269U, 138761, -1, 138766);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 283U, 146708, -1, 146782);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 282U, 146189, -1, 146555);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 281U, 145593, -1, 145948);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 280U, 144998, -1, 145360);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 279U, 144319, -1, 144677);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 278U, 143727, -1, 144082);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 277U, 143132, -1, 143494);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 276U, 142379, -1, 142736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 275U, 141700, -1, 142061);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 274U, 141105, -1, 141461);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 273U, 140506, -1, 140871);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 272U, 139823, -1, 140184);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 271U, 139228, -1, 139584);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 270U, 138906, -1, 138940);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 268U, 138133, -1, 138153);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 267U, 138025, -1, 138062);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 266U, 137769, -1, 137806);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 265U, 137515, -1, 137552);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 264U, 137263, -1, 137300);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 263U, 136725, -1, 136745);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 262U, 136595, -1, 136633);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 261U, 136342, -1, 136380);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 260U, 136087, -1, 136125);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 259U, 135830, -1, 135868);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 258U, 135251, -1, 135271);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 257U, 134941, -1, 135220);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 324U, 157357, -1, 157516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 323U, 157161, -1, 157322);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 322U, 156909, -1, 157074);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 321U, 156655, -1, 156820);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 320U, 156384, -1, 156541);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 319U, 156188, -1, 156349);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 318U, 155942, -1, 156101);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 317U, 155690, -1, 155855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 316U, 155325, -1, 155484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 315U, 155129, -1, 155290);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 314U, 154752, -1, 154911);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 313U, 154556, -1, 154717);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 312U, 154306, -1, 154469);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 311U, 154052, -1, 154217);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 310U, 153779, -1, 153938);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 309U, 153583, -1, 153744);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 308U, 153333, -1, 153496);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 307U, 153079, -1, 153244);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 306U, 152714, -1, 152873);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 305U, 152518, -1, 152679);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 304U, 152162, -1, 152319);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 303U, 151966, -1, 152127);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 302U, 151720, -1, 151879);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 301U, 151468, -1, 151633);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 300U, 151195, -1, 151354);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 299U, 150999, -1, 151160);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 298U, 150747, -1, 150912);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 297U, 150493, -1, 150658);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 296U, 150130, -1, 150287);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 295U, 149934, -1, 150095);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 294U, 149559, -1, 149716);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 293U, 149363, -1, 149524);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 292U, 149115, -1, 149276);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 291U, 148863, -1, 149028);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 290U, 148592, -1, 148749);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 289U, 148396, -1, 148557);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 288U, 148148, -1, 148309);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 287U, 147896, -1, 148061);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 286U, 147513, -1, 147670);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 285U, 147317, -1, 147478);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 284U, 147042, -1, 147145);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 325U, 157679, -1, 157883);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 356U, 171387, -1, 171392);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 357U, 171463, -1, 171655);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 355U, 171124, -1, 171288);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 354U, 171046, -1, 171059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 353U, 170579, -1, 170758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 352U, 170206, -1, 170385);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 351U, 169832, -1, 170011);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 350U, 169459, -1, 169638);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 349U, 169086, -1, 169264);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 348U, 168499, -1, 168677);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 347U, 167910, -1, 168088);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 346U, 167540, -1, 167718);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 344U, 166766, -1, 166771);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 343U, 166621, -1, 166720);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 345U, 166847, -1, 167054);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 342U, 166235, -1, 166427);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 341U, 165917, -1, 165945);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 340U, 165475, -1, 165686);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 339U, 165299, -1, 165398);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 338U, 165020, -1, 165033);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 337U, 164548, -1, 164767);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 336U, 164348, -1, 164447);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 335U, 163577, -1, 163767);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 334U, 163123, -1, 163313);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 333U, 162344, -1, 162443);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 332U, 161867, -1, 162227);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 331U, 161416, -1, 161639);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 330U, 161204, -1, 161303);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 329U, 160274, -1, 160606);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 328U, 159921, -1, 160125);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 327U, 159250, -1, 159458);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 326U, 158099, -1, 158957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 372U, 174230, -1, 174267);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 371U, 174117, -1, 174153);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 370U, 173961, -1, 173997);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 369U, 173803, -1, 173840);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 368U, 173690, -1, 173726);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 367U, 173534, -1, 173570);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 366U, 173234, -1, 173271);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 365U, 173112, -1, 173149);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 364U, 172944, -1, 172980);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 363U, 172831, -1, 172867);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 362U, 172581, -1, 172618);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 361U, 172459, -1, 172496);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 360U, 172291, -1, 172327);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 359U, 172178, -1, 172214);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 358U, 171898, -1, 171937);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 391U, 183120, -1, 183481);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 390U, 182464, -1, 182814);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 389U, 181809, -1, 182166);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 388U, 181126, -1, 181459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 387U, 180579, -1, 180909);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 386U, 180029, -1, 180366);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 385U, 179340, -1, 179673);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 384U, 178713, -1, 179050);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 383U, 178163, -1, 178494);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 382U, 177608, -1, 177949);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 381U, 176977, -1, 177314);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 380U, 176427, -1, 176758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 379U, 176129, -1, 176163);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 378U, 176040, -1, 176063);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 377U, 175810, -1, 175957);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 376U, 175630, -1, 175775);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 375U, 175324, -1, 175472);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 374U, 175162, -1, 175289);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 373U, 174759, -1, 174860);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 405U, 190413, -1, 190438);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 404U, 189717, -1, 189984);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 403U, 189344, -1, 189623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 402U, 188657, -1, 188930);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 401U, 188290, -1, 188563);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 400U, 187597, -1, 187876);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 399U, 187236, -1, 187503);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 398U, 186549, -1, 186822);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 397U, 186182, -1, 186455);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 396U, 185907, -1, 186044);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 395U, 185271, -1, 185497);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 394U, 184850, -1, 185077);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 393U, 184430, -1, 184656);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 392U, 184009, -1, 184236);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 413U, 193074, -1, 193290);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 412U, 192774, -1, 192987);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 411U, 192475, -1, 192687);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 410U, 192175, -1, 192388);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 409U, 191674, -1, 191895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 408U, 191374, -1, 191593);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 407U, 191073, -1, 191292);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 406U, 190771, -1, 190992);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 421U, 196201, -1, 196412);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 420U, 195900, -1, 196114);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 419U, 195598, -1, 195813);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 418U, 195297, -1, 195511);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 417U, 194798, -1, 195017);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 416U, 194496, -1, 194717);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 415U, 194193, -1, 194414);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 414U, 193893, -1, 194112);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 429U, 199329, -1, 199548);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 428U, 199023, -1, 199242);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 427U, 198717, -1, 198936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 426U, 198411, -1, 198630);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 425U, 197901, -1, 198117);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 424U, 197607, -1, 197820);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 423U, 197311, -1, 197525);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 422U, 197015, -1, 197230);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 437U, 202457, -1, 202676);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 436U, 202151, -1, 202370);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 435U, 201845, -1, 202064);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 434U, 201539, -1, 201758);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 433U, 201031, -1, 201245);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 432U, 200735, -1, 200950);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 431U, 200437, -1, 200653);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 430U, 200143, -1, 200356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 445U, 205591, -1, 205804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 444U, 205290, -1, 205504);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 443U, 204990, -1, 205203);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 442U, 204689, -1, 204903);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 441U, 204179, -1, 204400);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 440U, 203877, -1, 204098);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 439U, 203574, -1, 203795);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 438U, 203272, -1, 203493);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 453U, 208728, -1, 208942);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 452U, 208428, -1, 208641);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 451U, 208127, -1, 208341);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 450U, 207827, -1, 208040);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 449U, 207317, -1, 207538);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 448U, 207015, -1, 207236);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 447U, 206712, -1, 206933);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 446U, 206410, -1, 206631);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 457U, 210438, -1, 210653);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 456U, 210141, -1, 210357);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 455U, 209844, -1, 210059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 454U, 209547, -1, 209763);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 461U, 212333, -1, 212548);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 460U, 212036, -1, 212252);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 459U, 211739, -1, 211954);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 458U, 211442, -1, 211658);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 284, 309, 310, 684);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 1104, 1129, -1, 1212);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 2989, 3021, 9366, 9404);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 3141, 3166, 3558, 3589);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 3827, 3853, -1, 3955);
  covrtIfInit(&emlrtCoverageInstance, 1U, 5U, 4668, 4678, 4837, 4840);
  covrtIfInit(&emlrtCoverageInstance, 1U, 6U, 4849, 4868, 5270, 5304);
  covrtIfInit(&emlrtCoverageInstance, 1U, 7U, 5652, 5672, 5975, 6592);
  covrtIfInit(&emlrtCoverageInstance, 1U, 8U, 5737, 5763, -1, 5896);
  covrtIfInit(&emlrtCoverageInstance, 1U, 9U, 7266, 7290, 8362, 8365);
  covrtIfInit(&emlrtCoverageInstance, 1U, 10U, 7355, 7381, -1, 7514);
  covrtIfInit(&emlrtCoverageInstance, 1U, 11U, 9124, 9149, 9266, 9307);
  covrtIfInit(&emlrtCoverageInstance, 1U, 12U, 9366, 9404, -1, 9404);
  covrtIfInit(&emlrtCoverageInstance, 1U, 13U, 9409, 9451, 10684, 10730);
  covrtIfInit(&emlrtCoverageInstance, 1U, 14U, 10288, 10314, -1, 10424);
  covrtIfInit(&emlrtCoverageInstance, 1U, 15U, 10684, 10730, -1, 10730);
  covrtIfInit(&emlrtCoverageInstance, 1U, 16U, 12601, 12623, 13105, 13194);
  covrtIfInit(&emlrtCoverageInstance, 1U, 17U, 12672, 12694, -1, 13096);
  covrtIfInit(&emlrtCoverageInstance, 1U, 18U, 12965, 13016, -1, 13080);
  covrtIfInit(&emlrtCoverageInstance, 1U, 19U, 13220, 13245, -1, 13344);
  covrtIfInit(&emlrtCoverageInstance, 1U, 20U, 13405, 13420, -1, 13537);
  covrtIfInit(&emlrtCoverageInstance, 1U, 21U, 13621, 13700, -1, 13753);
  covrtIfInit(&emlrtCoverageInstance, 1U, 22U, 13820, 13865, -1, 14182);
  covrtIfInit(&emlrtCoverageInstance, 1U, 23U, 13995, 14067, -1, 14154);
  covrtIfInit(&emlrtCoverageInstance, 1U, 24U, 14216, 14232, -1, 14987);
  covrtIfInit(&emlrtCoverageInstance, 1U, 25U, 14268, 14289, -1, 14658);
  covrtIfInit(&emlrtCoverageInstance, 1U, 26U, 14306, 14332, -1, 14474);
  covrtIfInit(&emlrtCoverageInstance, 1U, 27U, 14671, 14687, -1, 14915);
  covrtIfInit(&emlrtCoverageInstance, 1U, 28U, 14748, 14774, -1, 14899);
  covrtIfInit(&emlrtCoverageInstance, 1U, 29U, 15295, 15316, -1, 15418);
  covrtIfInit(&emlrtCoverageInstance, 1U, 30U, 15618, 15664, 15765, 16782);
  covrtIfInit(&emlrtCoverageInstance, 1U, 31U, 15875, 15896, 16368, 16762);
  covrtIfInit(&emlrtCoverageInstance, 1U, 32U, 15921, 15947, -1, 16107);
  covrtIfInit(&emlrtCoverageInstance, 1U, 33U, 16410, 16436, -1, 16574);
  covrtIfInit(&emlrtCoverageInstance, 1U, 34U, 16884, 16905, -1, 17488);
  covrtIfInit(&emlrtCoverageInstance, 1U, 35U, 16926, 16952, -1, 17155);
  covrtIfInit(&emlrtCoverageInstance, 1U, 36U, 17536, 17562, -1, 17684);
  covrtIfInit(&emlrtCoverageInstance, 1U, 37U, 18119, 18140, -1, 18723);
  covrtIfInit(&emlrtCoverageInstance, 1U, 38U, 18161, 18187, -1, 18390);
  covrtIfInit(&emlrtCoverageInstance, 1U, 39U, 18770, 18796, -1, 18917);
  covrtIfInit(&emlrtCoverageInstance, 1U, 40U, 19319, 19340, -1, 19923);
  covrtIfInit(&emlrtCoverageInstance, 1U, 41U, 19361, 19387, -1, 19590);
  covrtIfInit(&emlrtCoverageInstance, 1U, 42U, 19970, 19996, -1, 20117);
  covrtIfInit(&emlrtCoverageInstance, 1U, 43U, 20494, 20519, 21405, 21454);
  covrtIfInit(&emlrtCoverageInstance, 1U, 44U, 20667, 20686, 20848, 21022);
  covrtIfInit(&emlrtCoverageInstance, 1U, 45U, 21152, 21177, -1, 21396);
  covrtIfInit(&emlrtCoverageInstance, 1U, 46U, 21194, 21206, 21306, 21380);
  covrtIfInit(&emlrtCoverageInstance, 1U, 47U, 21632, 21664, -1, 21727);
  covrtIfInit(&emlrtCoverageInstance, 1U, 48U, 21748, 21779, -1, 21841);
  covrtIfInit(&emlrtCoverageInstance, 1U, 49U, 21862, 21894, -1, 21957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 50U, 21978, 22009, -1, 22071);
  covrtIfInit(&emlrtCoverageInstance, 1U, 51U, 23508, 23533, 23785, 24171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 52U, 23591, 23666, -1, 23780);
  covrtIfInit(&emlrtCoverageInstance, 1U, 53U, 23921, 23978, -1, 24154);
  covrtIfInit(&emlrtCoverageInstance, 1U, 54U, 24274, 24299, 24534, 24913);
  covrtIfInit(&emlrtCoverageInstance, 1U, 55U, 24357, 24441, -1, 24529);
  covrtIfInit(&emlrtCoverageInstance, 1U, 56U, 24670, 24727, -1, 24905);
  covrtIfInit(&emlrtCoverageInstance, 1U, 57U, 25052, 25077, 25312, 25687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 58U, 25135, 25219, -1, 25307);
  covrtIfInit(&emlrtCoverageInstance, 1U, 59U, 25446, 25501, -1, 25679);
  covrtIfInit(&emlrtCoverageInstance, 1U, 60U, 27142, 27172, -1, 27509);
  covrtIfInit(&emlrtCoverageInstance, 1U, 61U, 27532, 27562, -1, 27895);
  covrtIfInit(&emlrtCoverageInstance, 1U, 62U, 27923, 27939, -1, 28276);
  covrtIfInit(&emlrtCoverageInstance, 1U, 63U, 28304, 28320, -1, 28653);
  covrtIfInit(&emlrtCoverageInstance, 1U, 64U, 28824, 28832, -1, 37561);
  covrtIfInit(&emlrtCoverageInstance, 1U, 65U, 28919, 29177, -1, 31069);
  covrtIfInit(&emlrtCoverageInstance, 1U, 66U, 29238, 29468, -1, 30111);
  covrtIfInit(&emlrtCoverageInstance, 1U, 67U, 30159, 30392, -1, 31031);
  covrtIfInit(&emlrtCoverageInstance, 1U, 68U, 31107, 31365, -1, 33231);
  covrtIfInit(&emlrtCoverageInstance, 1U, 69U, 31413, 31643, -1, 32286);
  covrtIfInit(&emlrtCoverageInstance, 1U, 70U, 32347, 32580, -1, 33219);
  covrtIfInit(&emlrtCoverageInstance, 1U, 71U, 33269, 33527, -1, 35388);
  covrtIfInit(&emlrtCoverageInstance, 1U, 72U, 33575, 33805, -1, 34448);
  covrtIfInit(&emlrtCoverageInstance, 1U, 73U, 34496, 34729, -1, 35376);
  covrtIfInit(&emlrtCoverageInstance, 1U, 74U, 35426, 35684, -1, 37553);
  covrtIfInit(&emlrtCoverageInstance, 1U, 75U, 35732, 35962, -1, 36613);
  covrtIfInit(&emlrtCoverageInstance, 1U, 76U, 36661, 36894, -1, 37541);
  covrtIfInit(&emlrtCoverageInstance, 1U, 77U, 38701, 38834, -1, 39807);
  covrtIfInit(&emlrtCoverageInstance, 1U, 78U, 38899, 38988, -1, 39791);
  covrtIfInit(&emlrtCoverageInstance, 1U, 79U, 39533, 39619, -1, 39771);
  covrtIfInit(&emlrtCoverageInstance, 1U, 80U, 39849, 39981, -1, 40954);
  covrtIfInit(&emlrtCoverageInstance, 1U, 81U, 40046, 40135, -1, 40938);
  covrtIfInit(&emlrtCoverageInstance, 1U, 82U, 40680, 40766, -1, 40918);
  covrtIfInit(&emlrtCoverageInstance, 1U, 83U, 40996, 41129, -1, 42102);
  covrtIfInit(&emlrtCoverageInstance, 1U, 84U, 41194, 41283, -1, 42086);
  covrtIfInit(&emlrtCoverageInstance, 1U, 85U, 41828, 41914, -1, 42066);
  covrtIfInit(&emlrtCoverageInstance, 1U, 86U, 42144, 42276, -1, 43249);
  covrtIfInit(&emlrtCoverageInstance, 1U, 87U, 42341, 42430, -1, 43233);
  covrtIfInit(&emlrtCoverageInstance, 1U, 88U, 42975, 43061, -1, 43213);
  covrtIfInit(&emlrtCoverageInstance, 1U, 89U, 43575, 43621, -1, 43677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 90U, 44851, 44984, -1, 45994);
  covrtIfInit(&emlrtCoverageInstance, 1U, 91U, 45049, 45138, -1, 45978);
  covrtIfInit(&emlrtCoverageInstance, 1U, 92U, 45687, 45806, -1, 45958);
  covrtIfInit(&emlrtCoverageInstance, 1U, 93U, 46036, 46168, -1, 47174);
  covrtIfInit(&emlrtCoverageInstance, 1U, 94U, 46233, 46322, -1, 47158);
  covrtIfInit(&emlrtCoverageInstance, 1U, 95U, 46867, 46986, -1, 47138);
  covrtIfInit(&emlrtCoverageInstance, 1U, 96U, 47216, 47349, -1, 48355);
  covrtIfInit(&emlrtCoverageInstance, 1U, 97U, 47414, 47503, -1, 48339);
  covrtIfInit(&emlrtCoverageInstance, 1U, 98U, 48048, 48167, -1, 48319);
  covrtIfInit(&emlrtCoverageInstance, 1U, 99U, 48397, 48529, -1, 49535);
  covrtIfInit(&emlrtCoverageInstance, 1U, 100U, 48594, 48683, -1, 49519);
  covrtIfInit(&emlrtCoverageInstance, 1U, 101U, 49228, 49347, -1, 49499);
  covrtIfInit(&emlrtCoverageInstance, 1U, 102U, 49861, 49907, -1, 49963);
  covrtIfInit(&emlrtCoverageInstance, 1U, 103U, 50178, 50207, 50220, 50556);
  covrtIfInit(&emlrtCoverageInstance, 1U, 104U, 50350, 50423, -1, 50520);
  covrtIfInit(&emlrtCoverageInstance, 1U, 105U, 51869, 52026, -1, 52662);
  covrtIfInit(&emlrtCoverageInstance, 1U, 106U, 52091, 52180, -1, 52646);
  covrtIfInit(&emlrtCoverageInstance, 1U, 107U, 52704, 52860, -1, 53498);
  covrtIfInit(&emlrtCoverageInstance, 1U, 108U, 52925, 53014, -1, 53482);
  covrtIfInit(&emlrtCoverageInstance, 1U, 109U, 53540, 53697, -1, 54335);
  covrtIfInit(&emlrtCoverageInstance, 1U, 110U, 53762, 53851, -1, 54319);
  covrtIfInit(&emlrtCoverageInstance, 1U, 111U, 54377, 54533, -1, 55171);
  covrtIfInit(&emlrtCoverageInstance, 1U, 112U, 54598, 54687, -1, 55155);
  covrtIfInit(&emlrtCoverageInstance, 1U, 113U, 55489, 55566, -1, 55621);
  covrtIfInit(&emlrtCoverageInstance, 1U, 114U, 55958, 56041, -1, 56298);
  covrtIfInit(&emlrtCoverageInstance, 1U, 115U, 56079, 56125, -1, 56290);
  covrtIfInit(&emlrtCoverageInstance, 1U, 116U, 56316, 56398, -1, 56571);
  covrtIfInit(&emlrtCoverageInstance, 1U, 117U, 56407, 56453, -1, 56563);
  covrtIfInit(&emlrtCoverageInstance, 1U, 118U, 56594, 56677, -1, 56851);
  covrtIfInit(&emlrtCoverageInstance, 1U, 119U, 56686, 56732, -1, 56843);
  covrtIfInit(&emlrtCoverageInstance, 1U, 120U, 56869, 56951, -1, 57126);
  covrtIfInit(&emlrtCoverageInstance, 1U, 121U, 56960, 57006, -1, 57118);
  covrtIfInit(&emlrtCoverageInstance, 1U, 122U, 58182, 58207, -1, 58287);
  covrtIfInit(&emlrtCoverageInstance, 1U, 123U, 58362, 58376, -1, 58664);
  covrtIfInit(&emlrtCoverageInstance, 1U, 124U, 58416, 58456, -1, 58652);
  covrtIfInit(&emlrtCoverageInstance, 1U, 125U, 58732, 58799, -1, 58853);
  covrtIfInit(&emlrtCoverageInstance, 1U, 126U, 58883, 58900, -1, 59757);
  covrtIfInit(&emlrtCoverageInstance, 1U, 127U, 58943, 58964, -1, 59465);
  covrtIfInit(&emlrtCoverageInstance, 1U, 128U, 58997, 59011, -1, 59371);
  covrtIfInit(&emlrtCoverageInstance, 1U, 129U, 59052, 59078, -1, 59228);
  covrtIfInit(&emlrtCoverageInstance, 1U, 130U, 59508, 59522, -1, 59726);
  covrtIfInit(&emlrtCoverageInstance, 1U, 131U, 59559, 59585, -1, 59710);
  covrtIfInit(&emlrtCoverageInstance, 1U, 132U, 59842, 59929, -1, 60206);
  covrtIfInit(&emlrtCoverageInstance, 1U, 133U, 59975, 60015, -1, 60194);
  covrtIfInit(&emlrtCoverageInstance, 1U, 134U, 60236, 60322, -1, 60503);
  covrtIfInit(&emlrtCoverageInstance, 1U, 135U, 60335, 60375, -1, 60491);
  covrtIfInit(&emlrtCoverageInstance, 1U, 136U, 60533, 60620, -1, 60802);
  covrtIfInit(&emlrtCoverageInstance, 1U, 137U, 60633, 60673, -1, 60790);
  covrtIfInit(&emlrtCoverageInstance, 1U, 138U, 60832, 60918, -1, 61099);
  covrtIfInit(&emlrtCoverageInstance, 1U, 139U, 60931, 60971, -1, 61087);
  covrtIfInit(&emlrtCoverageInstance, 1U, 140U, 62573, 62594, -1, 63139);
  covrtIfInit(&emlrtCoverageInstance, 1U, 141U, 62631, 62645, -1, 63033);
  covrtIfInit(&emlrtCoverageInstance, 1U, 142U, 62690, 62716, -1, 62874);
  covrtIfInit(&emlrtCoverageInstance, 1U, 143U, 63413, 63427, -1, 63767);
  covrtIfInit(&emlrtCoverageInstance, 1U, 144U, 63468, 63494, -1, 63624);
  covrtIfInit(&emlrtCoverageInstance, 1U, 145U, 63835, 63856, -1, 64401);
  covrtIfInit(&emlrtCoverageInstance, 1U, 146U, 63893, 63907, -1, 64295);
  covrtIfInit(&emlrtCoverageInstance, 1U, 147U, 63952, 63978, -1, 64136);
  covrtIfInit(&emlrtCoverageInstance, 1U, 148U, 64672, 64686, -1, 65025);
  covrtIfInit(&emlrtCoverageInstance, 1U, 149U, 64727, 64753, -1, 64882);
  covrtIfInit(&emlrtCoverageInstance, 1U, 150U, 65110, 65131, -1, 65677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 151U, 65168, 65182, -1, 65570);
  covrtIfInit(&emlrtCoverageInstance, 1U, 152U, 65227, 65253, -1, 65411);
  covrtIfInit(&emlrtCoverageInstance, 1U, 153U, 65967, 65981, -1, 66320);
  covrtIfInit(&emlrtCoverageInstance, 1U, 154U, 66022, 66048, -1, 66177);
  covrtIfInit(&emlrtCoverageInstance, 1U, 155U, 66389, 66414, 66951, 67000);
  covrtIfInit(&emlrtCoverageInstance, 1U, 156U, 66499, 66521, 66728, 66942);
  covrtIfInit(&emlrtCoverageInstance, 1U, 157U, 67076, 67101, -1, 67264);
  covrtIfInit(&emlrtCoverageInstance, 1U, 158U, 67110, 67122, 67198, 67256);
  covrtIfInit(&emlrtCoverageInstance, 1U, 159U, 67412, 67483, -1, 67545);
  covrtIfInit(&emlrtCoverageInstance, 1U, 160U, 67565, 67638, -1, 67700);
  covrtIfInit(&emlrtCoverageInstance, 1U, 161U, 67720, 67793, -1, 67855);
  covrtIfInit(&emlrtCoverageInstance, 1U, 162U, 69611, 69948, -1, 72320);
  covrtIfInit(&emlrtCoverageInstance, 1U, 163U, 70014, 70142, 71232, 72304);
  covrtIfInit(&emlrtCoverageInstance, 1U, 164U, 70207, 70357, -1, 71157);
  covrtIfInit(&emlrtCoverageInstance, 1U, 165U, 71306, 71470, -1, 72284);
  covrtIfInit(&emlrtCoverageInstance, 1U, 166U, 72430, 72763, -1, 75660);
  covrtIfInit(&emlrtCoverageInstance, 1U, 167U, 72829, 72956, 74273, 75644);
  covrtIfInit(&emlrtCoverageInstance, 1U, 168U, 73021, 73171, -1, 74198);
  covrtIfInit(&emlrtCoverageInstance, 1U, 169U, 74347, 74511, -1, 75624);
  covrtIfInit(&emlrtCoverageInstance, 1U, 170U, 75758, 76093, -1, 78693);
  covrtIfInit(&emlrtCoverageInstance, 1U, 171U, 76159, 76287, 77605, 78677);
  covrtIfInit(&emlrtCoverageInstance, 1U, 172U, 76352, 76502, -1, 77530);
  covrtIfInit(&emlrtCoverageInstance, 1U, 173U, 77679, 77843, -1, 78657);
  covrtIfInit(&emlrtCoverageInstance, 1U, 174U, 78791, 79124, -1, 81518);
  covrtIfInit(&emlrtCoverageInstance, 1U, 175U, 79190, 79317, 80431, 81502);
  covrtIfInit(&emlrtCoverageInstance, 1U, 176U, 79382, 79532, -1, 80356);
  covrtIfInit(&emlrtCoverageInstance, 1U, 177U, 80505, 80669, -1, 81482);
  covrtIfInit(&emlrtCoverageInstance, 1U, 178U, 81839, 81895, -1, 81926);
  covrtIfInit(&emlrtCoverageInstance, 1U, 179U, 83454, 83471, 86247, 88779);
  covrtIfInit(&emlrtCoverageInstance, 1U, 180U, 83571, 83666, -1, 84212);
  covrtIfInit(&emlrtCoverageInstance, 1U, 181U, 84242, 84336, -1, 84881);
  covrtIfInit(&emlrtCoverageInstance, 1U, 182U, 84911, 85006, -1, 85544);
  covrtIfInit(&emlrtCoverageInstance, 1U, 183U, 85574, 85668, -1, 86205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 184U, 86412, 86501, -1, 86932);
  covrtIfInit(&emlrtCoverageInstance, 1U, 185U, 86974, 87062, -1, 87493);
  covrtIfInit(&emlrtCoverageInstance, 1U, 186U, 87535, 87624, -1, 88049);
  covrtIfInit(&emlrtCoverageInstance, 1U, 187U, 88091, 88179, -1, 88604);
  covrtIfInit(&emlrtCoverageInstance, 1U, 188U, 89064, 89368, -1, 92711);
  covrtIfInit(&emlrtCoverageInstance, 1U, 189U, 89417, 89543, 91144, 92695);
  covrtIfInit(&emlrtCoverageInstance, 1U, 190U, 89609, 89767, 90636, 90799);
  covrtIfInit(&emlrtCoverageInstance, 1U, 191U, 90636, 90799, -1, 90799);
  covrtIfInit(&emlrtCoverageInstance, 1U, 192U, 91219, 91373, 92246, 92405);
  covrtIfInit(&emlrtCoverageInstance, 1U, 193U, 92246, 92405, -1, 92405);
  covrtIfInit(&emlrtCoverageInstance, 1U, 194U, 92784, 93086, -1, 96460);
  covrtIfInit(&emlrtCoverageInstance, 1U, 195U, 93136, 93267, 94881, 96444);
  covrtIfInit(&emlrtCoverageInstance, 1U, 196U, 93334, 93492, 94367, 94530);
  covrtIfInit(&emlrtCoverageInstance, 1U, 197U, 94367, 94530, -1, 94530);
  covrtIfInit(&emlrtCoverageInstance, 1U, 198U, 94957, 95111, 95990, 96149);
  covrtIfInit(&emlrtCoverageInstance, 1U, 199U, 95990, 96149, -1, 96149);
  covrtIfInit(&emlrtCoverageInstance, 1U, 200U, 96564, 96870, -1, 100272);
  covrtIfInit(&emlrtCoverageInstance, 1U, 201U, 96920, 97051, 98679, 100256);
  covrtIfInit(&emlrtCoverageInstance, 1U, 202U, 97118, 97278, 98159, 98324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 203U, 98159, 98324, -1, 98324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 204U, 98755, 98911, 99796, 99957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 205U, 99796, 99957, -1, 99957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 206U, 100344, 100652, -1, 104045);
  covrtIfInit(&emlrtCoverageInstance, 1U, 207U, 100701, 100827, 102453, 104029);
  covrtIfInit(&emlrtCoverageInstance, 1U, 208U, 100893, 101051, 101945, 102108);
  covrtIfInit(&emlrtCoverageInstance, 1U, 209U, 101945, 102108, -1, 102108);
  covrtIfInit(&emlrtCoverageInstance, 1U, 210U, 102528, 102682, 103580, 103739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 211U, 103580, 103739, -1, 103739);
  covrtIfInit(&emlrtCoverageInstance, 1U, 212U, 104118, 104424, -1, 107798);
  covrtIfInit(&emlrtCoverageInstance, 1U, 213U, 104474, 104605, 106219, 107782);
  covrtIfInit(&emlrtCoverageInstance, 1U, 214U, 104672, 104830, 105705, 105868);
  covrtIfInit(&emlrtCoverageInstance, 1U, 215U, 105705, 105868, -1, 105868);
  covrtIfInit(&emlrtCoverageInstance, 1U, 216U, 106295, 106449, 107328, 107487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 217U, 107328, 107487, -1, 107487);
  covrtIfInit(&emlrtCoverageInstance, 1U, 218U, 107871, 108173, -1, 111519);
  covrtIfInit(&emlrtCoverageInstance, 1U, 219U, 108223, 108354, 109954, 111503);
  covrtIfInit(&emlrtCoverageInstance, 1U, 220U, 108421, 108577, 109446, 109607);
  covrtIfInit(&emlrtCoverageInstance, 1U, 221U, 109446, 109607, -1, 109607);
  covrtIfInit(&emlrtCoverageInstance, 1U, 222U, 110030, 110182, 111055, 111212);
  covrtIfInit(&emlrtCoverageInstance, 1U, 223U, 111055, 111212, -1, 111212);
  covrtIfInit(&emlrtCoverageInstance, 1U, 224U, 111759, 112063, -1, 115412);
  covrtIfInit(&emlrtCoverageInstance, 1U, 225U, 112113, 112244, 113833, 115396);
  covrtIfInit(&emlrtCoverageInstance, 1U, 226U, 112311, 112469, 113319, 113482);
  covrtIfInit(&emlrtCoverageInstance, 1U, 227U, 113319, 113482, -1, 113482);
  covrtIfInit(&emlrtCoverageInstance, 1U, 228U, 113909, 114063, 114942, 115101);
  covrtIfInit(&emlrtCoverageInstance, 1U, 229U, 114942, 115101, -1, 115101);
  covrtIfInit(&emlrtCoverageInstance, 1U, 230U, 115484, 115786, -1, 119120);
  covrtIfInit(&emlrtCoverageInstance, 1U, 231U, 115835, 115960, 117559, 119104);
  covrtIfInit(&emlrtCoverageInstance, 1U, 232U, 116026, 116184, 117052, 117215);
  covrtIfInit(&emlrtCoverageInstance, 1U, 233U, 117052, 117215, -1, 117215);
  covrtIfInit(&emlrtCoverageInstance, 1U, 234U, 117634, 117788, 118635, 118794);
  covrtIfInit(&emlrtCoverageInstance, 1U, 235U, 118635, 118794, -1, 118794);
  covrtIfInit(&emlrtCoverageInstance, 1U, 236U, 119193, 119497, -1, 122814);
  covrtIfInit(&emlrtCoverageInstance, 1U, 237U, 119547, 119678, 121274, 122798);
  covrtIfInit(&emlrtCoverageInstance, 1U, 238U, 119745, 119901, 120745, 120906);
  covrtIfInit(&emlrtCoverageInstance, 1U, 239U, 120745, 120906, -1, 120906);
  covrtIfInit(&emlrtCoverageInstance, 1U, 240U, 121350, 121502, 122350, 122507);
  covrtIfInit(&emlrtCoverageInstance, 1U, 241U, 122350, 122507, -1, 122507);
  covrtIfInit(&emlrtCoverageInstance, 1U, 242U, 122918, 123226, -1, 126550);
  covrtIfInit(&emlrtCoverageInstance, 1U, 243U, 123276, 123407, 124996, 126534);
  covrtIfInit(&emlrtCoverageInstance, 1U, 244U, 123474, 123632, 124482, 124645);
  covrtIfInit(&emlrtCoverageInstance, 1U, 245U, 124482, 124645, -1, 124645);
  covrtIfInit(&emlrtCoverageInstance, 1U, 246U, 125072, 125226, 126080, 126239);
  covrtIfInit(&emlrtCoverageInstance, 1U, 247U, 126080, 126239, -1, 126239);
  covrtIfInit(&emlrtCoverageInstance, 1U, 248U, 126622, 126928, -1, 130216);
  covrtIfInit(&emlrtCoverageInstance, 1U, 249U, 126977, 127102, 128676, 130200);
  covrtIfInit(&emlrtCoverageInstance, 1U, 250U, 127168, 127326, 128169, 128332);
  covrtIfInit(&emlrtCoverageInstance, 1U, 251U, 128169, 128332, -1, 128332);
  covrtIfInit(&emlrtCoverageInstance, 1U, 252U, 128751, 128905, 129752, 129911);
  covrtIfInit(&emlrtCoverageInstance, 1U, 253U, 129752, 129911, -1, 129911);
  covrtIfInit(&emlrtCoverageInstance, 1U, 254U, 130289, 130597, -1, 133974);
  covrtIfInit(&emlrtCoverageInstance, 1U, 255U, 130647, 130778, 132406, 133958);
  covrtIfInit(&emlrtCoverageInstance, 1U, 256U, 130845, 131005, 131886, 132051);
  covrtIfInit(&emlrtCoverageInstance, 1U, 257U, 131886, 132051, -1, 132051);
  covrtIfInit(&emlrtCoverageInstance, 1U, 258U, 132482, 132638, 133498, 133659);
  covrtIfInit(&emlrtCoverageInstance, 1U, 259U, 133498, 133659, -1, 133659);
  covrtIfInit(&emlrtCoverageInstance, 1U, 260U, 134559, 134578, -1, 134675);
  covrtIfInit(&emlrtCoverageInstance, 1U, 261U, 135341, 135380, 136809, 138190);
  covrtIfInit(&emlrtCoverageInstance, 1U, 262U, 135397, 135549, -1, 136766);
  covrtIfInit(&emlrtCoverageInstance, 1U, 263U, 135667, 135805, 135918, 136062);
  covrtIfInit(&emlrtCoverageInstance, 1U, 264U, 135918, 136062, 136175, 136658);
  covrtIfInit(&emlrtCoverageInstance, 1U, 265U, 136175, 136317, 136430, 136658);
  covrtIfInit(&emlrtCoverageInstance, 1U, 266U, 136430, 136570, -1, 136570);
  covrtIfInit(&emlrtCoverageInstance, 1U, 267U, 136830, 136982, -1, 138174);
  covrtIfInit(&emlrtCoverageInstance, 1U, 268U, 137100, 137238, 137350, 137490);
  covrtIfInit(&emlrtCoverageInstance, 1U, 269U, 137350, 137490, 137602, 138087);
  covrtIfInit(&emlrtCoverageInstance, 1U, 270U, 137602, 137744, 137856, 138087);
  covrtIfInit(&emlrtCoverageInstance, 1U, 271U, 137856, 138000, -1, 138000);
  covrtIfInit(&emlrtCoverageInstance, 1U, 272U, 138565, 138582, 138812, 146808);
  covrtIfInit(&emlrtCoverageInstance, 1U, 273U, 138988, 139027, 142840, 146649);
  covrtIfInit(&emlrtCoverageInstance, 1U, 274U, 139048, 139078, 139634, 139673);
  covrtIfInit(&emlrtCoverageInstance, 1U, 275U, 139103, 139163, -1, 139613);
  covrtIfInit(&emlrtCoverageInstance, 1U, 276U, 139634, 139673, 140234, 142789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 277U, 139698, 139758, -1, 140213);
  covrtIfInit(&emlrtCoverageInstance, 1U, 278U, 140234, 140267, 140315, 142789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 279U, 140315, 140354, 140921, 142789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 280U, 140379, 140441, -1, 140900);
  covrtIfInit(&emlrtCoverageInstance, 1U, 281U, 140921, 140955, 141511, 142789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 282U, 140980, 141040, -1, 141490);
  covrtIfInit(&emlrtCoverageInstance, 1U, 283U, 141511, 141550, 142111, 142789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 284U, 141575, 141635, -1, 142090);
  covrtIfInit(&emlrtCoverageInstance, 1U, 285U, 142111, 142144, 142192, 142789);
  covrtIfInit(&emlrtCoverageInstance, 1U, 286U, 142192, 142231, -1, 142231);
  covrtIfInit(&emlrtCoverageInstance, 1U, 287U, 142256, 142314, -1, 142765);
  covrtIfInit(&emlrtCoverageInstance, 1U, 288U, 142865, 142895, 142943, 142982);
  covrtIfInit(&emlrtCoverageInstance, 1U, 289U, 142943, 142982, 143544, 146608);
  covrtIfInit(&emlrtCoverageInstance, 1U, 290U, 143007, 143067, -1, 143523);
  covrtIfInit(&emlrtCoverageInstance, 1U, 291U, 143544, 143577, 144132, 146608);
  covrtIfInit(&emlrtCoverageInstance, 1U, 292U, 143602, 143662, -1, 144111);
  covrtIfInit(&emlrtCoverageInstance, 1U, 293U, 144132, 144171, 144727, 146608);
  covrtIfInit(&emlrtCoverageInstance, 1U, 294U, 144196, 144254, -1, 144706);
  covrtIfInit(&emlrtCoverageInstance, 1U, 295U, 144727, 144761, 144809, 146608);
  covrtIfInit(&emlrtCoverageInstance, 1U, 296U, 144809, 144848, 145410, 146608);
  covrtIfInit(&emlrtCoverageInstance, 1U, 297U, 144873, 144933, -1, 145389);
  covrtIfInit(&emlrtCoverageInstance, 1U, 298U, 145410, 145443, 145998, 146608);
  covrtIfInit(&emlrtCoverageInstance, 1U, 299U, 145468, 145528, -1, 145977);
  covrtIfInit(&emlrtCoverageInstance, 1U, 300U, 145998, 146037, -1, 146037);
  covrtIfInit(&emlrtCoverageInstance, 1U, 301U, 146062, 146124, -1, 146584);
  covrtIfInit(&emlrtCoverageInstance, 1U, 302U, 147156, 147190, 147724, 147767);
  covrtIfInit(&emlrtCoverageInstance, 1U, 303U, 147199, 147235, -1, 147699);
  covrtIfInit(&emlrtCoverageInstance, 1U, 304U, 147248, 147300, 147492, 147687);
  covrtIfInit(&emlrtCoverageInstance, 1U, 305U, 147724, 147767, 149750, 157566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 306U, 147776, 147812, 148775, 149745);
  covrtIfInit(&emlrtCoverageInstance, 1U, 307U, 147825, 147879, 148075, 148766);
  covrtIfInit(&emlrtCoverageInstance, 1U, 308U, 148075, 148131, 148323, 148766);
  covrtIfInit(&emlrtCoverageInstance, 1U, 309U, 148323, 148379, 148571, 148766);
  covrtIfInit(&emlrtCoverageInstance, 1U, 310U, 148792, 148846, 149042, 149733);
  covrtIfInit(&emlrtCoverageInstance, 1U, 311U, 149042, 149098, 149290, 149733);
  covrtIfInit(&emlrtCoverageInstance, 1U, 312U, 149290, 149346, 149538, 149733);
  covrtIfInit(&emlrtCoverageInstance, 1U, 313U, 149750, 149787, 150321, 157566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 314U, 149816, 149852, -1, 150316);
  covrtIfInit(&emlrtCoverageInstance, 1U, 315U, 149865, 149917, 150109, 150304);
  covrtIfInit(&emlrtCoverageInstance, 1U, 316U, 150321, 150364, 152353, 157566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 317U, 150373, 150409, 151380, 152348);
  covrtIfInit(&emlrtCoverageInstance, 1U, 318U, 150422, 150476, 150672, 151371);
  covrtIfInit(&emlrtCoverageInstance, 1U, 319U, 150672, 150730, 150926, 151371);
  covrtIfInit(&emlrtCoverageInstance, 1U, 320U, 150926, 150982, 151174, 151371);
  covrtIfInit(&emlrtCoverageInstance, 1U, 321U, 151397, 151451, 151647, 152336);
  covrtIfInit(&emlrtCoverageInstance, 1U, 322U, 151647, 151703, 151893, 152336);
  covrtIfInit(&emlrtCoverageInstance, 1U, 323U, 151893, 151949, 152141, 152336);
  covrtIfInit(&emlrtCoverageInstance, 1U, 324U, 152353, 152391, 152907, 157566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 325U, 152400, 152436, -1, 152902);
  covrtIfInit(&emlrtCoverageInstance, 1U, 326U, 152449, 152501, 152693, 152890);
  covrtIfInit(&emlrtCoverageInstance, 1U, 327U, 152907, 152950, 154945, 157566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 328U, 152959, 152995, 153964, 154940);
  covrtIfInit(&emlrtCoverageInstance, 1U, 329U, 153008, 153062, 153258, 153955);
  covrtIfInit(&emlrtCoverageInstance, 1U, 330U, 153258, 153316, 153510, 153955);
  covrtIfInit(&emlrtCoverageInstance, 1U, 331U, 153510, 153566, 153758, 153955);
  covrtIfInit(&emlrtCoverageInstance, 1U, 332U, 153981, 154035, 154231, 154928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 333U, 154231, 154289, 154483, 154928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 334U, 154483, 154539, 154731, 154928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 335U, 154945, 154982, 155518, 157566);
  covrtIfInit(&emlrtCoverageInstance, 1U, 336U, 155011, 155047, -1, 155513);
  covrtIfInit(&emlrtCoverageInstance, 1U, 337U, 155060, 155112, 155304, 155501);
  covrtIfInit(&emlrtCoverageInstance, 1U, 338U, 155518, 155561, -1, 155561);
  covrtIfInit(&emlrtCoverageInstance, 1U, 339U, 155570, 155606, 156567, 157558);
  covrtIfInit(&emlrtCoverageInstance, 1U, 340U, 155619, 155673, 155869, 156558);
  covrtIfInit(&emlrtCoverageInstance, 1U, 341U, 155869, 155925, 156115, 156558);
  covrtIfInit(&emlrtCoverageInstance, 1U, 342U, 156115, 156171, 156363, 156558);
  covrtIfInit(&emlrtCoverageInstance, 1U, 343U, 156584, 156638, 156834, 157533);
  covrtIfInit(&emlrtCoverageInstance, 1U, 344U, 156834, 156892, 157088, 157533);
  covrtIfInit(&emlrtCoverageInstance, 1U, 345U, 157088, 157144, 157336, 157533);
  covrtIfInit(&emlrtCoverageInstance, 1U, 346U, 159168, 159200, 165111, 171314);
  covrtIfInit(&emlrtCoverageInstance, 1U, 347U, 159501, 159711, -1, 165050);
  covrtIfInit(&emlrtCoverageInstance, 1U, 348U, 159776, 159854, 164088, 164812);
  covrtIfInit(&emlrtCoverageInstance, 1U, 349U, 160180, 160212, 160857, 164034);
  covrtIfInit(&emlrtCoverageInstance, 1U, 350U, 161059, 161080, -1, 161668);
  covrtIfInit(&emlrtCoverageInstance, 1U, 351U, 161146, 161171, -1, 161336);
  covrtIfInit(&emlrtCoverageInstance, 1U, 352U, 162290, 162315, -1, 162472);
  covrtIfInit(&emlrtCoverageInstance, 1U, 353U, 162541, 162565, -1, 162854);
  covrtIfInit(&emlrtCoverageInstance, 1U, 354U, 162594, 162619, -1, 162826);
  covrtIfInit(&emlrtCoverageInstance, 1U, 355U, 162917, 162957, 163368, 164010);
  covrtIfInit(&emlrtCoverageInstance, 1U, 356U, 162986, 163011, -1, 163094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 357U, 163368, 163412, 163793, 164010);
  covrtIfInit(&emlrtCoverageInstance, 1U, 358U, 163441, 163466, -1, 163548);
  covrtIfInit(&emlrtCoverageInstance, 1U, 359U, 163826, 163851, -1, 163982);
  covrtIfInit(&emlrtCoverageInstance, 1U, 360U, 164215, 164236, -1, 164792);
  covrtIfInit(&emlrtCoverageInstance, 1U, 361U, 164294, 164319, -1, 164476);
  covrtIfInit(&emlrtCoverageInstance, 1U, 362U, 165190, 165211, -1, 165864);
  covrtIfInit(&emlrtCoverageInstance, 1U, 363U, 165253, 165278, -1, 165419);
  covrtIfInit(&emlrtCoverageInstance, 1U, 364U, 166494, 166518, 166789, 167075);
  covrtIfInit(&emlrtCoverageInstance, 1U, 365U, 166571, 166596, -1, 166745);
  covrtIfInit(&emlrtCoverageInstance, 1U, 366U, 167132, 167166, -1, 167316);
  covrtIfInit(&emlrtCoverageInstance, 1U, 367U, 167187, 167212, -1, 167296);
  covrtIfInit(&emlrtCoverageInstance, 1U, 368U, 167382, 167422, 167749, 167793);
  covrtIfInit(&emlrtCoverageInstance, 1U, 369U, 167439, 167464, -1, 167523);
  covrtIfInit(&emlrtCoverageInstance, 1U, 370U, 167749, 167793, 168119, 170775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 371U, 167810, 167835, -1, 167893);
  covrtIfInit(&emlrtCoverageInstance, 1U, 372U, 168119, 168163, 168708, 170775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 373U, 168180, 168205, -1, 168482);
  covrtIfInit(&emlrtCoverageInstance, 1U, 374U, 168226, 168276, 168340, 168394);
  covrtIfInit(&emlrtCoverageInstance, 1U, 375U, 168340, 168394, -1, 168394);
  covrtIfInit(&emlrtCoverageInstance, 1U, 376U, 168708, 168752, 169295, 170775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 377U, 168769, 168794, -1, 169069);
  covrtIfInit(&emlrtCoverageInstance, 1U, 378U, 168815, 168865, 168928, 168982);
  covrtIfInit(&emlrtCoverageInstance, 1U, 379U, 168928, 168982, -1, 168982);
  covrtIfInit(&emlrtCoverageInstance, 1U, 380U, 169295, 169340, 169669, 170775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 381U, 169357, 169382, -1, 169442);
  covrtIfInit(&emlrtCoverageInstance, 1U, 382U, 169669, 169714, 170042, 170775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 383U, 169731, 169756, -1, 169815);
  covrtIfInit(&emlrtCoverageInstance, 1U, 384U, 170042, 170087, 170416, 170775);
  covrtIfInit(&emlrtCoverageInstance, 1U, 385U, 170104, 170129, -1, 170189);
  covrtIfInit(&emlrtCoverageInstance, 1U, 386U, 170416, 170461, -1, 170461);
  covrtIfInit(&emlrtCoverageInstance, 1U, 387U, 170478, 170503, -1, 170562);
  covrtIfInit(&emlrtCoverageInstance, 1U, 388U, 170945, 171029, -1, 171076);
  covrtIfInit(&emlrtCoverageInstance, 1U, 389U, 171357, 171374, -1, 171405);
  covrtIfInit(&emlrtCoverageInstance, 1U, 390U, 171981, 172027, 173396, 174481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 391U, 172080, 172106, 172729, 172759);
  covrtIfInit(&emlrtCoverageInstance, 1U, 392U, 172127, 172153, 172236, 172266);
  covrtIfInit(&emlrtCoverageInstance, 1U, 393U, 172236, 172266, 172349, 172671);
  covrtIfInit(&emlrtCoverageInstance, 1U, 394U, 172349, 172379, -1, 172379);
  covrtIfInit(&emlrtCoverageInstance, 1U, 395U, 172404, 172430, 172522, 172552);
  covrtIfInit(&emlrtCoverageInstance, 1U, 396U, 172522, 172552, -1, 172552);
  covrtIfInit(&emlrtCoverageInstance, 1U, 397U, 172729, 172759, -1, 172759);
  covrtIfInit(&emlrtCoverageInstance, 1U, 398U, 172780, 172806, 172889, 172919);
  covrtIfInit(&emlrtCoverageInstance, 1U, 399U, 172889, 172919, 173002, 173324);
  covrtIfInit(&emlrtCoverageInstance, 1U, 400U, 173002, 173032, -1, 173032);
  covrtIfInit(&emlrtCoverageInstance, 1U, 401U, 173057, 173083, 173175, 173205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 402U, 173175, 173205, -1, 173205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 403U, 173396, 173446, 174342, 174481);
  covrtIfInit(&emlrtCoverageInstance, 1U, 404U, 173487, 173513, 173588, 173618);
  covrtIfInit(&emlrtCoverageInstance, 1U, 405U, 173588, 173618, 173910, 174312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 406U, 173639, 173665, 173748, 173778);
  covrtIfInit(&emlrtCoverageInstance, 1U, 407U, 173748, 173778, -1, 173778);
  covrtIfInit(&emlrtCoverageInstance, 1U, 408U, 173910, 173940, 174015, 174312);
  covrtIfInit(&emlrtCoverageInstance, 1U, 409U, 174015, 174045, -1, 174045);
  covrtIfInit(&emlrtCoverageInstance, 1U, 410U, 174066, 174092, 174175, 174205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 411U, 174175, 174205, -1, 174205);
  covrtIfInit(&emlrtCoverageInstance, 1U, 412U, 174363, 174388, -1, 174465);
  covrtIfInit(&emlrtCoverageInstance, 1U, 413U, 174896, 174973, 175991, 183629);
  covrtIfInit(&emlrtCoverageInstance, 1U, 414U, 175024, 175061, 175498, 175986);
  covrtIfInit(&emlrtCoverageInstance, 1U, 415U, 175074, 175145, 175303, 175489);
  covrtIfInit(&emlrtCoverageInstance, 1U, 416U, 175542, 175613, 175789, 175974);
  covrtIfInit(&emlrtCoverageInstance, 1U, 417U, 176203, 176242, 179761, 183587);
  covrtIfInit(&emlrtCoverageInstance, 1U, 418U, 176259, 176289, 176800, 176839);
  covrtIfInit(&emlrtCoverageInstance, 1U, 419U, 176310, 176370, -1, 176783);
  covrtIfInit(&emlrtCoverageInstance, 1U, 420U, 176800, 176839, 177356, 179718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 421U, 176860, 176920, -1, 177339);
  covrtIfInit(&emlrtCoverageInstance, 1U, 422U, 177356, 177389, 177429, 179718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 423U, 177429, 177468, 177991, 179718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 424U, 177489, 177551, -1, 177974);
  covrtIfInit(&emlrtCoverageInstance, 1U, 425U, 177991, 178025, 178536, 179718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 426U, 178046, 178106, -1, 178519);
  covrtIfInit(&emlrtCoverageInstance, 1U, 427U, 178536, 178575, 179092, 179718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 428U, 178596, 178656, -1, 179075);
  covrtIfInit(&emlrtCoverageInstance, 1U, 429U, 179092, 179125, 179165, 179718);
  covrtIfInit(&emlrtCoverageInstance, 1U, 430U, 179165, 179204, -1, 179204);
  covrtIfInit(&emlrtCoverageInstance, 1U, 431U, 179225, 179283, -1, 179698);
  covrtIfInit(&emlrtCoverageInstance, 1U, 432U, 179782, 179812, 179852, 179891);
  covrtIfInit(&emlrtCoverageInstance, 1U, 433U, 179852, 179891, 180408, 183554);
  covrtIfInit(&emlrtCoverageInstance, 1U, 434U, 179912, 179972, -1, 180391);
  covrtIfInit(&emlrtCoverageInstance, 1U, 435U, 180408, 180441, 180951, 183554);
  covrtIfInit(&emlrtCoverageInstance, 1U, 436U, 180462, 180522, -1, 180934);
  covrtIfInit(&emlrtCoverageInstance, 1U, 437U, 180951, 180990, 181501, 183554);
  covrtIfInit(&emlrtCoverageInstance, 1U, 438U, 181011, 181069, -1, 181484);
  covrtIfInit(&emlrtCoverageInstance, 1U, 439U, 181501, 181535, 181575, 183554);
  covrtIfInit(&emlrtCoverageInstance, 1U, 440U, 181575, 181614, 182236, 183554);
  covrtIfInit(&emlrtCoverageInstance, 1U, 441U, 181635, 181659, -1, 182219);
  covrtIfInit(&emlrtCoverageInstance, 1U, 442U, 181684, 181744, -1, 182195);
  covrtIfInit(&emlrtCoverageInstance, 1U, 443U, 182236, 182269, 182884, 183554);
  covrtIfInit(&emlrtCoverageInstance, 1U, 444U, 182290, 182314, -1, 182867);
  covrtIfInit(&emlrtCoverageInstance, 1U, 445U, 182339, 182399, -1, 182843);
  covrtIfInit(&emlrtCoverageInstance, 1U, 446U, 182884, 182923, -1, 182923);
  covrtIfInit(&emlrtCoverageInstance, 1U, 447U, 182944, 182968, -1, 183534);
  covrtIfInit(&emlrtCoverageInstance, 1U, 448U, 182993, 183055, -1, 183510);
  covrtIfInit(&emlrtCoverageInstance, 1U, 449U, 183895, 183945, 185784, 190386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 450U, 183954, 183996, 184372, 185762);
  covrtIfInit(&emlrtCoverageInstance, 1U, 451U, 184250, 184275, -1, 184363);
  covrtIfInit(&emlrtCoverageInstance, 1U, 452U, 184372, 184417, 184791, 185762);
  covrtIfInit(&emlrtCoverageInstance, 1U, 453U, 184670, 184695, -1, 184782);
  covrtIfInit(&emlrtCoverageInstance, 1U, 454U, 184791, 184837, 185213, 185762);
  covrtIfInit(&emlrtCoverageInstance, 1U, 455U, 185091, 185116, -1, 185204);
  covrtIfInit(&emlrtCoverageInstance, 1U, 456U, 185213, 185258, 185637, 185762);
  covrtIfInit(&emlrtCoverageInstance, 1U, 457U, 185511, 185536, -1, 185628);
  covrtIfInit(&emlrtCoverageInstance, 1U, 458U, 185654, 185679, -1, 185750);
  covrtIfInit(&emlrtCoverageInstance, 1U, 459U, 185784, 185838, 190282, 190386);
  covrtIfInit(&emlrtCoverageInstance, 1U, 460U, 186063, 186110, 187113, 187164);
  covrtIfInit(&emlrtCoverageInstance, 1U, 461U, 186123, 186165, 186486, 186973);
  covrtIfInit(&emlrtCoverageInstance, 1U, 462U, 186486, 186532, 186836, 186973);
  covrtIfInit(&emlrtCoverageInstance, 1U, 463U, 186857, 186882, -1, 186957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 464U, 186986, 187011, -1, 187104);
  covrtIfInit(&emlrtCoverageInstance, 1U, 465U, 187113, 187164, 188167, 190277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 466U, 187177, 187219, 187534, 188027);
  covrtIfInit(&emlrtCoverageInstance, 1U, 467U, 187534, 187580, 187890, 188027);
  covrtIfInit(&emlrtCoverageInstance, 1U, 468U, 187911, 187936, -1, 188011);
  covrtIfInit(&emlrtCoverageInstance, 1U, 469U, 188040, 188065, -1, 188158);
  covrtIfInit(&emlrtCoverageInstance, 1U, 470U, 188167, 188218, 189221, 190277);
  covrtIfInit(&emlrtCoverageInstance, 1U, 471U, 188231, 188273, 188594, 189081);
  covrtIfInit(&emlrtCoverageInstance, 1U, 472U, 188594, 188640, 188944, 189081);
  covrtIfInit(&emlrtCoverageInstance, 1U, 473U, 188965, 188990, -1, 189065);
  covrtIfInit(&emlrtCoverageInstance, 1U, 474U, 189094, 189119, -1, 189212);
  covrtIfInit(&emlrtCoverageInstance, 1U, 475U, 189221, 189272, -1, 189272);
  covrtIfInit(&emlrtCoverageInstance, 1U, 476U, 189285, 189327, 189654, 190135);
  covrtIfInit(&emlrtCoverageInstance, 1U, 477U, 189654, 189700, 189998, 190135);
  covrtIfInit(&emlrtCoverageInstance, 1U, 478U, 190019, 190044, -1, 190119);
  covrtIfInit(&emlrtCoverageInstance, 1U, 479U, 190148, 190173, -1, 190265);
  covrtIfInit(&emlrtCoverageInstance, 1U, 480U, 190295, 190320, -1, 190378);
  covrtIfInit(&emlrtCoverageInstance, 1U, 481U, 190657, 190707, 192052, 193551);
  covrtIfInit(&emlrtCoverageInstance, 1U, 482U, 190716, 190758, 191015, 192047);
  covrtIfInit(&emlrtCoverageInstance, 1U, 483U, 191015, 191060, 191315, 192047);
  covrtIfInit(&emlrtCoverageInstance, 1U, 484U, 191315, 191361, 191616, 192047);
  covrtIfInit(&emlrtCoverageInstance, 1U, 485U, 191616, 191661, 191905, 192047);
  covrtIfInit(&emlrtCoverageInstance, 1U, 486U, 191922, 191947, -1, 192035);
  covrtIfInit(&emlrtCoverageInstance, 1U, 487U, 192052, 192106, 193447, 193551);
  covrtIfInit(&emlrtCoverageInstance, 1U, 488U, 192115, 192162, 192411, 193442);
  covrtIfInit(&emlrtCoverageInstance, 1U, 489U, 192411, 192462, 192710, 193442);
  covrtIfInit(&emlrtCoverageInstance, 1U, 490U, 192710, 192761, 193010, 193442);
  covrtIfInit(&emlrtCoverageInstance, 1U, 491U, 193010, 193061, 193300, 193442);
  covrtIfInit(&emlrtCoverageInstance, 1U, 492U, 193317, 193342, -1, 193430);
  covrtIfInit(&emlrtCoverageInstance, 1U, 493U, 193460, 193485, -1, 193543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 494U, 193779, 193829, 195174, 196673);
  covrtIfInit(&emlrtCoverageInstance, 1U, 495U, 193838, 193880, 194135, 195169);
  covrtIfInit(&emlrtCoverageInstance, 1U, 496U, 194135, 194180, 194437, 195169);
  covrtIfInit(&emlrtCoverageInstance, 1U, 497U, 194437, 194483, 194740, 195169);
  covrtIfInit(&emlrtCoverageInstance, 1U, 498U, 194740, 194785, 195027, 195169);
  covrtIfInit(&emlrtCoverageInstance, 1U, 499U, 195044, 195069, -1, 195157);
  covrtIfInit(&emlrtCoverageInstance, 1U, 500U, 195174, 195228, 196569, 196673);
  covrtIfInit(&emlrtCoverageInstance, 1U, 501U, 195237, 195284, 195534, 196564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 502U, 195534, 195585, 195836, 196564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 503U, 195836, 195887, 196137, 196564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 504U, 196137, 196188, 196422, 196564);
  covrtIfInit(&emlrtCoverageInstance, 1U, 505U, 196439, 196464, -1, 196552);
  covrtIfInit(&emlrtCoverageInstance, 1U, 506U, 196582, 196607, -1, 196665);
  covrtIfInit(&emlrtCoverageInstance, 1U, 507U, 196901, 196951, 198288, 199801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 508U, 196960, 197002, 197253, 198260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 509U, 197253, 197298, 197548, 198260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 510U, 197548, 197594, 197843, 198260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 511U, 197843, 197888, 198127, 198260);
  covrtIfInit(&emlrtCoverageInstance, 1U, 512U, 198144, 198169, -1, 198248);
  covrtIfInit(&emlrtCoverageInstance, 1U, 513U, 198288, 198342, 199697, 199801);
  covrtIfInit(&emlrtCoverageInstance, 1U, 514U, 198351, 198398, 198653, 199692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 515U, 198653, 198704, 198959, 199692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 516U, 198959, 199010, 199265, 199692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 517U, 199265, 199316, 199558, 199692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 518U, 199575, 199600, -1, 199680);
  covrtIfInit(&emlrtCoverageInstance, 1U, 519U, 199710, 199735, -1, 199793);
  covrtIfInit(&emlrtCoverageInstance, 1U, 520U, 200029, 200079, 201416, 202928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 521U, 200088, 200130, 200379, 201388);
  covrtIfInit(&emlrtCoverageInstance, 1U, 522U, 200379, 200424, 200676, 201388);
  covrtIfInit(&emlrtCoverageInstance, 1U, 523U, 200676, 200722, 200973, 201388);
  covrtIfInit(&emlrtCoverageInstance, 1U, 524U, 200973, 201018, 201255, 201388);
  covrtIfInit(&emlrtCoverageInstance, 1U, 525U, 201272, 201297, -1, 201376);
  covrtIfInit(&emlrtCoverageInstance, 1U, 526U, 201416, 201470, 202824, 202928);
  covrtIfInit(&emlrtCoverageInstance, 1U, 527U, 201479, 201526, 201781, 202819);
  covrtIfInit(&emlrtCoverageInstance, 1U, 528U, 201781, 201832, 202087, 202819);
  covrtIfInit(&emlrtCoverageInstance, 1U, 529U, 202087, 202138, 202393, 202819);
  covrtIfInit(&emlrtCoverageInstance, 1U, 530U, 202393, 202444, 202686, 202819);
  covrtIfInit(&emlrtCoverageInstance, 1U, 531U, 202703, 202728, -1, 202807);
  covrtIfInit(&emlrtCoverageInstance, 1U, 532U, 202837, 202862, -1, 202920);
  covrtIfInit(&emlrtCoverageInstance, 1U, 533U, 203158, 203208, 204566, 206066);
  covrtIfInit(&emlrtCoverageInstance, 1U, 534U, 203217, 203259, 203516, 204543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 535U, 203516, 203561, 203818, 204543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 536U, 203818, 203864, 204121, 204543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 537U, 204121, 204166, 204410, 204543);
  covrtIfInit(&emlrtCoverageInstance, 1U, 538U, 204427, 204452, -1, 204531);
  covrtIfInit(&emlrtCoverageInstance, 1U, 539U, 204566, 204620, 205962, 206066);
  covrtIfInit(&emlrtCoverageInstance, 1U, 540U, 204629, 204676, 204926, 205957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 541U, 204926, 204977, 205226, 205957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 542U, 205226, 205277, 205527, 205957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 543U, 205527, 205578, 205814, 205957);
  covrtIfInit(&emlrtCoverageInstance, 1U, 544U, 205831, 205856, -1, 205945);
  covrtIfInit(&emlrtCoverageInstance, 1U, 545U, 205975, 206000, -1, 206058);
  covrtIfInit(&emlrtCoverageInstance, 1U, 546U, 206296, 206346, 207704, 209203);
  covrtIfInit(&emlrtCoverageInstance, 1U, 547U, 206355, 206397, 206654, 207681);
  covrtIfInit(&emlrtCoverageInstance, 1U, 548U, 206654, 206699, 206956, 207681);
  covrtIfInit(&emlrtCoverageInstance, 1U, 549U, 206956, 207002, 207259, 207681);
  covrtIfInit(&emlrtCoverageInstance, 1U, 550U, 207259, 207304, 207548, 207681);
  covrtIfInit(&emlrtCoverageInstance, 1U, 551U, 207565, 207590, -1, 207669);
  covrtIfInit(&emlrtCoverageInstance, 1U, 552U, 207704, 207758, 209099, 209203);
  covrtIfInit(&emlrtCoverageInstance, 1U, 553U, 207767, 207814, 208063, 209094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 554U, 208063, 208114, 208364, 209094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 555U, 208364, 208415, 208664, 209094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 556U, 208664, 208715, 208952, 209094);
  covrtIfInit(&emlrtCoverageInstance, 1U, 557U, 208969, 208994, -1, 209082);
  covrtIfInit(&emlrtCoverageInstance, 1U, 558U, 209112, 209137, -1, 209195);
  covrtIfInit(&emlrtCoverageInstance, 1U, 559U, 209433, 209483, 210820, 211098);
  covrtIfInit(&emlrtCoverageInstance, 1U, 560U, 209492, 209534, 209786, 210797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 561U, 209786, 209831, 210082, 210797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 562U, 210082, 210128, 210380, 210797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 563U, 210380, 210425, 210663, 210797);
  covrtIfInit(&emlrtCoverageInstance, 1U, 564U, 210680, 210705, -1, 210785);
  covrtIfInit(&emlrtCoverageInstance, 1U, 565U, 210820, 210874, 210994, 211098);
  covrtIfInit(&emlrtCoverageInstance, 1U, 566U, 210883, 210908, -1, 210989);
  covrtIfInit(&emlrtCoverageInstance, 1U, 567U, 211007, 211032, -1, 211090);
  covrtIfInit(&emlrtCoverageInstance, 1U, 568U, 211328, 211378, 212715, 212993);
  covrtIfInit(&emlrtCoverageInstance, 1U, 569U, 211387, 211429, 211681, 212692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 570U, 211681, 211726, 211977, 212692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 571U, 211977, 212023, 212275, 212692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 572U, 212275, 212320, 212558, 212692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 573U, 212575, 212600, -1, 212680);
  covrtIfInit(&emlrtCoverageInstance, 1U, 574U, 212715, 212769, 212889, 212993);
  covrtIfInit(&emlrtCoverageInstance, 1U, 575U, 212778, 212803, -1, 212884);
  covrtIfInit(&emlrtCoverageInstance, 1U, 576U, 212902, 212927, -1, 212985);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 3830, 3853, 1, 0,
                cond_starts_1_0, cond_ends_1_0, 2, postfix_exprs_1_0);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 5740, 5763, 1, 1,
                cond_starts_1_1, cond_ends_1_1, 2, postfix_exprs_1_1);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 7358, 7381, 1, 2,
                cond_starts_1_2, cond_ends_1_2, 2, postfix_exprs_1_2);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 3U, 10291, 10314, 1, 3,
                cond_starts_1_3, cond_ends_1_3, 2, postfix_exprs_1_3);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 4U, 13624, 13700, 2, 4,
                cond_starts_1_4, cond_ends_1_4, 3, postfix_exprs_1_4);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 5U, 14309, 14332, 1, 6,
                cond_starts_1_5, cond_ends_1_5, 2, postfix_exprs_1_5);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 6U, 14751, 14774, 1, 7,
                cond_starts_1_6, cond_ends_1_6, 2, postfix_exprs_1_6);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 7U, 15924, 15947, 1, 8,
                cond_starts_1_7, cond_ends_1_7, 2, postfix_exprs_1_7);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 8U, 16413, 16436, 1, 9,
                cond_starts_1_8, cond_ends_1_8, 2, postfix_exprs_1_8);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 9U, 16929, 16952, 1, 10,
                cond_starts_1_9, cond_ends_1_9, 2, postfix_exprs_1_9);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 10U, 17539, 17562, 1, 11,
                cond_starts_1_10, cond_ends_1_10, 2, postfix_exprs_1_10);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 11U, 18164, 18187, 1, 12,
                cond_starts_1_11, cond_ends_1_11, 2, postfix_exprs_1_11);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 12U, 18773, 18796, 1, 13,
                cond_starts_1_12, cond_ends_1_12, 2, postfix_exprs_1_12);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 13U, 19364, 19387, 1, 14,
                cond_starts_1_13, cond_ends_1_13, 2, postfix_exprs_1_13);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 14U, 19973, 19996, 1, 15,
                cond_starts_1_14, cond_ends_1_14, 2, postfix_exprs_1_14);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 15U, 28922, 29177, 2, 16,
                cond_starts_1_15, cond_ends_1_15, 3, postfix_exprs_1_15);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 16U, 29241, 29468, 2, 18,
                cond_starts_1_16, cond_ends_1_16, 3, postfix_exprs_1_16);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 17U, 30162, 30392, 2, 20,
                cond_starts_1_17, cond_ends_1_17, 3, postfix_exprs_1_17);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 18U, 31110, 31365, 2, 22,
                cond_starts_1_18, cond_ends_1_18, 3, postfix_exprs_1_18);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 19U, 31416, 31643, 2, 24,
                cond_starts_1_19, cond_ends_1_19, 3, postfix_exprs_1_19);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 20U, 32350, 32580, 2, 26,
                cond_starts_1_20, cond_ends_1_20, 3, postfix_exprs_1_20);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 21U, 33272, 33527, 2, 28,
                cond_starts_1_21, cond_ends_1_21, 3, postfix_exprs_1_21);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 22U, 33578, 33805, 2, 30,
                cond_starts_1_22, cond_ends_1_22, 3, postfix_exprs_1_22);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 23U, 34499, 34729, 2, 32,
                cond_starts_1_23, cond_ends_1_23, 3, postfix_exprs_1_23);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 24U, 35429, 35684, 2, 34,
                cond_starts_1_24, cond_ends_1_24, 3, postfix_exprs_1_24);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 25U, 35735, 35962, 2, 36,
                cond_starts_1_25, cond_ends_1_25, 3, postfix_exprs_1_25);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 26U, 36664, 36894, 2, 38,
                cond_starts_1_26, cond_ends_1_26, 3, postfix_exprs_1_26);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 27U, 43578, 43621, 2, 40,
                cond_starts_1_27, cond_ends_1_27, 3, postfix_exprs_1_27);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 28U, 49864, 49907, 2, 42,
                cond_starts_1_28, cond_ends_1_28, 3, postfix_exprs_1_28);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 29U, 50353, 50423, 2, 44,
                cond_starts_1_29, cond_ends_1_29, 3, postfix_exprs_1_29);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 30U, 55492, 55566, 2, 46,
                cond_starts_1_30, cond_ends_1_30, 3, postfix_exprs_1_30);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 31U, 58365, 58375, 1, 48,
                cond_starts_1_31, cond_ends_1_31, 2, postfix_exprs_1_31);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 32U, 58735, 58799, 2, 49,
                cond_starts_1_32, cond_ends_1_32, 3, postfix_exprs_1_32);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 33U, 59055, 59078, 1, 51,
                cond_starts_1_33, cond_ends_1_33, 2, postfix_exprs_1_33);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 34U, 59562, 59585, 1, 52,
                cond_starts_1_34, cond_ends_1_34, 2, postfix_exprs_1_34);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 35U, 62693, 62716, 1, 53,
                cond_starts_1_35, cond_ends_1_35, 2, postfix_exprs_1_35);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 36U, 63471, 63494, 1, 54,
                cond_starts_1_36, cond_ends_1_36, 2, postfix_exprs_1_36);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 37U, 63955, 63978, 1, 55,
                cond_starts_1_37, cond_ends_1_37, 2, postfix_exprs_1_37);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 38U, 64730, 64753, 1, 56,
                cond_starts_1_38, cond_ends_1_38, 2, postfix_exprs_1_38);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 39U, 65230, 65253, 1, 57,
                cond_starts_1_39, cond_ends_1_39, 2, postfix_exprs_1_39);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 40U, 66025, 66048, 1, 58,
                cond_starts_1_40, cond_ends_1_40, 2, postfix_exprs_1_40);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 41U, 69614, 69948, 3, 59,
                cond_starts_1_41, cond_ends_1_41, 6, postfix_exprs_1_41);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 42U, 72433, 72763, 3, 62,
                cond_starts_1_42, cond_ends_1_42, 6, postfix_exprs_1_42);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 43U, 75761, 76093, 3, 65,
                cond_starts_1_43, cond_ends_1_43, 6, postfix_exprs_1_43);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 44U, 78794, 79124, 3, 68,
                cond_starts_1_44, cond_ends_1_44, 6, postfix_exprs_1_44);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 45U, 81842, 81895, 2, 71,
                cond_starts_1_45, cond_ends_1_45, 3, postfix_exprs_1_45);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 46U, 83574, 83666, 1, 73,
                cond_starts_1_46, cond_ends_1_46, 2, postfix_exprs_1_46);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 47U, 84245, 84336, 1, 74,
                cond_starts_1_47, cond_ends_1_47, 2, postfix_exprs_1_47);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 48U, 84914, 85006, 1, 75,
                cond_starts_1_48, cond_ends_1_48, 2, postfix_exprs_1_48);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 49U, 85577, 85668, 1, 76,
                cond_starts_1_49, cond_ends_1_49, 2, postfix_exprs_1_49);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 50U, 86415, 86501, 1, 77,
                cond_starts_1_50, cond_ends_1_50, 2, postfix_exprs_1_50);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 51U, 86977, 87062, 1, 78,
                cond_starts_1_51, cond_ends_1_51, 2, postfix_exprs_1_51);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 52U, 87538, 87624, 1, 79,
                cond_starts_1_52, cond_ends_1_52, 2, postfix_exprs_1_52);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 53U, 88094, 88179, 1, 80,
                cond_starts_1_53, cond_ends_1_53, 2, postfix_exprs_1_53);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 54U, 89067, 89368, 2, 81,
                cond_starts_1_54, cond_ends_1_54, 3, postfix_exprs_1_54);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 55U, 92787, 93086, 2, 83,
                cond_starts_1_55, cond_ends_1_55, 3, postfix_exprs_1_55);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 56U, 96567, 96870, 2, 85,
                cond_starts_1_56, cond_ends_1_56, 3, postfix_exprs_1_56);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 57U, 100347, 100652, 2, 87,
                cond_starts_1_57, cond_ends_1_57, 3, postfix_exprs_1_57);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 58U, 104121, 104424, 2, 89,
                cond_starts_1_58, cond_ends_1_58, 3, postfix_exprs_1_58);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 59U, 107874, 108173, 2, 91,
                cond_starts_1_59, cond_ends_1_59, 3, postfix_exprs_1_59);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 60U, 111762, 112063, 2, 93,
                cond_starts_1_60, cond_ends_1_60, 3, postfix_exprs_1_60);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 61U, 115487, 115786, 2, 95,
                cond_starts_1_61, cond_ends_1_61, 3, postfix_exprs_1_61);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 62U, 119196, 119497, 2, 97,
                cond_starts_1_62, cond_ends_1_62, 3, postfix_exprs_1_62);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 63U, 122921, 123226, 2, 99,
                cond_starts_1_63, cond_ends_1_63, 3, postfix_exprs_1_63);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 64U, 126625, 126928, 2, 101,
                cond_starts_1_64, cond_ends_1_64, 3, postfix_exprs_1_64);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 65U, 130292, 130597, 2, 103,
                cond_starts_1_65, cond_ends_1_65, 3, postfix_exprs_1_65);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 66U, 135400, 135549, 3, 105,
                cond_starts_1_66, cond_ends_1_66, 5, postfix_exprs_1_66);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 67U, 135670, 135805, 2, 108,
                cond_starts_1_67, cond_ends_1_67, 3, postfix_exprs_1_67);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 68U, 135925, 136062, 2, 110,
                cond_starts_1_68, cond_ends_1_68, 3, postfix_exprs_1_68);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 69U, 136182, 136317, 2, 112,
                cond_starts_1_69, cond_ends_1_69, 3, postfix_exprs_1_69);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 70U, 136437, 136570, 2, 114,
                cond_starts_1_70, cond_ends_1_70, 3, postfix_exprs_1_70);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 71U, 136833, 136982, 3, 116,
                cond_starts_1_71, cond_ends_1_71, 5, postfix_exprs_1_71);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 72U, 137103, 137238, 2, 119,
                cond_starts_1_72, cond_ends_1_72, 3, postfix_exprs_1_72);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 73U, 137357, 137490, 2, 121,
                cond_starts_1_73, cond_ends_1_73, 3, postfix_exprs_1_73);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 74U, 137609, 137744, 2, 123,
                cond_starts_1_74, cond_ends_1_74, 3, postfix_exprs_1_74);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 75U, 137863, 138000, 2, 125,
                cond_starts_1_75, cond_ends_1_75, 3, postfix_exprs_1_75);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 76U, 159504, 159711, 5, 127,
                cond_starts_1_76, cond_ends_1_76, 9, postfix_exprs_1_76);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 77U, 159780, 159853, 2, 132,
                cond_starts_1_77, cond_ends_1_77, 3, postfix_exprs_1_77);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 78U, 167135, 167166, 2, 134,
                cond_starts_1_78, cond_ends_1_78, 3, postfix_exprs_1_78);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 79U, 170948, 171029, 2, 136,
                cond_starts_1_79, cond_ends_1_79, 3, postfix_exprs_1_79);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 80U, 174899, 174973, 2, 138,
                cond_starts_1_80, cond_ends_1_80, 3, postfix_exprs_1_80);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 81U, 175077, 175145, 2, 140,
                cond_starts_1_81, cond_ends_1_81, 3, postfix_exprs_1_81);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 82U, 175545, 175613, 2, 142,
                cond_starts_1_82, cond_ends_1_82, 3, postfix_exprs_1_82);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 4571, 4591, 4840);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 13585, 13609, 13765);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 13911, 13935, 14170);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 38482, 38511, 43685);
  covrtForInit(&emlrtCoverageInstance, 1U, 4U, 38633, 38673, 43261);
  covrtForInit(&emlrtCoverageInstance, 1U, 5U, 44632, 44661, 49971);
  covrtForInit(&emlrtCoverageInstance, 1U, 6U, 44783, 44823, 49547);
  covrtForInit(&emlrtCoverageInstance, 1U, 7U, 50241, 50275, 50540);
  covrtForInit(&emlrtCoverageInstance, 1U, 8U, 51268, 51295, 51525);
  covrtForInit(&emlrtCoverageInstance, 1U, 9U, 51550, 51579, 55629);
  covrtForInit(&emlrtCoverageInstance, 1U, 10U, 51690, 51730, 55183);
  covrtForInit(&emlrtCoverageInstance, 1U, 11U, 58297, 58324, 67066);
  covrtForInit(&emlrtCoverageInstance, 1U, 12U, 58694, 58720, 58865);
  covrtForInit(&emlrtCoverageInstance, 1U, 13U, 68801, 68827, 69320);
  covrtForInit(&emlrtCoverageInstance, 1U, 14U, 69330, 69359, 81934);
  covrtForInit(&emlrtCoverageInstance, 1U, 15U, 69474, 69514, 81530);
  covrtForInit(&emlrtCoverageInstance, 1U, 16U, 86351, 86371, 88629);
  covrtForInit(&emlrtCoverageInstance, 1U, 17U, 88794, 88819, 134683);
  covrtForInit(&emlrtCoverageInstance, 1U, 18U, 88966, 89006, 111531);
  covrtForInit(&emlrtCoverageInstance, 1U, 19U, 111616, 111656, 133986);
  covrtForInit(&emlrtCoverageInstance, 1U, 20U, 135281, 135303, 138202);
  covrtForInit(&emlrtCoverageInstance, 1U, 21U, 138878, 138890, 146682);
  covrtForInit(&emlrtCoverageInstance, 1U, 22U, 165997, 166011, 167332);
  covrtForInit(&emlrtCoverageInstance, 1U, 23U, 176105, 176117, 183612);

  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 1U, 0U, 4523, 4531, 5321);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 1U, 5509, 5517, 6608);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 2U, 6789, 6797, 8365);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 3U, 12545, 12553, 21462);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 4U, 135226, 135234, 146816);
  covrtWhileInit(&emlrtCoverageInstance, 1U, 5U, 158973, 158981, 171734);

  /* Initialize Switch Information */
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 5446, 5464, 8550, 3U,
                  caseStarts_1_0, caseExprEnds_1_0);
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 1U, 15163, 15206, 20476, 5U,
                  caseStarts_1_1, caseExprEnds_1_1);
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 2U, 61760, 61800, 66371, 5U,
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
