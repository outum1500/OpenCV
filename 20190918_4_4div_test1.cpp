#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main() {

	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cerr << "camera open failed" << endl;
		return 0;
	}

	Mat frame;
	cap >> frame; // �ʱ� ������ ũ�� ����!!

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	double fps = cap.get(CAP_PROP_FPS);

	VideoWriter outputVideo1("output1.avi", fourcc, fps, Size(frame.cols / 2, frame.rows / 2));
	VideoWriter outputVideo2("output2.avi", fourcc, fps, Size(frame.cols / 2, frame.rows / 2));
	VideoWriter outputVideo3("output3.avi", fourcc, fps, Size(frame.cols / 2, frame.rows / 2));
	VideoWriter outputVideo4("output4.avi", fourcc, fps, Size(frame.cols / 2, frame.rows / 2));

	while (true) {

		cap >> frame;
		Mat m1 = frame(Range(0, frame.rows / 2), Range(0, frame.cols / 2)); // ���� ���
		Mat m2 = frame(Range(frame.rows / 2, frame.rows), Range(0, frame.cols / 2)); // ���� �ϴ�
		Mat m3 = frame(Range(0, frame.rows / 2), Range(frame.cols / 2, frame.cols)); // ���� ���
		Mat m4 = frame(Range(frame.rows / 2, frame.rows), Range(frame.cols / 2, frame.cols)); // ���� �ϴ�


		if (frame.empty()) {
			break;
		}
		outputVideo1 << m1; // ����
		outputVideo2 << m2;
		outputVideo3 << m3;
		outputVideo4 << m4;

		imshow("frame", frame); // �������ؼ� �ٷ� ����
		imshow("roi", m1);
		imshow("roi2", m2);
		imshow("roi3", m3);
		imshow("roi4", m4);



		if (waitKey(10) == 27) { //ESC key
			break;
		}
	}
	destroyAllWindows();

	return 0;
}