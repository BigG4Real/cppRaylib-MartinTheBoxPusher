#include "raylib.h"
#include <raymath.h>
#pragma once

class SceneManger{

    public:
        int CurentRoom;
        void MakeRoom(int newRoomId, float sizeOfWall, float screenWidth, float screenHeight);

};