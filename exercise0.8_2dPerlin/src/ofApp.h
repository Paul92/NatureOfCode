#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    private:
        int xOffset;
        int yOffset;
        float noiseScale;

        ofImage noiseImage;

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
};
