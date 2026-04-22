#include <iostream>
#include <fstream>
#include <string>
#include <SDL3/SDL_filesystem.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>

import Renderer;
import Performance;

// todo: move to logger
void file_logger(void* userdata, int category, SDL_LogPriority priority, const char* message) {
    FILE* f = (FILE*)userdata;
    if (f) {
        fprintf(f, "[%d] %s\n", priority, message);
        std::cout << message << "\n";
        fflush(f);
    }
}


int main(int argc, char* argv[]) {

    // todo: move to logger
    SDL_CreateDirectory("Saved/Logs");
    FILE* logfile = fopen("Saved/Logs/Log.txt", "w");

    SDL_SetLogOutputFunction(file_logger, logfile);

    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    GameRenderer Renderer = GameRenderer();

    Renderer.InitGameWindow();

    bool quit = false;
    SDL_Event e;
    while (!quit) 
    {
        ScopeTimeTracker _("MainLoop");

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            if (e.type == SDL_EVENT_KEY_DOWN) {
                quit = true;
            }
        }

        Renderer.Draw();
    }
    // todo: move to logger
    fclose(logfile);

    Renderer.~GameRenderer();

    SDL_Quit();
    return 0;
}
