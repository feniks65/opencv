#include <opencv.h>

int main()
{

//First load your source image, here load as gray scale
cv::Mat srcImage = cv::imread("sourceImage.jpg", CV_LOAD_IMAGE_GRAYSCALE);

//Then define your mask image
cv::Mat mask = cv::Mat::zeros(srcImage.size(), srcImage.type());

//Define your destination image
cv::Mat dstImage = cv::Mat::zeros(srcImage.size(), srcImage.type());    

//I assume you want to draw the circle at the center of your image, with a radius of 50
cv::circle(mask, cv::Point(mask.rows/2, mask.cols/2), 50, cv::Scalar(255, 0, 0), -1, 8, 0);

//Now you can copy your source image to destination image with masking
srcImage.copyTo(dstImage, mask);

return 0;
}
