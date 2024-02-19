#pragma once
#include "Vector.h"
#include "VectorOps.h"

namespace komorebi
{
struct Ray
{
    Ray() = default;
    ~Ray() = default;
    Ray(float3 origin, float3 direction) : m_origin(origin), m_direction(direction){};

    float3 m_origin;
    float3 m_direction;

    bool IsNaN() const
    {
        return (m_origin.isNan() || m_direction.isNan());
    }
    float3 CastRay(Float t) const
    {
        return m_origin + m_direction * t;
    }
    float3 operator()(Float t) const
    {
        return CastRay(t);
    }
};
} // namespace komorebi