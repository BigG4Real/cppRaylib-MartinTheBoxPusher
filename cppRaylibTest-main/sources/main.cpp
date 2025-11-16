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

class Wall{
  public:
    bool isUsed = false;
    Vector2 pos;
    Vector2 lenght;

    void DrawWall(){
      DrawRectangle(
        pos.x, 
        pos.y,
        lenght.x, 
        lenght.y,
        WHITE
      );
    }

    void UpdateWall(){
      DrawWall();
    }
};
Wall wall[100];


class Martin{
  public:
    float speed = 7;
    float health = 100;
    
    Texture2D texture = LoadTexture(ASSETS_PATH"MartinLightSkinStare.jpg");

    Vector2 pos;

    Vector2 HandlePlayerInput()
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

    void UpdateMartinPos()
    {
      Vector2 dir = HandlePlayerInput();
      pos.x += dir.x * speed;
      if(DoesCollide()){
        pos.x -= dir.x * speed;
      }
      pos.y += dir.y * speed;
      if(DoesCollide()){
        pos.y -= dir.y * speed;
      }
    }

    bool DoesCollide(){      
      // martin hitbox
      Rectangle martinBox = { pos.x, pos.y, (float)texture.width, (float)texture.height};

      DrawRectangle(pos.x, pos.y, (float)texture.width, (float)texture.height, RED);
      
      int size = sizeof(wall) / sizeof(wall[0]);
      
      for (int i = 0; i < size; i++)
      {
        if(!wall[i].isUsed){continue;}

        // walls sides
        Rectangle wallBox = { wall[i].pos.x, wall[i].pos.y, wall[i].lenght.x, wall[i].lenght.y};
        
        // sigma boy checks
        bool collision = CheckCollisionRecs(martinBox, wallBox);

        DrawRectangle(wall[i].pos.x, wall[i].pos.y, wall[i].lenght.x, wall[i].lenght.y, RED);

        if(collision){
          return true;
        }

      }
      
      return false;
    }

    void DrawMartin(){
      DrawTextureV(texture, pos, WHITE);
    }

    void HandleMartin(){
      UpdateMartinPos();
      DrawMartin();
    }
};

Wall makeWall(float posX, float posY, float lenghtX, float lenghtY)
{
  Wall makeANewWall;
  makeANewWall.isUsed = true;
  makeANewWall.pos.x = posX;
  makeANewWall.pos.y = posY;
  makeANewWall.lenght.x = lenghtX;
  makeANewWall.lenght.y = lenghtY;
  
  return makeANewWall;
}

int GetAUnusedWall(int sizeOfWall){
  for (int i = 0; i < sizeOfWall; i++)
  {
    if(!wall[i].isUsed){
      return i;
    }
  }
}

int main()
{
  InitWindow(screenWidth, screenHeight, "Martin Killer");

  Martin martin;

  martin.pos.x += screenWidth / 2 - (float)martin.texture.width / 2;
  martin.pos.y += screenHeight / 2 - (float)martin.texture.height / 2;
  int sizeOfWall = sizeof(wall) / sizeof(wall[0]);
   
  wall[GetAUnusedWall(sizeOfWall)] = makeWall(screenWidth / 2 + 350, screenHeight / 2, 200, 50); 
  wall[GetAUnusedWall(sizeOfWall)] = makeWall(screenWidth / 2, screenHeight + 100 / 2, 50, 250); 

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    martin.HandleMartin();

    for (int i = 0; i < sizeOfWall; i++)
    {
      if(wall[i].isUsed){
        wall[i].DrawWall();
      }
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}