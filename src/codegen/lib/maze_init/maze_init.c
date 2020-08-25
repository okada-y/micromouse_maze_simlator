/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: maze_init.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 24-Aug-2020 20:13:17
 */

/* Include Files */
#include <string.h>
#include "maze_init.h"
#include "maze_solve.h"

/* Function Definitions */

/*
 * maze_init ���H���̏�����
 * ���� ���H���T�C�Y, ���H�c�T�C�Y
 * �o�� ���H�Ǐ��,���H�ǒT���ςݏ��
 * Arguments    : unsigned char maze_row_size
 *                unsigned char maze_col_size
 *                unsigned char maze_wall[1024]
 *                unsigned char maze_wall_search[1024]
 * Return Type  : void
 */
void maze_init(unsigned char maze_row_size, unsigned char maze_col_size,
               unsigned char maze_wall[1024], unsigned char maze_wall_search
               [1024])
{
  unsigned int qY;
  int i0;
  int i;
  int i1;
  int n;
  int maze_wall_tmp;

  /* ���p��` */
  /* ���H���A�T���Ϗ�񏉊��� */
  /*  maze_wall = uint8(zeros(maze_col_size-1,maze_row_size-1)); */
  /*  maze_wall_search = uint8(zeros(maze_col_size-1,maze_row_size-1)); */
  memset(&maze_wall[0], 0, sizeof(unsigned char) << 10);

  /* ���m�ƂȂ�O��4�ӂ̕Ǐ�����́A�T���ς݂Ƃ���B */
  qY = maze_row_size - 1U;
  if (qY > maze_row_size) {
    qY = 0U;
  }

  i0 = (int)qY;
  for (i = 0; i < i0; i++) {
    qY = maze_col_size - 1U;
    if (qY > maze_col_size) {
      qY = 0U;
    }

    i1 = (int)qY;
    for (n = 0; n < i1; n++) {
      /* �k�� */
      qY = maze_row_size - 1U;
      if (qY > maze_row_size) {
        qY = 0U;
      }

      if (1 + i == (int)qY) {
        maze_wall_tmp = i + (n << 5);
        maze_wall[maze_wall_tmp] |= 1;
      }

      /* ���� */
      qY = maze_col_size - 1U;
      if (qY > maze_col_size) {
        qY = 0U;
      }

      if (1 + n == (int)qY) {
        maze_wall[i + (n << 5)] = (unsigned char)(maze_wall[i + (n << 5)] | 2);
      }

      /* �쑤 */
      if (1 + i == 1) {
        maze_wall[n << 5] = (unsigned char)(maze_wall[n << 5] | 4);
      }

      /* ���� */
      if (1 + n == 1) {
        maze_wall[i] = (unsigned char)(maze_wall[i] | 8);
      }
    }
  }

  /* �X�^�[�g���̕ǂ�|_|�ƂȂ��Ă���̂ŁA���炩���ߓ��� */
  /* �X�^�[�g�}�X���猩�ē��� */
  maze_wall[0] = (unsigned char)(maze_wall[0] | 2);

  /* �X�^�[�g�}�X�̈�}�X�����̃}�X���猩�Đ��� */
  maze_wall[32] = (unsigned char)(maze_wall[32] | 8);

  /* �ȏ�̕Ǐ��͒T���ς݂Ƃ��� */
  memcpy(&maze_wall_search[0], &maze_wall[0], sizeof(unsigned char) << 10);

  /* ���W(1,1)�̖k���A(2,1)�̓쑤�͕ǂ��Ȃ����Ƃ��킩���Ă���̂ŒT���ς݂Ƃ���B */
  maze_wall_search[0] = (unsigned char)(maze_wall[0] | 1);
  maze_wall_search[1] = (unsigned char)(maze_wall[1] | 4);

  /* ���H��32�}�X�����̎��A�T�C�Y�ȏ�͈̔͂́A�T���s�v�i�s�j�̂��߁A�T���ς݂Ƃ���B */
  if (maze_col_size < 32) {
    i = 33 - maze_col_size;
    for (i0 = 0; i0 < i; i0++) {
      for (i1 = 0; i1 < 32; i1++) {
        maze_wall_search[i1 + (((maze_col_size + i0) - 1) << 5)] = 15U;
      }
    }
  }

  if (maze_row_size < 32) {
    i = 33 - maze_row_size;
    for (i0 = 0; i0 < 32; i0++) {
      memset(&maze_wall_search[((i0 << 5) + maze_row_size) + -1], 15, (unsigned
              int)(i * (int)sizeof(unsigned char)));
    }
  }
}

/*
 * File trailer for maze_init.c
 *
 * [EOF]
 */
