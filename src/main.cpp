#include <iostream>
#include <SDL3/SDL.h>

#include "version.hpp"

// SDL3 smoke-test app

int main()
{
    SDL_Window *window = nullptr;

    SDL_Surface *screen_surface = nullptr;

    if (! SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Cannot initialize SDL: " << SDL_GetError() << "\n";
    }
    else {
        window = SDL_CreateWindow("SDL test", 800, 600, 0);
        if (window == nullptr) {
            std::cerr << "Cannot create window: " << SDL_GetError() << "\n";
        }
        else {
            std::string window_title = std::format("Hello from v{}", rh::version::current());
            if (! SDL_SetWindowTitle(window, window_title.c_str())) {
                std::cerr << "Cannot set window title: " << SDL_GetError() << "\n";
            }

            screen_surface = SDL_GetWindowSurface(window);

            SDL_FillSurfaceRect(screen_surface, nullptr, SDL_MapSurfaceRGB(screen_surface, 0x6D, 0xD6, 0x61));

            SDL_UpdateWindowSurface(window);

            SDL_Event e;
            bool quit = false;
            while (quit == false) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_EVENT_QUIT) {
                        quit = true;
                    }
                }
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
