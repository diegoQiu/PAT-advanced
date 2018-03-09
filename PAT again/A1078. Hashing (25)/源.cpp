#include<iostream>	
#include<cmath>
const int maxn = 1000100;
bool p[maxn] = { true };
int prime[maxn], num = 0;
int n, msize;
int hashtable[10001] = { false };
bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = (int)(sqrt(1.0*n));
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int main() {
	scanf("%d %d", &msize, &n);
	while (!isPrime(msize)) {
		msize++;
	}
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		int pos = (temp) % msize;
		if (hashtable[pos] == false) {
			hashtable[pos] = true;
			if (i == 0)
				printf("%d", pos);
			else
				printf(" %d", pos);
		} else {
			int step;
			for (step = 1; step < msize; step++) {
				pos = (temp + step * step) % msize;
				if (hashtable[pos] == false) {
					hashtable[pos] = true;
					if (i == 0)
						printf("%d", pos);
					else
						printf(" %d", pos);
					break;
				}
			}
			if (step >= msize) {
				if (i > 0)
					printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}