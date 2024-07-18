#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;


void Rotate_Image()
{
    while (true)
    {
        cout << "Enter photo name (.jpg or other format): ";
        string photo;
        cin >> photo;
        int degree;
        cout << "Enter rotation degree (90, 180, or 270): ";
        cin >> degree;
        if (degree == 180)
        {
            Image image(photo);
            int width = image.width;
            int height = image.height;

            Image rotated(width,height); 
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    rotated(width - 1 - j, height - 1 - i, 0) = image(j, i, 0);
                    rotated(width - 1 - j, height - 1 - i, 1) = image(j, i, 1);
                    rotated(width - 1 - j, height - 1 - i, 2) = image(j, i, 2);
                }
            }
            cout << "Enter new photo name (.jpg or other format): ";
            string output_photo;
            cin >> output_photo;

            // Save the rotated image
            if (!rotated.saveImage(output_photo))
            {
                cout << "Failed to save image." << endl;
            }
            else
            {
                cout << "Image saved successfully." << endl;
                system(output_photo.c_str()); // Show photo after processing
            }

            break;
        }
        else if (degree == 270)
        {
            Image image(photo);
            int width = image.width;
            int height = image.height;

            Image rotated(height, width); 
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    rotated(j, width - 1 - i, 0) = image(i, j, 0);
                    rotated( j, width - 1 - i, 1) = image(i, j, 1);
                    rotated(j, width - 1 - i, 2) = image(i, j, 2);
                }
            }
            cout << "Enter new photo name (.jpg or other format): ";
            string output_photo;
            cin >> output_photo;

            // Save the rotated image
            if (!rotated.saveImage(output_photo))
            {
                cout << "Failed to save image." << endl;
            }
            else
            {
                cout << "Image saved successfully." << endl;
                system(output_photo.c_str()); // Show photo after processing
            }

            break;
        }
        else if (degree == 90)
        {
            Image image(photo);
            int width = image.width;
            int height = image.height;
            Image rotated(height, width);

            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    rotated(height - 1 - j, i, 0) = image(i, j, 0);
                    rotated(height - 1 - j, i, 1) = image(i, j, 1);
                    rotated(height - 1 - j, i, 2) = image(i, j, 2);
                }
            }
            cout << "Enter new photo name (.jpg or other format): ";
            string output_photo;
            cin >> output_photo;

            // Save the rotated image
            if (!rotated.saveImage(output_photo))
            {
                cout << "Failed to save image." << endl;
            }
            else
            {
                cout << "Image saved successfully." << endl;
                system(output_photo.c_str()); // Show photo after processing
            }

            break;
        }
        else
        {
            cout << "Invalid degree. Please enter 90, 180, or 270." << endl;
            continue;
        }
    }
}

int main()
{
    Rotate_Image();
    return 0;
}
