#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(125);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    
    angle = 0;
  

    historySize = ofGetWidth()/2;
	
    PerlinNoiseData = new float[historySize];
	TurbulenceData = new float[historySize];
    
    for (int i=0; i<historySize; i++){
		PerlinNoiseData[i] = 0;
        TurbulenceData[i] = 0;
	}
    
    
    //
    
    //turbulence.setModule(noise.perlinModule);
    

}

//--------------------------------------------------------------
void testApp::update(){

    
    
    
    //testvalue = noise.testFunction(0,0,sin(angle));
    //ofLogNotice(ofToString(testvalue));
    
    // Shift all of the old data forward through the array
	for (int i=(historySize-1); i>0; i--){
        PerlinNoiseData[i] = PerlinNoiseData[i-1];
		TurbulenceData[i] = TurbulenceData[i-1];
	}
	
    float perlinValue = noise.PerlinNoise(0,0,sin(angle));
    float turbulenceValue = turbulence.Apply(noise.perlinModule,0,0,sin(angle));
    
	TurbulenceData[0] = turbulenceValue;
	PerlinNoiseData[0] = perlinValue;
        
    angle += 0.005;
    
        
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // draw a "baseline"
    
	ofSetColor(0,0,0, 64);
	ofLine(ofGetWidth(),ofGetHeight()/2, 0,ofGetHeight()/2);
	
    // Draw Turbulence
    
    ofPushMatrix();
	// draw a wiggly line
	ofSetColor(255,0,0, 192);
	ofPolyline wigglyPolyLine;
	for (int i=0; i<historySize; i++){
		// From the 'i' iterator, use ofMap to compute both
		// an angle (around a circle) and an alpha value.
		float px = ofGetWidth()/2-i;
		float py = ofGetHeight()/2+100 * TurbulenceData[i];
		wigglyPolyLine.addVertex(ofVec2f(px,py));
	}
	
	// draw the line
	wigglyPolyLine.draw();
	ofPopMatrix();
    
    //ofSetColor(0, 0, 0);
    ofFill();
    ofCircle(ofGetWidth()/2,ofGetHeight()/2+(TurbulenceData[0]*100),4);
    ofNoFill();
    ofCircle(ofGetWidth()/2,ofGetHeight()/2+(TurbulenceData[0]*100),4);
    
    
    // DRaw Perlin
    
    ofPushMatrix();
	// draw a wiggly line
	ofSetColor(0,0,255, 192);
	wigglyPolyLine.clear();
	for (int i=0; i<historySize; i++){
		// From the 'i' iterator, use ofMap to compute both
		// an angle (around a circle) and an alpha value.
		float px = ofGetWidth()/2-i;
		float py = ofGetHeight()/2+100 * PerlinNoiseData[i];
		wigglyPolyLine.addVertex(ofVec2f(px,py));
	}
	
	// draw the line
	wigglyPolyLine.draw();
	ofPopMatrix();
    
    
    ofFill();
    ofCircle(ofGetWidth()/2,ofGetHeight()/2+(PerlinNoiseData[0]*100),4);
    ofNoFill();
    ofCircle(ofGetWidth()/2,ofGetHeight()/2+(PerlinNoiseData[0]*100),4);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("ofxLibNoise :: Turbulence & Perlin Noise", ofPoint(10,20));
    ofDrawBitmapString("The red line represents turbulence variations to perlin's noise blue line.", ofPoint(10,35));

    ofDrawBitmapString("(q/w) Perlin Octaves:  " +  ofToString(noise.getOctaveCount()), ofPoint(10,55));
    ofDrawBitmapString("(a/s) Perlin Frequency:  " +  ofToString(noise.getNoiseFrequency()), ofPoint(10,70));
    
    ofDrawBitmapString("(e/r) Turbulence Frequency: " +  ofToString(turbulence.getFrequency()), ofPoint(10,100));
    ofDrawBitmapString("(d/f) Turbulence Power: " + ofToString(turbulence.getPower()), ofPoint(10,115));
    ofDrawBitmapString("(c/v) Turbulence Roughness: " + ofToString(turbulence.getRoughness()), ofPoint(10,130));
    
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), ofPoint(10,160));
    
    // The frequency of the turbulence determines how often the coordinates of the input value changes. The power of the turbulence determines the magnitude of these changes.
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    // Los sets no son sets tendria que haber un increment y checkeo de que no sea menos de 0.
    
    if(key == 'q'){
        noise.setOctaveCount(-1);
    }
    
    if(key == 'w'){
        noise.setOctaveCount(1);
    }

    if(key == 'a'){
        noise.setNoiseFrequency(-0.1);
    }
    
    if(key == 's'){
        noise.setNoiseFrequency(0.1);
    }
    
    if(key == 'e') {
        turbulence.setFrequency(-0.1);
    }
    
    if(key == 'r'){
        turbulence.setFrequency(0.1);
    }
    
    if(key == 'd') {
        turbulence.setPower(-0.001);
    }
    
    if(key == 'f'){
        turbulence.setPower(0.001);
    }
    
    if(key == 'c') {
        turbulence.setRoughness(-1);
    }
    
    if(key == 'v'){
        turbulence.setRoughness(1);
    }

    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}