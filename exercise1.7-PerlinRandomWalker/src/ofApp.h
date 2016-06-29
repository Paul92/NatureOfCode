#pragma once

#include "ofMain.h"
#include "walker.h"

#include <random>
#include <chrono>

class ofApp : public ofBaseApp {

    private:
        Walker walker;
        ofFbo fbo;

        int noiseTimeIndex;

    public:
        ofApp();

        void setup();
        void update();
        void draw();
};
