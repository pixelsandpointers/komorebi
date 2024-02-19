#pragma once
#include "Komorebi.h"
#include <vector>

namespace komorebi
{
namespace math
{
template <typename T, int N> struct Vector
{
    using type = T;
    using iterator = type *;
    using const_iterator = const type *;
    using size_t = std::size_t;

    std::vector<T> m_values = std::vector<T>(N, static_cast<T>(0));

    Vector() = default;
    Vector(std::initializer_list<T> v)
    {
        size_t i = 0;
        for (const T &val : v)
            m_values[i++] = val;
    }

    bool isNan() const
    {
        for (int i = 0; i < N; ++i)
        {
            if (isnan(m_values[i]))
                return true;
        }
        return false;
    }

    void fill(const T &v)
    {
        for (int i = 0; i < N; ++i)
            m_values[i] = v;
    }

    bool operator==(const Vector<T, N> &a) const
    {
        for (int i = 0; i < N; ++i)
            if (m_values[i] != a.m_values[i])
                return false;
        return true;
    }

    bool operator!=(const Vector<T, N> &a) const
    {
        return !(*this == a);
    }

    T &operator[](size_t i)
    {
        return m_values[i];
    }
    const T &operator[](size_t i) const
    {
        return m_values[i];
    }

    size_t size() const
    {
        return m_values.size();
    }

    T *data()
    {
        return m_values.data();
    }

    const T *data() const
    {
        return m_values.data();
    }
};
} // namespace math

// expose commonly used vector types under komorebi namespace
using float2 = math::Vector<Float, 2>;
using float3 = math::Vector<Float, 3>;
using float4 = math::Vector<Float, 4>;

using i64_2 = math::Vector<int64_t, 2>;
using i64_3 = math::Vector<int64_t, 3>;
using i64_4 = math::Vector<int64_t, 4>;

using i32_2 = math::Vector<int32_t, 2>;
using i32_3 = math::Vector<int32_t, 3>;
using i32_4 = math::Vector<int32_t, 4>;
} // namespace komorebi