#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int test(Point2d pt1, Point2d pt2, Point2d pt3) {
	int x, y;
	int triangle = 2; // �а��� ��� 1, ������ ��� 0
	x = pt1.x;	y = pt1.y;
	
	pt1.x -= x; // pt1�� ��������
	pt1.y -= y;
	pt2.x -= x; // pt2�� pt1�� �̵���Ų��ŭ ���ֱ�
	pt2.y -= y;
	pt3.x -= x; // pt3�� pt1�� �̵���Ų��ŭ ���ֱ�
	pt3.y -= y;

	cout << pt2.ddot(pt3) << endl;
	if (pt2.ddot(pt3) > 0) { // ������ ���
		triangle = 0;
	}
	else if (pt2.ddot(pt3) < 0) { // �а��� ��� �ٷ� ����
		triangle = 1;
		cout << "�� �ﰢ���� �а��ﰢ�� �Դϴ�." << endl;
		return triangle;
	}


	
	x = pt2.x;	y = pt2.y;
	pt2.x -= x; // pt2�� ��������
	pt2.y -= y;
	pt3.x -= x; // pt3�� pt2�� �̵���Ų��ŭ ���ֱ�
	pt3.y -= y;
	pt1.x -= x; // pt1�� pt2�� �̵���Ų��ŭ ���ֱ�
	pt1.y -= y;

	cout << pt1.ddot(pt3) << endl;
	if (pt1.ddot(pt3) > 0) { // ������ ���
		triangle = 0;
	}
	else if (pt1.ddot(pt3) < 0) { // �а��� ��� �ٷ� ����
		triangle = 1;
		cout << "�� �ﰢ���� �а��ﰢ�� �Դϴ�." << endl;
		return triangle;
	}



	x = pt3.x;	y = pt3.y;
	pt3.x -= x; // pt3�� ��������
	pt3.y -= y;
	pt2.x -= x; // pt2�� pt3�� �̵���Ų��ŭ ���ֱ�
	pt2.y -= y;
	pt1.x -= x; // pt1�� pt3�� �̵���Ų��ŭ ���ֱ�
	pt1.y -= y;

	cout << pt1.ddot(pt2) << endl;
	if (pt1.ddot(pt2) > 0) { // ������ ���
		triangle = 0;
	}
	else if (pt1.ddot(pt2) < 0) { // �а��� ��� �ٷ� ����
		triangle = 1;
		cout << "�� �ﰢ���� �а��ﰢ�� �Դϴ�." << endl;
		return triangle;
	}


	if (triangle == 0) {
		cout << "�� �ﰢ���� �����ﰢ�� �Դϴ�." << endl;
	}
}

int main() {
	//Point2d pt5(100, 0), pt6(50, 50);
	//cout << "pt5 pt6 ���� = " << pt5.dot(pt6) << endl;
	Point2d pt1(0, 2), pt2(3, 1), pt3(2, 0);
	Point2d pt4(0, 1), pt5(1, 3), pt6(6, 3);


	test(pt1, pt2, pt3);
	cout << "" << endl;
	test(pt4, pt5, pt6);

	system("pause");
}