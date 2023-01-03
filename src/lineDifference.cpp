//
//  lineDifference.cpp
//  diffLines
//
//  Created by Matt Comeione on 1/2/23.
//

#include "lineDifference.hpp"

//--------------------------------------------------------------
void lineDifference::setup(){
    ofBackground(0);
    camera.setup(1280, 720);
    camera.setDesiredFrameRate(15);
//    image.allocate(camera.getWidth(), camera.getHeight());
//    imageGray.allocate(camera.getWidth(), camera.getHeight());
//    imageGrayPrevious.allocate(camera.getWidth(), camera.getHeight());
}


//--------------------------------------------------------------
void lineDifference::update(){
    camera.update();
    if(camera.isFrameNew()) {
        if(imageGray.bAllocated)
        {
            imageGrayPrevious = imageGray;
        }
        
        image.setFromPixels(camera.getPixels());
        imageGray.setFromColorImage(image);
        
        if(imageGrayPrevious.bAllocated) {
            imageDifference.absDiff(imageGray, imageGrayPrevious);
        }
    }
    for(vector<particleLine>::iterator it = particles.begin(); it != particles.end(); ) {
        (*it).update();
        if( (*it).dead ) {
            it = particles.erase(it);
        }
        else {
            ++it;
        }

    }

}


//--------------------------------------------------------------
void lineDifference::draw(){
    ofBackground(0, 0, 0 );
    float m = ofGetWidth()/camera.getWidth();
    for(int y=0; y<camera.getHeight(); y+=10) {
        for(int x=0; x<camera.getWidth(); x+=10) {
            ofColor gray = imageDifference.getPixels().getColor(x, y);
            int brightness = gray.getBrightness();
            if(brightness>50) {
                float size = ofMap(brightness, 0, 255, 5, 100);
                ofColor color = image.getPixels().getColor(x, y);
                particleLine particle(x*m, y*m, color, size);
                particles.push_back(particle);
            }
        }
    }
    for(vector<particleLine>::iterator it = particles.begin(); it != particles.end(); ++it) {
        (*it).draw();
    }

}

//--------------------------------------------------------------
bool lineDifference::isDead(particleLine p){
    return p.dead;
}
    
    
