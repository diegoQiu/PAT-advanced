#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 1001;
int K, N, queen[maxn];


bool isSolution() {
	bool flag = true;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (queen[i] == queen[j] || abs(i - j) == abs(queen[i] - queen[j])) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &queen[j]);
		}
		if (isSolution()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}