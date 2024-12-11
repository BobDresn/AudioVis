#include <SDL.h>
#include "imgui.h"
#include <iostream>



int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Circle Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    bool quit = false;
    SDL_Event e;

    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    SDL_DestroyWindow(window);

    SDL_Quit();
    std::cout << "SDL initialized and quit successfully!" << std::endl;
    return 0;
}