#pragma once

#include "ofMain.h"
#include "walker.h"

class ofApp : public ofBaseApp {

    private:
        Walker walker;
        ofFbo fbo;

    public:
        ofApp();

        void setup();
        void update();
        void draw();
};
