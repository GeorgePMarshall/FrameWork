#ifndef VECTOR_H
#define VECTOR_H
#include "math.h"

namespace MathLib
{
	class Vector2
	{
	public:

		union { float x, r; };
		union { float y, g; };

		Vector2();
		Vector2(float x, float y);

		float& operator [] (int index);
		bool operator == (const Vector2 &other) const;
		Vector2 operator + (const Vector2 &other) const;
		Vector2 operator - (const Vector2 &other) const;
		Vector2 operator * (const float &other) const;
		Vector2& operator += (const Vector2 &other);
		Vector2& operator -= (const Vector2 &other);
		Vector2& operator *= (const float &other);
		Vector2& operator = (const Vector2 &other);

		float Magnitude() const;
		void Normalize();
	};


	class Vector3
	{
	public:

		union { float x, r; };
		union { float y, g; };
		union { float z, b; };

		Vector3();
		Vector3(float x, float y, float z);

		float& operator [] (int index);
		bool operator == (const Vector3 &other) const;
		Vector3 operator + (const Vector3 &other) const;
		Vector3 operator - (const Vector3 &other) const;
		Vector3 operator * (const float &other) const;
		Vector3& operator += (const Vector3 &other);
		Vector3& operator -= (const Vector3 &other);
		Vector3& operator *= (const float &other);
		Vector3& operator = (const Vector3 &other);

		float Magnitude() const;
		void Normalize();
	};

	class Vector4
	{
	public:

		union { float x, r; };
		union { float y, g; };
		union { float z, b; };
		union { float w, a; };

		Vector4();
		Vector4(float x, float y, float z, float w);

		float& operator [] (int index);
		bool operator == (const Vector4 &other) const;
		Vector4 operator + (const Vector4 &other) const;
		Vector4 operator - (const Vector4 &other) const;
		Vector4 operator * (const float &other) const;
		Vector4& operator += (const Vector4 &other);
		Vector4& operator -= (const Vector4 &other);
		Vector4& operator *= (const float &other);
		Vector4& operator = (const Vector4 &other);

		float Magnitude() const;
		void Normalize();
	};

	Vector2 operator * (const float &lhs, const Vector2 &rhs);
	Vector3 operator * (const float &lhs, const Vector3 &rhs);
	Vector4 operator * (const float &lhs, const Vector4 &rhs);

	float Dot(const Vector2 &input, const Vector2 &input2);
	float Dot(const Vector3 &input, const Vector3 &input2);
	float Dot(const Vector4 &input, const Vector4 &input2);

	Vector3 Cross(const Vector3 &input, const Vector3 &input2);
	Vector4 Cross(const Vector4 &input, const Vector4 &input2);

	float Magnitude(const Vector2 &input);
	float Magnitude(const Vector3 &input);
	float Magnitude(const Vector4 &input);

	Vector2 Normalize(const Vector2 &input);
	Vector3 Normalize(const Vector3 &input);
	Vector4 Normalize(const Vector4 &input);

	typedef Vector2 vec2;
	typedef Vector3 vec3;
	typedef Vector4 vec4;

}
#endif