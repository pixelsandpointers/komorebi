#pragma once
#include <stdint.h>
#ifdef USE_FLOAT_PRECISION
using Float = float;
using FloatBits = uint32_t;
constexpr float OneMinusEpsilon = 0x1.fffffep-1;
#else
using Float = double;
using FloatBits = uint64_t;
constexpr double OneMinusEpsilon = 0x1.fffffffffffffp-1;
#endif

// includes
#include "Base/Camera.h"
#include "Ray.h"
#include "Sampling.h"
#include "Vector.h"
#include "VectorOps.h"
