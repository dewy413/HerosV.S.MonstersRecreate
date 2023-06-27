#include <iostream>
#include "raylib.h"
#include <vector>
#include "Objects/Entity.h"
using namespace std;



int main() {

    /// WINDOW SETUP OPTIONS
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);
    /// WINDOW SETUP OPTIONS




    Vector2 *selectedLocation;
    Vector2 *goToLocation;
    Vector2 mouseLocation;
    Rectangle mouseColl = {NULL, NULL, 5, 5};
    vector <Entity *> entities;
    Entity *selected;
    Entity boxOne({0, 0});
    Entity boxTwo({0, 50});
    Entity boxThree({0, 100});
    Entity boxFour({0, 150});
    Entity badGuy ({500, 250});

    boxOne.name = "1";
    boxTwo.name = "2";
    boxThree.name = "3";
    boxFour.name = "4";
    badGuy.name = "BAD";
    entities.push_back(&boxOne);
    entities.push_back(&boxTwo);
    entities.push_back(&boxThree);
    entities.push_back(&boxFour);
    entities.push_back(&badGuy);



    selectedLocation = &boxOne.boxLocation;
    goToLocation = &boxOne.goToLocation;
    selected = &boxOne;



    while (!WindowShouldClose()) { // Variable Update Zone


        selected->goToLocation = *goToLocation;
        mouseColl.x = GetMouseX() - 1.5;
        mouseColl.y = GetMouseY() - 1;
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
                selected->target = nullptr;
            }


        /// ENTITY LOOP
        for(auto & entitie : entities) {
            entitie->attackable.clear();
            entitie->locationCheck();
            if (CheckCollisionCircleRec({selected->hitBox.x + 25, selected->hitBox.y + 25}, selected->range,
                                        entitie->hitBox)) {
                selected->attackable.push_back(entitie);
            }
        }
        /// ENTITY CHECK LOOP


        BeginDrawing(); //Start the Drawing
        ClearBackground(BLACK);
        // Add loop for drawing
            boxOne.drawSelf(BLUE);
            boxTwo.drawSelf(BLACK);
            boxThree.drawSelf(GREEN);
            boxFour.drawSelf(PURPLE);
            badGuy.drawSelf(RED);
            DrawRectangleRec(mouseColl, PINK);

        EndDrawing();

    }


    return 0;
}