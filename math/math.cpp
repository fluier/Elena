#include "math.h"

#include<math.h>

#define M_PI  3.14159265358979323846

namespace Adina {
	void setProjectionMatrix(const float &angleOfView, const float &NEAR_PLANE, const float &FAR_PLANE, mat4 &M)
	{

		float aspectRatio = 1.0f;
		float y_scale = (float)((1.0f / tan(toRadians(angleOfView / 2.0f))) * aspectRatio);
		float x_scale = y_scale / aspectRatio;
		float frustum_length = FAR_PLANE - NEAR_PLANE;

		M.val[0][0] = x_scale;
		M.val[1][1] = y_scale;
		M.val[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustum_length);
		M.val[2][3] = -1;
		M.val[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustum_length);
		M.val[3][3] = 0;
	}
	void calcRotationMatrix(mat4 & rot, float angle)
	{
		rot.rotY(angle);
	}
	/****************************************************************
	1 0 0 x
	0 1 0 y
	0 0 1 z
	0 0 0 1
	*/
	void calcTranslationMatrix(mat4 & tr, float x, float y, float z)
	{
		tr.setIdentity();
		tr.val[0][3] = x;
		tr.val[1][3] = y;
		tr.val[2][3] = z;
	}
	float toRadians(float val)
	{
		return val * 180 / M_PI;
	}
}