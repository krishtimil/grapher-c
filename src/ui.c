#include <raylib.h>

// custom header
#include "ui.h"
#include "graph.h"
#include "structures.h"

Window windows[4] = { {false, "Polynomial", 5, {"Linear", "Quadratic in X", "Quadratic in Y", "Cubic in X", "Cubic in Y"}},
					 {false, "Conic Section", 4, {"Ellipse", "Parabola", "Hyperbola", "Circle"}},
					 {false, "Trigonometric", 3, {"Sin", "Cos", "Tan"}},
					 {false, "Exponential", 3, {"e^x", "a^x", "log(base a)x"}} };

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
        {

            // to prevent duplication of windows
            for (int j = 0; j < 4; j++)
            {
                if (i != j)
                    windows[j].show = false;
                else
                    windows[j].show = true;
            }
        }
    }
}

int draw_2ndwin()
{
    for (int i = 0; i < 4; i++)
    {
        if (windows[i].show)
        {
            windows[i].show = !GuiWindowBox((Rectangle){200, 100, 300, 70 * windows[i].typelen + 40}, windows[i].label);

            for (int j = 0; j < windows[i].typelen; j++)
            {
                GuiButton((Rectangle){215, j * 70 + 140, 270, 50}, windows[i].types[j]);
            }
        }
    }
}

int box_eq(int i)
{
    bool showEq = equation_arr[i].show;

    if (showEq)
    {
        show_eq(equation_arr[i].type, 1, 1, 0, 0, equation_arr[i].col);
    }

    // Draw GUI controls
    //------------------------------------------------------------------------------
    equation_arr[i].show = GuiCheckBox((Rectangle){15, i * 70 + 15 + 20, 20, 20}, "\0", equation_arr[i].show);
    DrawRectangleLines(50, i * 70 + 20, 235, 50, BLACK);
    DrawText(equation_arr[i].label, 50 + 10, i * 70 + 20 + 10, 30, GREEN);
}
