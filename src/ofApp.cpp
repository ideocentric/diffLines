#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    particles.setup();
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    
    recorder.setup(true,false);
    recorder.setWidth(ofGetWidth());
    recorder.setHeight(ofGetHeight());
    recorder.setFFmpegPath(ofToDataPath("ffmpeg"));
    recorder.setFps(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    particles.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    fbo.begin();
    particles.draw();
    fbo.end();
    ofSetColor(255);
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    if(recorder.isRecording()) {
        if(bRecording) {
            fbo.readToPixels(pixels);
            if(pixels.getWidth() > 0 && pixels.getHeight()>0) {
                recorder.addFrame(pixels);
            }
        }
    }
    ofDrawBitmapString(ofToString( ofGetFrameRate() ), 10,15);
    ofDrawBitmapString(ofToString( particles.particles.size() ), 10,30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'r':
            bRecording = !bRecording;
            if(recorder.isRecording()) {
                recorder.stop();
            } else {
                recorder.setOutputPath(ofToDataPath("difflines.mp4", true));
                recorder.startCustomRecord();
            }
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
