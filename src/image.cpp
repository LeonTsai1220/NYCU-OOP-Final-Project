#include "/home/leon/NYCU-OOP-Final-Project/inc/image.h"
Image::Image(int w, int h){
    width = w;
    height = h;
}
Image::Image(){
    width = 0;
    height = 0;
    
}

int Image::get_height(){
    return height;
}

int Image::get_width(){
    return width;
}
