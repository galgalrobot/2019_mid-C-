#pragma once
#include "CinemaManager.h"
#include "movie.h"
#include <iostream>
#include <memory>
#include <string>
using namespace std;

CinemaManager::CinemaManager(string temp_id, string temp_password) : id(temp_id), password(temp_password) {
	cout << "**********상영관 정보 생성**********" << endl;
	this->movie_arr = make_unique<movie[]>(3);//3개 영화관
	for (int i = 0; i < 3; i++) {
		int row, col;
		cout << i + 1 << "관의 좌석 정보를 입력하세요: ";
		cin >> row >> col;
		movie_arr[i].setMovieNumber(i + 1);
		movie_arr[i].setRow(row);
		movie_arr[i].setCol(col);
		movie_arr[i].make_seat(row, col, movie_arr[i].getSeat()); //좌석 만들기
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

	string id, pass; //아이디 및 비번
	int num = 0;
	cout << "아이디 입력: ";
	cin >> id;
	cout << "비번 입력: ";
	cin >> pass;
	cout << endl;
	if (id == (this->getId()) && pass == (this->getPassWord())) {
		while (true) {
			cout << "메뉴 종료들: ";
			cout << " 1번) 영화관 정보 입력 " << " 2번) 영화관 예매 " << " 3번) 메모리 누수" << " 4번) 종료" << endl;
			cout << "메뉴를 선택해주세요: ";
			cin >> num;
			switch (num) {
			case 1: {
				string movie_name, director; //영화이름, 영화감독
				int number;
				cout << endl;
				cout << "*****영화관 정보 입력*****" << endl;
				cout << "1) 영화제목 : ";
				cin >> movie_name;
				cout << "2) 영화감독 : ";
				cin >> director;
				cout << "3) 상영관(1,2,3) : ";
				cin >> number;
				if (movie_arr[number - 1].getName() == "") {
					this->movie_arr[number - 1].setName(movie_name); //영화이름 설정
					this->movie_arr[number - 1].setDirector(director); //영화감독 설정
				}
				else {
					cout << "선택하신 상영관은 이미 상영중인 상영관입니다." << endl;
				}
				break;
			}
			case 2: {
				int reserve_movie; //예매할 영화번호
				int reserve_num; //예매표수
				cout << endl;
				cout << "********* 영화 예매 *********" << endl;
				cout << "===================" << endl;
				for (int i = 0; i < 3;i++) {
					cout << i + 1 << ") " << "\t" << movie_arr[i].getName() << "\t" << movie_arr[i].getRow() * movie_arr[i].getCol() - movie_arr[i].getReserved() << "석" << endl; //전체 수에서 예약한 수 뺀거,,
				}
				cout << "===================" << endl;
				cout << "예매할 영화를 입력하세요 : ";
				cin >> reserve_movie;
				cout << "몇매를 구매하시겠습니까? : ";
				cin >> reserve_num;
				if (reserve_num <= movie_arr[reserve_movie-1].getRow() * movie_arr[reserve_movie-1].getCol() - movie_arr[reserve_movie-1].getReserved()) {
					movie_arr[reserve_movie - 1].show_seat(movie_arr[reserve_movie - 1].getSeat()); //그 영화 좌석 수 보여주기
					movie_arr[reserve_movie - 1].reserveSeat(movie_arr[reserve_movie - 1].getSeat(), reserve_num);
					movie_arr[reserve_movie - 1].setReserved(movie_arr[reserve_movie - 1].getReserved() + reserve_num); //예약한 좌석 수 조정

				}
				else {
					cout << "예매가능한 표수를 넘어섰습니다!" << endl;
				}
				break;
			}
			case 3: {
				//메모리 누수 방지 코드 -> unique_ptr라 할 필요 없음
				break;
			}
			case 4:
				cout << "종료버튼을 누르셨습니다." << endl;
				return;
			default:
				cout << "올바르게 입력해주세요" << endl;
				break;
			}
		}
	}
	else {
		cout << "아이디 혹은 비번이 틀렸습니다!" << endl;
	}

}