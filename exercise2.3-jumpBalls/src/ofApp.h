#pragma once

#include "ofMain.h"
#include "ball.h"

#include <vector>

class ofApp : public ofBaseApp {

    private:
        std::vector<Ball> balls;

    public:
        void setup();
        void update();
        void draw();
};
