#pragma once
#include <string>
#include <memory>
using namespace std;

class movie {
private:
	int row;
	int col;
	int movie_arr_number;  //영화관 번호
	unique_ptr<unique_ptr<int[]>[]> seat; //각 영화당 좌석
	string name; //영화 이름 
	string dire_name; //감독이름
	int reserved;

public:
	movie() = default;
	movie(int row, int col, int movie_arr_number);

	void setName(string name);
	string getName();

	void setDirector(string dire_name);
	string getDirector();

	void setRow(int row);
	int getRow();

	void setCol(int col);
	int getCol();

	void setMovieNumber(int movie_arr_number);
	int getMovieNumber();

	void setReserved(int reserved);
	int getReserved();

	void show_seat(unique_ptr<unique_ptr<int[]>[]>& seat);
	void reserveSeat(unique_ptr<unique_ptr<int[]>[]>& seat, int num);
	void make_seat(int row, int col, unique_ptr<unique_ptr<int[]>[]>& seat); //좌석 만드는 함수
	unique_ptr<unique_ptr<int[]>[]>& getSeat();  //참조로 넘기는 이유..uniquePtr는 복사불가능이라 주소값만 전달
};