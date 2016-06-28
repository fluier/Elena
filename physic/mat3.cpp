#include"mat3.h"

#include"mat2.h"

namespace Adina {
	mat3::mat3():
		m00(0), m01(0), m02(0),
		m10(0), m11(0), m12(0),
		m20(0), m21(0), m22(0)
	{
	}
	mat3::mat3(
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22) :
		m00(m00), m01(m01), m02(m02),
		m10(m10), m11(m11), m12(m12),
		m20(m20), m21(m21), m22(m22)
	{
	}
	void mat3::addTo(const mat3 b)
	{
		m00 += b.m00; m01 += b.m01; m02 += b.m02;
		m10 += b.m10; m11 += b.m11; m12 += b.m12;
		m20 += b.m20; m21 += b.m21; m22 += b.m22;
	}
	void mat3::setIdentity()
	{
		m00 = 1; m01 = 0; m02 = 0;
		m10 = 0; m11 = 1; m12 = 0;
		m20 = 0; m21 = 0; m22 = 1;
	}
	float mat3::determinant()
	{
		return m00*m11*m22 + m01*m12*m20 + m02*m10*m21 - 
			(m02*m11*m20)-(m01*m10*m22)-(m00*m12*m21);
	}
	float mat3::determinant2()
	{
		mat2 a(m11,m12,m21,m22);
		float det1 = m00 * a.determinant();

		mat2 b(m10, m12, m20, m22);
		float det2 = m01 * b.determinant();

		mat2 c(m10, m11, m20, m21);
		float det3 = m02 * c.determinant();

		return (-1)*det1 + (1)*det2 + (-1)*det3;
	}
	mat3 mat3::operator=(const mat3 & b)
	{
		return mat3();
	}
	mat3 mat3::operator+(const mat3 & b)
	{
		return mat3(
			m00 + b.m00, m01 + b.m01, m02 + b.m02,
			m10 + b.m10, m11 + b.m11, m12 + b.m12,
			m20 + b.m20, m21 + b.m21, m22 + b.m22);
	}
	mat3 mat3::operator*(const mat3 & b)
	{
		return mat3(m00*b.m00 + m01*b.m10 + m02*b.m20, m00*b.m01 + m01*b.m11 + m02*b.m21, m00*b.m02 + m01*b.m12 + m02*b.m22,
					m10*b.m00 + m11*b.m10 + m12*b.m20, m10*b.m01 + m11*b.m11 + m12*b.m21, m10*b.m02 + m11*b.m12 + m12*b.m22,
					m20*b.m00 + m21*b.m10 + m22*b.m20, m20*b.m01 + m21*b.m11 + m22*b.m21, m20*b.m02 + m21*b.m12 + m22*b.m22);
	}
	std::ostream & operator<<(std::ostream & output, const mat3 & m)
	{
		output << m.m00 << ", " << m.m01 << ", " << m.m02 << std::endl;
		output << m.m10 << ", " << m.m11 << ", " << m.m12 << std::endl;
		output << m.m20 << ", " << m.m21 << ", " << m.m22 << std::endl;
		return output;
	}
}