/**
 * @class Baloon
 *
 * A helium baloon.
 */
#pragma once

#include "ofMain.h"

class Baloon {
    private:
        float width;
        float height;

        float mass;

        ofPoint position;

        ofVec3f netForce;
        ofVec3f velocity;

    public:
        Baloon();

        void addForce(ofVec3f force);

        void setSize(float width, float height);
        void setMass(float mass);
        float getSpeed();
        void setVelocity(ofVec3f velocity);
        ofVec3f getVelocity();
        ofPoint getPosition();

        void update();
        void draw();
};
