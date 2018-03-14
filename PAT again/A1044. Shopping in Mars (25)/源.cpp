#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];
int sum[maxn];
int N, M;

int upper_bound(int L, int R, int x) {
	int left = L, right = R, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (sum[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	cin >> N >> M;
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		sum[i] += a[i];
	}
	int nearS=1000000000;
	for (int i = 1; i <= N; i++) {
		int j = upper_bound(i, N + 1, sum[i - 1] + M);
		if (sum[j - 1] - sum[i - 1] == M) {
			nearS = M;
			break;
		} else if (j <= N && sum[j] - sum[i - 1] < nearS) {
			nearS = sum[j] - sum[i - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		int j = upper_bound(i, N + 1, sum[i - 1] + nearS);
		if (sum[j - 1] - sum[i - 1] == nearS) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}