#include <iostream>

Image* box_filter(Image* img, int kernel) {
    RGBImage* rgbimage = dynamic_cast<RGBImage*>(img);
    if (!rgbimage) return nullptr;

    int width = img->get_width();
    int height = img->get_height();
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

    Image* tmp = new RGBImage(width, height, newpixels);
    return tmp;
}