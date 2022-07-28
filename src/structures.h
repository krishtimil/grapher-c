#ifndef STRUCTURE_H
#define STRUCTURE_H
#include "raylib.h"

typedef struct Equation
{
    char *label;
    Color col;
    char *type;
    bool show;
    int a;
    int b;
    int c;
    int d;
} Equation;

extern Equation equation_arr[8];

typedef struct Type {
    bool show;
	char *label;
    int var_num;
    float value[4];
}Type;

typedef struct Window
{
    bool show;
    char *label;
    int typelen;
    Type types[5];
} Window;


extern Window windows[4];
#endif