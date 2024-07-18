#include <iostream>
#include "Image_Class.h"
using namespace std;
void addframe() 
{
    while (true)
    {
        cout << "Enter photo name (.jpg or other format): ";
        string photo;
        cin >> photo;
        Image image(photo);
        int width = image.width;
        int height = image.height;
        string type;
        cout << "Enter frame type (simple or fancy): ";
        cin >> type;
        int frameSizeX = width * 0.01;
        int frameSizeY = height * 0.01;
        
        if (type == "simple")
        {
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    if (i < frameSizeX || i >= width - frameSizeX || j < frameSizeY || j >= height - frameSizeY)
                    {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 255;
                    }
                }
            }
        }
        else if (type == "fancy")
        {
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    if (i < frameSizeX || i >= width - frameSizeX || j < frameSizeY || j >= height - frameSizeY)
                    {
                        double wave = sin(0.1 * i) * sin(0.1 * j);
                        int red = 255 * (wave + 1) / 2;
                        int green = 255 * (1 - wave) / 2;
                        image(i, j, 0) = red;
                        image(i, j, 1) = green;
                        image(i, j, 2) = 255; // Blue
                    }
                }
            }
        }
        else{
            cout<<" Enter a valid frame type (simple or fancy)"<<endl;
        }
            cout << "Enter new photo name (.jpg or other format): ";
            string output_photo;
            cin >> output_photo;

            if (!image.saveImage(output_photo))
            {
                cout << "Failed to save image." << endl;
            }
            else
            {
                cout << "Image saved successfully." << endl;
                system(output_photo.c_str());
            }

            break;   
    }
}
int main() {   
    addframe();
}