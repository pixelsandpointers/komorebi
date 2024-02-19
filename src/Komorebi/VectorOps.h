#pragma once
#include "Vector.h"

namespace komorebi
{
inline float3 operator+(const float3 &v, const float3 &u)
{
    float3 out{};
    for (size_t i = 0; i < out.size(); ++i)
    {
        out[i] = v.m_values[i] + u.m_values[i];
    }

    return out;
}

inline float3 operator-(const float3 &v, const float3 &u)
{
    float3 out{};
    for (size_t i = 0; i < out.size(); ++i)
    {
        out[i] = v.m_values[i] - u.m_values[i];
    }

    return out;
}

inline float3 operator*(const float3 &v, Float f)
{
    float3 out{};
    for (size_t i = 0; i < out.size(); ++i)
    {
        out[i] = v.m_values[i] * f;
    }

    return out;
}

inline Float dot(const float3 &v, const float3 &u)
{
    Float out = 0.;
    for (size_t i = 0; i < v.size(); ++i)
    {
        out += v[i] * u[i];
    }

    return out;
}

inline float3 crossProduct(const float3 &v, const float3 &u)
{
    return float3{u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]};
}

} // namespace komorebi