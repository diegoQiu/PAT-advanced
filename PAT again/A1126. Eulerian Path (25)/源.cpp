#include<iostream>
#include<vector>
using namespace std;
const int maxn = 505;
int N, M;
int degree[maxn];
bool vis[maxn];
vector<int> pre[maxn];

int num = 0;
void dfs(int s) {
	num++;
	vis[s] = true;
	for (int i = 0; i < pre[s].size(); i++) {
		if (vis[pre[s][i]] == false) {
			dfs(pre[s][i]);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		degree[a]++;
		pre[a].push_back(b);
		degree[b]++;
		pre[b].push_back(a);
	}
	bool flag = true;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		printf("%d", degree[i]);
		if (degree[i] % 2 != 0) {
			cnt++;
			flag = false;
		}
		if (i < N)
			printf(" ");
		else
			printf("\n");
	}
	dfs(1);
	if (flag&&num==N)
		printf("Eulerian\n");
	else if (cnt == 2 && num == N) {
		printf("Semi-Eulerian");
	}
	else {
		printf("Non-Eulerian");
	}
	return 0;
}