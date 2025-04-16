#pragma once
#include "CinemaManager.h"
#include "movie.h"
#include <iostream>
#include <memory>
#include <string>
using namespace std;

CinemaManager::CinemaManager(string temp_id, string temp_password) : id(temp_id), password(temp_password) {
	cout << "**********�󿵰� ���� ����**********" << endl;
	this->movie_arr = make_unique<movie[]>(3);//3�� ��ȭ��
	for (int i = 0; i < 3; i++) {
		int row, col;
		cout << i + 1 << "���� �¼� ������ �Է��ϼ���: ";
		cin >> row >> col;
		movie_arr[i].setMovieNumber(i + 1);
		movie_arr[i].setRow(row);
		movie_arr[i].setCol(col);
		movie_arr[i].make_seat(row, col, movie_arr[i].getSeat()); //�¼� �����
	}

}
CinemaManager::CinemaManager() : CinemaManager("", "") {}

string CinemaManager::getId() {
	return this->id;
}

string CinemaManager::getPassWord() {
	return this->password;
}

void CinemaManager::start() {
	string TAB = "\t";

	string id, pass; //���̵� �� ���
	int num = 0;
	cout << "���̵� �Է�: ";
	cin >> id;
	cout << "��� �Է�: ";
	cin >> pass;
	cout << endl;
	if (id == (this->getId()) && pass == (this->getPassWord())) {
		while (true) {
			cout << "�޴� �����: ";
			cout << " 1��) ��ȭ�� ���� �Է� " << " 2��) ��ȭ�� ���� " << " 3��) �޸� ����" << " 4��) ����" << endl;
			cout << "�޴��� �������ּ���: ";
			cin >> num;
			switch (num) {
			case 1: {
				string movie_name, director; //��ȭ�̸�, ��ȭ����
				int number;
				cout << endl;
				cout << "*****��ȭ�� ���� �Է�*****" << endl;
				cout << "1) ��ȭ���� : ";
				cin >> movie_name;
				cout << "2) ��ȭ���� : ";
				cin >> director;
				cout << "3) �󿵰�(1,2,3) : ";
				cin >> number;
				if (movie_arr[number - 1].getName() == "") {
					this->movie_arr[number - 1].setName(movie_name); //��ȭ�̸� ����
					this->movie_arr[number - 1].setDirector(director); //��ȭ���� ����
				}
				else {
					cout << "�����Ͻ� �󿵰��� �̹� ������ �󿵰��Դϴ�." << endl;
				}
				break;
			}
			case 2: {
				int reserve_movie; //������ ��ȭ��ȣ
				int reserve_num; //����ǥ��
				cout << endl;
				cout << "********* ��ȭ ���� *********" << endl;
				cout << "===================" << endl;
				for (int i = 0; i < 3;i++) {
					cout << i + 1 << ") " << "\t" << movie_arr[i].getName() << "\t" << movie_arr[i].getRow() * movie_arr[i].getCol() - movie_arr[i].getReserved() << "��" << endl; //��ü ������ ������ �� ����,,
				}
				cout << "===================" << endl;
				cout << "������ ��ȭ�� �Է��ϼ��� : ";
				cin >> reserve_movie;
				cout << "��Ÿ� �����Ͻðڽ��ϱ�? : ";
				cin >> reserve_num;
				if (reserve_num <= movie_arr[reserve_movie-1].getRow() * movie_arr[reserve_movie-1].getCol() - movie_arr[reserve_movie-1].getReserved()) {
					movie_arr[reserve_movie - 1].show_seat(movie_arr[reserve_movie - 1].getSeat()); //�� ��ȭ �¼� �� �����ֱ�
					movie_arr[reserve_movie - 1].reserveSeat(movie_arr[reserve_movie - 1].getSeat(), reserve_num);
					movie_arr[reserve_movie - 1].setReserved(movie_arr[reserve_movie - 1].getReserved() + reserve_num); //������ �¼� �� ����

				}
				else {
					cout << "���Ű����� ǥ���� �Ѿ���ϴ�!" << endl;
				}
				break;
			}
			case 3: {
				//�޸� ���� ���� �ڵ� -> unique_ptr�� �� �ʿ� ����
				break;
			}
			case 4:
				cout << "�����ư�� �����̽��ϴ�." << endl;
				return;
			default:
				cout << "�ùٸ��� �Է����ּ���" << endl;
				break;
			}
		}
	}
	else {
		cout << "���̵� Ȥ�� ����� Ʋ�Ƚ��ϴ�!" << endl;
	}

}