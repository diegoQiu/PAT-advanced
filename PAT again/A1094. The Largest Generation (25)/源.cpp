#include<iostream>
#include<vector>
using namespace std;
const int maxn = 101;
struct Node {
	int data, height;
	vector<int > child;
}node[maxn];
int n;
int maxH, maxGen = 0;
int h[maxn];

void dfs(int index, int height) {
	h[height]++;
	if (h[height] > maxGen) {
		maxGen = h[height];
		maxH = height;
	}
	if (node[index].child.size() == 0) {
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		dfs(node[index].child[i], height + 1);
	}
}
int main() {
	int m;
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int id, k;
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			int kid;
			scanf("%d", &kid);
			node[id].child.push_back(kid);
		}
	}
	dfs(01, 1);
	printf("%d %d\n", maxGen, maxH);
	return 0;
}