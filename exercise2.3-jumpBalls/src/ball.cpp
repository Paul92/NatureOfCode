#include "ball.h"

Ball::Ball() : Ball(ofPoint(0, 0), 0) {
}

Ball::Ball(float mass) : Ball(ofPoint(0, 0), mass) {
}

Ball::Ball(ofPoint position, float mass) {
    this->position = position;
    this->mass = mass;
}

void Ball::addForce(ofVec3f force) {
    acceleration += force / mass;
}

void Ball::update() {
    velocity += acceleration;
    position += velocity;
}

void Ball::draw() const {
    ofDrawCircle(position, mass * 10);
}

ofPoint Ball::getPosition() const {
    return position;
}

void Ball::boundaryCheck() {
    if (position.x < 0) {
        velocity.x = -velocity.x;
        position.x = 0;
    }

    if (position.y > ofGetHeight() - mass * 10) {
        velocity.y = -velocity.y;
        position.y = ofGetHeight() - mass * 10;
    } else if (position.x < 0) {
        velocity.y = -velocity.y;
        position.y = 0;
    }
}

