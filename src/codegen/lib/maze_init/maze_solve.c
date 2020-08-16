/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: maze_solve.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 16-Aug-2020 15:44:45
 */

/* Include Files */
#include <string.h>
#include <math.h>
#include "maze_init.h"
#include "maze_solve.h"
#include "rem.h"
#include "maze_init_emxutil.h"
#include "idivide.h"
#include "isequal.h"
#include "maze_init_data.h"
#include "C:\work\matlab\maze_sim_git\src\C_src\matlab_movement.h"
#include "C:\work\matlab\maze_sim_git\src\C_src\matlab_IR_sensor.h"

/* Type Definitions */
#ifndef typedef_coder_internal_ref
#define typedef_coder_internal_ref

typedef struct {
  unsigned char contents;
} coder_internal_ref;

#endif                                 /*typedef_coder_internal_ref*/

#ifndef typedef_coder_internal_ref_1
#define typedef_coder_internal_ref_1

typedef struct {
  unsigned char contents[18];
} coder_internal_ref_1;

#endif                                 /*typedef_coder_internal_ref_1*/

#ifndef typedef_coder_internal_ref_2
#define typedef_coder_internal_ref_2

typedef struct {
  unsigned short contents;
} coder_internal_ref_2;

#endif                                 /*typedef_coder_internal_ref_2*/

#ifndef typedef_g_struct_T
#define typedef_g_struct_T

typedef struct {
  unsigned char unknown;
  unsigned char known;
} g_struct_T;

#endif                                 /*typedef_g_struct_T*/

#ifndef typedef_coder_internal_ref_4
#define typedef_coder_internal_ref_4

typedef struct {
  g_struct_T contents;
} coder_internal_ref_4;

#endif                                 /*typedef_coder_internal_ref_4*/

#ifndef typedef_f_struct_T
#define typedef_f_struct_T

typedef struct {
  unsigned char nowall;
  unsigned char wall;
} f_struct_T;

#endif                                 /*typedef_f_struct_T*/

#ifndef typedef_coder_internal_ref_5
#define typedef_coder_internal_ref_5

typedef struct {
  f_struct_T contents;
} coder_internal_ref_5;

#endif                                 /*typedef_coder_internal_ref_5*/

/* Function Declarations */
static void b_make_map_fustrun_diagonal(coder_internal_ref_2 *max_length,
  coder_internal_ref_3 *num_temp, const coder_internal_ref_5 *wall, const
  coder_internal_ref_4 *search, const unsigned char maze_goal[2], const unsigned
  char maze_wall[1024], const unsigned char maze_wall_search[1024], unsigned
  short row_num_node[1056], unsigned short col_num_node[1056], unsigned short
  *start_num);
static void b_search_adachi(const coder_internal_ref_5 *wall, coder_internal_ref
  *wall_flg, const coder_internal_ref_4 *search, const coder_internal_ref_1
  *maze_goal, coder_internal_ref_3 *num_temp, unsigned char *current_x, unsigned
  char *current_y, unsigned char *current_dir, unsigned char maze_row_size,
  unsigned char maze_col_size, unsigned char maze_wall[1024], unsigned char
  maze_wall_search[1024], const unsigned char exploration_goal[18], unsigned
  char *start_flg, unsigned char goal_after_flg, unsigned short contour_map[1024]);
static void decide_goal_node_dir(const unsigned char maze_goal[18], unsigned
  char goal_size, const unsigned short row_num_node[1056], const unsigned short
  col_num_node[1056], unsigned char goal_node[2], unsigned char *goal_matrix_dir,
  unsigned char *goal_dir);
static void decide_goal_section(const unsigned char maze_goal[18], const
  unsigned char goal_node[2], unsigned char goal_matrix_dir, unsigned char
  goal_dir, unsigned char goal_section[2], unsigned char goal_node2[2], unsigned
  char *goal_matrix_dir2);
static void fust_run(coder_internal_ref *current_x, coder_internal_ref
                     *current_y, coder_internal_ref *current_dir, const
                     coder_internal_ref *goal_size, const coder_internal_ref_5
                     *wall, const unsigned char maze_wall[1024], const unsigned
                     short contour_map[1024], const unsigned char maze_goal[18],
                     unsigned short max_length);
static void get_next_dir_diagonal(const unsigned short row_num_node[1056], const
  unsigned short col_num_node[1056], unsigned char current_move_dir, const
  unsigned char current_node[2], unsigned char current_matrix_dir, const
  unsigned char goal_node2[2], unsigned char goal_matrix_dir2, const unsigned
  char goal_section[2], unsigned char *next_dir, unsigned char next_node[2],
  unsigned char *next_node_property);
static unsigned char get_nextdir2(unsigned char current_x, unsigned char
  current_y, const unsigned char maze_wall[1024], const unsigned short
  contour_map[1024]);
static unsigned char get_turn_pattern_num(const double move_dir_buffer[3],
  unsigned char ref_move_mode);
static double goal_judge(const unsigned char maze_goal[18], unsigned char x,
  unsigned char y);
static void make_map_find(coder_internal_ref_3 *num_temp, const
  coder_internal_ref_5 *wall, const unsigned char maze_goal[18], unsigned char
  l_goal_size, const unsigned char maze_wall[1024], unsigned short contour_map
  [1024]);
static void make_map_fustrun(const coder_internal_ref *goal_size,
  coder_internal_ref_3 *num_temp, const coder_internal_ref_5 *wall, const
  coder_internal_ref_4 *search, const unsigned char maze_goal[18], const
  unsigned char maze_wall[1024], const unsigned char maze_wall_search[1024],
  unsigned short contour_map[1024]);
static void make_map_fustrun_diagonal(coder_internal_ref_2 *max_length,
  coder_internal_ref_3 *num_temp, const coder_internal_ref_5 *wall, const
  coder_internal_ref_4 *search, const unsigned char maze_goal[18], unsigned char
  goal_size, const unsigned char maze_wall[1024], const unsigned char
  maze_wall_search[1024], unsigned short row_num_node[1056], unsigned short
  col_num_node[1056], unsigned short *start_num);
static void make_route_diagonal(const unsigned short row_num_node[1056], const
  unsigned short col_num_node[1056], const unsigned char goal_section[2], const
  unsigned char goal_node2[2], unsigned char goal_node_property);
static void move_step(unsigned char *current_x, unsigned char *current_y,
                      unsigned char current_dir);
static void move_straight(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode, unsigned char straight_count);
static void search_adachi(const coder_internal_ref_5 *wall, coder_internal_ref
  *wall_flg, const coder_internal_ref_4 *search, const coder_internal_ref_1
  *maze_goal, coder_internal_ref_3 *num_temp, unsigned char *current_x, unsigned
  char *current_y, unsigned char *current_dir, unsigned char maze_row_size,
  unsigned char maze_col_size, unsigned char maze_wall[1024], unsigned char
  maze_wall_search[1024], const unsigned char exploration_goal[18], unsigned
  char l_goal_size, unsigned char *start_flg, unsigned char goal_after_flg,
  unsigned short contour_map[1024]);
static void turn_180deg(unsigned char *current_dir);
static void turn_clk_90deg(unsigned char *current_dir);
static void turn_conclk_90deg(unsigned char *current_dir);
static void turn_l_135(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode);
static void turn_l_180(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode);
static void turn_l_45(unsigned char current_node[2], unsigned char
                      *current_node_property, unsigned char *current_move_dir,
                      unsigned char *current_move_mode);
static void turn_l_90(unsigned char current_node[2], unsigned char
                      *current_node_property, unsigned char *current_move_dir,
                      unsigned char *current_move_mode);
static void turn_r_135(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode);
static void turn_r_45(unsigned char current_node[2], unsigned char
                      *current_node_property, unsigned char *current_move_dir,
                      unsigned char *current_move_mode);
static void wall_set(const coder_internal_ref_5 *wall, coder_internal_ref
                     *wall_flg, const coder_internal_ref_4 *search, const
                     coder_internal_ref_1 *maze_goal, unsigned char
                     maze_row_size, unsigned char maze_col_size, unsigned char
                     current_x, unsigned char current_y, unsigned char
                     current_dir, unsigned char maze_wall[1024], unsigned char
                     maze_wall_search[1024]);

/* Function Definitions */

/*
 * ���m�ǂ̗̈�͉��z�ǂ������ĐN�����Ȃ��B
 * ���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��),���H�T�����(16�i��)
 * �o�� ������map,�ő�o�H��
 * Arguments    : coder_internal_ref_2 *max_length
 *                coder_internal_ref_3 *num_temp
 *                const coder_internal_ref_5 *wall
 *                const coder_internal_ref_4 *search
 *                const unsigned char maze_goal[2]
 *                const unsigned char maze_wall[1024]
 *                const unsigned char maze_wall_search[1024]
 *                unsigned short row_num_node[1056]
 *                unsigned short col_num_node[1056]
 *                unsigned short *start_num
 * Return Type  : void
 */
static void b_make_map_fustrun_diagonal(coder_internal_ref_2 *max_length,
  coder_internal_ref_3 *num_temp, const coder_internal_ref_5 *wall, const
  coder_internal_ref_4 *search, const unsigned char maze_goal[2], const unsigned
  char maze_wall[1024], const unsigned char maze_wall_search[1024], unsigned
  short row_num_node[1056], unsigned short col_num_node[1056], unsigned short
  *start_num)
{
  int i114;
  unsigned short row_num_node_temp[1056];
  unsigned short col_num_node_temp[1056];
  int idx;
  unsigned char row_dir_node[1056];
  unsigned char col_dir_node[1056];
  int i115;
  int ii;
  int i116;
  int i117;
  int row_num_node_tmp;
  int i118;
  int i119;
  int i120;
  emxArray_uint16_T *row;
  emxArray_uint16_T *col;
  emxArray_uint16_T *b_num_temp;
  int i121;
  unsigned char change_flag;
  unsigned int qY;
  unsigned short u8;
  unsigned short i;
  bool exitg1;
  short ii_data[1056];
  int i122;
  int i123;
  int i124;
  int i125;
  int i126;
  unsigned char a;
  int i127;
  int i128;
  unsigned int u9;
  int i129;
  int i130;
  int i131;
  int i132;
  int i133;
  int i134;
  int i135;
  int i136;
  int i137;
  int i138;
  int i139;
  int i140;
  int i141;
  int i142;
  int i143;
  int i144;
  int i145;
  int i146;
  int i147;
  int i148;
  int i149;
  int i150;
  int i151;
  int i152;
  int i153;
  int i154;
  int i155;
  int i156;
  int i157;
  int i158;
  int i159;
  int i160;
  int i161;
  int i162;
  int i163;
  int i164;
  int i165;
  int i166;
  int i167;
  int i168;
  int i169;
  int i170;
  int i171;
  int i172;
  int i173;
  int i174;
  int i175;
  int i176;
  int i177;
  int i178;
  int i179;
  int i180;
  int i181;

  /*  make_map_fustrun_diagonal �ŒZ���s�p������MAP�𐶐� */
  /* ���[�J���ϐ��ݒ� */
  /* �p�����[�^�ݒ� */
  /*  ���H�p�����[�^�ݒ� */
  max_length->contents = 1024U;

  /*  ���[�g�̏d�ݐݒ� */
  /* MAP�̏�����(���ׂẴm�[�h��max_length�����) */
  /* ����MAP */
  /* �X�V�pMAP */
  /* �i�s�����ێ��p�m�[�h�쐬 */
  for (i114 = 0; i114 < 1056; i114++) {
    row_num_node[i114] = MAX_uint16_T;
    col_num_node[i114] = MAX_uint16_T;
    row_num_node_temp[i114] = MAX_uint16_T;
    col_num_node_temp[i114] = MAX_uint16_T;
    row_dir_node[i114] = 0U;
    col_dir_node[i114] = 0U;
  }

  /* �S�[���Z�N�V�������m�肵�Ă���ꍇ */
  /* �S�[���}�X����A������k�Ƀ}�b�v��W�J */
  /* �k�� */
  i114 = maze_goal[0] - 1;
  idx = (maze_goal[1] + (i114 << 5)) - 1;
  if (g_direction.North <= 7) {
    i115 = (unsigned char)(1 << g_direction.North);
  } else {
    i115 = 0;
  }

  if ((maze_wall[idx] & i115) == 0) {
    /* �����X�V */
    ii = (int)(maze_goal[1] + 1U);
    i116 = ii;
    if ((unsigned int)ii > 255U) {
      i116 = 255;
    }

    row_num_node_tmp = 33 * i114;
    row_num_node[(i116 + row_num_node_tmp) - 1] = 3U;

    /* �����ǉ� */
    i114 = ii;
    if ((unsigned int)ii > 255U) {
      i114 = 255;
    }

    if (g_d_direction.North <= 7) {
      row_dir_node[(i114 + row_num_node_tmp) - 1] = (unsigned char)(1 <<
        g_d_direction.North);
    } else {
      row_dir_node[(i114 + row_num_node_tmp) - 1] = 0U;
    }

    /* �X�V�pMAP�X�V */
    if ((unsigned int)ii > 255U) {
      ii = 255;
    }

    row_num_node_temp[(ii + row_num_node_tmp) - 1] = 0U;
  }

  /* ���� */
  if (g_direction.East <= 7) {
    i117 = (unsigned char)(1 << g_direction.East);
  } else {
    i117 = 0;
  }

  if ((maze_wall[idx] & i117) == 0) {
    /* �����X�V */
    i114 = (int)(maze_goal[0] + 1U);
    ii = i114;
    if ((unsigned int)i114 > 255U) {
      ii = 255;
    }

    col_num_node[(maze_goal[1] + ((ii - 1) << 5)) - 1] = 3U;

    /* �����ǉ� */
    ii = i114;
    if ((unsigned int)i114 > 255U) {
      ii = 255;
    }

    if (g_d_direction.East <= 7) {
      col_dir_node[(maze_goal[1] + ((ii - 1) << 5)) - 1] = (unsigned char)(1 <<
        g_d_direction.East);
    } else {
      col_dir_node[(maze_goal[1] + ((ii - 1) << 5)) - 1] = 0U;
    }

    /* �X�V�pMAP�X�V */
    if ((unsigned int)i114 > 255U) {
      i114 = 255;
    }

    col_num_node_temp[(maze_goal[1] + ((i114 - 1) << 5)) - 1] = 0U;
  }

  /* ��� */
  if (g_direction.South <= 7) {
    i118 = (unsigned char)(1 << g_direction.South);
  } else {
    i118 = 0;
  }

  if ((maze_wall[idx] & i118) == 0) {
    /* �����X�V */
    row_num_node_tmp = (maze_goal[1] + 33 * (maze_goal[0] - 1)) - 1;
    row_num_node[row_num_node_tmp] = 3U;

    /* �����ǉ� */
    if (g_d_direction.South <= 7) {
      i120 = (unsigned char)(1 << g_d_direction.South);
    } else {
      i120 = 0;
    }

    row_dir_node[row_num_node_tmp] = (unsigned char)
      (row_dir_node[row_num_node_tmp] | i120);

    /* �X�V�pMAP�X�V */
    row_num_node_temp[row_num_node_tmp] = 0U;
  }

  /* ���� */
  if (g_direction.West <= 7) {
    i119 = (unsigned char)(1 << g_direction.West);
  } else {
    i119 = 0;
  }

  if ((maze_wall[idx] & i119) == 0) {
    /* �����X�V */
    col_num_node[idx] = 3U;

    /* �����ǉ� */
    if (g_d_direction.West <= 7) {
      i121 = (unsigned char)(1 << g_d_direction.West);
    } else {
      i121 = 0;
    }

    col_dir_node[idx] = (unsigned char)(col_dir_node[idx] | i121);

    /* �X�V�pMAP�X�V */
    col_num_node_temp[idx] = 0U;
  }

  /* �S�[���Z�N�V�������m�肵�Ă��Ȃ��ꍇ     */
  emxInit_uint16_T(&row, 1);
  emxInit_uint16_T(&col, 1);
  emxInit_uint16_T(&b_num_temp, 1);
  do {
    change_flag = 0U;

    /* map�X�V�m�F�p�t���O */
    idx = max_length->contents;
    qY = idx - 1U;
    if (qY > (unsigned int)idx) {
      qY = 0U;
    }

    u8 = (unsigned short)qY;
    for (i = 0; i <= u8; i++) {
      /* �X�V�m�F�p�̕����J�E���g��0~max_length */
      /* Row_Edge�̏���[33�s,32��] */
      /* �������m�肵�Ă�����W������ */
      /* �ŏ���0,�X�V����A���������}�X�����X�������Ă��� */
      idx = 0;
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii < 1056)) {
        if (row_num_node_temp[ii] == i) {
          idx++;
          ii_data[idx - 1] = (short)(ii + 1);
          if (idx >= 1056) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        ii = 0;
      } else {
        ii = idx;
      }

      i114 = num_temp->contents->size[0];
      num_temp->contents->size[0] = ii;
      emxEnsureCapacity_uint16_T(num_temp->contents, i114);
      for (i114 = 0; i114 < ii; i114++) {
        num_temp->contents->data[i114] = (unsigned short)ii_data[i114];
      }

      /* 33�s�Ȃ̂ŁA�s�ԍ�:33�Ŋ��������܂� */
      i114 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i114);
      ii = num_temp->contents->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        idx = num_temp->contents->data[i114];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i114] = (unsigned short)qY;
      }

      d_rem(b_num_temp, row);
      i114 = row->size[0];
      emxEnsureCapacity_uint16_T(row, i114);
      ii = row->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        qY = row->data[i114] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        row->data[i114] = (unsigned short)qY;
      }

      /* ��ԍ�:33�Ŋ������Ƃ��̏� */
      i114 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i114);
      ii = num_temp->contents->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        idx = num_temp->contents->data[i114];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i114] = (unsigned short)qY;
      }

      idivide(b_num_temp, 33.0, col);
      i114 = col->size[0];
      emxEnsureCapacity_uint16_T(col, i114);
      ii = col->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        qY = col->data[i114] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        col->data[i114] = (unsigned short)qY;
      }

      /* ���������}�X�̐� */
      /* �����������W�ɑ΂��A����map���X�V */
      i114 = row->size[0];
      if (i114 < 0) {
        i114 = 0;
      } else {
        if (i114 > 65535) {
          i114 = 65535;
        }
      }

      for (idx = 0; idx < i114; idx++) {
        /* �k�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.North <= 7) {
          i122 = (unsigned char)(1 << g_direction.North);
        } else {
          i122 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i122) != 0) == wall->contents.nowall) {
          if (g_direction.North <= 7) {
            i123 = (unsigned char)(1 << g_direction.North);
          } else {
            i123 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i123) != 0) == search->contents.known) {
            /* ���i�s�������k�����ł��鎞 */
            if (g_d_direction.North <= 7) {
              i125 = (unsigned char)(1 << g_d_direction.North);
            } else {
              i125 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i125) != 0) {
              /* ���k�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 6U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North <= 7) {
                    i136 = (unsigned char)(1 << g_d_direction.North);
                  } else {
                    i136 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i136);
                }
              }

              /* ���i�s�������k�����łȂ��Ƃ�     */
            } else {
              /* ���k�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North <= 7) {
                    i135 = (unsigned char)(1 << g_d_direction.North);
                  } else {
                    i135 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i135);
                }
              }
            }
          }
        }

        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.East <= 7) {
          i124 = (unsigned char)(1 << g_direction.East);
        } else {
          i124 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i124) != 0) == wall->contents.nowall) {
          if (g_direction.East <= 7) {
            i126 = (unsigned char)(1 << g_direction.East);
          } else {
            i126 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i126) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_East <= 7) {
              i128 = (unsigned char)(1 << g_d_direction.North_East);
            } else {
              i128 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i128) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i142 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i142 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i142);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i141 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i141 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i141);
                }
              }
            }
          }
        }

        /* �����͒� */
        /* �쓌�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2];
        if (g_direction.East <= 7) {
          i127 = (unsigned char)(1 << g_direction.East);
        } else {
          i127 = 0;
        }

        if (((a & i127) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
            2];
          if (g_direction.East <= 7) {
            i129 = (unsigned char)(1 << g_direction.East);
          } else {
            i129 = 0;
          }

          if (((a & i129) != 0) == search->contents.known) {
            /* ���i�s�������쓌�����ł��鎞 */
            if (g_d_direction.South_East <= 7) {
              i131 = (unsigned char)(1 << g_d_direction.South_East);
            } else {
              i131 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i131) != 0) {
              /* ���쓌�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] >
                  (int)u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u9;

                /* ����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.South_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.South_East <= 7) {
                    i148 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i148 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(a | i148);
                }
              }

              /* ���i�s�������쓌�����łȂ��Ƃ�     */
            } else {
              /* ���쓌�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] >
                  (int)u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u9;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.South_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.South_East <= 7) {
                    i147 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i147 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(a | i147);
                }
              }
            }
          }
        }

        /* �쑤 */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2];
        if (g_direction.South <= 7) {
          i130 = (unsigned char)(1 << g_direction.South);
        } else {
          i130 = 0;
        }

        if (((a & i130) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
            2];
          if (g_direction.South <= 7) {
            i132 = (unsigned char)(1 << g_direction.South);
          } else {
            i132 = 0;
          }

          if (((a & i132) != 0) == search->contents.known) {
            /* ���i�s������������ł��鎞 */
            if (g_d_direction.South <= 7) {
              i134 = (unsigned char)(1 << g_d_direction.South);
            } else {
              i134 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i134) != 0) {
              /* ����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 6U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  2] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(1 << g_d_direction.South);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1))
                    - 2];
                  if (g_d_direction.South <= 7) {
                    i145 = (unsigned char)(1 << g_d_direction.South);
                  } else {
                    i145 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(a | i145);
                }
              }

              /* ���i�s������������łȂ��Ƃ�     */
            } else {
              /* ����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  2] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(1 << g_d_direction.South);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1))
                    - 2];
                  if (g_d_direction.South <= 7) {
                    i144 = (unsigned char)(1 << g_d_direction.South);
                  } else {
                    i144 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(a | i144);
                }
              }
            }
          }
        }

        /* �쐼�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2];
        if (g_direction.West <= 7) {
          i133 = (unsigned char)(1 << g_direction.West);
        } else {
          i133 = 0;
        }

        if (((a & i133) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
            2];
          if (g_direction.West <= 7) {
            i137 = (unsigned char)(1 << g_direction.West);
          } else {
            i137 = 0;
          }

          if (((a & i137) != 0) == search->contents.known) {
            /* ���i�s�������쐼�����ł��鎞 */
            if (g_d_direction.South_West <= 7) {
              i139 = (unsigned char)(1 << g_d_direction.South_West);
            } else {
              i139 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i139) != 0) {
              /* ���쐼�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  2] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 2] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2];
                  if (g_d_direction.South_West <= 7) {
                    i151 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i151 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(a | i151);
                }
              }

              /* ���i�s�������쐼�����łȂ��Ƃ�     */
            } else {
              /* ���쐼�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  2] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 2] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2];
                  if (g_d_direction.South_West <= 7) {
                    i150 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i150 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(a | i150);
                }
              }
            }
          }
        }

        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.West <= 7) {
          i138 = (unsigned char)(1 << g_direction.West);
        } else {
          i138 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i138) != 0) == wall->contents.nowall) {
          if (g_direction.West <= 7) {
            i140 = (unsigned char)(1 << g_direction.West);
          } else {
            i140 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i140) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_West <= 7) {
              i143 = (unsigned char)(1 << g_d_direction.North_West);
            } else {
              i143 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i143) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.North_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.North_West <= 7) {
                    i156 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i156 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(col_dir_node[(row->data[idx] +
                    ((col->data[idx] - 1) << 5)) - 1] | i156);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.North_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.North_West <= 7) {
                    i155 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i155 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(col_dir_node[(row->data[idx] +
                    ((col->data[idx] - 1) << 5)) - 1] | i155);
                }
              }
            }
          }
        }
      }

      /* Col_Edge�̏���[32�s,33��] */
      /* �������m�肵�Ă�����W������ */
      /* �ŏ���0,�X�V����A���������}�X�����X�������Ă��� */
      idx = 0;
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii < 1056)) {
        if (col_num_node_temp[ii] == i) {
          idx++;
          ii_data[idx - 1] = (short)(ii + 1);
          if (idx >= 1056) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        ii = 0;
      } else {
        ii = idx;
      }

      i114 = num_temp->contents->size[0];
      num_temp->contents->size[0] = ii;
      emxEnsureCapacity_uint16_T(num_temp->contents, i114);
      for (i114 = 0; i114 < ii; i114++) {
        num_temp->contents->data[i114] = (unsigned short)ii_data[i114];
      }

      /* 32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂� */
      i114 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i114);
      ii = num_temp->contents->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        idx = num_temp->contents->data[i114];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i114] = (unsigned short)qY;
      }

      c_rem(b_num_temp, row);
      i114 = row->size[0];
      emxEnsureCapacity_uint16_T(row, i114);
      ii = row->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        qY = row->data[i114] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        row->data[i114] = (unsigned short)qY;
      }

      /* ��ԍ�:32�Ŋ������Ƃ��̏� */
      i114 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i114);
      ii = num_temp->contents->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        idx = num_temp->contents->data[i114];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i114] = (unsigned short)qY;
      }

      idivide(b_num_temp, 32.0, col);
      i114 = col->size[0];
      emxEnsureCapacity_uint16_T(col, i114);
      ii = col->size[0];
      for (i114 = 0; i114 < ii; i114++) {
        qY = col->data[i114] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        col->data[i114] = (unsigned short)qY;
      }

      /* ���������}�X�̐� */
      /* �����������W�ɑ΂��A����map���X�V */
      i114 = row->size[0];
      if (i114 < 0) {
        i114 = 0;
      } else {
        if (i114 > 65535) {
          i114 = 65535;
        }
      }

      for (idx = 0; idx < i114; idx++) {
        /* �k���͕� */
        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.North <= 7) {
          i146 = (unsigned char)(1 << g_direction.North);
        } else {
          i146 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i146) != 0) == wall->contents.nowall) {
          if (g_direction.North <= 7) {
            i149 = (unsigned char)(1 << g_direction.North);
          } else {
            i149 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i149) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_East <= 7) {
              i153 = (unsigned char)(1 << g_d_direction.North_East);
            } else {
              i153 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i153) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i167 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i167 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i167);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i166 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i166 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i166);
                }
              }
            }
          }
        }

        /* ���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.East <= 7) {
          i152 = (unsigned char)(1 << g_direction.East);
        } else {
          i152 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i152) != 0) == wall->contents.nowall) {
          if (g_direction.East <= 7) {
            i154 = (unsigned char)(1 << g_direction.East);
          } else {
            i154 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i154) != 0) == search->contents.known) {
            /* ���i�s�������������ł��鎞 */
            if (g_d_direction.East <= 7) {
              i158 = (unsigned char)(1 << g_d_direction.East);
            } else {
              i158 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i158) != 0) {
              /* �����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 6U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.East <= 7) {
                    i173 = (unsigned char)(1 << g_d_direction.East);
                  } else {
                    i173 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i173);
                }
              }

              /* ���i�s�������������łȂ��Ƃ�     */
            } else {
              /* �����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.East <= 7) {
                    i172 = (unsigned char)(1 << g_d_direction.East);
                  } else {
                    i172 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i172);
                }
              }
            }
          }
        }

        /* �쓌�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.South <= 7) {
          i157 = (unsigned char)(1 << g_direction.South);
        } else {
          i157 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i157) != 0) == wall->contents.nowall) {
          if (g_direction.South <= 7) {
            i159 = (unsigned char)(1 << g_direction.South);
          } else {
            i159 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i159) != 0) == search->contents.known) {
            /* ���i�s�������쓌�����ł��鎞 */
            if (g_d_direction.South_East <= 7) {
              i161 = (unsigned char)(1 << g_d_direction.South_East);
            } else {
              i161 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i161) != 0) {
              /* ���쓌�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_East <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.South_East <= 7) {
                    i169 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i169 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(row_dir_node[(row->data[idx] + 33 *
                    (col->data[idx] - 1)) - 1] | i169);
                }
              }

              /* ���i�s�������쓌�����łȂ��Ƃ�     */
            } else {
              /* ���쓌�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_East <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.South_East <= 7) {
                    i168 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i168 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(row_dir_node[(row->data[idx] + 33 *
                    (col->data[idx] - 1)) - 1] | i168);
                }
              }
            }
          }
        }

        /* �쑤�͒� */
        /* �쐼�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1];
        if (g_direction.South <= 7) {
          i160 = (unsigned char)(1 << g_direction.South);
        } else {
          i160 = 0;
        }

        if (((a & i160) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
            1];
          if (g_direction.South <= 7) {
            i162 = (unsigned char)(1 << g_direction.South);
          } else {
            i162 = 0;
          }

          if (((a & i162) != 0) == search->contents.known) {
            /* ���i�s�������쐼�����ł��鎞 */
            if (g_d_direction.South_West <= 7) {
              i164 = (unsigned char)(1 << g_d_direction.South_West);
            } else {
              i164 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i164) != 0) {
              /* ���쐼�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2))
                    - 1];
                  if (g_d_direction.South_West <= 7) {
                    i176 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i176 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(a | i176);
                }
              }

              /* ���i�s�������쐼�����łȂ��Ƃ�     */
            } else {
              /* ���쐼�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2))
                    - 1];
                  if (g_d_direction.South_West <= 7) {
                    i175 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i175 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(a | i175);
                }
              }
            }
          }
        }

        /* ���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1];
        if (g_direction.West <= 7) {
          i163 = (unsigned char)(1 << g_direction.West);
        } else {
          i163 = 0;
        }

        if (((a & i163) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
            1];
          if (g_direction.West <= 7) {
            i165 = (unsigned char)(1 << g_direction.West);
          } else {
            i165 = 0;
          }

          if (((a & i165) != 0) == search->contents.known) {
            /* ���i�s�������������ł��鎞 */
            if (g_d_direction.West <= 7) {
              i171 = (unsigned char)(1 << g_d_direction.West);
            } else {
              i171 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i171) != 0) {
              /* �����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 6U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 2) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1];
                  if (g_d_direction.West <= 7) {
                    i179 = (unsigned char)(1 << g_d_direction.West);
                  } else {
                    i179 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(a | i179);
                }
              }

              /* ���i�s�������������łȂ��Ƃ�     */
            } else {
              /* �����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 2) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1];
                  if (g_d_direction.West <= 7) {
                    i178 = (unsigned char)(1 << g_d_direction.West);
                  } else {
                    i178 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(a | i178);
                }
              }
            }
          }
        }

        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1];
        if (g_direction.North <= 7) {
          i170 = (unsigned char)(1 << g_direction.North);
        } else {
          i170 = 0;
        }

        if (((a & i170) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
            1];
          if (g_direction.North <= 7) {
            i174 = (unsigned char)(1 << g_direction.North);
          } else {
            i174 = 0;
          }

          if (((a & i174) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_West <= 7) {
              i177 = (unsigned char)(1 << g_d_direction.North_West);
            } else {
              i177 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i177) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] > (int)
                  u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_West <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_West <= 7) {
                    i181 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i181 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(a | i181);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (u9 > 65535U) {
                u9 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] > (int)
                  u9) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u9;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u9;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_West <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u9 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u9 > 65535U) {
                  u9 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] ==
                    (int)u9) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_West <= 7) {
                    i180 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i180 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(a | i180);
                }
              }
            }
          }
        }
      }
    }

    /* �X�V���Ȃ���ΏI��(�X�^�[�g�n�_�̕����}�b�v���X�V)     */
  } while (!(change_flag == 0));

  emxFree_uint16_T(&b_num_temp);
  emxFree_uint16_T(&col);
  emxFree_uint16_T(&row);
  qY = row_num_node[1] + 3U;
  if (qY > 65535U) {
    qY = 65535U;
  }

  *start_num = (unsigned short)qY;
}

