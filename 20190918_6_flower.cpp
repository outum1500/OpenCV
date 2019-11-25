#include "opencv2\opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Size textsize = getTextSize("Hello, OpenCV", 3, 1, 1, 0);
	Mat img(600, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(196, 230, 10, 220), Scalar(0, 0, 255), -1);

	ellipse(img, Point(260, 130), Size(75, 20), -30, 0, 360, Scalar(255, 255, 0), -1);
	ellipse(img, Point(200, 90), Size(75, 20), -90, 0, 360, Scalar(255, 255, 0), -1);
	ellipse(img, Point(140, 130), Size(75, 20), -150, 0, 360, Scalar(255, 255, 0), -1);
	ellipse(img, Point(140, 190), Size(75, 20), -210, 0, 360, Scalar(255, 255, 0), -1);
	ellipse(img, Point(200, 230), Size(75, 20), -270, 0, 360, Scalar(255, 255, 0), -1);
	ellipse(img, Point(260, 190), Size(75, 20), -330, 0, 360, Scalar(255, 255, 0), -1);

	ellipse(img, Point(247, 400), Size(80, 15), -50, 0, 360, Scalar(255, 255, 0), -1);
	ellipse(img, Point(153, 400), Size(80, 15), -130, 0, 360, Scalar(255, 255, 0), -1);

	

	circle(img, Point(200, 160), 15, Scalar(255, 0, 0), -1, LINE_AA);
	circle(img, Point(200, 160), 27, Scalar(255, 0, 0), 13, LINE_AA);

	int textY = (img.rows - textsize.height) / 2;
	int textX = (img.cols - textsize.width) / 2;

	putText(img, "Hello, OpenCV", Point(textX, textY), 3, 1, Scalar::all(0), 1, 8, false);

	imshow("img", img);
	waitKey();
	system("pause");
}