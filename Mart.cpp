#include "Mart.h"
#include <fstream>
#include <memory>
#include <string>
using namespace std;

int Mart::number = 0;

Mart::Mart(string filename, string name) : filename(filename), name(name) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "���� ���� ����" << endl;
		return;
	}
	int row; //ǰ�� ��
	fin >> row;
	Mart::number = row;

	this->arr = make_unique<Item[]>(row); //�Ҵ�
	for (int i = 0; i < row;i++) {
		string code, snack;
		int price, num;

		// 1. ���Ͽ��� �ʵ庰�� �б�
		fin >> code >> snack >> price >> num;

		// 2. ���� set �Լ��� ����
		arr[i].setCode(code);
		arr[i].setName(snack);
		arr[i].setPrice(price);
		arr[i].setNum(num);
	}
}

Mart::Mart(string filename) : Mart(filename, "0000") {} //�̰� ��ɱ��� �����޴� ���ӻ�������! �ܼ��� filename(filename)�� ������� �ʱ�ȭ���ִ°�

void Mart::showItems() {
	string TAB = "\t";
	cout << "==============JuniZZangMart ��ǰ��Ȳ==============" << endl;
	cout << "==================================================" << endl;
	cout << "==================================================" << endl;
	cout << "�ڵ�" << TAB << "��ǰ��" << TAB << "���" << TAB << "����" << endl;
	for (int i = 0; i < number; i++) {
		cout << this->arr[i].getCode() << TAB << this->arr[i].getName() << TAB << this->arr[i].getNum() << TAB << this->arr[i].getPrice() << endl;
	}
	cout << "==================================================" << endl;
}