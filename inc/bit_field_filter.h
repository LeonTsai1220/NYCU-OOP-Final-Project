#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
Image* box_filter(Image* img, int kernel) {
    RGBImage* rgbimage = dynamic_cast<RGBImage*>(img);
    GrayImage* grayimage = dynamic_cast<GrayImage*>(img);
    int width = img->get_width();
    int height = img->get_height();
    Image* tmp;

    if (rgbimage){
        int*** pixels = rgbimage->get_pixels();
        int*** newpixels = new int**[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int*[width];
            for (int i = 0; i < width; i++) {
                newpixels[c][i] = new int[3];
            }
        }
        for (int c = 0; c < 3; c++) {
            for (int i = 0; i < height - kernel; i++) {
                for (int j = 0; j < width - kernel; j++) {
                    int sum = 0;
                    int count = 0;
                    for (int k = i; k < i + kernel; k++) {
                        for (int t = j; t < j + kernel; t++) {
                            sum += pixels[k][t][c];
                            count++;
                        }
                    }
                    int average = sum / count;
                    for (int k = i; k < i + kernel; k++) {
                        for (int t = j; t < j + kernel; t++) {
                            newpixels[k][t][c] = average;
                        }
                    }
                }
            }
        }
        tmp = new RGBImage(width, height, newpixels);

    
    }
    if(grayimage){
        int** pixels = grayimage->get_pixels();
        int** newpixels = new int*[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int[width];
        }
       
        for (int i = 0; i < height - kernel; i++) {
            for (int j = 0; j < width - kernel; j++) {
                int sum = 0;
                int count = 0;
                for (int k = i; k < i + kernel; k++) {
                    for (int t = j; t < j + kernel; t++) {
                        sum += pixels[k][t];
                        count++;
                    }
                }
                int average = sum / count;
                for (int k = i; k < i + kernel; k++) {
                    for (int t = j; t < j + kernel; t++) {
                        newpixels[k][t] = average;
                    }
                }
            }
        }    
        tmp = new GrayImage(width, height, newpixels);

        

    }


    


    return tmp;
}

int conv(int A[3][3], int B[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
           
           
            sum += A[i][j] * B[i][j];
            
        }
    }
    return sum;
}
Image* sobel_filter(Image* img, int kernel) {
    RGBImage* rgbimage = dynamic_cast<RGBImage*>(img);
    GrayImage* grayimage = dynamic_cast<GrayImage*>(img);
    int width = img->get_width();
    int height = img->get_height();
    int Gx[3][3] ={{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0},  {1, 2, 1}};
    Image* tmp;
    int bound = kernel / 2;
    cout << bound << endl;
    if(grayimage){
        int** pixels = grayimage->get_pixels();
        int** newpixels = new int*[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int[width];
        }
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int sumGx = 0;
                int sumGy = 0;
                int matrix[3][3] = {0};
                //memset(matrix, 0, sizeof(matrix));
                for (int k = -bound; k <= bound; ++k) {
                    for (int t = -bound; t <= bound; ++t) {
                        int y = i + k;
                        int x = j + t;
                        if (y >= 0 && y < height && x >= 0 && x < width) {
                            matrix[k + bound][t + bound] = pixels[y][x];
                        } else {
                            matrix[k + bound][t + bound] = 0;
                        }
                    }
                }
                sumGx = conv(Gx, matrix);
                sumGy = conv(Gy, matrix);
                newpixels[i][j] = min(255, static_cast<int>(std::sqrt(sumGx * sumGx + sumGy * sumGy)));
            }
        }
        
        tmp = new GrayImage(width, height, newpixels);

        

    }


    


    return tmp;
}


Image* contrast_stretching(Image* img) {
    RGBImage* rgbimage = dynamic_cast<RGBImage*>(img);
    GrayImage* grayimage = dynamic_cast<GrayImage*>(img);
    int width = img->get_width();
    int height = img->get_height();
    Image* tmp;
    if(grayimage){
        int** pixels = grayimage->get_pixels();
        int** newpixels = new int*[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int[width];
        }
        int max = -1, min = 256;
        for(int i = 0;i < height; i++){
            for(int j = 0;j<width; j++){
                if(pixels[i][j] > max){
                    max = pixels[i][j];
                }
                if(pixels[i][j] < min){
                    min = pixels[i][j];
                }
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                newpixels[i][j] = static_cast<uint8_t>(255.0 * (pixels[i][j] - min) / (max - min));
            }
        }
        
        tmp = new GrayImage(width, height, newpixels);

        

    }

    if (rgbimage){
        int*** pixels = rgbimage->get_pixels();
        int*** newpixels = new int**[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int*[width];
            for (int i = 0; i < width; i++) {
                newpixels[c][i] = new int[3];
            }
        }
        
        int max = -1, min = 256;
        for(int c = 0;c < 3;c++){
            for(int i = 0;i < height; i++){
                for(int j = 0;j<width; j++){
                    if(pixels[i][j][c] > max){
                        max = pixels[i][j][c];
                    }
                    if(pixels[i][j][c] < min){
                        min = pixels[i][j][c];
                    }
                }
            }
        }
        for(int c = 0;c < 3;c++){
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    newpixels[i][j][c] = static_cast<uint8_t>(255.0 * (pixels[i][j][c] - min) / (max - min));
                }
            }
        }
        
        tmp = new RGBImage(width, height, newpixels);

        

    }
    


    return tmp;
}

Image* mosaic_filter(Image* img, int kernel) {
    RGBImage* rgbimage = dynamic_cast<RGBImage*>(img);
    GrayImage* grayimage = dynamic_cast<GrayImage*>(img);
    int width = img->get_width();
    int height = img->get_height();
    Image* tmp;

    if (rgbimage){
        int*** pixels = rgbimage->get_pixels();
        int*** newpixels = new int**[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int*[width];
            for (int i = 0; i < width; i++) {
                newpixels[c][i] = new int[3];
            }
        }
        for (int c = 0; c < 3; c++) {
            for (int i = 0; i < height; i+=kernel) {
                for (int j = 0; j < width; j+=kernel) {
                    int sum = 0;
                    int count = 0;
                    for (int k = i; k < i + kernel && k < height; k++) {
                        for (int t = j; t < j + kernel && t < width; t++) {
                            sum += pixels[k][t][c];
                            count++;
                        }
                    }
                    int average = sum / count;
                    for (int k = i; k < i + kernel && k < height; k++) {
                        for (int t = j; t < j + kernel && t < width; t++) {
                            newpixels[k][t][c] = average;
                        }
                    }
                }
            }
        }
        tmp = new RGBImage(width, height, newpixels);

    
    }
    if(grayimage){
        int** pixels = grayimage->get_pixels();
        int** newpixels = new int*[height];
        for (int c = 0; c < height; c++) {
            newpixels[c] = new int[width];
        }
       
        for (int i = 0; i < height; i+=kernel) {
            for (int j = 0; j < width; j+=kernel) {
                int sum = 0;
                int count = 0;
                for (int k = i; k < i + kernel && k < height; k++) {
                    for (int t = j; t < j + kernel && t < width; t++) {
                        sum += pixels[k][t];
                        count++;
                    }
                }
                int average = sum / count;
                for (int k = i; k < i + kernel && k < height; k++) {
                    for (int t = j; t < j + kernel && t < width; t++) {
                        newpixels[k][t] = average;
                    }
                }
            }
        }    
        tmp = new GrayImage(width, height, newpixels);

        

    }


    


    return tmp;
}

