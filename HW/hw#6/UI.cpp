#include <iostream>
#include "UI.h"
using namespace std;

int UI::main_menu() {
	int num;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
	cin >> num;
	return num;
}

int UI::choose_shape() {
	int num;
	cout << "��:1, ��:2, �簢��:3 >>";
	cin >> num;
	return num;
}

int UI::delete_shape() {
	int num;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
	cin >> num;
	return num;
}