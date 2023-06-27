#include <iostream>
#include "raylib.h"
#include <vector>
#include "Objects/Entity.h"
#include "Objects/World.h"
using namespace std;



int main() {

    /// WINDOW SETUP OPTIONS
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HVM");

    SetTargetFPS(60);
    /// WINDOW SETUP OPTIONS



    World World;


   /* Vector2 *selectedLocation;
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
*/

    while (!WindowShouldClose()) { // Variable Update Zone


        World.selected->goToLocation = *World.goToLocation;
        World.mouseColl.x = GetMouseX() - 1.5;
        World.mouseColl.y = GetMouseY() - 1;
        if (IsKeyPressed(KEY_ONE)) {

            World.selected->boxLocation = *World.selectedLocation;
            World.selected->goToLocation = *World.goToLocation;
            World.selectedLocation = &World.entities[0]->boxLocation;
            World.goToLocation = &World.entities[0]->goToLocation;
            World.selected = World.entities[0];


        }

        if (IsKeyPressed(KEY_TWO)) {
            World.selected->boxLocation = *World.selectedLocation;
            World.selected->goToLocation = *World.goToLocation;
            World.selectedLocation = &World.entities[1]->boxLocation;
            World.goToLocation = &World.entities[1]->goToLocation;
            World.selected = World.entities[1];

        }

        if (IsKeyPressed(KEY_THREE)) {
            World.selected->boxLocation = *World.selectedLocation;
            World.selected->goToLocation = *World.goToLocation;
            World.selectedLocation = &World.entities[2]->boxLocation;
            World.goToLocation = &World.entities[2]->goToLocation;
            World.selected = World.entities[2];
        }

        if (IsKeyPressed(KEY_FOUR)) {
            World.selected->boxLocation = *World.selectedLocation;
            World.selected->goToLocation = *World.goToLocation;
            World.selectedLocation = &World.entities[3]->boxLocation;
            World.goToLocation = &World.entities[3]->goToLocation;
            World.selected = World.entities[3];

        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                World.mouseLocation = GetMousePosition();
                World.mouseLocation.x -= World.selected->hitBox.width / 2;
                World.mouseLocation.y -= World.selected->hitBox.height / 2;
                World.goToLocation = &World.mouseLocation;
                World.selected->target = nullptr;
            }


        /// ENTITY LOOP
        for(auto & entitie : World.entities) {
            entitie->attackable.clear();
            entitie->locationCheck();
            if (CheckCollisionCircleRec({World.selected->hitBox.x + 25, World.selected->hitBox.y + 25}, World.selected->range,
                                        entitie->hitBox)) {
                World.selected->attackable.push_back(entitie);
            }
        }
        /// ENTITY CHECK LOOP


        BeginDrawing(); //Start the Drawing
        ClearBackground(BLACK);
        // Add loop for drawing
            for(auto & entitie : World.entities) {
                entitie->drawSelf(RED);
            }
            DrawRectangleRec(World.mouseColl, PINK);

        EndDrawing();

    }


    return 0;
}