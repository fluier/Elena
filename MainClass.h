#pragma once

#include<vector>

#include"graphic\Window.h"
#include"graphic\GLSLProgram.h"
#include"graphic\Sprite.h"
#include"math\math.h"
namespace Adina {

	class MainClass
	{
		bool GAME_IS_RUNNING;
		Window window;
		GLSLProgram m_shader;
		
		std::vector<Sprite*>m_sprite;
		mat4 projection;
		mat4 rotMatrix;
		mat4 translationMatrix;
		mat4 transformMatrix;
	public:
		MainClass();
		~MainClass();

		void init();
		void run();
		void update();
		void draw();
		void input();
		void exit();

		///
		void initShaders();
	};


}