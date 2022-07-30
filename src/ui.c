#include <raylib.h>

// TODO: SlideListView
// custom header
#include "ui.h"
#include "graph.h"
#include "structures.h"

Window windows[4] = {
	{"Polynomial", 5, {
					{"linear", 2, {0}},
					{"quadratic_x", 3, {0}},
					{ "quadratic_y",3, {0}},
					{"cubic_x",4, {0}},
					{ "cubic_y",4, {0}}
				}
		},
	{"Conic Section", 4, {
					{"ellipse",2, {0}},
					{"parabola",1, {0}},
					{"hyperbola",2, {0}},
					{"circle",1, {0}}
				}
		},
	{"Trigonometric", 3, {
					{"sin",3, {0}},
					{"cos",3, {0}},
					{"tan",3, {0}}
				}
		},
	{"Exponential", 3, {
					{"e_ax",1, {0}},
					{"a_x",1, {0}},
					{"log_a_x",1, {0}}
				}
		}
};

//arrays for list view
char* window_category[4] = { "Polynomial", "Conic Section", "Trigonometric", "Exponential" };
char* window_type[4][5] = {
	{"Linear", "Quadratic in X", "Quadratic in Y", "Cubic in X", "Cubic in Y"},
	{"Ellipse", "Parabola", "Hyberbola", "Circle"},
	{"Sin", "Cos", "Tan"},
	{"e^(ax)", "a^x", "log(base a) x"}
};

char* vars[] = { "a:", "b:", "c:", "d:" };



// no of equations
int num_eq = 0;
bool window_Active = false;
bool added = false;

//for list view
int current_category = 0;
int current_type = 0;


bool editMode = true;

int init_window()
{
	const int screenWidth = 900;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Grapher-C");
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor())); // Set our game to run at max refresh rate of monitor
	/*Font font = LoadFontEx("res/Monospace.otf", 32, 0, 250);
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
	if (num_eq < 5 && GuiButton((Rectangle) { 15, num_eq * 120 + 10, 270, 50 }, "Add Equation"))
	{
		window_Active = true;
		//num_eq++;
	}

	if (window_Active)
	{
		//add data

		window_Active = !GuiWindowBox((Rectangle) { 150, 45, 400, 310 }, "Add Equation");
		GuiGroupBox((Rectangle) { 155, 80, 190, 265 }, "Category");
		current_category = GuiListViewEx((Rectangle) { 160, 90, 180, 250 }, window_category, 4, 0, NULL, current_category);
		GuiGroupBox((Rectangle) { 355, 80, 190, 215 }, "Type");
		current_type = GuiListViewEx((Rectangle) { 360, 90, 180, 200 }, window_type[current_category], windows[current_category].typelen, 0, NULL, current_type);
		added = GuiButton((Rectangle) { 355, 300, 190, 45 }, "Add");
		if (added) {
			window_Active = false;
			Color colors[] = { RED, YELLOW, PURPLE, MAGENTA, DARKGREEN, DARKPURPLE ,BROWN, BEIGE };
			equation_arr[num_eq].color = colors[(GetRandomValue(0, 7))];
			equation_arr[num_eq].type = windows[current_category].types[current_type];
			equation_arr[num_eq].show = false;
			num_eq++;
		}
	}
}


int box_eq(int i)
{
	bool showEq = equation_arr[i].show;

	if (showEq)
	{
		show_eq(equation_arr[i].type.label, 1, 1, 0, 0, equation_arr[i].color);
		sliders(i);
	}

	// Draw GUI controls
	//------------------------------------------------------------------------------
	equation_arr[i].show = GuiCheckBox((Rectangle) { 15, 15 + 120*i, 20, 20 }, "\0", equation_arr[i].show);
	DrawRectangleLines(50, 5 + 120 * i, 235, 40, BLACK);
	DrawText(equation_arr[i].type.label, 50 + 10,10 +120*i, 25, equation_arr[i].color);

	//equation_arr[i].show = GuiCheckBox((Rectangle) { 15, 5 + 35 * i + 79 * i + 7.5f, 20, 20 }, "\0", equation_arr[i].show);
	//DrawRectangleLines(50, 5 + 35 * i + 79 * i, 235, 35, BLACK);
	//DrawText(equation_arr[i].type.label, 50 + 10, 5 + 35 * i + 79 * i + 7, 25, equation_arr[i].color);

}

int sliders(int i) {
	GuiGroupBox((Rectangle) {15, 55 + 120 * i, 270, 60}, "Variables");
	for (int j = 0; j < equation_arr[i].type.var_num; j++) {
		float xcor = (j % 2 == 0) ? 30 : 160 ;
		float ycor = 120 * i + ((j / 2 != 0) ? 25 : 0);
		if (equation_arr[i].type.var_num <= 2)
			ycor += 75;
		else
			ycor += 65;
		DrawText(vars[j], xcor, ycor, 20, GRAY);
		equation_arr[i].type.value[j] = GuiSlider((Rectangle) {xcor+40, ycor , 60, 20}, "-10", "10", equation_arr[i].type.value[j], -10, 10);
	}
}

