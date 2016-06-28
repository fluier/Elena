#pragma once

#include<GL\glew.h>

namespace Adina {
	class Sprite
	{
		float m_x;
		float m_y;
		float m_z;
		float m_width;
		float m_height;
		GLuint m_vboID = 0;
	public:
		Sprite();
		~Sprite();

		void init(float x, float y, float width, float height);
		void init(float x, float y, float z, float width, float height);

		void draw();
	};
}
