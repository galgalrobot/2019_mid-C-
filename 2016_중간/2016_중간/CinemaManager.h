#pragma once
#include "movie.h"
#include <string>
#include <memory>
class CinemaManager {
private:
	unique_ptr <movie[]> movie_arr; //��ȭ�̸��� ������ �迭, movie Ÿ��
	const string id;  //���̵�
	const string password;  //const�� set����->���� �Ұ���
public:
	CinemaManager(); //�⺻ ������
	CinemaManager(string temp_id, string temp_password);
	string getId();
	string getPassWord();

	void start();
};