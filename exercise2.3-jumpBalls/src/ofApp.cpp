#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundColor(ofColor::black);

    for (int index = 0; index < 5; index++)
        balls.push_back(Ball(ofRandom(0.1, 3)));
}

void ofApp::update() {
    ofVec3f gravity(0, 0.00098);
    ofVec3f wind(0.001, 0);

    for (Ball &ball : balls) {
        ball.addForce(gravity);
        ball.addForce(wind);

        ball.boundaryCheck();

        ofPoint position = ball.getPosition();
        float distance = ofGetWidth() - position.x;

        if (distance < 100) {
            float forceValue = ofMap(distance, 0, 100, -0.05, 0, true);
            std::cout << forceValue << std::endl;
            ofVec3f repelForce(forceValue, 0);
            ball.addForce(repelForce);
        }


        ball.update();
    }
}

void ofApp::draw() {
    for (const Ball &ball : balls)
        ball.draw();
}

