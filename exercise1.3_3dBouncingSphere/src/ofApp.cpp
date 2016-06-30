#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);
    sphere.setRadius(20);
    easyCam.setDistance(300);
    box.set(150);
    velocity = ofVec3f(ofRandom(0, 10), ofRandom(0, 10), ofRandom(0, 10));
    sphere.setPosition(0, 0, 0);
}

void ofApp::update() {

    ofVec3f tempPosition = position + velocity;

    if (tempPosition.x > box.getWidth() / 2 || tempPosition.x < -box.getWidth() / 2)
        velocity.x = -velocity.x;
    if (tempPosition.y > box.getHeight() / 2 || tempPosition.y < -box.getHeight() / 2)
        velocity.y = -velocity.y;
    if (tempPosition.z > box.getDepth() / 2 || tempPosition.z < -box.getDepth() / 2)
        velocity.z = -velocity.z;

    position = position + velocity;
}

void ofApp::draw() {
    ofSetColor(ofColor::red);

    easyCam.begin();

    ofPushMatrix();
        ofTranslate(position);
        sphere.drawWireframe();
    ofPopMatrix();

    box.drawWireframe();
    easyCam.end();
}

