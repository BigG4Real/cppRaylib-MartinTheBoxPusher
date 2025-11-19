#include "SceneManger.h"
#include "main.h"
#include <iostream>
using namespace std;

void SceneManger::MakeRoom(int newRoomId, float sizeOfWall, float screenWidth, float screenHeight)
{
  SceneManger::CurentRoom =  newRoomId;
  
  switch (newRoomId)
  {
    case 0:
      
    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 + 900, screenHeight / 2 - 750, 200, 1500, BLUE, false); 
    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 - 1100, screenHeight / 2 - 750, 200, 1500, BLUE, false); 
    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 - 1000, screenHeight / 2 - 700, 2000, 200, BLUE, false); 
    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 - 1000, screenHeight / 2 + 500, 2000, 200, BLUE, false);

    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 - 700, screenHeight / 2 - 600, 100, 600, BLUE, false); 

    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 - 900, screenHeight / 2, 100, 100, PURPLE, true); 
    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 + 600, screenHeight / 2 - 200, 100, 100, PURPLE, true); 
    Main::wall[Main::GetAUnusedWall(sizeOfWall)] = Main::makeWall(screenWidth / 2 + 600, screenHeight / 2 + 200, 100, 100, PURPLE, true);

    break;
    case 1:

      break;

      default:
      cout << "Invalid room ID: " << newRoomId << endl;
      break;
  }
}
