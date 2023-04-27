#include "../includes/smash.hpp"

typedef struct s_rect {
    int w;
    int h;
    int x;
    int y;
}               t_rect;

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window*     window = SDL_CreateWindow("smash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer*   renderer = SDL_CreateRenderer(window, -1, 0);

    bool        is_running = true;
    SDL_Event   event;

    //rectangle
        // initialisation des valeurs du rectangle
    t_rect rec;
    rec.w = 50;
    rec.h = 50;
    rec.x = 100;
    rec.y = 100;


    while (is_running) {
        // raffraichissement de la page
        SDL_RenderClear(renderer);
        rec.x = (rec.x + 1) % 600;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect rect = { rec.x, rec.y, rec.w, rec.h };
        //rect = { rec.x, rec.y, rec.w, rec.h };
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderPresent(renderer);
 

        // gestion des evenements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            exit_game(is_running, window, renderer);
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}