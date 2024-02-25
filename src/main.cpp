#include <iostream>
#include <stdbool.h>
#include <SDL.h>
#include "./includes/constants.h"
#include "./includes/errors.h"
#include "./includes/entities/Game/Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();

    int last_frame_time = 0;

    while (game->running()) {
        int current_time = SDL_GetTicks();
        float delta_time = (current_time - last_frame_time) / 1000.0f;
        last_frame_time = current_time;

        game->handle_events();
        game->update(delta_time);
        game->draw();
    }

    game->clean();

    return 0;
}