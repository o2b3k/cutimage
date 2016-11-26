#include <iostream>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

/*
 *  Bismillahir Rohmanir Rohiym
 */

int main(){
    /* Rasmni path ni kiritamiz */
    Mat img = imread("/home/o2b3k/Documents/tutorial/image1.jpg"); // Открытие файла

    // Отобразить на изображении белую пунктирную сетку
    for( int i = 0; i < img.rows; i++ )
        for( int j = 0; j < img.cols; j++ )
            if ( ( i % 20 == 10 && j % 2 == 1 ) ||
                 ( j % 50 == 25 && i % 2 == 1 ) )
            {
                img.at<Vec3b>(i,j)[0]= 255;
                img.at<Vec3b>(i,j)[1]= 255;
                img.at<Vec3b>(i,j)[2]= 255;
            }

    imwrite("image01_res.jpg", img);
    /* Rasmdan olinadigan obektni koordinatasini beramiz x,y,width,height */
    Rect r( 240, 20, 200, 250 ); // Создание региона

    Mat img2;
    // Копирование региона в отдельное изображение
    img( r ).copyTo( img2 );
    img2 += CV_RGB(0,0,255); // Добавляем синего к изображению

    /*Rasmdan qirqib lingan rasmni yarkostini kotaramiz */
    // Изменение части изображения
    img( r ) *= 0.5; // Понижение яркости
    /*Natijalarni chiqaramiz*/
    imwrite( "image01_res6.jpg", img2 );
    imwrite( "image01_res7.jpg", img );
    imshow("1",img);
    imshow("2",img2);
    waitKey(0);
    return 0;
};