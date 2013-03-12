//
//  ofxLibNoise.cpp
//  emptyExample
//
//  Created by Pelayo M. on 09/03/13.
//
//

#include "ofxLibNoise.h"

//--------------------------------------------------------------
ofxLibNoise::ofxLibNoise(){
    
    perlinModule.SetOctaveCount (1);
	
    //turbulenceModule.SetFrequency (1.0);
    //turbulenceModule.SetPower (0.125);
	
}

//--------------------------------------------------------------
float ofxLibNoise::PerlinNoise(float x, float y, float z)
{
        
    float value = perlinModule.GetValue (x, y, z);
    return value;

}

//--------------------------------------------------------------
void ofxLibNoise::setOctaveCount(int value)
{
    int c = perlinModule.GetOctaveCount();
    perlinModule.SetOctaveCount(c+value);
}

//--------------------------------------------------------------
int ofxLibNoise::getOctaveCount()
{
    return perlinModule.GetOctaveCount();
}

//--------------------------------------------------------------
void ofxLibNoise::setNoiseFrequency(float value)
{
    float c = perlinModule.GetFrequency();
    perlinModule.SetFrequency(c+value);
}

//--------------------------------------------------------------
float ofxLibNoise::getNoiseFrequency()
{
    return perlinModule.GetFrequency();
}
