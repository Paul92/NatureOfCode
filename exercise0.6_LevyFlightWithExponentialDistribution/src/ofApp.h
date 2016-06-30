#pragma once

#include "ofMain.h"
#include "walker.h"

#include <random>
#include <chrono>

class ofApp : public ofBaseApp {

    private:
        Walker walker;
        ofFbo fbo;

        std::default_random_engine generator;
        std::uniform_real_distribution<float> stepSizeDistribution;

        float monteCarlo();

    public:
        ofApp();

        void setup();
        void update();
        void draw();
};
