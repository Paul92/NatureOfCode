#include "baloon.h"

Baloon::Baloon() {
    width = 0;
    height = 0;
    position = ofPoint(ofGetWidth() / 2, ofGetHeight());
}

void Baloon::setSize(float width, float height) {
    this->width = width;
    this->height = height;
}

void Baloon::setMass(float mass) {
    this->mass = mass;
}

void Baloon::addForce(ofVec3f force) {
    netForce += force;
}

void Baloon::update() {
    velocity += netForce / mass;
    position += velocity;

    netForce = ofVec3f(0, 0);
}

void Baloon::draw() {
    ofDrawEllipse(position, width, height);
}

ofVec3f Baloon::getVelocity() {
    return velocity;
}

ofPoint Baloon::getPosition() {
    return position;
}

void Baloon::setVelocity(ofVec3f velocity) {
    this->velocity = velocity;
}
