//
//  ImagePNG.hpp
//  raytracer
//
//  Created by Fakhir Shaheen on 28/06/2016.
//
//

#pragma once

#include "../Common.hpp"

namespace FEngine
{
    class ImagePNG
    {
    public:
        ImagePNG();
        ~ImagePNG();
        
        bool            Load(std::string filename);
        bool            Save(std::string filename);

        unsigned int    GetWidth();
        unsigned int    GetHeight();
        void            SetWidth(unsigned int width);
        void            SetHeight(unsigned int height);

    private:
        unsigned int width, height;
        std::vector<unsigned char> image;

    };
}