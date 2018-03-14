#include<iostream>
using namespace std;
const int maxn = 55;

char mp[5] = { 'S','H','C','D','J' };
int start[maxn], endd[maxn];
int f[maxn];
int main() {
	int k;
	cin >> k;
	for (int i = 1; i <= 54; i++) {
		start[i] = i;
	}
	for (int i = 1; i <= 54; i++) {
		cin >> f[i];
	}
	while (k--) {
		for (int i = 1; i < maxn; i++) {
			endd[f[i]] = start[i];
		}
		for (int i = 1; i < maxn; i++) {
			start[i] = endd[i];
		}
	}
	for (int i = 1; i < maxn; i++) {
		start[i]--;
		printf("%c %d", mp[start[i] / 13], start[i] % 13+1);
		if (i < maxn - 1)
			printf(" ");
	}
	return 0;
}