#include<iostream>	
#include<cmath>
using namespace	std;
const int maxn = 10001;

bool hashtable[maxn];
bool isPrime(int n) {
	if (n <= 1)
		return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int Msize, N;
int main() {
	cin >> Msize >> N;
	while (!isPrime(Msize))Msize++;
	int num = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		int ans = temp % Msize;
		if (hashtable[ans] == false) {
			printf("%d", ans);
			num++;
			if (num < N)
				printf(" ");
			hashtable[ans] = true;
		} else {
			int step;
			for ( step = 1; step < Msize; step++) {
				ans = (ans + step * step) % Msize;
				if (hashtable[ans] == false) {
					hashtable[ans] = true;
					printf("%d", ans);
					num++;
					if (num < N)
						printf(" ");
					break;
				}
			}
			if (step >= Msize) {
				printf("-");
				num++;
				if (num < N)
					printf(" ");
			}
		}
	}
	return 0;
}

