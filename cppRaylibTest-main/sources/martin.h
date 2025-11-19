#include "raylib.h"
#include <raymath.h>
#pragma once

class Martin{
  public:
    float speed = 8;
    float health = 100;
    
    Texture2D texture = LoadTexture(ASSETS_PATH"MartinLightSkinStare.jpg");

    Vector2 pos;

    void UpdateMartinPos();
    bool DoesCollide();
    void CanPush(Vector2 dir);
    void DrawMartin();
};