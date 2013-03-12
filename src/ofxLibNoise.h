/*
 *  ofxLibNoise.h
 *
 *  Created by Pelayo Méndez on 09/10/13.
 *  No rights reserved.
 *  
 *  libnoise Openframeworks addon.
 *  http://libnoise.sourceforge.net/
 *
 *	Dependencies: ---
 *
 *  Created with OpenFrameworks 0074
 */

#pragma once

#include "ofMain.h"
#include "noise.h"
#include "ofxLibNoiseTurbulence.h"

using namespace noise;

class ofxLibNoise {
    
    public:
    
        ofxLibNoise();
    
        float PerlinNoise(float x, float y, float z);
       
    
    
        void setOctaveCount(int value);
        int getOctaveCount();
    
        void setNoiseFrequency(float value);
        float getNoiseFrequency();
    
        module::Perlin perlinModule;
    
    private:
    
    
};