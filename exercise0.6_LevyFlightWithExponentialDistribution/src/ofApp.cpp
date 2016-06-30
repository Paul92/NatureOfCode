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

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);

    stepSizeDistribution = std::uniform_real_distribution<float>(0, 1);
}

void ofApp::setup() {

}

bool customDistribution(float param) {
    return pow(param, 10);
}

float ofApp::monteCarlo() {
    while (true) {
        float x = stepSizeDistribution(generator);
        float y = stepSizeDistribution(generator);

        if (y < customDistribution(x))
            return x;
    }
}

void ofApp::update() {

    walker.setDirection((Direction)(rand() % 8));
    walker.setStepSize(monteCarlo() * 10);
    walker.step();

}

void ofApp::draw() {
    fbo.begin();
        walker.draw();
    fbo.end();

    fbo.draw(0, 0);
}

