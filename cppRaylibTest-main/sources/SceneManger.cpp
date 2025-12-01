#include "SceneManger.h"
#include <iostream>
#include "CordsHandler.h"
#include "raylib.h"
#include <raymath.h>
using namespace std;

void Level::Generate(int Current, Cords* cordsSystem)
{
    switch (Current)
    {
    case 0:
        MapOne(cordsSystem);
        break;
    
    default:
        break;
    }
}

void Level::MapOne(Cords* cordsSystem){
    
    //gör allt till väggar
    CreatSector(cordsSystem, 0, 19, 0, 11, DataType(wall));

    //gör alla hol som spelaren kan gå i
    CreatSector(cordsSystem, 5, 7, 1, 4, DataType(nothing));
    CreatSector(cordsSystem, 3, 8, 4, 7, DataType(nothing));
    CreatSector(cordsSystem, 1, 2, 6, 7, DataType(nothing));
    CreatSector(cordsSystem, 4, 9, 8, 9, DataType(nothing));
    CreatSector(cordsSystem, 9, 13, 7, 7, DataType(nothing));
    CreatSector(cordsSystem, 14, 17, 6, 8, DataType(nothing));

    //gör väggar
    CreatSector(cordsSystem, 4, 4, 5, 6, DataType(wall));
    CreatSector(cordsSystem, 6, 7, 5, 6, DataType(wall));
    CreatSector(cordsSystem, 6, 8, 8, 8, DataType(wall));
    CreatSector(cordsSystem, 4, 4, 8, 9, DataType(wall));

    //gör spelaren
    CreatSector(cordsSystem, 11, 11, 8, 8, DataType(player));

    //gör win points
    MakeWinPoint(16, 8);
    MakeWinPoint(17, 8);
    MakeWinPoint(16, 7);
    MakeWinPoint(17, 7);
    MakeWinPoint(16, 6);
    MakeWinPoint(17, 6);

    // gör boxes
    CreatSector(cordsSystem, 8, 8, 8, 8, DataType(box));

}

void Level::CreatSector(Cords* cordsSystem, int startX, int endX, int startY, int endY, DataType dataType){
    for(int i = 0; i < (sizeof(cordsSystem->AllCords) / sizeof(cordsSystem->AllCords[0])); i++){
        bool rightWidth = cordsSystem->AllCords[i].pos.x >= startX && cordsSystem->AllCords[i].pos.x <= endX;
        bool rightHeight = cordsSystem->AllCords[i].pos.y >= startY && cordsSystem->AllCords[i].pos.y <= endY;
        if(rightHeight && rightWidth){
            cordsSystem->AllCords[i].data = DataType(dataType);
        }
    }
}

void Level::MakeWinPoint(int posX, int posY){
    for(int i = 0; i < (sizeof(winPoints) / sizeof(winPoints[0])); i++)
    {
        if(winPoints[i].isUsed == false){
            winPoints[i].pos.x = posX;
            winPoints[i].pos.y = posY;
            winPoints[i].isUsed = true;
            return;
        }
    }
}

void Level::DrawWin(Cords* cordsSystem){
    
    for(int i = 0; i < (sizeof(winPoints) / sizeof(winPoints[0])); i++)
    {
        if(winPoints[i].isUsed == false){
            continue;
        }
        Vector2 posOfTheRect{
            (GetScreenWidth() / 2) + (winPoints[i].pos.x * cordsSystem->SizeOfEvreything - (cordsSystem->Offsets * cordsSystem->Width / 2)) + (winPoints[i].pos.x * cordsSystem->Offsets) - (cordsSystem->Width * cordsSystem->SizeOfEvreything / 2),
            (GetScreenHeight() / 2) + (winPoints[i].pos.y * cordsSystem->SizeOfEvreything - (cordsSystem->Offsets * cordsSystem->Height / 2)) + (winPoints[i].pos.y * cordsSystem->Offsets) - (cordsSystem->Height * cordsSystem->SizeOfEvreything / 2)
          };
         
        DrawRectangle(posOfTheRect.x +(cordsSystem->SizeOfEvreything * 0.1f), posOfTheRect.y+(cordsSystem->SizeOfEvreything * 0.1f), cordsSystem->SizeOfEvreything-(cordsSystem->SizeOfEvreything * 0.2f), cordsSystem->SizeOfEvreything-(cordsSystem->SizeOfEvreything * 0.2f), WIN);
        DrawRectangle(posOfTheRect.x, posOfTheRect.y, cordsSystem->SizeOfEvreything, cordsSystem->SizeOfEvreything, WIN);
        DrawRectangle(posOfTheRect.x -(cordsSystem->SizeOfEvreything * 0.1f), posOfTheRect.y-(cordsSystem->SizeOfEvreything * 0.1f), cordsSystem->SizeOfEvreything+(cordsSystem->SizeOfEvreything * 0.2f), cordsSystem->SizeOfEvreything+(cordsSystem->SizeOfEvreything * 0.2f), WIN); 
        
    }
}
