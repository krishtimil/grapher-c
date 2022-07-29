#include "raylib.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI_2 1.57079

void draw_log(float a, Color col);
void hyperbola(float a, float b, Color col);
void ellipse(float a, float b, Color col);
void linear(float a, float b, Color col);
void quadratic_y(float a, float b, float c, Color col);
void quadratic_x(float a, float b, float c, Color col);
void draw_sine(float a, float b, float c, Color col);
void draw_tan(float a, float b, float c, Color col);
void cubic_y(float a, float b, float c, float d, Color col);
void cubic_x(float a, float b, float c, float d, Color col);

int draw_graph()
{
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;

	// Line testing
	Vector3 start = { 0.0f, 0.0f, 0.0f };
	Vector3 end = { 10.0f, 10.0f, 10.0f };

	Camera3D camera = { 0 };
	camera.position = (Vector3){ 5.0f, 10.0f, 0.0f }; // Camera position
	camera.target = (Vector3){ 5.0f, 0.0f, 0.0f };	// Camera looking at point
	camera.up = (Vector3){ 0.0f, 0.0f, 10.0f };		// Camera up vector (rotation towards target)
	camera.fovy = 90.0f;							// Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;
	// Making graph grid line
	BeginMode3D(camera);
	DrawGrid(40, 0.5f);
	EndMode3D();
	// Marking the origin
	DrawText("O", centerX, centerY, 2.0f, MAROON);
}

int show_eq(char* type, int a, int b, int c, int d, Color col)
{
	// type = tolower(type);
	// srand(1234);
	// Color colors[] = {GREEN, RED, GREEN, YELLOW, PURPLE, MAGENTA, DARKGREEN, DARKRED, DARKPURPLE};
	// col = colors[floor(rand()*4)];
	floor(rand() * 10);
	if (!strcmp(type, "quadratic_x"))
		quadratic_x(a, b, c, col);
	if (!strcmp(type, "quadratic_y"))
		quadratic_y(a, b, c, col);
	if (!strcmp(type, "sine"))
		draw_sine(a, b, c, col);
	if (!strcmp(type, "cos"))
		draw_sine(a, b, c + PI_2, col);
	if (!strcmp(type, "tan"))
		draw_tan(a, b, c, col);
	if (!strcmp(type, "hyperbola"))
		hyperbola(a, b, col);
	if (!strcmp(type, "ellipse"))
		ellipse(a, b, col);
	if (!strcmp(type, "cubic_x"))
		cubic_x(a, b, c, d, col);
	if (!strcmp(type, "cubic_y"))
		cubic_y(a, b, c, d, col);
	if (!strcmp(type, "ellipse"))
		ellipse(a, b, col);
	if (!strcmp(type, "linear"))
		linear(a, b, col);
	if (!strcmp(type, "log_a_x"))
		draw_log(a, col);
}

void draw_log(float a, Color col) {
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;

	if (a > 0 && a != 1) {
		// from origin to 0.001
		float x1, y1, x2, y2;
		int j = 0;
		x1 = 0.0001 * 15;
		y1 = 600;
		x2 = 0.001 * 15;
		y2 = ((float)log(0.001) / (float)log(a)) * 15;


		DrawLineEx((Vector2) { centerX + x1, y1 }, (Vector2) {
			centerX + x2, centerY - y2
		}, 2.0f, col);

		// for range 0.001 to 1
		for (float i = 0.001; i < 1; i += 0.001, j++) {

			if (j % 2 == 0) {
				x1 = i;
				y1 = ((float)log(i) / (float)log(a));
			}
			else {
				x2 = i;
				y2 = ((float)log(i) / (float)log(a));
			}
			DrawLineEx((Vector2) { centerX + x1 * 15, centerY - y1 * 15 }, (Vector2) { centerX + x2 * 15, centerY - y2 * 15 }, 2.0f, col);
		}

		// for range 1 to 20
		for (int i = 1; i <= 20; i += 1) {
			if (i % 2 == 0) {
				x1 = i;
				y1 = ((float)log(i) / (float)log(a));
			}
			else {
				x2 = i;
				y2 = ((float)log(i) / (float)log(a));
			}
			DrawLineEx((Vector2) { centerX + x1 * 15, centerY - y1 * 15 }, (Vector2) { centerX + x2 * 15, centerY - y2 * 15 }, 2.0f, col);
		}
	}

}

