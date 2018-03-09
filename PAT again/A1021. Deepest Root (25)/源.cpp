//用并查集来判断是否是一颗树
//用两次dfs来获得最大深度根节点
#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int maxn = 10005;
int n;
set<int> ans, temp;
int father[maxn];
bool isRoot[maxn];
vector<int> pre[maxn];

int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
}

int calBlock() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)] = true;
	}
	for (int i = 1; i <= n; i++) {
		ans += isRoot[i];
	}
	return ans;
}

int maxH = -1;
void dfs(int v, int  height, int preNow) {
	if (height>maxH) {
		maxH = height;
		ans.clear();
		ans.insert(v);
	} else if (height == maxH) {
		ans.insert(v);
	}
	for (int i = 0; i < pre[v].size(); i++) {
		if (pre[v][i] == preNow)
			continue;
		dfs(pre[v][i], height + 1, v);
	}
}

int main() {
	cin >> n;
	init();
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pre[a].push_back(b);
		pre[b].push_back(a);
		Union(a, b);
	}
	int block = calBlock();
	if (block != 1) {
		printf("Error: %d components\n", block);
		return 0;
	}
	dfs(1, 1, -1);
	temp = ans;
	auto it = temp.begin();
	dfs(*it, 1, -1);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		temp.insert(*it);
	}
	for (auto it = temp.begin(); it != temp.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}