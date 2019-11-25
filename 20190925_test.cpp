// 값은 잘 나오지 않지만 선생님이 맞다고 인정하셔서 이대로 제출합니당!!

#include "opencv2\opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void r_level_change(int pos, void* userdata);
void g_level_change(int pos, void* userdata);
void b_level_change(int pos, void* userdata);

Mat R;  
Mat G;  
Mat B;

int main() {
	Mat img = imread("apple.jpg");  // 이미지 불러오기
	R = img.clone();
	G = img.clone();
	B = img.clone();
	Mat redreal(img.rows, img.cols, CV_8UC1);
	

	namedWindow("image");
	imshow("image", img);

	namedWindow("result");
	createTrackbar("r", "result", 0, 255, r_level_change, (void*)&img);
	createTrackbar("g", "result", 0, 255, g_level_change, (void*)&img);
	createTrackbar("b", "result", 0, 255, b_level_change, (void*)&img);
	
	waitKey();
	system("pause");
	return 0;
}

void r_level_change(int pos, void* userdata) {  // red
	Mat img = *(Mat*)userdata;
	Mat temp(img.rows, img.cols, CV_8UC1);
	temp = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (img.at<Vec3b>(i, j)[2] <= pos + 10 && img.at<Vec3b>(i, j)[2] >= pos - 10){
				R.at<Vec3b>(i, j)[2] = 255;  // grayscale로
			}
			else
				R.at<Vec3b>(i, j)[2] = 0;
		}
	}

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (R.at<Vec3b>(i, j)[2] == 255 && G.at<Vec3b>(i, j)[1] == 255 && B.at<Vec3b>(i, j)[0] == 255) {
				temp.at<uchar>(i, j) = 0;
			}
			else
				temp.at<uchar>(i, j) = 255;
		}
	}
	imshow("result", temp);
}

void g_level_change(int pos, void* userdata) {  // green
	Mat img = *(Mat*)userdata;
	Mat temp(img.rows, img.cols, CV_8UC1);
	temp = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (img.at<Vec3b>(i, j)[1] <= pos + 10 && img.at<Vec3b>(i, j)[1] >= pos - 10) {
				G.at<Vec3b>(i, j)[1] = 255;  // grayscale로
			}
			else
				G.at<Vec3b>(i, j)[1] = 0;
		}
	}

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (R.at<Vec3b>(i, j)[2] == 255 && G.at<Vec3b>(i, j)[1] == 255 && B.at<Vec3b>(i, j)[0] == 255) {
				temp.at<uchar>(i, j) = 0;
			}
			else
				temp.at<uchar>(i, j) = 255;
		}
	}
	imshow("result", temp);
}

void b_level_change(int pos, void* userdata) {  // blue
	Mat img = *(Mat*)userdata;
	Mat temp(img.rows, img.cols, CV_8UC1);
	temp = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (img.at<Vec3b>(i, j)[0] <= pos + 10 && img.at<Vec3b>(i, j)[0] >= pos - 10) {
				B.at<Vec3b>(i, j)[0] = 255;  // grayscale로
			}
			else
				B.at<Vec3b>(i, j)[0] = 0;
		}
	}

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (R.at<Vec3b>(i, j)[2] == 255 && G.at<Vec3b>(i, j)[1] == 255 && B.at<Vec3b>(i, j)[0] == 255) {
				temp.at<uchar>(i, j) = 0;
			}
			else
				temp.at<uchar>(i, j) = 255;
		}
	}
	imshow("result", temp);
}