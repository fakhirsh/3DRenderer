//
//  ImagePNG.cpp
//  raytracer
//
//  Created by Fakhir Shaheen on 28/06/2016.
//
//

#include "ImagePNG.hpp"
#include "lodepng.h"

namespace FEngine
{

//==================================================================================================================
    
    void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
    {
        //Encode the image
        unsigned error = lodepng::encode(filename, image, width, height);
        
        //if there's an error, display it
        if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
    }

//==================================================================================================================

    ImagePNG::ImagePNG()
    {
        width = -1;
        height = -1;
    }
    
    ImagePNG::~ImagePNG()
    {
    
    }
    
    unsigned int ImagePNG::GetWidth()
    {
        return width;
    }
    
    unsigned int ImagePNG::GetHeight()
    {
        return height;
    }
    
    void ImagePNG::SetWidth(unsigned int width)
    {
        this->width = width;
    }
    
    void ImagePNG::SetHeight(unsigned int height)
    {
        this->height = height;
    }
    
    
    bool ImagePNG::Load(std::string filename)
    {

        unsigned error = lodepng::decode(image, width, height, filename);
        
        // If there's an error, display it.
        if(error != 0)
        {
            std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
            return false;
        }

        return true;
    }
        
    bool ImagePNG::Save(std::string path)
    {
        image.resize(width * height * 4);
        for(unsigned y = 0; y < height; y++)
            for(unsigned x = 0; x < width; x++)
            {
                image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
                image[4 * width * y + 4 * x + 1] = x ^ y;
                image[4 * width * y + 4 * x + 2] = x | y;
                image[4 * width * y + 4 * x + 3] = 255;
            }
        
        encodeOneStep(path.c_str(), image, width, height);
        
        return true;
    }
        
    
}