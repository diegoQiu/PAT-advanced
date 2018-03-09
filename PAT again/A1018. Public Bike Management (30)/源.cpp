#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 505;
const int INF = 1000000000;
int Sp, Cmax, N, M, w[maxn], G[maxn][maxn];
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
vector<int> tempPath, path;

void dijkstra(int s) {
	fill(d, d + maxn, INF);//²Ù
	d[s] = 0;
	for (int i = 0; i <= N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j <= N; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v <= N; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u]+G[u][v]<d[v]) {
					pre[v].clear();
					pre[v].push_back(u);
					d[v] = d[u] + G[u][v];
				}
				else if (d[v] == d[u] + G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int minNeed=INF;
int minRemain=INF;
void dfs(int v) {
	if (v == 0) {
		tempPath.push_back(v);
		int take = 0;
		int back = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
			if (w[id] > 0) {
				back += w[id];
			}
			else {
				if (back > abs(w[id])) {
					back -= abs(w[id]);
				}
				else {
					take+= abs(w[id]) - back;
					back = 0;
				}
			}
		}
		if (take < minNeed) {
			minNeed = take;
			path = tempPath;
			minRemain = back;
		}
		else if (take == minNeed && minRemain > back) {
			minRemain = back;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}
int main() {
	cin >> Cmax >> N >> Sp >> M;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &w[i]);
		w[i] -= Cmax / 2;
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		scanf("%d", &G[a][b]);
		G[b][a] = G[a][b];
	}
	dijkstra(0);
	dfs(Sp);
	cout << minNeed<<" ";
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i > 0)
			printf("->");
	}
	cout << " " << minRemain << endl;
	return 0;
}