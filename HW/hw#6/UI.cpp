#include <iostream>
#include "UI.h"
using namespace std;

int UI::main_menu() {
	int num;
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
	cin >> num;
	return num;
}

int UI::choose_shape() {
	int num;
	cout << "선:1, 원:2, 사각형:3 >>";
	cin >> num;
	return num;
}

int UI::delete_shape() {
	int num;
	cout << "삭제하고자 하는 도형의 인덱스 >>";
	cin >> num;
	return num;
}