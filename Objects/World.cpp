#include <vector>
#include "Entity.h"
#include "World.h"
#include <iostream>
#include "raylib.h"



World::World() {
    for (float i = 0; i < 4; i++) {
        entities.push_back(new Entity({0, 25 * i}));
    }

    selectedLocation = &entities[0]->boxLocation;
    goToLocation = &entities[0]->goToLocation;
    selected = entities[0];/**/
}


void World::createEntity() {
    entities.push_back(new Entity);


}

