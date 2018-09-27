#include "Math.h"
#include <purescript.h>

#define MATH_FFI_VAL(NAME, V)\
	PURS_FFI_VALUE(Math_ ## NAME, PURS_ANY_NUMBER(V))

#define MATH_FFI_1_(NAME, FN)\
	PURS_FFI_FUNC_1(Math_ ## NAME, v, {\
		return PURS_ANY_NUMBER_NEW(FN(purs_any_get_number(v)));\
	})

#define MATH_FFI_1(FN) MATH_FFI_1_(FN, FN)

#define MATH_FFI_2_(NAME, FN)\
	PURS_FFI_FUNC_2(Math_ ## NAME, v, w, {\
		return PURS_ANY_NUMBER_NEW(FN(purs_any_get_number(v),\
					      purs_any_get_number(w)));\
	})

#define MATH_FFI_2(FN) MATH_FFI_2_(FN, FN)

MATH_FFI_1_(abs, fabs);
MATH_FFI_1(acos);
MATH_FFI_1(asin);
MATH_FFI_1(atan);
MATH_FFI_2(atan2);
MATH_FFI_1(ceil);
MATH_FFI_1(cos);
MATH_FFI_1(exp);
MATH_FFI_1(floor);
MATH_FFI_1(log);
MATH_FFI_2(pow);
MATH_FFI_1(round);
MATH_FFI_1(sin);
MATH_FFI_1(sqrt);
MATH_FFI_1(tan);
MATH_FFI_1(trunc);
MATH_FFI_2_(remainder, fmod);
MATH_FFI_VAL(e, 2.7182818284590451);
MATH_FFI_VAL(ln2, 0.6931471805599453);
MATH_FFI_VAL(ln10, 2.302585092994046);
MATH_FFI_VAL(log2e, 1.4426950408889634);
MATH_FFI_VAL(log10e, 0.4342944819032518);
MATH_FFI_VAL(pi, 3.141592653589793);
MATH_FFI_VAL(sqrt1_2, 0.7071067811865476);
MATH_FFI_VAL(sqrt2, 1.4142135623730951);

PURS_FFI_FUNC_2(Math_max, a, b, {
	return (purs_any_get_number(a) < purs_any_get_number(b)) ? b : a;
})

PURS_FFI_FUNC_2(Math_min, a, b, {
	return (purs_any_get_number(a) < purs_any_get_number(b)) ? a : b;
})
