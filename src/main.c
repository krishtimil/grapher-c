#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for GUI controls

// custom header files
#include "structures.h"
#include "ui.h"
#include "graph.h"

// initialize array of euqations
Equation equation_arr[8];
float value = 50.0f;


int main(void)
{
	// init window
	init_window();
for (int k =0; k<5; k++){
	equation_arr[k].type = (Type) {"default",2, {0}};
	equation_arr[k].show = true;
	equation_arr[k].label = "default";
}

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		BeginDrawing();

		// Draws sections of main window
		draw_sections();
		// initialize euqations box num_eq times
		draw_boxes();

		//custom functions to draw window
		window_add();
		
		//code for input sliders
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < windows[i].typelen; j++) {
				if (windows[i].types[j].show)
				{
					windows[i].types[j].show = !GuiWindowBox((Rectangle) { 630, 150, 250, 70 * windows[i].types[j].var_num + 40 }, windows[i].types[j].label);
					for (int k = 0; k < windows[i].types[j].var_num; k++) {
						windows[i].types[j].value[k] = GuiSliderBar((Rectangle) { 645, 200 + k * 40, 120, 20 }, "-10", "10", windows[i].types[j].value[k], -10, 10);
					}
				}
			}
		}*/
		
		DrawFPS(GetScreenWidth() - 100, 10); // Displays FPS on Screen

		EndDrawing();
	}

	CloseWindow(); // Close window and OpenGL context

	return 0;
}
