#include "ofApp.h"

void ofApp::setup() {

    ofSetBackgroundColor(ofColor::black);

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);


    xPositionDistribution = std::normal_distribution<float>(ofGetWidth() / 2, 100);
    yPositionDistribution = std::normal_distribution<float>(ofGetHeight() / 2, 100);

    sizeDistribution = std::normal_distribution<float>(10, 4);

    noOfParticles = 80;

    resetSplatter();
}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetColor(ofColor::white);
    for (int index = 0; index < noOfParticles; index++) {
        ofDrawCircle(splatterPosition[index], splatterSize[index]);
    }
}

void ofApp::keyPressed(int key) {
    if (key == ' ')
        resetSplatter();
}

void ofApp::resetSplatter() {

    splatterPosition.clear();
    splatterSize.clear();

    for (int index = 0; index < noOfParticles; index++) {
        ofPoint position(xPositionDistribution(generator),
                         yPositionDistribution(generator));
        float size = sizeDistribution(generator);

        splatterPosition.push_back(position);
        splatterSize.push_back(size);
    }
}

