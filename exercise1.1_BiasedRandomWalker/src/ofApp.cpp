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
}

void ofApp::setup() {

}

void ofApp::update() {
    // Randomly generate a direction biased to bottom right.
    // It works by randomly selected a position from the following array:
    int directions[] = {0, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7};
    int directionIndex = rand() % (sizeof(directions) / sizeof(int));
    walker.setDirection((Direction)directions[directionIndex]);

    walker.step();
}

void ofApp::draw() {
    fbo.begin();
        walker.draw();
    fbo.end();

    fbo.draw(0, 0);
}

