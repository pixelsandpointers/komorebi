#pragma once
#include "Ray.h"
namespace komorebi
{
struct Camera
{
    Camera() = default;
    ~Camera() = default;
    float3 m_position;

    bool IntersectRay(Ray &r, Float distance = 100.) const
    {
        const auto hit = r.CastRay(distance);
        return true;
    }
};

} // namespace komorebi