/*
 * ���́@���݈ʒux,y,���ݕ���,���H�s�����T�C�Y,���H������T�C�Y,���H�Ǐ��,���H�ǂ̒T�����,�S�[�����W
 * �o��  ���݈ʒux,y,���ݕ���,�Ǐ��,�T�����
 * Arguments    : const coder_internal_ref_5 *wall
 *                coder_internal_ref *wall_flg
 *                const coder_internal_ref_4 *search
 *                const coder_internal_ref_1 *maze_goal
 *                coder_internal_ref_3 *num_temp
 *                unsigned char *current_x
 *                unsigned char *current_y
 *                unsigned char *current_dir
 *                unsigned char maze_row_size
 *                unsigned char maze_col_size
 *                unsigned char maze_wall[1024]
 *                unsigned char maze_wall_search[1024]
 *                const unsigned char exploration_goal[18]
 *                unsigned char *start_flg
 *                unsigned char goal_after_flg
 *                unsigned short contour_map[1024]
 * Return Type  : void
 */
static void b_search_adachi(const coder_internal_ref_5 *wall, coder_internal_ref
  *wall_flg, const coder_internal_ref_4 *search, const coder_internal_ref_1
  *maze_goal, coder_internal_ref_3 *num_temp, unsigned char *current_x, unsigned
  char *current_y, unsigned char *current_dir, unsigned char maze_row_size,
  unsigned char maze_col_size, unsigned char maze_wall[1024], unsigned char
  maze_wall_search[1024], const unsigned char exploration_goal[18], unsigned
  char *start_flg, unsigned char goal_after_flg, unsigned short contour_map[1024])
{
  unsigned char goal_flg;
  int exitg1;
  unsigned char next_dir;
  int q0;
  unsigned int qY;

  /*  search_adachi �����@�ł̒T�� */
  /* local�ϐ��錾 */
  goal_flg = 0U;

  /* �S�[������t���O */
  /*      search_start_x = current_x %�T���J�n��x */
  /*      search_start_y = current_y %�T���J�n��y */
  do {
    exitg1 = 0;

    /* �Ǐ��擾 */
    /* �S�[������͕Ǐ����X�V���Ȃ� */
    if (goal_after_flg != 1) {
      wall_set(wall, wall_flg, search, maze_goal, maze_row_size, maze_col_size, *
               current_x, *current_y, *current_dir, maze_wall, maze_wall_search);
    } else {
      /* �S�[������̂Ƃ� */
      goal_after_flg = 0U;

      /* �S�[������t���O���N���A */
    }

    /*  ������MAP���� */
    /*  [contour_map,max_length] = make_map2(maze_row_size,maze_col_size,maze_goal,maze_wall); */
    make_map_find(num_temp, wall, exploration_goal, 1U, maze_wall, contour_map);

    /* ���݈ʒu���S�[�������� */
    if ((*current_x == exploration_goal[0]) && (*current_y == exploration_goal[9]))
    {
      goal_flg = 1U;
    }

    /* �S�[�������� */
    if (goal_flg == 1) {
      exitg1 = 1;
    } else {
      /*  �i�s�����I�� */
      /* �D�揇�ʁ@�k�˓��˓�ː� */
      next_dir = get_nextdir2(*current_x, *current_y, maze_wall, contour_map);

      /*  ���ݕ����Ɛi�s�����ɉ��������� */
      q0 = (int)(4U + next_dir);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      qY = (unsigned int)q0 - *current_dir;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      next_dir = b_rem((unsigned char)qY);
      if (l_direction.front == next_dir) {
        q0 = 0;
      } else if (l_direction.right == next_dir) {
        q0 = 1;
      } else if (l_direction.back == next_dir) {
        q0 = 2;
      } else if (l_direction.left == next_dir) {
        q0 = 3;
      } else {
        q0 = -1;
      }

      switch (q0) {
       case 0:
        move_step(current_x, current_y, *current_dir);

        /* disp("front") */
        m_move_front(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;

       case 1:
        turn_clk_90deg(current_dir);
        move_step(current_x, current_y, *current_dir);

        /* disp("right") */
        m_move_right(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;

       case 2:
        turn_180deg(current_dir);
        move_step(current_x, current_y, *current_dir);

        /* disp("back") */
        m_move_back(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;

       case 3:
        turn_conclk_90deg(current_dir);
        move_step(current_x, current_y, *current_dir);

        /* disp("left") */
        m_move_left(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;
      }

      /* for code generation */
    }
  } while (exitg1 == 0);

  /* �S�[������~�t���O�������Ă��Ȃ���΁A���삳�����܂܏I�� */
  /*           */
  /*      if coder.target('MATLAB') */
  /*          %for MATLAB     */
  /*          %�T���I����,�}�[�J�[���ǂ��������� */
  /*          %m = makehgtform('translate',50*9,50*9,0); */
  /*          %h.Matrix = m; */
  /*          %�ʂ̎�ނ̃}�[�J�[�����u�� */
  /*          hold on */
  /*          plot(current_x * 9 -4.5,current_y * 9 -4.5,'-ob'); */
  /*          hold off */
  /*          %�T���󋵃v���b�g�𓧖��� */
  /*          serface_transparency(search_surf); */
  /*          drawnow */
  /*      else */
  /*          %for code generation */
  /*      end */
}

/*
 * �X�^�[�g�m�[�h,������ݒ�
 * Arguments    : const unsigned char maze_goal[18]
 *                unsigned char goal_size
 *                const unsigned short row_num_node[1056]
 *                const unsigned short col_num_node[1056]
 *                unsigned char goal_node[2]
 *                unsigned char *goal_matrix_dir
 *                unsigned char *goal_dir
 * Return Type  : void
 */
static void decide_goal_node_dir(const unsigned char maze_goal[18], unsigned
  char goal_size, const unsigned short row_num_node[1056], const unsigned short
  col_num_node[1056], unsigned char goal_node[2], unsigned char *goal_matrix_dir,
  unsigned char *goal_dir)
{
  unsigned char next_matrix_dir;
  unsigned char next_node_idx_0;
  unsigned char next_node_idx_1;
  unsigned short map_min;
  int i110;
  int exitg1;
  unsigned char goal_flag;
  int i;
  bool guard1 = false;
  int i111;
  bool guard2 = false;
  bool guard3 = false;
  bool guard4 = false;
  unsigned int qY;
  unsigned short u7;

  /*  decide_goal_node_dir �S�[���m�[�h�A����ѕ����̊m�� */
  /*  �΂߂̃R���^�[�}�b�v����A�S�[���ƂȂ�m�[�h�ƁA�S�[�����̐i���p�x���m�肷��B */
  *goal_matrix_dir = matrix_dir.Row;

  /* �X�^�[�g�m�[�h�͍s���� */
  /* �X�^�[�g�}�X�̖k�̃m�[�h */
  next_matrix_dir = matrix_dir.Row;

  /* �i�s������̃m�[�h�����i���j */
  goal_node[0] = 2U;
  next_node_idx_0 = 2U;
  goal_node[1] = 1U;
  next_node_idx_1 = 1U;

  /* �i�s������̃m�[�h���W */
  *goal_dir = g_d_direction.North;

  /* �i�s�����i�ŏ��̉��̒l�͖k�����j */
  map_min = MAX_uint16_T;
  i110 = goal_size;
  do {
    exitg1 = 0;
    goal_flag = 0U;
    for (i = 0; i < i110; i++) {
      /* ���݂̃m�[�h���s�����̎� */
      if (*goal_matrix_dir == matrix_dir.Row) {
        /*  %x */
        if (maze_goal[i] == goal_node[1]) {
          guard1 = false;
          if (maze_goal[i + 9] == goal_node[0]) {
            guard1 = true;
          } else {
            i111 = (int)(maze_goal[i + 9] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            if (i111 == goal_node[0]) {
              guard1 = true;
            }
          }

          if (guard1) {
            /* y���W�̈�v */
            /* �i�s������ɕǂ������(�}�b�v�l��65535�ł����)�A�i�s������ύX����i�΂ߐN�����j */
            /* �k�� */
            guard2 = false;
            guard3 = false;
            guard4 = false;
            if (*goal_dir == g_d_direction.North_East) {
              i111 = (int)(goal_node[1] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              if (col_num_node[(goal_node[0] + ((i111 - 1) << 5)) - 1] == 65535)
              {
                *goal_dir = g_d_direction.North;

                /* �쓌 */
              } else {
                guard4 = true;
              }
            } else {
              guard4 = true;
            }

            if (guard4) {
              if (*goal_dir == g_d_direction.South_East) {
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                i111 = (int)(goal_node[1] + 1U);
                if ((unsigned int)i111 > 255U) {
                  i111 = 255;
                }

                if (col_num_node[((int)qY + ((i111 - 1) << 5)) - 1] == 65535) {
                  *goal_dir = g_d_direction.South;

                  /* �쐼 */
                } else {
                  guard3 = true;
                }
              } else {
                guard3 = true;
              }
            }

            if (guard3) {
              if (*goal_dir == g_d_direction.South_West) {
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                if (col_num_node[((int)qY + ((goal_node[1] - 1) << 5)) - 1] ==
                    65535) {
                  *goal_dir = g_d_direction.South;

                  /* �k�� */
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
            }

            if (guard2 && ((*goal_dir == g_d_direction.North_West) &&
                           (col_num_node[(goal_node[0] + ((goal_node[1] - 1) <<
                    5)) - 1] == 65535))) {
              *goal_dir = g_d_direction.North;
            }

            /* �t���O */
            goal_flag = 1U;
          }
        }

        /* ���݂̃m�[�h��������̎� */
      } else {
        /*  %x */
        guard1 = false;
        if (maze_goal[i] == goal_node[1]) {
          guard1 = true;
        } else {
          i111 = (int)(maze_goal[i] + 1U);
          if ((unsigned int)i111 > 255U) {
            i111 = 255;
          }

          if (i111 == goal_node[1]) {
            guard1 = true;
          }
        }

        if (guard1 && (maze_goal[i + 9] == goal_node[0])) {
          /* y���W�̈�v */
          /* �i�s������ɕǂ������(�}�b�v�l��65535�ł����)�A�i�s������ύX����i�΂ߐN�����j */
          /* �k�� */
          guard2 = false;
          guard3 = false;
          if (*goal_dir == g_d_direction.North_East) {
            i111 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            if (row_num_node[(i111 + 33 * (goal_node[1] - 1)) - 1] == 65535) {
              *goal_dir = g_d_direction.East;

              /* �쓌 */
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3) {
            if ((*goal_dir == g_d_direction.South_East) && (row_num_node
                 [(goal_node[0] + 33 * (goal_node[1] - 1)) - 1] == 65535)) {
              *goal_dir = g_d_direction.East;

              /* �쐼 */
            } else if (*goal_dir == g_d_direction.South_West) {
              qY = goal_node[1] - 1U;
              if (qY > goal_node[1]) {
                qY = 0U;
              }

              if (row_num_node[(goal_node[0] + 33 * ((int)qY - 1)) - 1] == 65535)
              {
                *goal_dir = g_d_direction.West;

                /* �k�� */
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }

          if (guard2 && (*goal_dir == g_d_direction.North_West)) {
            i111 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            qY = goal_node[1] - 1U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            if (row_num_node[(i111 + 33 * ((int)qY - 1)) - 1] == 65535) {
              *goal_dir = g_d_direction.West;
            }
          }

          /* �t���O */
          goal_flag = 1U;
        }
      }
    }

    /*              disp("current_node") */
    /*              disp(current_node) */
    /*              disp("current_matrix_dir") */
    /*              disp(current_matrix_dir) */
    /*              disp("current_dir_dgnd") */
    /*              disp(current_dir_dgnd) */
    /* �S�[���m�[�h����̎� */
    /* ���݂̃m�[�h���S�[���m�[�h�Ƃ��A */
    /* ���݂̕������S�[�����̕����Ƃ���B */
    if (goal_flag == 1) {
      exitg1 = 1;
    } else {
      /* ���݂̃m�[�h�̕�������D��I�ɐi�s�������m�� */
      for (i = 0; i < 8; i++) {
        i111 = *goal_dir + i;
        if (i111 > 255) {
          i111 = 255;
        }

        goal_flag = (unsigned char)(i111 % 8);

        /* ���݂̃m�[�h���s�����̎� */
        if (*goal_matrix_dir == matrix_dir.Row) {
          if (goal_flag == g_d_direction.North) {
            i111 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            if (row_num_node[(i111 + 33 * (goal_node[1] - 1)) - 1] < map_min) {
              /* �ŏ��l���X�V */
              i111 = (int)(goal_node[0] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              map_min = row_num_node[(i111 + 33 * (goal_node[1] - 1)) - 1];

              /* ���݃m�[�h�̐i�s������k������ */
              *goal_dir = g_d_direction.North;

              /* �i�s������̍��W�A�s��̕������X�V */
              next_matrix_dir = matrix_dir.Row;
              i111 = (int)(goal_node[0] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              next_node_idx_0 = (unsigned char)i111;
              next_node_idx_1 = goal_node[1];
            }
          } else if (goal_flag == g_d_direction.North_East) {
            i111 = (int)(goal_node[1] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            if (col_num_node[(goal_node[0] + ((i111 - 1) << 5)) - 1] < map_min)
            {
              /* �ŏ��l���X�V */
              i111 = (int)(goal_node[1] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              map_min = col_num_node[(goal_node[0] + ((i111 - 1) << 5)) - 1];

              /* ���݃m�[�h�̐i�s������k������ */
              *goal_dir = g_d_direction.North_East;

              /* �i�s������̍��W�A�s��̕������X�V */
              next_matrix_dir = matrix_dir.Col;
              next_node_idx_0 = goal_node[0];
              i111 = (int)(goal_node[1] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              next_node_idx_1 = (unsigned char)i111;
            }
          } else if (goal_flag != g_d_direction.East) {
            if (goal_flag == g_d_direction.South_East) {
              qY = goal_node[0] - 1U;
              if (qY > goal_node[0]) {
                qY = 0U;
              }

              i111 = (int)(goal_node[1] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              if (col_num_node[((int)qY + ((i111 - 1) << 5)) - 1] < map_min) {
                /* �ŏ��l���X�V */
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                i111 = (int)(goal_node[1] + 1U);
                if ((unsigned int)i111 > 255U) {
                  i111 = 255;
                }

                map_min = col_num_node[((int)qY + ((i111 - 1) << 5)) - 1];

                /* ���݃m�[�h�̐i�s������k������ */
                *goal_dir = g_d_direction.South_East;

                /* �i�s������̍��W�A�s��̕������X�V */
                next_matrix_dir = matrix_dir.Col;
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                next_node_idx_0 = (unsigned char)qY;
                i111 = (int)(goal_node[1] + 1U);
                if ((unsigned int)i111 > 255U) {
                  i111 = 255;
                }

                next_node_idx_1 = (unsigned char)i111;
              }
            } else if (goal_flag == g_d_direction.South) {
              qY = goal_node[0] - 1U;
              if (qY > goal_node[0]) {
                qY = 0U;
              }

              if (row_num_node[((int)qY + 33 * (goal_node[1] - 1)) - 1] <
                  map_min) {
                /* �ŏ��l���X�V */
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                map_min = row_num_node[((int)qY + 33 * (goal_node[1] - 1)) - 1];

                /* ���݃m�[�h�̐i�s������k������ */
                *goal_dir = g_d_direction.South;

                /* �i�s������̍��W�A�s��̕������X�V */
                next_matrix_dir = matrix_dir.Row;
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                next_node_idx_0 = (unsigned char)qY;
                next_node_idx_1 = goal_node[1];
              }
            } else if (goal_flag == g_d_direction.South_West) {
              qY = goal_node[0] - 1U;
              if (qY > goal_node[0]) {
                qY = 0U;
              }

              if (col_num_node[((int)qY + ((goal_node[1] - 1) << 5)) - 1] <
                  map_min) {
                /* �ŏ��l���X�V */
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                map_min = col_num_node[((int)qY + ((goal_node[1] - 1) << 5)) - 1];

                /* ���݃m�[�h�̐i�s������k������ */
                *goal_dir = g_d_direction.South_West;

                /* �i�s������̍��W�A�s��̕������X�V */
                next_matrix_dir = matrix_dir.Col;
                qY = goal_node[0] - 1U;
                if (qY > goal_node[0]) {
                  qY = 0U;
                }

                next_node_idx_0 = (unsigned char)qY;
                next_node_idx_1 = goal_node[1];
              }
            } else if ((goal_flag != g_d_direction.West) && (goal_flag ==
                        g_d_direction.North_West) && (col_num_node[(goal_node[0]
              + ((goal_node[1] - 1) << 5)) - 1] < map_min)) {
              /* �ŏ��l���X�V */
              map_min = col_num_node[(goal_node[0] + ((goal_node[1] - 1) << 5))
                - 1];

              /* ���݃m�[�h�̐i�s������k������ */
              *goal_dir = g_d_direction.North_West;

              /* �i�s������̍��W�A�s��̕������X�V */
              next_matrix_dir = matrix_dir.Col;
              next_node_idx_0 = goal_node[0];
              next_node_idx_1 = goal_node[1];
            } else {
              /* �� */
            }
          } else {
            /* �� */
          }

          /* ���݂̃m�[�h��������̎�         */
        } else if (goal_flag != g_d_direction.North) {
          if (goal_flag == g_d_direction.North_East) {
            i111 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            if (row_num_node[(i111 + 33 * (goal_node[1] - 1)) - 1] < map_min) {
              /* �ŏ��l���X�V */
              i111 = (int)(goal_node[0] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              map_min = row_num_node[(i111 + 33 * (goal_node[1] - 1)) - 1];

              /* ���݃m�[�h�̐i�s������k�������� */
              *goal_dir = g_d_direction.North_East;

              /* �i�s������̍��W�A�s��̕������X�V */
              next_matrix_dir = matrix_dir.Row;
              i111 = (int)(goal_node[0] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              next_node_idx_0 = (unsigned char)i111;
              next_node_idx_1 = goal_node[1];
            }
          } else if (goal_flag == g_d_direction.East) {
            i111 = (int)(goal_node[1] + 1U);
            if ((unsigned int)i111 > 255U) {
              i111 = 255;
            }

            if (col_num_node[(goal_node[0] + ((i111 - 1) << 5)) - 1] < map_min)
            {
              /* �ŏ��l���X�V */
              i111 = (int)(goal_node[1] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              map_min = col_num_node[(goal_node[0] + ((i111 - 1) << 5)) - 1];

              /* ���݃m�[�h�̐i�s�����𓌌����� */
              *goal_dir = g_d_direction.East;

              /* �i�s������̍��W�A�s��̕������X�V */
              next_matrix_dir = matrix_dir.Col;
              next_node_idx_0 = goal_node[0];
              i111 = (int)(goal_node[1] + 1U);
              if ((unsigned int)i111 > 255U) {
                i111 = 255;
              }

              next_node_idx_1 = (unsigned char)i111;
            }
          } else if (goal_flag == g_d_direction.South_East) {
            u7 = row_num_node[(goal_node[0] + 33 * (goal_node[1] - 1)) - 1];
            if (u7 < map_min) {
              /* �ŏ��l���X�V */
              map_min = u7;

              /* ���݃m�[�h�̐i�s������쓌������ */
              *goal_dir = g_d_direction.South_East;

              /* �i�s������̍��W�A�s��̕������X�V */
              next_matrix_dir = matrix_dir.Row;
              next_node_idx_0 = goal_node[0];
              next_node_idx_1 = goal_node[1];
            }
          } else if (goal_flag != g_d_direction.South) {
            if (goal_flag == g_d_direction.South_West) {
              qY = goal_node[1] - 1U;
              if (qY > goal_node[1]) {
                qY = 0U;
              }

              if (row_num_node[(goal_node[0] + 33 * ((int)qY - 1)) - 1] <
                  map_min) {
                /* �ŏ��l���X�V */
                qY = goal_node[1] - 1U;
                if (qY > goal_node[1]) {
                  qY = 0U;
                }

                map_min = row_num_node[(goal_node[0] + 33 * ((int)qY - 1)) - 1];

                /* ���݃m�[�h�̐i�s������쐼������ */
                *goal_dir = g_d_direction.South_West;

                /* �i�s������̍��W�A�s��̕������X�V */
                next_matrix_dir = matrix_dir.Row;
                next_node_idx_0 = goal_node[0];
                qY = goal_node[1] - 1U;
                if (qY > goal_node[1]) {
                  qY = 0U;
                }

                next_node_idx_1 = (unsigned char)qY;
              }
            } else if (goal_flag == g_d_direction.West) {
              qY = goal_node[1] - 1U;
              if (qY > goal_node[1]) {
                qY = 0U;
              }

              if (col_num_node[(goal_node[0] + (((int)qY - 1) << 5)) - 1] <
                  map_min) {
                /* �ŏ��l���X�V */
                qY = goal_node[1] - 1U;
                if (qY > goal_node[1]) {
                  qY = 0U;
                }

                map_min = col_num_node[(goal_node[0] + (((int)qY - 1) << 5)) - 1];

                /* ���݃m�[�h�̐i�s�����𐼌����� */
                *goal_dir = g_d_direction.West;

                /* �i�s������̍��W�A�s��̕������X�V */
                next_matrix_dir = matrix_dir.Col;
                next_node_idx_0 = goal_node[0];
                qY = goal_node[1] - 1U;
                if (qY > goal_node[1]) {
                  qY = 0U;
                }

                next_node_idx_1 = (unsigned char)qY;
              }
            } else {
              if (goal_flag == g_d_direction.North_West) {
                i111 = (int)(goal_node[0] + 1U);
                if ((unsigned int)i111 > 255U) {
                  i111 = 255;
                }

                qY = goal_node[1] - 1U;
                if (qY > goal_node[1]) {
                  qY = 0U;
                }

                if (row_num_node[(i111 + 33 * ((int)qY - 1)) - 1] < map_min) {
                  /* �ŏ��l���X�V */
                  i111 = (int)(goal_node[0] + 1U);
                  if ((unsigned int)i111 > 255U) {
                    i111 = 255;
                  }

                  qY = goal_node[1] - 1U;
                  if (qY > goal_node[1]) {
                    qY = 0U;
                  }

                  map_min = row_num_node[(i111 + 33 * ((int)qY - 1)) - 1];

                  /* ���݃m�[�h�̐i�s������k�������� */
                  *goal_dir = g_d_direction.North_West;

                  /* �i�s������̍��W�A�s��̕������X�V */
                  next_matrix_dir = matrix_dir.Row;
                  i111 = (int)(goal_node[0] + 1U);
                  if ((unsigned int)i111 > 255U) {
                    i111 = 255;
                  }

                  next_node_idx_0 = (unsigned char)i111;
                  qY = goal_node[1] - 1U;
                  if (qY > goal_node[1]) {
                    qY = 0U;
                  }

                  next_node_idx_1 = (unsigned char)qY;
                }
              }
            }
          } else {
            /* �� */
          }
        } else {
          /* �� */
        }
      }

      goal_node[0] = next_node_idx_0;
      goal_node[1] = next_node_idx_1;
      *goal_matrix_dir = next_matrix_dir;
    }
  } while (exitg1 == 0);

  /*  */
}

/*
 * Arguments    : const unsigned char maze_goal[18]
 *                const unsigned char goal_node[2]
 *                unsigned char goal_matrix_dir
 *                unsigned char goal_dir
 *                unsigned char goal_section[2]
 *                unsigned char goal_node2[2]
 *                unsigned char *goal_matrix_dir2
 * Return Type  : void
 */
static void decide_goal_section(const unsigned char maze_goal[18], const
  unsigned char goal_node[2], unsigned char goal_matrix_dir, unsigned char
  goal_dir, unsigned char goal_section[2], unsigned char goal_node2[2], unsigned
  char *goal_matrix_dir2)
{
  int i112;
  int ex;
  unsigned int qY;
  int k;
  unsigned int b_qY;
  unsigned char uv0[18];
  bool temp1[18];
  signed char varargin_1[9];

  /*  decide_goal_section �S�[���}�X�̊m�� */
  /*  �m�肳�ꂽ�S�[���̃m�[�h�ƁA�S�[�����̐i���p�x����A */
  /*  �S�[���}�X���m�肷��B */
  /* (y,x) */
  goal_section[0] = 1U;
  goal_node2[0] = 1U;
  goal_section[1] = 1U;
  goal_node2[1] = 1U;
  *goal_matrix_dir2 = matrix_dir.Row;
  if (goal_dir == g_d_direction.North) {
    if (goal_matrix_dir == matrix_dir.Row) {
      i112 = (int)(goal_node[0] + 1U);
      ex = i112;
      if ((unsigned int)i112 > 255U) {
        ex = 255;
      }

      if (goal_judge(maze_goal, goal_node[1], (unsigned char)ex) != 0.0) {
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[0] = (unsigned char)i112;
        goal_section[1] = goal_node[1];

        /* (y,x) */
        goal_node2[0] = (unsigned char)i112;
        goal_node2[1] = goal_node[1];
      } else {
        goal_section[0] = goal_node[0];
        goal_section[1] = goal_node[1];

        /* (y,x) */
        goal_node2[0] = goal_node[0];
        goal_node2[1] = goal_node[1];
      }
    }

    /* ������͒��Ȃ̂łȂ� */
  } else if (goal_dir == g_d_direction.North_East) {
    if (goal_matrix_dir == matrix_dir.Row) {
      i112 = (int)(goal_node[1] + 1U);
      if ((unsigned int)i112 > 255U) {
        i112 = 255;
      }

      ex = (int)(goal_node[0] + 1U);
      if ((unsigned int)ex > 255U) {
        ex = 255;
      }

      if (goal_judge(maze_goal, (unsigned char)i112, (unsigned char)ex) != 0.0)
      {
        i112 = (int)(goal_node[0] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[0] = (unsigned char)i112;
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[1] = (unsigned char)i112;

        /* (y,x) */
        i112 = (int)(goal_node[0] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_node2[0] = (unsigned char)i112;
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_node2[1] = (unsigned char)i112;
      } else {
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        if (goal_judge(maze_goal, (unsigned char)i112, goal_node[0]) != 0.0) {
          goal_section[0] = goal_node[0];
          i112 = (int)(goal_node[1] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_section[1] = (unsigned char)i112;

          /* (y,x) */
          goal_node2[0] = goal_node[0];
          i112 = (int)(goal_node[1] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_node2[1] = (unsigned char)i112;
          *goal_matrix_dir2 = matrix_dir.Col;
        } else {
          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          if (goal_judge(maze_goal, goal_node[1], (unsigned char)i112) != 0.0) {
            i112 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_section[0] = (unsigned char)i112;
            goal_section[1] = goal_node[1];

            /* (y,x) */
            i112 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_node2[0] = (unsigned char)i112;
            goal_node2[1] = goal_node[1];
          } else {
            goal_section[0] = goal_node[0];
            goal_section[1] = goal_node[1];

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
          }
        }
      }
    } else {
      i112 = (int)(goal_node[1] + 1U);
      ex = i112;
      if ((unsigned int)i112 > 255U) {
        ex = 255;
      }

      k = (int)(goal_node[0] + 1U);
      if ((unsigned int)k > 255U) {
        k = 255;
      }

      if (goal_judge(maze_goal, (unsigned char)ex, (unsigned char)k) != 0.0) {
        ex = (int)(goal_node[0] + 1U);
        if ((unsigned int)ex > 255U) {
          ex = 255;
        }

        goal_section[0] = (unsigned char)ex;
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[1] = (unsigned char)i112;

        /* (y,x) */
        goal_node2[0] = (unsigned char)ex;
        goal_node2[1] = (unsigned char)i112;
        *goal_matrix_dir2 = matrix_dir.Col;
      } else {
        ex = (int)(goal_node[0] + 1U);
        if ((unsigned int)ex > 255U) {
          ex = 255;
        }

        if (goal_judge(maze_goal, goal_node[1], (unsigned char)ex) != 0.0) {
          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_section[0] = (unsigned char)i112;
          goal_section[1] = goal_node[1];

          /* (y,x) */
          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_node2[0] = (unsigned char)i112;
          goal_node2[1] = goal_node[1];
        } else {
          ex = i112;
          if ((unsigned int)i112 > 255U) {
            ex = 255;
          }

          if (goal_judge(maze_goal, (unsigned char)ex, goal_node[0]) != 0.0) {
            goal_section[0] = goal_node[0];
            ex = i112;
            if ((unsigned int)i112 > 255U) {
              ex = 255;
            }

            goal_section[1] = (unsigned char)ex;

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_node2[1] = (unsigned char)i112;
            *goal_matrix_dir2 = matrix_dir.Col;
          } else {
            goal_section[0] = goal_node[0];
            goal_section[1] = goal_node[1];

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
            *goal_matrix_dir2 = matrix_dir.Col;
          }
        }
      }
    }
  } else if (goal_dir == g_d_direction.East) {
    /* �s�����͒��Ȃ̂łȂ� */
    if (goal_matrix_dir == matrix_dir.Col) {
      i112 = (int)(goal_node[1] + 1U);
      if ((unsigned int)i112 > 255U) {
        i112 = 255;
      }

      if (goal_judge(maze_goal, (unsigned char)i112, goal_node[0]) != 0.0) {
        goal_section[0] = goal_node[0];
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[1] = (unsigned char)i112;

        /* (y,x) */
        goal_node2[0] = goal_node[0];
        goal_node2[1] = (unsigned char)i112;
        *goal_matrix_dir2 = matrix_dir.Col;
      } else {
        goal_section[0] = goal_node[0];
        goal_section[1] = goal_node[1];

        /* (y,x) */
        goal_node2[0] = goal_node[0];
        goal_node2[1] = goal_node[1];
        *goal_matrix_dir2 = matrix_dir.Col;
      }
    }
  } else if (goal_dir == g_d_direction.South_East) {
    if (goal_matrix_dir == matrix_dir.Row) {
      i112 = (int)(goal_node[1] + 1U);
      if ((unsigned int)i112 > 255U) {
        i112 = 255;
      }

      qY = goal_node[0] - 2U;
      if (qY > goal_node[0]) {
        qY = 0U;
      }

      if (goal_judge(maze_goal, (unsigned char)i112, (unsigned char)qY) != 0.0)
      {
        qY = goal_node[0] - 2U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_section[0] = (unsigned char)qY;
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[1] = (unsigned char)i112;

        /* (y,x) */
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_node2[0] = (unsigned char)qY;
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_node2[1] = (unsigned char)i112;
      } else {
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        if (goal_judge(maze_goal, (unsigned char)i112, (unsigned char)qY) != 0.0)
        {
          qY = goal_node[0] - 1U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          goal_section[0] = (unsigned char)qY;
          i112 = (int)(goal_node[1] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_section[1] = (unsigned char)i112;

          /* (y,x) */
          qY = goal_node[0] - 1U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          goal_node2[0] = (unsigned char)qY;
          i112 = (int)(goal_node[1] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_node2[1] = (unsigned char)i112;
          *goal_matrix_dir2 = matrix_dir.Col;
        } else {
          qY = goal_node[0] - 2U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          if (goal_judge(maze_goal, goal_node[1], (unsigned char)qY) != 0.0) {
            qY = goal_node[0] - 1U;
            if (qY > goal_node[0]) {
              qY = 0U;
            }

            goal_section[0] = (unsigned char)qY;
            goal_section[1] = goal_node[1];

            /* (y,x) */
            qY = goal_node[0] - 1U;
            if (qY > goal_node[0]) {
              qY = 0U;
            }

            goal_node2[0] = (unsigned char)qY;
            goal_node2[1] = goal_node[1];
          } else {
            qY = goal_node[0] - 1U;
            if (qY > goal_node[0]) {
              qY = 0U;
            }

            goal_section[0] = (unsigned char)qY;
            goal_section[1] = goal_node[1];

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
          }
        }
      }
    } else {
      i112 = (int)(goal_node[1] + 1U);
      if ((unsigned int)i112 > 255U) {
        i112 = 255;
      }

      qY = goal_node[0] - 1U;
      if (qY > goal_node[0]) {
        qY = 0U;
      }

      if (goal_judge(maze_goal, (unsigned char)i112, (unsigned char)qY) != 0.0)
      {
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_section[0] = (unsigned char)qY;
        i112 = (int)(goal_node[1] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        goal_section[1] = (unsigned char)i112;

        /* (y,x) */
        goal_node2[0] = (unsigned char)qY;
        goal_node2[1] = (unsigned char)i112;
        *goal_matrix_dir2 = matrix_dir.Col;
      } else {
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        if (goal_judge(maze_goal, goal_node[1], (unsigned char)qY) != 0.0) {
          qY = goal_node[0] - 1U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          goal_section[0] = (unsigned char)qY;
          goal_section[1] = goal_node[1];

          /* (y,x) */
          goal_node2[0] = goal_node[0];
          goal_node2[1] = goal_node[1];
        } else {
          i112 = (int)(goal_node[1] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          if (goal_judge(maze_goal, (unsigned char)i112, goal_node[0]) != 0.0) {
            goal_section[0] = goal_node[0];
            i112 = (int)(goal_node[1] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_section[1] = (unsigned char)i112;

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            i112 = (int)(goal_node[1] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_node2[1] = (unsigned char)i112;
            *goal_matrix_dir2 = matrix_dir.Col;
          } else {
            goal_section[0] = goal_node[0];
            goal_section[1] = goal_node[1];

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
            *goal_matrix_dir2 = matrix_dir.Col;
          }
        }
      }
    }
  } else if (goal_dir == g_d_direction.South) {
    if (goal_matrix_dir == matrix_dir.Row) {
      qY = goal_node[0] - 2U;
      if (qY > goal_node[0]) {
        qY = 0U;
      }

      if (goal_judge(maze_goal, goal_node[1], (unsigned char)qY) != 0.0) {
        qY = goal_node[0] - 2U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_section[0] = (unsigned char)qY;
        goal_section[1] = goal_node[1];

        /* (y,x) */
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_node2[0] = (unsigned char)qY;
        goal_node2[1] = goal_node[1];
      } else {
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_section[0] = (unsigned char)qY;
        goal_section[1] = goal_node[1];

        /* (y,x) */
        goal_node2[0] = goal_node[0];
        goal_node2[1] = goal_node[1];
      }
    }
  } else if (goal_dir == g_d_direction.South_West) {
    if (goal_matrix_dir == matrix_dir.Row) {
      qY = goal_node[1] - 1U;
      if (qY > goal_node[1]) {
        qY = 0U;
      }

      b_qY = goal_node[0] - 2U;
      if (b_qY > goal_node[0]) {
        b_qY = 0U;
      }

      if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)b_qY) != 0.0)
      {
        qY = goal_node[0] - 2U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_section[0] = (unsigned char)qY;
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_section[1] = (unsigned char)qY;

        /* (y,x) */
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_node2[0] = (unsigned char)qY;
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_node2[1] = (unsigned char)qY;
      } else {
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        b_qY = goal_node[0] - 1U;
        if (b_qY > goal_node[0]) {
          b_qY = 0U;
        }

        if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)b_qY) != 0.0)
        {
          qY = goal_node[0] - 1U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          goal_section[0] = (unsigned char)qY;
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          goal_section[1] = (unsigned char)qY;

          /* (y,x) */
          qY = goal_node[0] - 1U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          goal_node2[0] = (unsigned char)qY;
          goal_node2[1] = goal_node[1];
          *goal_matrix_dir2 = matrix_dir.Col;
        } else {
          qY = goal_node[0] - 2U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          if (goal_judge(maze_goal, goal_node[1], (unsigned char)qY) != 0.0) {
            qY = goal_node[0] - 2U;
            if (qY > goal_node[0]) {
              qY = 0U;
            }

            goal_section[0] = (unsigned char)qY;
            goal_section[1] = goal_node[1];

            /* (y,x) */
            qY = goal_node[0] - 1U;
            if (qY > goal_node[0]) {
              qY = 0U;
            }

            goal_node2[0] = (unsigned char)qY;
            goal_node2[1] = goal_node[1];
          } else {
            qY = goal_node[0] - 1U;
            if (qY > goal_node[0]) {
              qY = 0U;
            }

            goal_section[0] = (unsigned char)qY;
            goal_section[1] = goal_node[1];

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
          }
        }
      }
    } else {
      qY = goal_node[1] - 1U;
      if (qY > goal_node[1]) {
        qY = 0U;
      }

      b_qY = goal_node[0] - 2U;
      if (b_qY > goal_node[0]) {
        b_qY = 0U;
      }

      if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)b_qY) != 0.0)
      {
        qY = goal_node[0] - 2U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_section[0] = (unsigned char)qY;
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_section[1] = (unsigned char)qY;

        /* (y,x) */
        qY = goal_node[0] - 1U;
        if (qY > goal_node[0]) {
          qY = 0U;
        }

        goal_node2[0] = (unsigned char)qY;
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_node2[1] = (unsigned char)qY;
        *goal_matrix_dir2 = matrix_dir.Col;
      } else {
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        b_qY = goal_node[0] - 1U;
        if (b_qY > goal_node[0]) {
          b_qY = 0U;
        }

        if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)b_qY) != 0.0)
        {
          qY = goal_node[0] - 1U;
          if (qY > goal_node[0]) {
            qY = 0U;
          }

          goal_section[0] = (unsigned char)qY;
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          goal_section[1] = (unsigned char)qY;

          /* (y,x) */
          goal_node2[0] = goal_node[0];
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          goal_node2[1] = (unsigned char)qY;
        } else {
          qY = goal_node[1] - 2U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          if (goal_judge(maze_goal, (unsigned char)qY, goal_node[0]) != 0.0) {
            goal_section[0] = goal_node[0];
            qY = goal_node[1] - 2U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            goal_section[1] = (unsigned char)qY;

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            qY = goal_node[1] - 1U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            goal_node2[1] = (unsigned char)qY;
            *goal_matrix_dir2 = matrix_dir.Col;
          } else {
            goal_section[0] = goal_node[0];
            qY = goal_node[1] - 1U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            goal_section[1] = (unsigned char)qY;

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
            *goal_matrix_dir2 = matrix_dir.Col;
          }
        }
      }
    }
  } else if (goal_dir == g_d_direction.West) {
    /* �s�����͒��Ȃ̂łȂ� */
    if (goal_matrix_dir == matrix_dir.Col) {
      qY = goal_node[1] - 2U;
      if (qY > goal_node[1]) {
        qY = 0U;
      }

      if (goal_judge(maze_goal, (unsigned char)qY, goal_node[0]) != 0.0) {
        goal_section[0] = goal_node[0];
        qY = goal_node[1] - 2U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_section[1] = (unsigned char)qY;

        /* (y,x) */
        goal_node2[0] = goal_node[0];
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_node2[1] = (unsigned char)qY;
        *goal_matrix_dir2 = matrix_dir.Col;
      } else {
        goal_section[0] = goal_node[0];
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        goal_section[1] = (unsigned char)qY;

        /* (y,x) */
        goal_node2[0] = goal_node[0];
        goal_node2[1] = goal_node[1];
        *goal_matrix_dir2 = matrix_dir.Col;
      }
    }
  } else {
    if (goal_dir == g_d_direction.North_West) {
      if (goal_matrix_dir == matrix_dir.Row) {
        qY = goal_node[1] - 1U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        i112 = (int)(goal_node[0] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)i112) != 0.0)
        {
          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_section[0] = (unsigned char)i112;
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          goal_section[1] = (unsigned char)qY;

          /* (y,x) */
          goal_node2[0] = (unsigned char)i112;
          goal_node2[1] = (unsigned char)qY;
        } else {
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          if (goal_judge(maze_goal, (unsigned char)qY, goal_node[0]) != 0.0) {
            goal_section[0] = goal_node[0];
            qY = goal_node[1] - 1U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            goal_section[1] = (unsigned char)qY;

            /* (y,x) */
            goal_node2[0] = goal_node[0];
            goal_node2[1] = goal_node[1];
            *goal_matrix_dir2 = matrix_dir.Col;
          } else {
            i112 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            if (goal_judge(maze_goal, goal_node[1], (unsigned char)i112) != 0.0)
            {
              i112 = (int)(goal_node[0] + 1U);
              if ((unsigned int)i112 > 255U) {
                i112 = 255;
              }

              goal_section[0] = (unsigned char)i112;
              goal_section[1] = goal_node[1];

              /* (y,x) */
              i112 = (int)(goal_node[0] + 1U);
              if ((unsigned int)i112 > 255U) {
                i112 = 255;
              }

              goal_node2[0] = (unsigned char)i112;
              goal_node2[1] = goal_node[1];
            } else {
              goal_section[0] = goal_node[0];
              goal_section[1] = goal_node[1];

              /* (y,x) */
              goal_node2[0] = goal_node[0];
              goal_node2[1] = goal_node[1];
            }
          }
        }
      } else {
        qY = goal_node[1] - 2U;
        if (qY > goal_node[1]) {
          qY = 0U;
        }

        i112 = (int)(goal_node[0] + 1U);
        if ((unsigned int)i112 > 255U) {
          i112 = 255;
        }

        if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)i112) != 0.0)
        {
          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_section[0] = (unsigned char)i112;
          qY = goal_node[1] - 2U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          goal_section[1] = (unsigned char)qY;

          /* (y,x) */
          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          goal_node2[0] = (unsigned char)i112;
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          goal_node2[1] = (unsigned char)qY;
          *goal_matrix_dir2 = matrix_dir.Col;
        } else {
          qY = goal_node[1] - 1U;
          if (qY > goal_node[1]) {
            qY = 0U;
          }

          i112 = (int)(goal_node[0] + 1U);
          if ((unsigned int)i112 > 255U) {
            i112 = 255;
          }

          if (goal_judge(maze_goal, (unsigned char)qY, (unsigned char)i112) !=
              0.0) {
            i112 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_section[0] = (unsigned char)i112;
            qY = goal_node[1] - 1U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            goal_section[1] = (unsigned char)qY;

            /* (y,x) */
            i112 = (int)(goal_node[0] + 1U);
            if ((unsigned int)i112 > 255U) {
              i112 = 255;
            }

            goal_node2[0] = (unsigned char)i112;
            qY = goal_node[1] - 1U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            goal_node2[1] = (unsigned char)qY;
          } else {
            qY = goal_node[1] - 2U;
            if (qY > goal_node[1]) {
              qY = 0U;
            }

            /* ���͍��W�̔z����쐬 */
            /* �S�[������֐� */
            /* �S�[�����W�Ɣ�r */
            for (i112 = 0; i112 < 9; i112++) {
              uv0[i112] = (unsigned char)qY;
              uv0[9 + i112] = goal_node[0];
            }

            for (i112 = 0; i112 < 18; i112++) {
              temp1[i112] = (maze_goal[i112] == uv0[i112]);
            }

            /* x,y�Ƃ��Ɉ�v���邩�m�F�A��v�Ȃ�1��Ԃ� */
            for (i112 = 0; i112 < 9; i112++) {
              varargin_1[i112] = (signed char)(temp1[i112] * temp1[9 + i112]);
            }

            ex = varargin_1[0];
            for (k = 0; k < 8; k++) {
              i112 = varargin_1[k + 1];
              if (ex < i112) {
                ex = i112;
              }
            }

            if (ex != 0) {
              goal_section[0] = goal_node[0];
              qY = goal_node[1] - 2U;
              if (qY > goal_node[1]) {
                qY = 0U;
              }

              goal_section[1] = (unsigned char)qY;

              /* (y,x) */
              goal_node2[0] = goal_node[0];
              qY = goal_node[1] - 1U;
              if (qY > goal_node[1]) {
                qY = 0U;
              }

              goal_node2[1] = (unsigned char)qY;
              *goal_matrix_dir2 = matrix_dir.Col;
            } else {
              goal_section[0] = goal_node[0];
              qY = goal_node[1] - 1U;
              if (qY > goal_node[1]) {
                qY = 0U;
              }

              goal_section[1] = (unsigned char)qY;

              /* (y,x) */
              goal_node2[0] = goal_node[0];
              goal_node2[1] = goal_node[1];
              *goal_matrix_dir2 = matrix_dir.Col;
            }
          }
        }
      }
    }
  }
}

/*
 * ���́@�Ǐ��,�ǒT�����,������MAP,�S�[�����W,�ő�o�H��
 * �o��
 * Arguments    : coder_internal_ref *current_x
 *                coder_internal_ref *current_y
 *                coder_internal_ref *current_dir
 *                const coder_internal_ref *goal_size
 *                const coder_internal_ref_5 *wall
 *                const unsigned char maze_wall[1024]
 *                const unsigned short contour_map[1024]
 *                const unsigned char maze_goal[18]
 *                unsigned short max_length
 * Return Type  : void
 */
static void fust_run(coder_internal_ref *current_x, coder_internal_ref
                     *current_y, coder_internal_ref *current_dir, const
                     coder_internal_ref *goal_size, const coder_internal_ref_5
                     *wall, const unsigned char maze_wall[1024], const unsigned
                     short contour_map[1024], const unsigned char maze_goal[18],
                     unsigned short max_length)
{
  unsigned char goal_flag;
  unsigned short little;
  unsigned char next_dir;
  int exitg1;
  unsigned char a;
  int q0;
  int tempi;
  int i31;
  int i32;
  int i33;
  unsigned int qY;
  int i34;
  unsigned char u4;
  unsigned char b_current_dir;

  /*  fust_run �ŒZ�o�H���o */
  /* local�ϐ��錾 */
  goal_flag = 0U;

  /* �S�[������t���O */
  little = max_length;

  /* �i�s�����I��p臒l */
  /* �}�E�X�ʒu�\���p�I�u�W�F�N�g */
  /* �}�E�X�̏����ʒu�ݒ� */
  current_x->contents = 1U;
  current_y->contents = 1U;
  current_dir->contents = g_direction.North;
  next_dir = g_direction.North;

  /* �T���J�n��x */
  /* �T���J�n��y */
  /* �T���J�n�ʒu�v���b�g */
  /*      %���Ճv���b�g */
  /*      hold on */
  /*      plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r'); */
  /*      hold off */
  /*      drawnow limitrate nocallbacks */
  do {
    exitg1 = 0;

    /* ���݈ʒu���S�[�������� */
    a = goal_size->contents;
    q0 = a;
    for (tempi = 0; tempi < q0; tempi++) {
      if ((current_x->contents == maze_goal[tempi]) && (current_y->contents ==
           maze_goal[tempi + 9])) {
        goal_flag = 1U;
      }
    }

    if (goal_flag == 1) {
      exitg1 = 1;
    } else {
      /*             %%�i�s�����I�� */
      /* �D�揇�ʁ@�k�˓��˓�ː� */
      /* �k���̕ǂ̂���Ȃ� */
      a = maze_wall[(current_y->contents + ((current_x->contents - 1) << 5)) - 1];
      if (g_direction.North <= 7) {
        i31 = (unsigned char)(1 << g_direction.North);
      } else {
        i31 = 0;
      }

      if ((a & i31) == wall->contents.nowall) {
        /* �k���̓�����map��臒l���Ⴏ��΁A */
        q0 = (int)(current_y->contents + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        if (contour_map[(q0 + ((current_x->contents - 1) << 5)) - 1] < little) {
          /* 臒l��k���̓���map�l�ɕύX */
          q0 = (int)(current_y->contents + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          little = contour_map[(q0 + ((current_x->contents - 1) << 5)) - 1];

          /* �k����i�s�����ɕύXy */
          next_dir = g_direction.North;
        }
      }

      /* ���� */
      a = maze_wall[(current_y->contents + ((current_x->contents - 1) << 5)) - 1];
      if (g_direction.East <= 7) {
        i32 = (unsigned char)(1 << g_direction.East);
      } else {
        i32 = 0;
      }

      if ((a & i32) == wall->contents.nowall) {
        q0 = (int)(current_x->contents + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        if (contour_map[(current_y->contents + ((q0 - 1) << 5)) - 1] < little) {
          q0 = (int)(current_x->contents + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          little = contour_map[(current_y->contents + ((q0 - 1) << 5)) - 1];
          next_dir = g_direction.East;
        }
      }

      /* �쑤 */
      a = maze_wall[(current_y->contents + ((current_x->contents - 1) << 5)) - 1];
      if (g_direction.South <= 7) {
        i33 = (unsigned char)(1 << g_direction.South);
      } else {
        i33 = 0;
      }

      if ((a & i33) == wall->contents.nowall) {
        q0 = current_y->contents;
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        if (contour_map[((int)qY + ((current_x->contents - 1) << 5)) - 1] <
            little) {
          q0 = current_y->contents;
          qY = q0 - 1U;
          if (qY > (unsigned int)q0) {
            qY = 0U;
          }

          little = contour_map[((int)qY + ((current_x->contents - 1) << 5)) - 1];
          next_dir = g_direction.South;
        }
      }

      /* ���� */
      a = maze_wall[(current_y->contents + ((current_x->contents - 1) << 5)) - 1];
      if (g_direction.West <= 7) {
        i34 = (unsigned char)(1 << g_direction.West);
      } else {
        i34 = 0;
      }

      if ((a & i34) == wall->contents.nowall) {
        q0 = current_x->contents;
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        if (contour_map[(current_y->contents + (((int)qY - 1) << 5)) - 1] <
            little) {
          q0 = current_x->contents;
          qY = q0 - 1U;
          if (qY > (unsigned int)q0) {
            qY = 0U;
          }

          little = contour_map[(current_y->contents + (((int)qY - 1) << 5)) - 1];
          next_dir = g_direction.West;
        }
      }

      /*             %%���ݕ����Ɛi�s�����ɉ��������� */
      q0 = (int)(4U + next_dir);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      qY = (unsigned int)q0 - current_dir->contents;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      a = (unsigned char)((unsigned char)qY % 4);
      if (l_direction.front == a) {
        q0 = 0;
      } else if (l_direction.right == a) {
        q0 = 1;
      } else if (l_direction.back == a) {
        q0 = 2;
      } else if (l_direction.left == a) {
        q0 = 3;
      } else {
        q0 = -1;
      }

      switch (q0) {
       case 0:
        a = current_x->contents;
        u4 = current_y->contents;
        b_current_dir = current_dir->contents;

        /* ���� ���݈ʒux,y,���ݕ��� */
        /* �o�� ���݈ʒux,y */
        /*  move_step ��}�X�O�i����֐� */
        /* �k�Ɉ�}�X */
        if (b_current_dir == g_direction.North) {
          q0 = (int)(u4 + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          u4 = (unsigned char)q0;

          /* disp("north_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.East) {
          q0 = (int)(a + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          a = (unsigned char)q0;

          /* disp("east_step") */
        }

        /* ��Ɉ�}�X */
        if (b_current_dir == g_direction.South) {
          qY = u4 - 1U;
          if (qY > u4) {
            qY = 0U;
          }

          u4 = (unsigned char)qY;

          /* disp("south_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.West) {
          qY = a - 1U;
          if (qY > a) {
            qY = 0U;
          }

          a = (unsigned char)qY;

          /* disp("west_step") */
        }

        current_x->contents = a;
        current_y->contents = u4;

        /* disp("front") */
        break;

       case 1:
        a = current_dir->contents;

        /* ���� ���ݕ��� */
        /* �o�� ���ݕ��� */
        /*  turn_clk_90deg ���v�����90�x�^�[������֐�  */
        q0 = (int)(4U + a);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        q0++;
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_dir->contents = (unsigned char)(q0 % 4);
        a = current_x->contents;
        u4 = current_y->contents;
        b_current_dir = current_dir->contents;

        /* ���� ���݈ʒux,y,���ݕ��� */
        /* �o�� ���݈ʒux,y */
        /*  move_step ��}�X�O�i����֐� */
        /* �k�Ɉ�}�X */
        if (b_current_dir == g_direction.North) {
          q0 = (int)(u4 + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          u4 = (unsigned char)q0;

          /* disp("north_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.East) {
          q0 = (int)(a + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          a = (unsigned char)q0;

          /* disp("east_step") */
        }

        /* ��Ɉ�}�X */
        if (b_current_dir == g_direction.South) {
          qY = u4 - 1U;
          if (qY > u4) {
            qY = 0U;
          }

          u4 = (unsigned char)qY;

          /* disp("south_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.West) {
          qY = a - 1U;
          if (qY > a) {
            qY = 0U;
          }

          a = (unsigned char)qY;

          /* disp("west_step") */
        }

        current_x->contents = a;
        current_y->contents = u4;

        /* disp("right") */
        break;

       case 2:
        a = current_dir->contents;

        /* ���� ���ݕ��� */
        /* �o�� ���ݕ��� */
        /*  turn_180deg 180�x�^�[������֐� */
        q0 = (int)(4U + a);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_dir->contents = (unsigned char)((q0 - 2) % 4);
        a = current_x->contents;
        u4 = current_y->contents;
        b_current_dir = current_dir->contents;

        /* ���� ���݈ʒux,y,���ݕ��� */
        /* �o�� ���݈ʒux,y */
        /*  move_step ��}�X�O�i����֐� */
        /* �k�Ɉ�}�X */
        if (b_current_dir == g_direction.North) {
          q0 = (int)(u4 + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          u4 = (unsigned char)q0;

          /* disp("north_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.East) {
          q0 = (int)(a + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          a = (unsigned char)q0;

          /* disp("east_step") */
        }

        /* ��Ɉ�}�X */
        if (b_current_dir == g_direction.South) {
          qY = u4 - 1U;
          if (qY > u4) {
            qY = 0U;
          }

          u4 = (unsigned char)qY;

          /* disp("south_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.West) {
          qY = a - 1U;
          if (qY > a) {
            qY = 0U;
          }

          a = (unsigned char)qY;

          /* disp("west_step") */
        }

        current_x->contents = a;
        current_y->contents = u4;

        /* disp("back") */
        break;

       case 3:
        a = current_dir->contents;

        /* ���́@���ݕ��� */
        /* �o�́@���ݕ��� */
        /*  turn_conclk_90deg �����v�����90�x���֐�  */
        q0 = (int)(4U + a);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_dir->contents = (unsigned char)((q0 - 1) % 4);
        a = current_x->contents;
        u4 = current_y->contents;
        b_current_dir = current_dir->contents;

        /* ���� ���݈ʒux,y,���ݕ��� */
        /* �o�� ���݈ʒux,y */
        /*  move_step ��}�X�O�i����֐� */
        /* �k�Ɉ�}�X */
        if (b_current_dir == g_direction.North) {
          q0 = (int)(u4 + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          u4 = (unsigned char)q0;

          /* disp("north_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.East) {
          q0 = (int)(a + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          a = (unsigned char)q0;

          /* disp("east_step") */
        }

        /* ��Ɉ�}�X */
        if (b_current_dir == g_direction.South) {
          qY = u4 - 1U;
          if (qY > u4) {
            qY = 0U;
          }

          u4 = (unsigned char)qY;

          /* disp("south_step") */
        }

        /* ���Ɉ�}�X */
        if (b_current_dir == g_direction.West) {
          qY = a - 1U;
          if (qY > a) {
            qY = 0U;
          }

          a = (unsigned char)qY;

          /* disp("west_step") */
        }

        current_x->contents = a;
        current_y->contents = u4;

        /* disp("left") */
        break;
      }

      /* for code generation */
    }
  } while (exitg1 == 0);
}

/*
 * �o�͕ϐ���`
 * Arguments    : const unsigned short row_num_node[1056]
 *                const unsigned short col_num_node[1056]
 *                unsigned char current_move_dir
 *                const unsigned char current_node[2]
 *                unsigned char current_matrix_dir
 *                const unsigned char goal_node2[2]
 *                unsigned char goal_matrix_dir2
 *                const unsigned char goal_section[2]
 *                unsigned char *next_dir
 *                unsigned char next_node[2]
 *                unsigned char *next_node_property
 * Return Type  : void
 */
static void get_next_dir_diagonal(const unsigned short row_num_node[1056], const
  unsigned short col_num_node[1056], unsigned char current_move_dir, const
  unsigned char current_node[2], unsigned char current_matrix_dir, const
  unsigned char goal_node2[2], unsigned char goal_matrix_dir2, const unsigned
  char goal_section[2], unsigned char *next_dir, unsigned char next_node[2],
  unsigned char *next_node_property)
{
  bool p;
  bool b_p;
  int k;
  bool exitg1;
  unsigned short map_min;
  unsigned int qY;
  int i182;
  unsigned char temp;
  int i183;
  unsigned short u10;

  /*  get_next_dir_diagonal �΂ߗL�ł̐i�s����,�s��擾 */
  *next_dir = g_d_direction.North;
  next_node[0] = 1U;
  next_node[1] = 1U;
  *next_node_property = matrix_dir.Row;

  /* ���݂̃G�b�W�̓S�[���m�[�h�� */
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (current_node[k] != goal_node2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (p && (current_matrix_dir == goal_matrix_dir2)) {
    /* �S�[���m�[�h�̏ꍇ */
    /* �S�[���m�[�h���s�����̏ꍇ */
    if (goal_matrix_dir2 == matrix_dir.Row) {
      if ((goal_section[1] == goal_node2[0]) && (goal_section[0] == goal_node2[1]))
      {
        next_node[0] = goal_node2[0];
        next_node[1] = goal_node2[1];
        *next_node_property = matrix_dir.section;
      } else {
        *next_dir = g_d_direction.South;
        qY = goal_node2[0] - 1U;
        if (qY > goal_node2[0]) {
          qY = 0U;
        }

        next_node[0] = (unsigned char)qY;
        next_node[1] = goal_node2[1];
        *next_node_property = matrix_dir.section;
      }
    } else {
      /* �S�[���m�[�h��������̏ꍇ */
      if ((goal_section[1] == goal_node2[0]) && (goal_section[0] == goal_node2[1]))
      {
        *next_dir = g_d_direction.East;
        next_node[0] = goal_node2[0];
        next_node[1] = goal_node2[1];
        *next_node_property = matrix_dir.section;
      } else {
        *next_dir = g_d_direction.West;
        next_node[0] = goal_node2[0];
        qY = goal_node2[1] - 1U;
        if (qY > goal_node2[1]) {
          qY = 0U;
        }

        next_node[1] = (unsigned char)qY;
        *next_node_property = matrix_dir.section;
      }
    }
  } else {
    /* �S�[���m�[�h�łȂ��ꍇ */
    /* 臒l���` */
    map_min = MAX_uint16_T;

    /* ���݂̃m�[�h�̕�������D��I�ɐi�s�������m�� */
    for (k = 0; k < 8; k++) {
      i182 = current_move_dir + k;
      if (i182 > 255) {
        i182 = 255;
      }

      temp = (unsigned char)(i182 % 8);

      /* ���݂̃m�[�h���s�����̎� */
      if (current_matrix_dir == matrix_dir.Row) {
        if (temp == g_d_direction.North) {
          i182 = (int)(current_node[0] + 1U);
          i183 = i182;
          if ((unsigned int)i182 > 255U) {
            i183 = 255;
          }

          if (row_num_node[(i183 + 33 * (current_node[1] - 1)) - 1] < map_min) {
            /* �ŏ��l���X�V */
            i183 = i182;
            if ((unsigned int)i182 > 255U) {
              i183 = 255;
            }

            map_min = row_num_node[(i183 + 33 * (current_node[1] - 1)) - 1];

            /* ���݃m�[�h�̐i�s������k������ */
            *next_dir = g_d_direction.North;

            /* �i�s������̍��W�A�s��̕������X�V */
            *next_node_property = matrix_dir.Row;
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            next_node[0] = (unsigned char)i182;
            next_node[1] = current_node[1];
          }
        } else if (temp == g_d_direction.North_East) {
          i182 = (int)(current_node[1] + 1U);
          i183 = i182;
          if ((unsigned int)i182 > 255U) {
            i183 = 255;
          }

          if (col_num_node[(current_node[0] + ((i183 - 1) << 5)) - 1] < map_min)
          {
            /* �ŏ��l���X�V */
            i183 = i182;
            if ((unsigned int)i182 > 255U) {
              i183 = 255;
            }

            map_min = col_num_node[(current_node[0] + ((i183 - 1) << 5)) - 1];

            /* ���݃m�[�h�̐i�s�����𓌖k������ */
            *next_dir = g_d_direction.North_East;

            /* �i�s������̍��W�A�s��̕������X�V */
            *next_node_property = matrix_dir.Col;
            next_node[0] = current_node[0];
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            next_node[1] = (unsigned char)i182;
          }
        } else if (temp != g_d_direction.East) {
          if (temp == g_d_direction.South_East) {
            qY = current_node[0] - 1U;
            if (qY > current_node[0]) {
              qY = 0U;
            }

            i182 = (int)(current_node[1] + 1U);
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            if (col_num_node[((int)qY + ((i182 - 1) << 5)) - 1] < map_min) {
              /* �ŏ��l���X�V */
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              i182 = (int)(current_node[1] + 1U);
              if ((unsigned int)i182 > 255U) {
                i182 = 255;
              }

              map_min = col_num_node[((int)qY + ((i182 - 1) << 5)) - 1];

              /* ���݃m�[�h�̐i�s������쓌������ */
              *next_dir = g_d_direction.South_East;

              /* �i�s������̍��W�A�s��̕������X�V */
              *next_node_property = matrix_dir.Col;
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              next_node[0] = (unsigned char)qY;
              i182 = (int)(current_node[1] + 1U);
              if ((unsigned int)i182 > 255U) {
                i182 = 255;
              }

              next_node[1] = (unsigned char)i182;
            }
          } else if (temp == g_d_direction.South) {
            qY = current_node[0] - 1U;
            if (qY > current_node[0]) {
              qY = 0U;
            }

            if (row_num_node[((int)qY + 33 * (current_node[1] - 1)) - 1] <
                map_min) {
              /* �ŏ��l���X�V */
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              map_min = row_num_node[((int)qY + 33 * (current_node[1] - 1)) - 1];

              /* ���݃m�[�h�̐i�s������������ */
              *next_dir = g_d_direction.South;

              /* �i�s������̍��W�A�s��̕������X�V */
              *next_node_property = matrix_dir.Row;
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              next_node[0] = (unsigned char)qY;
              next_node[1] = current_node[1];
            }
          } else if (temp == g_d_direction.South_West) {
            qY = current_node[0] - 1U;
            if (qY > current_node[0]) {
              qY = 0U;
            }

            if (col_num_node[((int)qY + ((current_node[1] - 1) << 5)) - 1] <
                map_min) {
              /* �ŏ��l���X�V */
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              map_min = col_num_node[((int)qY + ((current_node[1] - 1) << 5)) -
                1];

              /* ���݃m�[�h�̐i�s������쐼������ */
              *next_dir = g_d_direction.South_West;

              /* �i�s������̍��W�A�s��̕������X�V */
              *next_node_property = matrix_dir.Col;
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              next_node[0] = (unsigned char)qY;
              next_node[1] = current_node[1];
            }
          } else if ((temp != g_d_direction.West) && (temp ==
                      g_d_direction.North_West)) {
            u10 = col_num_node[(current_node[0] + ((current_node[1] - 1) << 5))
              - 1];
            if (u10 < map_min) {
              /* �ŏ��l���X�V */
              map_min = u10;

              /* ���݃m�[�h�̐i�s������k�������� */
              *next_dir = g_d_direction.North_West;

              /* �i�s������̍��W�A�s��̕������X�V */
              *next_node_property = matrix_dir.Col;
              next_node[0] = current_node[0];
              next_node[1] = current_node[1];
            }
          } else {
            /* �� */
          }
        } else {
          /* �� */
        }

        /* ���݂̃m�[�h���s�����̎�         */
      } else if (temp != g_d_direction.North) {
        if (temp == g_d_direction.North_East) {
          i182 = (int)(current_node[0] + 1U);
          if ((unsigned int)i182 > 255U) {
            i182 = 255;
          }

          if (row_num_node[(i182 + 33 * (current_node[1] - 1)) - 1] < map_min) {
            /* �ŏ��l���X�V */
            i182 = (int)(current_node[0] + 1U);
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            map_min = row_num_node[(i182 + 33 * (current_node[1] - 1)) - 1];

            /* ���݃m�[�h�̐i�s������k�������� */
            *next_dir = g_d_direction.North_East;

            /* �i�s������̍��W�A�s��̕������X�V */
            *next_node_property = matrix_dir.Row;
            i182 = (int)(current_node[0] + 1U);
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            next_node[0] = (unsigned char)i182;
            next_node[1] = current_node[1];
          }
        } else if (temp == g_d_direction.East) {
          i182 = (int)(current_node[1] + 1U);
          if ((unsigned int)i182 > 255U) {
            i182 = 255;
          }

          if (col_num_node[(current_node[0] + ((i182 - 1) << 5)) - 1] < map_min)
          {
            /* �ŏ��l���X�V */
            i182 = (int)(current_node[1] + 1U);
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            map_min = col_num_node[(current_node[0] + ((i182 - 1) << 5)) - 1];

            /* ���݃m�[�h�̐i�s�����𓌌����� */
            *next_dir = g_d_direction.East;

            /* �i�s������̍��W�A�s��̕������X�V */
            *next_node_property = matrix_dir.Col;
            next_node[0] = current_node[0];
            i182 = (int)(current_node[1] + 1U);
            if ((unsigned int)i182 > 255U) {
              i182 = 255;
            }

            next_node[1] = (unsigned char)i182;
          }
        } else if (temp == g_d_direction.South_East) {
          u10 = row_num_node[(current_node[0] + 33 * (current_node[1] - 1)) - 1];
          if (u10 < map_min) {
            /* �ŏ��l���X�V */
            map_min = u10;

            /* ���݃m�[�h�̐i�s������쓌������ */
            *next_dir = g_d_direction.South_East;

            /* �i�s������̍��W�A�s��̕������X�V */
            *next_node_property = matrix_dir.Row;
            next_node[0] = current_node[0];
            next_node[1] = current_node[1];
          }
        } else if (temp != g_d_direction.South) {
          if (temp == g_d_direction.South_West) {
            qY = current_node[1] - 1U;
            if (qY > current_node[1]) {
              qY = 0U;
            }

            if ((int)qY > 0) {
              qY = current_node[1] - 1U;
              if (qY > current_node[1]) {
                qY = 0U;
              }

              if (row_num_node[(current_node[0] + 33 * ((int)qY - 1)) - 1] <
                  map_min) {
                /* �ŏ��l���X�V */
                qY = current_node[1] - 1U;
                if (qY > current_node[1]) {
                  qY = 0U;
                }

                map_min = row_num_node[(current_node[0] + 33 * ((int)qY - 1)) -
                  1];

                /* ���݃m�[�h�̐i�s������쐼������ */
                *next_dir = g_d_direction.South_West;

                /* �i�s������̍��W�A�s��̕������X�V */
                *next_node_property = matrix_dir.Row;
                next_node[0] = current_node[0];
                qY = current_node[1] - 1U;
                if (qY > current_node[1]) {
                  qY = 0U;
                }

                next_node[1] = (unsigned char)qY;
              }
            }
          } else if (temp == g_d_direction.West) {
            qY = current_node[1] - 1U;
            if (qY > current_node[1]) {
              qY = 0U;
            }

            if ((int)qY > 0) {
              qY = current_node[1] - 1U;
              if (qY > current_node[1]) {
                qY = 0U;
              }

              if (col_num_node[(current_node[0] + (((int)qY - 1) << 5)) - 1] <
                  map_min) {
                /* �ŏ��l���X�V */
                qY = current_node[1] - 1U;
                if (qY > current_node[1]) {
                  qY = 0U;
                }

                map_min = col_num_node[(current_node[0] + (((int)qY - 1) << 5))
                  - 1];

                /* ���݃m�[�h�̐i�s�����𐼌����� */
                *next_dir = g_d_direction.West;

                /* �i�s������̍��W�A�s��̕������X�V */
                *next_node_property = matrix_dir.Col;
                next_node[0] = current_node[0];
                qY = current_node[1] - 1U;
                if (qY > current_node[1]) {
                  qY = 0U;
                }

                next_node[1] = (unsigned char)qY;
              }
            }
          } else {
            if (temp == g_d_direction.North_West) {
              qY = current_node[1] - 1U;
              if (qY > current_node[1]) {
                qY = 0U;
              }

              if ((int)qY > 0) {
                i182 = (int)(current_node[0] + 1U);
                if ((unsigned int)i182 > 255U) {
                  i182 = 255;
                }

                qY = current_node[1] - 1U;
                if (qY > current_node[1]) {
                  qY = 0U;
                }

                if (row_num_node[(i182 + 33 * ((int)qY - 1)) - 1] < map_min) {
                  /* �ŏ��l���X�V */
                  i182 = (int)(current_node[0] + 1U);
                  if ((unsigned int)i182 > 255U) {
                    i182 = 255;
                  }

                  qY = current_node[1] - 1U;
                  if (qY > current_node[1]) {
                    qY = 0U;
                  }

                  map_min = row_num_node[(i182 + 33 * ((int)qY - 1)) - 1];

                  /* ���݃m�[�h�̐i�s������k�������� */
                  *next_dir = g_d_direction.North_West;

                  /* �i�s������̍��W�A�s��̕������X�V */
                  *next_node_property = matrix_dir.Row;
                  i182 = (int)(current_node[0] + 1U);
                  if ((unsigned int)i182 > 255U) {
                    i182 = 255;
                  }

                  next_node[0] = (unsigned char)i182;
                  qY = current_node[1] - 1U;
                  if (qY > current_node[1]) {
                    qY = 0U;
                  }

                  next_node[1] = (unsigned char)qY;
                }
              }
            }
          }
        } else {
          /* �� */
        }
      } else {
        /* �� */
      }
    }
  }
}

/*
 * ���� ���ݒnx,y,�Ǐ��,������map,�ő�o�H��
 *  �o�� ���̐i�s���p
 * Arguments    : unsigned char current_x
 *                unsigned char current_y
 *                const unsigned char maze_wall[1024]
 *                const unsigned short contour_map[1024]
 * Return Type  : unsigned char
 */
static unsigned char get_nextdir2(unsigned char current_x, unsigned char
  current_y, const unsigned char maze_wall[1024], const unsigned short
  contour_map[1024])
{
  unsigned char next_dir;
  unsigned short little;
  int i7;
  int i8;
  int i9;
  int i10;
  unsigned short u2;
  int i11;
  int i12;

  /*  get_nextdir2 ������map���玟�Ɍ�����������I�� */
  /* �o�͂̏����� */
  next_dir = 0U;
  little = MAX_uint16_T;

  /*             %%�i�s�����I�� */
  /* �D�揇�ʁ@�k�˓��˓�ː� */
  /* �k���̕ǂ̂���Ȃ����� */
  i7 = current_y + ((current_x - 1) << 5);
  i8 = maze_wall[i7 - 1];
  if (g_direction.North <= 7) {
    i9 = (unsigned char)(1 << g_direction.North);
  } else {
    i9 = 0;
  }

  if (((i8 & i9) == 0) && (contour_map[i7] < 65535)) {
    /* �k���̓�����map��臒l���Ⴏ��΁A */
    /* 臒l��k���̓���map�l�ɕύX */
    little = contour_map[current_y + ((current_x - 1) << 5)];

    /* �k����i�s�����ɕύXy */
    next_dir = g_direction.North;
  }

  /* ���� */
  if (g_direction.East <= 7) {
    i10 = (unsigned char)(1 << g_direction.East);
  } else {
    i10 = 0;
  }

  if ((i8 & i10) == 0) {
    u2 = contour_map[(current_y + (current_x << 5)) - 1];
    if (u2 < little) {
      little = u2;
      next_dir = g_direction.East;
    }
  }

  /* �쑤 */
  if (g_direction.South <= 7) {
    i11 = (unsigned char)(1 << g_direction.South);
  } else {
    i11 = 0;
  }

  if ((i8 & i11) == 0) {
    u2 = contour_map[i7 - 2];
    if (u2 < little) {
      little = u2;
      next_dir = g_direction.South;
    }
  }

  /* ���� */
  if (g_direction.West <= 7) {
    i12 = (unsigned char)(1 << g_direction.West);
  } else {
    i12 = 0;
  }

  if (((i8 & i12) == 0) && (contour_map[(current_y + ((current_x - 2) << 5)) - 1]
       < little)) {
    /*  little = contour_map(current_y,current_x-1); */
    next_dir = g_direction.West;
  }

  return next_dir;
}

/*
 * ����p�^�[���ԍ��̏�����
 * Arguments    : const double move_dir_buffer[3]
 *                unsigned char ref_move_mode
 * Return Type  : unsigned char
 */
static unsigned char get_turn_pattern_num(const double move_dir_buffer[3],
  unsigned char ref_move_mode)
{
  unsigned char turn_pattern_num;

  /* �p�^�[���𔻒肷��֐� */
  turn_pattern_num = turn_pattern.b_default;

  /* ���i�� */
  if (ref_move_mode == move_dir_property.straight) {
    /* ����45�x�܂���Ƃ�(�E�܃p�^�[��) */
    if (move_dir_buffer[0] == 1.0) {
      if (move_dir_buffer[1] == 1.0) {
        turn_pattern_num = turn_pattern.r_45;
      } else if (move_dir_buffer[1] == 2.0) {
        turn_pattern_num = turn_pattern.r_90;
      } else {
        if (move_dir_buffer[1] == 3.0) {
          if (move_dir_buffer[2] == 3.0) {
            turn_pattern_num = turn_pattern.r_135;
          } else {
            if (move_dir_buffer[2] == 4.0) {
              turn_pattern_num = turn_pattern.r_180;
            }
          }
        }
      }

      /* ����-45�x�܂���Ƃ�(���܃p�^�[��)     */
    } else {
      if (move_dir_buffer[0] == 7.0) {
        if (move_dir_buffer[1] == 7.0) {
          turn_pattern_num = turn_pattern.l_45;
        } else if (move_dir_buffer[1] == 6.0) {
          turn_pattern_num = turn_pattern.l_90;
        } else {
          if (move_dir_buffer[1] == 5.0) {
            if (move_dir_buffer[2] == 5.0) {
              turn_pattern_num = turn_pattern.l_135;
            } else {
              if (move_dir_buffer[2] == 4.0) {
                turn_pattern_num = turn_pattern.l_180;
              }
            }
          }
        }
      }
    }

    /* �΂߂̎� */
  } else {
    if (ref_move_mode == move_dir_property.diagonal) {
      /* �E�܃p�^�[�� */
      if (move_dir_buffer[0] == 1.0) {
        turn_pattern_num = turn_pattern.r_45;
      } else if (move_dir_buffer[0] == 2.0) {
        if (move_dir_buffer[1] == 2.0) {
          turn_pattern_num = turn_pattern.r_90;
        } else {
          if (move_dir_buffer[1] == 3.0) {
            turn_pattern_num = turn_pattern.r_135;
          }
        }

        /* ���܃p�^�[��     */
      } else if (move_dir_buffer[0] == 7.0) {
        turn_pattern_num = turn_pattern.l_45;
      } else {
        if (move_dir_buffer[0] == 6.0) {
          if (move_dir_buffer[1] == 6.0) {
            turn_pattern_num = turn_pattern.l_90;
          } else {
            if (move_dir_buffer[1] == 5.0) {
              turn_pattern_num = turn_pattern.l_135;
            }
          }
        }
      }
    }
  }

  return turn_pattern_num;
}

/*
 * ���͍��W�̔z����쐬
 * Arguments    : const unsigned char maze_goal[18]
 *                unsigned char x
 *                unsigned char y
 * Return Type  : double
 */
static double goal_judge(const unsigned char maze_goal[18], unsigned char x,
  unsigned char y)
{
  int i113;
  unsigned char uv1[18];
  bool temp1[18];
  int ex;
  signed char varargin_1[9];
  int k;

  /* �S�[������֐� */
  /* �S�[�����W�Ɣ�r */
  for (i113 = 0; i113 < 9; i113++) {
    uv1[i113] = x;
    uv1[9 + i113] = y;
  }

  for (i113 = 0; i113 < 18; i113++) {
    temp1[i113] = (maze_goal[i113] == uv1[i113]);
  }

  /* x,y�Ƃ��Ɉ�v���邩�m�F�A��v�Ȃ�1��Ԃ� */
  for (i113 = 0; i113 < 9; i113++) {
    varargin_1[i113] = (signed char)(temp1[i113] * temp1[9 + i113]);
  }

  ex = varargin_1[0];
  for (k = 0; k < 8; k++) {
    i113 = varargin_1[k + 1];
    if (ex < i113) {
      ex = i113;
    }
  }

  return ex;
}

/*
 * ���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��)
 * �o�� ������map,�ő�o�H��
 * Arguments    : coder_internal_ref_3 *num_temp
 *                const coder_internal_ref_5 *wall
 *                const unsigned char maze_goal[18]
 *                unsigned char l_goal_size
 *                const unsigned char maze_wall[1024]
 *                unsigned short contour_map[1024]
 * Return Type  : void
 */
static void make_map_find(coder_internal_ref_3 *num_temp, const
  coder_internal_ref_5 *wall, const unsigned char maze_goal[18], unsigned char
  l_goal_size, const unsigned char maze_wall[1024], unsigned short contour_map
  [1024])
{
  int i2;
  int idx;
  emxArray_uint8_T *row;
  emxArray_uint8_T *col;
  emxArray_uint16_T *r0;
  emxArray_uint16_T *b_num_temp;
  unsigned char change_flag;
  unsigned short tempi;
  bool exitg1;
  int ii;
  bool exitg2;
  short ii_data[1024];
  unsigned int qY;
  unsigned short u0;
  int i3;
  int i4;
  int i5;
  int i6;

  /*   make_map_find �Ǐ�񂩂瓙����MAP�𐶐� */
  /*  ���H�p�����[�^�ݒ� */
  /* MAP�̏�����(���ׂĂ̗v�f��max_length�����) */
  /* 32�}�X��map��ێ� */
  /* 16bit�ɂ��ׂ� */
  for (i2 = 0; i2 < 1024; i2++) {
    contour_map[i2] = MAX_uint16_T;
  }

  /* �S�[�����W��0����� */
  i2 = l_goal_size;
  for (idx = 0; idx < i2; idx++) {
    contour_map[(maze_goal[idx + 9] + ((maze_goal[idx] - 1) << 5)) - 1] = 0U;
  }

  emxInit_uint8_T(&row, 1);
  emxInit_uint8_T(&col, 1);
  emxInit_uint16_T(&r0, 1);
  emxInit_uint16_T(&b_num_temp, 1);
  do {
    change_flag = 0U;

    /* map�X�V�m�F�p�t���O */
    tempi = 0U;
    exitg1 = false;
    while ((!exitg1) && (tempi < 65535)) {
      /* �����J�E���g��0~max_length */
      /* �������m�肵�Ă�����W������ */
      /* �ŏ���0,�X�V����A���������}�X�����X�������Ă��� */
      idx = 0;
      ii = 0;
      exitg2 = false;
      while ((!exitg2) && (ii < 1024)) {
        if (contour_map[ii] == tempi) {
          idx++;
          ii_data[idx - 1] = (short)(ii + 1);
          if (idx >= 1024) {
            exitg2 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        idx = 0;
      }

      i2 = num_temp->contents->size[0];
      num_temp->contents->size[0] = idx;
      emxEnsureCapacity_uint16_T(num_temp->contents, i2);
      for (i2 = 0; i2 < idx; i2++) {
        num_temp->contents->data[i2] = (unsigned short)ii_data[i2];
      }

      /* 32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂� */
      i2 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i2);
      idx = num_temp->contents->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        ii = num_temp->contents->data[i2];
        qY = ii - 1U;
        if (qY > (unsigned int)ii) {
          qY = 0U;
        }

        b_num_temp->data[i2] = (unsigned short)qY;
      }

      c_rem(b_num_temp, r0);
      i2 = row->size[0];
      row->size[0] = r0->size[0];
      emxEnsureCapacity_uint8_T(row, i2);
      idx = r0->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        qY = r0->data[i2] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        u0 = (unsigned short)qY;
        if ((unsigned short)qY > 255) {
          u0 = 255U;
        }

        row->data[i2] = (unsigned char)u0;
      }

      /* ��ԍ�:32�Ŋ������Ƃ��̏� */
      i2 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i2);
      idx = num_temp->contents->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        ii = num_temp->contents->data[i2];
        qY = ii - 1U;
        if (qY > (unsigned int)ii) {
          qY = 0U;
        }

        b_num_temp->data[i2] = (unsigned short)qY;
      }

      idivide(b_num_temp, 32.0, r0);
      i2 = col->size[0];
      col->size[0] = r0->size[0];
      emxEnsureCapacity_uint8_T(col, i2);
      idx = r0->size[0];
      for (i2 = 0; i2 < idx; i2++) {
        qY = r0->data[i2] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        u0 = (unsigned short)qY;
        if ((unsigned short)qY > 255) {
          u0 = 255U;
        }

        col->data[i2] = (unsigned char)u0;
      }

      /* ���������}�X�̐� */
      i2 = row->size[0];
      if (i2 < 0) {
        i2 = 0;
      } else {
        if (i2 > 255) {
          i2 = 255;
        }
      }

      /* �X�V�}�X��������Ȃ���ΏI�� */
      if ((unsigned char)i2 == 0) {
        exitg1 = true;
      } else {
        /* �����������W�ɑ΂��A����map���X�V */
        i2 = (unsigned char)i2;
        for (idx = 0; idx < i2; idx++) {
          /* �k�� */
          if (g_direction.North <= 7) {
            i3 = (unsigned char)(1 << g_direction.North);
          } else {
            i3 = 0;
          }

          if ((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
               i3) == wall->contents.nowall) {
            /* �k����MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ������� */
            ii = (int)(row->data[idx] + 1U);
            if ((unsigned int)ii > 255U) {
              ii = 255;
            }

            if (contour_map[(ii + ((col->data[idx] - 1) << 5)) - 1] == 65535) {
              ii = (int)(row->data[idx] + 1U);
              if ((unsigned int)ii > 255U) {
                ii = 255;
              }

              contour_map[(ii + ((col->data[idx] - 1) << 5)) - 1] = (unsigned
                short)(tempi + 1);
              change_flag = 1U;
            }
          }

          /* ���� */
          if (g_direction.East <= 7) {
            i4 = (unsigned char)(1 << g_direction.East);
          } else {
            i4 = 0;
          }

          if ((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
               i4) == wall->contents.nowall) {
            /* ������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ������� */
            ii = (int)(col->data[idx] + 1U);
            if ((unsigned int)ii > 255U) {
              ii = 255;
            }

            if (contour_map[(row->data[idx] + ((ii - 1) << 5)) - 1] == 65535) {
              ii = (int)(col->data[idx] + 1U);
              if ((unsigned int)ii > 255U) {
                ii = 255;
              }

              contour_map[(row->data[idx] + ((ii - 1) << 5)) - 1] = (unsigned
                short)(tempi + 1);
              change_flag = 1U;
            }
          }

          /* �쑤 */
          if (g_direction.South <= 7) {
            i5 = (unsigned char)(1 << g_direction.South);
          } else {
            i5 = 0;
          }

          if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
                i5) == wall->contents.nowall) && (contour_map[(row->data[idx] +
                ((col->data[idx] - 1) << 5)) - 2] == 65535)) {
            /* �쑤��MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ������� */
            contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2] =
              (unsigned short)(tempi + 1);
            change_flag = 1U;
          }

          /* ���� */
          if (g_direction.West <= 7) {
            i6 = (unsigned char)(1 << g_direction.West);
          } else {
            i6 = 0;
          }

          if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
                i6) == wall->contents.nowall) && (contour_map[(row->data[idx] +
                ((col->data[idx] - 2) << 5)) - 1] == 65535)) {
            /* ������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ������� */
            contour_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1] =
              (unsigned short)(tempi + 1);
            change_flag = 1U;
          }
        }

        tempi++;
      }
    }

    /* �X�V���Ȃ���ΏI��     */
  } while (!(change_flag == 0));

  emxFree_uint16_T(&b_num_temp);
  emxFree_uint16_T(&r0);
  emxFree_uint8_T(&col);
  emxFree_uint8_T(&row);
}

/*
 * ���m�ǂ̗̈�͉��z�ǂ������ĐN�����Ȃ��B
 * ���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��),���H�T�����(16�i��)
 * �o�� ������map,�ő�o�H��
 * Arguments    : const coder_internal_ref *goal_size
 *                coder_internal_ref_3 *num_temp
 *                const coder_internal_ref_5 *wall
 *                const coder_internal_ref_4 *search
 *                const unsigned char maze_goal[18]
 *                const unsigned char maze_wall[1024]
 *                const unsigned char maze_wall_search[1024]
 *                unsigned short contour_map[1024]
 * Return Type  : void
 */
static void make_map_fustrun(const coder_internal_ref *goal_size,
  coder_internal_ref_3 *num_temp, const coder_internal_ref_5 *wall, const
  coder_internal_ref_4 *search, const unsigned char maze_goal[18], const
  unsigned char maze_wall[1024], const unsigned char maze_wall_search[1024],
  unsigned short contour_map[1024])
{
  int i13;
  unsigned char move_dir_map[1024];
  unsigned char change_flag;
  int idx;
  int contour_map_tmp;
  unsigned short contour_refine_map[1024];
  emxArray_uint8_T *row;
  emxArray_uint8_T *col;
  int i14;
  emxArray_uint16_T *r1;
  emxArray_uint16_T *b_num_temp;
  int i15;
  int i16;
  unsigned short tempi;
  int i17;
  bool exitg1;
  int i18;
  short ii_data[1024];
  unsigned int qY;
  unsigned short u3;
  int i19;
  int i20;
  int i21;
  int i22;
  int i23;
  int i24;
  int i25;
  int i26;
  int i27;
  int i28;
  int i29;
  int i30;

  /*  make_map_fustrun �ŒZ���s�p������MAP�𐶐� */
  /* ���[�J���ϐ��ݒ� */
  /* �p�����[�^�ݒ� */
  /*  ���H�p�����[�^�ݒ� */
  /* MAP�̏�����(���ׂĂ̗v�f��max_length�����) */
  /* 32�}�X��map��ێ� */
  /* �i�s�����⊮�p�ϐ���` */
  for (i13 = 0; i13 < 1024; i13++) {
    contour_map[i13] = MAX_uint16_T;
    move_dir_map[i13] = 0U;
  }

  /* �S�[�����W�� */
  /*  �����}�b�v�F0����� */
  /*  �i�s���� : 1+2+4+8(������k���ׂ�)=15 */
  /*  ����� */
  change_flag = goal_size->contents;
  i13 = change_flag;
  for (idx = 0; idx < i13; idx++) {
    contour_map_tmp = (maze_goal[idx + 9] + ((maze_goal[idx] - 1) << 5)) - 1;
    contour_map[contour_map_tmp] = 0U;
    if (g_direction.North <= 7) {
      i14 = (unsigned char)(1 << g_direction.North);
    } else {
      i14 = 0;
    }

    if (g_direction.East <= 7) {
      i15 = (unsigned char)(1 << g_direction.East);
    } else {
      i15 = 0;
    }

    i16 = (int)((unsigned int)i14 + i15);
    if ((unsigned int)i16 > 255U) {
      i16 = 255;
    }

    if (g_direction.South <= 7) {
      i17 = (unsigned char)(1 << g_direction.South);
    } else {
      i17 = 0;
    }

    i16 = (int)((unsigned int)i16 + i17);
    if ((unsigned int)i16 > 255U) {
      i16 = 255;
    }

    if (g_direction.West <= 7) {
      i18 = (unsigned char)(1 << g_direction.West);
    } else {
      i18 = 0;
    }

    i16 = (int)((unsigned int)i16 + i18);
    if ((unsigned int)i16 > 255U) {
      i16 = 255;
    }

    move_dir_map[contour_map_tmp] = (unsigned char)i16;
  }

  /* �X�V����p�ϐ�(�d�݂Â��Ȃ��̕����}�b�v) */
  memcpy(&contour_refine_map[0], &contour_map[0], sizeof(unsigned short) << 10);
  emxInit_uint8_T(&row, 1);
  emxInit_uint8_T(&col, 1);
  emxInit_uint16_T(&r1, 1);
  emxInit_uint16_T(&b_num_temp, 1);
  do {
    change_flag = 0U;

    /* map�X�V�m�F�p�t���O */
    for (tempi = 0; tempi < MAX_uint16_T; tempi++) {
      /* �X�V�m�F�p�̕����J�E���g��0~max_length */
      /* �������m�肵�Ă�����W������ */
      /* �ŏ���0,�X�V����A���������}�X�����X�������Ă��� */
      idx = 0;
      contour_map_tmp = 0;
      exitg1 = false;
      while ((!exitg1) && (contour_map_tmp < 1024)) {
        if (contour_refine_map[contour_map_tmp] == tempi) {
          idx++;
          ii_data[idx - 1] = (short)(contour_map_tmp + 1);
          if (idx >= 1024) {
            exitg1 = true;
          } else {
            contour_map_tmp++;
          }
        } else {
          contour_map_tmp++;
        }
      }

      if (1 > idx) {
        idx = 0;
      }

      i13 = num_temp->contents->size[0];
      num_temp->contents->size[0] = idx;
      emxEnsureCapacity_uint16_T(num_temp->contents, i13);
      for (i13 = 0; i13 < idx; i13++) {
        num_temp->contents->data[i13] = (unsigned short)ii_data[i13];
      }

      /* 32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂� */
      i13 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i13);
      idx = num_temp->contents->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        contour_map_tmp = num_temp->contents->data[i13];
        qY = contour_map_tmp - 1U;
        if (qY > (unsigned int)contour_map_tmp) {
          qY = 0U;
        }

        b_num_temp->data[i13] = (unsigned short)qY;
      }

      c_rem(b_num_temp, r1);
      i13 = row->size[0];
      row->size[0] = r1->size[0];
      emxEnsureCapacity_uint8_T(row, i13);
      idx = r1->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        qY = r1->data[i13] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        u3 = (unsigned short)qY;
        if ((unsigned short)qY > 255) {
          u3 = 255U;
        }

        row->data[i13] = (unsigned char)u3;
      }

      /* ��ԍ�:32�Ŋ������Ƃ��̏� */
      i13 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i13);
      idx = num_temp->contents->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        contour_map_tmp = num_temp->contents->data[i13];
        qY = contour_map_tmp - 1U;
        if (qY > (unsigned int)contour_map_tmp) {
          qY = 0U;
        }

        b_num_temp->data[i13] = (unsigned short)qY;
      }

      idivide(b_num_temp, 32.0, r1);
      i13 = col->size[0];
      col->size[0] = r1->size[0];
      emxEnsureCapacity_uint8_T(col, i13);
      idx = r1->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        qY = r1->data[i13] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        u3 = (unsigned short)qY;
        if ((unsigned short)qY > 255) {
          u3 = 255U;
        }

        col->data[i13] = (unsigned char)u3;
      }

      /* ���������}�X�̐� */
      /* �����������W�ɑ΂��A����map���X�V */
      i13 = row->size[0];
      if (i13 < 0) {
        i13 = 0;
      } else {
        if (i13 > 65535) {
          i13 = 65535;
        }
      }

      for (idx = 0; idx < i13; idx++) {
        /* �k�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.North <= 7) {
          i19 = (unsigned char)(1 << g_direction.North);
        } else {
          i19 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i19) != 0) == wall->contents.nowall) {
          if (g_direction.North <= 7) {
            i20 = (unsigned char)(1 << g_direction.North);
          } else {
            i20 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i20) != 0) == search->contents.known) {
            /* ���i�s�������k�����ł��鎞 */
            if (g_direction.North <= 7) {
              i22 = (unsigned char)(1 << g_direction.North);
            } else {
              i22 = 0;
            }

            if ((move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i22) != 0) {
              /* ���k�̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ */
              i16 = (int)(row->data[idx] + 1U);
              if ((unsigned int)i16 > 255U) {
                i16 = 255;
              }

              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] > (int)qY)
              {
                /* �X�V�m�F�p��MAP�X�V */
                i16 = (int)(row->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] =
                  (unsigned short)qY;

                /* ����MAP�X�V */
                i16 = (int)(row->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] = (unsigned
                  short)qY;

                /* �ړ�����MAP�X�V */
                i16 = (int)(row->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                if (g_direction.North <= 7) {
                  move_dir_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_direction.North);
                } else {
                  move_dir_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }

              /* ���i�s�������k�����łȂ��Ƃ�     */
            } else {
              /* ���k�̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              i16 = (int)(row->data[idx] + 1U);
              if ((unsigned int)i16 > 255U) {
                i16 = 255;
              }

              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 5U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] > (int)qY)
              {
                /* �X�V�m�F�p��MAP�X�V */
                i16 = (int)(row->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] =
                  (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                i16 = (int)(row->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 5U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] = (unsigned
                  short)qY;

                /* �ړ�����MAP�X�V */
                i16 = (int)(row->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                if (g_direction.North <= 7) {
                  move_dir_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_direction.North);
                } else {
                  move_dir_map[(i16 + ((col->data[idx] - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }
            }
          }
        }

        /* ���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.East <= 7) {
          i21 = (unsigned char)(1 << g_direction.East);
        } else {
          i21 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i21) != 0) == wall->contents.nowall) {
          if (g_direction.East <= 7) {
            i23 = (unsigned char)(1 << g_direction.East);
          } else {
            i23 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i23) != 0) == search->contents.known) {
            /* ���i�s�������������ł��鎞 */
            if (g_direction.East <= 7) {
              i25 = (unsigned char)(1 << g_direction.East);
            } else {
              i25 = 0;
            }

            if ((move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i25) != 0) {
              /* �����̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ */
              i16 = (int)(col->data[idx] + 1U);
              if ((unsigned int)i16 > 255U) {
                i16 = 255;
              }

              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] > (int)qY)
              {
                /* �X�V�m�F�p��MAP�X�V */
                i16 = (int)(col->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] =
                  (unsigned short)qY;

                /* ����MAP�X�V */
                i16 = (int)(col->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] = (unsigned
                  short)qY;

                /* �ړ�����MAP�X�V */
                i16 = (int)(col->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                if (g_direction.East <= 7) {
                  move_dir_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_direction.East);
                } else {
                  move_dir_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }

              /* ���i�s�������������łȂ��Ƃ�     */
            } else {
              /* �����̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              i16 = (int)(col->data[idx] + 1U);
              if ((unsigned int)i16 > 255U) {
                i16 = 255;
              }

              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 5U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] > (int)qY)
              {
                /* �X�V�m�F�p��MAP�X�V */
                i16 = (int)(col->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] =
                  (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                i16 = (int)(col->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 5U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] = (unsigned
                  short)qY;

                /* �ړ�����MAP�X�V */
                i16 = (int)(col->data[idx] + 1U);
                if ((unsigned int)i16 > 255U) {
                  i16 = 255;
                }

                if (g_direction.East <= 7) {
                  move_dir_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_direction.East);
                } else {
                  move_dir_map[(row->data[idx] + ((i16 - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }
            }
          }
        }

        /* �쑤 */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.South <= 7) {
          i24 = (unsigned char)(1 << g_direction.South);
        } else {
          i24 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i24) != 0) == wall->contents.nowall) {
          if (g_direction.South <= 7) {
            i26 = (unsigned char)(1 << g_direction.South);
          } else {
            i26 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i26) != 0) == search->contents.known) {
            /* ���i�s������������ł��鎞 */
            if (g_direction.South <= 7) {
              i28 = (unsigned char)(1 << g_direction.South);
            } else {
              i28 = 0;
            }

            if ((move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i28) != 0) {
              /* ����̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 2] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_direction.South <= 7) {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(1 << g_direction.South);
                } else {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }

              /* ���i�s������������łȂ��Ƃ�     */
            } else {
              /* ����̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 5U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 2] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 5U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_direction.South <= 7) {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(1 << g_direction.South);
                } else {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }
            }
          }
        }

        /* ���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.West <= 7) {
          i27 = (unsigned char)(1 << g_direction.West);
        } else {
          i27 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i27) != 0) == wall->contents.nowall) {
          if (g_direction.West <= 7) {
            i29 = (unsigned char)(1 << g_direction.West);
          } else {
            i29 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i29) != 0) == search->contents.known) {
            /* ���i�s�������������ł��鎞 */
            if (g_direction.West <= 7) {
              i30 = (unsigned char)(1 << g_direction.West);
            } else {
              i30 = 0;
            }

            if ((move_dir_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i30) != 0) {
              /* ���k�̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(row->data[idx] + ((col->data[idx] - 2) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_direction.West <= 7) {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(1 << g_direction.West);
                } else {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }

              /* ���i�s�������������łȂ��Ƃ�     */
            } else {
              /* ���k�̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 5U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (contour_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = contour_refine_map[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_refine_map[(row->data[idx] + ((col->data[idx] - 2) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = contour_map[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 5U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                contour_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_direction.West <= 7) {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(1 << g_direction.West);
                } else {
                  move_dir_map[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;
              }
            }
          }
        }
      }
    }

    /* �X�V���Ȃ���ΏI��     */
  } while (!(change_flag == 0));

  emxFree_uint16_T(&b_num_temp);
  emxFree_uint16_T(&r1);
  emxFree_uint8_T(&col);
  emxFree_uint8_T(&row);
}

/*
 * ���m�ǂ̗̈�͉��z�ǂ������ĐN�����Ȃ��B
 * ���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��),���H�T�����(16�i��)
 * �o�� ������map,�ő�o�H��
 * Arguments    : coder_internal_ref_2 *max_length
 *                coder_internal_ref_3 *num_temp
 *                const coder_internal_ref_5 *wall
 *                const coder_internal_ref_4 *search
 *                const unsigned char maze_goal[18]
 *                unsigned char goal_size
 *                const unsigned char maze_wall[1024]
 *                const unsigned char maze_wall_search[1024]
 *                unsigned short row_num_node[1056]
 *                unsigned short col_num_node[1056]
 *                unsigned short *start_num
 * Return Type  : void
 */
static void make_map_fustrun_diagonal(coder_internal_ref_2 *max_length,
  coder_internal_ref_3 *num_temp, const coder_internal_ref_5 *wall, const
  coder_internal_ref_4 *search, const unsigned char maze_goal[18], unsigned char
  goal_size, const unsigned char maze_wall[1024], const unsigned char
  maze_wall_search[1024], unsigned short row_num_node[1056], unsigned short
  col_num_node[1056], unsigned short *start_num)
{
  int i35;
  unsigned short row_num_node_temp[1056];
  unsigned short col_num_node_temp[1056];
  unsigned char row_dir_node[1056];
  int ii;
  unsigned char col_dir_node[1056];
  int idx;
  int i36;
  int i37;
  int i38;
  emxArray_uint16_T *row;
  int i39;
  emxArray_uint16_T *col;
  int i40;
  emxArray_uint16_T *b_num_temp;
  int row_num_node_tmp;
  unsigned char change_flag;
  int i41;
  int i42;
  int i43;
  unsigned int qY;
  int i44;
  unsigned short u5;
  unsigned short i;
  int i45;
  int i46;
  int i47;
  bool exitg1;
  int i48;
  int i49;
  short ii_data[1056];
  int i50;
  int i51;
  int i52;
  int i53;
  int i54;
  unsigned char a;
  int i55;
  int i56;
  unsigned int u6;
  int i57;
  int i58;
  int i59;
  int i60;
  int i61;
  int i62;
  int i63;
  int i64;
  int i65;
  int i66;
  int i67;
  int i68;
  int i69;
  int i70;
  int i71;
  int i72;
  int i73;
  int i74;
  int i75;
  int i76;
  int i77;
  int i78;
  int i79;
  int i80;
  int i81;
  int i82;
  int i83;
  int i84;
  int i85;
  int i86;
  int i87;
  int i88;
  int i89;
  int i90;
  int i91;
  int i92;
  int i93;
  int i94;
  int i95;
  int i96;
  int i97;
  int i98;
  int i99;
  int i100;
  int i101;
  int i102;
  int i103;
  int i104;
  int i105;
  int i106;
  int i107;
  int i108;
  int i109;

  /*  make_map_fustrun_diagonal �ŒZ���s�p������MAP�𐶐� */
  /* ���[�J���ϐ��ݒ� */
  /* �p�����[�^�ݒ� */
  /*  ���H�p�����[�^�ݒ� */
  max_length->contents = 1024U;

  /*  ���[�g�̏d�ݐݒ� */
  /* MAP�̏�����(���ׂẴm�[�h��max_length�����) */
  /* ����MAP */
  /* �X�V�pMAP */
  /* �i�s�����ێ��p�m�[�h�쐬 */
  for (i35 = 0; i35 < 1056; i35++) {
    row_num_node[i35] = MAX_uint16_T;
    col_num_node[i35] = MAX_uint16_T;
    row_num_node_temp[i35] = MAX_uint16_T;
    col_num_node_temp[i35] = MAX_uint16_T;
    row_dir_node[i35] = 0U;
    col_dir_node[i35] = 0U;
  }

  /* �S�[���Z�N�V�������m�肵�Ă���ꍇ */
  if (goal_size == 1) {
    /* �S�[���}�X����A������k�Ƀ}�b�v��W�J */
    /* �k�� */
    i35 = maze_goal[0] - 1;
    ii = (maze_goal[9] + (i35 << 5)) - 1;
    if (g_direction.North <= 7) {
      i36 = (unsigned char)(1 << g_direction.North);
    } else {
      i36 = 0;
    }

    if ((maze_wall[ii] & i36) == 0) {
      /* �����X�V */
      i37 = (int)(maze_goal[9] + 1U);
      i38 = i37;
      if ((unsigned int)i37 > 255U) {
        i38 = 255;
      }

      row_num_node_tmp = 33 * i35;
      row_num_node[(i38 + row_num_node_tmp) - 1] = 3U;

      /* �����ǉ� */
      i35 = i37;
      if ((unsigned int)i37 > 255U) {
        i35 = 255;
      }

      if (g_d_direction.North <= 7) {
        row_dir_node[(i35 + row_num_node_tmp) - 1] = (unsigned char)(1 <<
          g_d_direction.North);
      } else {
        row_dir_node[(i35 + row_num_node_tmp) - 1] = 0U;
      }

      /* �X�V�pMAP�X�V */
      if ((unsigned int)i37 > 255U) {
        i37 = 255;
      }

      row_num_node_temp[(i37 + row_num_node_tmp) - 1] = 0U;
    }

    /* ���� */
    if (g_direction.East <= 7) {
      i39 = (unsigned char)(1 << g_direction.East);
    } else {
      i39 = 0;
    }

    if ((maze_wall[ii] & i39) == 0) {
      /* �����X�V */
      i35 = (int)(maze_goal[0] + 1U);
      i37 = i35;
      if ((unsigned int)i35 > 255U) {
        i37 = 255;
      }

      col_num_node[(maze_goal[9] + ((i37 - 1) << 5)) - 1] = 3U;

      /* �����ǉ� */
      i37 = i35;
      if ((unsigned int)i35 > 255U) {
        i37 = 255;
      }

      if (g_d_direction.East <= 7) {
        col_dir_node[(maze_goal[9] + ((i37 - 1) << 5)) - 1] = (unsigned char)(1 <<
          g_d_direction.East);
      } else {
        col_dir_node[(maze_goal[9] + ((i37 - 1) << 5)) - 1] = 0U;
      }

      /* �X�V�pMAP�X�V */
      if ((unsigned int)i35 > 255U) {
        i35 = 255;
      }

      col_num_node_temp[(maze_goal[9] + ((i35 - 1) << 5)) - 1] = 0U;
    }

    /* ��� */
    if (g_direction.South <= 7) {
      i43 = (unsigned char)(1 << g_direction.South);
    } else {
      i43 = 0;
    }

    if ((maze_wall[ii] & i43) == 0) {
      /* �����X�V */
      row_num_node_tmp = (maze_goal[9] + 33 * (maze_goal[0] - 1)) - 1;
      row_num_node[row_num_node_tmp] = 3U;

      /* �����ǉ� */
      if (g_d_direction.South <= 7) {
        i47 = (unsigned char)(1 << g_d_direction.South);
      } else {
        i47 = 0;
      }

      row_dir_node[row_num_node_tmp] = (unsigned char)
        (row_dir_node[row_num_node_tmp] | i47);

      /* �X�V�pMAP�X�V */
      row_num_node_temp[row_num_node_tmp] = 0U;
    }

    /* ���� */
    if (g_direction.West <= 7) {
      i45 = (unsigned char)(1 << g_direction.West);
    } else {
      i45 = 0;
    }

    if ((maze_wall[ii] & i45) == 0) {
      /* �����X�V */
      col_num_node[ii] = 3U;

      /* �����ǉ� */
      if (g_d_direction.West <= 7) {
        i49 = (unsigned char)(1 << g_d_direction.West);
      } else {
        i49 = 0;
      }

      col_dir_node[ii] = (unsigned char)(col_dir_node[ii] | i49);

      /* �X�V�pMAP�X�V */
      col_num_node_temp[ii] = 0U;
    }

    /* �S�[���Z�N�V�������m�肵�Ă��Ȃ��ꍇ     */
  } else {
    /* �S�[���m�[�h�� */
    /*  �����F0����� */
    /*  �i�s���� : �ǂ��Ȃ���ΑS����=0b11111111=255 */
    /*  ����� */
    i35 = goal_size;
    for (idx = 0; idx < i35; idx++) {
      /* �k�� */
      ii = maze_goal[idx] - 1;
      i37 = maze_goal[idx + 9];
      i38 = (i37 + (ii << 5)) - 1;
      if (g_direction.North <= 7) {
        i40 = (unsigned char)(1 << g_direction.North);
      } else {
        i40 = 0;
      }

      if ((maze_wall[i38] & i40) == 0) {
        /* �����X�V */
        i41 = (int)(maze_goal[idx + 9] + 1U);
        i42 = i41;
        if ((unsigned int)i41 > 255U) {
          i42 = 255;
        }

        row_num_node_tmp = 33 * ii;
        row_num_node[(i42 + row_num_node_tmp) - 1] = 0U;

        /* �����X�V */
        if ((unsigned int)i41 > 255U) {
          i41 = 255;
        }

        row_dir_node[(i41 + row_num_node_tmp) - 1] = MAX_uint8_T;
      }

      /* ���� */
      if (g_direction.East <= 7) {
        i44 = (unsigned char)(1 << g_direction.East);
      } else {
        i44 = 0;
      }

      if ((maze_wall[i38] & i44) == 0) {
        /* �����X�V */
        ii = (int)(maze_goal[idx] + 1U);
        i41 = ii;
        if ((unsigned int)ii > 255U) {
          i41 = 255;
        }

        col_num_node[(i37 + ((i41 - 1) << 5)) - 1] = 0U;

        /* �����X�V */
        if ((unsigned int)ii > 255U) {
          ii = 255;
        }

        col_dir_node[(i37 + ((ii - 1) << 5)) - 1] = MAX_uint8_T;
      }

      /* ��� */
      if (g_direction.South <= 7) {
        i46 = (unsigned char)(1 << g_direction.South);
      } else {
        i46 = 0;
      }

      if ((maze_wall[i38] & i46) == 0) {
        /* �����X�V */
        row_num_node_tmp = (i37 + 33 * (maze_goal[idx] - 1)) - 1;
        row_num_node[row_num_node_tmp] = 0U;

        /* �����X�V */
        row_dir_node[row_num_node_tmp] = MAX_uint8_T;
      }

      /* ���� */
      if (g_direction.West <= 7) {
        i48 = (unsigned char)(1 << g_direction.West);
      } else {
        i48 = 0;
      }

      if ((maze_wall[i38] & i48) == 0) {
        /* �����X�V */
        col_num_node[i38] = 0U;

        /* �����X�V */
        col_dir_node[i38] = MAX_uint8_T;
      }
    }

    /* �X�V����p�ϐ�(�d�݂Â��Ȃ��̕����}�b�v) */
    memcpy(&row_num_node_temp[0], &row_num_node[0], 1056U * sizeof(unsigned
            short));
    memcpy(&col_num_node_temp[0], &col_num_node[0], 1056U * sizeof(unsigned
            short));
  }

  emxInit_uint16_T(&row, 1);
  emxInit_uint16_T(&col, 1);
  emxInit_uint16_T(&b_num_temp, 1);
  do {
    change_flag = 0U;

    /* map�X�V�m�F�p�t���O */
    idx = max_length->contents;
    qY = idx - 1U;
    if (qY > (unsigned int)idx) {
      qY = 0U;
    }

    u5 = (unsigned short)qY;
    for (i = 0; i <= u5; i++) {
      /* �X�V�m�F�p�̕����J�E���g��0~max_length */
      /* Row_Edge�̏���[33�s,32��] */
      /* �������m�肵�Ă�����W������ */
      /* �ŏ���0,�X�V����A���������}�X�����X�������Ă��� */
      idx = 0;
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii < 1056)) {
        if (row_num_node_temp[ii] == i) {
          idx++;
          ii_data[idx - 1] = (short)(ii + 1);
          if (idx >= 1056) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        ii = 0;
      } else {
        ii = idx;
      }

      i35 = num_temp->contents->size[0];
      num_temp->contents->size[0] = ii;
      emxEnsureCapacity_uint16_T(num_temp->contents, i35);
      for (i35 = 0; i35 < ii; i35++) {
        num_temp->contents->data[i35] = (unsigned short)ii_data[i35];
      }

      /* 33�s�Ȃ̂ŁA�s�ԍ�:33�Ŋ��������܂� */
      i35 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i35);
      ii = num_temp->contents->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        idx = num_temp->contents->data[i35];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i35] = (unsigned short)qY;
      }

      d_rem(b_num_temp, row);
      i35 = row->size[0];
      emxEnsureCapacity_uint16_T(row, i35);
      ii = row->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        qY = row->data[i35] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        row->data[i35] = (unsigned short)qY;
      }

      /* ��ԍ�:33�Ŋ������Ƃ��̏� */
      i35 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i35);
      ii = num_temp->contents->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        idx = num_temp->contents->data[i35];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i35] = (unsigned short)qY;
      }

      idivide(b_num_temp, 33.0, col);
      i35 = col->size[0];
      emxEnsureCapacity_uint16_T(col, i35);
      ii = col->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        qY = col->data[i35] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        col->data[i35] = (unsigned short)qY;
      }

      /* ���������}�X�̐� */
      /* �����������W�ɑ΂��A����map���X�V */
      i35 = row->size[0];
      if (i35 < 0) {
        i35 = 0;
      } else {
        if (i35 > 65535) {
          i35 = 65535;
        }
      }

      for (idx = 0; idx < i35; idx++) {
        /* �k�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.North <= 7) {
          i50 = (unsigned char)(1 << g_direction.North);
        } else {
          i50 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i50) != 0) == wall->contents.nowall) {
          if (g_direction.North <= 7) {
            i51 = (unsigned char)(1 << g_direction.North);
          } else {
            i51 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i51) != 0) == search->contents.known) {
            /* ���i�s�������k�����ł��鎞 */
            if (g_d_direction.North <= 7) {
              i53 = (unsigned char)(1 << g_d_direction.North);
            } else {
              i53 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i53) != 0) {
              /* ���k�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 6U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North <= 7) {
                    i64 = (unsigned char)(1 << g_d_direction.North);
                  } else {
                    i64 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i64);
                }
              }

              /* ���i�s�������k�����łȂ��Ƃ�     */
            } else {
              /* ���k�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North <= 7) {
                    i63 = (unsigned char)(1 << g_d_direction.North);
                  } else {
                    i63 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i63);
                }
              }
            }
          }
        }

        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.East <= 7) {
          i52 = (unsigned char)(1 << g_direction.East);
        } else {
          i52 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i52) != 0) == wall->contents.nowall) {
          if (g_direction.East <= 7) {
            i54 = (unsigned char)(1 << g_direction.East);
          } else {
            i54 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i54) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_East <= 7) {
              i56 = (unsigned char)(1 << g_d_direction.North_East);
            } else {
              i56 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i56) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i70 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i70 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i70);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i69 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i69 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i69);
                }
              }
            }
          }
        }

        /* �����͒� */
        /* �쓌�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2];
        if (g_direction.East <= 7) {
          i55 = (unsigned char)(1 << g_direction.East);
        } else {
          i55 = 0;
        }

        if (((a & i55) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
            2];
          if (g_direction.East <= 7) {
            i57 = (unsigned char)(1 << g_direction.East);
          } else {
            i57 = 0;
          }

          if (((a & i57) != 0) == search->contents.known) {
            /* ���i�s�������쓌�����ł��鎞 */
            if (g_d_direction.South_East <= 7) {
              i59 = (unsigned char)(1 << g_d_direction.South_East);
            } else {
              i59 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i59) != 0) {
              /* ���쓌�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] >
                  (int)u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u6;

                /* ����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.South_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.South_East <= 7) {
                    i76 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i76 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(a | i76);
                }
              }

              /* ���i�s�������쓌�����łȂ��Ƃ�     */
            } else {
              /* ���쓌�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] >
                  (int)u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u6;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.South_East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.South_East <= 7) {
                    i75 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i75 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 2] =
                    (unsigned char)(a | i75);
                }
              }
            }
          }
        }

        /* �쑤 */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2];
        if (g_direction.South <= 7) {
          i58 = (unsigned char)(1 << g_direction.South);
        } else {
          i58 = 0;
        }

        if (((a & i58) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
            2];
          if (g_direction.South <= 7) {
            i60 = (unsigned char)(1 << g_direction.South);
          } else {
            i60 = 0;
          }

          if (((a & i60) != 0) == search->contents.known) {
            /* ���i�s������������ł��鎞 */
            if (g_d_direction.South <= 7) {
              i62 = (unsigned char)(1 << g_d_direction.South);
            } else {
              i62 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i62) != 0) {
              /* ����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 6U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  2] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(1 << g_d_direction.South);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1))
                    - 2];
                  if (g_d_direction.South <= 7) {
                    i73 = (unsigned char)(1 << g_d_direction.South);
                  } else {
                    i73 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(a | i73);
                }
              }

              /* ���i�s������������łȂ��Ƃ�     */
            } else {
              /* ����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  2] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(1 << g_d_direction.South);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1))
                    - 2];
                  if (g_d_direction.South <= 7) {
                    i72 = (unsigned char)(1 << g_d_direction.South);
                  } else {
                    i72 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 2]
                    = (unsigned char)(a | i72);
                }
              }
            }
          }
        }

        /* �쐼�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2];
        if (g_direction.West <= 7) {
          i61 = (unsigned char)(1 << g_direction.West);
        } else {
          i61 = 0;
        }

        if (((a & i61) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
            2];
          if (g_direction.West <= 7) {
            i65 = (unsigned char)(1 << g_direction.West);
          } else {
            i65 = 0;
          }

          if (((a & i65) != 0) == search->contents.known) {
            /* ���i�s�������쐼�����ł��鎞 */
            if (g_d_direction.South_West <= 7) {
              i67 = (unsigned char)(1 << g_d_direction.South_West);
            } else {
              i67 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i67) != 0) {
              /* ���쐼�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  2] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 2] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2];
                  if (g_d_direction.South_West <= 7) {
                    i79 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i79 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(a | i79);
                }
              }

              /* ���i�s�������쐼�����łȂ��Ƃ�     */
            } else {
              /* ���쐼�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  2] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 2] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 2]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 2];
                  if (g_d_direction.South_West <= 7) {
                    i78 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i78 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    2] = (unsigned char)(a | i78);
                }
              }
            }
          }
        }

        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.West <= 7) {
          i66 = (unsigned char)(1 << g_direction.West);
        } else {
          i66 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i66) != 0) == wall->contents.nowall) {
          if (g_direction.West <= 7) {
            i68 = (unsigned char)(1 << g_direction.West);
          } else {
            i68 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i68) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_West <= 7) {
              i71 = (unsigned char)(1 << g_d_direction.North_West);
            } else {
              i71 = 0;
            }

            if ((row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                 & i71) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.North_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.North_West <= 7) {
                    i84 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i84 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(col_dir_node[(row->data[idx] +
                    ((col->data[idx] - 1) << 5)) - 1] | i84);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] -
                  1)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.North_West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.North_West <= 7) {
                    i83 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i83 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                    1] = (unsigned char)(col_dir_node[(row->data[idx] +
                    ((col->data[idx] - 1) << 5)) - 1] | i83);
                }
              }
            }
          }
        }
      }

      /* Col_Edge�̏���[32�s,33��] */
      /* �������m�肵�Ă�����W������ */
      /* �ŏ���0,�X�V����A���������}�X�����X�������Ă��� */
      idx = 0;
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii < 1056)) {
        if (col_num_node_temp[ii] == i) {
          idx++;
          ii_data[idx - 1] = (short)(ii + 1);
          if (idx >= 1056) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        ii = 0;
      } else {
        ii = idx;
      }

      i35 = num_temp->contents->size[0];
      num_temp->contents->size[0] = ii;
      emxEnsureCapacity_uint16_T(num_temp->contents, i35);
      for (i35 = 0; i35 < ii; i35++) {
        num_temp->contents->data[i35] = (unsigned short)ii_data[i35];
      }

      /* 32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂� */
      i35 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i35);
      ii = num_temp->contents->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        idx = num_temp->contents->data[i35];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i35] = (unsigned short)qY;
      }

      c_rem(b_num_temp, row);
      i35 = row->size[0];
      emxEnsureCapacity_uint16_T(row, i35);
      ii = row->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        qY = row->data[i35] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        row->data[i35] = (unsigned short)qY;
      }

      /* ��ԍ�:32�Ŋ������Ƃ��̏� */
      i35 = b_num_temp->size[0];
      b_num_temp->size[0] = num_temp->contents->size[0];
      emxEnsureCapacity_uint16_T(b_num_temp, i35);
      ii = num_temp->contents->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        idx = num_temp->contents->data[i35];
        qY = idx - 1U;
        if (qY > (unsigned int)idx) {
          qY = 0U;
        }

        b_num_temp->data[i35] = (unsigned short)qY;
      }

      idivide(b_num_temp, 32.0, col);
      i35 = col->size[0];
      emxEnsureCapacity_uint16_T(col, i35);
      ii = col->size[0];
      for (i35 = 0; i35 < ii; i35++) {
        qY = col->data[i35] + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        col->data[i35] = (unsigned short)qY;
      }

      /* ���������}�X�̐� */
      /* �����������W�ɑ΂��A����map���X�V */
      i35 = row->size[0];
      if (i35 < 0) {
        i35 = 0;
      } else {
        if (i35 > 65535) {
          i35 = 65535;
        }
      }

      for (idx = 0; idx < i35; idx++) {
        /* �k���͕� */
        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.North <= 7) {
          i74 = (unsigned char)(1 << g_direction.North);
        } else {
          i74 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i74) != 0) == wall->contents.nowall) {
          if (g_direction.North <= 7) {
            i77 = (unsigned char)(1 << g_direction.North);
          } else {
            i77 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i77) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_East <= 7) {
              i81 = (unsigned char)(1 << g_d_direction.North_East);
            } else {
              i81 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i81) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i95 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i95 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i95);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] > (int)
                  u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_East <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_East);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_East <= 7) {
                    i94 = (unsigned char)(1 << g_d_direction.North_East);
                  } else {
                    i94 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 1)) - 1] =
                    (unsigned char)(a | i94);
                }
              }
            }
          }
        }

        /* ���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.East <= 7) {
          i80 = (unsigned char)(1 << g_direction.East);
        } else {
          i80 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i80) != 0) == wall->contents.nowall) {
          if (g_direction.East <= 7) {
            i82 = (unsigned char)(1 << g_direction.East);
          } else {
            i82 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i82) != 0) == search->contents.known) {
            /* ���i�s�������������ł��鎞 */
            if (g_d_direction.East <= 7) {
              i86 = (unsigned char)(1 << g_d_direction.East);
            } else {
              i86 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i86) != 0) {
              /* �����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 6U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.East <= 7) {
                    i101 = (unsigned char)(1 << g_d_direction.East);
                  } else {
                    i101 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i101);
                }
              }

              /* ���i�s�������������łȂ��Ƃ�     */
            } else {
              /* �����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] >
                  (int)u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node_temp[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.East <= 7) {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(1 << g_d_direction.East);
                } else {
                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (col_num_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1];
                  qY = col->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.East <= 7) {
                    i100 = (unsigned char)(1 << g_d_direction.East);
                  } else {
                    i100 = 0;
                  }

                  col_dir_node[(row->data[idx] + (((int)qY - 1) << 5)) - 1] =
                    (unsigned char)(a | i100);
                }
              }
            }
          }
        }

        /* �쓌�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        if (g_direction.South <= 7) {
          i85 = (unsigned char)(1 << g_direction.South);
        } else {
          i85 = 0;
        }

        if (((maze_wall[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1] &
              i85) != 0) == wall->contents.nowall) {
          if (g_direction.South <= 7) {
            i87 = (unsigned char)(1 << g_direction.South);
          } else {
            i87 = 0;
          }

          if (((maze_wall_search[(row->data[idx] + ((col->data[idx] - 1) << 5))
                - 1] & i87) != 0) == search->contents.known) {
            /* ���i�s�������쓌�����ł��鎞 */
            if (g_d_direction.South_East <= 7) {
              i89 = (unsigned char)(1 << g_d_direction.South_East);
            } else {
              i89 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i89) != 0) {
              /* ���쓌�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_East <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.South_East <= 7) {
                    i97 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i97 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(row_dir_node[(row->data[idx] + 33 *
                    (col->data[idx] - 1)) - 1] | i97);
                }
              }

              /* ���i�s�������쓌�����łȂ��Ƃ�     */
            } else {
              /* ���쓌�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_East <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_East);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 1)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  if (g_d_direction.South_East <= 7) {
                    i96 = (unsigned char)(1 << g_d_direction.South_East);
                  } else {
                    i96 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 1)) - 1]
                    = (unsigned char)(row_dir_node[(row->data[idx] + 33 *
                    (col->data[idx] - 1)) - 1] | i96);
                }
              }
            }
          }
        }

        /* �쑤�͒� */
        /* �쐼�� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1];
        if (g_direction.South <= 7) {
          i88 = (unsigned char)(1 << g_direction.South);
        } else {
          i88 = 0;
        }

        if (((a & i88) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
            1];
          if (g_direction.South <= 7) {
            i90 = (unsigned char)(1 << g_direction.South);
          } else {
            i90 = 0;
          }

          if (((a & i90) != 0) == search->contents.known) {
            /* ���i�s�������쐼�����ł��鎞 */
            if (g_d_direction.South_West <= 7) {
              i92 = (unsigned char)(1 << g_d_direction.South_West);
            } else {
              i92 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i92) != 0) {
              /* ���쐼�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2))
                    - 1];
                  if (g_d_direction.South_West <= 7) {
                    i104 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i104 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(a | i104);
                }
              }

              /* ���i�s�������쐼�����łȂ��Ƃ�     */
            } else {
              /* ���쐼�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                  > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node_temp[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                  1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.South_West <= 7) {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(1 << g_d_direction.South_West);
                } else {
                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (row_num_node[(row->data[idx] + 33 * (col->data[idx] - 2)) -
                    1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2))
                    - 1];
                  if (g_d_direction.South_West <= 7) {
                    i103 = (unsigned char)(1 << g_d_direction.South_West);
                  } else {
                    i103 = 0;
                  }

                  row_dir_node[(row->data[idx] + 33 * (col->data[idx] - 2)) - 1]
                    = (unsigned char)(a | i103);
                }
              }
            }
          }
        }

        /* ���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1];
        if (g_direction.West <= 7) {
          i91 = (unsigned char)(1 << g_direction.West);
        } else {
          i91 = 0;
        }

        if (((a & i91) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
            1];
          if (g_direction.West <= 7) {
            i93 = (unsigned char)(1 << g_direction.West);
          } else {
            i93 = 0;
          }

          if (((a & i93) != 0) == search->contents.known) {
            /* ���i�s�������������ł��鎞 */
            if (g_d_direction.West <= 7) {
              i99 = (unsigned char)(1 << g_d_direction.West);
            } else {
              i99 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i99) != 0) {
              /* �����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 6U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 2) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 6U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1];
                  if (g_d_direction.West <= 7) {
                    i107 = (unsigned char)(1 << g_d_direction.West);
                  } else {
                    i107 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(a | i107);
                }
              }

              /* ���i�s�������������łȂ��Ƃ�     */
            } else {
              /* �����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                  1] > (int)qY) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node_temp[(row->data[idx] + ((col->data[idx] - 2) << 5))
                  - 1] = (unsigned short)qY;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1]
                  = (unsigned short)qY;

                /* �ړ�����MAP�X�V */
                if (g_d_direction.West <= 7) {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(1 << g_d_direction.West);
                } else {
                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* �����̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (col_num_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1] == (int)qY) {
                  /* �ړ�������ǉ� */
                  a = col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5))
                    - 1];
                  if (g_d_direction.West <= 7) {
                    i106 = (unsigned char)(1 << g_d_direction.West);
                  } else {
                    i106 = 0;
                  }

                  col_dir_node[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
                    1] = (unsigned char)(a | i106);
                }
              }
            }
          }
        }

        /* �k���� */
        /* �ǂ����� & �T���ς݂ł���Ƃ� */
        a = maze_wall[(row->data[idx] + ((col->data[idx] - 2) << 5)) - 1];
        if (g_direction.North <= 7) {
          i98 = (unsigned char)(1 << g_direction.North);
        } else {
          i98 = 0;
        }

        if (((a & i98) != 0) == wall->contents.nowall) {
          a = maze_wall_search[(row->data[idx] + ((col->data[idx] - 2) << 5)) -
            1];
          if (g_direction.North <= 7) {
            i102 = (unsigned char)(1 << g_direction.North);
          } else {
            i102 = 0;
          }

          if (((a & i102) != 0) == search->contents.known) {
            /* ���i�s�������k�������ł��鎞 */
            if (g_d_direction.North_West <= 7) {
              i105 = (unsigned char)(1 << g_d_direction.North_West);
            } else {
              i105 = 0;
            }

            if ((col_dir_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) - 1]
                 & i105) != 0) {
              /* ���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 4U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] > (int)
                  u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_West <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 4U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_West <= 7) {
                    i109 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i109 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(a | i109);
                }
              }

              /* ���i�s�������k�������łȂ��Ƃ�     */
            } else {
              /* ���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ */
              qY = row->data[idx] + 1U;
              if (qY > 65535U) {
                qY = 65535U;
              }

              u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5)) -
                1] + 18U;
              if (u6 > 65535U) {
                u6 = 65535U;
              }

              if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] > (int)
                  u6) {
                /* �X�V�m�F�p��MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node_temp[(row->data[idx] + ((col->data[idx] - 1) <<
                  5)) - 1] + 1U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node_temp[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u6;

                /* ����MAP�X�V(�d�݂Â�����) */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                  (unsigned short)u6;

                /* �ړ�����MAP�X�V */
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                if (g_d_direction.North_West <= 7) {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(1 << g_d_direction.North_West);
                } else {
                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] = 0U;
                }

                /* �X�V�t���O�𗧂Ă� */
                change_flag = 1U;

                /* ���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ */
              } else {
                qY = row->data[idx] + 1U;
                if (qY > 65535U) {
                  qY = 65535U;
                }

                u6 = col_num_node[(row->data[idx] + ((col->data[idx] - 1) << 5))
                  - 1] + 18U;
                if (u6 > 65535U) {
                  u6 = 65535U;
                }

                if (row_num_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] ==
                    (int)u6) {
                  /* �ړ�������ǉ� */
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  a = row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1];
                  qY = row->data[idx] + 1U;
                  if (qY > 65535U) {
                    qY = 65535U;
                  }

                  if (g_d_direction.North_West <= 7) {
                    i108 = (unsigned char)(1 << g_d_direction.North_West);
                  } else {
                    i108 = 0;
                  }

                  row_dir_node[((int)qY + 33 * (col->data[idx] - 2)) - 1] =
                    (unsigned char)(a | i108);
                }
              }
            }
          }
        }
      }
    }

    /* �X�V���Ȃ���ΏI��(�X�^�[�g�n�_�̕����}�b�v���X�V)     */
  } while (!(change_flag == 0));

  emxFree_uint16_T(&b_num_temp);
  emxFree_uint16_T(&col);
  emxFree_uint16_T(&row);
  qY = row_num_node[1] + 3U;
  if (qY > 65535U) {
    qY = 65535U;
  }

  *start_num = (unsigned short)qY;
}

