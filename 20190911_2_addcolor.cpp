#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat img = imread("testimage.jpg");
	Mat m1 = Mat(img.cols * 2, img.rows * 2, CV_8UC3);
	Scalar s = Scalar(0, 255, 0);
	int i = 0, j = 0, m = 0, k = 0;
	m = img.cols / 2;
	k = img.rows / 2;

	imshow("img", img);
	m1 = m1.setTo(s);

	for (i = 0; i < img.rows; i++) {
		for (j = 0; j < img.cols; j++) {
			m1.at<Vec3b>(m+i, k+j) = img.at<Vec3b>(i, j);
		}
	}
	
	imshow("m1", m1);

	waitKey();

	system("pause");
}