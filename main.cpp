#include <iostream>
#include "raylib.h"

using namespace std;


Vector2 checkLocation(Vector2 current, Vector2 goTo) {
    if(current.x != goTo.x) {
        current.x = goTo.x;
    }

    if(current.y != goTo.y) {
        current.y = goTo.y;
    }

    return current;

}

int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);



    Vector2 boxLocation = {0, 0};





    while (!WindowShouldClose()) { // Variable Update Zone

        boxLocation = checkLocation(boxLocation, GetMousePosition()); // Should update the mouse to be at the location of where the
        BeginDrawing(); //Start the Drawing

            ClearBackground(RAYWHITE);
            DrawRectangle(boxLocation.x, boxLocation.y, 40, 40, RED); // Creates the box
        EndDrawing();

    }


    return 0;
}