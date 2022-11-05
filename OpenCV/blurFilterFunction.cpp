#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

float filtre[7][7] = {
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
};

int filtreBoyutu = 7;

double toplam0, toplam1, toplam2;
double k, l;

Mat orgim, dst;

int main()
{
	orgim = imread("img.jpg");

	Mat filtreRes(orgim.rows, orgim.cols, CV_8UC3, Scalar(0, 0, 0));

	l = filtreBoyutu * filtreBoyutu;
	k = 1.0 / l;

	for (int y = 0;y < orgim.rows - filtreBoyutu;y++) {  //Orjinal resimin piksellerine eriþim
		for (int x = 0;x < orgim.cols - filtreBoyutu;x++) {
			for (int t = 0;t < filtreBoyutu;t++) {  //Filtrenin piksellerine eriþim
				for (int f = 0; f < filtreBoyutu; f++)
				{
					toplam0 = toplam0 + orgim.at<Vec3b>(y + t, x + f)[0] * filtre[t][f] * k;
					toplam1 = toplam1 + orgim.at<Vec3b>(y + t, x + f)[1] * filtre[t][f] * k;
					toplam2 = toplam2 + orgim.at<Vec3b>(y + t, x + f)[2] * filtre[t][f] * k;
				}
			}
			filtreRes.at<Vec3b>(y, x)[0] = toplam0;
			filtreRes.at<Vec3b>(y, x)[1] = toplam1;
			filtreRes.at<Vec3b>(y, x)[2] = toplam2;

			toplam0 = 0;
			toplam1 = 0;
			toplam2 = 0;
		}
	}

	blur(orgim, dst, Size(filtreBoyutu, filtreBoyutu)); //Hazir fonksiyon

	imshow("Resim", orgim);
	imshow("Hazýr Fonk", dst);
	imshow("Yapýlan Filtreleme", filtreRes);

	waitKey(0);
	return 0;
}