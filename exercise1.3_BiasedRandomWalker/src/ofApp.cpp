#include "ofApp.h"

#include <ctime>
#include <cstdlib>

ofApp::ofApp() : walker(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2)) {

    ofSetBackgroundColor(ofColor::black);

    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);

    fbo.begin();
        ofClear(255, 255, 255, 0);
    fbo.end();

    std::srand(std::time(NULL));

    mouseDirection = Direction::NORTH;
}

void ofApp::setup() {

}

void ofApp::update() {
    // Randomly generate a direction biased to bottom right.
    // It works by randomly selected a position from the following array:
    Direction directions[] = {Direction::NORTH,
                              Direction::SOUTH,
                              Direction::EAST,
                              Direction::WEST,
                              mouseDirection,
                              mouseDirection,
                              mouseDirection};
    int directionIndex = rand() % (sizeof(directions) / sizeof(Direction));
    walker.setDirection(directions[directionIndex]);

    walker.step();
}

void ofApp::draw() {
    fbo.begin();
        walker.draw();
    fbo.end();

    fbo.draw(0, 0);
}

void ofApp::mouseMoved(int x, int y) {
    // x axis versor.
    static const ofVec3f xAxis(ofGetWidth() / 2 + 100, ofGetHeight() / 2, 0);


    // Vector that points to the mouse position.
    ofPoint mouse = ofVec3f(x - ofGetWidth() / 2, y - ofGetHeight() / 2, 0);

    // The angle between the mouse vector and the x axis.
    float angle = mouse.angle(xAxis);

    if (angle >= 45 && angle < 135)
        mouseDirection = Direction::NORTH;
    else if (angle >= 135 && angle < 225)
        mouseDirection = Direction::EAST;
    else if (angle >= 225 && angle < 315)
        mouseDirection = Direction::SOUTH;
    else
        mouseDirection = Direction::WEST;

    std::cout << mouseDirection << " " << angle << std::endl;
}
