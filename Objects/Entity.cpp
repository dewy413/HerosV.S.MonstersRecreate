#include "Entity.h"
#include <iostream>
#include "raylib.h"
#include "World.h"
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
    hitBox.x = boxLocation.x; //Update location so it is live
    hitBox.y = boxLocation.y; // ^^^
    if (!checkLocation()) {
        updateLocation();
    }
}

bool Entity::checkLocation() {

    if (target != nullptr) {
        goToLocation.x = target->hitBox.x; //Makes move location to the target
        goToLocation.y = target->hitBox.y; // ^^^
    }

    if (boxLocation.x != goToLocation.x) {
        return false;
    }

    if (boxLocation.y != goToLocation.y) {
        return false;
    }

    return true;

}

void Entity::updateLocation() {

    double timer = GetTime();



    if (attacked) {
        target = shooter;
    }

    if (target != nullptr) {

        /// ATTACKABLE
        if (CheckCollisionCircleRec({boxLocation.x + 25, boxLocation.y + 25}, range, target->hitBox)) {
            target->attacked = false;
            goToLocation.x = boxLocation.x;
            goToLocation.y = boxLocation.y;
            if(abs(timer - lastAttack) > cooldown) {
                target->health -= attack;
                target->attacked = true;
                target->shooter = this;
                lastAttack = GetTime();
            }

            return;
        }
        /// ATTACKABLE

        /// MOVE TO ATTACKABLE
        goToLocation.x = target->hitBox.x;
            goToLocation.y = target->hitBox.y;
        /// MOVE TO ATTACKABLE

    }

    /// DEFAULT MOVE LOCATION

    if (boxLocation.x > int(goToLocation.x)) {
        if (abs(boxLocation.x - goToLocation.x) > speed) {
            boxLocation.x -= speed; // Used for exact movement, not just
        } else {
            boxLocation.x -= abs(boxLocation.x - goToLocation.x);

        }
    }
    if (boxLocation.x < int(goToLocation.x)) {
        if (abs(boxLocation.x - goToLocation.x) > speed) {
            boxLocation.x += speed;

        } else {
            boxLocation.x += abs(boxLocation.x - goToLocation.x);

        }
    }
    if (boxLocation.y > int(goToLocation.y)) {
        if (abs(boxLocation.y - goToLocation.y) > speed) {
            boxLocation.y -= speed;

        } else {
            boxLocation.y -= abs(boxLocation.y - goToLocation.y);

        }

    }
    if (boxLocation.y < int(goToLocation.y)) {
        if (abs(boxLocation.y - goToLocation.y) > speed) {
            boxLocation.y += speed;

        } else {
            boxLocation.y += abs(boxLocation.y - goToLocation.y);

        }

    }
    /// DEFAULT MOVE LOCATION

}



void Entity::drawSelf(Color color) const {
    DrawRectangleRec(hitBox, color);
    DrawRectangle(hitBox.x, hitBox.y - 12, health / 2, 8, RED);
    DrawRectangleLines(hitBox.x, hitBox.y - 12, 50, 8, BLACK);
    DrawCircleLines(hitBox.x + 25, hitBox.y + 25, range, YELLOW); // range
}



