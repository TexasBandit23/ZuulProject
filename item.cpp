#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"

using namespace std;
//Copy description into item name
Item::Item(char* newDescription){
strcpy(description, newDescription);

}
//Get item name
char* Item::getDescription(){
    return description;
}
//Destructor
Item::~Item(){

}
