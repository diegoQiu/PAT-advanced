#include<iostream>
using namespace std;
const int maxn = 50005;
int N, pre[maxn], in[maxn];

struct node {
	int data;
	node *lchild, *rchild;
};

void creat(node* &root, int preL, int preR, int inL, int inR) {
	if (preL > preR)
		return ;
	if (root == NULL) {
		root = new node;
		root->data = pre[preL];
		root->lchild = root->rchild = NULL;
	}
	int k = inL;
	for (; k < inR; k++) {
		if (in[k] == pre[preL])
			break;
	}
	int leftNum = k - inL;
	creat(root->lchild, preL + 1, preL + leftNum, inL, k - 1);
	creat(root->rchild, preL + leftNum + 1, preR, k + 1, inR);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &in[i]);
	}
	node *root = NULL;
	creat(root, 0, N - 1, 0, N - 1);
	while (root->lchild||root->rchild) {
		while (root->lchild)
			root = root->lchild;
		if (root->rchild!=NULL)
			root = root->rchild;
	}
	printf("%d", root->data);
	return 0;
}