#include "mat4.h"

#include "mat3.h"

namespace Adina {
	mat4::mat4()
	{
	
	}
	mat4::~mat4()
	{

	}
	void mat4::setToZero()
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				val[i][j] = 0.0f;
			}
		}
	}
	void mat4::setIdentity()
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) val[i][j] = 1.0f;
				else val[i][j] = 0.0f;
			}
		}
	}
	mat4 mat4::operator=(const mat4 & b)
	{
		for (int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				val[i][j] = b.val[i][j];
			}
		}
		return *this;
	}
	mat4 mat4::operator*(const mat4 & b)
	{
		float sum = 0;
		mat4* rez = new mat4;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					sum = sum + val[i][k] * b.val[k][j];
				}
				rez->val[i][j] = sum;
				sum = 0;
			}
		}
		return *rez;
	}
	/******************************************************************
	1  0   0   0
	0 cos -sin 0
	0 sin cos  0
	0  0   0   1
	*/
	void mat4::rotX(float angle)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				val[i][j] = 0.0f;
			}
		}
		val[0][0] = 1;
		val[1][1] = cos(angle);
		val[1][2] = -sin(angle);
		val[2][1] = sin(angle);
		val[3][3] = cos(angle);
		val[4][4] = 1;
	}
	/******************************************************************
	 cos 0 sin 0
	  0  1  0  0
	-sin 0 cos 0
	  0  0  0  1
	*/
	void mat4::rotY(float angle)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				val[i][j] = 0.0f;
			}
		}
		val[0][0] = cos(angle);
		val[0][2] = sin(angle);
		val[2][0] = -sin(angle);
		val[2][2] = cos(angle);
		val[1][1] = 1;
		val[3][3] = 3;
	}
	/******************************************************************
	cos -sin 0 0
	sin  cos 0 0
	0     0  1 0
	0     0  0 1
	*/
	void mat4::rotZ(float angle)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				val[i][j] = 0.0f;
			}
		}
		val[0][0] = cos(angle);
		val[0][1] = -sin(angle);
		val[1][0] = sin(angle);
		val[1][1] = cos(angle);
		val[2][2] = 1;
		val[3][3] = 1;
	}
	std::ostream & operator<<(std::ostream & output, const mat4 & m)
	{
		for (int i = 0; i < 4; i++) {
			output << std::endl;
			for (int j = 0; j < 4; j++) {
				output << m.val[i][j] << "  ";
			}
		}
		return output;
	}
}
