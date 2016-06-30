#include "ofApp.h"

void ofApp::setup() {
    xOffset = 0;
    yOffset = 0;

    noiseScale = 0.1;

    noiseImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
}

void ofApp::update() {

    unsigned char *pixels = noiseImage.getPixels().getData();

    for (int x = 0; x < noiseImage.getWidth(); x++)
        for (int y = 0; y < noiseImage.getHeight(); y++) {
            int index = y * noiseImage.getWidth() + x;
            float noise = ofNoise(xOffset + x * noiseScale, yOffset + y * noiseScale);
            pixels[index] = ofMap(noise, 0, 1, 0, 255, true);
        }

    noiseImage.update();
}

void ofApp::draw() {
    noiseImage.draw(0, 0);
}

void ofApp::keyPressed(int key) {
    switch (key) {
        case OF_KEY_UP:
            xOffset--;
            break;
        case OF_KEY_DOWN:
            yOffset++;
            break;
        case OF_KEY_LEFT:
            xOffset++;
            break;
        case OF_KEY_RIGHT:
            xOffset--;
            break;
        case '+':
            noiseScale += 0.001;
            break;
        case '-':
            noiseScale -= 0.001;
            break;
    }
}

