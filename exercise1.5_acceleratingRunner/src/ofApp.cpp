#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);

    position = ofVec2f(0, ofGetHeight() / 2);
    acceleration = ofVec2f(0.1, 0);

}

void ofApp::update() {
    position += velocity;
}

void ofApp::draw() {
    ofDrawRectangle(position, 10, 10);
}

void ofApp::keyPressed(int key) {
    if (key == OF_KEY_UP) {
        velocity += acceleration;
    } else if (key == OF_KEY_DOWN) {
        velocity -= acceleration;
    }
}
