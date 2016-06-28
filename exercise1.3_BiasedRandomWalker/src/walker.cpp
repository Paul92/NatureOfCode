#include "walker.h"

Walker::Walker(ofPoint initialPosition) {
    position = initialPosition;

    direction = Direction::NORTH;

    stepSize = 1;
}

void Walker::setDirection(Direction newDirection) {
    direction = newDirection;
}

void Walker::setStepSize(float newStepSize) {
    stepSize = newStepSize;
}

void Walker::step() {

    oldPosition = position;

    switch (direction) {
        case NORTH:
            position.y -= stepSize;
            break;
        case NORTH_EAST:
            position.y -= stepSize;
            position.x -= stepSize;
            break;
        case NORTH_WEST:
            position.y -= stepSize;
            position.x += stepSize;
            break;

        case SOUTH:
            position.y += stepSize;
            break;
        case SOUTH_EAST:
            position.y += stepSize;
            position.x -= stepSize;
            break;
        case SOUTH_WEST:
            position.y += stepSize;
            position.x += stepSize;
            break;

        case EAST:
            position.x -= stepSize;
            break;
        case WEST:
            position.x += stepSize;
            break;
    }
}

void Walker::draw() {
    ofDrawLine(oldPosition, position);
}

