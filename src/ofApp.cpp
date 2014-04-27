#include "ofApp.h"

#include <iostream>

namespace {
    class AzimuthListGenerator_CIAIR
    {
    public:
        typedef int value_type;
        typedef size_t size_type;

        static const value_type AZIMUTH_INTERVAL = 5;
        static const size_type NUM_DATA = 360 / AZIMUTH_INTERVAL;

        AzimuthListGenerator_CIAIR() : azimuth_(-5) {}

        value_type operator ()()
        {
            azimuth_ += AZIMUTH_INTERVAL;
            return azimuth_;
        }

    private:
        value_type azimuth_;
    };

    template <typename T>
    class PrintNum
    {
    public:
        void operator ()(T num)
        {
            std::cout << num << std::endl;
        }
    };

    template <typename T>
    void DumpVector(const std::vector<T>& input)
    {
        for_each(input.begin(), input.end(), PrintNum<T>());
    }
}

HRTFLoader::HRTFLoader(const std::string& path)
{
    std::vector<AzimuthListGenerator_CIAIR::value_type> available_azimuth(AzimuthListGenerator_CIAIR::NUM_DATA);
    std::generate(available_azimuth.begin(), available_azimuth.end(), AzimuthListGenerator_CIAIR());
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    HRTFLoader loader("CIAIR/");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
