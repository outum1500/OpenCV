#include "opencv2/opencv.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace cv;

int main() {
	Mat m1(1000, 1000, CV_8UC3);
	Rect roi(0, 0, 10, 10);
	int i, j;
	int rand1, rand2, rand3;

	for (i = 0; i < 1000; i += 10) {
		for (j = 0; j < 1000; j += 10) {
			rand1 = rand() % 256;
			rand2 = rand() % 256;
			rand3 = rand() % 256;
			Mat subimg = m1(Rect(i, j, 10, 10));
			subimg = Scalar(rand1, rand2, rand3);
		}
	}

	imshow("m1", m1);

	waitKey();
	system("pause");
	return 0;
}