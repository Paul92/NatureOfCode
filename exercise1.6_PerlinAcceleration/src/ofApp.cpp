#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);

    position = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
}

void ofApp::update() {
    time += 0.001;

    acceleration.x = (ofNoise(time) - 0.6) / 15;
    acceleration.y = (ofNoise(time) - 0.6) / 15;

    velocity += acceleration;
    position += velocity;

    position.x = ofClamp(position.x, 0, ofGetWidth() - 30);
    position.y = ofClamp(position.y, 0, ofGetHeight() - 30);
}

void ofApp::draw() {
    ofDrawRectangle(position, 10, 10);
}

