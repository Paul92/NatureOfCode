/**
 * @class Walker
 *
 * @brief A point that can walk in various directions.
 */

#pragma once

#include "ofMain.h"

/// The movement direction.
enum Direction {NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST};

class Walker {
    private:
        /// The current position of the walker.
        ofPoint position;
        ofPoint oldPosition;

        /// The direction of the next step.
        Direction direction;

        /// The size of the next step.
        float stepSize;

    public:

        Walker(ofPoint initialPosition);

        void setDirection(Direction newDirection);

        void setStepSize(float newStepSize);

        void step();

        void draw();
};
