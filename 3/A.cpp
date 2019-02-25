#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	char c1, c2;
	int a1, a2;
	cin >> c1 >> a1;
	cin >> c2 >> a2;
	int b1 = c1 - 'a', b2 = c2 - 'a';
	cout << max(abs(a1 - a2), abs(b1 - b2)) << endl;
	while (a1 != a2 || b1 != b2) {
		if (b1 < b2) {
			b1++;
			cout << "R";
		}
		if (b1 > b2) {
			b1--;
			cout << "L";
		}
		if (a1 > a2) {
			a1--;
			cout << "D";
		}
		if (a1 < a2) {
			a1++;
			cout << "U";
		}
		cout << endl;
	}
}