#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    private:
        int xOffset;
        int yOffset;
        float noiseScale;

        ofShader waveShader;

        ofImage noiseImage;
        ofEasyCam easyCam;
        ofPlanePrimitive plane;

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
};
