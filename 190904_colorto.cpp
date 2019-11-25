#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat img, img2;
	Mat resized, result;
	int cbright = 0, max = 0, maxbright;
	int bright[256] = { 0, };

	img = imread("testimage.jpg");
	cvtColor(img, img2, COLOR_RGB2GRAY);
	resize(img2, resized, Size(500, 500));

	resized.copyTo(result);

	for (int j = 0; j < resized.rows; j++) {      // 밝기 배열에 몇개가 있는지
		for (int i = 0; i < resized.cols; i++) {
			cbright = resized.at<uchar>(j, i)++;

			bright[cbright]++;
		}
	}

	for (int i = 0; i < 255; i++) { // 가장 많은 화소가 있는 밝기가 얼마인지 구하는 반복문
		cbright = bright[i];
		if (max < cbright) {
			max = cbright;
			maxbright = i;
		}
	}
	
	cout << maxbright << endl; // 가장 많은 화소가 있는 밝기 출력

	/*
	for (int j = 0; j < resized.rows; j++) {    // 원본에서 위에서 찾은 밝기값을 빼기
		for (int i = 0; i < resized.cols; i++) {
			resized.at<uchar>(j, i) -= 10;			
		}
	}
	*/

	//imshow("testimage", result);
	//imshow("resized", resized);
	waitKey();
	system("pause");
	return 0;
}