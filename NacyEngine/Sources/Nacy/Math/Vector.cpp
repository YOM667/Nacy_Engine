#include "pch.h"
#include <cmath>
#include "Vector.h"

namespace Nacy
{
	// ============================= Vector2 =============================

	Vector2& Vector2::operator=(Vector2 const& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		return *this;
	}

	Vector2 Vector2::create(float x, float y)
	{
		return Vector2(x,y);
	}

	Vector2& Vector2::operator+=(float scalar)
	{
		this->x += scalar;
		this->y += scalar;
		return *this;
	}

	Vector2& Vector2::operator+=(Vector2 const& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}
	Vector2& Vector2::operator-=(float scalar)
	{
		this->x -= scalar;
		this->y -= scalar;
		return *this;
	}
	Vector2& Vector2::operator-=(Vector2 const& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	Vector2& Vector2::operator*=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}

	Vector2& Vector2::operator*=(Vector2 const& vector)
	{
		this->x *= vector.x;
		this->y *= vector.y;
		return *this;
	}

	Vector2& Vector2::operator/=(float scalar)
	{
		this->x /= scalar;
		this->y /= scalar;
		return *this;
	}

	Vector2& Vector2::operator/=(Vector2 const& vector)
	{
		this->x /= vector.x;
		this->y /= vector.y;
		return *this;
	}

	Vector2 operator+(Vector2 const& vector, float scalar)
	{
		return Vector2(vector.x + scalar,vector.y + scalar);
	}

	Vector2 operator+(float scalar, Vector2 const& vector)
	{
		return Vector2(vector.x + scalar, vector.y + scalar);
	}

	
	Vector2 operator+(Vector2 const& vector1, Vector2 const& vector2)
	{
		return Vector2(vector1.x + vector2.x, vector1.y + vector2.y);
	}

	
	Vector2 operator-(Vector2 const& vector, float scalar)
	{
		return Vector2(vector.x - scalar, vector.y - scalar);
	}

	
	Vector2 operator-(float scalar, Vector2 const& vector)
	{
		return Vector2(vector.x - scalar, vector.y - scalar);
	}

	
	Vector2 operator-(Vector2 const& vector1, Vector2 const& vector2)
	{
		return Vector2(vector1.x - vector2.x, vector1.y - vector2.y);
	}

	
	Vector2 operator*(Vector2 const& vector, float scalar)
	{
		return Vector2(vector.x * scalar, vector.y * scalar);
	}

	
	Vector2 operator*(float scalar, Vector2 const& vector)
	{
		return Vector2(vector.x * scalar, vector.y * scalar);
	}

	
	Vector2 operator*(Vector2 const& vector1, Vector2 const& vector2)
	{
		return Vector2(vector1.x * vector2.x, vector1.y * vector2.y);
	}

	
	Vector2 operator/(Vector2 const& vector, float scalar)
	{
		return Vector2(vector.x / scalar, vector.y / scalar);
	}

	
	Vector2 operator/(float scalar, Vector2 const& vector)
	{
		return Vector2(vector.x / scalar, vector.y / scalar);
	}

	
	Vector2 operator/(Vector2 const& vector1, Vector2 const& vector2)
	{
		return Vector2(vector1.x / vector2.x, vector1.y / vector2.y);
	}


	// ============================= Vector3 =============================

	Vector3 Vector3::create(float x, float y, float z)
	{
		return Vector3(x, y, z);
	}

	Vector3& Vector3::operator=(Vector3 const& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		return *this;
	}

	Vector3& Vector3::operator+=(float scalar)
	{
		this->x += scalar;
		this->y += scalar;
		this->z += scalar;
		return *this;
	}

	Vector3& Vector3::operator+=(Vector3 const& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}

	Vector3& Vector3::operator-=(float scalar)
	{
		this->x -= scalar;
		this->y -= scalar;
		this->z -= scalar;
		return *this;
	}

	Vector3& Vector3::operator-=(Vector3 const& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}

