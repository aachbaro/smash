#include "../includes/smash.hpp"

void exit_game(bool &is_running, SDL_Window* win, SDL_Renderer* render) {
    SDL_DestroyRenderer(render); // Destruction du renderer
    SDL_DestroyWindow(win); // Destruction de la fenêtre
    is_running = false;
    SDL_Quit();
}