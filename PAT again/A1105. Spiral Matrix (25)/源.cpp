#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
int G[10010][10010];
int ans[10005]; 

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> N;
	int n, m;
	 m = (int)ceil(sqrt(1.0*N));
	while (N%m != 0) {
		m++;
	}
	n = N / m;
	for (int i = 0; i < N; i++) {
		cin >> ans[i];
	}
	if (N == 1) {
		printf("%d", ans[0]);
		return 0;
	}
	sort(ans, ans + N, cmp);
	int left = 1, right = n, up = 1, down = m;
	int i = 1,j = 1, now = 0;
	while (now < N) {
		while (now < N&&j < right) {
			G[i][j] = ans[now++];
			j++;
		}
		while (now < N&&i < down) {
			G[i][j] = ans[now++];
			i++;
		}
		while (now<N&&j>left) {
			G[i][j] = ans[now++];
			j--;
		}
		while (now<N&&i>up) {
			G[i][j] = ans[now++];
			i--;
		}
		up++;
		down--;
		left++;
		right--;
		i++;
		j++;
		if (now == N - 1) {
			G[i][j] = ans[now++];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", G[i][j]);
			if (j < n)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}