/*
 * �X�^�[�g�m�[�h�̏�����
 * Arguments    : const unsigned short row_num_node[1056]
 *                const unsigned short col_num_node[1056]
 *                const unsigned char goal_section[2]
 *                const unsigned char goal_node2[2]
 *                unsigned char goal_node_property
 * Return Type  : void
 */
static void make_route_diagonal(const unsigned short row_num_node[1056], const
  unsigned short col_num_node[1056], const unsigned char goal_section[2], const
  unsigned char goal_node2[2], unsigned char goal_node_property)
{
  unsigned char current_node[2];
  unsigned char current_node_property;
  unsigned char current_move_dir;
  unsigned char current_move_mode;
  unsigned char straight_count;
  unsigned char ref_move_dir;
  unsigned char ref_move_mode;
  int goal_flag;
  unsigned char next_node[2];
  unsigned char next_move_dir;
  unsigned char b_next_node[2];
  unsigned char next_node_property;
  int exitg1;
  int i;
  double move_dir_buffer[3];
  unsigned char ref_node_property;
  bool exitg2;
  bool p;
  bool b_p;
  int k;
  unsigned char turn_pattern_num;
  unsigned char b_next_node_property;
  unsigned int qY;
  unsigned char b_next_move_dir;

  /*  make_route_diagonal �΂ߗL�ł̍ŒZ���[�g�����A���s */
  current_node[0] = 1U;
  current_node[1] = 1U;

  /* �����}�X�̓�̃m�[�h */
  current_node_property = matrix_dir.Row;

  /* ��̃m�[�h�̑����͍s���� */
  current_move_dir = g_d_direction.North;

  /* �����̐i�s�����͖k */
  current_move_mode = move_dir_property.straight;

  /* �����̐i�s���������͒��i�i�΂߂łȂ��j */
  straight_count = 0U;

  /* ���i�p�̃J�E���^ */
  /* ����̂ݎ��̃m�[�h���Œ� */
  /* �����}�X�̖k�̃m�[�h */
  /* �k�̃m�[�h�̑����͍s���� */
  /* ��m�[�h���W�����̃m�[�h�� */
  /* ��m�[�h�̈ړ������A���[�h�����݂̃m�[�h�ɐݒ� */
  ref_move_dir = g_d_direction.North;
  ref_move_mode = move_dir_property.straight;

  /* �S�[���t���O�����܂Ń��[�v */
  goal_flag = 0;

  /* �΂ߍ��݂̐i�s���@�I�� */
  next_node[0] = 2U;
  next_node[1] = 1U;
  get_next_dir_diagonal(row_num_node, col_num_node, g_d_direction.North,
                        next_node, matrix_dir.Row, goal_node2,
                        goal_node_property, goal_section, &next_move_dir,
                        b_next_node, &next_node_property);
  do {
    exitg1 = 0;

    /*          disp(["next_move_dir=",num2str(next_move_dir)]) */
    /*          disp(["ref_move_dir=",num2str(ref_move_dir)]) */
    /* ��m�[�h���猩�āA�i�s����������̂Ƃ� */
    if (ref_move_dir == next_move_dir) {
      /*              disp("���i") */
      i = (int)(straight_count + 1U);
      if ((unsigned int)i > 255U) {
        i = 255;
      }

      straight_count = (unsigned char)i;

      /* ���i�J�E���^���C���N�������g */
      /* ��m�[�h���ړ�����B */
      ref_node_property = next_node_property;
      ref_move_dir = next_move_dir;

      /* ��m�[�h���S�[���ł��邩���� */
      p = false;
      b_p = true;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k < 2)) {
        if (b_next_node[k] != goal_node2[k]) {
          b_p = false;
          exitg2 = true;
        } else {
          k++;
        }
      }

      if (b_p) {
        p = true;
      }

      if ((p && (next_node_property == goal_node_property)) ||
          ((next_node_property == matrix_dir.section) && (goal_section[1] ==
            b_next_node[0]) && (goal_section[0] == b_next_node[1]))) {
        /* ���݈ʒu���m�[�h�ł��鎞�A�S�[���i�����̃p�^�[�������肷��B */
        p = false;
        b_p = true;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k < 2)) {
          if (b_next_node[k] != goal_node2[k]) {
            b_p = false;
            exitg2 = true;
          } else {
            k++;
          }
        }

        if (b_p) {
          p = true;
        }

        if (p && (next_node_property == goal_node_property)) {
          /* �S�[���̏ꍇ�A�S�[���i�����̃p�^�[�������肷��B */
          get_next_dir_diagonal(row_num_node, col_num_node, next_move_dir,
                                b_next_node, next_node_property, goal_node2,
                                goal_node_property, goal_section,
                                &b_next_move_dir, next_node,
                                &b_next_node_property);

          /* ���i�̏ꍇ�i���i�N���j */
          if (next_move_dir == b_next_move_dir) {
            /* �S�[�����J�E���^�𑝉� */
            i = (int)((unsigned char)i + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            /* ���݃m�[�h���璼�i�J�E���^���ړ�����֐��B */
            move_straight(current_node, &current_node_property,
                          &current_move_dir, &current_move_mode, (unsigned char)
                          i);
            straight_count = 0U;

            /*                          disp("�S�[�������N��") */
            /*                          disp(current_node) */
            /* �^�[���̏ꍇ�i�΂ߐN���j */
            /* 45�x�^�[���̂ݑz��(���̈ړ������Ń^�[���̎�ނ�����) */
          } else {
            /*                          disp("�S�[�������i�O") */
            /*                          disp(current_node) */
            /* ���i�J�E���^������Έړ� */
            /* �O�Ղ��v���b�g */
            /* ���݃m�[�h���璼�i�J�E���^���ړ�����֐��B */
            move_straight(current_node, &current_node_property,
                          &current_move_dir, &current_move_mode, (unsigned char)
                          i);
            straight_count = 0U;

            /*                          disp("�S�[�������i��") */
            /*                          disp(current_node) */
            /* �i�s�����̃o�b�t�@���N���A */
            move_dir_buffer[1] = 0.0;
            move_dir_buffer[2] = 0.0;

            /* 1��܂ł̐i�s��������A�^�[���̃p�^�[�������� */
            /* ���ݐi�s��������̑��ΓI�Ȉړ��������o�b�t�@ */
            if (b_next_move_dir > 127) {
              b_next_move_dir = 127U;
            }

            turn_pattern_num = current_move_dir;
            if (current_move_dir > 127) {
              turn_pattern_num = 127U;
            }

            move_dir_buffer[0] = (b_next_move_dir - turn_pattern_num) & 7;

            /* �^�[���̎�ނ𔻒肷�� */
            turn_pattern_num = get_turn_pattern_num(move_dir_buffer,
              ref_move_mode);

            /* �^�[���̋O�Ղ�`�悷�� */
            /* �p�^�[�������܂�Ȃ������ꍇ�A�G���[ */
            /* �p�^�[���ɉ������ړ����� */
            if (turn_pattern_num == turn_pattern.r_45) {
              turn_r_45(current_node, &current_node_property, &current_move_dir,
                        &current_move_mode);
            } else {
              if (turn_pattern_num == turn_pattern.l_45) {
                turn_l_45(current_node, &current_node_property,
                          &current_move_dir, &current_move_mode);
              }
            }
          }

          /* �Q�ƈʒu���Z�N�V�����ł���Ƃ� */
        } else {
          /* ���i�J�E���^������΁A�ړ�����B */
          /*                      disp("�S�[�������i�i�Z�N�V�����j") */
          /* �O�Ղ��v���b�g */
          /* ���݃m�[�h���璼�i�J�E���^���ړ�����֐��B */
          move_straight(current_node, &current_node_property, &current_move_dir,
                        &current_move_mode, (unsigned char)i);
          straight_count = 0U;
        }

        /* �S�[�����������������t���O�𗧂Ă� */
        /*                  disp("�S�[����") */
        /*                  disp(straight_count) */
        /*                  disp(current_node) */
        goal_flag = 1;
      }

      /* ��m�[�h���猩�āA�i�s�������قȂ�(�Ȃ���)�Ƃ� */
    } else {
      /*              disp("�^�[��") */
      /* ���i�J�E���^����Ƃ� */
      if (straight_count > 0) {
        /* �O�Ղ��v���b�g */
        /* ���݃m�[�h���璼�i�J�E���^���ړ�����֐��B */
        move_straight(current_node, &current_node_property, &current_move_dir,
                      &current_move_mode, straight_count);
        straight_count = 0U;

        /*                  disp("�^�[���O���i�J�E���^") */
        /*                  disp(straight_count) */
        /*                  disp(current_node) */
      }

      /* �i�s�����̃o�b�t�@���N���A */
      move_dir_buffer[0] = 0.0;
      move_dir_buffer[1] = 0.0;
      move_dir_buffer[2] = 0.0;

      /* 3��܂ł̐i�s��������A�^�[���̃p�^�[�������� */
      i = 0;
      exitg2 = false;
      while ((!exitg2) && (i < 3)) {
        /* ���ݐi�s��������̑��ΓI�Ȉړ��������o�b�t�@ */
        /*                  disp(["current_move_dir",num2str(current_move_dir)]) */
        /*                  disp(["next_move_dir",num2str(next_move_dir)]) */
        turn_pattern_num = next_move_dir;
        if (next_move_dir > 127) {
          turn_pattern_num = 127U;
        }

        b_next_node_property = current_move_dir;
        if (current_move_dir > 127) {
          b_next_node_property = 127U;
        }

        move_dir_buffer[i] = (turn_pattern_num - b_next_node_property) & 7;

        /* �^�[���̎�ނ𔻒肷�� */
        turn_pattern_num = get_turn_pattern_num(move_dir_buffer, ref_move_mode);

        /* �p�^�[�����m�肵�Ă���ΏI�� */
        if (turn_pattern_num != 0) {
          /* �p�^�[���̋O�Ղ�`�� */
          exitg2 = true;
        } else {
          /* ���̐i�s���������肷�� */
          next_node[0] = b_next_node[0];
          next_node[1] = b_next_node[1];
          get_next_dir_diagonal(row_num_node, col_num_node, next_move_dir,
                                next_node, next_node_property, goal_node2,
                                goal_node_property, goal_section, &next_move_dir,
                                b_next_node, &next_node_property);

          /* 3��ڂŃp�^�[�������܂�Ȃ������ꍇ�A�G���[ */
          i++;
        }
      }

      /* �p�^�[���ɉ����Ĉړ� */
      if (turn_pattern_num == turn_pattern.r_45) {
        turn_r_45(current_node, &current_node_property, &current_move_dir,
                  &current_move_mode);
      } else if (turn_pattern_num == turn_pattern.l_45) {
        turn_l_45(current_node, &current_node_property, &current_move_dir,
                  &current_move_mode);
      } else if (turn_pattern_num == turn_pattern.r_90) {
        /* ���i�p�^�[���̎� */
        /*  �E90�x */
        if (current_move_mode == move_dir_property.straight) {
          if (current_move_dir == g_d_direction.North) {
            i = (int)(current_node[0] + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            current_node[0] = (unsigned char)i;
            i = (int)(current_node[1] + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            current_node[1] = (unsigned char)i;
            current_node_property = matrix_dir.Col;
            current_move_dir = g_d_direction.East;
            current_move_mode = move_dir_property.straight;
          } else if (current_move_dir == g_d_direction.East) {
            i = (int)(current_node[1] + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            current_node[1] = (unsigned char)i;
            current_node_property = matrix_dir.Row;
            current_move_dir = g_d_direction.South;
            current_move_mode = move_dir_property.straight;
          } else if (current_move_dir == g_d_direction.South) {
            qY = current_node[0] - 2U;
            if (qY > current_node[0]) {
              qY = 0U;
            }

            current_node[0] = (unsigned char)qY;
            current_node_property = matrix_dir.Col;
            current_move_dir = g_d_direction.West;
            current_move_mode = move_dir_property.straight;
          } else {
            if (current_move_dir == g_d_direction.West) {
              i = (int)(current_node[0] + 1U);
              if ((unsigned int)i > 255U) {
                i = 255;
              }

              current_node[0] = (unsigned char)i;
              i = (int)(current_node[1] + 2U);
              if ((unsigned int)i > 255U) {
                i = 255;
              }

              current_node[1] = (unsigned char)i;
              current_node_property = matrix_dir.Row;
              current_move_dir = g_d_direction.North;
              current_move_mode = move_dir_property.straight;
            }
          }

          /* �΂߃p�^�[���̎��iV90�j     */
        } else {
          if (current_move_mode == move_dir_property.diagonal) {
            if (current_move_dir == g_d_direction.North_East) {
              i = (int)(current_node[1] + 1U);
              if ((unsigned int)i > 255U) {
                i = 255;
              }

              current_node[1] = (unsigned char)i;
              current_node_property = matrix_dir.Row;
              current_move_dir = g_d_direction.South_East;
              current_move_mode = move_dir_property.diagonal;
            } else if (current_move_dir == g_d_direction.South_East) {
              qY = current_node[0] - 1U;
              if (qY > current_node[0]) {
                qY = 0U;
              }

              current_node[0] = (unsigned char)qY;
              current_node_property = matrix_dir.Col;
              current_move_dir = g_d_direction.South_West;
              current_move_mode = move_dir_property.diagonal;
            } else if (current_move_dir == g_d_direction.South_West) {
              qY = current_node[1] - 1U;
              if (qY > current_node[1]) {
                qY = 0U;
              }

              current_node[1] = (unsigned char)qY;
              current_node_property = matrix_dir.Row;
              current_move_dir = g_d_direction.North_West;
              current_move_mode = move_dir_property.diagonal;
            } else {
              if (current_move_dir == g_d_direction.North_West) {
                i = (int)(current_node[0] + 1U);
                if ((unsigned int)i > 255U) {
                  i = 255;
                }

                current_node[0] = (unsigned char)i;
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
              }
            }
          }
        }
      } else if (turn_pattern_num == turn_pattern.l_90) {
        turn_l_90(current_node, &current_node_property, &current_move_dir,
                  &current_move_mode);
      } else if (turn_pattern_num == turn_pattern.r_135) {
        turn_r_135(current_node, &current_node_property, &current_move_dir,
                   &current_move_mode);
      } else if (turn_pattern_num == turn_pattern.l_135) {
        turn_l_135(current_node, &current_node_property, &current_move_dir,
                   &current_move_mode);
      } else if (turn_pattern_num == turn_pattern.r_180) {
        /* ���i�p�^�[���̎� */
        /*  �E180�x */
        if (current_move_mode == move_dir_property.straight) {
          if (current_move_dir == g_d_direction.North) {
            i = (int)(current_node[0] + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            current_node[0] = (unsigned char)i;
            i = (int)(current_node[1] + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            current_node[1] = (unsigned char)i;
            current_node_property = matrix_dir.Row;
            current_move_dir = g_d_direction.South;
            current_move_mode = move_dir_property.straight;
          } else if (current_move_dir == g_d_direction.East) {
            qY = current_node[0] - 1U;
            if (qY > current_node[0]) {
              qY = 0U;
            }

            current_node[0] = (unsigned char)qY;
            i = (int)(current_node[1] + 1U);
            if ((unsigned int)i > 255U) {
              i = 255;
            }

            current_node[1] = (unsigned char)i;
            current_node_property = matrix_dir.Col;
            current_move_dir = g_d_direction.West;
            current_move_mode = move_dir_property.straight;
          } else if (current_move_dir == g_d_direction.South) {
            qY = current_node[0] - 1U;
            if (qY > current_node[0]) {
              qY = 0U;
            }

            current_node[0] = (unsigned char)qY;
            qY = current_node[1] - 1U;
            if (qY > current_node[1]) {
              qY = 0U;
            }

            current_node[1] = (unsigned char)qY;
            current_node_property = matrix_dir.Row;
            current_move_dir = g_d_direction.North;
            current_move_mode = move_dir_property.straight;
          } else {
            if (current_move_dir == g_d_direction.West) {
              i = (int)(current_node[0] + 1U);
              if ((unsigned int)i > 255U) {
                i = 255;
              }

              current_node[0] = (unsigned char)i;
              qY = current_node[1] - 1U;
              if (qY > current_node[1]) {
                qY = 0U;
              }

              current_node[1] = (unsigned char)qY;
              current_node_property = matrix_dir.Col;
              current_move_dir = g_d_direction.East;
              current_move_mode = move_dir_property.straight;
            }
          }

          /* �΂߃p�^�[���̎�     */
        }
      } else {
        if (turn_pattern_num == turn_pattern.l_180) {
          turn_l_180(current_node, &current_node_property, &current_move_dir,
                     &current_move_mode);
        }
      }

      /*              disp("�^�[���I�����A�m�[�h") */
      /*              disp(current_node) */
      /*              disp(goal_node2) */
      /* �ړ���A�S�[���𔻒� */
      if (isequal(current_node, goal_node2) && (current_node_property ==
           goal_node_property)) {
        goal_flag = 1;
      }

      /* ��m�[�h���ړ� */
      ref_node_property = next_node_property;
      ref_move_dir = current_move_dir;
      ref_move_mode = current_move_mode;
    }

    /* �S�[���t���O�������Ă���ΏI�� */
    if (goal_flag == 1) {
      exitg1 = 1;
    } else {
      /* ���̈ړ��������擾 */
      /* �΂ߍ��݂̐i�s���@�I�� */
      next_node[0] = b_next_node[0];
      next_node[1] = b_next_node[1];
      get_next_dir_diagonal(row_num_node, col_num_node, ref_move_dir, next_node,
                            ref_node_property, goal_node2, goal_node_property,
                            goal_section, &next_move_dir, b_next_node,
                            &next_node_property);

      /*          disp("���i�s����") */
      /*          disp(next_move_dir) */
    }
  } while (exitg1 == 0);
}

/*
 * ���� ���݈ʒux,y,���ݕ���
 * �o�� ���݈ʒux,y
 * Arguments    : unsigned char *current_x
 *                unsigned char *current_y
 *                unsigned char current_dir
 * Return Type  : void
 */
static void move_step(unsigned char *current_x, unsigned char *current_y,
                      unsigned char current_dir)
{
  int q0;
  unsigned int qY;

  /*  move_step ��}�X�O�i����֐� */
  /* �k�Ɉ�}�X */
  if (current_dir == g_direction.North) {
    q0 = (int)(*current_y + 1U);
    if ((unsigned int)q0 > 255U) {
      q0 = 255;
    }

    *current_y = (unsigned char)q0;

    /* disp("north_step") */
  }

  /* ���Ɉ�}�X */
  if (current_dir == g_direction.East) {
    q0 = (int)(*current_x + 1U);
    if ((unsigned int)q0 > 255U) {
      q0 = 255;
    }

    *current_x = (unsigned char)q0;

    /* disp("east_step") */
  }

  /* ��Ɉ�}�X */
  if (current_dir == g_direction.South) {
    q0 = *current_y;
    qY = q0 - 1U;
    if (qY > (unsigned int)q0) {
      qY = 0U;
    }

    *current_y = (unsigned char)qY;

    /* disp("south_step") */
  }

  /* ���Ɉ�}�X */
  if (current_dir == g_direction.West) {
    q0 = *current_x;
    qY = q0 - 1U;
    if (qY > (unsigned int)q0) {
      qY = 0U;
    }

    *current_x = (unsigned char)qY;

    /* disp("west_step") */
  }
}

/*
 * ���i��
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 *                unsigned char straight_count
 * Return Type  : void
 */
static void move_straight(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode, unsigned char straight_count)
{
  unsigned char u12;
  int q0;
  unsigned char temp_quotient;
  unsigned char temp_remainder;
  unsigned char temp_qr;
  unsigned int qY;

  /*  �ړ��p�֐� */
  /*  ���i */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u12 = current_node[1];
      q0 = (int)((unsigned int)current_node[0] + straight_count);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      current_node[1] = u12;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.North;
      *current_move_mode = move_dir_property.straight;
    } else if (*current_move_dir == g_d_direction.East) {
      q0 = (int)((unsigned int)current_node[1] + straight_count);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.East;
      *current_move_mode = move_dir_property.straight;
    } else if (*current_move_dir == g_d_direction.South) {
      u12 = current_node[1];
      q0 = current_node[0];
      qY = (unsigned int)q0 - straight_count;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      current_node[1] = u12;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.South;
      *current_move_mode = move_dir_property.straight;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u12 = current_node[1];
        qY = (unsigned int)u12 - straight_count;
        if (qY > u12) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.West;
        *current_move_mode = move_dir_property.straight;
      }
    }

    /* �΂ߒ��i�̂Ƃ�     */
  } else {
    if (*current_move_mode == move_dir_property.diagonal) {
      /* ���i�J�E���^��2�Ŋ��������Ƃ��܂�A���̍��v���v�Z */
      /* (�ړ���m�[�h���W�̈�ʉ��p) */
      temp_quotient = (unsigned char)trunc((double)straight_count / 2.0);
      temp_remainder = (unsigned char)(straight_count % 2);
      temp_qr = (unsigned char)(temp_quotient + temp_remainder);
      if (*current_move_dir == g_d_direction.North_East) {
        if (*current_node_property == matrix_dir.Row) {
          u12 = current_node[1];
          q0 = (int)((unsigned int)current_node[0] + temp_quotient);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          current_node[0] = (unsigned char)q0;
          q0 = (int)((unsigned int)u12 + temp_qr);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          current_node[1] = (unsigned char)q0;
          q0 = (int)((unsigned int)*current_node_property + temp_remainder);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          *current_node_property = (unsigned char)q0;
          *current_move_dir = g_d_direction.North_East;
          *current_move_mode = move_dir_property.diagonal;
        } else {
          if (*current_node_property == matrix_dir.Col) {
            u12 = current_node[1];
            q0 = (int)((unsigned int)current_node[0] + temp_qr);
            if ((unsigned int)q0 > 255U) {
              q0 = 255;
            }

            current_node[0] = (unsigned char)q0;
            q0 = (int)((unsigned int)u12 + temp_quotient);
            if ((unsigned int)q0 > 255U) {
              q0 = 255;
            }

            current_node[1] = (unsigned char)q0;
            q0 = *current_node_property;
            qY = (unsigned int)q0 - temp_remainder;
            if (qY > (unsigned int)q0) {
              qY = 0U;
            }

            *current_node_property = (unsigned char)qY;
            *current_move_dir = g_d_direction.North_East;
            *current_move_mode = move_dir_property.diagonal;
          }
        }
      } else if (*current_move_dir == g_d_direction.South_East) {
        if (*current_node_property == matrix_dir.Row) {
          u12 = current_node[1];
          q0 = current_node[0];
          qY = (unsigned int)q0 - temp_qr;
          if (qY > (unsigned int)q0) {
            qY = 0U;
          }

          current_node[0] = (unsigned char)qY;
          q0 = (int)((unsigned int)u12 + temp_qr);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          current_node[1] = (unsigned char)q0;
          q0 = (int)((unsigned int)*current_node_property + temp_remainder);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          *current_node_property = (unsigned char)q0;
          *current_move_dir = g_d_direction.South_East;
          *current_move_mode = move_dir_property.diagonal;
        } else {
          if (*current_node_property == matrix_dir.Col) {
            u12 = current_node[1];
            q0 = current_node[0];
            qY = (unsigned int)q0 - temp_quotient;
            if (qY > (unsigned int)q0) {
              qY = 0U;
            }

            current_node[0] = (unsigned char)qY;
            q0 = (int)((unsigned int)u12 + temp_quotient);
            if ((unsigned int)q0 > 255U) {
              q0 = 255;
            }

            current_node[1] = (unsigned char)q0;
            q0 = *current_node_property;
            qY = (unsigned int)q0 - temp_remainder;
            if (qY > (unsigned int)q0) {
              qY = 0U;
            }

            *current_node_property = (unsigned char)qY;
            *current_move_dir = g_d_direction.South_East;
            *current_move_mode = move_dir_property.diagonal;
          }
        }
      } else if (*current_move_dir == g_d_direction.South_West) {
        if (*current_node_property == matrix_dir.Row) {
          u12 = current_node[1];
          q0 = current_node[0];
          qY = (unsigned int)q0 - temp_qr;
          if (qY > (unsigned int)q0) {
            qY = 0U;
          }

          current_node[0] = (unsigned char)qY;
          qY = (unsigned int)u12 - temp_quotient;
          if (qY > u12) {
            qY = 0U;
          }

          current_node[1] = (unsigned char)qY;
          q0 = (int)((unsigned int)*current_node_property + temp_remainder);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          *current_node_property = (unsigned char)q0;
          *current_move_dir = g_d_direction.South_West;
          *current_move_mode = move_dir_property.diagonal;
        } else {
          if (*current_node_property == matrix_dir.Col) {
            u12 = current_node[1];
            q0 = current_node[0];
            qY = (unsigned int)q0 - temp_quotient;
            if (qY > (unsigned int)q0) {
              qY = 0U;
            }

            current_node[0] = (unsigned char)qY;
            qY = (unsigned int)u12 - temp_qr;
            if (qY > u12) {
              qY = 0U;
            }

            current_node[1] = (unsigned char)qY;
            q0 = *current_node_property;
            qY = (unsigned int)q0 - temp_remainder;
            if (qY > (unsigned int)q0) {
              qY = 0U;
            }

            *current_node_property = (unsigned char)qY;
            *current_move_dir = g_d_direction.South_West;
            *current_move_mode = move_dir_property.diagonal;
          }
        }
      } else {
        if (*current_move_dir == g_d_direction.North_West) {
          if (*current_node_property == matrix_dir.Row) {
            u12 = current_node[1];
            q0 = (int)((unsigned int)current_node[0] + temp_quotient);
            if ((unsigned int)q0 > 255U) {
              q0 = 255;
            }

            current_node[0] = (unsigned char)q0;
            qY = (unsigned int)u12 - temp_quotient;
            if (qY > u12) {
              qY = 0U;
            }

            current_node[1] = (unsigned char)qY;
            q0 = (int)((unsigned int)*current_node_property + temp_remainder);
            if ((unsigned int)q0 > 255U) {
              q0 = 255;
            }

            *current_node_property = (unsigned char)q0;
            *current_move_dir = g_d_direction.North_West;
            *current_move_mode = move_dir_property.diagonal;
          } else {
            if (*current_node_property == matrix_dir.Col) {
              u12 = current_node[1];
              q0 = (int)((unsigned int)current_node[0] + temp_qr);
              if ((unsigned int)q0 > 255U) {
                q0 = 255;
              }

              current_node[0] = (unsigned char)q0;
              qY = (unsigned int)u12 - temp_qr;
              if (qY > u12) {
                qY = 0U;
              }

              current_node[1] = (unsigned char)qY;
              q0 = *current_node_property;
              qY = (unsigned int)q0 - temp_remainder;
              if (qY > (unsigned int)q0) {
                qY = 0U;
              }

              *current_node_property = (unsigned char)qY;
              *current_move_dir = g_d_direction.North_West;
              *current_move_mode = move_dir_property.diagonal;
            }
          }
        }
      }
    }
  }

  /* �ړ��������A���i�J�E���^���N���A */
}

