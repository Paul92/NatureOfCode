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
        std::normal_distribution<float> stepSizeDistribution;

    public:
        ofApp();

        void setup();
        void update();
        void draw();
};
