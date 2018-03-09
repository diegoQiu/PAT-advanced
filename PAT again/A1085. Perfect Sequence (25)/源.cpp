#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int a[maxn];
int n, p;

int main() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 1;
	int i = 0, j = 0;
	while (i < n&&j < n) {
		while (j < n&&a[j] <= (long long)a[i] * p) {
			ans = max(ans, j - i+1);
			j++;
		}
		i++;
	}
	printf("%d", ans);
	return 0;
}