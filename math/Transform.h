#pragma once

#include"../physic/mat4.h"
#include"../physic/vec3.h"
namespace Adina {
	class Transform
	{
	public:
		Transform();
		~Transform();
		mat4 viewMatrix(const vec3&, const vec3& lk, const vec3& up);
		mat4 scalMatrix(const vec3& s);
		mat4 rotaMatrix();
		mat4 tranMatrix(const vec3& t);
	};
}

