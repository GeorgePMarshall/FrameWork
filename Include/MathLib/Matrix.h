#ifndef Matrix_H
#define Matrix_H
#include "Vector.h"
#include "Math.h"

namespace MathLib
{
	///////////////////////////
	//Mat 2
	//////////////////////////
	class Mat2
	{
		//make union
		union
		{
			float mm_matrix[2][2];
			float m_matrix[4];
		};
		

	public:
		Mat2();

		void Zero();
		float* GetArray();

		float* operator [] (int index);
		Mat2 operator + (Mat2 &other) const;
		Mat2 operator - (Mat2 &other) const;
		Mat2 operator * (Mat2 &other) const;
		Mat2& operator = (Mat2 &other);
		Mat2& operator += (Mat2 &other);
		Mat2& operator -= (Mat2 &other);
		Mat2& operator *= (Mat2 &other);
		bool operator == (Mat2 &other) const;

		Vector2 operator * (Vector2 &other) const;
	};
	

	///////////////////////////
	//Mat 3
	//////////////////////////
	class Mat3
	{
		union
		{
			float mm_matrix[3][3];
			float m_matrix[9];
		};

	public:
		Mat3();

		void Zero();
		float* GetArray();

		float* operator [] (int index);
		Mat3 operator + (Mat3 &other) const;
		Mat3 operator - (Mat3 &other) const;
		Mat3 operator * (Mat3 &other) const;
		Mat3& operator = (Mat3 &other);
		Mat3& operator += (Mat3 &other);
		Mat3& operator -= (Mat3 &other);
		Mat3& operator *= (Mat3 &other);
		bool operator == (Mat3 &other) const;

		Vector3 operator * (Vector3 &other) const;
	};


	///////////////////////////
	//Mat 4
	//////////////////////////
	class Mat4
	{
		union
		{
			float mm_matrix[4][4];
			float m_matrix[16];
		};

	public:
		Mat4();

		void Zero();
		float* GetArray();

		float* operator [] (int index);
		Mat4 operator + (Mat4 &other) const;
		Mat4 operator - (Mat4 &other) const;
		Mat4 operator * (Mat4 &other) const;
		Mat4& operator = (Mat4 &other);
		Mat4& operator += (Mat4 &other);
		Mat4& operator -= (Mat4 &other);
		Mat4& operator *= (Mat4 &other);
		bool operator == (Mat4 &other) const;

		Vector4 operator * (Vector4 &other) const;
	};
	

	///////////////////////////
	//Matrix functions
	//////////////////////////


	Mat3 translate(Mat3 matrix, Vector2 translation);
	Mat3 rotate(Mat3 matrix, float degrees);
	Mat3 scale(Mat3 matrix, Vector2 scale);

	Mat4 translate(Mat4 matrix, Vector3 translation);
	Mat4 rotate(Mat4 matrix, float rotation, Vector3 rotationalAxis);
	Mat4 scale(Mat4 matrix, Vector3 scale);
	Mat4 ortho(float left, float right, float bottom, float top, float near, float far);

	typedef Mat2 mat2;
	typedef Mat3 mat3;
	typedef Mat4 mat4;
}



#endif

