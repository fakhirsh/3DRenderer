//#define GLFW_INCLUDE_GLU

#include "Common.hpp"
#include "Raytracer.hpp"

using namespace std;
using namespace FEngine;

//////////////////////////////////////////////////////////////
///   Global variables


///////////////////////////////////////////////////////////////


int main(int argc, char * argv[])
{
    
    
    SystemConfig sysConfig;
    
    sysConfig.assetPath = "../Assets/";
    
    // Set file manager BEFORE calling Init
    std::shared_ptr<IOManager> ioPtr(new IOManagerDefault());
    sysConfig.ioManager = ioPtr;
    
    // Set Logger
    std::shared_ptr<Log> logPtr(new LogDefault());
    sysConfig.log = logPtr;
    
    vector<char> buffer;
    string sysConfXMLPath = sysConfig.assetPath + "Config/SystemConfig.xml";
    if(!sysConfig.ioManager->GetAssetStream(sysConfXMLPath, buffer))
    {
        // Error opening config file
        sysConfig.log->Print("--- Error opening Config/SystemConfig.xml ---");
    }
    
    if(!sysConfig.LoadConfig(buffer))
    {
        // Error parsing config file
        sysConfig.log->Print("--- Error parsing Config/SystemConfig.xml ---");
        
        return 1;
    }
    
    sysConfig.log->Print("Successfully loaded: Config/SystemConfig.xml");
    
    sysConfig.log->Print("Raytracer ...");
    
    ImagePNG img;
    img.SetWidth(2048);
    img.SetHeight(2048);
    img.Save("myPng.png");
    
    return 0;
}


