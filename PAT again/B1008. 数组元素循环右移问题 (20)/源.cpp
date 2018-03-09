#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	vector <int> a;
	scanf("%d %d", &n, &m);
	if (m >= n) {
		m %= n;
	}
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}
	reverse(a.begin(), a.begin() + n - m);
	reverse(a.begin() + n - m, a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i < n - 1)
			printf(" ");
	}
	return 0;
}