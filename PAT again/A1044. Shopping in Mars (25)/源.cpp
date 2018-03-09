#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];
int sum[maxn];

int bSearch(int left, int right,int m) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (sum[mid] > m) {
			right = mid;
		} else
			left = mid + 1;
	}
	return right;
}
int main() {
	int n, m;
	cin >> n >> m;
	a[0] = 0;
	sum[0] = 0;
	int near;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int j = bSearch(i, n + 1, sum[i - 1] + m);
		if (sum[j - 1] - sum[i - 1] == m) {
			near = m;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < near) {
			near
		}
	}
	return 0;
}