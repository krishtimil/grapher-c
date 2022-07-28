#include <raylib.h>
// TODO: SlideListView
// custom header
#include "ui.h"
#include "graph.h"
#include "structures.h"

Window windows[4] = { {false, "Polynomial", 5, {
	{false, "Linear", 2, {0}}, {false, "Quadratic in X", 3, {0}},{false,  "Quadratic in Y",3, {0}}, {false, "Cubic in X",4, {0}},{false,  "Cubic in Y",4, {0}}}},
					 {false, "Conic Section", 4, {
		{false, "Ellipse",2, {0}}, {false, "Parabola",1, {0}}, {false, "Hyperbola",2, {0}}, {false, "Circle",1, {0}}}},
					 {false, "Trigonometric", 3, {
		{false, "Sin",3, {0}}, {false, "Cos",3, {0}}, {false, "Tan",3, {0}}}},
					 {false, "Exponential", 3, {
		{false, "e^(ax)",1, {0}}, {false, "a^x",1, {0}}, {false, "log(base a)x",1, {0}}}} };
// no of equations


int num_eq = 0;
bool window_Active = false;


bool editMode = true;

int init_window()
{
	const int screenWidth = 900;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Grapher-C");
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor())); // Set our game to run at max refresh rate of monitor
	/*Font font = LoadFontEx('res/Monospace.otf', 32, 0, 250);
	GuiSetFont(font);*/
}

int draw_sections()
{
	ClearBackground(RAYWHITE);
	DrawLine(GetScreenWidth() - GetScreenHeight(), 0, GetScreenWidth() - GetScreenHeight(), GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
	DrawRectangle(0, 0, GetScreenWidth() - 600, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
	draw_graph();
}

int draw_boxes() {
	for (int i = 0; i < num_eq; i++)
		box_eq(i);
}

int window_add()
{
	if (num_eq < 8 && GuiButton((Rectangle) { 15, num_eq * 70 + 20, 270, 50 }, "Add Equation"))
	{
		window_Active = true;
		// num_eq++;
	}

	if (window_Active)
	{
		window_Active = !GuiWindowBox((Rectangle) { 150, 45, 250, 320 }, "Add Equation");
		for (int i = 0; i < 4; i++)
		{
			if (GuiButton((Rectangle) { 165, i * 70 + 90, 220, 50 }, windows[i].label))
			{
				// to prevent duplication of windows
				for (int j = 0; j < 4; j++)
				{
					if (i != j)
						windows[j].show = false;
					else {
						windows[j].show = true;
					}
				}
			}
		}
	}
}


int window_type()
{
	for (int i = 0; i < 4; i++) {
		if (windows[i].show)
		{
			windows[i].show = !GuiWindowBox((Rectangle) { 390, 75, 250, 70 * windows[i].typelen + 40 }, windows[i].label);

			for (int j = 0; j < windows[i].typelen; j++)
			{
				if (GuiButton((Rectangle) { 405, j * 70 + 120, 220, 50 }, windows[i].types[j].label)) {
					for (int k = 0; k < windows[i].typelen; k++)
					{
						if (j != k)
							windows[i].types[k].show = false;
						else
							windows[i].types[k].show = true;
					}
				}
			}
		}
	}
}

int window_input()
{
	
	//value = GuiSliderBar((Rectangle) { 600, 140, 120, 20 }, "InnerRadius", NULL, value, 0, 100);
	

	/*if (GuiSpinner((Rectangle) { 300, 500, 100, 40 }, "Hello", & value, 0, 10, editMode) ){
		editMode = !editMode;
	}*/
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
	equation_arr[i].show = GuiCheckBox((Rectangle) { 15, i * 70 + 15 + 20, 20, 20 }, "\0", equation_arr[i].show);
	DrawRectangleLines(50, i * 70 + 20, 235, 50, BLACK);
	DrawText(equation_arr[i].label, 50 + 10, i * 70 + 20 + 10, 30, GREEN);
}
