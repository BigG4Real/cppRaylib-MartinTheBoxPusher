#include "CordsHandler.h"
#include <iostream>
#include "raylib.h"
#include <raymath.h>
using namespace std;

// Gör ett net där man får lägga in width och height samt en enum med value ID
void Cords::MakeVectorNet(int width, int height){

    Width = width;
    Height = height;

    int onCurrentChange = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Vector2 newVector
            {
                (float)x,
                (float)y
            };
            AllCords[onCurrentChange].IsInUse = true;
            AllCords[onCurrentChange].pos = newVector;
            AllCords[onCurrentChange].data = DataType(nothing);
            onCurrentChange++;
        }
    }
}

void Cords::DrawEvrethingInCords(){

    for(int i = 0; i < (sizeof(AllCords) / sizeof(AllCords[0])); i++){
        if(!AllCords[i].IsInUse){
            return;
        }


        Vector2 posOfTheRect{
            (GetScreenWidth() / 2) + (AllCords[i].pos.x * SizeOfEvreything - (Offsets * Width / 2)) + (AllCords[i].pos.x * Offsets) - (Width * SizeOfEvreything / 2),
            (GetScreenHeight() / 2) + (AllCords[i].pos.y * SizeOfEvreything - (Offsets * Height / 2)) + (AllCords[i].pos.y * Offsets) - (Height * SizeOfEvreything / 2)
        };


        if(AllCords[i].data == DataType(nothing)){
            
        }
        else if(AllCords[i].data == DataType(wall)){
            DrawRectangle(posOfTheRect.x +(SizeOfEvreything * 0.1f), posOfTheRect.y+(SizeOfEvreything * 0.1f), SizeOfEvreything-(SizeOfEvreything * 0.2f), SizeOfEvreything-(SizeOfEvreything * 0.2f), SIGMABLUE);
            DrawRectangle(posOfTheRect.x, posOfTheRect.y, SizeOfEvreything, SizeOfEvreything, SIGMABLUE);
            DrawRectangle(posOfTheRect.x -(SizeOfEvreything * 0.1f), posOfTheRect.y-(SizeOfEvreything * 0.1f), SizeOfEvreything+(SizeOfEvreything * 0.2f), SizeOfEvreything+(SizeOfEvreything * 0.2f), SIGMABLUE);
        }
        else if(AllCords[i].data == DataType(player)){
            DrawRectangle(posOfTheRect.x +(SizeOfEvreything * 0.1f), posOfTheRect.y+(SizeOfEvreything * 0.1f), SizeOfEvreything-(SizeOfEvreything * 0.2f), SizeOfEvreything-(SizeOfEvreything * 0.2f), SIGMAGREEN);
            DrawRectangle(posOfTheRect.x, posOfTheRect.y, SizeOfEvreything, SizeOfEvreything, SIGMAGREEN);
            DrawRectangle(posOfTheRect.x -(SizeOfEvreything * 0.1f), posOfTheRect.y-(SizeOfEvreything * 0.1f), SizeOfEvreything+(SizeOfEvreything * 0.2f), SizeOfEvreything+(SizeOfEvreything * 0.2f), SIGMAGREEN);
        }
        else if(AllCords[i].data == DataType(box)){
            DrawRectangle(posOfTheRect.x +(SizeOfEvreything * 0.1f), posOfTheRect.y+(SizeOfEvreything * 0.1f), SizeOfEvreything-(SizeOfEvreything * 0.2f), SizeOfEvreything-(SizeOfEvreything * 0.2f), BOX);
            DrawRectangle(posOfTheRect.x, posOfTheRect.y, SizeOfEvreything, SizeOfEvreything, BOX);
            DrawRectangle(posOfTheRect.x -(SizeOfEvreything * 0.1f), posOfTheRect.y-(SizeOfEvreything * 0.1f), SizeOfEvreything+(SizeOfEvreything * 0.2f), SizeOfEvreything+(SizeOfEvreything * 0.2f), BOX);
        }

    }
}