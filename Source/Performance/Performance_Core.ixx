module;

// TODO: remove
#include <iostream>
#include <SDL3/SDL.h>

export module Performance:Core;

export class ScopeTimeTracker
{
public:
    ScopeTimeTracker(const char* NewMessage) : Message(NewMessage), start(SDL_GetPerformanceCounter()) {};

    ~ScopeTimeTracker()
    {
        end = SDL_GetPerformanceCounter();

        double elapsedMS = (end - start) * 1000.0 / SDL_GetPerformanceFrequency();

        SDL_Log("%s \nTook %f ms\n", Message, elapsedMS);
    };

private:
    Uint64 start;
    Uint64 end;

    const char* Message;
};

