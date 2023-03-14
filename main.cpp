#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Phone{
    char name[20];
    char opSys[20];
    float phonePrice;
    Phone();
};

Phone::Phone(){
    name[0] = 0;
    opSys[0] = 0;
    phonePrice = 0;
}

class Smartphone{
    char model[20];
    float price;
    char os[20];
    int arrSize;
    Phone arr[10];
public:
    Smartphone();
    Smartphone(char* model, char* os, float price);
    bool addToArray(char* name, char* opSys, float phonePrice);
    float getPrice(){
    return price;
    };
    int getSize(){
    return arrSize;
    };
    void printAll();
    int sortPhonesByPrice(const void* a, const void* b);
    Phone* getArr() {
        return arr;
    };
    friend int sortPhonesByPrice(const void* a, const void* b);
};

Smartphone::Smartphone(){
    strcpy_s(model, "");
	strcpy_s(os, "");
	price = 0;
	arrSize = 0;
}

Smartphone::Smartphone(char* mod, char* opSys, float p){
    strcpy_s(model, mod);
	strcpy_s(os, opSys);
	price = p;
	arrSize = 0;
}

bool Smartphone::addToArray(char* n, char* opS, float pPrice){
    strcpy_s(this->arr[arrSize].name, n);
	strcpy_s(this->arr[arrSize].opSys, opS);
	this->arr[arrSize].phonePrice = pPrice;
	this->arrSize++;
	return 1;
}

void Smartphone::printAll(){
	for (int i = 0; i < this -> arrSize; i++){
        cout << "Model: " << this -> arr[i].name << endl;
        cout << "Operating system: " << this -> arr[i].opSys << endl;
        cout << "Price: " << this -> arr[i].phonePrice << endl;
        cout << "---------------------------------------"<< endl;
	}
}

int sortPhonesByPrice(const void* a, const void* b) {
    const Phone* x = (Phone*)a;
	const Phone* y = (Phone*)b;

    if (x->phonePrice > y->phonePrice)
	{
		return 1;
	}
	else if (x->phonePrice < y->phonePrice)
	{
		return -1;
	}
	return 0;
}

int main()
{
    Smartphone iPhone("iPhone 11", "iOS", 999.99);

    iPhone.addToArray("iPhone 14", "iOS", 1800.99);
    iPhone.addToArray("iPhone 11", "iOS", 999.99);
    iPhone.addToArray("iPhone 12", "iOS", 1200.99);
    iPhone.addToArray("iPhone 13", "iOS", 1300.99);

    qsort(iPhone.getArr(), iPhone.getSize(), sizeof(Phone), sortPhonesByPrice);

    Phone* sortedArr = iPhone.getArr();
    for (int i = 0; i < iPhone.getSize(); i++) {
        cout << "Model: " << sortedArr[i].name << endl;
        cout << "Operating system: " << sortedArr[i].opSys << endl;
        cout << "Price: " << sortedArr[i].phonePrice << endl;
        cout << "---------------------------------------"<< endl;
    }

    return 0;
}
