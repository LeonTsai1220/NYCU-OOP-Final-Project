#ifndef _GRAY_IMAGE_H_
#define _GRAY_IMAGE_H_

#include "image.h"

class GrayImage : public Image{
    private:
        int** pixels;
    public:
        GrayImage() : Image(0,0), pixels(nullptr){}
        GrayImage(int width, int height, int** pix) : Image(width, height), pixels(pix){}
        ~GrayImage();
        bool LoadImage(string filename) override;
        void DumpImage(string filename)override;
        void Display_X_server()override;
        void Display_ASCII()override;
        void Display_CMD() override;
        
};

#endif