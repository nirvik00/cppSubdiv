#include "ofApp.h"
#include "Pt.h"
#include "Rect.h"
#include "ctrlVector.h"

void ofApp::setup(){
	srand(time(NULL));
	vecIniRect.clear();
	vecOutRect.clear();

	for (unsigned int i = 300; i < 300*3; i+=325) {
		for (unsigned int j = 0; j < 300 * 2; j += 325) {
			a = Pt(50 + i, 50 + j);
			b = Pt(a.x + 300, a.y);
			c = Pt(a.x + 300, b.y + 250);
			d = Pt(a.x, c.y);

			ctrlVector cv; // control vector
			vector<int> cvV;// initialize the control vector
			cvV.clear(); // clear the control vector
			cvV = cv.newIntVector(NUM);

			Rect r(a, b, c, d); // setup the initial rectangle
			r.setIntVector(cvV); // generate & set control vector to Rect
			vecIniRect.push_back(r); //make a vector of initial rectangles
			r.clrState();
			r.subdivide(r, 0, 0); // construct the vectors of rects from initial rect

			vector<Rect> rv;
			rv.clear();
			rv = r.getRectVector();// get the vector of output vectors
			vecOutRect.push_back(rv); // vector of output vectors from subdivision of initial rectangles
		}
	}
}

void ofApp::update(){}

void ofApp::draw(){	
	ofBackground(255, 255, 255);
	for (int i = 0; i < vecOutRect.size(); i++) {
		for (int j = 0; j < vecOutRect[i].size(); j++) {
			vecOutRect[i][j].drawRect();
		}		
	}
}

void ofApp::keyPressed(int key){
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){
	setup();
}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
