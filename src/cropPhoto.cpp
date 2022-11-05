#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat img;
Point pt1, pt2;

void fonksiyon(int event, int x, int y, int flags, void* userdata) {

	if (event == EVENT_LBUTTONDOWN) {//sol tus basildiginda
		pt1.x = x;
		pt1.y = y;
	}
	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) {//basili sekilde suruklendiginde
		pt2.x = x;
		pt2.y = y;

		Mat gecici = Mat::zeros(img.size(), CV_8UC3);
		rectangle(gecici, Point(pt1.x, pt1.y), Point(pt2.x, pt2.y), Scalar(0, 255, 0), 4, 8, 0);
		gecici = gecici + img;
		imshow("Kýrp", gecici);
	}
	if (event == EVENT_LBUTTONUP) {//sol tus býrakýldýðýnda
		Rect crop;
		crop.x = pt1.x;
		crop.y = pt1.y;

		crop.width = pt2.x - pt1.x;
		crop.height = pt2.y - pt1.y;

		Mat sonResim = img(crop);
		imshow("Orjinal", sonResim);
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