#pragma once
#include "Nacy/Core/Core.h"
namespace Engine
{

	template<size_t S, typename T> class Vector;

	template<typename T>
	class  Vector<2, T>
	{
	public:
		Vector(T x, T y) : x(x), y(y) {}

		template<typename U>
		Vector<2, T>& operator=(Vector<2, U> const& vector);
		template<typename U>
		Vector<2, T>& operator+=(U scalar);
		template<typename U>
		Vector<2, T>& operator+=(Vector<2, U> const& vector);
		template<typename U>
		Vector<2, T>& operator-=(U scalar);
		template<typename U>
		Vector<2, T>& operator-=(Vector<2, U> const& vector);
		template<typename U>
		Vector<2, T>& operator*=(U scalar);
		template<typename U>
		Vector<2, T>& operator*=(Vector<2, U> const& vector);
		template<typename U>
		Vector<2, T>& operator/=(U scalar);
		template<typename U>
		Vector<2, T>& operator/=(Vector<2, U> const& vector);
		T x, y;
	};
	//========================================= Vector2 =========================================
	template<typename T>
	 Vector<2, T> operator+(Vector<2, T> const& vector, T scalar);
	template<typename T>
	 Vector<2, T> operator+(T scalar, Vector<2, T> const& v);
	template<typename T>
	 Vector<2, T> operator+(Vector<2, T> const& vector1, Vector<2, T> const& vector2);
	template<typename T>
	 Vector<2, T> operator-(Vector<2, T> const& vector, T scalar);
	template<typename T>
	 Vector<2, T> operator-(T scalar, Vector<2, T> const& vector);
	template<typename T>
	 Vector<2, T> operator-(Vector<2, T> const& vector1, Vector<2, T> const& vector2);
	template<typename T>
	 Vector<2, T> operator*(Vector<2, T> const& vector, T scalar);
	template<typename T>
	 Vector<2, T> operator*(T scalar, Vector<2, T> const& vector);
	template<typename T>
	 Vector<2, T> operator*(Vector<2, T> const& vector1, Vector<2, T> const& vector2);
	template<typename T>
	 Vector<2, T> operator/(Vector<2, T> const& vector, T scalar);
	template<typename T>
	 Vector<2, T> operator/(T scalar, Vector<2, T> const& vector);
	template<typename T>
	 Vector<2, T> operator/(Vector<2, T> const& vector1, Vector<2, T> const& vector2);

	//========================================= Vector3 =========================================

	template<typename T>
	class  Vector<3, T>
	{
	public:
		Vector(T x, T y, T z) : x(x), y(y), z(z) {}
		template<typename U>
		Vector<3, T>& operator=(Vector<3, U> const& vector);
		template<typename U>
		Vector<3, T>& operator+=(U scalar);
		template<typename U>
		Vector<3, T>& operator+=(Vector<3, U> const& vector);
		template<typename U>
		Vector<3, T>& operator-=(U scalar);
		template<typename U>
		Vector<3, T>& operator-=(Vector<3, U> const& vector);
		template<typename U>
		Vector<3, T>& operator*=(U scalar);
		template<typename U>
		Vector<3, T>& operator*=(Vector<3, U> const& vector);
		template<typename U>
		Vector<3, T>& operator/=(U scalar);
		template<typename U>
		Vector<3, T>& operator/=(Vector<3, U> const& vector);
		T x, y, z;
	};

	template<typename T>
	 Vector<3, T> operator+(Vector<3, T> const& vector, T scalar);
	template<typename T>
	 Vector<3, T> operator+(T scalar, Vector<3, T> const& v);
	template<typename T>
	 Vector<3, T> operator+(Vector<3, T> const& vector1, Vector<3, T> const& vector2);
	template<typename T>
	 Vector<3, T> operator-(Vector<3, T> const& vector, T scalar);
	template<typename T>
	 Vector<3, T> operator-(T scalar, Vector<3, T> const& vector);
	template<typename T>
	 Vector<3, T> operator-(Vector<3, T> const& vector1, Vector<3, T> const& vector2);
	template<typename T>
	 Vector<3, T> operator*(Vector<3, T> const& vector, T scalar);
	template<typename T>
	 Vector<3, T> operator*(T scalar, Vector<3, T> const& vector);
	template<typename T>
	 Vector<3, T> operator*(Vector<3, T> const& vector1, Vector<3, T> const& vector2);
	template<typename T>
	 Vector<3, T> operator/(Vector<3, T> const& vector, T scalar);
	template<typename T>
	 Vector<3, T> operator/(T scalar, Vector<3, T> const& vector);
	template<typename T>
	 Vector<3, T> operator/(Vector<3, T> const& vector1, Vector<3, T> const& vector2);

