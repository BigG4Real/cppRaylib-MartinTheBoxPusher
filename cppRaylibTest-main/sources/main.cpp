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

int currentMap = 1;

int main()
{
  InitWindow(screenWidth, screenHeight, "Martin The Box Pusher / Sokoban");
  InitAudioDevice(); 

  // Sigman pekar till rätt ställe...
  Martin* martin = new Martin;
  Cords* cords = new Cords;
  Level* level = new Level;

  martin->cords = cords;

  //Gör cordinat fält
  level->Generate(currentMap, cords);

  SetTargetFPS(0);

  //sounds
  Sound music = LoadSound(ASSETS_PATH"Music.ogg");  
  PlaySound(music);

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
    if(level->CheckIfWin(cords) || IsKeyPressed(KEY_W)){
      currentMap++;
      cords->ResetMap();
      level->Generate(currentMap, cords);
    }
    if(IsKeyPressed(KEY_R)){
      level->Generate(currentMap, cords);
    }
    #pragma endregion

    if(currentMap >= 3){
      float Size = 670;
      DrawText("67", (screenWidth / 2) + (Size / 2) + 225, (screenHeight / 2)+ (Size / 2), Size, SIXSEVEN);
    }

    if(!IsSoundPlaying(music)){
      PlaySound(music);
    }
    EndDrawing();
  }
  UnloadSound(music);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}