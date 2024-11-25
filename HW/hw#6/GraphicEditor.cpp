#include <iostream>
#include "GraphicEditor.h"
using namespace std;

GraphicEditor::~GraphicEditor() {
	for (Shape* shape : v)
		delete shape;
}

void GraphicEditor::insertShape(int shape) {
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
	v.push_back(p);
}

void GraphicEditor::deleteShape(int index) {
	delete v[index];
	v.erase(v.begin() + index);
}

void GraphicEditor::show() {
	for (int i = 0; i < v.size(); i++) {
		cout << i << ": ";
		v[i]->paint();
	}
}

void GraphicEditor::play() {
	cout << "그래픽 에디터입니다." << endl;
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