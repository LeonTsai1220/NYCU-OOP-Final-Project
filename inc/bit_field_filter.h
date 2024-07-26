#include <iostream>

int** box_filter(Image *img, int kernel){
    GrayImage* grayimage = dynamic_cast<GrayImage*>(img);
    int width = img->get_width();
    int height = img->get_height();
    int** pixels = grayimage->get_pixels();
    int** newpixels = new int*[width];
    for(int i=0;i<width;i++){
        newpixels[i] = new int[height];
    }
    for(int i=0;i<width-kernel;i++){
        for(int j=0;j<height-kernel;j++){
            int sum = 0;
            for(int k=i;k<i+kernel;k++){
                for(int t = j;j < j + kernel;t++){
                    sum += pixels[k][t];
                }
            }
            sum /= (kernel * kernel);
            for(int k=i;k<i+kernel;k++){
                for(int t = j;j < j + kernel;t++){
                    newpixels[k][t] = sum;
                }
            }
        }
    }
    return newpixels;


}