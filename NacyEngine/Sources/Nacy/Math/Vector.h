#pragma once

#include "Nacy/Core/Core.h"

namespace Nacy {

    struct NACY_API Vector2 {
    public:
        explicit Vector2() : x(0.0f), y(0.0f) {}

        explicit Vector2(float x, float y) : x(x), y(y) {}

        static Vector2 create(float x, float y);

        Vector2 &operator=(Vector2 const &vector);

        Vector2 &operator+=(float scalar);

        Vector2 &operator+=(Vector2 const &vector);

        Vector2 &operator-=(float scalar);

        Vector2 &operator-=(Vector2 const &vector);

        Vector2 &operator*=(float scalar);

        Vector2 &operator*=(Vector2 const &vector);

        Vector2 &operator/=(float scalar);

        Vector2 &operator/=(Vector2 const &vector);

        float x, y;
    };
    //========================================= Vector2 =========================================

    NACY_API Vector2 operator+(Vector2 const &vector, float scalar);

    NACY_API Vector2 operator+(float scalar, Vector2 const &v);

    NACY_API Vector2 operator+(Vector2 const &vector1, Vector2 const &vector2);

    NACY_API Vector2 operator-(Vector2 const &vector, float scalar);

    NACY_API Vector2 operator-(float scalar, Vector2 const &vector);

    NACY_API Vector2 operator-(Vector2 const &vector1, Vector2 const &vector2);

    NACY_API Vector2 operator*(Vector2 const &vector, float scalar);

    NACY_API Vector2 operator*(float scalar, Vector2 const &vector);

    NACY_API Vector2 operator*(Vector2 const &vector1, Vector2 const &vector2);

    NACY_API Vector2 operator/(Vector2 const &vector, float scalar);

    NACY_API Vector2 operator/(float scalar, Vector2 const &vector);

    NACY_API Vector2 operator/(Vector2 const &vector1, Vector2 const &vector2);

    //========================================= Vector3 =========================================


    struct NACY_API Vector3 {
    public:
        explicit Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

        explicit Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

        static Vector3 create(float x, float y, float z);

        Vector3 &operator=(Vector3 const &vector);

        Vector3 &operator+=(float scalar);

        Vector3 &operator+=(Vector3 const &vector);

        Vector3 &operator-=(float scalar);

        Vector3 &operator-=(Vector3 const &vector);

        Vector3 &operator*=(float scalar);

        Vector3 &operator*=(Vector3 const &vector);

        Vector3 &operator/=(float scalar);

        Vector3 &operator/=(Vector3 const &vector);

        float x, y, z;
    };


    NACY_API Vector3 operator+(Vector3 const &vector, float scalar);

    NACY_API Vector3 operator+(float scalar, Vector3 const &v);

    NACY_API Vector3 operator+(Vector3 const &vector1, Vector3 const &vector2);

    NACY_API Vector3 operator-(Vector3 const &vector, float scalar);

    NACY_API Vector3 operator-(float scalar, Vector3 const &vector);

    NACY_API Vector3 operator-(Vector3 const &vector1, Vector3 const &vector2);

    NACY_API Vector3 operator*(Vector3 const &vector, float scalar);

    NACY_API Vector3 operator*(float scalar, Vector3 const &vector);

    NACY_API Vector3 operator*(Vector3 const &vector1, Vector3 const &vector2);

    NACY_API Vector3 operator/(Vector3 const &vector, float scalar);

    NACY_API Vector3 operator/(float scalar, Vector3 const &vector);

    NACY_API Vector3 operator/(Vector3 const &vector1, Vector3 const &vector2);

    //========================================= Vector4 =========================================

    struct NACY_API Vector4 {
    public:
        explicit Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

        explicit Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        static Vector4 create(float x, float y, float z, float w);

        Vector4 &operator=(Vector4 const &vector);

        Vector4 &operator+=(float scalar);

        Vector4 &operator+=(Vector4 const &vector);

        Vector4 &operator-=(float scalar);

        Vector4 &operator-=(Vector4 const &vector);

        Vector4 &operator*=(float scalar);

        Vector4 &operator*=(Vector4 const &vector);

        Vector4 &operator/=(float scalar);

        Vector4 &operator/=(Vector4 const &vector);

        float x, y, z, w;
    };

    NACY_API Vector4 operator+(Vector4 const &vector, float scalar);

    NACY_API Vector4 operator+(float scalar, Vector4 const &v);

    NACY_API Vector4 operator+(Vector4 const &vector1, Vector4 const &vector2);

    NACY_API Vector4 operator-(Vector4 const &vector, float scalar);

    NACY_API Vector4 operator-(float scalar, Vector4 const &vector);

    NACY_API Vector4 operator-(Vector4 const &vector1, Vector4 const &vector2);

    NACY_API Vector4 operator*(Vector4 const &vector, float scalar);

    NACY_API Vector4 operator*(float scalar, Vector4 const &vector);

    NACY_API Vector4 operator*(Vector4 const &vector1, Vector4 const &vector2);

    NACY_API Vector4 operator/(Vector4 const &vector, float scalar);

    NACY_API Vector4 operator/(float scalar, Vector4 const &vector);

    NACY_API Vector4 operator/(Vector4 const &vector1, Vector4 const &vector2);

    //========================================= Function =========================================

    NACY_API float dot(Vector2 const &vector1, Vector2 const &vector2);

    NACY_API float dot(Vector3 const &vector1, Vector3 const &vector2);

    NACY_API float dot(Vector4 const &vector1, Vector4 const &vector2);

    NACY_API float length(Vector2 const &vector);

    NACY_API float length(Vector3 const &vector);

    NACY_API float length(Vector4 const &vector);

    NACY_API float distance(Vector2 const &vector1, Vector2 const &vector2);

    NACY_API float distance(Vector3 const &vector1, Vector3 const &vector2);

    NACY_API float distance(Vector4 const &vector1, Vector4 const &vector2);

    NACY_API Vector2 normalize(Vector2 vector);

    NACY_API Vector3 normalize(Vector3 vector);

    NACY_API Vector4 normalize(Vector4 vector);

    //========================================= Type Define =========================================
    struct NACY_API RGBA {
        RGBA();

        RGBA(float color);

        RGBA(float red, float green, float blue, float alpha);

        float red, green, blue, alpha;
    };

}


