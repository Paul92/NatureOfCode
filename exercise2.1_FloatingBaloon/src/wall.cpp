#include "wall.h"

Wall::Wall() {
}

void Wall::setup(ofPoint position, float width, float height) {
    this->position = position;
    this->width = width;
    this->height = height;
}

void Wall::update() {
}

void Wall::draw() {
    ofDrawRectangle(position, width, height);
}

bool Wall::hit(ofPoint point) {
    ofRectangle rectangle(position, width, height);

    return rectangle.inside(point);
}
