#include<iostream>
#include<vector>
using namespace std;
const int maxn = 101;
int n, m;
struct Node {
	vector<int> child;
}node[maxn];

int levelNoChild[maxn];
int maxH = 0;
void dfs(int index, int height) {
	if (node[index].child.size() == 0) {
		levelNoChild[height]++;
		if (height > maxH)
			maxH = height;
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		dfs(node[index].child[i], height + 1);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int id, num;
		scanf("%d %d", &id, &num);
		for (int j = 0; j < num; j++) {
			int kid;
			scanf("%d", &kid);
			node[id].child.push_back(kid);
		}
	}
	dfs(01, 0);
	for (int i = 0; i <= maxH; i++) {
		printf("%d", levelNoChild[i]);
		if (i < maxH)
			printf(" ");
	}
	return 0;
}