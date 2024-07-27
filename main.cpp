#include "image.h"
#include "gray_image.h"
#include "rgb_image.h"
#include "photo_mosaic.h"
#include "bit_field_filter.h"
#include <jpeglib.h>    
#include <iostream>
#include "data_loader.h"
using namespace std;
int main(int argc, char *argv[]){
    
        
    Image *img1 = new GrayImage();
    if(img1->LoadImage("Image-Folder/mnist/img_100.jpg")){
        cout << "Load successfully!" << endl;
    }
    img1->DumpImage("img1.jpg");
    img1->Display_X_server();
    img1->Display_ASCII();
    //img1->Display_CMD("Image-Folder/mnist/img_100.jpg");
    

    Image *img2 = new RGBImage();
    img2->LoadImage("Image-Folder/lena.jpg");
    img2->DumpImage("img2.jpg");
    img2->Display_X_server();
    img2->Display_ASCII();
    //img2->Display_CMD();
    cout << "box filter" << endl;
    Image *img3 = new RGBImage();
    //img3->LoadImage("Image-Folder/mnist/img_99.jpg");
    img3 = box_filter(img2, 5);
    cout << "dump img3" << endl;
    img3->DumpImage("img3.jpg");
    img3->Display_X_server();
    // some bit field filter design driven code here

    // some photo mosaic driven code here

    // more ...
    return 0;
}
