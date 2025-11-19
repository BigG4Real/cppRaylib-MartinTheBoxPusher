#include "WallManger.h"
#include <iostream>
#include "raylib.h"
#include <raymath.h>
using namespace std;

void WallManger::DrawWall(){
  DrawRectangle(
    pos.x, 
    pos.y,
    lenght.x, 
    lenght.y,
    color
  );
}