void linear(float a, float b, Color col)
{
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;


	int rightEdgeX = (centerX / 2) / 15;
	int rightEdgeY = a * rightEdgeX + b;
	int leftEdgeX = (-centerX / 2) / 15;
	int leftEdgeY = a * leftEdgeX + b;

	if (rightEdgeY <= 20 || leftEdgeY <= 20) {
		Vector2 start = { centerX + rightEdgeX * 15, centerY - rightEdgeY * 15 };
		Vector2 end = { centerX + leftEdgeX * 15, centerY - leftEdgeY * 15 };
		DrawLineEx(start, end, 2.0f, col);
	}

}

void ellipse(float a, float b, Color col)
{
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;
	DrawEllipseLines(centerX, centerY, a * 15, b * 15, col);
}

void hyperbola(float a, float b, Color col)
{
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;
	Vector2 P1 = { centerX + 30 * a * 2, centerY + 30 * b * sqrt(3) };
	Vector2 P2 = { centerX + 2 / 3 * 30 * a, centerY + 30 * b * (48 - 26 * sqrt(3)) / 18 };
	Vector2 P3 = { centerX + 2 / 3 * 30 * a, centerY - 30 * b * (48 - 26 * sqrt(3)) / 18 };
	Vector2 P4 = { centerX + 30 * 2 * a, centerY - 30 * b * sqrt(3) };
	Vector2 El = { centerX + 20 * 15, centerY + 20 * (b / a) * 13 };
	Vector2 El2 = { centerX + 20 * 15, centerY - 20 * (b / a) * 13 };
	DrawLineBezierCubic(P1, P4, P2, P3, 2.0f, col);
	DrawLineEx(P1, El, 2.0f, col);
	DrawLineEx(P4, El2, 2.0f, col);

	Vector2 q1 = { centerX - 30 * a * 2, centerY + 30 * b * sqrt(3) };
	Vector2 q2 = { centerX - 2 / 3 * 30 * a, centerY + 30 * b * (48 - 26 * sqrt(3)) / 18 };
	Vector2 q3 = { centerX - 2 / 3 * 30 * a, centerY - 30 * b * (48 - 26 * sqrt(3)) / 18 };
	Vector2 q4 = { centerX - 30 * 2 * a, centerY - 30 * b * sqrt(3) };
	Vector2 Eql = { centerX - 20 * 15, centerY + 20 * (b / a) * 13 };
	Vector2 Eql2 = { centerX - 20 * 15, centerY - 20 * (b / a) * 13 };
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

void draw_sine(float a, float b, float c, Color col)
{
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;
	for (float i = -10000; i < 10000; i = i + 1)
	{
		int x = i / 5;
		int y = -a * 15 * sin((b * i) / 75);
		if (x + centerX - c * 15 >= 300)
		{
			DrawPixel(x + centerX - c * 15, y + centerY - 1, col);
		}
	}
}

void draw_tan(float a, float b, float c, Color col)
{
	int centerX = GetScreenWidth() - GetScreenHeight() / 2;
	int centerY = GetScreenHeight() / 2;
	for (float i = -10000; i < 10000; i = i + 1)
	{
		int x1, y1;
		int x = i / 5;
		int y = -a * 15 * tan((b * i) / 75);
		if (x + centerX - c * 15 >= 300)
		{
			DrawPixel(x + centerX - c * 15, y + centerY - 1, col);
			// if(i>=-1000)
			DrawLine(x1 + centerX - c * 15, y1 + centerY - 1, x + centerX - c * 15, y + centerY - 1, col);
			// DrawLine(x2+centerX-c*15,y2+centerY-1,x+centerX-c*15,y+centerY-1,col);
			// int x2=x1;
			// int y2=y1;
		}
		x1 = x;
		y1 = y;
	}
}
