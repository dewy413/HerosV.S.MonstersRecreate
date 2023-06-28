#ifndef HEROSV_S_MONSTERSRECREATE_WORLD_H
#define HEROSV_S_MONSTERSRECREATE_WORLD_H

#include <iostream>
#include "raylib.h"
#include <vector>

class World {
public:
    World();
    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    Rectangle mouseColl {NULL, NULL, 5, 5};
    vector <Entity *> entities;
    Entity *selected;
};


#endif //HEROSV_S_MONSTERSRECREATE_WORLD_H
