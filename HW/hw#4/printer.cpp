#include <iostream>
#include <string>
using namespace std;

class printer {
	string model, manufacturer;
	int printedCount, availableCount;
public:
	printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	bool print(int pages) {
		if (availableCount >= pages) {
			availableCount -= pages;
			return true;
		}
		else {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			return false;
		}
	}
	string getModel() { return model; }
	string getManuf() { return manufacturer; }
	int getAv() { return availableCount; }
};

class inkJet : public printer {
	int availableInk;
public:
	inkJet(string model, string manufacturer, int availableCount, int availableInk) :
		printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void printInkJet(int pages) {
		if (print(pages)) {
			if (availableInk >= pages) {
				availableInk -= pages;
				cout << "프린트하였습니다." << endl;
			}
		}
	}
	void show() {
		cout << getModel() << " ," << getManuf() << " ,남은종이 " << getAv() << "장 ,남은 잉크"
			<< availableInk << endl;
	}
};

class Laser : public printer {
	int availableToner;
public:
	Laser(string model, string manufacturer, int availableCount, int availableToner) :
		printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void printLaser(int pages) {
		if (print(pages)) {
			if (availableToner >= pages) {
				availableToner -= pages;
				cout << "프린트하였습니다." << endl;
			}
		}
	}
	void show() {
		cout << getModel() << " ," << getManuf() << " ,남은종이 " << getAv() << "장 ,남은 잉크"
			<< availableToner << endl;
	}
};

int main() {
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	inkJet* IJ = new inkJet("Officejet V40", "HP", 5, 10);
	Laser* L = new Laser("SCX-6x45", "삼성전자", 3, 20);
	cout << "잉크젯 : "; IJ->show();
	cout << "레이저 : "; L->show();

	int x, y;
	char a;

	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> x >> y;
		if (x == 1) {
			IJ->printInkJet(y);
			IJ->show();
			L->show();
		}
		if (x == 2) {
			L->printLaser(y);
			IJ->show();
			L->show();
		}
		cout << "계속 프린트 하시겠습니다(y/n)>>";
		cin >> a;
		if (a == 'n')
			break;
		else if (a == 'y')
			continue;
		else
			break;
	}
	delete IJ;
	delete L;
}