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

    noiseTimeIndex = 0;
}

void ofApp::setup() {

}

void ofApp::update() {

    walker.setDirection((Direction)(rand() % 8));

    noiseTimeIndex += 0.01;
    float noiseValue = ofNoise(noiseTimeIndex);
    float stepSize = ofMap(noiseValue, 0, 1, 1, 20, true);

    walker.setStepSize(stepSize);
    walker.step();

}

void ofApp::draw() {
    fbo.begin();
        walker.draw();
    fbo.end();

    fbo.draw(0, 0);
}

