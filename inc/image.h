#ifndef _IMAGE_H_
#define _IMAGE_H_
#include "/home/leon/NYCU-OOP-Final-Project/Data-Loader/data_loader.h"
using namespace std;

class Image{
    protected:
        int width, height;
        static Data_Loader data_loader;
    public:
        Image(int w, int h);
        ~Image();
        virtual bool LoadImage(string filename) = 0;
        virtual void DumpImage(string filename) = 0;
        virtual void Display_X_server() = 0;
        virtual void Display_ASCII() = 0;
        virtual void Display_CMD() = 0;
        int get_width();
        int get_height();
};

#endif