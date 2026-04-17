// TODO: remove
#include <iostream>
#include <SDL3/SDL.h>

export module Renderer:Core;

export class GameRenderer
{
public:
	GameRenderer();
	~GameRenderer();

	void InitGameWindow() {
		_window = SDL_CreateWindow("LOM Engine", 960, 540, SDL_WINDOW_RESIZABLE);

		// create the device
		_GPUDevice = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, false, NULL);
		SDL_ClaimWindowForGPUDevice(_GPUDevice, _window);
	};

private:
	SDL_Window* _window;

	SDL_GPUDevice* _GPUDevice;
};

GameRenderer::GameRenderer()
{
}

GameRenderer::~GameRenderer()
{
	SDL_DestroyGPUDevice(_GPUDevice);

	SDL_DestroyWindow(_window);
}