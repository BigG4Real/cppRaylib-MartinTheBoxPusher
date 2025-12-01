//Tar in andra scripts
#include "SceneManger.h"
#include "WallManger.h"
#include "martin.h"
#include "CordsHandler.h"

//Olika biblotek
#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <list>

//Raylib sigman
#include "raylib.h"
#include <raymath.h>

using namespace std;

const int screenWidth = GetMonitorWidth(0);
const int screenHeight = GetMonitorHeight(0);

int widthOfMap = 19;
int heightOfMap = 11;

int main()
{
  InitWindow(screenWidth, screenHeight, "Martin The Box Pusher");

  // Sigman pekar till rätt ställe...
  Martin* martin = new Martin;
  Cords* cords = new Cords;
  Level* level = new Level;

  martin->cords = cords;

  //Gör cordinat fält
  cords->MakeVectorNet(19,11);
  level->MapOne(cords);

  SetTargetFPS(120);

  //Game loop
  while (!WindowShouldClose())
  {    
    BeginDrawing();
    ClearBackground(BLACK);

    #pragma region DrawInCords
    cords->DrawEvrethingInCords();
    #pragma endregion

    #pragma region Martin das sigma
    martin->UpdateMartinPos();
    #pragma endregion

    #pragma region Win Points
    level->DrawWin(cords);
    #pragma endregion
    
    EndDrawing();
  }
  CloseWindow();
  return 0;
}