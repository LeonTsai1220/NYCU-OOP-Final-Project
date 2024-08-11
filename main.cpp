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
    if(img1->LoadImage("Image-Folder/img6.png")){
        cout << "Load successfully!" << endl;
    }
    img1->DumpImage("img1.jpg");
    img1->Display_X_server();
    //img1->Display_ASCII();
    //img1->Display_CMD("Image-Folder/mnist/img_100.jpg");
    

    Image *img2 = new RGBImage();
    img2->LoadImage("Image-Folder/lena.jpg");
    img2->DumpImage("img2.jpg");
    img2->Display_X_server();
    //img2->Display_ASCII();
    //img2->Display_CMD();
    cout << "box filter" << endl;
    Image *img3 = new RGBImage();
    //img3->LoadImage("Image-Folder/mnist/img_99.jpg");
    img3 = box_filter(img2, 5);
    cout << "dump img3" << endl;
    img3->DumpImage("img3.jpg");
    img3->Display_X_server();


    Image *img4 = new GrayImage();
    img4 = box_filter(img1, 10);
    cout << "dump img4" << endl;
    img4->DumpImage("img4.jpg");
    img4->Display_X_server();


    Image *img5 = new GrayImage();
    img5 = sobel_filter(img1, 3);
    img5->DumpImage("img5.jpg");
    img5->Display_X_server();


    Image * img6 = new GrayImage();
    img6 = contrast_stretching(img1);
    img6->DumpImage("img6.jpg");
    img6->Display_X_server();

    Image * img7 = new RGBImage();
    img7 = contrast_stretching(img2);
    img7->DumpImage("img7.jpg");
    img7->Display_X_server();
    // some bit field filter design driven code here
    Image * img8 = new GrayImage();
    img8 = mosaic_filter(img1, 5);
    img8->DumpImage("img8.jpg");
    img8->Display_X_server();

    // some photo mosaic driven code here
    Image * img9 = new RGBImage();
    img9 = mosaic_filter(img2, 5);
    img9->DumpImage("img9.jpg");
    img9->Display_X_server();

    // more ...
    return 0;
}
