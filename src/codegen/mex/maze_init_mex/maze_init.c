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
  24,                                  /* colNo */
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

  /* maze_init 迷路情報の初期化 */
  /* 入力 迷路横サイズ, 迷路縦サイズ  */
  /* 出力 迷路壁情報,迷路壁探索済み情報 */
  /* 方角定義 */
  /* 迷路情報、探索済情報初期化 */
  /*  maze_wall = uint8(zeros(maze_col_size-1,maze_row_size-1)); */
  /*  maze_wall_search = uint8(zeros(maze_col_size-1,maze_row_size-1)); */
  memset(&maze_wall[0], 0, sizeof(uint8_T) << 10);

  /* 既知となる外周4辺の壁情報を入力、探索済みとする。 */
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

      /* 北側 */
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

      /* 東側 */
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

      /* 南側 */
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, 1 + i == 1)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
        maze_wall_tmp = 1 + n;
        if (maze_wall_tmp > 32) {
          emlrtDynamicBoundsCheckR2012b(maze_wall_tmp, 1, 32, &e_emlrtBCI, sp);
        }

        maze_wall[n << 5] = (uint8_T)(maze_wall[n << 5] | 4);
      }

      /* 西側 */
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

  /* スタート時の壁は|_|となっているので、あらかじめ入力 */
  /* スタートマスから見て東側 */
  maze_wall[0] = (uint8_T)(maze_wall[0] | 2);

  /* スタートマスの一マス東側のマスから見て西側 */
  maze_wall[32] = (uint8_T)(maze_wall[32] | 8);

  /* 以上の壁情報は探索済みとする */
  memcpy(&maze_wall_search[0], &maze_wall[0], sizeof(uint8_T) << 10);

  /* 座標(1,1)の北側、(2,1)の南側は壁がないことがわかっているので探索済みとする。 */
  maze_wall_search[0] = (uint8_T)(maze_wall[0] | 1);
  maze_wall_search[1] = (uint8_T)(maze_wall[1] | 4);

  /* 迷路が32マス未満の時、サイズ以上の範囲は、探索不要（不可）のため、探索済みとする。 */
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
