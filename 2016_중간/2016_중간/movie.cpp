#pragma once
#include "movie.h"
#include <string>
#include <memory>
#include <iostream>
using namespace std;

movie::movie(int row, int col, int movie_arr_number) : row(row), col(col), movie_arr_number(movie_arr_number) {}
//movie::movie() : movie(0, 0, 0) {}

void movie::make_seat(int row, int col, unique_ptr<unique_ptr<int[]>[]>& seat) {
	this->seat = make_unique<unique_ptr<int[]>[]>(row); //좌석 행 만들어주기
	for (int i = 0; i < row; i++) {
		seat[i] = make_unique<int[]>(col);
	} //2차원 배열 완성
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (seat[i][j] != 0) {
				reserved++;
			}
			seat[i][j] = 0;
		}
	} //일단 다 0으로 예약가능하게
}//좌석 만들어주기

void movie::show_seat(unique_ptr<unique_ptr<int[]>[]>& seat) {
	std::cout << endl;
	std::cout << "좌석현황" << endl;
	std::cout << "  ";
	for (int i = 0; i < this->getRow(); i++) {
		std::cout << i + 1 << " ";
	}
	std::cout << endl;
	for (int i = 0; i < this->getRow(); i++) {
		std::cout << static_cast<char>('A' + i) << " ";
		for (int j = 0;j < this->getCol(); j++) {
			if (seat[i][j] == 0) {
				std::cout << "ㅇ ";
			}
			else {
				std::cout << "x ";
			}//예약 되었다는 뜻
		}
		std::cout << endl;
	}
}

//영화 이름
void movie::setName(string name) {
	this->name = name;
}
string movie::getName() {
	return this->name;
}

//행과 열
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

//예약함수
void movie::reserveSeat(unique_ptr<unique_ptr<int[]>[]>& seat, int num) {
	int count = 0;
	while (count < num) {
		char temp_row;
		int col;
		cout << "==> 좌석을 선택하세요: ";
		cin >> temp_row >> col;
		int row = temp_row - 'A';
		col -= 1;
		if (seat[row][col] == 0) {
			count++;
			this->seat[row][col] = 1; //예약불가능하게 만들기!
		}
		else {
			cout << "이미 예약되어있습니다." << endl;
		}
	}
	cout << "예약이 완료되었습니다. 감사합니다." << endl;
}

//예약 확인
void movie::setReserved(int reserved) {
	this->reserved = reserved;
}
int movie::getReserved() {
	return this->reserved;
}

//좌석 
unique_ptr<unique_ptr<int[]>[]>& movie::getSeat() {
	return this->seat; //레퍼런스만 반환
}

//영화관 번호
void movie::setMovieNumber(int movie_arr_number) {
	this->movie_arr_number = movie_arr_number;
}
int movie::getMovieNumber() {
	return this->movie_arr_number;
}

//감독이름
void movie::setDirector(string dire_name) {
	this->dire_name = dire_name;
}
string movie::getDirector() {
	return this->dire_name;
}

