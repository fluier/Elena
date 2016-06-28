#pragma once

#include"..\physic\mat4.h"

namespace Adina {
	void setProjectionMatrix(const float &angleOfView, const float &near, const float &far, mat4 &M);
	void calcRotationMatrix(mat4 & rot,float angle);
	void calcTranslationMatrix(mat4& tr, float x, float y, float z);
	float toRadians(float val);
}