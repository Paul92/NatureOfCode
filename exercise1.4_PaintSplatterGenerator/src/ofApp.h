#pragma once

#include "ofMain.h"

#include <chrono>
#include <random>


class ofApp : public ofBaseApp {

    private:

        std::normal_distribution<float> xPositionDistribution;
        std::normal_distribution<float> yPositionDistribution;
        std::normal_distribution<float> sizeDistribution;

        std::default_random_engine generator;

        int noOfParticles;

        // The splatter at position splatterPosition[i] has size splatterSize[i].
        std::vector<ofPoint> splatterPosition;
        std::vector<float> splatterSize;


        // Regenerate the paint splatter.
        void resetSplatter();

    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
};
