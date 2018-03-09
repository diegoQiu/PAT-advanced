#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 101;
int n, m, s;

struct Node {
	int weight;
	vector<int> child;
}node[maxn];

bool cmp(int  a, int  b) {
	return node[a].weight > node[b].weight;
}

vector<int> path;
void dfs(int index, int weight) {
	if (node[index].child.size() == 0 && weight == s) {
		for (int i = 0; i < path.size(); i++) {
			printf("%d",node[path[i]].weight);
			if (i < path.size() - 1)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	sort(node[index].child.begin(), node[index].child.end(), cmp);
	for (int i = 0; i < node[index].child.size(); i++) {
		path.push_back(node[index].child[i]);
		dfs(node[index].child[i], weight + node[node[index].child[i]].weight);
		path.pop_back();
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &node[i].weight);
	}
	for (int i = 0; i < m; i++) {
		int father, k;
		scanf("%d %d", &father, &k);
		for (int j = 0; j < k; j++) {
			int kid;
			scanf("%d", &kid);
			node[father].child.push_back(kid);
		}
	}
	path.push_back(0);
	dfs(0, node[0].weight);
	return 0;
}