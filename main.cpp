#include "ofMain.h"
#include "ofApp.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

//========================================================================
int main( ){
	ofSetupOpenGL(1050,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
