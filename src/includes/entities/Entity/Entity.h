#pragma once

#include <SDL.h>

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity();

    float x;
    float y;
    float width;
    float height;
    float speed;

    void setup();
    void draw(SDL_Renderer *renderer);
    void update(float delta_time);
};

#endif