#include "Entity.h"
#include "raylib.h"

void Entity::updateLocation() {
    if(boxLocation.x > int(goToLocation.x)) {

        boxLocation.x -= speed;
    }
    if(boxLocation.x < int(goToLocation.x)) {

        boxLocation.x += speed;
    }
    if(boxLocation.y > int(goToLocation.y)) {
        boxLocation.y -= speed;
    }

    if(boxLocation.y < int(goToLocation.y)) {
        boxLocation.y += speed;
    }
}

bool Entity::checkLocation() {
    if(boxLocation.x != goToLocation.x) {
        return false;
    }

    if(boxLocation.y != goToLocation.y) {
        return false;
    }

    return true;

}


Entity::Entity(int a, int d, int h, int s, Vector2 box) {
    this->attack = a;
    this->defense = d;
    this->health = h;
    this->speed = s;
    this->boxLocation = box;
    this->hitbox = {boxLocation.x, boxLocation.y, 50, 50};
    this->goToLocation = boxLocation;
}

