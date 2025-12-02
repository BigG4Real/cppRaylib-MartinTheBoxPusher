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

int currentMap = 0;
int CurrentTime;

void gameLocic(Cords* cords, Martin* martin, Level* level){
  
  CurrentTime++;
  
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
  if(IsKeyPressed(KEY_SPACE)){
    level->Generate(currentMap, cords);
  }
  #pragma endregion
}

int main()
{
  InitWindow(screenWidth, screenHeight, "Martin The Box Pusher / Sokoban");
  InitAudioDevice(); 

  // Sigman pekar till rätt ställe...
  Martin* martin = new Martin;
  Cords* cords = new Cords;
  Level* level = new Level;

  martin->cords = cords;

  SetTargetFPS(60);

  //sounds
  Sound music = LoadSound(ASSETS_PATH"Music.ogg");  
  PlaySound(music);

  //Game loop
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    //Jag vet att jag borde lägga detta i en funktion fast orkar inte :c    
    if(currentMap == 0){
      float Size = 50;
      DrawText("Use the arrows key to move or use wasd.", 50, 50, Size, SIXSEVEN);
      DrawText("Try to be as fast as possible to not lose score!", 50, 50 + Size, Size, SIXSEVEN);
      DrawText("The more you move the more score you will lose!", 50, 50 + (Size * 2), Size, SIXSEVEN);
      DrawText("If you get stuck press spacebar to reload!", 50, 50 + (Size * 3), Size, SIXSEVEN);
      DrawText("Push all of the boxes (oranges thing) to the", 50, 100 + (Size * 4), Size, SIXSEVEN);
      DrawText("win points (the red things) to win!!!", 50, 100 + (Size * 5), Size, SIXSEVEN);
      DrawText("Pres any key to start!", 50, 100 + (Size * 7), Size, SIXSEVEN);
      if(GetKeyPressed()){
        currentMap++;
        martin->amountOfSteps = 0;
        CurrentTime = 0;
        level->Generate(currentMap, cords);

      }
    }
    else if(currentMap >= 3){
      float Size = 100;
      int score = ((999999 / martin->amountOfSteps) / (CurrentTime / 60)) * 400;
      DrawText(TextFormat("Amount of steps: %03i", martin->amountOfSteps), 50, 50, Size, SIXSEVEN);
      DrawText(TextFormat("Time: %04i", (CurrentTime / 60)), 50, 50 + Size, Size, SIXSEVEN);
      DrawText(TextFormat("Score: %03i", score), 50, 50 + (Size * 2), Size, SIXSEVEN);
    }
    else if(currentMap >= 3 || currentMap != 0){
      gameLocic(cords, martin, level);
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