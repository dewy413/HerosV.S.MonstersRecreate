#include <vector>
#include "Entity.h"
#include "World.h"
#include <iostream>
#include "raylib.h"



World::World() {
    /// Player Character Generation
    for (float i = 0; i < 4; i++) {
        entities.push_back(new Entity({0, 25 * i}));
    }

    //It is done this way because if I have a different set starting go to location the player will not spawn in where they are supposed to be.
    selectedLocation = &entities[0]->boxLocation; // Default selected location to be the first players' location.
    goToLocation = &entities[0]->goToLocation; // Default selected location to be the first players goto-location.
    selected = entities[0]; // Default selected character to be the first one.
}


void World::createEntity() {
    entities.push_back(new Entity);


}

