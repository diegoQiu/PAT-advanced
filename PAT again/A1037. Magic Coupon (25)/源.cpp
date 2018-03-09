#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100050;
int c[maxn], p[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int nc, np;
	cin >> nc;
	for (int i = 0; i < nc; i++) {
		scanf("%d", &c[i]);
	}
	cin >> np;
	for (int i = 0; i < np; i++) {
		scanf("%d", &p[i]);
	}
	sort(c, c + nc,cmp);
	sort(p, p + np,cmp);
	long long ans = 0;
	for (int i = 0; i < nc&&i<np&&c[i]>0&&p[i]>0; i++) {
		ans += c[i] * p[i];
	}
	for (int i = nc - 1, j = np - 1; c[i] < 0 && p[j] < 0 && i >= 0 && j >= 0; i--, j--) {
		ans += c[i] * p[j];
	}
	printf("%ld", ans);
	return 0;
}