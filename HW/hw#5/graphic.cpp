#include <iostream>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint() { draw(); }
	Shape* add(Shape* p) { this->next = p; return p; }
	Shape* getNext() { return next; }
};

class Line : public Shape {
public:
	virtual void draw() {
		cout << "Line" << endl;
	}
};
class Circle : public Shape {
public:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};
class Rect : public Shape {
public:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
public:
	static int main_menu() {
		int num;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
		cin >> num;
		return num;
	}
	static int choose_shape() {
		int num;
		cout << "��:1, ��:2, �簢��:3 >>";
		cin >> num;
		return num;
	}
	static int delete_shape() {
		int num;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
		cin >> num;
		return num;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() { pStart = NULL; pLast = NULL; }
	void insertShape(int shape) {
		Shape* p = NULL;
		switch (shape) {
		case 1:
			p = new Line();
			break;
		case 2:
			p = new Circle();
			break;
		case 3:
			p = new Rect();
			break;
		}
		if (pStart == NULL) {
			pStart = p;
			pLast = p;
			return;
		}
		pLast->add(p);
		pLast = pLast->getNext();
	}
	void deleteShape(int index) {
		Shape* x = pStart;
		Shape* y = pStart;
		for (int i = 0; i < index; i++) {
			x = y;
			y = y->getNext();
		}
		if (y == pStart) {
			pStart = y->getNext();
			delete y;
		}
		else {
			x->add(y->getNext());
			delete y;
		}
	}
	void show() {
		Shape* y = pStart;
		int a = 0;
		while (y != NULL) {
			cout << a++ << ": ";
			y->paint();
			y = y->getNext();
		}
	}
	void play() {
		cout << "�׷��� �������Դϴ�." << endl;
		int menu, shape, index;
		while (true) {
			menu = UI::main_menu();
			switch (menu) {
			case 1:
				shape = UI::choose_shape();
				insertShape(shape);
				break;
			case 2:
				index = UI::delete_shape();
				deleteShape(index);
				break;
			case 3:
				show();
				break;
			case 4:
				return;
			}

		}
	}
};

int main() {
	GraphicEditor graphicEditor;
	graphicEditor.play();

	return 0;
}