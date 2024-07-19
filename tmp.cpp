#include <iostream>
#include <string>
#include <vector>
#include "Data-Loader/data_loader.h"
using namespace std;

class Data_Loader{

public:
    Data_Loader();
    ~Data_Loader();
    int **Load_Gray(string filename, int *w, int *h);
    int ***Load_RGB(string filename, int *w, int *h);
    void Dump_Gray(int w, int h, int **pixels, string filename);
    void Dump_RGB(int w, int h, int ***pixels, string filename);
    //void Display_Gray_X_Server(int w, int h, int **pixels);
    //void Display_RGB_X_Server(int w, int h, int ***pixels);
    void Display_Gray_ASCII(int w, int h, int **pixels);
    void Display_RGB_ASCII(int w, int h, int ***pixels);
    void Display_Gray_CMD(string filename);
    void Display_RGB_CMD(string filename);
    bool List_Directory(string directoryPath, vector<string> &filenames);

private:
    bool File_Exists(const string &filename);
};



class Image{
    protected:
        int width, height;
        Data_Loader data_loader();
    public:
        Image(int width, int height);
        ~Image();
        virtual bool LoadImage(string filename) = 0;
        virtual void DumpImage(string filename) = 0;
        //virtual void Display_X_server() = 0;
        virtual void Display_ASCII() = 0;
        virtual void Display_CMD() = 0;
        int get_width();
        int get_height();
};

class gray_Image : public Image{
    private:
        int** pixels;
    public:
        gray_Image();
        gray_Image(int width, int height, int** pixels);
        ~gray_Image();
        bool LoadImage(string filename);
        void DumpImage(string filename);
        //void Display_X_server();
        void Display_ASCII();
        void Display_CMD();
        
};

class RGBImage : public Image{
    private:
        int** pixels;
    public:
        RGBImage();
        RGBImage(int width, int height, int** pixels);
        ~RGBImage();
        bool LoadImage(string filename);
        void DumpImage(string filename);
        void Display_X_server();
        void Display_ASCII();
        void Display_CMD();
        
};

int main(){
    Data_Loader data_loader;
    
    // 1. Load gray image
    int w1;
    int h1;
    int **pixels1 = data_loader.Load_Gray("Image-Folder/mnist/img_0.jpg", &w1, &h1);
    data_loader.Dump_Gray(w1, h1, pixels1, string("pixels1.jpg"));
    data_loader.Display_Gray_X_Server(w1, h1, pixels1);
    data_loader.Display_Gray_ASCII(w1, h1, pixels1);
    data_loader.Display_Gray_CMD("pixels1.jpg");

    // 2. Load rgb image into gray scale image
    int w2;
    int h2;
    int **pixels2 = data_loader.Load_Gray("Image-Folder/lena.jpg", &w2, &h2);
    data_loader.Dump_Gray(w2, h2, pixels2, string("pixels2.jpg"));
    data_loader.Display_Gray_X_Server(w2, h2, pixels2);
    data_loader.Display_Gray_CMD("pixels2.jpg");

    // 3. Load rgb image
    int w3;
    int h3;
    int ***pixels3 = data_loader.Load_RGB("Image-Folder/cifar10/airplane_0010.png", &w3, &h3);
    data_loader.Dump_RGB(w3, h3, pixels3, string("pixels3.jpg"));
    data_loader.Display_RGB_X_Server(w3, h3, pixels3);
    data_loader.Display_RGB_ASCII(w3, h3, pixels3);
    data_loader.Display_RGB_CMD("pixels3.jpg");

    // 4. List Directory
    vector<string> filenames;
    data_loader.List_Directory("Image-Folder/mnist", filenames);
    for(const auto &filename : filenames){
        cout << filename << endl;
    }
}
