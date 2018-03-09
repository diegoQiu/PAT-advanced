#include<iostream>
using namespace std;
const int maxn = 1000010;
int prime[maxn], num = 0;
bool isPrime[maxn] = { false };
void find_Prime(int n) {
	for (int i = 2; i < maxn; i++) {
		if (isPrime[i] == false) {
			prime[num++] = i;
			if (num >= n)
				break;
			for (int j = 2 * i; j < maxn; j +=i) {
				isPrime[j] = true;
			}
		}
	}
}
int main() {
	int m, n, count = 0;
	cin >> m >> n;
	find_Prime(n);
	for (int i = m; i <= n; i++) {
		printf("%d", prime[i - 1]);
		count++;
		if (count % 10 != 0 && i < n)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}