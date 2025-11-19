#include "SceneManger.h"
#include <iostream>
#include "martin.h"
#include "main.h"
using namespace std;


void Martin::UpdateMartinPos()
{
  Vector2 dir = Main::HandlePlayerInput();
  float speed = Martin::speed;

  Martin::pos.x += dir.x * speed;
  Martin::CanPush(dir);
  if (Martin::DoesCollide()){
    Martin::pos.x -= dir.x * speed;
  }
  
  Martin::pos.y += dir.y * speed;
  Martin::CanPush(dir);  
  if(Martin::DoesCollide()){
    Martin::pos.y -= dir.y * speed;
  }
  
}

bool Martin::DoesCollide()
{
  // martin hitbox
  Rectangle martinBox = { Martin::pos.x + 50, Martin::pos.y + 50, 100, 100};

  DrawRectangle(Martin::pos.x + 50, Martin::pos.y + 50, 100, 100, RED);
  
  int size = sizeof(Main::wall) / sizeof(Main::wall[0]);
  
  for (int i = 0; i < size; i++)
  {
    if(!Main::wall[i].isUsed || Main::wall[i].isPushable){continue;}

    // walls sides
    Rectangle wallBox = { Main::wall[i].pos.x, Main::wall[i].pos.y, Main::wall[i].lenght.x, Main::wall[i].lenght.y};
    
    // sigma boy check
    bool collision = CheckCollisionRecs(martinBox, wallBox);

    DrawRectangle(Main::wall[i].pos.x, Main::wall[i].pos.y, Main::wall[i].lenght.x, Main::wall[i].lenght.y, RED);

    if(collision){
      return true;
    }

  }
  
  return false;
}

    
void Martin::CanPush(Vector2 dir)
{
  float speed = Martin::speed;
  // martin hitbox
  Rectangle martinBox = { Martin::pos.x + 50, Martin::pos.y + 50, 100, 100};
  DrawRectangle(Martin::pos.x + 50, Martin::pos.y + 50, 100, 100, RED);
  
  int size = sizeof(Main::wall) / sizeof(Main::wall[0]);
  
  for (int i = 0; i < size; i++)
  {
    if(!Main::wall[i].isUsed || !Main::wall[i].isPushable){continue;}
    // walls sides
    Rectangle wallBox = { Main::wall[i].pos.x, Main::wall[i].pos.y, Main::wall[i].lenght.x, Main::wall[i].lenght.y};
    
    // sigma boy checks
    bool collision = CheckCollisionRecs(martinBox, wallBox);
    DrawRectangle(Main::wall[i].pos.x, Main::wall[i].pos.y, Main::wall[i].lenght.x, Main::wall[i].lenght.y, RED);
    if(collision){
      Main::wall[i].pos.x += dir.x * speed;
      Main::wall[i].pos.y += dir.y * speed;
      Rectangle wallBoxNewLoc = { Main::wall[i].pos.x, Main::wall[i].pos.y, Main::wall[i].lenght.x, Main::wall[i].lenght.y};
      for (int j = 0; j < size; j++)
      {
        if(!Main::wall[i].isUsed || i == j){continue;}
        
        Rectangle newWallBox = { Main::wall[j].pos.x, Main::wall[j].pos.y, Main::wall[j].lenght.x, Main::wall[j].lenght.y};
        bool newCollision = CheckCollisionRecs(newWallBox, wallBoxNewLoc);
        if(newCollision){  
          Main::wall[i].pos.x -= dir.x * speed;
          Main::wall[i].pos.y -= dir.y * speed;
          Martin::pos.x -= dir.x * speed * 2;
          Martin::pos.y -= dir.y * speed * 2;
        }
      }
    }
  }
}


void Martin::DrawMartin(){
    Vector2 newpos{
      Martin::pos.x + 50,
      Martin::pos.y + 50
  };
  DrawTextureV(texture, pos, WHITE);
}