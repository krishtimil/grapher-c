#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for GUI controls
#include "equation.h"
#include "graph.h"

Equation equation_arr[8];

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
    int i = 0;

    // For testing purposes
    equation_arr[0].label = "mx+y=z";
    equation_arr[0].col = GREEN;
    equation_arr[0].show = false;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawLine(GetScreenWidth() - GetScreenHeight(), 0, GetScreenWidth() - GetScreenHeight(), GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(0, 0, GetScreenWidth() - 600, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
        draw_graph();

        for (int j = 0; j < i; j++)
            box_eq(j);

        if (i < 8 && GuiButton((Rectangle){15, i * 70 + 20, 270, 50}, "Add Equation"))
        {
            i++;
        }

        DrawFPS(GetScreenWidth() - 100, 10); // Displays FPS on Screen

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
    bool showEq = equation_arr[i].show;

    if (showEq)
    {
        show_eq();
    }

    // Draw GUI controls
    //------------------------------------------------------------------------------
    equation_arr[i].show = GuiCheckBox((Rectangle){15, i * 70 + 15 + 20, 20, 20}, "\0", equation_arr[i].show);
    DrawRectangleLines(50, i * 70 + 20, 235, 50, BLACK);
    DrawText(equation_arr[i].label, 50 + 10, i * 70 + 20 + 10, 30, GREEN);
}
