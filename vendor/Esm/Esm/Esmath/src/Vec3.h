#pragma once

#include <cassert>
#include <cmath>
#include <iostream>

namespace Esm {

	struct Vec3
	{

		float x;
		float y;
		float z;

		Vec3();

		Vec3(float xc, float yc, float zc);

		Vec3(const Vec3& u);

		Vec3& operator=(const Vec3 &u);

		Vec3 operator+(const Vec3& u);

		Vec3& operator+=(const Vec3 &u);

		Vec3 operator-(const Vec3& u);

		Vec3& operator-=(const Vec3 &u);

		Vec3 operator*(const Vec3& u);

		Vec3& operator*=(const Vec3& u);

		Vec3 operator*(const float& Scale);

		Vec3& operator*=(const float& Scale);

		Vec3 operator/(const float& Scale);

		Vec3& operator/=(const float& Scale);

		Vec3 operator- ();

		bool operator==(Vec3& u);

		bool operator!=(Vec3& u);

		void Normalize();
	};

	Vec3 CrossProduct(const Vec3& lhs, const Vec3& rhs);
	
    Vec3 Scale(const float Scalar, const Vec3& rhs);

    float Distance(const Vec3& lhs, const Vec3& rhs);
	
}