	//========================================= Vector4 =========================================
	template<typename T>
	class  Vector<4, T>
	{
	public:
		Vector(T x, T y, T z) : x(x), y(y), z(z), w(w) {}
		template<typename U>
		Vector<4, T>& operator=(Vector<4, U> const& vector);
		template<typename U>
		Vector<4, T>& operator+=(U scalar);
		template<typename U>
		Vector<4, T>& operator+=(Vector<4, U> const& vector);
		template<typename U>
		Vector<4, T>& operator-=(U scalar);
		template<typename U>
		Vector<4, T>& operator-=(Vector<4, U> const& vector);
		template<typename U>
		Vector<4, T>& operator*=(U scalar);
		template<typename U>
		Vector<4, T>& operator*=(Vector<4, U> const& vector);
		template<typename U>
		Vector<4, T>& operator/=(U scalar);
		template<typename U>
		Vector<4, T>& operator/=(Vector<4, U> const& vector);
		T x, y, z, w;
	};
	template<typename T>
	 Vector<4, T> operator+(Vector<4, T> const& vector, T scalar);
	template<typename T>
	 Vector<4, T> operator+(T scalar, Vector<4, T> const& v);
	template<typename T>
	 Vector<4, T> operator+(Vector<4, T> const& vector1, Vector<4, T> const& vector2);
	template<typename T>
	 Vector<4, T> operator-(Vector<4, T> const& vector, T scalar);
	template<typename T>
	 Vector<4, T> operator-(T scalar, Vector<4, T> const& vector);
	template<typename T>
	 Vector<4, T> operator-(Vector<4, T> const& vector1, Vector<4, T> const& vector2);
	template<typename T>
	 Vector<4, T> operator*(Vector<4, T> const& vector, T scalar);
	template<typename T>
	 Vector<4, T> operator*(T scalar, Vector<4, T> const& vector);
	template<typename T>
	 Vector<4, T> operator*(Vector<4, T> const& vector1, Vector<4, T> const& vector2);
	template<typename T>
	 Vector<4, T> operator/(Vector<4, T> const& vector, T scalar);
	template<typename T>
	 Vector<4, T> operator/(T scalar, Vector<4, T> const& vector);
	template<typename T>
	 Vector<4, T> operator/(Vector<4, T> const& vector1, Vector<4, T> const& vector2);

	//========================================= Function =========================================
	template<typename T>
	 T dot(Vector<2, T> const& vector1, Vector<2, T> const& vector2);
	template<typename T>
	 T dot(Vector<3, T> const& vector1, Vector<3, T> const& vector2);
	template<typename T>
	 T dot(Vector<4, T> const& vector1, Vector<4, T> const& vector2);
	template<size_t S, typename T>
	 T length(Vector<S, T> const& vector);
	template<size_t S, typename T>
	 T distance(Vector<S, T> const& vector1, Vector<S, T> const& vector2);


	template<size_t S, typename T>
	 Vector<2, T> normalize(Vector<S, T> vector);
	
	//========================================= Type Define =========================================
	 typedef Vector<2, float> NACY_API Vector2F;
	 typedef Vector<2, double> NACY_API Vector2D;
	 typedef Vector<3, float> NACY_API Vector3F;
	 typedef Vector<3, double> NACY_API Vector3D;
	 typedef Vector<4, float> NACY_API Vector4F;
	 typedef Vector<4, double> NACY_API Vector4D;

	 typedef Vector4F NACY_API RGBA;
	 typedef Vector3F NACY_API RGB;

	
}


