/**
 * @class Ball
 *
 * A sample ball class that implements some physics properties.
 * Can be used in particle systems.
 */
#include "ofMain.h"

class Ball {
    private:
        ofPoint position;
        ofVec3f velocity;
        ofVec3f acceleration;
        float mass;

    public:
        Ball();
        Ball(float mass);
        Ball(ofPoint position, float mass);

        void addForce(ofVec3f force);
        ofPoint getPosition() const;

        /// Bounce off the window boundaries.
        void boundaryCheck();

        void update();
        void draw() const;
};
