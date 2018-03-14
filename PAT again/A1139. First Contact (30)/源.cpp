#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
int N, M,K;
struct node {
	int a, b;
};
int  G[maxn][maxn];
vector<int> f[maxn];
vector<node> ans;
bool cmp(node x, node y) {
	if (x.a != y.a)
		return x.a < y.a;
	else
		return x.b < y.b;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		string a, b;
		cin >> a >> b;
		int x = abs(stoi(a)), y = abs(stoi(b));
		if (a.length() == b.length()) {
			f[x].push_back(y);
			f[y].push_back(x);
		}
		G[x][y] = 1;
		G[y][x] = 1;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ans.clear();
		for (int j = 0; j < f[abs(a)].size(); j++) {
			for (int k = 0; k < f[abs(b)].size(); k++) {
				int u = f[abs(a)][j], v = f[abs(b)][k];
				if (u == abs(b) || v == abs(a))
					continue;
				if (G[u][v] == 1) {
					node p;
					p.a = u;
					p.b = v;
					ans.push_back(p);
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for (int j = 0; j < ans.size(); j++) {
			printf("%04d %04d\n", ans[j].a, ans[j].b);
		}
	}
	return 0;
}