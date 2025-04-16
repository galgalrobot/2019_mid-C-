#pragma once
#include <string>
#include <memory>
using namespace std;

class movie {
private:
	int row;
	int col;
	int movie_arr_number;  //��ȭ�� ��ȣ
	unique_ptr<unique_ptr<int[]>[]> seat; //�� ��ȭ�� �¼�
	string name; //��ȭ �̸� 
	string dire_name; //�����̸�
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
	void make_seat(int row, int col, unique_ptr<unique_ptr<int[]>[]>& seat); //�¼� ����� �Լ�
	unique_ptr<unique_ptr<int[]>[]>& getSeat();  //������ �ѱ�� ����..uniquePtr�� ����Ұ����̶� �ּҰ��� ����
};