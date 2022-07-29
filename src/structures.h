#ifndef STRUCTURE_H
#define STRUCTURE_H
#include "raylib.h"


typedef struct Type {
    char* label;
    int var_num;
    float value[4];
}Type;


typedef struct Equation
{
    char *label;
    Type type;
    bool show;
    Color color;
} Equation;

extern Equation equation_arr[8];


typedef struct Window
{
    char *label;
    int typelen;
    Type types[5];
    Color col;
} Window;


extern Window windows[4];
#endif