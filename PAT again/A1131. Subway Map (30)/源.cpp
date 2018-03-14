#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 10000;
vector<int> v[maxn];
vector<int> tempPath, path;
int minCnt, minTransfer;
bool vis[maxn];
int line[maxn][maxn];
int st, ed, N, M, K;

int transferCnt(vector<int> a) {
	int cnt = -1, preLine = 0;;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i]][a[i - 1]] != preLine) {
			cnt++;
		}
		preLine = line[a[i]][a[i - 1]];
	}
	return cnt;
}

void dfs(int s) {
	if (s == ed ){
		tempPath.push_back(s);
		if (tempPath.size() < minCnt || (tempPath.size() == minCnt &&
			transferCnt(tempPath) < minTransfer)) {
			path = tempPath;
			minCnt = tempPath.size();
			minTransfer = transferCnt(tempPath);

		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(s);
	for (int i = 0; i < v[s].size(); i++) {
		if (vis[v[s][i]] == false) {
			vis[v[s][i]] = true;
			dfs(v[s][i]);
		}
	}
	tempPath.pop_back();
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int last;
		scanf("%d %d", &M, &last);
		for (int j = 1; j < M; j++) {
			int temp;
			scanf("%d", &temp);
			line[last][temp] = i;
			line[temp][last] = i;
			v[last].push_back(temp);
			v[temp].push_back(last);
			last = temp;
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &st, &ed);
		memset(vis, false, sizeof(vis));
		minCnt = 99999, minTransfer = 99999;
		dfs(st);
		printf("%d\n", minCnt);
		int preLine = 0, preTransfer = st;
		for (int j = 1; j < path.size(); j++) {
			if (line[path[j]][path[j - 1]] != preLine) {
				if (preLine != 0) {
					printf("Take Line#%d from %04d to %04d.\n"
						, preLine, preTransfer, path[j - 1]);
				}
				preTransfer = path[j - 1];
				preLine = line[path[j]][path[j - 1]];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, ed);
	}
	return 0;
}