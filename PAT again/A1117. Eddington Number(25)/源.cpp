#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn], n;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a + n+1,cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > i) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}