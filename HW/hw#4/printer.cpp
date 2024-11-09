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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
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
				cout << "����Ʈ�Ͽ����ϴ�." << endl;
			}
		}
	}
	void show() {
		cout << getModel() << " ," << getManuf() << " ,�������� " << getAv() << "�� ,���� ��ũ"
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
				cout << "����Ʈ�Ͽ����ϴ�." << endl;
			}
		}
	}
	void show() {
		cout << getModel() << " ," << getManuf() << " ,�������� " << getAv() << "�� ,���� ��ũ"
			<< availableToner << endl;
	}
};

int main() {
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	inkJet* IJ = new inkJet("Officejet V40", "HP", 5, 10);
	Laser* L = new Laser("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "��ũ�� : "; IJ->show();
	cout << "������ : "; L->show();

	int x, y;
	char a;

	while (true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
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
		cout << "��� ����Ʈ �Ͻðڽ��ϴ�(y/n)>>";
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