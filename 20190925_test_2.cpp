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

	setMouseCallback("image", on_mouse); // 마우스 클릭하면 함수 호출

	waitKey();
	system("pause");
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) { // 마우스 클릭했을때 불림
	switch (event) {
	case EVENT_LBUTTONDOWN: // 왼클릭 하면
		ptOld = Point(x, y);
		cout << "클릭한 좌표 : " << x << ", " << y << endl; // 좌표 출력
		rgbprint(x, y, img); // 비슷한 화소 이미지 띄워주는 함수 호출
		break;
	default:
		break;
	}
}

void rgbprint(int x, int y, Mat image) { // 왼쪽 클릭 하면 호출됨
	int r, g, b;
	Mat result(img.rows, img.cols, CV_8UC1);

	r = img.at<Vec3b>(y, x)[2]; // 각각 채널별로 화소 저장
	g = img.at<Vec3b>(y, x)[1];
	b = img.at<Vec3b>(y, x)[0];
	cout << "R : "<< r << "    G : " << g << "    B : " << b << endl; // 출력


	for (int i = 0; i < img.rows; i++) { // +- 10인 부분 검정색으로 출력
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