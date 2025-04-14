#include "Item.h"
#include "Mart.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	//1번
	cout << "202411247 권준희" << endl;

	//2번
	Item item1;
	Item item2("A0001", "새우깡", 5, 100);

	//3번 - A,B
	item1.print();
	item2.print(true);

	//4번
	Mart juni1("product.txt");
	Mart juni2("product.txt", "greenjoa");

	//5번
	juni1.showItems();
}
