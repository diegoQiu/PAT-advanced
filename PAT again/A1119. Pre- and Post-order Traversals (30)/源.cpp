#include<iostream>
using namespace std;
const int maxn = 35;
int pre[maxn], post[maxn], in[maxn];
int N;
struct node {
	int data;
	node *lchild, *rchild;
};

bool flag = true;
void creat(node* &root ,int preL, int preR, int postL, int postR) {
	if (preL > preR)
		return;
	if (root == NULL) {
		root = new node;
		root->data = pre[preL];
		root->lchild = root->rchild = NULL;
	}
	if (preL == preR) {//这种情况要单独处理，因为preL==preR的时候
		//下面那个if一定会成立，即flag总会被置为false
		root->data = pre[preL];
		return;
	}
	int k = preL+1;
	while (k<=preR&&pre[k] != post[postR - 1]) {
		k++;
	}
	if (k==preL+1)
		flag = false;
	creat(root->lchild, preL + 1, k - 1, postL, postL + k - preL - 2);
	creat(root->rchild, k, preR, postL + k - preL-1, postR - 1);
}

int cnt = 0;
void inOrder(node* root) {
	if (root == NULL)
		return;
	inOrder(root->lchild);
	printf("%d", root->data);
	cnt++;
	if (cnt < N)
		printf(" ");
	else
		printf("\n");
	inOrder(root->rchild);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pre[i];
	}for (int i = 0; i < N; i++) {
		cin >> post[i];
	}
	node* root = NULL;
	creat(root, 0, N - 1, 0, N - 1);
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	inOrder(root);
	return 0;
}