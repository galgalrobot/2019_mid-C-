#include "Mart.h"
#include <fstream>
#include <memory>
#include <string>
using namespace std;

int Mart::number = 0;

Mart::Mart(string filename, string name) : filename(filename), name(name) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "파일 열기 실패" << endl;
		return;
	}
	int row; //품목 수
	fin >> row;
	Mart::number = row;

	this->arr = make_unique<Item[]>(row); //할당
	for (int i = 0; i < row;i++) {
		string code, snack;
		int price, num;

		// 1. 파일에서 필드별로 읽기
		fin >> code >> snack >> price >> num;

		// 2. 각각 set 함수로 설정
		arr[i].setCode(code);
		arr[i].setName(snack);
		arr[i].setPrice(price);
		arr[i].setNum(num);
	}
}

Mart::Mart(string filename) : Mart(filename, "0000") {} //이게 기능까지 물려받는 위임생성자임! 단순히 filename(filename)은 멤버변수 초기화해주는거

void Mart::showItems() {
	string TAB = "\t";
	cout << "==============JuniZZangMart 제품현황==============" << endl;
	cout << "==================================================" << endl;
	cout << "==================================================" << endl;
	cout << "코드" << TAB << "제품명" << TAB << "재고" << TAB << "가격" << endl;
	for (int i = 0; i < number; i++) {
		cout << this->arr[i].getCode() << TAB << this->arr[i].getName() << TAB << this->arr[i].getNum() << TAB << this->arr[i].getPrice() << endl;
	}
	cout << "==================================================" << endl;
}