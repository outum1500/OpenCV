#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	int row = 2;
	int col = 3;
	Mat m1(row, col, CV_8UC1);
	Mat m2;
	cout << m1 << endl << endl;
	
	m2 = m1.t(); // 90�� ȸ��*
	m2.resize(m1.cols + 2, 100);

	m2 = m2.t(); // 180�� ȸ��
	m2 = m2.t(); // 270�� ȸ��
	m2 = m2.t(); // 360�� ȸ��

	cout << m2 << endl << endl;
	
	system("pause");
}