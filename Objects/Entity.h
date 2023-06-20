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

    explicit Entity(Vector2 location);
    void locationCheck();
    bool checkLocation() const;
    void updateLocation();
    void drawSelf(Color color) const;
};

#endif //HEROSV_S_MONSTERSRECREATE_ENTITY_H
