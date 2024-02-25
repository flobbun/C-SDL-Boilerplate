#include "Entity.h"
#include <SDL.h>
#include "../../constants.h"
#include "../../utils/draw_circle.c"

Entity::Entity() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    speed = 0;
}

void Entity::setup() {
    const int random_x = rand() % WINDOW_WIDTH;
    const int random_y = rand() % WINDOW_HEIGHT;
    x = random_x;
    y = random_y;
}

void Entity::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, WHITE);
    draw_circle(renderer, x, y, 10);
}

void Entity::update(float delta_time) {
    const float max_speed = 100;
    const float acceleration = 16;

    x += speed * delta_time;
    y += speed * delta_time;
    if (x > WINDOW_WIDTH) {
        x = 0;
    }
    if (y > WINDOW_HEIGHT) {
        y = 0;
    }

    if (speed < max_speed) {
        speed += acceleration * delta_time;
    }
    if (speed == max_speed) {
        speed = 0;
    }
}