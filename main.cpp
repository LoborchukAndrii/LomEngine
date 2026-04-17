#include <SDL3/SDL.h>
#include <iostream>
#include <fstream>
#include <string>

import Renderer;


void file_logger(void* userdata, int category, SDL_LogPriority priority, const char* message) {
    FILE* f = (FILE*)userdata;
    if (f) {
        fprintf(f, "[%d] %s\n", priority, message);
        fflush(f);
    }
}


int main(int argc, char* argv[]) {

    auto logfile = fopen("sdl_log.txt", "w");
    SDL_SetLogOutputFunction(file_logger, logfile);

    if (SDL_Init(SDL_INIT_VIDEO) == false) { // SDL3 returns bool
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    GameRenderer* Renderer = new GameRenderer();

    Renderer->InitGameWindow();

    // SDL3 CreateWindow only takes title, width, height, and flags
    //SDL_Window* window = SDL_CreateWindow("LOM Engine", 800, 600, 0);

    //if (!window) {
    //    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    //    SDL_Quit();
    //    return 1;
    //}

    //// Switch to fullscreen
    //if (!SDL_SetWindowFullscreen(window, true)) {
    //    SDL_Log("Failed to enter fullscreen: %s", SDL_GetError());
    //}


    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            if (e.type == SDL_EVENT_KEY_DOWN) {
                quit = true;
            }
        }
    }

    fclose(logfile);

    SDL_Quit();
    return 0;
}
