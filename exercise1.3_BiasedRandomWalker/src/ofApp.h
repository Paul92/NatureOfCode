#pragma once

#include "ofMain.h"
#include "walker.h"

class ofApp : public ofBaseApp {

    private:
        Walker walker;
        ofFbo fbo;

        // The direction indicated by mouse,
        Direction mouseDirection;

    public:
        ofApp();

        void setup();
        void update();
        void draw();

        void mouseMoved(int x, int y);
};