/*
 * ���́@���݈ʒux,y,���ݕ���,���H�s�����T�C�Y,���H������T�C�Y,���H�Ǐ��,���H�ǂ̒T�����,�S�[�����W
 * �o��  ���݈ʒux,y,���ݕ���,�Ǐ��,�T�����
 * Arguments    : const coder_internal_ref_5 *wall
 *                coder_internal_ref *wall_flg
 *                const coder_internal_ref_4 *search
 *                const coder_internal_ref_1 *maze_goal
 *                coder_internal_ref_3 *num_temp
 *                unsigned char *current_x
 *                unsigned char *current_y
 *                unsigned char *current_dir
 *                unsigned char maze_row_size
 *                unsigned char maze_col_size
 *                unsigned char maze_wall[1024]
 *                unsigned char maze_wall_search[1024]
 *                const unsigned char exploration_goal[18]
 *                unsigned char l_goal_size
 *                unsigned char *start_flg
 *                unsigned char goal_after_flg
 *                unsigned short contour_map[1024]
 * Return Type  : void
 */
static void search_adachi(const coder_internal_ref_5 *wall, coder_internal_ref
  *wall_flg, const coder_internal_ref_4 *search, const coder_internal_ref_1
  *maze_goal, coder_internal_ref_3 *num_temp, unsigned char *current_x, unsigned
  char *current_y, unsigned char *current_dir, unsigned char maze_row_size,
  unsigned char maze_col_size, unsigned char maze_wall[1024], unsigned char
  maze_wall_search[1024], const unsigned char exploration_goal[18], unsigned
  char l_goal_size, unsigned char *start_flg, unsigned char goal_after_flg,
  unsigned short contour_map[1024])
{
  unsigned char goal_flg;
  int i277;
  int exitg1;
  int i;
  unsigned char next_dir;
  unsigned int qY;

  /*  search_adachi �����@�ł̒T�� */
  /* local�ϐ��錾 */
  goal_flg = 0U;

  /* �S�[������t���O */
  /*      search_start_x = current_x %�T���J�n��x */
  /*      search_start_y = current_y %�T���J�n��y */
  i277 = l_goal_size;
  do {
    exitg1 = 0;

    /* �Ǐ��擾 */
    /* �S�[������͕Ǐ����X�V���Ȃ� */
    if (goal_after_flg != 1) {
      wall_set(wall, wall_flg, search, maze_goal, maze_row_size, maze_col_size, *
               current_x, *current_y, *current_dir, maze_wall, maze_wall_search);
    } else {
      /* �S�[������̂Ƃ� */
      goal_after_flg = 0U;

      /* �S�[������t���O���N���A */
    }

    /*  ������MAP���� */
    /*  [contour_map,max_length] = make_map2(maze_row_size,maze_col_size,maze_goal,maze_wall); */
    make_map_find(num_temp, wall, exploration_goal, l_goal_size, maze_wall,
                  contour_map);

    /* ���݈ʒu���S�[�������� */
    for (i = 0; i < i277; i++) {
      if ((*current_x == exploration_goal[i]) && (*current_y ==
           exploration_goal[i + 9])) {
        goal_flg = 1U;
      }
    }

    /* �S�[�������� */
    if (goal_flg == 1) {
      exitg1 = 1;
    } else {
      /*  �i�s�����I�� */
      /* �D�揇�ʁ@�k�˓��˓�ː� */
      next_dir = get_nextdir2(*current_x, *current_y, maze_wall, contour_map);

      /*  ���ݕ����Ɛi�s�����ɉ��������� */
      i = (int)(4U + next_dir);
      if ((unsigned int)i > 255U) {
        i = 255;
      }

      qY = (unsigned int)i - *current_dir;
      if (qY > (unsigned int)i) {
        qY = 0U;
      }

      next_dir = b_rem((unsigned char)qY);
      if (l_direction.front == next_dir) {
        i = 0;
      } else if (l_direction.right == next_dir) {
        i = 1;
      } else if (l_direction.back == next_dir) {
        i = 2;
      } else if (l_direction.left == next_dir) {
        i = 3;
      } else {
        i = -1;
      }

      switch (i) {
       case 0:
        move_step(current_x, current_y, *current_dir);

        /* disp("front") */
        m_move_front(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;

       case 1:
        turn_clk_90deg(current_dir);
        move_step(current_x, current_y, *current_dir);

        /* disp("right") */
        m_move_right(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;

       case 2:
        turn_180deg(current_dir);
        move_step(current_x, current_y, *current_dir);

        /* disp("back") */
        m_move_back(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;

       case 3:
        turn_conclk_90deg(current_dir);
        move_step(current_x, current_y, *current_dir);

        /* disp("left") */
        m_move_left(*start_flg, wall_flg->contents, move_dir_property.straight);

        /* �X�^�[�g����t���O���N���A */
        *start_flg = 0U;

        /* �ǃt���O���N���A */
        wall_flg->contents = 0U;
        break;
      }

      /* for code generation */
    }
  } while (exitg1 == 0);

  /* �S�[������~�t���O�������Ă���Ƃ� */
  /* ��~��������{ */
  m_goal_movement(*start_flg, wall_flg->contents, move_dir_property.straight);

  /* �S�[������~�t���O�������Ă��Ȃ���΁A���삳�����܂܏I�� */
  /*           */
  /*      if coder.target('MATLAB') */
  /*          %for MATLAB     */
  /*          %�T���I����,�}�[�J�[���ǂ��������� */
  /*          %m = makehgtform('translate',50*9,50*9,0); */
  /*          %h.Matrix = m; */
  /*          %�ʂ̎�ނ̃}�[�J�[�����u�� */
  /*          hold on */
  /*          plot(current_x * 9 -4.5,current_y * 9 -4.5,'-ob'); */
  /*          hold off */
  /*          %�T���󋵃v���b�g�𓧖��� */
  /*          serface_transparency(search_surf); */
  /*          drawnow */
  /*      else */
  /*          %for code generation */
  /*      end */
}

/*
 * ���� ���ݕ���
 * �o�� ���ݕ���
 * Arguments    : unsigned char *current_dir
 * Return Type  : void
 */
static void turn_180deg(unsigned char *current_dir)
{
  int i279;

  /*  turn_180deg 180�x�^�[������֐� */
  i279 = (int)(4U + *current_dir);
  if ((unsigned int)i279 > 255U) {
    i279 = 255;
  }

  *current_dir = (unsigned char)((i279 - 2) % 4);
}

/*
 * ���� ���ݕ���
 * �o�� ���ݕ���
 * Arguments    : unsigned char *current_dir
 * Return Type  : void
 */
static void turn_clk_90deg(unsigned char *current_dir)
{
  int i278;

  /*  turn_clk_90deg ���v�����90�x�^�[������֐�  */
  i278 = (int)(4U + *current_dir);
  if ((unsigned int)i278 > 255U) {
    i278 = 255;
  }

  i278++;
  if ((unsigned int)i278 > 255U) {
    i278 = 255;
  }

  *current_dir = (unsigned char)(i278 % 4);
}

/*
 * ���́@���ݕ���
 * �o�́@���ݕ���
 * Arguments    : unsigned char *current_dir
 * Return Type  : void
 */
static void turn_conclk_90deg(unsigned char *current_dir)
{
  int i280;

  /*  turn_conclk_90deg �����v�����90�x���֐�  */
  i280 = (int)(4U + *current_dir);
  if ((unsigned int)i280 > 255U) {
    i280 = 255;
  }

  *current_dir = (unsigned char)((i280 - 1) % 4);
}

/*
 * ���i�p�^�[���̎�
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 * Return Type  : void
 */
static void turn_l_135(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode)
{
  unsigned char u17;
  int q0;
  unsigned int qY;

  /*  ��135�x */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u17 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      qY = u17 - 1U;
      if (qY > u17) {
        qY = 0U;
      }

      current_node[1] = (unsigned char)qY;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.South_West;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.East) {
      u17 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      q0 = (int)(u17 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.North_West;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.South) {
      u17 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 1U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      q0 = (int)(u17 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.North_East;
      *current_move_mode = move_dir_property.diagonal;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u17 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        qY = u17 - 1U;
        if (qY > u17) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.South_East;
        *current_move_mode = move_dir_property.diagonal;
      }
    }

    /* �΂߃p�^�[���̎�  */
  } else {
    if (*current_move_mode == move_dir_property.diagonal) {
      if (*current_move_dir == g_d_direction.North_East) {
        u17 = current_node[1];
        q0 = (int)(current_node[0] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[0] = (unsigned char)q0;
        current_node[1] = u17;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.West;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_East) {
        q0 = (int)(current_node[1] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[1] = (unsigned char)q0;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.North;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_West) {
        u17 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        current_node[1] = u17;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.East;
        *current_move_mode = move_dir_property.straight;
      } else {
        if (*current_move_dir == g_d_direction.North_West) {
          u17 = current_node[1];
          qY = u17 - 1U;
          if (qY > u17) {
            qY = 0U;
          }

          current_node[1] = (unsigned char)qY;
          *current_node_property = matrix_dir.Row;
          *current_move_dir = g_d_direction.South;
          *current_move_mode = move_dir_property.straight;
        }
      }
    }
  }
}

/*
 * ���i�p�^�[���̎�
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 * Return Type  : void
 */
static void turn_l_180(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode)
{
  unsigned char u18;
  int q0;
  unsigned int qY;

  /*  ��180�x */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u18 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      qY = u18 - 1U;
      if (qY > u18) {
        qY = 0U;
      }

      current_node[1] = (unsigned char)qY;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.South;
      *current_move_mode = move_dir_property.straight;
    } else if (*current_move_dir == g_d_direction.East) {
      u18 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      q0 = (int)(u18 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.West;
      *current_move_mode = move_dir_property.straight;
    } else if (*current_move_dir == g_d_direction.South) {
      u18 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 1U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      q0 = (int)(u18 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.North;
      *current_move_mode = move_dir_property.straight;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u18 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        qY = u18 - 1U;
        if (qY > u18) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.East;
        *current_move_mode = move_dir_property.straight;
      }
    }

    /* �΂߃p�^�[���̎�  */
  }
}

/*
 * ���i�p�^�[���̎�
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 * Return Type  : void
 */
static void turn_l_45(unsigned char current_node[2], unsigned char
                      *current_node_property, unsigned char *current_move_dir,
                      unsigned char *current_move_mode)
{
  unsigned char u14;
  int q0;
  unsigned int qY;

  /*  ��45�x */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u14 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      current_node[1] = u14;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.North_West;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.East) {
      u14 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      q0 = (int)(u14 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.North_East;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.South) {
      u14 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 2U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      q0 = (int)(u14 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.South_East;
      *current_move_mode = move_dir_property.diagonal;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u14 = current_node[1];
        qY = u14 - 2U;
        if (qY > u14) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.South_West;
        *current_move_mode = move_dir_property.diagonal;
      }
    }
  } else {
    if (*current_move_mode == move_dir_property.diagonal) {
      if (*current_move_dir == g_d_direction.North_East) {
        u14 = current_node[1];
        q0 = (int)(current_node[0] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[0] = (unsigned char)q0;
        current_node[1] = u14;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.North;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_East) {
        u14 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        q0 = (int)(u14 + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[1] = (unsigned char)q0;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.East;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_West) {
        u14 = current_node[1];
        qY = u14 - 1U;
        if (qY > u14) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.South;
        *current_move_mode = move_dir_property.straight;
      } else {
        if (*current_move_dir == g_d_direction.North_West) {
          *current_node_property = matrix_dir.Col;
          *current_move_dir = g_d_direction.West;
          *current_move_mode = move_dir_property.straight;
        }
      }
    }
  }
}

/*
 * ���i�p�^�[���̎�
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 * Return Type  : void
 */
static void turn_l_90(unsigned char current_node[2], unsigned char
                      *current_node_property, unsigned char *current_move_dir,
                      unsigned char *current_move_mode)
{
  unsigned char u15;
  int q0;
  unsigned int qY;

  /*  ��90�x */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u15 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      current_node[1] = u15;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.West;
      *current_move_mode = move_dir_property.straight;
    } else if (*current_move_dir == g_d_direction.East) {
      u15 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      q0 = (int)(u15 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.North;
      *current_move_mode = move_dir_property.straight;
    } else if (*current_move_dir == g_d_direction.South) {
      u15 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 2U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      q0 = (int)(u15 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.East;
      *current_move_mode = move_dir_property.straight;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u15 = current_node[1];
        qY = u15 - 2U;
        if (qY > u15) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.South;
        *current_move_mode = move_dir_property.straight;
      }
    }

    /* �΂߃p�^�[���̎��iV90�j     */
  } else {
    if (*current_move_mode == move_dir_property.diagonal) {
      if (*current_move_dir == g_d_direction.North_East) {
        u15 = current_node[1];
        q0 = (int)(current_node[0] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[0] = (unsigned char)q0;
        current_node[1] = u15;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.North_West;
        *current_move_mode = move_dir_property.diagonal;
      } else if (*current_move_dir == g_d_direction.South_East) {
        q0 = (int)(current_node[1] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[1] = (unsigned char)q0;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.North_East;
        *current_move_mode = move_dir_property.diagonal;
      } else if (*current_move_dir == g_d_direction.South_West) {
        u15 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        current_node[1] = u15;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.South_East;
        *current_move_mode = move_dir_property.diagonal;
      } else {
        if (*current_move_dir == g_d_direction.North_West) {
          u15 = current_node[1];
          qY = u15 - 1U;
          if (qY > u15) {
            qY = 0U;
          }

          current_node[1] = (unsigned char)qY;
          *current_node_property = matrix_dir.Row;
          *current_move_dir = g_d_direction.South_West;
          *current_move_mode = move_dir_property.diagonal;
        }
      }
    }
  }
}

/*
 * ���i�p�^�[���̎�
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 * Return Type  : void
 */
static void turn_r_135(unsigned char current_node[2], unsigned char
  *current_node_property, unsigned char *current_move_dir, unsigned char
  *current_move_mode)
{
  unsigned char u16;
  int q0;
  unsigned int qY;

  /*  �E135�x */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u16 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      q0 = (int)(u16 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.South_East;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.East) {
      u16 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 1U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      q0 = (int)(u16 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.South_West;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.South) {
      u16 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 1U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      qY = u16 - 1U;
      if (qY > u16) {
        qY = 0U;
      }

      current_node[1] = (unsigned char)qY;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.North_West;
      *current_move_mode = move_dir_property.diagonal;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u16 = current_node[1];
        q0 = (int)(current_node[0] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[0] = (unsigned char)q0;
        qY = u16 - 1U;
        if (qY > u16) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.North_East;
        *current_move_mode = move_dir_property.diagonal;
      }
    }

    /* �΂߃p�^�[���̎�     */
  } else {
    if (*current_move_mode == move_dir_property.diagonal) {
      if (*current_move_dir == g_d_direction.North_East) {
        q0 = (int)(current_node[1] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[1] = (unsigned char)q0;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.South;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_East) {
        u16 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        current_node[1] = u16;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.West;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_West) {
        u16 = current_node[1];
        qY = u16 - 1U;
        if (qY > u16) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.North;
        *current_move_mode = move_dir_property.straight;
      } else {
        if (*current_move_dir == g_d_direction.North_West) {
          u16 = current_node[1];
          q0 = (int)(current_node[0] + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          current_node[0] = (unsigned char)q0;
          current_node[1] = u16;
          *current_node_property = matrix_dir.Col;
          *current_move_dir = g_d_direction.East;
          *current_move_mode = move_dir_property.straight;
        }
      }
    }
  }
}

/*
 * ���i�p�^�[���̎�
 * Arguments    : unsigned char current_node[2]
 *                unsigned char *current_node_property
 *                unsigned char *current_move_dir
 *                unsigned char *current_move_mode
 * Return Type  : void
 */
static void turn_r_45(unsigned char current_node[2], unsigned char
                      *current_node_property, unsigned char *current_move_dir,
                      unsigned char *current_move_mode)
{
  unsigned char u13;
  int q0;
  unsigned int qY;

  /*  �E45�x */
  if (*current_move_mode == move_dir_property.straight) {
    if (*current_move_dir == g_d_direction.North) {
      u13 = current_node[1];
      q0 = (int)(current_node[0] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[0] = (unsigned char)q0;
      q0 = (int)(u13 + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.North_East;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.East) {
      q0 = (int)(current_node[1] + 1U);
      if ((unsigned int)q0 > 255U) {
        q0 = 255;
      }

      current_node[1] = (unsigned char)q0;
      *current_node_property = matrix_dir.Row;
      *current_move_dir = g_d_direction.South_East;
      *current_move_mode = move_dir_property.diagonal;
    } else if (*current_move_dir == g_d_direction.South) {
      u13 = current_node[1];
      q0 = current_node[0];
      qY = q0 - 2U;
      if (qY > (unsigned int)q0) {
        qY = 0U;
      }

      current_node[0] = (unsigned char)qY;
      current_node[1] = u13;
      *current_node_property = matrix_dir.Col;
      *current_move_dir = g_d_direction.South_West;
      *current_move_mode = move_dir_property.diagonal;
    } else {
      if (*current_move_dir == g_d_direction.West) {
        u13 = current_node[1];
        q0 = (int)(current_node[0] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[0] = (unsigned char)q0;
        qY = u13 - 2U;
        if (qY > u13) {
          qY = 0U;
        }

        current_node[1] = (unsigned char)qY;
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.North_West;
        *current_move_mode = move_dir_property.diagonal;
      }
    }
  } else {
    if (*current_move_mode == move_dir_property.diagonal) {
      if (*current_move_dir == g_d_direction.North_East) {
        q0 = (int)(current_node[1] + 1U);
        if ((unsigned int)q0 > 255U) {
          q0 = 255;
        }

        current_node[1] = (unsigned char)q0;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.East;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_East) {
        *current_node_property = matrix_dir.Row;
        *current_move_dir = g_d_direction.South;
        *current_move_mode = move_dir_property.straight;
      } else if (*current_move_dir == g_d_direction.South_West) {
        u13 = current_node[1];
        q0 = current_node[0];
        qY = q0 - 1U;
        if (qY > (unsigned int)q0) {
          qY = 0U;
        }

        current_node[0] = (unsigned char)qY;
        current_node[1] = u13;
        *current_node_property = matrix_dir.Col;
        *current_move_dir = g_d_direction.West;
        *current_move_mode = move_dir_property.straight;
      } else {
        if (*current_move_dir == g_d_direction.North_West) {
          u13 = current_node[1];
          q0 = (int)(current_node[0] + 1U);
          if ((unsigned int)q0 > 255U) {
            q0 = 255;
          }

          current_node[0] = (unsigned char)q0;
          qY = u13 - 1U;
          if (qY > u13) {
            qY = 0U;
          }

          current_node[1] = (unsigned char)qY;
          *current_node_property = matrix_dir.Row;
          *current_move_dir = g_d_direction.North;
          *current_move_mode = move_dir_property.straight;
        }
      }
    }
  }
}

/*
 * matlab��ł͉摜����擾�����Ǐ����Q�Ƃ���B
 * ����:�摜���瓾�����H���,���H�s�����ǖ���,���H������ǖ���,
 *      ���ݒn���Wx,y,���ݐi�s����,���H�Ǐ��,���H�ǒT�����
 * �o��:���H�Ǐ��,���H�ǒT�����
 * Arguments    : const coder_internal_ref_5 *wall
 *                coder_internal_ref *wall_flg
 *                const coder_internal_ref_4 *search
 *                const coder_internal_ref_1 *maze_goal
 *                unsigned char maze_row_size
 *                unsigned char maze_col_size
 *                unsigned char current_x
 *                unsigned char current_y
 *                unsigned char current_dir
 *                unsigned char maze_wall[1024]
 *                unsigned char maze_wall_search[1024]
 * Return Type  : void
 */
static void wall_set(const coder_internal_ref_5 *wall, coder_internal_ref
                     *wall_flg, const coder_internal_ref_4 *search, const
                     coder_internal_ref_1 *maze_goal, unsigned char
                     maze_row_size, unsigned char maze_col_size, unsigned char
                     current_x, unsigned char current_y, unsigned char
                     current_dir, unsigned char maze_wall[1024], unsigned char
                     maze_wall_search[1024])
{
  unsigned char wall_write[4];
  unsigned char serch_write[4];
  short wall_sensor_front;
  int i184;
  unsigned char a;
  int i;
  int i185;
  int i186;
  int i187;
  int i188;
  int k;
  int i189;
  int i190;
  int i191;
  int i192;
  int i193;
  int i194;
  int i195;
  int i196;
  unsigned int qY;
  int i197;
  int i198;
  int i199;
  int i200;
  bool tempx[9];
  int i201;
  bool tempy[9];
  signed char varargin_1[9];
  int i202;
  int i203;
  int i204;
  int i205;
  int i206;
  int i207;
  int i208;
  int i209;
  int i210;
  int i211;
  int i212;
  int i213;
  int i214;
  int i215;
  int i216;
  int i217;
  int i218;
  int i219;
  int i220;
  int i221;
  int i222;
  int i223;
  int i224;
  int i225;
  int i226;
  int i227;
  int i228;
  int i229;
  int i230;
  int i231;
  int i232;
  int i233;
  int i234;
  int i235;
  int i236;
  int i237;
  int i238;
  int i239;
  int i240;
  int i241;
  int i242;
  int i243;
  int i244;
  int i245;
  int i246;
  int i247;
  int i248;
  int i249;
  int i250;
  int i251;
  int i252;
  int i253;
  int i254;
  int i255;
  int i256;
  int i257;
  int i258;
  int i259;
  int i260;
  int i261;
  int i262;
  int i263;
  int i264;
  int i265;
  int i266;
  int i267;
  int i268;
  int i269;
  int i270;
  int i271;
  int i272;
  int i273;
  int i274;
  int i275;
  int i276;

  /*   wall_set �Ǐ��擾 */
  /* �O���[�o���ϐ�(matlab�ł͖��H�f�[�^���AC�ł͕ǃZ���T�l���Q��) */
  /* for matlab */
  /* for C gen */
  /* �ǃZ���T臒l */
  /* ���[�J���ϐ��錾 */
  /* �Ǐ�񏑂����ݗp�o�b�t�@(N,E,S,W) */
  wall_write[0] = 0U;
  serch_write[0] = 0U;
  wall_write[1] = 0U;
  serch_write[1] = 0U;
  wall_write[2] = 0U;
  serch_write[2] = 0U;
  wall_write[3] = 0U;
  serch_write[3] = 0U;

  /* �T����񏑂����ݗp�o�b�t�@(N,E,S,W) */
  /* �ǃZ���TAD�l�i�[�ϐ� */
  /* �}�E�X�̕����Ɋ�Â��Ǐ��擾 */
  /* �}�E�X�̕����Ɛ�Ε����̍�=�}�E�X�̕����ƂȂ邱�Ƃ𗘗p���A */
  /* ��Ίp�x�Ɛ������Ƃ�B */
  /* �O���̕ǔ��� */
  /* for Cgen */
  /* �Z���T�l�擾 */
  wall_sensor_front = m_get_front_sensor();

  /* �Z���T�l�����ƂɁA�ǂ̗L���𔻒� */
  if (wall_sensor_front > wall_sensor_front_th) {
    /* �Ǐ��擾 */
    i184 = (int)(b_rem(current_dir) + 1U);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    wall_write[i184 - 1] = wall->contents.wall;

    /* �ǃt���O�Z�b�g */
    a = wall_flg->contents;
    wall_flg->contents = (unsigned char)(a | 1);
  }

  /* �T������X�V */
  i184 = (int)(b_rem(current_dir) + 1U);
  if ((unsigned int)i184 > 255U) {
    i184 = 255;
  }

  serch_write[i184 - 1] = search->contents.known;

  /* �E�ǔ��� */
  /* for Cgen */
  /* �Z���T�l�擾 */
  wall_sensor_front = m_get_right_sensor();

  /* �Z���T�l�����ƂɁA�ǂ̗L���𔻒� */
  if (wall_sensor_front > wall_sensor_right_th) {
    /* �Ǐ��擾 */
    i184 = (int)(current_dir + 1U);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    i184 = (int)(b_rem((unsigned char)i184) + 1U);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    wall_write[i184 - 1] = wall->contents.wall;

    /* �ǃt���O�Z�b�g */
    a = wall_flg->contents;
    wall_flg->contents = (unsigned char)(a | 2);
  }

  /* �T������X�V */
  i184 = (int)(current_dir + 1U);
  if ((unsigned int)i184 > 255U) {
    i184 = 255;
  }

  i184 = (int)(b_rem((unsigned char)i184) + 1U);
  if ((unsigned int)i184 > 255U) {
    i184 = 255;
  }

  serch_write[i184 - 1] = search->contents.known;

  /* ����͏��𓾂邱�Ƃ��ł��Ȃ��̂ŏ������Ȃ��B */
  /* ���ǔ��� */
  /* for Cgen */
  /* �Z���T�l�擾 */
  wall_sensor_front = m_get_left_sensor();

  /* �Z���T�l�����ƂɁA�ǂ̗L���𔻒� */
  if (wall_sensor_front > wall_sensor_left_th) {
    /* �Ǐ��擾 */
    i184 = (int)(current_dir + 3U);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    i184 = (int)(b_rem((unsigned char)i184) + 1U);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    wall_write[i184 - 1] = wall->contents.wall;

    /* �ǃt���O�Z�b�g */
    a = wall_flg->contents;
    wall_flg->contents = (unsigned char)(a | 8);
  }

  /* �T������X�V */
  i184 = (int)(current_dir + 3U);
  if ((unsigned int)i184 > 255U) {
    i184 = 255;
  }

  i184 = (int)(b_rem((unsigned char)i184) + 1U);
  if ((unsigned int)i184 > 255U) {
    i184 = 255;
  }

  serch_write[i184 - 1] = search->contents.known;

  /* �����܂� */
  /* �Ǐ��,�T��������� */
  /* �k�� */
  i184 = (int)(g_direction.North + 1U);
  i = i184;
  if ((unsigned int)i184 > 255U) {
    i = 255;
  }

  if (g_direction.North <= 7) {
    i185 = (unsigned char)(1 << g_direction.North);
  } else {
    i185 = 0;
  }

  i = (int)((unsigned int)i185 * wall_write[i - 1]);
  if ((unsigned int)i > 255U) {
    i = 255;
  }

  i186 = current_y + ((current_x - 1) << 5);
  i187 = i186 - 1;
  maze_wall[i187] = (unsigned char)(maze_wall[i187] | i);
  i = i184;
  if ((unsigned int)i184 > 255U) {
    i = 255;
  }

  if (g_direction.North <= 7) {
    i188 = (unsigned char)(1 << g_direction.North);
  } else {
    i188 = 0;
  }

  i = (int)((unsigned int)i188 * serch_write[i - 1]);
  if ((unsigned int)i > 255U) {
    i = 255;
  }

  maze_wall_search[i187] = (unsigned char)(maze_wall_search[i187] | i);

  /* ���� */
  i = (int)(g_direction.East + 1U);
  k = i;
  if ((unsigned int)i > 255U) {
    k = 255;
  }

  if (g_direction.East <= 7) {
    i189 = (unsigned char)(1 << g_direction.East);
  } else {
    i189 = 0;
  }

  k = (int)((unsigned int)i189 * wall_write[k - 1]);
  if ((unsigned int)k > 255U) {
    k = 255;
  }

  maze_wall[i187] = (unsigned char)(maze_wall[i187] | k);
  k = i;
  if ((unsigned int)i > 255U) {
    k = 255;
  }

  if (g_direction.East <= 7) {
    i190 = (unsigned char)(1 << g_direction.East);
  } else {
    i190 = 0;
  }

  k = (int)((unsigned int)i190 * serch_write[k - 1]);
  if ((unsigned int)k > 255U) {
    k = 255;
  }

  maze_wall_search[i187] = (unsigned char)(maze_wall_search[i187] | k);

  /* �쑤 */
  k = (int)(g_direction.South + 1U);
  i191 = k;
  if ((unsigned int)k > 255U) {
    i191 = 255;
  }

  if (g_direction.South <= 7) {
    i192 = (unsigned char)(1 << g_direction.South);
  } else {
    i192 = 0;
  }

  i191 = (int)((unsigned int)i192 * wall_write[i191 - 1]);
  if ((unsigned int)i191 > 255U) {
    i191 = 255;
  }

  maze_wall[i187] = (unsigned char)(maze_wall[i187] | i191);
  i191 = k;
  if ((unsigned int)k > 255U) {
    i191 = 255;
  }

  if (g_direction.South <= 7) {
    i193 = (unsigned char)(1 << g_direction.South);
  } else {
    i193 = 0;
  }

  i191 = (int)((unsigned int)i193 * serch_write[i191 - 1]);
  if ((unsigned int)i191 > 255U) {
    i191 = 255;
  }

  maze_wall_search[i187] = (unsigned char)(maze_wall_search[i187] | i191);

  /* ���� */
  i191 = (int)(g_direction.West + 1U);
  i194 = i191;
  if ((unsigned int)i191 > 255U) {
    i194 = 255;
  }

  if (g_direction.West <= 7) {
    i195 = (unsigned char)(1 << g_direction.West);
  } else {
    i195 = 0;
  }

  i194 = (int)((unsigned int)i195 * wall_write[i194 - 1]);
  if ((unsigned int)i194 > 255U) {
    i194 = 255;
  }

  maze_wall[i187] = (unsigned char)(maze_wall[i187] | i194);
  i194 = i191;
  if ((unsigned int)i191 > 255U) {
    i194 = 255;
  }

  if (g_direction.West <= 7) {
    i196 = (unsigned char)(1 << g_direction.West);
  } else {
    i196 = 0;
  }

  i194 = (int)((unsigned int)i196 * serch_write[i194 - 1]);
  if ((unsigned int)i194 > 255U) {
    i194 = 255;
  }

  maze_wall_search[i187] = (unsigned char)(maze_wall_search[i187] | i194);

  /* �ׂ荇���}�X�̏��ɂ����� */
  /* �k���̃}�X�̓쑤�̕Ǐ�� */
  qY = maze_row_size - 1U;
  if (qY > maze_row_size) {
    qY = 0U;
  }

  if (current_y < (int)qY) {
    i194 = i184;
    if ((unsigned int)i184 > 255U) {
      i194 = 255;
    }

    if (g_direction.South <= 7) {
      i197 = (unsigned char)(1 << g_direction.South);
    } else {
      i197 = 0;
    }

    i194 = (int)((unsigned int)i197 * wall_write[i194 - 1]);
    if ((unsigned int)i194 > 255U) {
      i194 = 255;
    }

    maze_wall[i186] = (unsigned char)(maze_wall[i186] | i194);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    if (g_direction.South <= 7) {
      i200 = (unsigned char)(1 << g_direction.South);
    } else {
      i200 = 0;
    }

    i184 = (int)((unsigned int)i200 * serch_write[i184 - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    maze_wall_search[i186] = (unsigned char)(maze_wall_search[i186] | i184);
  }

  /* �����̃}�X�̐����̕Ǐ�� */
  qY = maze_col_size - 1U;
  if (qY > maze_col_size) {
    qY = 0U;
  }

  if (current_x < (int)qY) {
    i184 = i;
    if ((unsigned int)i > 255U) {
      i184 = 255;
    }

    if (g_direction.West <= 7) {
      i198 = (unsigned char)(1 << g_direction.West);
    } else {
      i198 = 0;
    }

    i184 = (int)((unsigned int)i198 * wall_write[i184 - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    i194 = (current_y + (current_x << 5)) - 1;
    maze_wall[i194] = (unsigned char)(maze_wall[i194] | i184);
    if ((unsigned int)i > 255U) {
      i = 255;
    }

    if (g_direction.West <= 7) {
      i202 = (unsigned char)(1 << g_direction.West);
    } else {
      i202 = 0;
    }

    i184 = (int)((unsigned int)i202 * serch_write[i - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    maze_wall_search[i194] = (unsigned char)(maze_wall_search[i194] | i184);
  }

  /* �쑤�̃}�X�̖k���̕Ǐ�� */
  if (current_y > 1) {
    i184 = k;
    if ((unsigned int)k > 255U) {
      i184 = 255;
    }

    if (g_direction.North <= 7) {
      i199 = (unsigned char)(1 << g_direction.North);
    } else {
      i199 = 0;
    }

    i184 = (int)((unsigned int)i199 * wall_write[i184 - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    i = i186 - 2;
    maze_wall[i] = (unsigned char)(maze_wall[i] | i184);
    if ((unsigned int)k > 255U) {
      k = 255;
    }

    if (g_direction.North <= 7) {
      i203 = (unsigned char)(1 << g_direction.North);
    } else {
      i203 = 0;
    }

    i184 = (int)((unsigned int)i203 * serch_write[k - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    maze_wall_search[i] = (unsigned char)(maze_wall_search[i] | i184);
  }

  /* �����̃}�X�̓����̕Ǐ�� */
  if (current_x > 1) {
    i184 = i191;
    if ((unsigned int)i191 > 255U) {
      i184 = 255;
    }

    if (g_direction.East <= 7) {
      i201 = (unsigned char)(1 << g_direction.East);
    } else {
      i201 = 0;
    }

    i184 = (int)((unsigned int)i201 * wall_write[i184 - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    i = (current_y + ((current_x - 2) << 5)) - 1;
    maze_wall[i] = (unsigned char)(maze_wall[i] | i184);
    if ((unsigned int)i191 > 255U) {
      i191 = 255;
    }

    if (g_direction.East <= 7) {
      i204 = (unsigned char)(1 << g_direction.East);
    } else {
      i204 = 0;
    }

    i184 = (int)((unsigned int)i204 * serch_write[i191 - 1]);
    if ((unsigned int)i184 > 255U) {
      i184 = 255;
    }

    maze_wall_search[i] = (unsigned char)(maze_wall_search[i] | i184);
  }

  /* ���ݒn���S�[���łȂ��ꍇ */
  for (i184 = 0; i184 < 9; i184++) {
    tempx[i184] = (maze_goal->contents[i184] == current_x);
  }

  for (i184 = 0; i184 < 9; i184++) {
    tempy[i184] = (maze_goal->contents[9 + i184] == current_y);
  }

  for (i = 0; i < 9; i++) {
    varargin_1[i] = (signed char)(tempx[i] * tempy[i]);
  }

  i = varargin_1[0];
  for (k = 0; k < 8; k++) {
    i184 = varargin_1[k + 1];
    if (i < i184) {
      i = i184;
    }
  }

  if (i == 0) {
    /* ���ɑ΂��A3�����T���ς݂��A���ׂĕǂ��Ȃ��ꍇ�A����������̕ǂ��m�肳����B */
    /* �k,���ɕǂ��Ȃ��ꍇ */
    if (g_direction.North <= 7) {
      i205 = (unsigned char)(1 << g_direction.North);
    } else {
      i205 = 0;
    }

    if (g_direction.North <= 7) {
      i206 = (unsigned char)(1 << g_direction.North);
    } else {
      i206 = 0;
    }

    if ((maze_wall[i187] & i205) != i206) {
      if (g_direction.East <= 7) {
        i207 = (unsigned char)(1 << g_direction.East);
      } else {
        i207 = 0;
      }

      if (g_direction.East <= 7) {
        i209 = (unsigned char)(1 << g_direction.East);
      } else {
        i209 = 0;
      }

      if ((maze_wall[(current_y + ((current_x - 1) << 5)) - 1] & i207) != i209)
      {
        /* �k�̃}�X�̓����T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.East <= 7) {
          i211 = (unsigned char)(1 << g_direction.East);
        } else {
          i211 = 0;
        }

        if ((maze_wall_search[i186] & i211) != 0) {
          if (g_direction.East <= 7) {
            i215 = (unsigned char)(1 << g_direction.East);
          } else {
            i215 = 0;
          }

          if (g_direction.East <= 7) {
            i218 = (unsigned char)(1 << g_direction.East);
          } else {
            i218 = 0;
          }

          if ((maze_wall[i186] & i215) != i218) {
            /* ���̃}�X�̖k�̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.North <= 7) {
              i223 = (unsigned char)(1 << g_direction.North);
            } else {
              i223 = 0;
            }

            maze_wall[(current_y + (current_x << 5)) - 1] = (unsigned char)
              (maze_wall[(current_y + (current_x << 5)) - 1] | i223);
            if (g_direction.North <= 7) {
              i230 = (unsigned char)(1 << g_direction.North);
            } else {
              i230 = 0;
            }

            maze_wall_search[(current_y + (current_x << 5)) - 1] = (unsigned
              char)(maze_wall_search[(current_y + (current_x << 5)) - 1] | i230);

            /* �ׂ荇���}�X�i���k�}�X�j�̓�̕ǂ��m�� */
            if (g_direction.South <= 7) {
              i236 = (unsigned char)(1 << g_direction.South);
            } else {
              i236 = 0;
            }

            maze_wall[current_y + (current_x << 5)] = (unsigned char)
              (maze_wall[current_y + (current_x << 5)] | i236);
            if (g_direction.South <= 7) {
              i244 = (unsigned char)(1 << g_direction.South);
            } else {
              i244 = 0;
            }

            maze_wall_search[current_y + (current_x << 5)] = (unsigned char)
              (maze_wall_search[current_y + (current_x << 5)] | i244);
          }
        }

        /* ���̃}�X�̖k���T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.North <= 7) {
          i217 = (unsigned char)(1 << g_direction.North);
        } else {
          i217 = 0;
        }

        if ((maze_wall_search[(current_y + (current_x << 5)) - 1] & i217) != 0)
        {
          if (g_direction.North <= 7) {
            i221 = (unsigned char)(1 << g_direction.North);
          } else {
            i221 = 0;
          }

          if (g_direction.North <= 7) {
            i226 = (unsigned char)(1 << g_direction.North);
          } else {
            i226 = 0;
          }

          if ((maze_wall[(current_y + (current_x << 5)) - 1] & i221) != i226) {
            /* �k�̃}�X�̓��̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.East <= 7) {
              i232 = (unsigned char)(1 << g_direction.East);
            } else {
              i232 = 0;
            }

            maze_wall[i186] = (unsigned char)(maze_wall[i186] | i232);
            if (g_direction.East <= 7) {
              i240 = (unsigned char)(1 << g_direction.East);
            } else {
              i240 = 0;
            }

            maze_wall_search[i186] = (unsigned char)(maze_wall_search[i186] |
              i240);

            /* �ׂ荇���}�X�i���k�}�X�j�̐��̕ǂ��m�� */
            if (g_direction.West <= 7) {
              i247 = (unsigned char)(1 << g_direction.West);
            } else {
              i247 = 0;
            }

            maze_wall[current_y + (current_x << 5)] = (unsigned char)
              (maze_wall[current_y + (current_x << 5)] | i247);
            if (g_direction.West <= 7) {
              i254 = (unsigned char)(1 << g_direction.West);
            } else {
              i254 = 0;
            }

            maze_wall_search[current_y + (current_x << 5)] = (unsigned char)
              (maze_wall_search[current_y + (current_x << 5)] | i254);
          }
        }
      }
    }

    /* �k,���ɕǂ��Ȃ��ꍇ */
    if (g_direction.North <= 7) {
      i208 = (unsigned char)(1 << g_direction.North);
    } else {
      i208 = 0;
    }

    if (g_direction.North <= 7) {
      i210 = (unsigned char)(1 << g_direction.North);
    } else {
      i210 = 0;
    }

    if ((maze_wall[(current_y + ((current_x - 1) << 5)) - 1] & i208) != i210) {
      if (g_direction.West <= 7) {
        i212 = (unsigned char)(1 << g_direction.West);
      } else {
        i212 = 0;
      }

      if (g_direction.West <= 7) {
        i214 = (unsigned char)(1 << g_direction.West);
      } else {
        i214 = 0;
      }

      if ((maze_wall[(current_y + ((current_x - 1) << 5)) - 1] & i212) != i214)
      {
        /* �k�̃}�X�̐����T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.West <= 7) {
          i219 = (unsigned char)(1 << g_direction.West);
        } else {
          i219 = 0;
        }

        if ((maze_wall_search[current_y + ((current_x - 1) << 5)] & i219) != 0)
        {
          if (g_direction.West <= 7) {
            i225 = (unsigned char)(1 << g_direction.West);
          } else {
            i225 = 0;
          }

          if (g_direction.West <= 7) {
            i229 = (unsigned char)(1 << g_direction.West);
          } else {
            i229 = 0;
          }

          if ((maze_wall[i186] & i225) != i229) {
            /* ���̃}�X�̖k�̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.North <= 7) {
              i235 = (unsigned char)(1 << g_direction.North);
            } else {
              i235 = 0;
            }

            maze_wall[(current_y + ((current_x - 2) << 5)) - 1] = (unsigned char)
              (maze_wall[(current_y + ((current_x - 2) << 5)) - 1] | i235);
            if (g_direction.North <= 7) {
              i243 = (unsigned char)(1 << g_direction.North);
            } else {
              i243 = 0;
            }

            maze_wall_search[(current_y + ((current_x - 2) << 5)) - 1] =
              (unsigned char)(maze_wall_search[(current_y + ((current_x - 2) <<
              5)) - 1] | i243);

            /* �ׂ荇���}�X�i�k���}�X�j�̓�̕ǂ��m�� */
            if (g_direction.South <= 7) {
              i250 = (unsigned char)(1 << g_direction.South);
            } else {
              i250 = 0;
            }

            maze_wall[current_y + ((current_x - 2) << 5)] = (unsigned char)
              (maze_wall[current_y + ((current_x - 2) << 5)] | i250);
            if (g_direction.South <= 7) {
              i258 = (unsigned char)(1 << g_direction.South);
            } else {
              i258 = 0;
            }

            maze_wall_search[current_y + ((current_x - 2) << 5)] = (unsigned
              char)(maze_wall_search[current_y + ((current_x - 2) << 5)] | i258);
          }
        }

        /* ���̃}�X�̖k���T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.North <= 7) {
          i228 = (unsigned char)(1 << g_direction.North);
        } else {
          i228 = 0;
        }

        if ((maze_wall_search[(current_y + ((current_x - 2) << 5)) - 1] & i228)
            != 0) {
          if (g_direction.North <= 7) {
            i234 = (unsigned char)(1 << g_direction.North);
          } else {
            i234 = 0;
          }

          if (g_direction.North <= 7) {
            i239 = (unsigned char)(1 << g_direction.North);
          } else {
            i239 = 0;
          }

          if ((maze_wall[(current_y + ((current_x - 2) << 5)) - 1] & i234) !=
              i239) {
            /* �k�̃}�X�̐��̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.West <= 7) {
              i246 = (unsigned char)(1 << g_direction.West);
            } else {
              i246 = 0;
            }

            maze_wall[i186] = (unsigned char)(maze_wall[i186] | i246);
            if (g_direction.West <= 7) {
              i253 = (unsigned char)(1 << g_direction.West);
            } else {
              i253 = 0;
            }

            maze_wall_search[i186] = (unsigned char)(maze_wall_search[i186] |
              i253);

            /* �ׂ荇���}�X�i�k���}�X�j�̓��̕ǂ��m�� */
            if (g_direction.East <= 7) {
              i260 = (unsigned char)(1 << g_direction.East);
            } else {
              i260 = 0;
            }

            maze_wall[current_y + ((current_x - 2) << 5)] = (unsigned char)
              (maze_wall[current_y + ((current_x - 2) << 5)] | i260);
            if (g_direction.East <= 7) {
              i266 = (unsigned char)(1 << g_direction.East);
            } else {
              i266 = 0;
            }

            maze_wall_search[current_y + ((current_x - 2) << 5)] = (unsigned
              char)(maze_wall_search[current_y + ((current_x - 2) << 5)] | i266);
          }
        }
      }
    }

    /* ��,���ɕǂ��Ȃ��ꍇ */
    if (g_direction.East <= 7) {
      i213 = (unsigned char)(1 << g_direction.East);
    } else {
      i213 = 0;
    }

    if (g_direction.East <= 7) {
      i216 = (unsigned char)(1 << g_direction.East);
    } else {
      i216 = 0;
    }

    if ((maze_wall[i187] & i213) != i216) {
      if (g_direction.South <= 7) {
        i220 = (unsigned char)(1 << g_direction.South);
      } else {
        i220 = 0;
      }

      if (g_direction.South <= 7) {
        i224 = (unsigned char)(1 << g_direction.South);
      } else {
        i224 = 0;
      }

      if ((maze_wall[i187] & i220) != i224) {
        /* ��̃}�X�̓����T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.East <= 7) {
          i231 = (unsigned char)(1 << g_direction.East);
        } else {
          i231 = 0;
        }

        if ((maze_wall_search[(current_y + ((current_x - 1) << 5)) - 2] & i231)
            != 0) {
          if (g_direction.East <= 7) {
            i238 = (unsigned char)(1 << g_direction.East);
          } else {
            i238 = 0;
          }

          if (g_direction.East <= 7) {
            i242 = (unsigned char)(1 << g_direction.East);
          } else {
            i242 = 0;
          }

          if ((maze_wall[(current_y + ((current_x - 1) << 5)) - 2] & i238) !=
              i242) {
            /* ���̃}�X�̓�̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.South <= 7) {
              i249 = (unsigned char)(1 << g_direction.South);
            } else {
              i249 = 0;
            }

            maze_wall[(current_y + (current_x << 5)) - 1] = (unsigned char)
              (maze_wall[(current_y + (current_x << 5)) - 1] | i249);
            if (g_direction.South <= 7) {
              i257 = (unsigned char)(1 << g_direction.South);
            } else {
              i257 = 0;
            }

            maze_wall_search[(current_y + (current_x << 5)) - 1] = (unsigned
              char)(maze_wall_search[(current_y + (current_x << 5)) - 1] | i257);

            /* �ׂ荇���}�X�i�쓌�}�X�j�̖k�̕ǂ��m�� */
            i184 = (current_y + (current_x << 5)) - 2;
            if (g_direction.North <= 7) {
              i265 = (unsigned char)(1 << g_direction.North);
            } else {
              i265 = 0;
            }

            maze_wall[i184] = (unsigned char)(maze_wall[i184] | i265);
            if (g_direction.North <= 7) {
              i268 = (unsigned char)(1 << g_direction.North);
            } else {
              i268 = 0;
            }

            maze_wall_search[i184] = (unsigned char)(maze_wall_search[i184] |
              i268);
          }
        }

        /* ���̃}�X�̓삪�T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.South <= 7) {
          i241 = (unsigned char)(1 << g_direction.South);
        } else {
          i241 = 0;
        }

        if ((maze_wall_search[(current_y + (current_x << 5)) - 1] & i241) != 0)
        {
          if (g_direction.South <= 7) {
            i248 = (unsigned char)(1 << g_direction.South);
          } else {
            i248 = 0;
          }

          if (g_direction.South <= 7) {
            i252 = (unsigned char)(1 << g_direction.South);
          } else {
            i252 = 0;
          }

          if ((maze_wall[(current_y + (current_x << 5)) - 1] & i248) != i252) {
            /* ��̃}�X�̓��̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.East <= 7) {
              i259 = (unsigned char)(1 << g_direction.East);
            } else {
              i259 = 0;
            }

            maze_wall[(current_y + ((current_x - 1) << 5)) - 2] = (unsigned char)
              (maze_wall[(current_y + ((current_x - 1) << 5)) - 2] | i259);
            if (g_direction.East <= 7) {
              i264 = (unsigned char)(1 << g_direction.East);
            } else {
              i264 = 0;
            }

            maze_wall_search[(current_y + ((current_x - 1) << 5)) - 2] =
              (unsigned char)(maze_wall_search[(current_y + ((current_x - 1) <<
              5)) - 2] | i264);

            /* �ׂ荇���}�X�i�쓌�}�X�j�̐��̕ǂ��m��B�T���ς݂Ƃ��� */
            if (g_direction.West <= 7) {
              i270 = (unsigned char)(1 << g_direction.West);
            } else {
              i270 = 0;
            }

            maze_wall[(current_y + (current_x << 5)) - 2] = (unsigned char)
              (maze_wall[(current_y + (current_x << 5)) - 2] | i270);
            if (g_direction.West <= 7) {
              i273 = (unsigned char)(1 << g_direction.West);
            } else {
              i273 = 0;
            }

            maze_wall_search[(current_y + (current_x << 5)) - 2] = (unsigned
              char)(maze_wall_search[(current_y + (current_x << 5)) - 2] | i273);
          }
        }
      }
    }

    /* ��,���ɕǂ��Ȃ��ꍇ */
    if (g_direction.West <= 7) {
      i222 = (unsigned char)(1 << g_direction.West);
    } else {
      i222 = 0;
    }

    if (g_direction.West <= 7) {
      i227 = (unsigned char)(1 << g_direction.West);
    } else {
      i227 = 0;
    }

    if ((maze_wall[i187] & i222) != i227) {
      if (g_direction.South <= 7) {
        i233 = (unsigned char)(1 << g_direction.South);
      } else {
        i233 = 0;
      }

      if (g_direction.South <= 7) {
        i237 = (unsigned char)(1 << g_direction.South);
      } else {
        i237 = 0;
      }

      if ((maze_wall[i187] & i233) != i237) {
        /* ��̃}�X�̐����T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.West <= 7) {
          i245 = (unsigned char)(1 << g_direction.West);
        } else {
          i245 = 0;
        }

        if ((maze_wall_search[(current_y + ((current_x - 1) << 5)) - 2] & i245)
            != 0) {
          if (g_direction.West <= 7) {
            i251 = (unsigned char)(1 << g_direction.West);
          } else {
            i251 = 0;
          }

          if (g_direction.West <= 7) {
            i256 = (unsigned char)(1 << g_direction.West);
          } else {
            i256 = 0;
          }

          if ((maze_wall[(current_y + ((current_x - 1) << 5)) - 2] & i251) !=
              i256) {
            /* ���̃}�X�̓�̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.South <= 7) {
              i262 = (unsigned char)(1 << g_direction.South);
            } else {
              i262 = 0;
            }

            maze_wall[(current_y + ((current_x - 2) << 5)) - 1] = (unsigned char)
              (maze_wall[(current_y + ((current_x - 2) << 5)) - 1] | i262);
            if (g_direction.South <= 7) {
              i267 = (unsigned char)(1 << g_direction.South);
            } else {
              i267 = 0;
            }

            maze_wall_search[(current_y + ((current_x - 2) << 5)) - 1] =
              (unsigned char)(maze_wall_search[(current_y + ((current_x - 2) <<
              5)) - 1] | i267);

            /* �ׂ荇���}�X�i�쐼�}�X�j�̖k�̕ǂ��m��B�T���ς݂Ƃ��� */
            i184 = (current_y + ((current_x - 2) << 5)) - 2;
            if (g_direction.North <= 7) {
              i272 = (unsigned char)(1 << g_direction.North);
            } else {
              i272 = 0;
            }

            maze_wall[i184] = (unsigned char)(maze_wall[i184] | i272);
            if (g_direction.North <= 7) {
              i274 = (unsigned char)(1 << g_direction.North);
            } else {
              i274 = 0;
            }

            maze_wall_search[i184] = (unsigned char)(maze_wall_search[i184] |
              i274);
          }
        }

        /* ���̃}�X�̓삪�T���ς݁@���@�ǂ��Ȃ��Ƃ� */
        if (g_direction.South <= 7) {
          i255 = (unsigned char)(1 << g_direction.South);
        } else {
          i255 = 0;
        }

        if ((maze_wall_search[(current_y + ((current_x - 2) << 5)) - 1] & i255)
            != 0) {
          if (g_direction.South <= 7) {
            i261 = (unsigned char)(1 << g_direction.South);
          } else {
            i261 = 0;
          }

          if (g_direction.South <= 7) {
            i263 = (unsigned char)(1 << g_direction.South);
          } else {
            i263 = 0;
          }

          if ((maze_wall[(current_y + ((current_x - 2) << 5)) - 1] & i261) !=
              i263) {
            /* ��̃}�X�̐��̕ǂ��m��A�T���ς݂Ƃ���B */
            if (g_direction.West <= 7) {
              i269 = (unsigned char)(1 << g_direction.West);
            } else {
              i269 = 0;
            }

            maze_wall[(current_y + ((current_x - 1) << 5)) - 2] = (unsigned char)
              (maze_wall[(current_y + ((current_x - 1) << 5)) - 2] | i269);
            if (g_direction.West <= 7) {
              i271 = (unsigned char)(1 << g_direction.West);
            } else {
              i271 = 0;
            }

            maze_wall_search[(current_y + ((current_x - 1) << 5)) - 2] =
              (unsigned char)(maze_wall_search[(current_y + ((current_x - 1) <<
              5)) - 2] | i271);

            /* �ׂ荇���}�X�i�쐼�}�X�j�̓��̕ǂ��m��B�T���ς݂Ƃ��� */
            if (g_direction.East <= 7) {
              i275 = (unsigned char)(1 << g_direction.East);
            } else {
              i275 = 0;
            }

            maze_wall[(current_y + ((current_x - 2) << 5)) - 2] = (unsigned char)
              (maze_wall[(current_y + ((current_x - 2) << 5)) - 2] | i275);
            if (g_direction.East <= 7) {
              i276 = (unsigned char)(1 << g_direction.East);
            } else {
              i276 = 0;
            }

            maze_wall_search[(current_y + ((current_x - 2) << 5)) - 2] =
              (unsigned char)(maze_wall_search[(current_y + ((current_x - 2) <<
              5)) - 2] | i276);
          }
        }
      }
    }
  }
}

/*
 * maze_solve ���@�ł̖��H�T���֐�
 * ���� ���H�Ǐ��,���H�T�����,���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,
 * �o�� �Ǐ��,�T�����
 * Arguments    : unsigned char maze_wall[1024]
 *                unsigned char maze_wall_search[1024]
 *                unsigned char maze_row_size
 *                unsigned char maze_col_size
 *                unsigned char goal_size
 *                const unsigned char maze_goal[18]
 *                unsigned char run_mode
 *                unsigned short contour_map[1024]
 *                unsigned short row_num_node[1056]
 *                unsigned short col_num_node[1056]
 * Return Type  : void
 */
void maze_solve(unsigned char maze_wall[1024], unsigned char maze_wall_search
                [1024], unsigned char maze_row_size, unsigned char maze_col_size,
                unsigned char goal_size, const unsigned char maze_goal[18],
                unsigned char run_mode, unsigned short contour_map[1024],
                unsigned short row_num_node[1056], unsigned short col_num_node
                [1056])
{
  coder_internal_ref b_goal_size;
  coder_internal_ref wall_flg;
  int idx;
  coder_internal_ref_1 b_maze_goal;
  unsigned char new_goal[18];
  coder_internal_ref_5 wall;
  coder_internal_ref_4 search;
  coder_internal_ref_3 num_temp;
  coder_internal_ref_2 max_length;
  unsigned char col_temp;
  unsigned short minval;
  coder_internal_ref current_x;
  coder_internal_ref current_y;
  coder_internal_ref current_dir;
  unsigned char goal_section[2];
  unsigned char search_flag;
  unsigned char b_goal_section[2];
  unsigned char goal_node2[2];
  unsigned char start_flg;
  int exitg1;
  bool exitg2;
  bool b0;
  unsigned short contour_map_temp[1024];
  unsigned short u11;
  int ii_size_idx_0;
  int ii;
  short ii_data[1];
  unsigned short tmp_data[1];
  b_goal_size.contents = goal_size;

  /* C����֐��C���N���[�h */
  /* ���[�J���ϐ���`  */
  /*  �S�[�����X�g�b�v�t���O(0:�ړ��p���@1:�X�g�b�v) */
  /*  �X�^�[�g�t���O(0:���쒆�@1:��~����̈ړ��J�n) */
  /* �S�[������t���O(0:�S�[������łȂ�, 1:�S�[������) */
  wall_flg.contents = 0U;

  /* �ǃt���O(1:�O�A2:�E�A�i4:���)�A8:��) */
  /*  �O���[�o���ϐ��錾 */
  /*  global maze_goal; */
  /* ���[�J���ϐ��錾 */
  for (idx = 0; idx < 18; idx++) {
    b_maze_goal.contents[idx] = maze_goal[idx];
    new_goal[idx] = 0U;
  }

  memset(&contour_map[0], 0, sizeof(unsigned short) << 10);
  for (idx = 0; idx < 1056; idx++) {
    row_num_node[idx] = MAX_uint16_T;
    col_num_node[idx] = MAX_uint16_T;
  }

  /* �m�[�h�̑�����` */
  /* 0:�s����, 1:�����,�@2:�Z�N�V�����i�}�X�j */
  matrix_dir.Row = 0U;
  matrix_dir.Col = 1U;
  matrix_dir.section = 2U;

  /* ��Ε��p��` */
  g_direction.North = 0U;
  g_direction.East = 1U;
  g_direction.South = 2U;
  g_direction.West = 3U;

  /* �΂ߍ��݂̐�Ε��p��` */
  g_d_direction.North = 0U;
  g_d_direction.North_East = 1U;
  g_d_direction.East = 2U;
  g_d_direction.South_East = 3U;
  g_d_direction.South = 4U;
  g_d_direction.South_West = 5U;
  g_d_direction.West = 6U;
  g_d_direction.North_West = 7U;

  /* �}�E�X������` */
  l_direction.front = 0U;
  l_direction.right = 1U;
  l_direction.back = 2U;
  l_direction.left = 3U;

  /* �ړ�����������` */
  /* ���ior�΂� */
  move_dir_property.straight = 0U;
  move_dir_property.diagonal = 1U;

  /* �p�^�[���ԍ���` */
  turn_pattern.b_default = 0U;
  turn_pattern.r_45 = 1U;
  turn_pattern.l_45 = 2U;
  turn_pattern.r_90 = 3U;
  turn_pattern.l_90 = 4U;
  turn_pattern.r_135 = 5U;
  turn_pattern.l_135 = 6U;
  turn_pattern.r_180 = 7U;
  turn_pattern.l_180 = 8U;

  /* �Ǐ���` */
  wall.contents.nowall = 0U;
  wall.contents.wall = 1U;

  /* �T������` */
  search.contents.unknown = 0U;
  search.contents.known = 1U;

  /* ���s���[�h��` */
  /*  �T�� */
  c_emxInitStruct_coder_internal_(&num_temp);
  if (run_mode == 0) {
    /* �}�E�X�̏����ʒu�ݒ� */
    /* for C gen */
    /* �e�t���O���` */
    /* ��~���� */
    /* ��~���������{���� */
    /* �S�[������t���O�̓N���A */
    /* ��}�X�O�i */
    col_temp = 1U;

    /* ���� ���݈ʒux,y,���ݕ��� */
    /* �o�� ���݈ʒux,y */
    /*  move_step ��}�X�O�i����֐� */
    /* �k�Ɉ�}�X */
    search_flag = 2U;

    /* disp("north_step") */
    /* ���Ɉ�}�X */
    if (g_direction.North == g_direction.East) {
      col_temp = 2U;

      /* disp("east_step") */
    }

    /* ��Ɉ�}�X */
    if (g_direction.North == g_direction.South) {
      search_flag = 1U;

      /* disp("south_step") */
    }

    /* ���Ɉ�}�X */
    if (g_direction.North == g_direction.West) {
      col_temp--;

      /* disp("west_step") */
    }

    /* C����ł̃X�^�[�g���� */
    m_start_movement(1, 0, move_dir_property.straight);

    /* ��~����t���O���N���A */
    /* �S�[�����v���b�g */
    /* �����@�ɂ��T�� */
    current_x.contents = col_temp;
    current_y.contents = search_flag;
    current_dir.contents = g_direction.North;
    start_flg = 0U;
    search_adachi(&wall, &wall_flg, &search, &b_maze_goal, &num_temp,
                  &current_x.contents, &current_y.contents,
                  &current_dir.contents, maze_row_size, maze_col_size, maze_wall,
                  maze_wall_search, maze_goal, goal_size, &start_flg, 0U,
                  contour_map);

    /* �ЂƂ܂ÃS�[��(��~) */
    /* �e�t���O���` */
    start_flg = 1U;

    /* ��~���� */
    /* ��~���������{���Ȃ� */
    /* �S�[������t���O�����Ă� */
    /* �S�[�������ׂĒT�� */
    do {
      exitg1 = 0;
      search_flag = 0U;
      idx = 0;
      exitg2 = false;
      while ((!exitg2) && (idx <= goal_size - 1)) {
        col_temp = b_maze_goal.contents[idx + 9];
        if (maze_wall_search[(col_temp + ((b_maze_goal.contents[idx] - 1) << 5))
            - 1] != 15) {
          new_goal[0] = b_maze_goal.contents[idx];
          new_goal[9] = col_temp;
          search_flag = 1U;
          exitg2 = true;
        } else {
          idx++;
        }
      }

      if (search_flag == 1) {
        b_search_adachi(&wall, &wall_flg, &search, &b_maze_goal, &num_temp,
                        &current_x.contents, &current_y.contents,
                        &current_dir.contents, maze_row_size, maze_col_size,
                        maze_wall, maze_wall_search, new_goal, &start_flg, 1U,
                        contour_map);

        /* �S�[������t���O�����Ă� */
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    /* ���T���}�X���Ȃ��Ȃ�܂ŁB */
    /*  ���n�_�����ԋ߂����T���}�X��T�� */
    do {
      exitg1 = 0;

      /* ���T���̃}�X�𒊏o */
      /* ���T���}�X�̌��ݒn�i�S�[���j����̋����𒊏o */
      /* �T����������uint16�̏����(�V�����S�[����min�Ō��肵�����̂ŁB) */
      for (idx = 0; idx < 1024; idx++) {
        b0 = (maze_wall_search[idx] != 15);
        contour_map_temp[idx] = (unsigned short)((unsigned int)b0 *
          contour_map[idx]);
        if (b0 * contour_map[idx] == 0) {
          contour_map_temp[idx] = MAX_uint16_T;
        }
      }

      /* ���T���}�X�̂����A���ݒn�����ԋ߂��}�X�̗v�f�ԍ��𒊏o */
      minval = contour_map_temp[0];
      for (idx = 0; idx < 1023; idx++) {
        u11 = contour_map_temp[idx + 1];
        if (minval > u11) {
          minval = u11;
        }
      }

      idx = 0;
      ii_size_idx_0 = 1;
      ii = 0;
      exitg2 = false;
      while ((!exitg2) && (ii < 1024)) {
        if (contour_map_temp[ii] == minval) {
          idx = 1;
          ii_data[0] = (short)(ii + 1);
          exitg2 = true;
        } else {
          ii++;
        }
      }

      if (idx == 0) {
        ii_size_idx_0 = 0;
      }

      for (idx = 0; idx < ii_size_idx_0; idx++) {
        tmp_data[0] = (unsigned short)ii_data[0];
      }

      idx = num_temp.contents->size[0];
      num_temp.contents->size[0] = ii_size_idx_0;
      emxEnsureCapacity_uint16_T(num_temp.contents, idx);
      for (idx = 0; idx < ii_size_idx_0; idx++) {
        num_temp.contents->data[0] = (unsigned short)ii_data[0];
      }

      /* �s�ԍ��𒊏o(32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂�) */
      search_flag = (unsigned char)((tmp_data[0] - 1) % 32 + 1);

      /* ��ԍ��𒊏o(32�Ŋ������Ƃ��̏�) */
      col_temp = (unsigned char)((int)trunc(((double)num_temp.contents->data[0]
        - 1.0) / 32.0) + 1);
      if (contour_map_temp[(search_flag + ((col_temp - 1) << 5)) - 1] == 65535)
      {
        exitg1 = 1;
      } else {
        new_goal[0] = col_temp;
        new_goal[9] = search_flag;

        /* �S�[�����v���b�g              */
        b_search_adachi(&wall, &wall_flg, &search, &b_maze_goal, &num_temp,
                        &current_x.contents, &current_y.contents,
                        &current_dir.contents, maze_row_size, maze_col_size,
                        maze_wall, maze_wall_search, new_goal, &start_flg, 1U,
                        contour_map);

        /* �S�[������t���O�����Ă� */
      }
    } while (exitg1 == 0);

    /* ���T���}�X��������Ȃ��Ƃ��A��~���������{ */
    m_goal_movement(start_flg, wall_flg.contents, move_dir_property.straight);

    /* �X�^�[�g��ړI�n�Ƃ��đ����@�ōĒT�� */
    /* �e�t���O���` */
    /* ��~���� */
    /* ��~���������{���� */
    /* �S�[������t���O�����Ă� */
    new_goal[0] = 1U;
    new_goal[9] = 1U;
    start_flg = 1U;
    search_adachi(&wall, &wall_flg, &search, &b_maze_goal, &num_temp,
                  &current_x.contents, &current_y.contents,
                  &current_dir.contents, maze_row_size, maze_col_size, maze_wall,
                  maze_wall_search, new_goal, 1U, &start_flg, 1U, contour_map);

    /* for code generation */
  }

  /*  �ŒZ���s */
  if (run_mode == 1) {
    /* �T���������Ƃɓ�����MAP�𐶐� */
    make_map_fustrun(&b_goal_size, &num_temp, &wall, &search,
                     b_maze_goal.contents, maze_wall, maze_wall_search,
                     contour_map);
    max_length.contents = MAX_uint16_T;

    /* �R���^�[�}�b�v�̕`�� */
    /* �ŒZ�������s */
    fust_run(&current_x, &current_y, &current_dir, &b_goal_size, &wall,
             maze_wall, contour_map, b_maze_goal.contents, MAX_uint16_T);
  }

  /*  �΂߂ł̍ŒZ���s */
  if (run_mode == 2) {
    /* �ŒZ�o�H���� */
    /* �S�[���}�X�̃m�[�h�����ׂăS�[���m�[�h�Ƃ��A�}�b�v���� */
    make_map_fustrun_diagonal(&max_length, &num_temp, &wall, &search,
      b_maze_goal.contents, b_goal_size.contents, maze_wall, maze_wall_search,
      row_num_node, col_num_node, &minval);

    /* �S�[���t�߂̃��[�g�œK���̂��߁A�}�b�v�Đ��� */
    /* �X�^�[�g����S�[���m�[�h�܂ŁA���[�g�������A�S�[���m�[�h�A�������m�� */
    decide_goal_node_dir(b_maze_goal.contents, b_goal_size.contents,
                         row_num_node, col_num_node, goal_section, &search_flag,
                         &col_temp);

    /* �m�肳�ꂽ�S�[���m�[�h�A��������S�[���}�X�A�m�[�h���Ē�` */
    decide_goal_section(b_maze_goal.contents, goal_section, search_flag,
                        col_temp, b_goal_section, goal_node2, &start_flg);

    /* �m�肳�ꂽ�S�[���}�X����A�ēx�}�b�v�𐶐� */
    goal_section[0] = b_goal_section[1];
    goal_section[1] = b_goal_section[0];

    /* x,y�ɕϊ� */
    b_make_map_fustrun_diagonal(&max_length, &num_temp, &wall, &search,
      goal_section, maze_wall, maze_wall_search, row_num_node, col_num_node,
      &minval);

    /*      if coder.target('MATLAB')    */
    /*          %�����}�b�v�v���b�g(�ǂ̕����͂Ȃ�) */
    /*          hold on */
    /*          %�Z�N�V��������(�S�[���A�X�^�[�g�̂�) */
    /*          text((goal_section(1)-1)*9+4.5,(goal_section(2)-1)*9+4.5,string(goal_num),'HorizontalAlignment','center'); */
    /*          text(4.5,4.5,string(start_num),'HorizontalAlignment','center'); */
    /*          %�G�b�W���� */
    /*          %row_node */
    /*          for l = 1:33 */
    /*              for j = 1:32 */
    /*                  if row_num_node(l,j) ~= 65535 */
    /*                      text((j-1)*9+4.5,(l-1)*9,string(row_num_node(l,j)),'HorizontalAlignment','center'); */
    /*                  end */
    /*              end */
    /*          end  */
    /*   */
    /*          %col_node */
    /*          for l = 1:32 */
    /*              for j = 1:33 */
    /*                  if col_num_node(l,j) ~= 65535 */
    /*                      text((j-1)*9,(l-1)*9+4.5,string(col_num_node(l,j)),'HorizontalAlignment','center'); */
    /*                  end */
    /*              end */
    /*          end     */
    /*          hold off */
    /*      end */
    /* �������ꂽMAP�����ƂɍŒZ���s */
    make_route_diagonal(row_num_node, col_num_node, goal_section, goal_node2,
                        start_flg);
  }

  c_emxFreeStruct_coder_internal_(&num_temp);
}

/*
 * File trailer for maze_solve.c
 *
 * [EOF]
 */
