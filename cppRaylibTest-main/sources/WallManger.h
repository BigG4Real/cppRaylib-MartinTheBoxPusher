#include "raylib.h"
#include <raymath.h>
#pragma once

class WallManger{
    public:
      bool isUsed = false;
      Vector2 pos;
      Vector2 lenght;
      Color color;
      bool isPushable = false;
      void DrawWall();
};