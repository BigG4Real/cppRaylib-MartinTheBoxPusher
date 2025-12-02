#include "raylib.h"
#include <raymath.h>
#include "CordsHandler.h"
#pragma once

class Martin{
  public:
    //Kommer få cordsen
    Cords* cords;
    
    Texture2D texture = LoadTexture(ASSETS_PATH"MartinLightSkinStare.jpg");

    int amountOfSteps;

    //Martins metoder :)
    void UpdateMartinPos();
    Vector2 HandlePlayerInput();
    Vector2 GetMartinPos();
    void MoveMartin(Vector2 playerPos, Vector2 moveDir);
    int GetMartinPosIndex();
    bool didBoxCollide(Vector2 boxPos, Vector2 martinDir);
};