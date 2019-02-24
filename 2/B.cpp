#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MaxN 1005
#define MaxM 1e9
int howt(int a, int m) {
	int licz = 0;
	while (a%m == 0 && a != 0) {
		a /= m;
		licz++;
	}
	return licz;
}
struct punkt {
	int a = MaxM, from;
};
struct kordy {
	int x, y;
};
int tab[MaxN][MaxN];
punkt t2[MaxN][MaxN];
punkt t5[MaxN][MaxN];
kordy zera;
void wypisz(punkt tab[MaxN][MaxN], int n) {
	printf("%d\n", tab[n][n]);
	int i = n;
	int j = n;
	vector<int> v;
	while (i != 1 || j != 1) {
		if (tab[i][j].from == 1) {
			v.push_back(1);
			j--;
		}
		else {
			i--;
			v.push_back(0);
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == 0) printf("D");
		else printf("R");
	}
}
int main() {
	int n;
	scanf("%d", &n);

	bool is0 = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tab[i][j]);
			if (tab[i][j] == 0) {
				is0 = true;
				zera.x = i;
				zera.y = j;
			}
			t2[i][j].a = howt(tab[i][j], 2);
			t5[i][j].a = howt(tab[i][j], 5);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (t2[i - 1][j].a >= t2[i][j - 1].a) {
				t2[i][j].a += t2[i][j - 1].a;
				t2[i][j].from = 1;
			}
			else {
				t2[i][j].a += t2[i - 1][j].a;
				t2[i][j].from = 0;
			}
			if (t5[i - 1][j].a >= t5[i][j - 1].a) {
				t5[i][j].a += t5[i][j - 1].a;
				t5[i][j].from = 1;
			}
			else {
				t5[i][j].a += t5[i - 1][j].a;
				t5[i][j].from = 0;
			}
		}
	}
	if (is0 && 1 <= min(t5[n][n].a, t2[n][n].a)) {
		printf("1\n");
		for (int i = 1; i < zera.x; i++) {
			printf("D");
		}
		for (int i = 1; i < zera.y; i++) {
			printf("R");
		}
		for (int i = 1; i <= n - zera.x; i++) {
			printf("D");
		}
		for (int i = 1; i <= n - zera.y; i++) {
			printf("R");
		}
		return 0;
	}
	if (t5[n][n].a >= t2[n][n].a) wypisz(t2, n);
	else wypisz(t5, n);

}