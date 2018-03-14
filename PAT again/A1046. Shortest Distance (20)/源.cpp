#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int disToOne[maxn];
int N,M;
int main() {
	cin >> N;
	int sum = 0;
	for (int i = 1; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		disToOne[i + 1] = temp + disToOne[i];
		sum += temp;
	}
	int temp;
	scanf("%d", &temp);
	sum += temp;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", min(abs(disToOne[b] - disToOne[a]), (sum - abs(disToOne[b] - disToOne[a]))));
	}
	return 0;
}