#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	int data,height;
	node *lchild, *rchild;
};

int getHeight(node* root) {
	if (root != NULL)
		return root->height;
	return 0;
}
int getBalance(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root,int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->height = 1;
		root->rchild = root->lchild = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->lchild )== 1) {
				R(root);
			}
			else if (getBalance(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	} else {
		insert(root->rchild, x);
		updateHeight(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->rchild) == -1) {
				L(root);
			} else if (getBalance(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
	return;
}
int main() {
	int n;
	cin >> n;
	int pre[25];
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
		insert(root, pre[i]);
	}
	printf("%d", root->data);
	return 0;
}