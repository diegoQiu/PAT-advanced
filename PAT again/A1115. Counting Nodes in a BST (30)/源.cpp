#include<iostream>
using namespace std;
int n;
struct node {
	int data,layer;
	node *lchild, *rchild;
};

void insert(node* &root, int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x <= root->data)
		insert(root->lchild, x);
	else
		insert(root->rchild, x);
}

int maxH = -1;
void dfs(node* root,int depth) {
	if (root == NULL)
		return;
	if (depth > maxH) {
		maxH = depth;
	}
	dfs(root->lchild, depth + 1);
	dfs(root->rchild, depth + 1);
}

int n1 = 0, n2 = 0;
void getAns(node* root, int depth) {
	if (root == NULL)
		return;
	if (depth == maxH)
		n1++;
	else if (depth == maxH - 1)
		n2++;
	getAns(root->lchild, depth + 1);
	getAns(root->rchild, depth + 1);
}
int main() {
	int n;
	cin >> n;
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		insert(root, temp);
	}
	dfs(root,0);
	getAns(root, 0);
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	return 0;
}