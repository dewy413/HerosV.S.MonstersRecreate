#ifndef HEROSV_S_MONSTERSRECREATE_ENTITY_H
#define HEROSV_S_MONSTERSRECREATE_ENTITY_H

#include <iostream>
#include "raylib.h"
#include <vector>

using namespace std;

class Entity {
public:
    Vector2 boxLocation;
    Vector2 goToLocation;
    Rectangle hitBox;
    int health = 100;
    int speed = 5;
    int attack = 5;
    int range = 25;
    string name;
    Entity *target = nullptr;

    explicit Entity(Vector2 location);
    void locationCheck();
    [[nodiscard]] bool checkLocation();
    void updateLocation();
    void drawSelf(Color color) const;
};

#endif //HEROSV_S_MONSTERSRECREATE_ENTITY_H
