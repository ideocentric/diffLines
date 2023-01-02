//
//  lineDifference.hpp
//  diffLines
//
//  Created by Matt Comeione on 1/2/23.
//

#ifndef lineDifference_hpp
#define lineDifference_hpp

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "particleLine.hpp"

class lineDifference {
public:
    vector<particleLine> particles;
    ofVideoGrabber camera;
    ofxCvColorImage image;
    ofxCvGrayscaleImage imageGray;
    ofxCvGrayscaleImage imageGrayPrevious;
    ofxCvGrayscaleImage imageDifference;
    ofPixels pxPrevious;
    ofMutex mutex;

    void setup();
    void update();
    void draw();
    bool isDead(particleLine p);
};

#endif /* lineDifference_hpp */
