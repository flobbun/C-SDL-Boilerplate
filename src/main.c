#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "./constants.h"
#include "./errors.h"

// Global variables
int game_is_running = false;
int last_frame_time = 0;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

// Function to initialize our SDL window
int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, SDL_INITIALIZE_ERROR);
        return false;
    }
    window = SDL_CreateWindow(
        GAME_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );
    if (!window) {
        fprintf(stderr, WINDOW_CREATION_ERROR);
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, RENDERER_CREATION_ERROR);
        return false;
    }
    return true;
}

// Function to poll SDL events and process keyboard input
void process_input(void) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                game_is_running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    game_is_running = false;
                }
                break;
        }
    }
}

// Setup function that runs once at the beginning of our program
void setup(void) {
  // !... Initialize stuff here
}

// Update function with a fixed time step
void update(void) {
    // Get delta_time factor converted to seconds to be used to update objects
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0;

    // Store the milliseconds of the current frame to be used in the next one
    last_frame_time = SDL_GetTicks();

    // Update logic here
      // !...
}

// Render function to draw game objects in the SDL window
void render(void) {
    // Clear the window to a black color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw stuff here
      // !...

    SDL_RenderPresent(renderer);
}

// Function to destroy SDL window and renderer
void destroy_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Main function
int main(int argc, char* args[]) {
    game_is_running = initialize_window();

    setup();

    while (game_is_running) {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}