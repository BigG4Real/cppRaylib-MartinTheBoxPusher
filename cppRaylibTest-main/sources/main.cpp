#include "SceneManger.h"
#include "WallManger.h"
#include "martin.h"
#include "main.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <list>

#include "raylib.h"
#include <raymath.h>

using namespace std;

const int screenWidth = 1920;
const int screenHeight = 1080;


Vector2 Main::HandlePlayerInput()
{
  Vector2 dir;
  dir.x = 0;
  dir.y = 0;
  if (IsKeyDown(KEY_RIGHT))
  {
    dir.x += 1;
  }
  if (IsKeyDown(KEY_LEFT))
  {
    dir.x -= 1;
  }
  if (IsKeyDown(KEY_DOWN))
  {
    dir.y += 1;
  }
  if (IsKeyDown(KEY_UP))
  {
    dir.y -= 1;
  }
  dir = Vector2Normalize(dir);
  return dir;
}

WallManger Main::makeWall(float posX, float posY, float lenghtX, float lenghtY, Color Color, bool push)
{
  WallManger makeANewWall;
  makeANewWall.isUsed = true;
  makeANewWall.pos.x = posX;
  makeANewWall.pos.y = posY;
  makeANewWall.lenght.x = lenghtX;
  makeANewWall.lenght.y = lenghtY;
  makeANewWall.color = Color;
  makeANewWall.isPushable = push;
  
  return makeANewWall;
}

int Main::GetAUnusedWall(int sizeOfWall){
  for (int i = 0; i < sizeOfWall; i++)
  {
    if(!Main::wall[i].isUsed){
      return i;
    }
  }
  return 0;
}

int main()
{
  InitWindow(screenWidth, screenHeight, "Martin Killer");

  Martin martin;
  SceneManger manager;
  martin.pos.x += screenWidth / 2 - (float)martin.texture.width / 2;
  martin.pos.y += screenHeight / 2 - (float)martin.texture.height / 2;

  int sizeOfWall = sizeof(Main::wall) / sizeof(Main::wall[0]);
  
  manager.MakeRoom(0, sizeOfWall, screenWidth, screenHeight);

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    martin.UpdateMartinPos();
    martin.DrawMartin();

    for (int i = 0; i < sizeOfWall; i++)
    {
      if(Main::wall[i].isUsed){
        Main::wall[i].DrawWall();
      }
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}