#pragma once

#include "ofMain.h"

#include <vector>
#include <iostream>
#include <stdlib.h>
#include "time.h"

#include "Pt.h"
#include "Rect.h"
#include "ctrlVector.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		/*my global variables*/
		vector< vector<int> > vecIntVec; // vector of control vectors
		int NUM = 10;

		/* single elements*/
		Pt a, b, c, d; // points
		
		/* vector of single elements*/
		vector<Rect> vecIniRect;
		vector< vector<Rect> > vecOutRect;


};