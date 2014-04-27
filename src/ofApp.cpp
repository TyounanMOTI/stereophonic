#include "ofApp.h"

#include <iostream>
#include <boost/format.hpp>

namespace {
    class AzimuthListGenerator_CIAIR
    {
    public:
        typedef int value_type;
        typedef size_t size_type;

        static const value_type AZIMUTH_INTERVAL = 5;
        static const size_type NUM_DATA = 360 / AZIMUTH_INTERVAL;

        AzimuthListGenerator_CIAIR() : azimuth_(-AZIMUTH_INTERVAL) {}

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

HRTFLoader::HRTFLoader(const std::string& path) : available_azimuth_(AzimuthListGenerator_CIAIR::NUM_DATA)
{
    std::generate(available_azimuth_.begin(), available_azimuth_.end(), AzimuthListGenerator_CIAIR());

    std::string filename_left_ear  = str(boost::format("%s/elev0/L0e%03da.dat") % path % 0);
}

//--------------------------------------------------------------
void ofApp::setup(){
    HRTFLoader loader("CIAIR");
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
