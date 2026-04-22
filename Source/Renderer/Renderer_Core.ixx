module;

// TODO: remove
#include <SDL3/SDL.h>

import Performance;

export module Renderer:Core;

export class GameRenderer
{
public:
	GameRenderer() : _window(nullptr), _GPUDevice(nullptr)
	{
	}
	~GameRenderer()
	{
		SDL_DestroyGPUDevice(_GPUDevice);

		SDL_DestroyWindow(_window);
	}

	void InitGameWindow() {

		_window = SDL_CreateWindow("LOM Engine", 800, 600, SDL_WINDOW_RESIZABLE);

		SDL_Surface* icon = SDL_LoadPNG("Content/Icons/MyRobot.png");

		if (!icon) {
			SDL_Log("Failed to load icon: %s", SDL_GetError());
		}

		SDL_SetWindowIcon(_window, icon);
	};

	void Draw() {
		ScopeTimeTracker _("GPU");

	};

private:
	SDL_Window* _window;

	SDL_GPUDevice* _GPUDevice;
};

