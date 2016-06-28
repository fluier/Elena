#include"mat2.h"
namespace Adina {

	mat2::mat2():
		m00(0), m01(0),
		m10(0), m11(0)
	{
	}
	mat2::mat2(float m00, float m01, float m10, float m11):
		m00(m00), m01(m01),
		m10(m10), m11(m11)
	{
	}
	void mat2::addTo(const mat2 b)
	{
		m00 += b.m00; m01 += b.m01;
		m10 += b.m10; m11 += b.m11;
	}
	void mat2::setIdentity()
	{
		m00 = 1; m01 = 0;
		m10 = 0, m11 = 1;
	}
	float mat2::determinant()
	{
		return m00 * m11 - m10 * m01;
	}
	mat2 mat2::adj()
	{
		return mat2(m11,-m01,-m10,m00);
	}
	mat2 mat2::adj(const float s)
	{
		return mat2(m11*s, -m01*s, -m10*s, m00*s);
	}
	mat2 mat2::inv()
	{
		float det = determinant();
		if(det != 0){
			return adj(det);
		}
		else {
			return mat2();
		}
	}
	mat2 mat2::operator*(const mat2 & b)
	{
		return mat2((m00*b.m00 + m01*b.m10), (m00*b.m01 + m01*b.m11),
					(m10*b.m00 + m11*b.m10), (m10*b.m01 + m11*b.m11));
	}
	mat2 mat2::operator=(const mat2 & b)
	{
		m00 = b.m00;	m01 = b.m01;
		m10 = b.m10;	m11 = b.m11;
		return *this;
	}
	std::ostream & operator<<(std::ostream & output, const mat2 & m)
	{
		output << m.m00 << ", " << m.m01 << std::endl;
		output << m.m10 << ", " << m.m11 << std::endl;
		return output;
	}
}