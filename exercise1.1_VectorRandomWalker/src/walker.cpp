#include "walker.h"

Walker::Walker(ofPoint initialPosition) :
      directions {ofPoint(-1, 0), ofPoint(1, 0),   ofPoint(0, -1),
                  ofPoint(0, 1),  ofPoint(-1, -1), ofPoint(-1, 1),
                  ofPoint(1, -1), ofPoint(1, 1)}
{
    position = initialPosition;

    direction = directions[Direction::NORTH];

    stepSize = 5;
}

void Walker::setDirection(Direction newDirection) {
    direction = directions[newDirection];
}

void Walker::setStepSize(float newStepSize) {
    stepSize = newStepSize;
}

void Walker::step() {
    oldPosition = position;

    ofPoint velocity = direction * stepSize;

    position = position + velocity;
}

void Walker::draw() {
    ofDrawLine(oldPosition, position);
}

