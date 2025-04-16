#pragma once
#include "Item.h"
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

Item::Item(string code, std::string name, int num, int price, int total_sell, std::string order_name) :code(code), name(name), num(num), price(price), total_sell(total_sell), order_name(order_name) {} //누적판매금액, 주문자까지 받는 생성자
Item::Item() : code("noInfo"), name("noinfo"), num(0), price(0) {}
Item::Item(string code) : code(code), name("noinfo"), num(0), price(0) {}
Item::Item(string code, std::string name) : code(code), name(name), num(0), price(0) {}
Item::Item(string code, std::string name, int num) : code(code), name(name), num(num) {}
Item::Item(string code, std::string name, int num, int price) : code(code), name(name), num(num), price(price) {}

void Item::setCode(string code) {
	this->code = code;
}
string Item::getCode() {
	return this->code;
}
void Item::setName(string name) {
	this->name = name;
}
string Item::getName() {
	return this->name;
}
void Item::setNum(int num) {
	this->num = num;
}
int Item::getNum() {
	return this->num;
}
void Item::setPrice(int price) {
	this->price = price;
}
int Item::getPrice() {
	return this->price;
}
void Item::setTotal_sell(int total_sell) {
	this->total_sell = total_sell;
}
int Item::getTotal_sell() {
	return this->total_sell;
}
void Item::setOrder_name(string name) {
	this->order_name = order_name;
}
string Item::getOrder_name() {
	return this->order_name;
}//getter, setter 함수


string Item::print() {
	string TAB = "\t";
	string result = this->code + TAB + this->name + TAB + to_string(this->num) + TAB + to_string(this->price) + "\n";
	cout << result;
	return result;
}
string Item::print(bool value) {
	string TAB = "\t";
	if (value == true) {
		string result = (this->code) + TAB + (this->name) + TAB + to_string(this->num) + TAB + to_string(this->price) + TAB + to_string(this->total_sell) + TAB + (this->order_name) + "\n";
		cout << result;
		return result;
	}
	return "False입니다!\n";
}//코드, 제품명, 재고수량, 판매가격, 누적판매금액, 주문자