#ifndef HEROSV_S_MONSTERSRECREATE_ENTITY_H
#define HEROSV_S_MONSTERSRECREATE_ENTITY_H

#include <iostream>
#include "raylib.h"
#include <vector>

using namespace std;

class Entity {
public:
    string name;
    Vector2 boxLocation;
    Vector2 goToLocation;
    Rectangle hitBox;
    int speed = 5;
    int health = 100;
    int attack = 5;
    int range = 200;
    Entity *target = nullptr;
    vector <Entity *> attackable;

    explicit Entity(Vector2 location);

    Entity();
    void locationCheck();
    [[nodiscard]] bool checkLocation();
    void updateLocation();
    void drawSelf(Color color) const;
};

#endif //HEROSV_S_MONSTERSRECREATE_ENTITY_H
