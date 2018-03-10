#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 202;
int n, m,k;
int G[maxn][maxn];
bool vis[maxn];

int main() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a][b] = G[b][a] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		memset(vis, false, sizeof(vis));
		bool flag = true;
		int num;
		int a[1001];
		scanf("%d", &num);
		if (num != n + 1) {
			flag = false;
		}
		for (int j = 0; j < num; j++) {
			scanf("%d", &a[j]);
			vis[a[j]] = true;
		}
		if (a[0] != a[num - 1]) {
			flag = false;
		}
		for (int j = 1; j <= num-1; j++) {
			if (G[a[j]][a[j -1]] == 0) {
				flag = false;
				break;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (vis[j] == false) {
				flag = false;
				break;
			}
		}
		if (flag)
			printf("YES\n");
		else {
			printf("NO\n");
		}
	}
	return 0;
}