#include <raylib.h>

// custom header
#include "ui.h"
#include "graph.h"
#include "structures.h"

Window windows[5] = {{false, "Polynomial"},
                     {false, "Conic Section"},
                     {false, "Trigonometric"},
                     {false, "Exponential"}};

int init_window()
{
    const int screenWidth = 900;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Grapher-C");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor())); // Set our game to run at max refresh rate of monitor
}

int draw_sections()
{
    ClearBackground(RAYWHITE);
    DrawLine(GetScreenWidth() - GetScreenHeight(), 0, GetScreenWidth() - GetScreenHeight(), GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
    DrawRectangle(0, 0, GetScreenWidth() - 600, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
    draw_graph();
}

int draw_window_buttons()
{
    // loop for individual buttons

    for (int i = 0; i < 4; i++)
    {
        if (GuiButton((Rectangle){165, i * 70 + 90, 270, 50}, windows[i].label))
            windows[i].show = true;
    }
}

int draw_2ndwin()
{
    for (int i = 0; i < 4; i++)
    {
        if (windows[i].show)
        {
            windows[i].show = !GuiWindowBox((Rectangle){200, 100, 300, 320}, windows[i].label);
        }
    }
}

int win2nd_buttons()
{
    
}

