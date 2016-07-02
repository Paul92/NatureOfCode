#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    private:
        ofPoint position;
        ofVec2f velocity;
        ofVec2f acceleration;

        ofPoint mousePosition;

    public:
        void setup();
        void update();
        void draw();
        void mouseMoved(int x, int y);
};
