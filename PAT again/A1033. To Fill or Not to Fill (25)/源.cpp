#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 505;
const int INF = 1000000000;
struct Station {
	double d;
	double p;
}st[maxn];
bool cmp(Station a, Station b) {
	return a.d < b.d;
}
int main() {
	double  Cmax, D, Davg;
	int N;
	cin >> Cmax >> D >> Davg >> N;
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &st[i].p, &st[i].d);
	}
	sort(st, st + N, cmp);
	st[N].p = 0;
	st[N].d = D;
	if (st[0].d != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double maxDis = Davg * Cmax;
	int now = 0;
	double ans = 0.0, nowTank = 0;
	while (now < N) {
		int k = -1;
		double priceMin = INF;
		for (int i = now + 1; i <= N && st[i].d - st[now].d <= maxDis; i++) {
			if (st[i].p < priceMin) {
				priceMin = st[i].p;
				k = i;
				if (priceMin < st[now].p)
					break;
			}
		}
		if (k == -1)
			break;
		double need = (st[k].d - st[now].d) / Davg;
		if (priceMin < st[now].p) {
			if (nowTank < need) {
				ans += (need - nowTank)*st[now].p;
				nowTank = 0;
			} else
				nowTank -= need;
		} else {
			ans += (Cmax - nowTank)*st[now].p;
			nowTank = Cmax - need;
		}
		now = k;
	}
	if (now == N)
		printf("%.2f\n", ans);
	else
		printf("The maximum travel distance = %.2f\n",
			st[now].d + maxDis);
	return 0;
}