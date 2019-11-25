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
		//previous = current; // 이전에 받았던 사각형은 previous로
		current = rot.boundingRect(); // 지금 받은 사각형

		cout << i << " : " << current.area() << endl;
		
		if (max.area() < current.area()) { // 새로 받아온 사각형의 크기가 최대 사각형의 크기보다 크다면
			max = current; // max 갱신
			result = i; // max일 때 i의 값도 갱신
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