#include "pch.h"
#include "Vector.h"

namespace Engine
{
	// ============================= Vector2 =============================
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator=(Vector<2, U> const& vector)
	{
		this->x = static_cast<U>(vector.x);
		this->y = static_cast<U>(vector.y);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator+=(Vector<2, U> const& vector)
	{
		this->x += static_cast<T>(vector.x);
		this->y += static_cast<T>(vector.y);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}
	template<typename T>
	template<typename U>
	Vector<2, T>& Vector<2, T>::operator-=(Vector<2, U> const& vector)
	{
		this->x -= static_cast<T>(vector.x);
		this->y -= static_cast<T>(vector.y);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator*=(Vector<2, U> const& vector)
	{
		this->x *= static_cast<T>(vector.x);
		this->y *= static_cast<T>(vector.y);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<2, T>& Vector<2, T>::operator/=(Vector<2, U> const& vector)
	{
		this->x /= static_cast<T>(vector.x);
		this->y /= static_cast<T>(vector.y);
		return *this;
	}


	template<typename T>
	Vector<2, T> operator+(Vector<2, T> const& vector, T scalar)
	{
		return Vector<2, T>(vector.x + scalar,vector.y + scalar);
	}

	template<typename T>
	Vector<2, T> operator+(T scalar, Vector<2, T> const& vector)
	{
		return Vector<2, T>(vector.x + scalar, vector.y + scalar);
	}

	template<typename T>
	Vector<2, T> operator+(Vector<2, T> const& vector1, Vector<2, T> const& vector2)
	{
		return Vector<2, T>(vector1.x + vector2.x, vector1.y + vector2.y);
	}

	template<typename T>
	Vector<2, T> operator-(Vector<2, T> const& vector, T scalar)
	{
		return Vector<2, T>(vector.x - scalar, vector.y - scalar);
	}

	template<typename T>
	Vector<2, T> operator-(T scalar, Vector<2, T> const& vector)
	{
		return Vector<2, T>(vector.x - scalar, vector.y - scalar);
	}

	template<typename T>
	Vector<2, T> operator-(Vector<2, T> const& vector1, Vector<2, T> const& vector2)
	{
		return Vector<2, T>(vector1.x - vector2.x, vector1.y - vector2.y);
	}

	template<typename T>
	Vector<2, T> operator*(Vector<2, T> const& vector, T scalar)
	{
		return Vector<2, T>(vector.x * scalar, vector.y * scalar);
	}

	template<typename T>
	Vector<2, T> operator*(T scalar, Vector<2, T> const& vector)
	{
		return Vector<2, T>(vector.x * scalar, vector.y * scalar);
	}

	template<typename T>
	Vector<2, T> operator*(Vector<2, T> const& vector1, Vector<2, T> const& vector2)
	{
		return Vector<2, T>(vector1.x * vector2.x, vector1.y * vector2.y);
	}

	template<typename T>
	Vector<2, T> operator/(Vector<2, T> const& vector, T scalar)
	{
		return Vector<2, T>(vector.x / scalar, vector.y / scalar);
	}

	template<typename T>
	Vector<2, T> operator/(T scalar, Vector<2, T> const& vector)
	{
		return Vector<2, T>(vector.x / scalar, vector.y / scalar);
	}

	template<typename T>
	Vector<2, T> operator/(Vector<2, T> const& vector1, Vector<2, T> const& vector2)
	{
		return Vector<2, T>(vector1.x / vector2.x, vector1.y / vector2.y);
	}


	// ============================= Vector3 =============================
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator=(Vector<3, U> const& vector)
	{
		this->x = static_cast<T>(vector.x);
		this->y = static_cast<T>(vector.y);
		this->z = static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator+=(Vector<3, U> const& vector)
	{
		this->x += static_cast<T>(vector.x);
		this->y += static_cast<T>(vector.y);
		this->z += static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}
	template<typename T>
	template<typename U>
	Vector<3, T>& Vector<3, T>::operator-=(Vector<3, U> const& vector)
	{
		this->x -= static_cast<T>(vector.x);
		this->y -= static_cast<T>(vector.y);
		this->z -= static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator*=(Vector<3, U> const& vector)
	{
		this->x *= static_cast<T>(vector.x);
		this->y *= static_cast<T>(vector.y);
		this->z *= static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<3, T>& Vector<3, T>::operator/=(Vector<3, U> const& vector)
	{
		this->x /= static_cast<T>(vector.x);
		this->y /= static_cast<T>(vector.y);
		this->z /= static_cast<T>(vector.z);
		return *this;
	}

	template<typename T>
	Vector<3, T> operator+(Vector<3, T> const& vector, T scalar)
	{
		return Vector<3, T>(vector.x + scalar, vector.y + scalar, vector.z + scalar);
	}

	template<typename T>
	Vector<3, T> operator+(T scalar, Vector<3, T> const& vector)
	{
		return Vector<3, T>(vector.x + scalar, vector.y + scalar, vector.z + scalar);
	}

	template<typename T>
	Vector<3, T> operator+(Vector<3, T> const& vector1, Vector<3, T> const& vector2)
	{
		return Vector<3, T>(vector1.x + vector2.x, vector1.y + vector2.y , vector1.z + vector2.z);
	}

	template<typename T>
	Vector<3, T> operator-(Vector<3, T> const& vector, T scalar)
	{
		return Vector<3, T>(vector.x - scalar, vector.y - scalar, vector.z - scalar);
	}

	template<typename T>
	Vector<3, T> operator-(T scalar, Vector<3, T> const& vector)
	{
		return Vector<3, T>(vector.x - scalar, vector.y - scalar, vector.z - scalar);
	}

	template<typename T>
	Vector<3, T> operator-(Vector<3, T> const& vector1, Vector<3, T> const& vector2)
	{
		return Vector<3, T>(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
	}

	template<typename T>
	Vector<3, T> operator*(Vector<3, T> const& vector, T scalar)
	{
		return Vector<3, T>(vector.x * scalar, vector.y * scalar, vector.z * scalar);
	}

	template<typename T>
	Vector<3, T> operator*(T scalar, Vector<3, T> const& vector)
	{
		return Vector<3, T>(vector.x * scalar, vector.y * scalar, vector.z * scalar);
	}

	template<typename T>
	Vector<3, T> operator*(Vector<3, T> const& vector1, Vector<3, T> const& vector2)
	{
		return Vector<3, T>(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
	}

	template<typename T>
	Vector<3, T> operator/(Vector<3, T> const& vector, T scalar)
	{
		return Vector<3, T>(vector.x / scalar, vector.y / scalar, vector.z / scalar);
	}

	template<typename T>
	Vector<3, T> operator/(T scalar, Vector<3, T> const& vector)
	{
		return Vector<3, T>(vector.x / scalar, vector.y / scalar, vector.z / scalar);
	}

	template<typename T>
	Vector<3, T> operator/(Vector<3, T> const& vector1, Vector<3, T> const& vector2)
	{
		return Vector<3, T>(vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z);
	}
	// ============================= Vector4 =============================
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator=(Vector<4, U> const& vector)
	{
		this->x = static_cast<T>(vector.x);
		this->y = static_cast<T>(vector.y);
		this->z = static_cast<T>(vector.z);
		this->w = static_cast<T>(vector.w);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		this->w += static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator+=(Vector<4, U> const& vector)
	{
		this->x += static_cast<T>(vector.x);
		this->y += static_cast<T>(vector.y);
		this->z += static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}
	template<typename T>
	template<typename U>
	Vector<4, T>& Vector<4, T>::operator-=(Vector<4, U> const& vector)
	{
		this->x -= static_cast<T>(vector.x);
		this->y -= static_cast<T>(vector.y);
		this->z -= static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator*=(Vector<4, U> const& vector)
	{
		this->x *= static_cast<T>(vector.x);
		this->y *= static_cast<T>(vector.y);
		this->z *= static_cast<T>(vector.z);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	Vector<4, T>& Vector<4, T>::operator/=(Vector<4, U> const& vector)
	{
		this->x /= static_cast<T>(vector.x);
		this->y /= static_cast<T>(vector.y);
		this->z /= static_cast<T>(vector.z);
		return *this;
	}

	template<typename T>
	Vector<4, T> operator+(Vector<4, T> const& vector, T scalar)
	{
		return Vector<4, T>(vector.x + scalar, vector.y + scalar, vector.z + scalar, vector.w + scalar);
	}

	template<typename T>
	Vector<4, T> operator+(T scalar, Vector<4, T> const& vector)
	{
		return Vector<4, T>(vector.x + scalar, vector.y + scalar, vector.z + scalar, vector.w + scalar);
	}

	template<typename T>
	Vector<4, T> operator+(Vector<4, T> const& vector1, Vector<4, T> const& vector2)
	{
		return Vector<4, T>(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z, vector1.w + vector2.w);
	}

	template<typename T>
	Vector<4, T> operator-(Vector<4, T> const& vector, T scalar)
	{
		return Vector<4, T>(vector.x - scalar, vector.y - scalar, vector.z - scalar, vector.w - scalar);
	}

	template<typename T>
	Vector<4, T> operator-(T scalar, Vector<4, T> const& vector)
	{
		return Vector<4, T>(vector.x - scalar, vector.y - scalar, vector.z - scalar, vector.w - scalar);
	}

	template<typename T>
	Vector<4, T> operator-(Vector<4, T> const& vector1, Vector<4, T> const& vector2)
	{
		return Vector<4, T>(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z, vector1.w - vector2.w);
	}

	template<typename T>
	Vector<4, T> operator*(Vector<4, T> const& vector, T scalar)
	{
		return Vector<4, T>(vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar);
	}

	template<typename T>
	Vector<4, T> operator*(T scalar, Vector<4, T> const& vector)
	{
		return Vector<4, T>(vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar);
	}

	template<typename T>
	Vector<4, T> operator*(Vector<4, T> const& vector1, Vector<4, T> const& vector2)
	{
		return Vector<4, T>(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z, vector1.w * vector2.w);
	}

	template<typename T>
	Vector<4, T> operator/(Vector<4, T> const& vector, T scalar)
	{
		return Vector<4, T>(vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar);
	}

	template<typename T>
	Vector<4, T> operator/(T scalar, Vector<4, T> const& vector)
	{
		return Vector<4, T>(vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar);
	}

	template<typename T>
	Vector<4, T> operator/(Vector<4, T> const& vector1, Vector<4, T> const& vector2)
	{

		return Vector<4, T>(vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z, vector1.w / vector2.w);
	}


	template<typename T>
	T dot(Vector<2, T> const& vector1, Vector<2, T> const& vector2)
	{
		Vector<2, T> vec = vector1 * vector2;
		return vec.x + vec.y;
	}
	template<typename T>
	T dot(Vector<3, T> const& vector1, Vector<3, T> const& vector2)
	{
		Vector<3, T> vec = vector1 * vector2;
		return vec.x + vec.y + vec.z;
	}
	template<typename T>
	T dot(Vector<4, T> const& vector1, Vector<4, T> const& vector2)
	{
		Vector<3, T> vec = vector1 * vector2;
		return (vec.x + vec.y) + (vec.z + vec.w);
	}
	template<size_t S, typename T>
	T length(Vector<S, T> const& vector)
	{
		return sqrt(dot(vector, vector));
	}
	template<size_t S, typename T>
	T distance(Vector<S, T> const& vector1, Vector<S, T> const& vector2)
	{
		return length(vector1 - vector2);
	}


	template<size_t S, typename T>
	Vector<S, T> normalize(Vector<S, T> vector)
	{
		return vector * static_cast<T>(1) / sqrt(dot(vector, vector));
	}
}