#include<iostream>
#include<cmath>

using namespace std;
struct punkty {
	long double x, y, r;
};
long double srx, sry;
punkty t[3];
double rr[3];
double Ct(double sx, double sy) {
	double eps = 0;
	for (int i = 0; i < 3; i++) rr[i] = sqrt((sx - t[i].x)*(sx - t[i].x) + ((sy - t[i].y)*(sy - t[i].y))) / t[i].r;
	for (int i = 0; i < 3; i++) eps += (rr[i] - rr[(i + 1) % 3])*(rr[i] - rr[(i + 1) % 3]);
	return eps;
}
int main() {
	for (int i = 0; i < 3; i++) cin >> t[i].x >> t[i].y >> t[i].r;
	for (int i = 0; i < 3; i++) srx += (t[i].x / 3), sry += (t[i].y / 3);
	for (double s = 1; s > 1e-6;) {
		if (Ct(srx, sry) > Ct(srx + s, sry)) srx += s;
		else if (Ct(srx, sry) > Ct(srx - s, sry)) srx -= s;
		else if (Ct(srx, sry) > Ct(srx, sry + s)) sry += s;
		else if (Ct(srx, sry) > Ct(srx, sry - s)) sry -= s;
		else s *= 0.7;
	}
	if (Ct(srx, sry) < 1e-5) printf("%.5lf %.5lf\n", srx, sry);
	return 0;
}