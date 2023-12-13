#ifndef ITEM_H
#define ITEM_H
#include <cstring>

using namespace std;
//Item Class
class Item {
private:
//Item Name
char description[100];
public:
//Methods
Item(char* newDescription);
~Item();
char* getDescription();

};

#endif
