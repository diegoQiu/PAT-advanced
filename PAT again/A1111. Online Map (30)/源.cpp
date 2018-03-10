#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 505;
const int INF = 1000000000;

int N, M, G[maxn][maxn], d[maxn], T[maxn][maxn], w[maxn];
bool vis[maxn];
vector<int > pre1[maxn],pre2[maxn];
vector<int > path1, path2,tempPath;
int st, ed;

void dijkstra(int s) {
	memset(vis, false, sizeof(vis));
	fill(d, d + maxn, INF);
	fill(w, w + maxn, INF);
	d[s] = 0;
	w[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v < N; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					pre1[v].clear();
					pre1[v].push_back(u);
				}
				else if (d[v] == d[u] + G[u][v]) {
					pre1[v].push_back(u);
				}
			}
		}
	}
}

void dijkstra2(int s) {
	memset(vis, false, sizeof(vis));
	fill(w, w + maxn, INF);
	d[s] = 0;
	w[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && w[j] < MIN) {
				MIN = w[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v < N; v++) {
			if (vis[v] == false && T[u][v] != INF) {
				if (w[v] > w[u] + T[u][v]) {
					w[v] = w[u] + T[u][v];
					pre2[v].clear();
					pre2[v].push_back(u);
				}
				else if (w[v] == w[u] + T[u][v]) {
					pre2[v].push_back(u);
				}
			}
		}
	}
}

int minTime = INF;
void dfs(int v) {
	if (v == st){
		tempPath.push_back(v);
		int tempTime = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int u = tempPath[i], v = tempPath[i - 1];
			tempTime += T[u][v];
		}
		if (tempTime < minTime) {
			minTime = tempTime;
			path1 = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre1[v].size(); i++) {
		dfs(pre1[v][i]);
	}
	tempPath.pop_back();
}

int minNode = INF;
void dfs2(int v) {
	if (v == st) {
		tempPath.push_back(v);
		int node = tempPath.size();
		if (node < minNode) {
			minNode = node;
			path2 = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre2[v].size(); i++) {
		dfs2(pre2[v][i]);
	}
	tempPath.pop_back();
}

void print(vector<int > path) {
	for (int i = path.size() - 1;i>=0; i--) {
		printf("%d", path[i]);
		if (i > 0)
			printf(" -> ");
	}
}
int main() {
	cin >> N >> M;
	fill(G[0], G[0] + maxn * maxn, INF);
	fill(T[0], T[0] + maxn * maxn, INF);
	for (int i = 0; i < M; i++) {
		int a, b, s, len, t;
		scanf("%d %d %d %d %d", &a, &b, &s, &len, &t);
		if (s == 1) {
			G[a][b] = len;
			T[a][b] = t;
		}
		else {
			G[b][a] = len;
			G[a][b] = len;
			T[a][b] = t;
			T[b][a] = t;
		}
	}
	cin >> st >> ed;
	dijkstra(st);
	dfs(ed);
	dijkstra2(st);
	dfs2(ed);
	if (path1 == path2) {
		cout << "Distance = " << d[ed] << "; Time = " << w[ed] << ": ";
		print(path1);
	}
	else {
		cout << "Distance = " << d[ed] << ": ";
		print(path1);
		cout << endl;
		cout << "Time = " << w[ed] << ": ";
		print(path2);
	}
	return 0;
}