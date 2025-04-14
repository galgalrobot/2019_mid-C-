#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;

class Item {
private:
	string code;  //A0001
	std::string name; //새우깡
	int num;  //재고수량
	int price; //판매가격

	int total_sell; //누적 판매금액
	std::string order_name; //주문자

public:
	Item(string code, std::string name, int num, int price);
	Item();  //기본 생성자
	Item(string code);
	Item(string code, std::string name);
	Item(string code, std::string name, int num);
	Item(string code, std::string name, int num, int price, int total_sell, std::string order_name);

	void setCode(string code);
	string getCode();
	void setName(std::string name);
	std::string getName();
	void setNum(int num);
	int getNum();
	void setPrice(int price);
	int getPrice();
	void setTotal_sell(int total_sell);
	int getTotal_sell();
	void setOrder_name(std::string name);
	std::string getOrder_name(); //getter, setter 함수


	std::string print(); //코드, 제품명, 재고수량, 판매가격
	std::string print(bool value); //코드, 제품명, 재고수량, 판매가격, 누적판매금액, 주문자

};