/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * maze_init.c
 *
 * Code generation for function 'maze_init'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "maze_init.h"
#include "maze_solve.h"
#include "maze_init_mex_data.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  32,                                  /* iLast */
  24,                                  /* lineNo */
  46,                                  /* colNo */
  "maze_wall",                         /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  24,                                  /* lineNo */
  48,                                  /* colNo */
  "maze_wall",                         /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  29,                                  /* lineNo */
  46,                                  /* colNo */
  "maze_wall",                         /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  29,                                  /* lineNo */
  48,                                  /* colNo */
  "maze_wall",                         /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  34,                                  /* lineNo */
  48,                                  /* colNo */
  "maze_wall",                         /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  39,                                  /* lineNo */
  46,                                  /* colNo */
  "maze_wall",                         /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  60,                                  /* lineNo */
  27,                                  /* colNo */
  "maze_wall_search",                  /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  63,                                  /* lineNo */
  22,                                  /* colNo */
  "maze_wall_search",                  /* aName */
  "maze_init",                         /* fName */
  "C:\\work\\matlab\\maze_sim_git\\src\\maze_init.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void maze_init(const emlrtStack *sp, uint8_T maze_row_size, uint8_T
               maze_col_size, uint8_T maze_wall[1024], uint8_T maze_wall_search
               [1024])
{
  uint32_T qY;
  int32_T i0;
  int32_T i;
  int32_T i1;
  int32_T n;
  int32_T maze_wall_tmp;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* maze_init ���H���̏����� */
  /* ���� ���H���T�C�Y, ���H�c�T�C�Y  */
  /* �o�� ���H�Ǐ��,���H�ǒT���ςݏ�� */
  /* ���p��` */
  /* ���H���A�T���Ϗ�񏉊��� */
  /*  maze_wall = uint8(zeros(maze_col_size-1,maze_row_size-1)); */
  /*  maze_wall_search = uint8(zeros(maze_col_size-1,maze_row_size-1)); */
  memset(&maze_wall[0], 0, sizeof(uint8_T) << 10);

  /* ���m�ƂȂ�O��4�ӂ̕Ǐ�����́A�T���ς݂Ƃ���B */
  qY = maze_row_size - 1U;
  if (qY > maze_row_size) {
    qY = 0U;
  }

  i0 = (int32_T)qY;
  for (i = 0; i < i0; i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    qY = maze_col_size - 1U;
    if (qY > maze_col_size) {
      qY = 0U;
    }

    i1 = (int32_T)qY;
    for (n = 0; n < i1; n++) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 1);

      /* �k�� */
      qY = maze_row_size - 1U;
      if (qY > maze_row_size) {
        qY = 0U;
      }

      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, 1 + i == (int32_T)qY)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
        maze_wall_tmp = 1 + i;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &emlrtBCI, sp);
        }

        maze_wall_tmp = 1 + n;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &b_emlrtBCI, sp);
        }

        maze_wall_tmp = i + (n << 5);
        maze_wall[maze_wall_tmp] |= 1;
      }

      /* ���� */
      qY = maze_col_size - 1U;
      if (qY > maze_col_size) {
        qY = 0U;
      }

      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, 1 + n == (int32_T)qY)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
        maze_wall_tmp = 1 + i;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &c_emlrtBCI, sp);
        }

        maze_wall_tmp = 1 + n;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &d_emlrtBCI, sp);
        }

        maze_wall[i + (n << 5)] = (uint8_T)(maze_wall[i + (n << 5)] | 2);
      }

      /* �쑤 */
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, 1 + i == 1)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
        maze_wall_tmp = 1 + n;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &e_emlrtBCI, sp);
        }

        maze_wall[n << 5] = (uint8_T)(maze_wall[n << 5] | 4);
      }

      /* ���� */
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, 1 + n == 1)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
        maze_wall_tmp = 1 + i;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &f_emlrtBCI, sp);
        }

        maze_wall[i] = (uint8_T)(maze_wall[i] | 8);
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);

  /* �X�^�[�g���̕ǂ�|_|�ƂȂ��Ă���̂ŁA���炩���ߓ��� */
  /* �X�^�[�g�}�X���猩�ē��� */
  maze_wall[0] = (uint8_T)(maze_wall[0] | 2);

  /* �X�^�[�g�}�X�̈�}�X�����̃}�X���猩�Đ��� */
  maze_wall[32] = (uint8_T)(maze_wall[32] | 8);

  /* �ȏ�̕Ǐ��͒T���ς݂Ƃ��� */
  memcpy(&maze_wall_search[0], &maze_wall[0], sizeof(uint8_T) << 10);

  /* ���W(1,1)�̖k���A(2,1)�̓쑤�͕ǂ��Ȃ����Ƃ��킩���Ă���̂ŒT���ς݂Ƃ���B */
  maze_wall_search[0] = (uint8_T)(maze_wall[0] | 1);
  maze_wall_search[1] = (uint8_T)(maze_wall[1] | 4);

  /* ���H��32�}�X�����̎��A�T�C�Y�ȏ�͈̔͂́A�T���s�v�i�s�j�̂��߁A�T���ς݂Ƃ���B */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 4, maze_col_size < 32)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
    if (maze_col_size < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 32, &g_emlrtBCI, sp);
    }

    maze_wall_tmp = 33 - maze_col_size;
    for (i0 = 0; i0 < maze_wall_tmp; i0++) {
      for (i1 = 0; i1 < 32; i1++) {
        maze_wall_search[i1 + (((maze_col_size + i0) - 1) << 5)] = 15U;
      }
    }
  }

  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 5, maze_row_size < 32)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
    if (maze_row_size < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 32, &h_emlrtBCI, sp);
    }

    maze_wall_tmp = 33 - maze_row_size;
    for (i0 = 0; i0 < 32; i0++) {
      memset(&maze_wall_search[((i0 << 5) + maze_row_size) + -1], 15, (uint32_T)
             (maze_wall_tmp * (int32_T)sizeof(uint8_T)));
    }
  }
}

/* End of code generation (maze_init.c) */
