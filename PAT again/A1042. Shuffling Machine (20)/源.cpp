/*
�ؼ����������ʱ���Ƚ�start[i]-- ��Ȼ�������ȷ���Ƶ���ĸ���
��Ϊ����1 �������������ʱ��Ҫ��1�ӻ���
*/
#include<iostream>
using namespace std;
const int N = 54;
char mp[5] = { 'S','H','C','D','J' };
int start[N], End[N];
int f[N];
int main() {
	int k;
	cin >> k;
	for (int i = 1; i <= N; i++) {
		start[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> f[i];
	}
	while (k) {
		for (int i = 1; i <= N; i++) {
			End[f[i]] = start[i];
		}
		for (int i = 1; i <= N; i++) {
			start[i] = End[i];
		}
		k--;
	}
	for (int i = 1; i <= N; i++) {
		start[i]--;
		printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);
		if (i < N)
			printf(" ");
	}
	return 0;
}