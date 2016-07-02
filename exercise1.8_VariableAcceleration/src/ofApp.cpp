#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);

    position = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
    mousePosition = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
}

void ofApp::update() {
    acceleration = mousePosition - position;

    float distance = acceleration.length();
    if (distance != 0) {
        acceleration.normalize();
        acceleration *= 1. / distance;
    } else {
        acceleration = ofPoint(0, 0);
    }

    velocity += acceleration;
    position += velocity;
}

void ofApp::draw() {
    ofDrawRectangle(position, 10, 10);
}

void ofApp::mouseMoved(int x, int y) {
    mousePosition = ofPoint(x, y);
}
