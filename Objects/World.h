#ifndef HEROSV_S_MONSTERSRECREATE_WORLD_H
#define HEROSV_S_MONSTERSRECREATE_WORLD_H

#include <iostream>
#include "raylib.h"
#include <vector>
#include "Entity.h"

class World {
public:
    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    Entity *selected;
    Entity party[4];
    vector <Entity> entities;

    World() {
        selectedLocation = &boxOne.boxLocation;
        goToLocation = &boxOne.goToLocation;
        selected = &boxOne;
    }
    void partyInputCheck() {

    }
};


#endif //HEROSV_S_MONSTERSRECREATE_WORLD_H
