#include<iostream>
#include<algorithm>
using namespace std;
int numOf1(int x) {
	int ans = 0;
	while (x != 0) {
		if (x % 10 == 1)
			ans++;
		x /= 10;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += numOf1(i);
	}
	printf("%d\n", ans);
	return 0;
}