#include "MainClass.h"
#include<iostream>

namespace Adina {


	MainClass::MainClass()
	{
	}


	MainClass::~MainClass()
	{
	}
	void MainClass::init()
	{
		window.create("Adina", 500, 500, 0);
		initShaders();
		Sprite* a = new Sprite; a->init(-3, -1, -1, 1, 1);
		m_sprite.push_back(a);

		Sprite* b = new Sprite; b->init(1, -1, -1, 1, 1);
		m_sprite.push_back(b);

		Sprite* c = new Sprite; c->init(0, 0, -1, 1, 1);
		m_sprite.push_back(c);
		
		projection.setToZero();
		setProjectionMatrix(60, 1, -100, projection);
	}

	void MainClass::run()
	{
		GAME_IS_RUNNING = true;
		init();
		while (GAME_IS_RUNNING) {
			update();
			draw();
		}
	}

	void MainClass::update()
	{
		input();
	}
	float time;
	void MainClass::draw()
	{
		glClearColor(0.0, 0.0, 0.0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		calcTranslationMatrix(translationMatrix, 0, 0, -10);
		calcRotationMatrix(rotMatrix, time);
		transformMatrix = projection *rotMatrix * translationMatrix;
		m_shader.use();
		m_shader.setUniformMatrix4fv("transformMatrix", transformMatrix);
		m_shader.setUniform1f("time", time += 0.001);
		for (Sprite* s : m_sprite) {
			s->draw();
		}
		m_shader.unuse();
		window.swapBuffer();
	}

	void MainClass::input()
	{
		SDL_Event evnt;
		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				exit();
				break;
			case SDLK_ESCAPE:
				exit();
				break;
			default:
				break;
			}
		}
	}

	void MainClass::exit()
	{
		GAME_IS_RUNNING = false;
	}

	void MainClass::initShaders()
	{
		m_shader.compileShaders("Shaders/vertex.txt", "Shaders/fragment.txt");
		m_shader.addAttribute("vertexPosition");
		m_shader.linkShaders();
	}

}
int main() {
	Adina::MainClass app;
	app.run();

	return 0;
}