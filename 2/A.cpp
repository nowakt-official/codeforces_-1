#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define MaxN 1010
struct punkty
{
	int x, y;
};
struct dane {
	string s;
	int a;
};
map<string, punkty> m;
map < string, int> mm;
int main() {
	int n;
	cin >> n;
	int actmax = 0;
	vector<string> max;
	dane data[MaxN];
	for (int i = 0; i < n; i++) {
		string s;
		int points;
		cin >> s >> points;
		data[i].s = s;
		data[i].a = points;
		m[s].x += points;
		m[s].y = i;
	}
	for (int i = 0; i < n; i++) {
		if (m[data[i].s].x > actmax) {
			actmax = m[data[i].s].x;
		}
	}
	vector<string> vv;
	for (int i = 0; i < n; i++) {
		string s = data[i].s;
		mm[s] += data[i].a;
		if (mm[s] >= actmax) {
			vv.push_back(s);
		}
	}
	//cout << actmax << endl;
	for (int i = 0; i < vv.size(); i++) {
		if (m[vv[i]].x == actmax) {
			cout << vv[i];
			return 0;
		}
	}
}