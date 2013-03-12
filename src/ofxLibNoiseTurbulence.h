//
//  ofxLibNoiseTurbulence.h
//  emptyExample
//
//  Created by Pelayo M. on 12/03/13.
//
//

#pragma once

#include "ofMain.h"
#include "noise.h"

using namespace noise::module;

class ofxLibNoiseTurbulence {
    
    public:
    
        ofxLibNoiseTurbulence();
    
        
    
        void setFrequency(float value);
        float getFrequency();
        
        void setPower(float value);
        float getPower();
    
        void setRoughness(int value);
        int getRoughness();
	
        float Apply(Perlin perlinModule, float x, float y, float z);
    
        void setModule(Perlin perlinModule);
        float Apply(float x, float y, float z);
    
    private:
    
        Turbulence turbulenceModule;
        Perlin perlinModule;
    
};