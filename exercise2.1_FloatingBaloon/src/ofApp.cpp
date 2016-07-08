#include "ofApp.h"
#include <cmath>

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);

    baloon.setSize(20, 25);
    wall.setup(ofPoint(100, 100), ofGetWidth() - 200, 30);
}

void ofApp::update() {
    float baloonVolume = 4. / 3 * PI * 15 * 10 * 10;
    float baloonMass = 0.164 * baloonVolume;
    float airMass = 1.225 * baloonVolume;
    float g = 0.001;

    baloon.addForce(ofVec3f(0, baloonMass * g, 0));
    baloon.addForce(ofVec3f(0, -airMass * g, 0));
    baloon.setMass(baloonMass);

    if (wall.hit(baloon.getPosition())) {
        baloon.addForce(ofVec3f(0, baloonMass * baloon.getVelocity().length(), 0));
        baloon.setVelocity(ofPoint(0, 0));
    }

    // Add air resistance
    if (baloon.getVelocity().y > 0)
        baloon.addForce(ofVec3f(0, -1, 0));
    else
        baloon.addForce(ofVec3f(0, 1, 0));

    baloon.update();
}

void ofApp::draw() {
    baloon.draw();
    wall.draw();
}

