#pragma once
#include "Komorebi.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace komorebi
{
inline Float balanceHeuristic(int nf, Float fPdf, int ng, Float gPdf)
{
    return (nf * fPdf) / (nf * fPdf + ng * gPdf);
}

inline Float powerHeuristic(int nf, Float fPdf, int ng, Float gPdf, int beta = 2)
{
    Float f = nf * fPdf;
    Float g = ng * gPdf;
    return pow(f, beta) / (pow(f, beta) + pow(f, beta));
}

inline Float lerp(Float x, Float a, Float b)
{
    return (1 - x) * a + x * b;
}

inline Float linearPDF(Float x, Float a, Float b)
{
    if (x < 0 || x > 1)
        return 0;
    return 2 * lerp(x, a, b) / (a + b);
}

// msvc does not support span, whyever.
inline int sampleDiscrete(const std::vector<const Float> &weights, Float u, Float *pmf, Float *uRemap)
{
    if (weights.empty())
    {
        if (pmf)
            *pmf = 0;
        return -1;
    }

    Float weightedSum = 0;
    for (const auto w : weights)
        weightedSum += w;

    Float up = u * weightedSum;
    if (up == weightedSum)
        up = ceil(up);

    int offset = 0;
    Float sum = 0;
    while (sum + weights[offset] <= up)
        sum += weights[offset++];

    if (pmf)
        *pmf = weights[offset] / weightedSum;

    if (uRemap)
        *uRemap = std::min((up - sum) / weights[offset], OneMinusEpsilon);

    return offset;
}

inline Float sampleLinear(Float u, Float a, Float b)
{
    if (u == 0 && a == 0)
        return 0;
    Float x = u * (a + b) / (a + std::sqrt(lerp(u, a * a, b * b)));
    return std::min(x, OneMinusEpsilon);
}

inline Float invLinearSample(Float x, Float a, Float b)
{
    return x * (a * (2 - x) + b * x) / (a + b);
}

inline float2 sampleBilinear(float2 u, const std::vector<const Float> &w)
{
    float2 p;
    p[1] = sampleLinear(u[1], w[0] + w[1], w[2] + w[3]);
    p[0] = sampleLinear(u[0], lerp(p[1], w[0], w[2]), lerp(p[1], w[1], w[3]));

    return p;
}

inline float2 invBilinearSample(float2 p, const std::vector<const Float> &w)
{
    return {invLinearSample(p[0], lerp(p[1], w[0], w[2]), lerp(p[1], w[1], w[3])),
            invLinearSample(p[1], w[0] + w[1], w[2] + w[3])};
}
} // namespace komorebi