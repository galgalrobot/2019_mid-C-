#pragma once
#include <string>
#include <memory>
#include "Item.h"
using namespace std;

class Mart {
private:
	static int number;  //자판기 번호
	unique_ptr<Item[]> arr;
	string filename;
	string name;

public:
	Mart() = delete;
	Mart(string filename);
	Mart(string filename, string name);
	void showItems();
};
