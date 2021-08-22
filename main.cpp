#include <iostream>
#include "window.hpp"
#include "input.h"
#include "shader.h"
#include "model.h"
#include "transform.h"
#include "cam.h"
#include <chrono>
#include <thread>
#include "texture.h"

int main(){

	Window window;
	Input input(window.windowPtr);
	Shader shader("res/vShader.glsl", "res/fShader.glsl");
	Camera camera;

	Model keyboard("res/keyboard.obj");
	Model desk("res/desk.obj");
	Model mug("res/mug.obj");

	Transform keyboardTransform;
	Transform deskTransform;
	Transform mugTransform;

	Texture keyboardTexture("res/keyboard.png");
	Texture deskTexture("res/desk.png");
	Texture mugTexture("res/mug.png");


	deskTransform.scale = glm::vec3(100);

	keyboardTransform.scale = glm::vec3(15);
	keyboardTransform.rotation.y = -90;
	keyboardTransform.position.y = 135;
	keyboardTransform.position.z = -130;
	keyboardTransform.position.x = -160;

	mugTransform.position.y = 135.5;
	mugTransform.position.z = -40;
	mugTransform.position.x = -150;

	auto end = std::chrono::high_resolution_clock::now();

	while(!glfwWindowShouldClose(window.windowPtr)){
		std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - end;
		end = std::chrono::high_resolution_clock::now();
		float deltaTime = diff.count();
		window.clearWindow();
		input.processInput();

		// Update
		camera.update(input, deltaTime);

		// Render
		shader.use();
		shader.loadUniform("projection", camera.projectionMatrix);
		shader.loadUniform("view", camera.getViewMatrix());

		shader.loadUniform("model", keyboardTransform.getMatrix());
		keyboardTexture.bind();
		keyboard.render();
		
		shader.loadUniform("model", deskTransform.getMatrix());
		deskTexture.bind();
		desk.render();
		
		shader.loadUniform("model", mugTransform.getMatrix());
		mugTexture.bind();
		mug.render();
		
		shader.unuse();

		window.swapBuffers();
	}
	return 0;
}
