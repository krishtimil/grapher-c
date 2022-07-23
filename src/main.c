#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for GUI controls
#include "equation.h"
#include "graph.h"

Equation equation_arr[8];
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 900;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Grapher-C");

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor())); // Set our game to run at max refresh rate of monitor
	//--------------------------------------------------------------------------------------
	int i = 0;

	// For testing purposes
	equation_arr[0].label = "mx+y=z";
	equation_arr[0].col = GREEN;
	equation_arr[0].show = false;
	equation_arr[0].type = "quadratic_x";
	// testing quad y
	equation_arr[1].label = "quad=y";
	equation_arr[1].col = BLUE;
	equation_arr[1].show = false;
	equation_arr[1].type = "quadratic_y";
	// sine testing
	equation_arr[2].label = "y=asin(bx+c)";
	equation_arr[2].col = MAROON;
	equation_arr[2].show = false;
	equation_arr[2].type = "sine";
	// tan testing
	equation_arr[3].label = "y=acos(bx+c)";
	equation_arr[3].col = PURPLE;
	equation_arr[3].show = false;
	equation_arr[3].type = "cos";
	// hyperbola testing
	equation_arr[4].label = "x^2/a^2 -y^2/b^2 =1";
	equation_arr[4].col = RED;
	equation_arr[4].show = false;
	equation_arr[4].type = "hyperbola";
	// ellipse testing
	equation_arr[5].label = "x^2/a^2 +y^2/b^2 =1";
	equation_arr[5].col = DARKGREEN;
	equation_arr[5].show = false;
	equation_arr[5].type = "ellipse";

	bool window_Active = false;
	bool window_poly = false;
	bool button_conic = false;
	bool button_trig = false;
	bool button_exp = false;

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
			window_Active = true;
		}

		if (window_Active)
		{
			window_Active = !GuiWindowBox((Rectangle){150, 50, 300, 320}, "Add Equation");
			if(GuiButton((Rectangle){165, 0 * 70 + 90, 270, 50}, "Polynomial"))
				window_poly = true;
			button_conic = GuiButton((Rectangle){165, 1 * 70 + 90, 270, 50}, "Conic Section");
			button_trig = GuiButton((Rectangle){165, 2 * 70 + 90, 270, 50}, "Trigonometric");
			button_exp = GuiButton((Rectangle){165, 3 * 70 + 90, 270, 50}, "Exponential");
		}

		if(window_poly){
			window_poly = !GuiWindowBox((Rectangle){200, 100, 300, 320}, "Polynomial");
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
		show_eq(equation_arr[i].type, 2, 5, 6, 0, equation_arr[i].col);
	}

	// Draw GUI controls
	//------------------------------------------------------------------------------
	equation_arr[i].show = GuiCheckBox((Rectangle){15, i * 70 + 15 + 20, 20, 20}, "\0", equation_arr[i].show);
	DrawRectangleLines(50, i * 70 + 20, 235, 50, BLACK);
	DrawText(equation_arr[i].label, 50 + 10, i * 70 + 20 + 10, 30, GREEN);
}
