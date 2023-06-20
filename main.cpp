#include <iostream>
#include "raylib.h"
#include <vector>
#include "Objects/Entity.h"
using namespace std;

class World {
public:
    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    vector <Entity> entities;
    Entity *selected;



};



int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);



    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    vector <Entity> entities;
    World testWorld;
    Entity party[4];
    Entity *selected;
    Entity boxOne({0, 0});
    Entity boxTwo({0, 50});
    Entity boxThree({0, 100});
    Entity boxFour({0, 150});


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
        ClearBackground(WHITE);
            boxOne.drawSelf(BLUE);
            boxTwo.drawSelf(RED);
            boxThree.drawSelf(GREEN);
            boxFour.drawSelf(PURPLE);
        EndDrawing();

    }


    return 0;
}