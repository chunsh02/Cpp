#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Player {
public:
	string name[2];
	void setName();
};

void Player::setName() {
	cout << "ù��° ���� �̸�>>";
	getline(cin, name[0], '\n');
	cout << "�ι�° ���� �̸�>>";
	getline(cin, name[1]);
}

class GamblingGame {
public:
	Player player;
	GamblingGame(const Player& p) : player(p) {}
	void game();
};

void GamblingGame::game() {
	srand((unsigned)time(0));
	int n = rand();
	int i = 0;
	while (true) {
		cout << player.name[i % 2] << ": <Enter>";
		if (cin.get() == '\n') {
			int a = rand() % 3;
			int b = rand() % 3;
			int c = rand() % 3;
			cout << "\t\t" << a << "\t" << b << "\t" << c << "\t";
			if (a == b && b == c) {
				cout << player.name[i % 2] << "�� �¸�!!" << endl;
				break;
			}
			else
				cout << "�ƽ�����!" << endl;
		}
		i++;
	}
}

int main() {
	Player p;
	cout << "***** �׺� ������ �����մϴ�. *****" << endl;
	p.setName();
	GamblingGame g(p);
	g.game();
}