#pragma once
namespace komorebi
{
	namespace math
	{
		namespace internal
		{
			template <typename T, int N>
			struct Vector
			{
				using type = T;
				using iterator = type*;
				using const_iterator = const type*;
				using size_t = std::size_t;

				T m_values[N] = {};

				Vector() = default;
				Vector(std::initializer_list<T> v)
				{
					size_t i = 0;
					for (const T& val : v)
						m_values[i++] = val;
				}

				void fill(const T& v)
				{
					for (int i = 0; i < N; ++i)
						m_values[i] = v;
				}

				bool operator==(const Vector<T, N>& a) const
				{
					for (int i = 0; i < N; ++i)
						if (m_values[i] != a.m_values[i])
							return false;
					return true;
				}

				bool operator!=(const Vector<T, N>& a) const
				{
					return !(*this == a);
				}

				T& operator[](size_t i)
				{
					return m_values[i];
				}
				const T& operator[](size_t i) const
				{
					return m_values[i];
				}

				T* data()
				{
					return m_values;
				}

				const T* data() const
				{
					return m_values;
				}
			};
		}
	}
}