#pragma once
#include "movie.h"
#include <string>
#include <memory>
#include <iostream>
using namespace std;

movie::movie(int row, int col, int movie_arr_number) : row(row), col(col), movie_arr_number(movie_arr_number) {}
//movie::movie() : movie(0, 0, 0) {}

void movie::make_seat(int row, int col, unique_ptr<unique_ptr<int[]>[]>& seat) {
	this->seat = make_unique<unique_ptr<int[]>[]>(row); //�¼� �� ������ֱ�
	for (int i = 0; i < row; i++) {
		seat[i] = make_unique<int[]>(col);
	} //2���� �迭 �ϼ�
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (seat[i][j] != 0) {
				reserved++;
			}
			seat[i][j] = 0;
		}
	} //�ϴ� �� 0���� ���డ���ϰ�
}//�¼� ������ֱ�

void movie::show_seat(unique_ptr<unique_ptr<int[]>[]>& seat) {
	std::cout << endl;
	std::cout << "�¼���Ȳ" << endl;
	std::cout << "  ";
	for (int i = 0; i < this->getRow(); i++) {
		std::cout << i + 1 << " ";
	}
	std::cout << endl;
	for (int i = 0; i < this->getRow(); i++) {
		std::cout << static_cast<char>('A' + i) << " ";
		for (int j = 0;j < this->getCol(); j++) {
			if (seat[i][j] == 0) {
				std::cout << "�� ";
			}
			else {
				std::cout << "x ";
			}//���� �Ǿ��ٴ� ��
		}
		std::cout << endl;
	}
}

//��ȭ �̸�
void movie::setName(string name) {
	this->name = name;
}
string movie::getName() {
	return this->name;
}

//��� ��
void movie::setCol(int col) {
	this->col = col;
}
int movie::getCol() {
	return this->col;
}
void movie::setRow(int row) {
	this->row = row;
}
int movie::getRow() {
	return this->row;
}

//�����Լ�
void movie::reserveSeat(unique_ptr<unique_ptr<int[]>[]>& seat, int num) {
	int count = 0;
	while (count < num) {
		char temp_row;
		int col;
		cout << "==> �¼��� �����ϼ���: ";
		cin >> temp_row >> col;
		int row = temp_row - 'A';
		col -= 1;
		if (seat[row][col] == 0) {
			count++;
			this->seat[row][col] = 1; //����Ұ����ϰ� �����!
		}
		else {
			cout << "�̹� ����Ǿ��ֽ��ϴ�." << endl;
		}
	}
	cout << "������ �Ϸ�Ǿ����ϴ�. �����մϴ�." << endl;
}

//���� Ȯ��
void movie::setReserved(int reserved) {
	this->reserved = reserved;
}
int movie::getReserved() {
	return this->reserved;
}

//�¼� 
unique_ptr<unique_ptr<int[]>[]>& movie::getSeat() {
	return this->seat; //���۷����� ��ȯ
}

//��ȭ�� ��ȣ
void movie::setMovieNumber(int movie_arr_number) {
	this->movie_arr_number = movie_arr_number;
}
int movie::getMovieNumber() {
	return this->movie_arr_number;
}

//�����̸�
void movie::setDirector(string dire_name) {
	this->dire_name = dire_name;
}
string movie::getDirector() {
	return this->dire_name;
}

