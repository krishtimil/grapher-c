#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "graph.h"


int init_ui(){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char title[40] = "Grapher - 2d graph plotter";
    
    InitWindow(screenWidth, screenHeight, title);
    
    Font font_default = LoadFontEx("resources/euler.otf", 32, 0, 250);

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
       
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        // BeginDrawing();
        //     GuiCheckBox((Rectangle) {10,20,20,20}, "", false);
        //     GuiLabel((Rectangle) {10,20,30,40}, "Hello");

        // EndDrawing();

        draw_graph();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;

}