#include "raylib.h"
#include <raymath.h>
#include "CordsHandler.h"
#include "WinPoint.h"
#pragma once

class Level{

    public:
        int Current;
        void Generate(int Current, Cords* cordsSystem);

        void MapOne(Cords* cordsSystem);
        void MapTwo(Cords* cordsSystem);

        void CreatSector(Cords* cordsSystem, int startX, int endX, int startY, int endY, DataType dataType);

        //Win points
        WinPoint winPoints[20];

        void DrawWin(Cords* cordsSystem);
        void MakeWinPoint(int posX, int posY);

        bool CheckIfWin(Cords* cordsSystem);
};