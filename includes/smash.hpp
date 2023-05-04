#ifndef SMASH_HPP
# define SMASH_HPP

# include <string>
# include "../sdl/include/SDL.h"

typedef struct s_move {
    bool left;
    bool right;
    bool up;
    bool down;
}               t_move;

typedef struct t_pos {
    int x;
    int y;
}

typedef struct s_rect {
    unsigned int w;
    unsigned int h;
}               t_rect;

void exit_game(bool &is_running, SDL_Window* win, SDL_Renderer* render);
void handle_input(SDL_Event event, t_rect &rec);
void    move(t_rect &rec);

#endif