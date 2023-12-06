#pragma once

// define floating point precision
#ifdef FLOAT_PRECISION
using Float = float;
#elif defined(DOUBLE_PRECISION)
using Float = double;
#endif

