#include "raylib.h"
#include <math.h>

void draw_hyperbola(float a, float b, Color col);

int draw_graph()
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;

    // Line testing
    Vector3 start = {0.0f, 0.0f, 0.0f};
    Vector3 end = {10.0f, 10.0f, 10.0f};

    Camera3D camera = {0};
    camera.position = (Vector3){5.0f, 10.0f, 0.0f}; // Camera position
    camera.target = (Vector3){5.0f, 0.0f, 0.0f};    // Camera looking at point
    camera.up = (Vector3){0.0f, 0.0f, 10.0f};       // Camera up vector (rotation towards target)
    camera.fovy = 90.0f;                            // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;
    // Making graph grid line
    BeginMode3D(camera);
    DrawGrid(40, 0.5f);
    EndMode3D();
    // Marking the origin
    DrawText("O", centerX, centerY, 2.0f, MAROON);
    // For Quadratic Equation
}

int show_eq()
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;

    Vector2 quadstartPos = {centerX + 400, centerY + 500};
    Vector2 quadendPos = {centerX + 400, centerY - 500};
    Vector2 quadControl = {centerX - 400, centerY};
    Vector2 quadControl2 = {centerX + 400, centerY + 500};

    Vector3 start = {0.0f, 0.0f, 0.0f};
    Vector3 end = {10.0f, 10.0f, 10.0f};
    DrawLine3D(start, end, PURPLE);
    DrawLineBezierQuad(quadstartPos, quadendPos, quadControl, 2.0f, BLUE);

    // Drawing Ellipse
    DrawEllipseLines(centerX, centerY, 300.0f, 200.0f, BEIGE);
    DrawLineBezierCubic(quadstartPos, quadendPos, quadControl, quadControl2, 2.0f, GREEN);
    draw_hyperbola(1, 1, BLACK);
}

void draw_hyperbola(float a, float b, Color col)
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;
    Vector2 P1 = {centerX + 30 * a * 2, centerY + 30 * b * sqrt(3)};
    Vector2 P2 = {centerX + 2 / 3 * 30 * a, centerY + 30 * b * (48 - 26 * sqrt(3)) / 18};
    Vector2 P3 = {centerX + 2 / 3 * 30 * a, centerY - 30 * b * (48 - 26 * sqrt(3)) / 18};
    Vector2 P4 = {centerX + 30 * 2 * a, centerY - 30 * b * sqrt(3)};
    Vector2 El = {centerX + 20 * 15, centerY + 20 * (b / a) * 13};
    Vector2 El2 = {centerX + 20 * 15, centerY - 20 * (b / a) * 13};
    DrawLineBezierCubic(P1, P4, P2, P3, 2.0f, col);
    DrawLineEx(P1, El, 2.0f, col);
    DrawLineEx(P4, El2, 2.0f, col);

    Vector2 q1 = {centerX - 30 * a * 2, centerY + 30 * b * sqrt(3)};
    Vector2 q2 = {centerX - 2 / 3 * 30 * a, centerY + 30 * b * (48 - 26 * sqrt(3)) / 18};
    Vector2 q3 = {centerX - 2 / 3 * 30 * a, centerY - 30 * b * (48 - 26 * sqrt(3)) / 18};
    Vector2 q4 = {centerX - 30 * 2 * a, centerY - 30 * b * sqrt(3)};
    Vector2 Eql = {centerX - 20 * 15, centerY + 20 * (b / a) * 13};
    Vector2 Eql2 = {centerX - 20 * 15, centerY - 20 * (b / a) * 13};
    DrawLineBezierCubic(q1, q4, q2, q3, 2.0f, col);
    DrawLineEx(q1, Eql, 2.0f, col);
    DrawLineEx(q4, Eql2, 2.0f, col);
}