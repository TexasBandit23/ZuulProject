#ifndef ROOM_H
#define ROOM_H
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;
//Room Class
class Room {
private:
//Room Name
char description[100];
//WinID (Only used for outside)
int WinID = 0;
//Map
map<char*, Room*> exits;
//Vector of items
vector <Item> Items;
public:
//Constructor
Room(char* newDescription);
~Room();
//Exit method
Room* getExit(char* newDirection);
void setExit(char* newDirection, Room* neighbor);
void ExitsAndItems();
//Item methods
Item getItem(char* itemTitle);
void setWinID(int number);
void setItem(Item newItem);
void removeItem(char* itemTitle);
void printItems();
//Gets the ID
int getWinID();
//Gets the Room name 
char* getRoomDescription();
};

#endif
