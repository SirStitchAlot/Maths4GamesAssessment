#pragma warning( push , 0)
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>

#pragma warning(pop)

// //////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

#include "Game_01.h"


int main(int argc, char* argv[]){
    // Initialization
    int screenWidth = 640;
    int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Tank example - Ver 1.0");

    SetTargetFPS(60);

    Game_01 GM = Game_01();
    GM.Init();


    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        GM.Update();

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);
        GM.Draw();

        DrawText("Raylib C++", 520, 364, 20, DARKGRAY);
        //DrawText("Raylib C++", 520, 364, 20, DARKBROWN);
        // predefined colors - color table at the end of page - https://www.raylib.com/cheatsheet/cheatsheet.html

        EndDrawing();
    }

    // De-Initialization
    GM.Shutdown();

    CloseWindow();        // Close window and OpenGL context
    cout << " -- end of code -- " << endl;

    return 0;
}