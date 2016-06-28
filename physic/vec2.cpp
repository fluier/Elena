#include "vec2.h"
#include<math.h>


#define PI 3.14159265
namespace Adina {

	vec2::vec2() {

	}
	vec2::vec2(float x, float y) :x(x), y(y) {

	}
	void vec2::init(float x, float y) {
		this->x = x;
		this->y = y;
	}

	void vec2::normalise() {

	}

	float vec2::magnitude()const
	{
		return (float)sqrt(x*x + y*y);
	}

	float vec2::tangent() {
		if (x != 0) return (y / x);
		else return 0;
	}
	void vec2::add(const vec2& b) {
		x += b.x;
		y += b.y;
	}
	void vec2::sub(const vec2 & b)
	{
		x -= b.x;
		y -= b.y;
	}
	void vec2::scale(const float & s)
	{
		x *= s;
		y *= s;
	}
	float vec2::dot(const vec2& b) const {
		return ((x * b.x) + (y * b.y));
	}
	float vec2::angleBetween(const vec2& b)const {
		return acos(dot(b) / (magnitude() * b.magnitude())) * 180.0 / PI;
	}
	vec2 vec2::operator+(const vec2& b)const {
		return vec2(x + b.x, y + b.y);
	}
	vec2 vec2::operator-(const vec2& b)const {
		return vec2(x - b.x, y - b.y);
	}
	vec2 vec2::operator=(const vec2& b)const {
		return vec2(b.x, b.y);
	}
	vec2 vec2::operator+=(const vec2& b) {
		x += b.x;
		y += b.y;
		return *this;
	}
	vec2 vec2::operator-=(const vec2& b) {
		x -= b.x;
		y -= b.y;
		return *this;
	}

	bool vec2::operator==(const vec2 & b)const {
		return magnitude() == b.magnitude();
	}
	std::ostream &operator<<(std::ostream &output, const vec2& d)
	{
		output << d.x << ", " << d.y;
		return output;
	}
}