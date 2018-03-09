#include<iostream>	
#include<algorithm>
#include<string>
#include<cstring>
#include<map>	
#include<vector>
using namespace std;
const int maxn = 202;
const int INF = 1000000000;
int N, K;
string  star, city[maxn];
int  G[maxn][maxn];
bool vis[maxn] = { false };
int d[maxn], w[maxn];
vector<int> pre[maxn];
vector<int > path, tempPath;
map<string, int> nameToNum;
map<int, string> numToString;
int st, ed;

void dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
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
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[v] == d[u] + G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int ansW = -1;
double ansAvg = -1;
int numPath = 0;
void dfs(int v) {
	if (v == 0) {
		numPath++;
		tempPath.push_back(v);
		int weight = 0;
		double avg=0;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			int id = tempPath[i];
			weight += w[id];
		}
		avg = 1.0*weight / (tempPath.size()-1);
		if (weight > ansW) {
			ansW = weight;
			ansAvg = avg;
			path = tempPath;
		}
		else if (weight == ansW && avg > ansAvg) {
			ansAvg = avg;
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
	cin >> N >> K>>star;
	numToString[0] = star;
	nameToNum[star] = 0;
	for (int i = 1; i < N; i++) {
		string s;
		int weight;
		cin >> s >> weight;
		nameToNum[s] = i;
		numToString[i] = s;
		w[i] = weight;
	}
	fill(G[0], G[0] + maxn * maxn, INF);//≤Ÿ£¨”÷Õ¸¡À
	for (int i = 0; i < K; i++) {
		string s1, s2;
		int len;
		cin >> s1 >> s2 >> len;
		G[nameToNum[s1]][nameToNum[s2]] = G[nameToNum[s2]][nameToNum[s1]] = len;
	}
	 ed =nameToNum["ROM"];
	 dijkstra(0);
	 dfs(ed);
	 cout << numPath << " " << d[ed] << " " << ansW;
	 printf(" %d\n", (int)ansAvg);
	 for (int i = path.size() - 1; i >= 0; i--) {
		 cout << numToString[path[i]];
		 if (i > 0)
			 printf("->");
	 }
	 return 0;
}