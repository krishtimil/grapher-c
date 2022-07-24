#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for GUI controls

//custom header files
#include "structures.h"
#include "ui.h"
#include "graph.h"

//initialize array of euqations
Equation equation_arr[8];

int main(void)
{
	//init window
	init_window();
	//no of equations
	int num_eq = 0;

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
	
	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		BeginDrawing();

		//Draws sections of main window
		draw_sections();
		// initialize euqations box num_eq times
		for (int j = 0; j < num_eq; j++)
			box_eq(j);

		if (num_eq < 8 && GuiButton((Rectangle){15, num_eq * 70 + 20, 270, 50}, "Add Equation"))
		{
			window_Active = true;
			// i++;
		}

		if (window_Active)
		{
			window_Active = !GuiWindowBox((Rectangle){150, 50, 300, 320}, "Add Equation");
			draw_window_buttons();
			
		}

		draw_2ndwin();

		DrawFPS(GetScreenWidth() - 100, 10); // Displays FPS on Screen

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow(); // Close window and OpenGL context

	return 0;
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