	Vector3& Vector3::operator*=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}

	Vector3& Vector3::operator*=(Vector3 const& vector)
	{
		this->x *= vector.x;
		this->y *= vector.y;
		this->z *= vector.z;
		return *this;
	}

	Vector3& Vector3::operator/=(float scalar)
	{
		this->x /= scalar;
		this->y /= scalar;
		this->z /= scalar;
		return *this;
	}

	Vector3& Vector3::operator/=(Vector3 const& vector)
	{
		this->x /= vector.x;
		this->y /= vector.y;
		this->z /= vector.z;
		return *this;
	}

	
	Vector3 operator+(Vector3 const& vector, float scalar)
	{
		return Vector3(vector.x + scalar, vector.y + scalar, vector.z + scalar);
	}

	
	Vector3 operator+(float scalar, Vector3 const& vector)
	{
		return Vector3(vector.x + scalar, vector.y + scalar, vector.z + scalar);
	}

	
	Vector3 operator+(Vector3 const& vector1, Vector3 const& vector2)
	{
		return Vector3(vector1.x + vector2.x, vector1.y + vector2.y , vector1.z + vector2.z);
	}

	
	Vector3 operator-(Vector3 const& vector, float scalar)
	{
		return Vector3(vector.x - scalar, vector.y - scalar, vector.z - scalar);
	}

	
	Vector3 operator-(float scalar, Vector3 const& vector)
	{
		return Vector3(vector.x - scalar, vector.y - scalar, vector.z - scalar);
	}

	
	Vector3 operator-(Vector3 const& vector1, Vector3 const& vector2)
	{
		return Vector3(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
	}

	
	Vector3 operator*(Vector3 const& vector, float scalar)
	{
		return Vector3(vector.x * scalar, vector.y * scalar, vector.z * scalar);
	}

	
	Vector3 operator*(float scalar, Vector3 const& vector)
	{
		return Vector3(vector.x * scalar, vector.y * scalar, vector.z * scalar);
	}

	
	Vector3 operator*(Vector3 const& vector1, Vector3 const& vector2)
	{
		return Vector3(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
	}

	
	Vector3 operator/(Vector3 const& vector, float scalar)
	{
		return Vector3(vector.x / scalar, vector.y / scalar, vector.z / scalar);
	}

	
	Vector3 operator/(float scalar, Vector3 const& vector)
	{
		return Vector3(vector.x / scalar, vector.y / scalar, vector.z / scalar);
	}

	
	Vector3 operator/(Vector3 const& vector1, Vector3 const& vector2)
	{
		return Vector3(vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z);
	}
	// ============================= Vector4 =============================
	Vector4 Vector4::create(float x, float y, float z, float w)
	{
		return Vector4(x, y, z, w);
	}
	
	Vector4& Vector4::operator=(Vector4 const& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		this->w = vector.w;
		return *this;
	}

	Vector4& Vector4::operator+=(float scalar)
	{
		this->x += scalar;
		this->y += scalar;
		this->z += scalar;
		this->w += scalar;
		return *this;
	}

	Vector4& Vector4::operator+=(Vector4 const& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		this->w += vector.w;
		return *this;
	}

	Vector4& Vector4::operator-=(float scalar)
	{
		this->x -= scalar;
		this->y -= scalar;
		this->z -= scalar;
		this->w -= scalar;
		return *this;
	}
	

	Vector4& Vector4::operator-=(Vector4 const& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		this->w -= vector.w;
		return *this;
	}

	Vector4& Vector4::operator*=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
		return *this;
	}

	Vector4& Vector4::operator*=(Vector4 const& vector)
	{
		this->x *= vector.x;
		this->y *= vector.y;
		this->z *= vector.z;
		this->w *= vector.w;
		return *this;
	}

	Vector4& Vector4::operator/=(float scalar)
	{
		this->x /= scalar;
		this->y /= scalar;
		this->z /= scalar;
		this->w /= scalar;
		return *this;
	}

	Vector4& Vector4::operator/=(Vector4 const& vector)
	{
		this->x /= vector.x;
		this->y /= vector.y;
		this->z /= vector.z;
		this->w /= vector.w;
		return *this;
	}

	
	Vector4 operator+(Vector4 const& vector, float scalar)
	{
		return Vector4(vector.x + scalar, vector.y + scalar, vector.z + scalar, vector.w + scalar);
	}

	
	Vector4 operator+(float scalar, Vector4 const& vector)
	{
		return Vector4(vector.x + scalar, vector.y + scalar, vector.z + scalar, vector.w + scalar);
	}

	
	Vector4 operator+(Vector4 const& vector1, Vector4 const& vector2)
	{
		return Vector4(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z, vector1.w + vector2.w);
	}

	
	Vector4 operator-(Vector4 const& vector, float scalar)
	{
		return Vector4(vector.x - scalar, vector.y - scalar, vector.z - scalar, vector.w - scalar);
	}

	
	Vector4 operator-(float scalar, Vector4 const& vector)
	{
		return Vector4(vector.x - scalar, vector.y - scalar, vector.z - scalar, vector.w - scalar);
	}

	
	Vector4 operator-(Vector4 const& vector1, Vector4 const& vector2)
	{
		return Vector4(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z, vector1.w - vector2.w);
	}

	
	Vector4 operator*(Vector4 const& vector, float scalar)
	{
		return Vector4(vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar);
	}

	
	Vector4 operator*(float scalar, Vector4 const& vector)
	{
		return Vector4(vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar);
	}

	
	Vector4 operator*(Vector4 const& vector1, Vector4 const& vector2)
	{
		return Vector4(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z, vector1.w * vector2.w);
	}

	
	Vector4 operator/(Vector4 const& vector, float scalar)
	{
		return Vector4(vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar);
	}

	
	Vector4 operator/(float scalar, Vector4 const& vector)
	{
		return Vector4(vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar);
	}

	
	Vector4 operator/(Vector4 const& vector1, Vector4 const& vector2)
	{

		return Vector4(vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z, vector1.w / vector2.w);
	}


	
	float dot(Vector2 const& vector1, Vector2 const& vector2)
	{
		Vector2 vec = vector1 * vector2;
		return vec.x + vec.y;
	}
	
	float dot(Vector3 const& vector1, Vector3 const& vector2)
	{
		Vector3 vec = vector1 * vector2;
		return vec.x + vec.y + vec.z;
	}
	
	float dot(Vector4 const& vector1, Vector4 const& vector2)
	{
		Vector4 vec = vector1 * vector2;
		return (vec.x + vec.y) + (vec.z + vec.w);
	}
	float length(Vector2 const& vector)
	{
		return sqrt(dot(vector, vector));
	}
	float length(Vector3 const& vector)
	{
		return sqrt(dot(vector, vector));
	}
	float length(Vector4 const& vector)
	{
		return sqrt(dot(vector, vector));
	}

	float distance(Vector2 const& vector1, Vector2 const& vector2)
	{
		return length(vector1 - vector2);
	}
	float distance(Vector3 const& vector1, Vector3 const& vector2)
	{
		return length(vector1 - vector2);
	}
	float distance(Vector4 const& vector1, Vector4 const& vector2)
	{
		return length(vector1 - vector2);
	}

	Vector2 normalize(Vector2 vector)
	{
		return vector * 1.0f / sqrt(dot(vector, vector));
	}
	Vector3 normalize(Vector3 vector)
	{
		return vector * 1.0f / sqrt(dot(vector, vector));
	}
	Vector4 normalize(Vector4 vector)
	{
		return vector * 1.0f / sqrt(dot(vector, vector));
	}
	RGBA::RGBA()
		: red(0.0f), green(0.0f), blue(0.0f), alpha(0.0f) {}
	RGBA::RGBA(float color) : red(color), green(color), blue(color), alpha(color)
	{
	}
	RGBA::RGBA(float red, float green, float blue, float alpha)
		: red(red), green(green), blue(blue), alpha(alpha) {}

}