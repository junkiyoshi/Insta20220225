#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetLineWidth(3);
	ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<ofColor> color_palette;
	color_palette.push_back(ofColor(109, 23, 129));
	color_palette.push_back(ofColor(75, 83, 158));
	color_palette.push_back(ofColor(132, 93, 159));
	color_palette.push_back(ofColor(66, 35, 128));
	color_palette.push_back(ofColor(200, 64, 114));
	color_palette.push_back(ofColor(0, 160, 158));
	color_palette.push_back(ofColor(215, 130, 63));
	color_palette.push_back(ofColor(0, 0, 0));

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int x = -230; x <= 230; x += 230) {

		for (int y = -230; y <= 230; y += 230) {

			this->paletteShuffle(color_palette);

			ofFill();
			ofSetColor(color_palette[0]);
			ofDrawCircle(x, y, 100);

			ofNoFill();
			ofSetColor(color_palette[1]);
			ofDrawCircle(x, y, 100);

			auto noise_seed = ofRandom(1000);

			for (int radius = 30; radius < 85; radius += 5) {

				int deg_start = ofNoise(noise_seed, ofGetFrameNum() * 0.02 + radius * 0.0085) * 720;
				for (int i = 0; i < 2; i++) {

					ofSetColor(color_palette[2 + i]);

					ofBeginShape();
					for (int deg = deg_start + i * 180; deg < deg_start + i * 180 + 90; deg += 1) {

						ofVertex(x + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD));
					}
					ofEndShape();
				}
			}

		}
	}
}

//--------------------------------------------------------------
void ofApp::paletteShuffle(vector<ofColor>& color_palette) {

	for (int i = 0; i < color_palette.size(); i++) {

		int k = ofRandom(i, color_palette.size());
		ofColor tmp = color_palette[i];
		color_palette[i] = color_palette[k];
		color_palette[k] = tmp;
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}