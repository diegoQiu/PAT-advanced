#include<iostream>
#include<algorithm>
using namespace std;
int coin[100005];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + N);
	int a=0, b=N-1;
	while (a < b) {
		if (coin[a] + coin[b] == M) {
			printf("%d %d\n", coin[a], coin[b]);
			return 0;
		} else if (coin[a] + coin[b] < M)
			a++;
		else
			b--;
	}
	printf("No Solution\n");
	return 0;
}