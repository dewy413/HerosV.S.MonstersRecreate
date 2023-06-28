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



    /// GENERATE WORLD
    World World;
    /// GENERATE WORLD



    /// VARIABLE UPDATE ZONE
    while (!WindowShouldClose()) {

        World.selected->goToLocation = *World.goToLocation; // Makes sure that the selected location is up-to-date.
        World.mouseColl.x = GetMouseX() - 1.5; // Mouse exact click location relative to the generated hotbox square.
        World.mouseColl.y = GetMouseY() - 1; // ^^^^^

        /// PLAYER INPUT KEY CODE
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

        /// PLAYER INPUT KEY CODE

        /// MOUSE CLICK CODE
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            for (auto &entity: World.entities) {
                // Target following
                if (CheckCollisionRecs(World.mouseColl, entity->hitBox)) {
                    World.selected->target = entity;
                    break;
                } else {
                    // General location moving
                    World.mouseLocation = GetMousePosition();
                    World.mouseLocation.x -= World.selected->hitBox.width / 2;
                    World.mouseLocation.y -= World.selected->hitBox.height / 2;
                    World.goToLocation = &World.mouseLocation;
                    World.selected->target = nullptr;
                }
            }
        }

        /// MOUSE CLICK CODE

        /// ENTITY LOOP
        for (auto &entitie: World.entities) {
            entitie->locationCheck();
            }
        /// ENTITY CHECK LOOP

        /// VARIABLE UPDATE ZONE


        /// DRAWING ZONE
        BeginDrawing();
        ClearBackground(BLACK);
        for (auto &entity: World.entities) {
            entity->drawSelf(RED);
        }
        DrawRectangleRec(World.mouseColl, PINK);

        EndDrawing();

    }
    /// DRAWING ZONE

    return 0;
}