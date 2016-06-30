#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    private:
        ofSpherePrimitive sphere;

        ofEasyCam easyCam;
        ofBoxPrimitive box;

        ofVec3f velocity;
        ofVec3f position;

    public:
        void setup();
        void update();
        void draw();
};
