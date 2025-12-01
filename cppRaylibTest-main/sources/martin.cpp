#include "SceneManger.h"
#include <iostream>
#include "martin.h"
#include "CordsHandler.h"
using namespace std;

//Vilket håll man vill gå ut
Vector2 Martin::HandlePlayerInput()
{
  Vector2 dir;
  dir.x = 0;
  dir.y = 0;
  if (IsKeyPressed(KEY_RIGHT))
  {
    dir.x += 1;
  }
  if (IsKeyPressed(KEY_LEFT))
  {
    dir.x -= 1;
  }
  if (IsKeyPressed(KEY_DOWN))
  {
    dir.y += 1;
  }
  if (IsKeyPressed(KEY_UP))
  {
    dir.y -= 1;
  }
  return dir;
}

//Lägg Martin på en ny pos i CordsHandler
void Martin::UpdateMartinPos()
{
  MoveMartin(GetMartinPos(), HandlePlayerInput());
}

void Martin::MoveMartin(Vector2 playerPos, Vector2 moveDir){
    int martin = GetMartinPosIndex();
    for(int i = 0; i < (sizeof(cords->AllCords) / sizeof(cords->AllCords[0])); i++){

    if(cords->AllCords[i].pos == playerPos + moveDir){
      if(cords->AllCords[i].data == DataType(box) && !didBoxCollide(cords->AllCords[i].pos, moveDir) || cords->AllCords[i].data == DataType(wall)){
        //beta gå ut
        return;
      }
      //sigman klarade sig
      cords->AllCords[martin].data = DataType(nothing);
      cords->AllCords[i].data = DataType(player);
    }
  }
}

bool Martin::didBoxCollide(Vector2 boxPos, Vector2 martinDir){
  Vector2 newBoxPos = boxPos + martinDir;
  for(int i = 0; i < (sizeof(cords->AllCords) / sizeof(cords->AllCords[0])); i++)
  {
    if(cords->AllCords[i].pos == newBoxPos && cords->AllCords[i].data == DataType(nothing))
    {
      cords->AllCords[i].data = DataType(box);
      return true;
    }
  }  
  return false;
}

Vector2 Martin::GetMartinPos(){
  for(int i = 0; i < (sizeof(cords->AllCords) / sizeof(cords->AllCords[0])); i++){

    if(cords->AllCords[i].data == DataType(player)){
      return cords->AllCords[i].pos;
    }
  }
  Vector2 seafty{
    0,0
  };
  return seafty;
}
int Martin::GetMartinPosIndex(){
  for(int i = 0; i < (sizeof(cords->AllCords) / sizeof(cords->AllCords[0])); i++){

    if(cords->AllCords[i].data == DataType(player)){
      return i;
    }
  }
  return 0;
}