#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
#include<iomanip>

using namespace std;
const double eps = 1e-4;
struct point {
	double x, y;
};
double od(point a, point b) {
	double wyn = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	return sqrt(wyn);
}
double kont(double a, double b, double c) {
	return acos((b*b + c * c - a * a) / (2 * b*c));
}
double gcd(double x, double y) {
	while (fabs(x) > eps && fabs(y) > eps) {
		if (x > y)
			x -= floor(x / y)*y;
		else
			y -= floor(y / x)*x;

	}
	return x + y;
}
int main() {
	point aa, bb, cc;
	cin >> aa.x >> aa.y >> bb.x >> bb.y >> cc.x >> cc.y;
	double a, b, c;
	a = od(aa, bb);
	b = od(bb, cc);
	c = od(cc, aa);
	double p = (a + b + c) / 2;
	double pol = sqrt(p*(p - a)*(p - b)*(p - c));
	double R = (a*b*c) / (4 * pol);
	double A = kont(a, b, c);
	double B = kont(b, a, c);
	double C = kont(c, a, b);
	double N = M_PI / gcd(gcd(A, B), C);
	cout << fixed;
	cout << setprecision(6);
	//cout << N << endl;
	cout << N / 2 * R*R*sin(2 * M_PI / N);

}
