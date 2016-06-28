#pragma once

#include<iostream>

namespace Adina {

	struct vec3
	{
		float x;
		float y;
		float z;

		vec3();
		vec3(float x, float y, float z);
		void init(float x, float y, float z);

		void normalise();

		float magnitude()const;
		float distance(const vec3& b)const;
		void add(const vec3& b);
		void sub(const vec3& b);
		void scale(const float& s);

		float dot(const vec3& b)const;
		vec3 cross(const vec3& b)const;

		float alfaAngle()const;
		float alfaAngleDegree()const;
		float betaAngle()const;
		float betaAngleDegree()const;
		float gamaAngle()const;
		float gamaAngleDegree()const;
		float angle(const vec3& b)const;

		vec3 operator+(const vec3& b)const;
		vec3 operator-(const vec3& b)const;
		vec3 operator=(const vec3& b)const;
		vec3 operator+=(const vec3& b);
		vec3 operator-=(const vec3& b);
		bool operator==(const vec3& b)const;

		friend std::ostream &operator<<(std::ostream &output, const vec3& d);
	};
}


