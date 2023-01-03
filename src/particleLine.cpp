//
//  particleLine.cpp
//  diffLines
//
//  Created by Matt Comeione on 1/2/23.
//

#include "particleLine.hpp"


//--------------------------------------------------------------
particleLine::particleLine(int x, int y, ofColor c) {
    position = glm::vec2(x, y);
    size = ofRandom(50,400);
    growth = size/60*2;  // full size in 30 frames
    decay = size/60/5;
    length = 1;
    width = ofRandom(0.5, 4.0);
    color.setHsb(c.getHue(), c.getSaturation(), c.getBrightness(), 200);
    dead = false;
    growing = true;
    force = glm::vec2(0, 0.02);
    direction = glm::vec2(ofRandom(-1.0, 1.0), ofRandom(-2.0, 2.0));
}


//--------------------------------------------------------------
particleLine::particleLine(int x, int y, ofColor c, float s) {
    position = glm::vec2(x, y);
    size = s*2;
    growth = size/60*2;  // full size in 30 frames
    decay = size/60/5; //
    length = 1;
    width = ofRandom(0.5, 4.0);
    color.setHsb(c.getHue(), c.getSaturation(), c.getBrightness(), 200);
    dead = false;
    growing = true;
    force = glm::vec2(0, 0.02);
    direction = glm::vec2(ofRandom(-1.0, 1.0), ofRandom(-2.0, 2.0));
}


//--------------------------------------------------------------
particleLine::~particleLine() {
    
}


//--------------------------------------------------------------
void particleLine::update() {
    position += direction;
    direction += force;
    if(growing) {
        length += growth;
        if(length>= size) {
            growing = false;
        }
    }
    else {
        length -= decay;
        if(length<1) {
            length = 1;
        }
    }
    float brightness = color.getBrightness();
    if(brightness > 1) {
        color.setBrightness(brightness -= 0.5);
    }
    else {
        color.setBrightness(0);
        dead = true;
    }
    if(position.x < 0 || position.x > ofGetWidth() || position.y > ofGetHeight())
    {
        dead = true;
    }
}


//--------------------------------------------------------------
void particleLine::draw() {
    ofSetColor(color);
    ofSetLineWidth(width);
    glm::vec2 diff = glm::vec2(0, length);
    glm::vec2 end = position + diff;
    ofDrawLine(position, end);
}
