/**
 * @class Wall
 *
 * A wall that restricts the motion of objects.
 */
#pragma once

#include "ofMain.h"

class Wall {
    private:
        ofPoint position;
        float width, height;

    public:
        Wall();

        void setup(ofPoint position, float width, float height);

        void draw();
        void update();

        /// Returns true if the point hits the wall or is inside it.
        bool hit(ofPoint point);
};
