#include <iostream>
#include "raylib.h"

using namespace std;


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
    int remainderx = int(goTo.x) % speed;
    int remaindery = int(goTo.y) % speed;

    if(current.x > goTo.x) {
        current.x -= speed + remainderx;
    }
    if(current.x < goTo.x) {
        current.x += speed + remainderx;
    }
    if(current.y > goTo.y) {
        current.y -= speed + remaindery;
    }

    if(current.y < goTo.y) {
        current.y += speed + remaindery;
    }

}


int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);



    Vector2 boxLocation = {0, 0};
    Vector2 goToLocation = {0, 0};
    int speed = 5;
    bool locationReached = false;
    bool mouseClicked = false;




    while (!WindowShouldClose()) { // Variable Update Zone



        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            goToLocation = GetMousePosition();
        }

        if(!checkLocation(boxLocation, goToLocation)) {
            updateLocation(boxLocation, goToLocation, speed);
        }

        BeginDrawing(); //Start the Drawing
            cout << goToLocation.x << " " << goToLocation.y << endl;
            ClearBackground(RAYWHITE);
            DrawRectangle(boxLocation.x, boxLocation.y, 40, 40, RED); // Creates the box
        EndDrawing();

    }


    return 0;
}