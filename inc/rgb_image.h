#ifndef _RGB_IMAGE_H_
#define _RGB_IMAGE_H_

#include "image.h"


class RGBImage : public Image{
    private:
        int*** pixels;
    public:
        RGBImage() : Image(0, 0), pixels(nullptr){}
        RGBImage(int width, int height, int*** pix) : Image(width, height), pixels(pix){}
        ~RGBImage();
        bool LoadImage(string filename);
        void DumpImage(string filename);
        void Display_X_server();
        void Display_ASCII();
        void Display_CMD(string filename);
        
};
#endif