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
    Rectangle mouseColl = {NULL, NULL, 25, 25};
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
        mouseColl.x = GetMouseX() - 12;
        mouseColl.y = GetMouseY() - 12;
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
            for(auto & entitie : entities) {
                if(CheckCollisionRecs(mouseColl, entitie->hitBox)) {
                    goToLocation->x = entitie->goToLocation.x - 75;
                    goToLocation->y = entitie->goToLocation.y;
                    selected->goToLocation = *goToLocation;
                    break;
                } else {
                    mouseLocation = GetMousePosition();
                    mouseLocation.x -= selected->hitBox.width / 2;
                    mouseLocation.y -= selected->hitBox.height / 2;
                    goToLocation = &mouseLocation;
                }
            }
        }

        boxOne.locationCheck();
        boxTwo.locationCheck();
        boxThree.locationCheck();
        boxFour.locationCheck();
        badGuy.locationCheck();

        BeginDrawing(); //Start the Drawing
        ClearBackground(WHITE);
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