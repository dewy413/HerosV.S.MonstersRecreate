#include <iostream>
#include "raylib.h"
#include <vector>
using namespace std;

//q, w, e, r to select ability you want to use when attacking


class entity {
public:
    //Rectangle hitBox;
    Vector2 boxLocation = {0, 0};
    Vector2 goToLocation = {0, 0};
    int speed = 5;


    void locationCheck() {
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
    entity boxOne;
    entity boxTwo;
    entity boxThree;
    entity boxFour;

    entities.push_back(boxOne);
    entities.push_back(boxTwo);
    entities.push_back(boxThree);
    entities.push_back(boxFour);


    boxOne.boxLocation = {0, 0};
    //boxOne.hitBox = {boxOne.boxLocation.x, boxOne.boxLocation.y, 50, 50};

    boxTwo.boxLocation = {50, 50};
    //boxTwo.hitBox = {boxTwo.boxLocation.x, boxTwo.boxLocation.y, 50, 50};
    boxTwo.goToLocation = boxTwo.boxLocation;

    boxThree.boxLocation = {100, 100};
    //boxThree.hitBox = {boxThree.boxLocation.x, boxThree.boxLocation.y, 50, 50};
    boxThree.goToLocation = boxThree.boxLocation;

    boxFour.boxLocation = {150, 150};
    //boxFour.hitBox = {boxFour.boxLocation.x, boxFour.boxLocation.y, 50, 50};
    boxFour.goToLocation = boxFour.boxLocation;

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
            goToLocation = &mouseLocation;
        }

        boxOne.locationCheck();
        boxTwo.locationCheck();
        boxThree.locationCheck();
        boxFour.locationCheck();


        BeginDrawing(); //Start the Drawing
        ClearBackground(BLACK);
            DrawRectangle(boxOne.boxLocation.x, boxOne.boxLocation.y, 40, 40, RED); // Creates the box
            DrawRectangle(boxTwo.boxLocation.x, boxTwo.boxLocation.y, 40, 40, BLUE);
            DrawRectangle(boxThree.boxLocation.x, boxThree.boxLocation.y, 40, 40, YELLOW);
            DrawRectangle(boxFour.boxLocation.x, boxFour.boxLocation.y, 40, 40, GREEN);
        EndDrawing();

    }


    return 0;
}