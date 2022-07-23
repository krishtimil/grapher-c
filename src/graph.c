#include "raylib.h"

int draw_graph()
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
    DrawGrid(50, 0.5f);
    DrawLine3D(start, end, PURPLE);
    EndMode3D();
    // Marking the origin
    DrawText("O", centerX, centerY, 2.0f, MAROON);
    // For Quadratic Equation
    DrawLineBezierQuad(quadstartPos, quadendPos, quadControl, 2.0f, BLUE);
    // Drawing Ellipse
    DrawEllipseLines(centerX, centerY, 300.0f, 200.0f, BEIGE);
    DrawLineBezierCubic(quadstartPos, quadendPos, quadControl, quadControl2, 2.0f, YELLOW);
}