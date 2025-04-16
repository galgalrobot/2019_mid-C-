#pragma once
#include "movie.h"
#include <string>
#include <memory>
class CinemaManager {
private:
	unique_ptr <movie[]> movie_arr; //영화관을 저장할 배열 <- 영화에 대한 이름을 저장할 것이므로 movie로 받음
	const string id;  //아이디
	const string password;  //const면 set못씀->변경 불가능
public:
	CinemaManager(); //기본 생성자
	CinemaManager(string temp_id, string temp_password);
	string getId();
	string getPassWord();

	void start();
};