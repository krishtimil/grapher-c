#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for GUI controls

void draws_graph();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int init_ui(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Grapher-C");

    Vector2 center = {(GetScreenWidth() - 300) / 2.0f, GetScreenHeight() / 2.0f};

    float innerRadius = 80.0f;
    float outerRadius = 190.0f;

    float startAngle = 0.0f;
    float endAngle = 360.0f;
    int segments = 0;
    int minSegments = 4;

    bool showGraph = true;
    bool drawRingLines = false;
    bool drawCircleLines = false;

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

        DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(500, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));

        // if (drawRing) DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3f));
        if (showGraph)
        {
            draws_graph();
        }
        if (drawRingLines)
            DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4f));
        if (drawCircleLines)
            DrawCircleSectorLines(center, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4f));

        // Draw GUI controls
        //------------------------------------------------------------------------------
        startAngle = GuiSliderBar((Rectangle){600, 40, 120, 20}, "StartAngle", NULL, startAngle, -450, 450);
        endAngle = GuiSliderBar((Rectangle){600, 70, 120, 20}, "EndAngle", NULL, endAngle, -450, 450);

        innerRadius = GuiSliderBar((Rectangle){600, 140, 120, 20}, "InnerRadius", NULL, innerRadius, 0, 100);
        outerRadius = GuiSliderBar((Rectangle){600, 170, 120, 20}, "OuterRadius", NULL, outerRadius, 0, 200);

        segments = (int)GuiSliderBar((Rectangle){600, 240, 120, 20}, "Segments", NULL, (float)segments, 0, 100);

        showGraph = GuiCheckBox((Rectangle){600, 320, 20, 20}, "Draw Ring", showGraph);
        drawRingLines = GuiCheckBox((Rectangle){600, 350, 20, 20}, "Draw RingLines", drawRingLines);
        drawCircleLines = GuiCheckBox((Rectangle){600, 380, 20, 20}, "Draw CircleLines", drawCircleLines);
        //------------------------------------------------------------------------------

        int minSegments = (int)ceilf((endAngle - startAngle) / 90);
        DrawText(TextFormat("MODE: %s", (segments >= minSegments) ? "MANUAL" : "AUTO"), 600, 270, 10, (segments >= minSegments) ? MAROON : DARKGRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void draws_graph()
{
    const int screenSize = 500;
    const int centerX = screenSize / 2;
    const int centerY = screenSize / 2;
    Vector2 quadstartPos = {centerX + 400, centerY + 500};
    Vector2 quadendPos = {centerX + 400, centerY - 500};
    Vector2 quadControl = {centerX - 400, centerY};
    Vector2 quadControl2 = {centerX + 400, centerY + 500};

    // Line testing
    Vector3 start = {0.0f, 0.0f, 0.0f};
    Vector3 end = {10.0f, 10.0f, 10.0f};

    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 10.0f, 0.0f}; // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};    // Camera looking at point
    camera.up = (Vector3){0.0f, 0.0f, 10.0f};       // Camera up vector (rotation towards target)
    camera.fovy = 90.0f;                            // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;
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
    DrawLineBezierQuad(quadstartPos, quadendPos, quadControl, 2.0f, BLUE);
    // Drawing Ellipse
    DrawEllipseLines(centerX, centerY, 300.0f, 200.0f, BEIGE);
    DrawLineBezierCubic(quadstartPos, quadendPos, quadControl, quadControl2, 2.0f, YELLOW);
}