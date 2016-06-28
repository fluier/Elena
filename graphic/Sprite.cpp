#include "Sprite.h"
#include "Vertex.h"


#include<cstddef>

namespace Adina {

	Sprite::Sprite()
	{
	}


	Sprite::~Sprite()
	{
		if (m_vboID != 0) {
			glDeleteBuffers(1, &m_vboID);
		}
	}
	void Sprite::init(float x, float y, float width, float height)
	{
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		if (m_vboID == 0) {
			glGenBuffers(1, &m_vboID);
		}
		if (m_vboID == 0) {
			glGenBuffers(1, &m_vboID);
		}

		Vertex vertexData[6]; // 6 vertex * xy

							  // first triangle
		vertexData[0].setPosition(x + width, y + height);
		vertexData[0].setUV(1, 1);

		vertexData[1].setPosition(x, y + height);
		vertexData[1].setUV(0, 1);

		vertexData[2].setPosition(x, y);
		vertexData[2].setUV(0, 0);

		// second triangle
		vertexData[3].setPosition(x, y);
		vertexData[3].setUV(0, 0);

		vertexData[4].setPosition(x + width, y);
		vertexData[4].setUV(1, 0);

		vertexData[5].setPosition(x + width, y + height);
		vertexData[5].setUV(1, 1);


		for (int i = 0; i < 6; i++) {
			vertexData[i].color.r = 255;
			vertexData[i].color.g = 0;
			vertexData[i].color.b = 255;
			vertexData[i].color.a = 255;
		}
		vertexData[1].color.r = 0;
		vertexData[1].color.g = 0;
		vertexData[1].color.b = 255;
		vertexData[1].color.a = 255;

		vertexData[4].color.r = 0;
		vertexData[4].color.g = 255;
		vertexData[4].color.b = 0;
		vertexData[4].color.a = 255;

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void Sprite::init(float x, float y, float z, float width, float height)
	{
		m_x = x;
		m_y = y;
		m_z = z;
		m_width = width;
		m_height = height;
		if (m_vboID == 0) {
			glGenBuffers(1, &m_vboID);
		}
		if (m_vboID == 0) {
			glGenBuffers(1, &m_vboID);
		}

		Vertex vertexData[6]; // 6 vertex * xyz

							  // first triangle
		vertexData[0].setPosition(x + width, y + height,z);
		vertexData[0].setUV(1, 1);

		vertexData[1].setPosition(x, y + height, z);
		vertexData[1].setUV(0, 1);

		vertexData[2].setPosition(x, y, z);
		vertexData[2].setUV(0, 0);

		// second triangle
		vertexData[3].setPosition(x, y, z);
		vertexData[3].setUV(0, 0);

		vertexData[4].setPosition(x + width, y, z);
		vertexData[4].setUV(1, 0);

		vertexData[5].setPosition(x + width, y + height, z);
		vertexData[5].setUV(1, 1);


		for (int i = 0; i < 6; i++) {
			vertexData[i].color.r = 255;
			vertexData[i].color.g = 0;
			vertexData[i].color.b = 255;
			vertexData[i].color.a = 255;
		}
		vertexData[1].color.r = 0;
		vertexData[1].color.g = 0;
		vertexData[1].color.b = 255;
		vertexData[1].color.a = 255;

		vertexData[4].color.r = 0;
		vertexData[4].color.g = 255;
		vertexData[4].color.b = 0;
		vertexData[4].color.a = 255;

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void Sprite::draw()
	{

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
		//glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, position));

		glDrawArrays(GL_TRIANGLES, 0, 6);

		//glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}
}
