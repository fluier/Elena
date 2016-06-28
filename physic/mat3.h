#pragma once

#include<iostream>

namespace Adina {
	struct mat3 {
		float m00, m01, m02;
		float m10, m11, m12;
		float m20, m21, m22;
		mat3();
		mat3(
			float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22);
		void addTo(const mat3 b);
		void setIdentity();
		float determinant();
		float determinant2();

		mat3 operator=(const mat3& b);
		mat3 operator+(const mat3& b);
		mat3 operator*(const mat3& b);

		friend std::ostream &operator<<(std::ostream &output, const mat3& m);
	};
}