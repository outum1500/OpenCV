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

	for (int j = 0; j < resized.rows; j++) {      // ��� �迭�� ��� �ִ���
		for (int i = 0; i < resized.cols; i++) {
			cbright = resized.at<uchar>(j, i)++;

			bright[cbright]++;
		}
	}

	for (int i = 0; i < 255; i++) { // ���� ���� ȭ�Ұ� �ִ� ��Ⱑ ������ ���ϴ� �ݺ���
		cbright = bright[i];
		if (max < cbright) {
			max = cbright;
			maxbright = i;
		}
	}
	
	cout << maxbright << endl; // ���� ���� ȭ�Ұ� �ִ� ��� ���

	/*
	for (int j = 0; j < resized.rows; j++) {    // �������� ������ ã�� ��Ⱚ�� ����
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