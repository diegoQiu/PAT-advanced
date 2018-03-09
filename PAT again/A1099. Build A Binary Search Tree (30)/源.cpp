#include<iostream>
#include<algorithm>
#include<queue>	
using namespace std;
const int maxn = 101;
int n;
int in[maxn];
struct Node {
	int data, lchild, rchild;
}node[maxn];
queue<Node> q;

int index = 0;
void inOrder(int root) {
	if (root ==-1)
		return;
	inOrder(node[root].lchild);
	node[root].data = in[index++];
	inOrder(node[root].rchild);
}

void levelOrder(int root) {
	q.push(node[root]);
	int cnt = 0;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		printf("%d", top.data);
		cnt++;
		if (cnt < n )
			printf(" ");
		if (top.lchild != -1) {
			q.push(node[top.lchild]);
		}
		if (top.rchild != -1) {
			q.push(node[top.rchild]);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &node[i].lchild, &node[i].rchild);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in, in + n);
	inOrder(0);
	levelOrder(0);
	return 0;
}