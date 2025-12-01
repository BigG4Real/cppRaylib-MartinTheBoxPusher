#include "raylib.h"
#include <raymath.h>
#include <vector>
#pragma once

enum DataType{
    nothing,
    wall,
    player,
    box,
    winThing
};

class getCords{
    public:
        DataType data = DataType(nothing);
        Vector2 pos;
        bool IsInUse;
};

class Cords{
    public:
        void MakeVectorNet(int width, int height);

        int Width;
        int Height;

        float SizeOfEvreything = 75;
        float Offsets = 25;

        getCords AllCords[2000];

        void DrawEvrethingInCords();
};
