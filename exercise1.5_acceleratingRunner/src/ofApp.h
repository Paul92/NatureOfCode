#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    private:
        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;

    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
};
