#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int ans[maxn];
int main() {
	int N, a, b;
	cin >> N;
	for (int i=0; i < N; i++) {
		scanf("%d", &ans[i]);
	}
	int sum1 = 0, sum2 = 0;
	if (N % 2 == 0)
		a = b = N / 2;
	else {
		a = N / 2;
		b = N - a;
	}
	sort(ans, ans + N);
	for (int i = 0; i < a; i++) {
		sum1 += ans[i];
	}
	for (int i = a; i < N; i++) {
		sum2 += ans[i];
	}
	printf("%d %d\n", b - a, sum2 - sum1);
	return 0;
}