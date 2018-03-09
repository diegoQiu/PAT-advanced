#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100050;
int a[maxn];
int pos[maxn];
int main() {
	int N;
	cin >> N;
	int temp;
	int left = N - 1;
	int num = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		pos[temp] = i;
		if (temp == i && temp != 0) {
			left--;
		}
	}
	int k = 1;
	while (left > 0) {
		if (pos[0] == 0) {
			while (k < N) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);
					num++;
					break;
				}
				k++;
			}
		}
		while(pos[0]!=0){
			swap(pos[0], pos[pos[0]]);
			num++;
			left--;
		}
	}
	
	printf("%d\n", num);
	return 0;
}