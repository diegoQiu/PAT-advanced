#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>	
#include<string>;
using namespace std;
const int maxn = 1020;
const int INF = 1000000000;
int N, M, K, Ds;
int G[maxn][maxn], d[maxn];
bool vis[maxn];
vector<int> pre[maxn];

int stringToNum(string str) {
	int i = 0;
	int ans = 0;
	while (i < str.length()) {
		if (str[i] != 'G')
			ans = ans * 10 + str[i] - '0';
		i++;
	}
	if (str[0] == 'G')
		return N + ans;
	else
		return ans;
}

void dijkstra(int s) {
	memset(vis, false, sizeof(vis));
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 1; i <=M+ N; i++) {
		int u = -1, MIN = INF;
		for (int j = 1; j <= N+M; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 1; v <= N+M; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}


int main() {
	cin >> N >> M >> K >> Ds;
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < K; i++) {
		string str1, str2;
		int len;
		cin >> str1 >> str2 >> len;
		int a = 0, b = 0;
		a = stringToNum(str1);
		b = stringToNum(str2);
		G[a][b] = G[b][a] = len;
	}
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;
	for (int i = N + 1; i <= N + M; i++) {
		double minDis = INF, avg = 0;
		dijkstra(i);
		for (int j = 1; j <= N; j++) {
			if (d[j] > Ds) {
				minDis = -1;
				break;
			}
			if (d[j] < minDis) {
				minDis = d[j];
			}
			avg += 1.0*d[j] / N;
		}
		if (minDis == -1)
			continue;
		if (minDis > ansDis) {
			ansID = i;
			ansAvg = avg;
			ansDis = minDis;
		} else if (minDis == ansDis && avg<ansAvg) {
			ansID = i;
			ansAvg = avg;
		}
	}
	if (ansID == -1) {
		cout << "No Solution" << endl;
	} else {
		printf("G%d\n", ansID - N);
		printf("%.1f %.1f", ansDis, ansAvg);
	}
	return 0;
}