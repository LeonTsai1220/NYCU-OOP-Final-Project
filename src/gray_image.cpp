#include "/home/leon/NYCU-OOP-Final-Project/inc/gray_image.h"

bool GrayImage::LoadImage(string filename){
    pixels = data_loader.Load_Gray(filename, &width, &height);
    if(pixels == nullptr){
        return 0;
    }
    else return 1;
}

void GrayImage::DumpImage(string filename){
    if(pixels == nullptr){
        cout << "there is an error" << endl;
    }
    cout << width << " " << height << " " << filename << endl;
    data_loader.Dump_Gray(width, height, pixels, filename);
    return;
}

void GrayImage::Display_X_server(){
    data_loader.Display_Gray_X_Server(width, height, pixels);
    return;
}

void GrayImage::Display_ASCII(){
    data_loader.Display_Gray_ASCII(width, height, pixels);
    return;
}


void GrayImage::Display_CMD(string filename){
    data_loader.Display_Gray_CMD(filename);
}

int ** GrayImage::get_pixels(){
    return pixels;
}