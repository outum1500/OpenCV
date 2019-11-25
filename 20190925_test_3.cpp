#include "opencv2\opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

TickMeter tm;
Mat different;
int chances = 10;
Mat img;
Mat img2;

void on_mouse(int event, int x, int y, int flags, void *);

int main() {

	img = imread("test3img.jpg");
	img2 = imread("test3img2.jpg");
	double lefttime = 0;
	different = Mat(img.rows, img.cols, CV_8UC1);


	imshow("img", img);
	imshow("img2", img2);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			Scalar tmp = img.at<Vec3b>(i, j);
			Scalar tmp2 = img2.at<Vec3b>(i, j);
			int flag = 0;
			for (int k = 0; k < 3; k++) {

				if (tmp[k] != tmp2[k]) {
					//cout << tmp[k] << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				different.at<uchar>(i, j) = 0; // 검정색
			}
			else if (flag == 0) {
				different.at<uchar>(i, j) = 255; // 흰색
			}
			flag = 0;
		}
	}

	imshow("different", different);

	setMouseCallback("img2", on_mouse);


	while (true) {

		Mat tmp = img.clone();

		tm.start();
		waitKey(33);
		tm.stop();

		lefttime = (60-tm.getTimeSec());

		Size textsize = getTextSize(to_string(lefttime), 3, 1, 1, 0);
		int textX = (tmp.cols - textsize.width) / 2;
		int textY = (tmp.rows - textsize.height) / 2;
		rectangle(tmp, Point(textX, 0), Point(textX+ textsize.width, textsize.height+ textsize.height), Scalar(0,0,0),-1);

		putText(tmp, to_string(lefttime), Point(textX, textsize.height), 3, 1, Scalar::all(255), 1, 8, false);

		imshow("original", tmp);

		if ((lefttime <= 0) || !(chances)) {
		//	cout << "END" << endl;

			tm.reset();
			chances = 10;

		}

		//cout << lefttime << endl;
	}
	
	system("pause");
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {

	if (event == EVENT_LBUTTONDOWN) {

		if (!(different.at<uchar>(x, y))) {
			//동그라미
			circle(img2, Point(x, y), 10, Scalar(255, 0, 0), 3, LINE_AA);
			cout << "yes!" << endl;
			imshow("img2", img2);
		}
		else {
			chances-- ;
			cout << "no!" << endl;
		}


	}

}