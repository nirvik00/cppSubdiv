#include "Rect.h"

Pt Rect::getA() {
	return a;
}
Pt Rect::getB() {
	return b;
}
Pt Rect::getC() {
	return c;
}
Pt Rect::getD() {
	return d;
}
void Rect::clrRectVector() {
	rectVector.clear();
}
vector<Rect>Rect::getRectVector() {
	return rectVector;
}

void Rect::setIntVector(vector<int> v) {
	intVector.clear();
	intVector = v;
}

void Rect::setup(Pt a_, Pt b_, Pt c_, Pt d_) {
	a = a_;
	b = b_;
	c = c_;
	d = d_;
}
void Rect::setup(Pt arr[4]) {
	a = arr[0];
	b = arr[1];
	c = arr[2];
	d = arr[3];
}
void Rect::drawRect() {
	ofSetLineWidth(1);
	ofSetColor(0, 0, 0);
	ofLine(a.x, a.y, b.x, b.y);
	ofLine(b.x, b.y, c.x, c.y);
	ofLine(c.x, c.y, d.x, d.y);
	ofLine(d.x, d.y, a.x, a.y);
	ofLine(a.x, a.y, c.x, c.y);
	ofLine(b.x, b.y, d.x, d.y);
}
void Rect::drawRect(int t) {
	ofSetLineWidth(t);
	ofLine(a.x, a.y, b.x, b.y);
	ofLine(b.x, b.y, c.x, c.y);
	ofLine(c.x, c.y, d.x, d.y);
	ofLine(d.x, d.y, a.x, a.y);
	ofSetLineWidth(1);
}
void Rect::drawRect(vector<Rect> rV) {
	for (unsigned int i = 0; i<rV.size(); i++) {
		ofSetColor(0, 0, 0);
		ofSetLineWidth(2);
		Pt a = rV[i].getA(); 
		Pt b = rV[i].getB(); 
		Pt c = rV[i].getC(); 
		Pt d = rV[i].getD(); 
		ofLine(a.x, a.y, b.x, b.y);
		ofLine(b.x, b.y, c.x, c.y);
		ofLine(c.x, c.y, d.x, d.y);
		ofLine(d.x, d.y, a.x, a.y);
	}
	ofSetLineWidth(1);
}
void Rect::drawRect(vector<Rect>rV, int t) {
	for (unsigned int i = 0; i<rV.size(); i++) {
		ofSetColor(0, 0, 0);
		ofSetLineWidth(t);
		Pt a = rV[i].getA();
		Pt b = rV[i].getB();
		Pt c = rV[i].getC();
		Pt d = rV[i].getD();
		ofLine(a.x, a.y, b.x, b.y);
		ofLine(b.x, b.y, c.x, c.y);
		ofLine(c.x, c.y, d.x, d.y);
		ofLine(d.x, d.y, a.x, a.y);
	}	
	ofSetLineWidth(1);
}



void Rect::incrementState() {
	state++;
}
void Rect::clrState() {
	state = 0;
}
void Rect::subdivide(Rect r, int C, int re) {	
	Pt a = r.getA();
	Pt b = r.getB();
	Pt c = r.getC();
	Pt d = r.getD();
	int w = intVector[state];
	incrementState();
	cout << "rec: " << state << ", w: " << w << endl;
	Rect r0, r1;
	if (w == 0) {
		Pt m = Pt((a.x + b.x) / 2, (a.y + b.y) / 2);
		Pt n = Pt((c.x + d.x) / 2, (c.y + d.y) / 2);
		r0.setup(a, m, n, d); r1.setup(m, b, c, n);
	}
	else {
		Pt m = Pt((b.x + c.x) / 2, (b.y + c.y) / 2);
		Pt n = Pt((d.x + a.x) / 2, (d.y + a.y) / 2);
		r0.setup(a, b, m, n); r1.setup(n, m, c, d);
	}

	if (C < 2) {
		C++;
		subdivide(r0, C, re);
		subdivide(r1, C, re);
	}
	else {
		rectVector.push_back(r0); rectVector.push_back(r1);
	}

}

Rect Rect::moveRect(float x, float y) {
	Pt a = getA(); Pt b = getB(); Pt c = getC(); Pt d = getD();
	float dx = fabs(c.x - a.x); 
	Pt A = Pt(a.x + x, a.y); Pt B = Pt(b.x + x, b.y); Pt C = Pt(B.x, c.y); Pt D = Pt(A.x, d.y);
	Pt ptx[4] = { A,B,C,D };
	Rect s(ptx);
	return s;
}



