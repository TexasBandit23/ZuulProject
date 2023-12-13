#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;
//Constructor
Room::Room(char* newDescription){
strcpy(description, newDescription);

}
//Add item to vector of items
void Room::setItem(Item newItem){
Items.push_back(newItem);
}
//Use iterator to get item
Item Room::getItem(char* itemTitle){
vector <Item> :: iterator ptr;
for(ptr = Items.begin(); ptr != Items.end(); ptr++){
if(strcmp(ptr->getDescription(), itemTitle) == 0){
return (*ptr);
    }
}
return 0;
}
//Use iterator to search for item and remove
void Room::removeItem(char* itemTitle){
vector <Item> :: iterator ptr2;
for(ptr2 = Items.begin(); ptr2 != Items.end(); ptr2++){
if(strcmp(ptr2->getDescription(), itemTitle) == 0){
Items.erase(ptr2);
break;
    }
}
}
//More iterators, this time to print
void Room :: printItems(){
    vector <Item> :: iterator ptr3;
    for(ptr3= Items.begin(); ptr3 != Items.end(); ptr3++){
    cout << ptr3->getDescription() << ",";
  }
  cout << endl;
}
//Another interator!
void Room::ExitsAndItems(){
    cout << "Exits:" << endl;
  //Prints out the exits
  for(map<char*, Room*>::iterator ptr = exits.begin(); ptr != exits.end(); ptr++){
    cout << " " << ptr->first;
  }
  cout << endl;
  cout << "Items in this room:" << endl;
  //PrintItems method from above
  printItems();
}
//Setting the exit in a direction
void Room::setExit(char* newDirection,Room* neighbor){
  exits[newDirection] = neighbor;
  }
//Gets the exit next room
Room* Room::getExit(char* newDirection){
map<char*, Room*>:: iterator ptr;
for(ptr = (exits).begin(); ptr != exits.end(); ptr++){
if(strcmp(ptr->first, newDirection) == 0){
return ptr->second;
    }
}
return 0;
}
//Sets the win ID (Only used for outside)
void Room::setWinID(int number){
  WinID = number;
}
//Gets the win ID of the room (Only used for outside)
int Room :: getWinID(){
  return WinID;
}
//Gets the name of the Room
char* Room :: getRoomDescription(){
    return description;
}
