#include "Item.h"
#include "Mart.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	//1��
	cout << "202411247 ������" << endl;

	//2��
	Item item1;
	Item item2("A0001", "�����", 5, 100);

	//3�� - A,B
	item1.print();
	item2.print(true);

	//4��
	Mart juni1("product.txt");
	Mart juni2("product.txt", "greenjoa");

	//5��
	juni1.showItems();
}
