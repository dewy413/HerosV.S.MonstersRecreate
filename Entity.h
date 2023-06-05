#ifndef HEROSV_S_MONSTERSRECREATE_ENTITY_H
#define HEROSV_S_MONSTERSRECREATE_ENTITY_H

#include <iostream>
#include "raylib.h"


class Entity {
public:
    Entity(int a, int d, int h, int s, Vector2 box);
    int attack;
    int defense;
    int health;
    int speed;
    Rectangle hitbox;
    Vector2 boxLocation;
    Vector2 goToLocation;
    void updateLocation();
    bool checkLocation();
};

#endif //HEROSV_S_MONSTERSRECREATE_ENTITY_H
