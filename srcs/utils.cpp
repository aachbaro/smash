#include "../includes/smash.hpp"

void exit_game(bool &is_running, SDL_Window* win, SDL_Renderer* render) {
    SDL_DestroyRenderer(render); // Destruction du renderer
    SDL_DestroyWindow(win); // Destruction de la fenêtre
    is_running = false;
    SDL_Quit();
}

void handle_input(SDL_Event event, t_rect &rec) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                rec.move.up = true;
                break;
            case SDLK_DOWN:
                rec.move.down = true;
                break;
            case SDLK_LEFT:
                rec.move.left = true;
                break;
            case SDLK_RIGHT:
                rec.move.right = true;
                break;
            default:
                break;
        }
    }
    if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                rec.move.up = false;
                break;
            case SDLK_DOWN:
                rec.move.down = false;
                break;
            case SDLK_LEFT:
                rec.move.left = false;
                break;
            case SDLK_RIGHT:
                rec.move.right = false;
                break;
            default:
                break;
        }
    }
}

void    move(t_rect &rec)
{
    int speed = 9;
    if (rec.move.left && rec.x - speed > 0) { rec.x -= speed; }
    if (rec.move.right && rec.x + speed + 3 < 1000) { rec.x += speed; }
    if (rec.move.up && rec.y - speed > 0) { rec.y -= speed; }
    if (rec.move.down && rec.y + speed + 3 < 1000) { rec.y += speed; }
}