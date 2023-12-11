#pragma once
// includes
#include "Vector.h"

// define floating point precision
#ifdef USE_FLOAT_PRECISION
using Float = float;
using FloatBits = uint32_t;
#else
using Float = double;
using FloatBits = uint64_t;
#endif

using Vector3i = komorebi::math::internal::Vector<int, 3>;
using Vector3f = komorebi::math::internal::Vector<Float, 3>;

