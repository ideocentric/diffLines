//
//  particleLine.hpp
//  diffLines
//
//  Created by Matt Comeione on 1/2/23.
//

#ifndef particleLine_hpp
#define particleLine_hpp

#include "ofMain.h"


class particleLine {
public:
    ofColor color;
    bool dead, growing;
    float size, length, growth, decay, width;
    glm::vec2 force, direction, position;
    
    particleLine(int x, int y, ofColor c);
    particleLine(int x, int y, ofColor c, float size);
    ~particleLine();
    
    void update();
    void draw();
};

#endif /* particleLine_hpp */
