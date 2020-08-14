/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rt_nonfinite.h
 *
 * Code generation for function 'maze_init'
 *
 */

#ifndef RT_NONFINITE_H
#define RT_NONFINITE_H
#define rtInf      	mxGetInf()
#define rtMinusInf 	(-mxGetInf())
#define rtNaN      	mxGetNaN()
#define rtInfF     	(real32_T)mxGetInf()
#define rtMinusInfF	(-(real32_T)mxGetInf())
#define rtNaNF     	(real32_T)mxGetNaN()
#define rtIsNaN(X) 	mxIsNaN(X)
#define rtIsInf(X) 	mxIsInf(X)
#define rtIsNaNF(X)	mxIsNaN(X)
#define rtIsInfF(X)	mxIsInf(X)
#endif
/* End of code generation (rt_nonfinite.h) */
