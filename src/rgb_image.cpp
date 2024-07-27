#include "rgb_image.h"

bool RGBImage::LoadImage(string filename){
    pixels = data_loader.Load_RGB(filename, &width, &height);
    if(pixels == nullptr){
        return 0;
    }
    else return 1;
}

void RGBImage::DumpImage(string filename){
    if(pixels == nullptr){
        cout << "there is an error" << endl;
    }
    cout << width << " " << height << " " << filename << endl;
    data_loader.Dump_RGB(width, height, pixels, filename);
    return;
}

void RGBImage::Display_X_server(){
    data_loader.Display_RGB_X_Server(width, height, pixels);
    return;
}

void RGBImage::Display_ASCII(){
    data_loader.Display_RGB_ASCII(width, height, pixels);
    return;
}


void RGBImage::Display_CMD(string filename){
    data_loader.Display_RGB_CMD(filename);
}

int*** RGBImage::get_pixels(){
    return pixels;
}