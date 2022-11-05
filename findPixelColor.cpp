#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat img;

void fonksiyon(int event, int x, int y, int flags, void* userdata) {

	if (event == EVENT_MOUSEMOVE) {
		int blue = img.at<Vec3b>(y, x)[0];
		int green = img.at<Vec3b>(y, x)[1];
		int red = img.at<Vec3b>(y, x)[2];

		cout << "Blue Value : " << blue << " ";
		cout << "Green Value : " << green << " ";
		cout << "Red Value : " << red << " ";
		cout << "Column : " << x << " Row : " << y << endl;

	}
	else if (event == EVENT_RBUTTONDOWN) { //sag tus
	}
	else if (event == EVENT_MBUTTONDOWN) { //orta tus
	}
	else if (event == EVENT_LBUTTONDOWN) {//sol tus
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