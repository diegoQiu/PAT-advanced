#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	int a[101];
	cin >> n;
	int now = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > now) {
			ans += (a[i] - now) * 6;
		}
		else if (a[i] < now) {
			ans += (now - a[i]) * 4;
		}
		now = a[i];
	}
	printf("%d\n", ans + n * 5);
	return 0;
}