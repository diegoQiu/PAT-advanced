#include<iostream>
#include<string>
using namespace std;

const int maxn = 25;
bool notRoot[maxn];
struct Node {
	string data;
	int lchild, rchild;
}node[maxn];

void inOrder(int root, int depth) {
	if (node[root].lchild == -1 && node[root].rchild == -1) {
		cout << node[root].data;
		return;
	}
	if (depth > 1)
		printf("(");
	if (node[root].lchild != -1)
		inOrder(node[root].lchild, depth + 1);
	cout << node[root].data;
	if (node[root].rchild != -1)
		inOrder(node[root].rchild, depth + 1);
	if (depth > 1)
		printf(")");
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> node[i].data >> node[i].lchild >> node[i].rchild;
		if (node[i].lchild != -1)
			notRoot[node[i].lchild] = true;
		if (node[i].rchild  != -1)
			notRoot[node[i].rchild] = true;
	}
	int root;
	for (int i = 1; i <= N; i++) {
		if (!notRoot[i]) {
			root = i;
			break;
		}
	}
	inOrder(root, 1);
	return 0;
}