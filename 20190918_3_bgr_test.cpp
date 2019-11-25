#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat m1 = imread("testimage.jpg", IMREAD_COLOR);
	Mat B(m1.rows, m1.cols, CV_8UC1);
	Mat G(m1.rows, m1.cols, CV_8UC1);
	Mat R(m1.rows, m1.cols, CV_8UC1);

	for (int i = 1; i < m1.rows; i++) {
		for (int j = 0; j < m1.cols; j++) {
			B.at<uchar>(i, j) = m1.at<Vec3b>(i, j)[0];
			G.at<uchar>(i, j) = m1.at<Vec3b>(i, j)[1];
			R.at<uchar>(i, j) = m1.at<Vec3b>(i, j)[2];
		}
	}

	imshow("origin", m1);
	imshow("B", B);
	imshow("G", G);
	imshow("R", R);

	waitKey();
	system("pause");
	return 0;
}