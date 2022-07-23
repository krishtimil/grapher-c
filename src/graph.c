#include "raylib.h"
#include <math.h>
#include <string.h>

void hyperbola(float a, float b, Color col);
void cubic_y(float a, float b, float c, float d, Color col);
void cubic_x(float a, float b, float c, float d, Color col);
void quadratic_y(float a, float b, float c, Color col);
void quadratic_x(float a, float b, float c, Color col);

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
}

int show_eq(char *type, int a, int b, int c, int d, Color col)
{
    //type = tolower(type);
    if (!strcmp(type, "quadratic_x"))
        quadratic_x(a,b,c,col);
    
}

void hyperbola(float a, float b, Color col)
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

void cubic_y(float a, float b, float c, float d, Color col)
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;
    for (float i = -10000; i < 10000; i = i + 1)
    {
        int x = i / 15 + centerX - 1;
        int y = ((-a * i * i * i + b * i * i * 229 - c * i * 52500) / 800000 + centerY);
        if (y + 300 + 1 + d * 15 >= 300)
        {
            DrawPixel(y + 300 + d * 15, x - 300, col);
            DrawPixel(y + 300 + 1 + d * 15, x - 300, col);
            if (b != 0)
                DrawPixel(y + 300 - 1 + d * 15, x - 300, col);
        }
    }
}

void cubic_x(float a, float b, float c, float d, Color col)
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;
    for (float i = -10000; i < 10000; i = i + 1)
    {
        int x = i / 15 + centerX - 1;
        int y = ((-a * i * i * i - b * i * i * 229 - c * i * 52500) / 800000 + centerY - d * 15);
        DrawPixel(x, y, col);
        DrawPixel(x, y - 1, col);
        DrawPixel(x, y + 1, col);
    }
}

void quadratic_y(float a, float b, float c, Color col)
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;

    /*for(float i=-10000;i<=10000;i=i+1)
                {
                    int x=i/15+centerX-1;
                    int y=((-a*i*i-b*i*229-c)/3500+centerY-1);
                    if(-y+897+c*15>=300)
                    DrawPixel(-y+897+c*15,x-300+122,col);
                }*/
    for (float i = -10000; i <= 10000; i = i + 1)
    {
        int x = i / 15 + centerX - 1;
        int y = ((-a * i * i + b * i * 229 - c) / 3500 + centerY);
        if (-y + 897 + c * 15 >= 300)
            DrawPixel(-y + 898 + c * 15, x - 300 + 2, col);
    }
}

void quadratic_x(float a, float b, float c, Color col)
{
    int centerX = GetScreenWidth() - GetScreenHeight() / 2;
    int centerY = GetScreenHeight() / 2;
    for (float i = -10000; i < 10000; i = i + 1)
    {
        int x = i / 15 + centerX - 1;
        int y = ((-a * i * i - b * i * 230 - c) / 3500 + centerY - c * 15);
        DrawPixel(x, y, col);
    }
    for (float i = -10000; i <= 10000; i = i + 1)
    {
        int x = i / 15 + centerX - 1;
        int y = ((-a * i * i - b * i * 230 - c) / 3500 + centerY - 1 - c * 15);
        DrawPixel(x, y, col);
    }
}
