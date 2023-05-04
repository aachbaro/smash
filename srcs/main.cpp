#include "../includes/smash.hpp"



int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window*     window = SDL_CreateWindow("smash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN);
    SDL_Renderer*   renderer = SDL_CreateRenderer(window, -1, 0);

    bool        is_running = true;
    SDL_Event   event;

    //rectangle
        // initialisation des valeurs du rectangle
    t_rect rec;
    rec.w = 10;
    rec.h = 10;
    rec.x = 100;
    rec.y = 100;
    rec.move.left = 0;
    rec.move.right = 0;
    rec.move.up = 0;
    rec.move.down = 0;
    Uint32 last_frame_time = SDL_GetTicks();


    while (is_running) {
        Uint32 current_time = SDL_GetTicks();
        Uint32 elapsed_time = current_time - last_frame_time;

        // raffraichissement de la page
        if (elapsed_time >= 1000 / 30) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            move(rec);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Rect rect = { rec.x, rec.y, rec.w, rec.h };
            SDL_RenderDrawRect(renderer, &rect);
            SDL_RenderPresent(renderer);
            last_frame_time = current_time;
        }
        // gestion des evenements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                exit_game(is_running, window, renderer);
            }
            handle_input(event, rec);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}