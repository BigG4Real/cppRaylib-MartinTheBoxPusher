#include "raylib.h"
#include <raymath.h>
#include "WallManger.h"
#pragma once

class Main{
  public:
    static WallManger wall[100];
    static Vector2 HandlePlayerInput();
    static WallManger makeWall(float posX, float posY, float lenghtX, float lenghtY, Color Color, bool push);
    static int GetAUnusedWall(int sizeOfWall);

};