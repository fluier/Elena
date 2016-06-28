#pragma once

#include<iostream>
namespace Adina {

	struct vec2
	{
		float x;
		float y;

		vec2();
		vec2(float x, float y);
		void init(float x, float y);

		void normalise();

		float magnitude()const;
		float tangent();
		void add(const vec2& b);
		void sub(const vec2& b);
		void scale(const float& s);

		float dot(const vec2& b)const;
		float angleBetween(const vec2& b)const;

		vec2 operator+(const vec2& b)const;
		vec2 operator-(const vec2& b)const;
		vec2 operator=(const vec2& b)const;
		vec2 operator+=(const vec2& b);
		vec2 operator-=(const vec2& b);
		bool operator==(const vec2& b)const;

		friend std::ostream &operator<<(std::ostream &output, const vec2& d);
	};

}
