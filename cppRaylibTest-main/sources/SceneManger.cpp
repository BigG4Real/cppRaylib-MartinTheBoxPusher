#include "SceneManger.h"
#include <iostream>
#include "CordsHandler.h"
#include "raylib.h"
#include <raymath.h>
using namespace std;

void Level::Generate(int Current, Cords* cordsSystem)
{
    for(int i = 0; i < (sizeof(winPoints) / sizeof(winPoints[0])); i++)
    {
        winPoints[i].isUsed = false;
    }

    switch (Current)
    {
        case 1:
            MapOne(cordsSystem);
            break;
        
        case 2:
            MapTwo(cordsSystem);
            break;
    
    default:
        break;
    }
}

void Level::MapOne(Cords* cordsSystem){
    //Tar bort allt ifall man laddar ny bana
    CreatSector(cordsSystem, 0, 999, 0, 999, DataType(nothing));

    cordsSystem->MakeVectorNet(19,11);

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
    CreatSector(cordsSystem, 7, 7, 3, 4, DataType(box));
    CreatSector(cordsSystem, 5, 5, 4, 4, DataType(box));
    CreatSector(cordsSystem, 5, 5, 2, 2, DataType(box));
    CreatSector(cordsSystem, 5, 5, 7, 7, DataType(box));
    CreatSector(cordsSystem, 2, 2, 7, 7, DataType(box));

}


void Level::MapTwo(Cords* cordsSystem){
    //Tar bort allt ifall man laddar ny bana
    CreatSector(cordsSystem, 0, 999, 0, 999, DataType(nothing));

    cordsSystem->MakeVectorNet(14,10);
    
    //gör allt till väggar
    CreatSector(cordsSystem, 0, 14, 0, 10, DataType(wall));

    //gör alla hol som spelaren kan gå i
    CreatSector(cordsSystem, 1, 12, 1, 8, DataType(nothing));

    //gör väggar
    CreatSector(cordsSystem, 0, 2, 6, 10, DataType(wall));
    CreatSector(cordsSystem, 0, 5, 6, 6, DataType(wall));
    CreatSector(cordsSystem, 5, 5, 5, 5, DataType(wall));
    CreatSector(cordsSystem, 5, 5, 0, 3, DataType(wall));

    CreatSector(cordsSystem, 7, 8, 3, 3, DataType(wall));
    CreatSector(cordsSystem, 9, 10, 3, 4, DataType(wall));

    CreatSector(cordsSystem, 7, 7, 5, 6, DataType(wall));
    CreatSector(cordsSystem, 8, 8, 6, 6, DataType(wall));
    
    CreatSector(cordsSystem, 7, 7, 8, 8, DataType(wall));

    CreatSector(cordsSystem, 12, 12, 5, 5, DataType(wall));


    //gör spelaren
    CreatSector(cordsSystem, 7, 7, 4, 4, DataType(player));

    //gör win points
    MakeWinPoint(1, 1);
    MakeWinPoint(1, 2);
    MakeWinPoint(1, 3);
    MakeWinPoint(1, 4);
    MakeWinPoint(1, 5);

    MakeWinPoint(2, 1);
    MakeWinPoint(2, 2);
    MakeWinPoint(2, 3);
    MakeWinPoint(2, 4);
    MakeWinPoint(2, 5);

    // gör boxes
    CreatSector(cordsSystem, 7, 7, 2, 2, DataType(box));
    CreatSector(cordsSystem, 10, 10, 2, 2, DataType(box));
    CreatSector(cordsSystem, 6, 6, 3, 3, DataType(box));

    CreatSector(cordsSystem, 10, 10, 5, 5, DataType(box));

    CreatSector(cordsSystem, 9, 9, 6, 7, DataType(box));
    CreatSector(cordsSystem, 11, 11, 6, 7, DataType(box));

    CreatSector(cordsSystem, 7, 7, 7, 7, DataType(box));

    CreatSector(cordsSystem, 4, 4, 7, 7, DataType(box));


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

bool Level::CheckIfWin(Cords* cordsSystem){
    
    for(int i = 0; i < (sizeof(winPoints) / sizeof(winPoints[0])); i++){
        for(int j = 0; j < (sizeof(cordsSystem->AllCords) / sizeof(cordsSystem->AllCords[0])); j++)
        {
            if(winPoints[i].isUsed && cordsSystem->AllCords[j].pos == winPoints[i].pos && cordsSystem->AllCords[j].data != DataType(box)){
                return false;
            }
        }
    }
    return true;
}
