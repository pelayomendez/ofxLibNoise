//
//  ofxLibNoiseTurbulence.cpp
//  emptyExample
//
//  Created by Pelayo M. on 12/03/13.
//
//

#include "ofxLibNoiseTurbulence.h"

//--------------------------------------------------------------
ofxLibNoiseTurbulence::ofxLibNoiseTurbulence()
{
 
    turbulenceModule.SetFrequency (1.0);
    turbulenceModule.SetPower (0.125);
    
}

//--------------------------------------------------------------
float ofxLibNoiseTurbulence::Apply(Perlin perlinModule, float x, float y, float z)
{
    
    turbulenceModule.SetSourceModule(0, perlinModule);
    float value = turbulenceModule.GetValue(x, y, z);
    return value;
    
}

//--------------------------------------------------------------
void ofxLibNoiseTurbulence::setModule(Perlin perlinModule)
{
    
    turbulenceModule.SetSourceModule(0, perlinModule);
    
}

//--------------------------------------------------------------
float ofxLibNoiseTurbulence::Apply(float x, float y, float z)
{
    
    // Aqui habria que comprobar si tiene un modulo de noise asignado o no.
    
    turbulenceModule.SetSourceModule(0, perlinModule);
    float value = turbulenceModule.GetValue(x, y, z);
    return value;
    
}

//--------------------------------------------------------------
void ofxLibNoiseTurbulence::setFrequency(float value)
{
    
    turbulenceModule.SetFrequency(getFrequency()+value);

}

//--------------------------------------------------------------
float ofxLibNoiseTurbulence::getFrequency()
{
    
    return turbulenceModule.GetFrequency();
    
}

//--------------------------------------------------------------
void ofxLibNoiseTurbulence::setPower(float value)
{
    
    turbulenceModule.SetPower(getPower()+value);

}

//--------------------------------------------------------------
float ofxLibNoiseTurbulence::getPower()
{
    
    return turbulenceModule.GetPower();
    
}


//--------------------------------------------------------------
void ofxLibNoiseTurbulence::setRoughness(int value)
{
    
    turbulenceModule.SetRoughness(getRoughness()+value);
    
}

//--------------------------------------------------------------
int ofxLibNoiseTurbulence::getRoughness()
{
    
    return turbulenceModule.GetRoughnessCount();
    
}

