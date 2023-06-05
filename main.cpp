#include <iostream>
#include "raylib.h"

using namespace std;
//1, 2, 3, 4 to select what character you want to use
//q, w, e, r to select ability you want to use when attacking


struct entity {

    Rectangle hitBox;
    Vector2 boxLocation;
    Vector2 goToLocation;

};


bool checkLocation(Vector2 current, Vector2 goTo) {

    if(current.x != goTo.x) {
        return false;
    }

    if(current.y != goTo.y) {
        return false;
    }

    return true;

}
void updateLocation(Vector2 &current, Vector2 goTo, int speed) {

    int remainder = 0;
    if(current.x > int(goTo.x)) {

        current.x -= speed;
    }
    if(current.x < int(goTo.x)) {

        current.x += speed;
    }
    if(current.y > int(goTo.y)) {
        current.y -= speed;
    }

    if(current.y < int(goTo.y)) {
        current.y += speed;
    }

}


int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);



    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    entity boxOne;
    entity boxTwo;

    boxOne.boxLocation = {0, 0};
    boxOne.hitBox = {boxOne.boxLocation.x, boxOne.boxLocation.y, 50, 50};

    boxTwo.boxLocation = {50, 50};
    boxTwo.hitBox = {boxTwo.boxLocation.x, boxTwo.boxLocation.y, 50, 50};
    boxTwo.goToLocation = boxTwo.boxLocation;
    selectedLocation = &boxOne.boxLocation;
    goToLocation = &boxOne.goToLocation;
    int speed = 5;




    while (!WindowShouldClose()) { // Variable Update Zone
        if(IsKeyPressed(KEY_ONE)) {
            cout << boxOne.boxLocation.x << " " << boxOne.boxLocation.y << endl;
            boxTwo.boxLocation = *selectedLocation;
            boxTwo.goToLocation = *goToLocation;
            selectedLocation = &boxOne.boxLocation;
            goToLocation = &boxOne.goToLocation;


        }

        if(IsKeyPressed(KEY_TWO)) {
            boxOne.boxLocation = *selectedLocation;
            boxOne.goToLocation = *goToLocation;
            selectedLocation = &boxTwo.boxLocation;
            goToLocation = &boxTwo.goToLocation;

        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouseLocation = GetMousePosition();
            goToLocation = &mouseLocation;
        }

        if(!checkLocation(*selectedLocation, *goToLocation)) {
            updateLocation(*selectedLocation, *goToLocation, speed);
        }

        BeginDrawing(); //Start the Drawing
        ClearBackground(RAYWHITE);
            DrawRectangle(boxOne.boxLocation.x, boxOne.boxLocation.y, 40, 40, RED); // Creates the box
            DrawRectangle(boxTwo.boxLocation.x, boxTwo.boxLocation.y, 40, 40, BLUE);
        EndDrawing();

    }


    return 0;
}