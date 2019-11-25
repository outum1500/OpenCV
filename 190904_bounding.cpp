#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void bounding(Rect r1) {
	int i = 0;
	int result = 0;
	Rect current;
	Rect max;
	Point p = r1.tl() + r1.br() / 2;
	
	for (i = 1; i <= 360; i++) {
		RotatedRect rot(p, r1.size(), i);
		//previous = current; // ������ �޾Ҵ� �簢���� previous��
		current = rot.boundingRect(); // ���� ���� �簢��

		cout << i << " : " << current.area() << endl;
		
		if (max.area() < current.area()) { // ���� �޾ƿ� �簢���� ũ�Ⱑ �ִ� �簢���� ũ�⺸�� ũ�ٸ�
			max = current; // max ����
			result = i; // max�� �� i�� ���� ����
		}
	}


	cout << result << endl;
	cout << max.area() << endl;
	
}

int main() {
	Rect r1(0, 0, 10, 20);

	bounding(r1);

	system("pause");
}