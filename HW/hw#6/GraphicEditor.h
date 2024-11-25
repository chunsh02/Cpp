#ifndef GRAPHIC_EDITOR_H
#define GRAPHIC_EDITOR_H

#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "UI.h"
using namespace std;

class GraphicEditor {
    vector<Shape*> v;
public:
    ~GraphicEditor();
    void insertShape(int shape);
    void deleteShape(int index);
    void show();
    void play();
};

#endif

