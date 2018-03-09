#include<iostream>
using namespace std;
const int maxn = 2005;
struct Poly {
	int e;
	double a;
}poly[maxn];
double ans[maxn];
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %lf", &poly[i].e, &poly[i].a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		double y;
		scanf("%d %lf", &x, &y);
		for (int j = 0; j < n; j++) {
			ans[poly[j].e + x] += poly[j].a*y;
		}
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++) {
		if (ans[i] != 0.0)
			cnt++;
	}
	cout << cnt;
	for (int i = maxn; i >= 0; i--) {
		if (ans[i] != 0.0)
			printf(" %d %.1f", i, ans[i]);
	}
	return 0;
}