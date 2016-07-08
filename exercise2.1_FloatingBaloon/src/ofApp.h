#pragma once

#include "ofMain.h"
#include "baloon.h"
#include "wall.h"

class ofApp : public ofBaseApp {

    private:
        Baloon baloon;
        Wall wall;

    public:
        void setup();
        void update();
        void draw();
};
