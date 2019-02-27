#include <iostream>
#include <algorithm>
#include <vector>
#define MaxN 100010
using namespace std;

int main() {
	int n, v;
	cin >> n >> v;
	pair<double, pair<int, int>> p[n], makis;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i].first = (double)-b / a;
		p[i].second.first = -a;
		p[i].second.second = i + 1;
	}
	sort(p, p + n);
	int wyn = 0;
	int k = 0;
	int j = 0;
	bool yes = false;
	bool yesyes = false;
	vector<int> vv;
	while (j < v && k < n) {
		if (j == v - 1) {
			yes = true;

			if (p[k].second.first == -1) {
				wyn += (double)p[k].first*p[k].second.first;
				vv.push_back(p[k].second.second);
				j++;
				k++;
				yes = false;
				continue;
			}
			if (yesyes == false) {
				yesyes = true;
				makis.first = p[k].first;
				makis.second.first = p[k].second.first;
				makis.second.second = p[k].second.second;
			}
			k++;
			continue;
		}
		wyn += (double)p[k].first*p[k].second.first;
		j -= p[k].second.first;
		vv.push_back(p[k].second.second);
		k++;
	}
	while (yes && k < n && yesyes == false) {
		if (p[k].second.first == -2) {
			makis.first = p[k].first;
			makis.second.first = p[k].second.first;
			makis.second.second = p[k].second.second;
			yesyes = true;
			break;

		}
		k++;
	}

	if (yesyes == true && yes == true) {
		for (int i = vv.size() - 1; i >= 0; i--) {
			if (p[i].second.first == -1 && (double)p[i].first*p[i].second.first < (double)makis.first*makis.second.first) {
				vv[i] = makis.second.second;
				wyn += (makis.first*makis.second.first) - (p[i].first*p[i].second.first);
				break;
			}
		}
	}
	cout << wyn << endl;
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i] << " ";
	}
}