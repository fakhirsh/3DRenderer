//
//  SystemConfig.cpp
//  raytracer
//
//  Created by Fakhir Shaheen on 28/06/2016.
//
//

#include "SystemConfig.hpp"
#include <tinyxml2.h>

//#include "IOManager.h"

//using namespace tinyxml2;

namespace FEngine
{
    
    SystemConfig::SystemConfig()
    {
        imageWidth          =   -1;
        imageHeight         =   -1;
        msAA                =   -1;
    }
    
    bool SystemConfig::LoadConfig(std::vector<char> & buffer)
    {
        tinyxml2::XMLDocument configXML;
        tinyxml2::XMLError xmlErr;
        
        xmlErr = configXML.Parse((const char*)&buffer[0], buffer.size());
        if(xmlErr != tinyxml2::XML_SUCCESS)
        {
            return false;
        }
        
        tinyxml2::XMLElement * root;
        tinyxml2::XMLElement * child;
        
        root = configXML.FirstChildElement( "SystemConfig" );
        
        child = root->FirstChildElement( "AppDescription" );
        if(child != NULL){
            sceneName= child->Attribute("sceneName");
            version = child->Attribute("version");
            outputPath = child->Attribute("outputPath");
        }
        
        child = child->NextSiblingElement( "Graphics" );
        if(child != NULL){
            sscanf(child->Attribute("imageWidth"), "%d", &imageWidth);
            sscanf(child->Attribute("imageHeight"), "%d", &imageHeight);
            
            sscanf(child->Attribute("msAA"), "%d", &msAA);
        }
        
        return true;
    }
    
};