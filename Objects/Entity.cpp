#include "Entity.h"
#include <iostream>
#include "raylib.h"
#include <vector>

using namespace std;


Entity::Entity(Vector2 location) {
    boxLocation = location;
    goToLocation = boxLocation;
    hitBox.x = location.x;
    hitBox.y = location.y;
    hitBox.height = 50;
    hitBox.width = 50;
}

void Entity::locationCheck() {
    if(!checkLocation()) {
        updateLocation();
    }
}

bool Entity::checkLocation() const {
    if(boxLocation.x != goToLocation.x) {
        return false;
    }

    if(boxLocation.y != goToLocation.y) {
        return false;
    }

    return true;

}

void Entity::updateLocation() {
    if(boxLocation.x > int(goToLocation.x)) {
        if(abs(boxLocation.x - goToLocation.x) > speed) {
            boxLocation.x -= speed;
        } else {
            boxLocation.x -= abs(boxLocation.x - goToLocation.x);

        }
    }
    if(boxLocation.x < int(goToLocation.x)) {
        if(abs(boxLocation.x - goToLocation.x) > speed) {
            boxLocation.x += speed;

        } else {
            boxLocation.x += abs(boxLocation.x - goToLocation.x);

        }
    }
    if(boxLocation.y > int(goToLocation.y)) {
        if(abs(boxLocation.y - goToLocation.y) > speed) {
            boxLocation.y -= speed;

        } else {
            boxLocation.y -= abs(boxLocation.y - goToLocation.y);

        }

    }

    if(boxLocation.y < int(goToLocation.y)) {
        if(abs(boxLocation.y - goToLocation.y) > speed) {
            boxLocation.y += speed;

        } else {
            boxLocation.y += abs(boxLocation.y - goToLocation.y);

        }

    }


}

void Entity::drawSelf(Color color) const {
    DrawRectangleRec(hitBox, color);
    DrawRectangle(hitBox.x, hitBox.y - 12, health / 2, 8, RED);
    DrawRectangleLines(hitBox.x, hitBox.y - 12, 50, 8, BLACK);
}

Entity::Entity() {
}