#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 1005;
const int INF = 1000000000;
int N, M, K;
int block;
bool vis[maxn];
int st;
vector<int> pre[maxn];
int father[maxn];
int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void init() {
	for (int i = 1; i < maxn; i++) {
		vis[i] = false;
		father[i] = i;
	}
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pre[a].push_back(b);
		pre[b].push_back(a);
	}
	for (int i = 1; i <= K; i++) {
		init();
		scanf("%d", &st);
		block = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < pre[j].size(); k++) {
				int u = pre[j][k];
				if (j == st || u == st)
					continue;
				Union(j, u);
			}
		}
		for (int j = 1; j <= N; j++) {
			if (j == st)
				continue;
			int root = findFather(j);
			if (vis[j] == false) {
				block++;
				vis[j] = true;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}