#include "vec3.h"



#include<math.h>


#define PI 3.14159265

namespace Adina {

	vec3::vec3() :x(1), y(0), z(0) {
	}
	vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {

	}
	void vec3::init(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void vec3::normalise() {
		x = x / magnitude();
		y = y / magnitude();
		z = z / magnitude();
	}

	float vec3::magnitude()const
	{
		return (float)sqrt(x*x + y*y + z*z);
	}

	float vec3::distance(const vec3 & b) const
	{
		return (float)sqrt(pow((x - b.x), 2) + pow((y - b.y), 2) + pow((z - b.z), 2));
	}

	void vec3::add(const vec3& b) {
		x += b.x;
		y += b.y;
		z += b.z;
	}
	void vec3::sub(const vec3 & b)
	{
		x -= b.x;
		y -= b.y;
		z -= b.z;
	}
	void vec3::scale(const float& s)
	{
		x *= s;
		y *= s;
		z *= s;
	}
	float vec3::dot(const vec3& b) const {
		return ((x * b.x) + (y * b.y) + (z * b.z));
	}

	vec3 vec3::cross(const vec3 & b) const
	{
		float tx = y * b.z - z * b.y;
		float ty = z * b.x - x * b.z;
		float tz = x * b.y - y * b.x;
		return vec3(tx, ty, tz);
	}
	//α is the angle between u(unit vector) and the x - axis
	float vec3::alfaAngle()const {
		return (x / magnitude());
	}
	float vec3::alfaAngleDegree()const {
		return (float)(acos(x / magnitude()) * 180.0 / PI);
	}
	//β is the angle between u(unit vector) and the y-axis
	float vec3::betaAngle()const {
		return (y / magnitude());
	}
	float vec3::betaAngleDegree() const
	{
		return (float)(acos(y / magnitude()) * 180.0 / PI);
	}
	//γ is the angle between u(unit vector) and the z-axis
	float vec3::gamaAngle()const {
		return (z / magnitude());
	}

	float vec3::gamaAngleDegree()const {
		return (float)(acos(z / magnitude()) * 180.0 / PI);
	}
	float vec3::angle(const vec3& b)const {
		float d = dot(b);
		float m = magnitude() * b.magnitude();
		return (float)(acos(d / m) * 180.0 / PI);
	}
	vec3 vec3::operator+(const vec3& b)const {
		return vec3(x + b.x, y + b.y, z + b.z);
	}
	vec3 vec3::operator-(const vec3& b)const {
		return vec3(x - b.x, y - b.y, z - b.z);
	}
	vec3 vec3::operator=(const vec3& b)const {
		return vec3(b.x, b.y, b.z);
	}
	vec3 vec3::operator+=(const vec3& b) {
		add(b);
		return *this;
	}
	vec3 vec3::operator-=(const vec3& b) {
		sub(b);
		return *this;
	}

	bool vec3::operator==(const vec3 & b)const {
		return magnitude() == b.magnitude();
	}
	std::ostream &operator<<(std::ostream &output, const vec3& d) {
		output << d.x << ", " << d.y << ", " << d.z;
		return output;
	}
}