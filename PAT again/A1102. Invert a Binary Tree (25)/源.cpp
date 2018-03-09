#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node {
	int data, lchild, rchild;
}node[10];
bool notRoot[10];
int n;

queue<Node> q;
void level(int root) {
	q.push(node[root]);
	int cnt = 0;
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		printf("%d", temp.data);
		cnt++;
		if (cnt < n)
			printf(" ");
		else {
			printf("\n");
		}
		if (temp.lchild != -1) {
			q.push(node[temp.lchild]);
		}
		if (temp.rchild != -1)
			q.push(node[temp.rchild]);
	}
}

int num = 0;
void inOrder(int root) {
	if (root == -1)
		return;
	inOrder(node[root].lchild);
	printf("%d", node[root].data);
	num++;
	if (num < n)
		printf(" ");
	inOrder(node[root].rchild);
}

void reverseTree(int root) {
	if (root == -1)
		return;
	if (node[root].lchild != -1) {
		reverseTree(node[root].lchild);
	}
	if (node[root].rchild != -1) {
		reverseTree(node[root].rchild);
	}
	int temp = node[root].lchild;
	node[root].lchild = node[root].rchild;
	node[root].rchild = temp;
}
int main() {
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		if (str[0] >= '0'&&str[0] <= '9') {
			node[i].lchild = str[0] - '0';
			notRoot[str[0] - '0'] = true;
		}
		else {
			node[i].lchild = -1;
		}
		if (str[2] >= '0'&&str[2] <= '9') {
			node[i].rchild = str[2] - '0';
			notRoot[str[2] - '0'] = true;
		}
		else {
			node[i].rchild = -1;
		}
		node[i].data = i;
	}
	int root;
	for (int i = 0; i < 10; i++) {
		if (notRoot[i] == false) {
			root = i;
			break;
		}
	}
	int cRoot = root;
	reverseTree(root);
	level(root);
	inOrder(cRoot);
	return 0;
}