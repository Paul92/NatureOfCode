#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    private:
        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;

        float time = 0;

    public:
        void setup();
        void update();
        void draw();
};
