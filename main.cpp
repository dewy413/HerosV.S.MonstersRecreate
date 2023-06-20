#include <iostream>
#include "raylib.h"
#include <vector>
using namespace std;

//q, w, e, r to select ability you want to use when attacking


class entity {
public:
    string name;
    Vector2 boxLocation;
    Vector2 goToLocation;
    Rectangle hitBox;
    int speed = 5;

    explicit entity(Vector2 location) {
        boxLocation = location;
        goToLocation = boxLocation;
        hitBox.x = location.x;
        hitBox.y = location.y;
        hitBox.height = 50;
        hitBox.width = 50;
    }
    void locationCheck() {
        hitBox.x = boxLocation.x;
        hitBox.y = boxLocation.y;
        if(!checkLocation()) {
            updateLocation();
        }
    }
    bool checkLocation() const {

        if(boxLocation.x != goToLocation.x) {
            return false;
        }

        if(boxLocation.y != goToLocation.y) {
            return false;
        }

        return true;

    }
    void updateLocation() {



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
    void drawSelf(Color color) const {
        DrawRectangleRec(hitBox, color);
    }

};





int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);



    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    vector <entity> entities;
    entity *selected;
    entity boxOne({0, 0});
    entity boxTwo({50, 50});
    entity boxThree({100, 100});
    entity boxFour({150, 150});


    entities.push_back(boxOne);
    entities.push_back(boxTwo);
    entities.push_back(boxThree);
    entities.push_back(boxFour);



    selectedLocation = &boxOne.boxLocation;
    goToLocation = &boxOne.goToLocation;
    selected = &boxOne;



    while (!WindowShouldClose()) { // Variable Update Zone


        selected->goToLocation = *goToLocation;


        if (IsKeyPressed(KEY_ONE)) {

            selected->boxLocation = *selectedLocation;
            selected->goToLocation = *goToLocation;
            selectedLocation = &boxOne.boxLocation;
            goToLocation = &boxOne.goToLocation;
            selected = &boxOne;


        }

        if (IsKeyPressed(KEY_TWO)) {
            selected->boxLocation = *selectedLocation;
            selected->goToLocation = *goToLocation;
            selectedLocation = &boxTwo.boxLocation;
            goToLocation = &boxTwo.goToLocation;
            selected = &boxTwo;

        }

        if (IsKeyPressed(KEY_THREE)) {

            selected->boxLocation = *selectedLocation;
            selected->goToLocation = *goToLocation;
            selectedLocation = &boxThree.boxLocation;
            goToLocation = &boxThree.goToLocation;
            selected = &boxThree;


        }

        if (IsKeyPressed(KEY_FOUR)) {
            selected->boxLocation = *selectedLocation;
            selected->goToLocation = *goToLocation;
            selectedLocation = &boxFour.boxLocation;
            goToLocation = &boxFour.goToLocation;
            selected = &boxFour;

        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouseLocation = GetMousePosition();
            mouseLocation.x -= selected->hitBox.width / 2;
            mouseLocation.y -= selected->hitBox.height / 2;
            goToLocation = &mouseLocation;
        }

        boxOne.locationCheck();
        boxTwo.locationCheck();
        boxThree.locationCheck();
        boxFour.locationCheck();


        BeginDrawing(); //Start the Drawing
        ClearBackground(BLACK);
            boxOne.drawSelf(RED);
            boxTwo.drawSelf(BLUE);
            boxThree.drawSelf(GREEN);
            boxFour.drawSelf(PURPLE);
        EndDrawing();

    }


    return 0;
}