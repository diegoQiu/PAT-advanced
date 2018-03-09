#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100010;
int n;
double p, r;

struct Node {
	int height;
	vector<int> child;
}node[maxn];

int maxHeight = 0;
int num=0;
void dfs(int index, int height) {
	if (node[index].child.size() == 0) {
		if (height > maxHeight) {
			maxHeight = height;
			num = 1;
		}
		else if (height == maxHeight) {
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
	int root;
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		if (id == -1) {
			root = i;
		}
		else {
			node[id].child.push_back(i);
		}
	}
	dfs(root, 0);
	printf("%.2f %d\n", p*pow(1 + r, maxHeight), num);
	return 0;
}