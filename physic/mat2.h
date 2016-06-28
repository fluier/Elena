#pragma once

#include<iostream>

namespace Adina {
	struct mat2 {
		float m00, m01;
		float m10, m11;
		mat2();
		mat2(float m00, float m01, float m10, float m11);
		void addTo(const mat2 b);
		void setIdentity();
		float determinant();
		mat2 adj();
		mat2 adj(const float s);
		mat2 inv();
		mat2 operator*(const mat2& b);
		mat2 operator=(const mat2& b);
		friend std::ostream &operator<<(std::ostream &output, const mat2& m);
	};
}