#include <iostream>
#include <string>
using namespace std;
bool whattype(string s) {
	if (s[0] != 'R') return false;
	bool isC = false;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'C') isC = true;
	}
	if (isC == true && s[1] >= '0' && s[1] <= '9') return true;
	return false;
}
void redo1(string s) {
	int licz1 = 0, licz2 = 0;
	bool c = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C') c = true;
		if (s[i] >= '0' && s[i] <= '9') {
			if (c == false) {
				licz1 *= 10;
				licz1 += s[i] - '0';
			}
			else {
				licz2 *= 10;
				licz2 += s[i] - '0';
			}
		}
	}
	string ss;
	while (licz2) {
		ss = char((licz2 - 1) % 26 + 'A') + ss;
		licz2 = (licz2 - 1) / 26;

	}
	cout << ss << licz1 << endl;
}
void redo2(string s) {
	int licz1 = 0, licz2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			licz1 *= 26;
			licz1 += s[i] - 'A' + 1;
		}
		if (s[i] >= '0' && s[i] <= '9') {
			licz2 *= 10;
			licz2 += s[i] - '0';
		}
	}
	cout << 'R' << licz2 << 'C' << licz1 << endl;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (whattype(s)) redo1(s);
		else redo2(s);
	}
}