#include "ofApp.h"

void ofApp::setup() {
    xOffset = 0;
    yOffset = 0;

    noiseScale = 0.1;

    noiseImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    easyCam.setDistance(2000);

    ofSetBackgroundColor(ofColor::white);


    waveShader.load("shadersGL3/wave");

    plane.set(2000, 2000, 25, 25, OF_PRIMITIVE_TRIANGLES);
    plane.mapTexCoordsFromTexture(noiseImage.getTexture());
    plane.setPosition(ofGetWidth() / 2 - 500, ofGetHeight() / 2- 1000, 700);
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
    ofSetColor(ofColor::white);
    ofDrawRectangle(0, 400, 1200, 1000);
    noiseImage.bind();
    easyCam.begin();
    waveShader.begin();
    ofRotate(90, 1, 0, 0);
    plane.drawWireframe();
    waveShader.end();
    easyCam.end();
    noiseImage.unbind();
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

