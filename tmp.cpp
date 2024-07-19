#include <iostream>
#include <string>
#include <vector>
#include "Data-Loader/data_loader.h"
#include "/home/leon/NYCU-OOP-Final-Project/Data-Loader/data_loader.h"
#include "/home/leon/NYCU-OOP-Final-Project/inc/gray_image.h"
using namespace std;



int main(){
    
    Image *img1 = new GrayImage();
    img1->LoadImage("Image-Folder/mnist/img_100.jpg");
    img1->DumpImage("img1.jpg");
    img1->Display_X_server();
    img1->Display_CMD();
    
}
