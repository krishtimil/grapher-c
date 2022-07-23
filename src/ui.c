#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for GUI controls

#include "graph.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int init_ui(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 900;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Grapher-C");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // NOTE: All variables update happens inside GUI control functions
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawLine(GetScreenWidth() - GetScreenHeight(), 0, GetScreenWidth() - GetScreenHeight(), GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(0, 0, GetScreenWidth() - 600, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
        draw_graph();
        box_eq(0);
        box_eq(1);
        add_button(2);
        // if (drawRing) DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3f));

        DrawFPS(GetScreenWidth() - 100, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

int box_eq(int i)
{
    bool showEq = true;

    if (showEq)
    {
        show_eq();
    }

    // Draw GUI controls
    //------------------------------------------------------------------------------
    showEq = GuiCheckBox((Rectangle){15, i*60 + 15 + 10, 20, 20}, "\0", showEq);
    DrawRectangleLines(50, i*60 + 10, 235, 50, BLACK);
    DrawText("y=mx+c", 50 + 10, i*60 + 10 + 10, 30, GREEN);
}

int add_button(int i){
    GuiButton((Rectangle) {15, i*60 + 10, 270, 50}, "Add Equation");
}