#pragma once

#include<iostream>

namespace Adina {

	struct mat4
	{
		float val[4][4];

		mat4();
		~mat4();
		void setToZero();
		void setIdentity();
		mat4 operator=(const mat4& b);
		mat4 operator*(const mat4& b);
		void rotX(float angle);
		void rotY(float angle);
		void rotZ(float angle);
		friend std::ostream &operator<<(std::ostream &output, const mat4& m);
	};
}