#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 100010;
struct Node {
	int data;
	vector<int> child;
}node[maxn];

int n;
double p, r;
bool notroot[maxn] = { false };
int minLeaf = maxn;
int num = 0;
void dfs(int index, int height) {
	if (node[index].child.size() == 0) {
		if (height < minLeaf) {
			num = 1;
			minLeaf = height;
		}
		else if (height == minLeaf) {
			num++;
		}
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		dfs(node[index].child[i], height + 1);
	}
}
int main() {
	cin >> n >> p >> r;
	r /= 100;
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		for (int j = 0; j < id; j++) {
			int kid;
			scanf("%d", &kid);
			notroot[kid] = true;
			node[i].child.push_back(kid);
		}
	}
	int root;
	for (int i = 0; i < n; i++) {
		if (notroot[i] == false) {
			root = i;
			break;
		}
	}
	dfs(root, 0);
	printf("%.4f %d\n", p*pow(1 + r, minLeaf), num);
	return 0;
}