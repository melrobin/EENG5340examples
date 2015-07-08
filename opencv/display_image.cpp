#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    cout << "The matrix is "<<image.rows << " by " << image.cols << endl;
    int average;
    double X[image.rows*image.cols];
    for (int i=00;i<image.rows;i++)
      for (int j=00;j<image.cols;j++)
       {
           Vec3b intensity = image.at<Vec3b>(i,j);
            uchar blue = intensity.val[0];
            uchar green = intensity.val[1];
            uchar red = intensity.val[2];
            //average=int((blue+green+red)/3);
            image.at<Vec3b>(i,j).val[0]=uchar(double((2*image.at<Vec3b>(i,j))%255));
            image.at<Vec3b>(i,j).val[1]=uchar(double((2*image.at<Vec3b>(i,j))%255));;
            image.at<Vec3b>(i,j).val[2]=uchar(double((2*image.at<Vec3b>(i,j))%255));
          //  X[i+image.rows*j]=double(average);
     }
    namedWindow("Altered Image",WINDOW_AUTOSIZE);// Create a window for display.
    imshow("Altered Image",image);    // Show our image inside it.
    waitKey(0);   // Wait for a keystroke in the window
//     ofstream outfile("image_data.txt");
//     for (int i=0;i<image.rows*image.cols;i++)
//        outfile<< X[i] << endl;
//     outfile.close();
    return 0;
}
