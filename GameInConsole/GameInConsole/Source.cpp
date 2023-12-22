/*This code is made available under the Creative Commons Zero 1.0 License
(https://creativecommons.org/publicdomain/zero/1.0)*/

/*
    ASCII ART USING OPENCV WITH C++
    CREATED BY: sdam1n
*/

// Headers for OpenCV
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<Windows.h>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
using namespace cv;

int main()
{

    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 2;
    fontex.dwFontSize.X = 7;
    fontex.dwFontSize.Y = 7;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);

    string image_path = "..\\..\\..\\albanets-fotorobot-768x576.jpg";
    string ascii_chars = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    Mat img;
    img = imread(image_path);
    resize(img, img, Size(img.size().width / 6, img.size().height / 6));  // resize this according to monitor or terminal size

    vector<vector<int>> brightness_vector(img.rows); // for storing converted BGR values to brightness

    for (int r = 0; r < img.rows; ++r)
    {
        for (int c = 0; c < img.cols; ++c)
        {
            Vec3b pixel = img.at<Vec3b>(r, c);   // BGR value for a point
            int blue = pixel[0], green = pixel[1], red = pixel[2];
            int brightness = (blue + green + red) / 3;  // average method for converting BGR to brightness value
            brightness_vector[r].push_back(brightness);
        }
    }

    for (int i = 0; i < brightness_vector.size(); i++)
    {
        for (int j = 0; j < brightness_vector[i].size(); j++)
        {
            int ascii_index = ceil(brightness_vector[i][j] / 4); // mapping value to ascii_char string
            cout << ascii_chars[ascii_index];   // 3 times because pixels are square and terminal chars are rectangle
            cout << ascii_chars[ascii_index];
            cout << ascii_chars[ascii_index];

        }
        cout << endl;
    }

    return 0;

}