#include<iostream>
using namespace std;
int vis[10010];
int a[100010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		vis[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (vis[a[i]] == 1) {
			printf("%d", a[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}