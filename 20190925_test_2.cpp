#include "opencv2\opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img = imread("apple.jpg");
Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*);
void rgbprint(int x, int y, Mat image);

int main() {
	namedWindow("image");
	imshow("image", img);

	setMouseCallback("image", on_mouse); // ���콺 Ŭ���ϸ� �Լ� ȣ��

	waitKey();
	system("pause");
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) { // ���콺 Ŭ�������� �Ҹ�
	switch (event) {
	case EVENT_LBUTTONDOWN: // ��Ŭ�� �ϸ�
		ptOld = Point(x, y);
		cout << "Ŭ���� ��ǥ : " << x << ", " << y << endl; // ��ǥ ���
		rgbprint(x, y, img); // ����� ȭ�� �̹��� ����ִ� �Լ� ȣ��
		break;
	default:
		break;
	}
}

void rgbprint(int x, int y, Mat image) { // ���� Ŭ�� �ϸ� ȣ���
	int r, g, b;
	Mat result(img.rows, img.cols, CV_8UC1);

	r = img.at<Vec3b>(y, x)[2]; // ���� ä�κ��� ȭ�� ����
	g = img.at<Vec3b>(y, x)[1];
	b = img.at<Vec3b>(y, x)[0];
	cout << "R : "<< r << "    G : " << g << "    B : " << b << endl; // ���


	for (int i = 0; i < img.rows; i++) { // +- 10�� �κ� ���������� ���
		for (int j = 0; j < img.cols; j++) {
			if (img.at<Vec3b>(i, j)[2] >= r - 10 && img.at<Vec3b>(i, j)[2] <= r + 10 &&
				img.at<Vec3b>(i, j)[1] >= g - 10 && img.at<Vec3b>(i, j)[1] <= g + 10 &&
				img.at<Vec3b>(i, j)[0] >= b - 10 && img.at<Vec3b>(i, j)[0] <= b + 10) {
				result.at<uchar>(i, j) = saturate_cast<uchar>(0);
			}
			else
				result.at<uchar>(i, j) = saturate_cast<uchar>(255);
		}
	}

	imshow("result", result);
}