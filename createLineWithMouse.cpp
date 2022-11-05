#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat img;
int sayac;
Point pt1, pt2;

void fonksiyon(int event, int x, int y, int flags, void* userdata) {

	if (event == EVENT_MOUSEMOVE) {
	}
	else if (event == EVENT_RBUTTONDOWN) { //sag tus
	}
	else if (event == EVENT_MBUTTONDOWN) { //orta tus
	}
	else if (event == EVENT_LBUTTONDOWN) {//sol tus
		sayac++;
		if (sayac == 1) {
			pt1.x = x;
			pt1.y = y;
		}
		else if (sayac == 2) {
			pt2.x = x;
			pt2.y = y;

			line(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);

			imshow("Pencere", img);

			sayac = 0;
		}
	}
}


int main()
{
	img = imread("img.jpg");
	namedWindow("Pencere", CV_WINDOW_AUTOSIZE);
	setMouseCallback("Pencere", fonksiyon, NULL);

	imshow("Pencere", img);

	waitKey(0);
	return 0;
}