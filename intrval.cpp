#include <iostream>
using namespace std;
#include "Image_Class.h"
#include <cstdio>

int main()
{
    cout<<"Enter photo name (.jpg or other format): ";
    string Invert_photo;
    cin>> Invert_photo;

    Image image(Invert_photo);
    for(int i=0; i<image.width; i++)  // row .......
    {
        for (int j = 0; j < image.height; j++) //col
        {                                      //.
                                                //.
           for(int k=0;k<3;k++){  // 3=channles
            image(i, j, k) = 255 - image(i, j, k);
           }
        }
    }
    cout<<"Enter new photo name (.jpg or other format): ";
    cin>>Invert_photo; //newfile
    image.saveImage(Invert_photo);
    system(Invert_photo.c_str());//show photo after end
}
