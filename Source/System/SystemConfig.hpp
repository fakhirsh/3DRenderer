//
//  SystemConfig.hpp
//  raytracer
//
//  Created by Fakhir Shaheen on 28/06/2016.
//
//

#ifndef SystemConfig_hpp
#define SystemConfig_hpp

#include "../Common.hpp"

#include "../ResourceCache/IOManager.hpp"
#include "../Debugging/Log.hpp"

namespace FEngine
{
    //class IOManager;
    class IRenderer;
    class Log;

    class SystemConfig
    {
    public:
        SystemConfig();
        
        /*
         *  LoadConfiguration
         *  @param  buffer    A memory buffer containing entire config XML file.
         */
        bool        LoadConfig      (std::vector<char> & buffer);
        
        std::string sceneName;
        std::string version;
        std::string assetPath;
        std::string outputPath;
        
        int         imageWidth;
        int         imageHeight;
        int         msAA;
        
        std::shared_ptr<IOManager>  ioManager;
        std::shared_ptr<Log>        log;
        
    private:
        
    };
}

#endif /* SystemConfig_hpp */
