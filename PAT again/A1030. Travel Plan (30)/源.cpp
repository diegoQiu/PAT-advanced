#include<iostream>	
#include<algorithm>
#include<cstring>	
using namespace std;

const int maxn = 505;
const int INF = 1000000000;
int N, M, st, ed;
int d[maxn], G[maxn][maxn],w[maxn], cost[maxn][maxn];
bool vis[maxn];
int pre[maxn];

void dijkstra(int s) {
	fill(d, d + maxn, INF);
	fill(w, w + maxn, INF);
	for (int i = 0; i < N; i++) {
		pre[i] = i;
	}
	d[s] = 0;
	w[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v < N; v++) {
			if (vis[v] == false && G[v][u] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + cost[u][v];
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v]) {
					if (w[v] > w[u] + cost[u][v]) {
						w[v] = w[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

void dfs(int v) {
	if (v == st) {
		printf("%d ", st);
		return;
	}
	dfs(pre[v]);
	printf("%d ", v);
}
int main() {
	cin >> N >> M >> st >> ed;
	fill(G[0], G[0] + maxn * maxn, INF);
	fill(cost[0], cost[0] + maxn * maxn, INF);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		scanf("%d %d", &G[a][b], &cost[a][b]);
		G[b][a] = G[a][b];
		cost[b][a] = cost[a][b];
	}
	dijkstra(st);
	dfs(ed);
	printf("%d %d\n", d[ed], w[ed]);
	return 0;
}