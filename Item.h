#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;

class Item {
private:
	string code;  //A0001
	std::string name; //�����
	int num;  //������
	int price; //�ǸŰ���

	int total_sell; //���� �Ǹűݾ�
	std::string order_name; //�ֹ���

public:
	Item(string code, std::string name, int num, int price);
	Item();  //�⺻ ������
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
	std::string getOrder_name(); //getter, setter �Լ�


	std::string print(); //�ڵ�, ��ǰ��, ������, �ǸŰ���
	std::string print(bool value); //�ڵ�, ��ǰ��, ������, �ǸŰ���, �����Ǹűݾ�, �ֹ���

};