#include "raylib.h"

int draw_graph(){
    //--------------------------------------------------------------------------------------
    const int screenWidth = 720;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Grapher Project");
        
        
        const int centerX= screenWidth/2;
        const int centerY= screenHeight/2;

    // Defining thye camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 0.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 0.0f, 10.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 90.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //-------------------------------------------------------    -------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


    //Quadratic testing
    Vector2 quadstartPos = {centerX+400,centerY+500};
    Vector2 quadendPos ={centerX+400,centerY-500};
    Vector2 quadControl = {centerX-400,centerY};
    Vector2 quadControl2 = {centerX+400,centerY +500};

    // Line testing
    Vector3 start = {0.0f, 0.0f, 0.0f};
    Vector3 end = {10.0f, 10.0f, 10.0f};


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Making graph grid line
            BeginMode3D(camera);
                DrawGrid(100, 0.5f);
                DrawLine3D(start, end, PURPLE);
            EndMode3D();
                // Title (kinda)
                DrawText("Grapher!", 10, 40, 20, DARKGRAY);
                // Marking the origin
                DrawText("O", centerX, centerY, 2.0f, MAROON);
                // For Quadratic Equation
                DrawLineBezierQuad(quadstartPos, quadendPos,quadControl, 2.0f, BLUE);
                // Drawing Ellipse
                DrawEllipseLines(centerX, centerY, 300.0f, 200.0f, BEIGE);
                DrawLineBezierCubic(quadstartPos, quadendPos,quadControl, quadControl2, 2.0f, YELLOW);


            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}