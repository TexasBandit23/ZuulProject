/* Author: Tejas Pandit
   Last Edited: 12/5/23
   This program creates a Zuul Program. This is an adventure game where the user can perform different actions
   The user can pick up items and can win if they meet certain conditions
   HELP - If the user types help, a few lines of information about the game will pop up
   MOVE - To move, the user must first enter MOVE, and click enter. They must then enter the direction they would like to move in
   GET - To get an item, the user must first enter GET, and click enter. They must then enter which item they would like to get
   DROP - To drop an item, the user must first enter DROP, and click enter. They must then enter which item they would like to drop
   INVENTORY - This command shows the players inventory
   QUIT - This command immediately quits the game

   Worked with Jazveer
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

//Prototypes
void pickup (Room* &currentRoom,vector<Item> &inventory);
void go(Room* &currentRoom);
bool checkWin(Room* &currentRoom, vector<Item> &inventory);
void help();
void drop (Room* &currentRoom,vector<Item> &inventory);
void Inventory(vector<Item> &inventory);

int main(){
    //Variables
    vector<Room*> Rooms;
    vector<Room*>::iterator ptr;
    bool Playing = true;
    char wantToPlay[10];
    char input[100];
    vector<Item> inventory;
    
    //Intro
    cout << "This is Zuul! Good luck, you'll need it..." << endl;
    cout << "You are on a spaceship, all alone, stranded in the middle of space..." << endl;
    cout << "Do you want to fix the ship? (Answer 'yes' or 'no')'" << endl;
    //Confirm
    cin >> wantToPlay;
    if(strcmp(wantToPlay, "no") == 0){
        cout << "Good luck getting home..." << endl;
        exit(0);
    }
    if(strcmp(wantToPlay, "yes") == 0){
                //Create rooms, exits, and map
                char* North = (char*)("North");
                char* East = (char*)("East");
                char* South = (char*)("South");
                char* West = (char*)("West");
                map<char*, Room*> initialMap;

		//Bridge
                char bridgeText[100] = "You are in the bridge.";
                Room* Bridge = new Room(bridgeText);

		//Armory
                char armoryText[100] = "You are in the armory.";
                Room* Armory = new Room(armoryText);
		char spacesuitText[100] = "Spacesuit";
		Item* Spacesuit = new Item(spacesuitText);
		Armory->setItem(*Spacesuit);

		//Security Room
                char securityRoomText[100] = "You are in the security room.";
                Room* securityRoom = new Room(securityRoomText);

		//Jail Cell
                char jailCellText[100] = "You are in the jail cell.";
                Room* jailCell = new Room(jailCellText);
                char weaponText[100] = "Weapon";
                Item* Weapon = new Item(weaponText);
                jailCell->setItem(*Weapon);

		//Training Room
                char trainingRoomText[100] = "You are in the training room.";
                Room* trainingRoom = new Room(trainingRoomText);

		//Cargo Bay
                char cargoBayText[100] = "You are in the cargo bay.";
                Room* cargoBay = new Room(cargoBayText);
                char toolsText[100] = "Tools";
                Item* Tools = new Item(toolsText);
                cargoBay->setItem(*Tools);

		//Cafeteria
                char cafeteriaText[100] = "You are in the cafeteria.";
                Room* Cafeteria = new Room(cafeteriaText);

		//Kitchen
                char kitchenText[100] = "You are in the kitchen.";
                Room* Kitchen = new Room(kitchenText);
                char foodText[100] = "Food";
                Item* Food = new Item(foodText);
                Kitchen->setItem(*Food);

		//Cryostasis Tubes
                char cryostasisTubesText[100] = "You are in the cryostasis tubes.";
                Room* cryostasisTubes = new Room(cryostasisTubesText);

		//Medical Bay
                char medicalBayText[100] = "You are in the medical bay.";
                Room* medicalBay = new Room(medicalBayText);
                char bandagesText[100] = "Bandages";
                Item* Bandages = new Item(bandagesText);
                medicalBay->setItem(*Bandages);

		//Science Lab
                char scienceLabText[100] = "You are in the science lab.";
                Room* scienceLab = new Room(scienceLabText);

		//Captain's Quarters
                char captainsQuartersText[100] = "You are in the captain's quarters.";
                Room* captainsQuarters = new Room(captainsQuartersText);

		//Outside
                char outsideText[100] = "You are outside.";
                Room* Outside = new Room(outsideText);

		//Engine Room
                char engineRoomText[100] = "You are in the engine room.";
                Room* engineRoom = new Room(engineRoomText);

		//Hangar
                char hangarText[100] = "You are in the hangar.";
                Room* Hangar = new Room(hangarText);
                char partsText[100] = "Parts";
                Item* Parts = new Item(partsText);
                Hangar->setItem(*Parts);
		
                //Exits
                Bridge-> setExit(East, Armory);
		Bridge-> setExit(South, Cafeteria);
		Bridge-> setExit(West, medicalBay);
		Bridge-> setExit(North, captainsQuarters);
		Armory-> setExit(East, securityRoom);
		Armory-> setExit(South, trainingRoom);
		Armory-> setExit(West, Bridge);
		securityRoom-> setExit(South, cargoBay);
		securityRoom-> setExit(West, Armory);
		securityRoom-> setExit(North, jailCell);
		cargoBay-> setExit(North, securityRoom);
		cargoBay-> setExit(West, trainingRoom);
		trainingRoom-> setExit(North, Armory);
		trainingRoom-> setExit(East, cargoBay);
		Kitchen-> setExit(North, Cafeteria);
		Cafeteria-> setExit(South, Kitchen);
		Cafeteria-> setExit(North, Bridge);
		cryostasisTubes-> setExit(North, medicalBay);
		medicalBay-> setExit(South, cryostasisTubes);
		medicalBay-> setExit(East, Bridge);
		medicalBay-> setExit(West, scienceLab);
		scienceLab-> setExit(East, medicalBay);
		captainsQuarters-> setExit(South, Bridge);
		captainsQuarters-> setExit(North, engineRoom);
		Hangar-> setExit(East, engineRoom);
		engineRoom-> setExit(West, Hangar);
		engineRoom-> setExit(South, captainsQuarters);
		engineRoom-> setExit(East, Outside);
		Outside-> setExit(West, engineRoom);
		jailCell-> setExit(South, securityRoom);

		//Used for later to determine if game is won
                Outside->setWinID(1);
		
                //Setting starting Room to the bridge
                Room* currentRoom = Bridge;
		
    //Player is confirmed playing
    cout << "The ship has broken down. You need to repair it to continue on your journey. Find all the objects needed for you to fix the ship. Once you have found them all, go outside to win!" << endl;
    //Print intro information like the current room, its description, and commands.
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    cout << "Your commands are HELP, MOVE, GET, DROP, QUIT, and INVENTORY." << endl;
    cout << "Enter a command: " << endl; 

    //While playing, continue until game is won
    //Need to fix weird error here
    while(Playing == true){
      //Read in input
      cin >> input;
	
      //"HELP" was entered
      if(strcmp(input, "HELP") == 0){
	help();
      }
	
      //"MOVE was entered       
      else if(strcmp(input, "MOVE") == 0){
	go(currentRoom);
        if(checkWin(currentRoom,inventory) == true){
	  cout << "Congratulations, you've done it, you can continue on your journey. Safe travels!" << endl;
	  exit(0);
        }
      }
      //If the user enters "GET"
      else if(strcmp(input, "GET") == 0){
        pickup(currentRoom, inventory);
      }
      //If the user enters "DROP"
      else if(strcmp(input, "DROP") == 0){
        drop(currentRoom, inventory);
      }
      //If the user enters "QUIT" 
      else if(strcmp(input, "QUIT") == 0){
        cout << "BYE!" << endl;
        //Exits
        Playing = false;
        exit(0);
      }
      //If the user enters "INVENTORY"
      else if(strcmp(input, "INVENTORY") == 0){
        Inventory(inventory);
      }
    }
    }
}

//Prints Help
void help(){
    cout << "This is Zuul! Good luck, you'll need it..." << endl;
    cout << "You are on a spaceship, all alone, stranded in the middle of space..." << endl;
    cout << "The ship has broken down. You need to repair it to continue on your journey. Find all the objects needed for you to fix the ship. Once you have found them all, go outside to win!" << endl;
    cout << "Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
}

//Movement   
void go(Room* &currentRoom){
  char placeholder[100];
  //The room the user is currently in
  cout << currentRoom->getRoomDescription() << endl;
  //All exits and items of the room
  currentRoom->ExitsAndItems();
  cout << "Where would you like to go (North, South, East, or West)?" << endl;
  //Take in the direction the user inputs
  cin >> placeholder;
  //the next room is the room on the other end of the exit chosen
  Room* nextRoom = currentRoom->getExit(placeholder);
  //currentRoom is the nextRoom
  currentRoom = nextRoom;
  //Prints out the description of the new current room
  cout << currentRoom->getRoomDescription() << endl;
  //Print out the new exits and items of the new current room
  currentRoom->ExitsAndItems();
}

//Get an item
void pickup(Room* &currentRoom,vector<Item> &inventory){
  char placeholder2[100];
  cout << "Items: " << endl;
  //Prints the items in the room
  currentRoom->printItems();
  cout << "Which item(s) would you like to get?" << endl;
  //Takes in the name of the item to be picked up from the user
  cin >> placeholder2;
  //Pick up the item
  Item RoomItem = currentRoom->getItem(placeholder2);
  //Add to inventory
  inventory.push_back(RoomItem);
  //Rmove the item from the room
  currentRoom->removeItem(placeholder2);
  cout << "You have gotten: " << placeholder2 << endl;
  //If the user has all the items and is outside, the game is won
  if(checkWin(currentRoom,inventory) == true){
    cout << "Congratualtions, you've done it, you can continue on your journey. Safe travels!" << endl;
    //exit the program
    exit(0);
    }
}

//Drop an item
//Fixed errors with this function
void drop(Room* &currentRoom,vector<Item> &inventory){
  vector<Item>::iterator ptr4;
  char placeholder3[100];
  cout << "Here is what you have: " << endl;
  //Inventory printed
  Inventory(inventory);
  cout << "What do you want to drop (hint: you need all items)?" << endl;
  //Takes in the name of the item the user wants to drop
  cin >> placeholder3;
  //Search for and find item in inventory
  for(ptr4 = inventory.begin(); ptr4 != inventory.end(); ptr4++){
    if(strcmp(ptr4->getDescription(),placeholder3) == 0){
      char tempItemDescription[100] = " "; 
      //Temporary item to be deleted
      Item tempItem(tempItemDescription);
      tempItem = (*ptr4);
      //Erases the item
      inventory.erase(ptr4);
      //Add the item to the room as it has been dropped
      currentRoom->setItem(tempItem);
      cout << "Oh no! You dropped: " << placeholder3 << endl;
      break;
    }
  }
}
//Inventory
void Inventory(vector<Item> &inventory){
    vector<Item>::iterator ptr;
    //Iterate through and print all items in the inventory
    for(ptr = inventory.begin(); ptr != inventory.end(); ptr++){
      cout << ptr->getDescription() << " ";;
    }
    cout << endl;
}
//If all items are collected (inventory of size 6) and the user is outside (Room ID of 1, not 0), the game is won
bool checkWin(Room* &currentRoom, vector<Item> &inventory){
  if(inventory.size() == 6 && currentRoom->getWinID() != 0){
    return true;
  }
  return false;
}
