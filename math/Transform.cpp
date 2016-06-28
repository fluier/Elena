#include "Transform.h"

namespace Adina {
	Transform::Transform()
	{
	}


	Transform::~Transform()
	{
	}
	mat4 Transform::viewMatrix(const vec3&, const vec3& lk, const vec3& up)
	{
		mat4 rez; rez.setToZero();
		return mat4();
	}
	/*****************************************************************
	SCALE ************************************************************
	x 0 0 0
	0 y 0 0
	0 0 z 0
	0 0 0 1
	*/
	mat4 Transform::scalMatrix(const vec3& s)
	{
		mat4* rez = new mat4; rez->setToZero();
		rez->val[0][0] = s.x;
		rez->val[1][1] = s.y;
		rez->val[2][2] = s.z;
		rez->val[3][3] = 1.0f;
		return *rez;
	}

	mat4 Transform::rotaMatrix()
	{
		mat4 rez; rez.setIdentity();

		return mat4();
	}
	/*************************************************************************************
	TRANSLATION***************************************************************************
	1 0 0 x
	0 1 0 y
	0 0 1 z
	0 0 0 1
	*/
	mat4 Transform::tranMatrix(const vec3& t)
	{
		mat4* rez = new mat4; rez->setIdentity();
		rez->val[0][3] = t.x;
		rez->val[1][3] = t.x;
		rez->val[2][3] = t.x;
		return *rez;
	}
}