#include<iostream>
#include<algorithm>
using namespace std;
int K, N;

struct node {
	int data;
	node *lchild, *rchild;
	bool flag;//true==black,false==red
};

void insert(node* &root, int x) {
	if (root == NULL) {
		root = new node;
		root->lchild = root->rchild = NULL;
		if (x < 0) {
			root->data = (-x);
			root->flag = false;
		}
		else {
			root->data = x;
			root->flag = true;
		}
		return;
	}
	if (abs(x) < root->data)
		insert(root->lchild, x);
	else
		insert(root->rchild, x);
}

int getHeight(node* root) {
	if (root == NULL)
		return 0;
	int l = getHeight(root->lchild);
	int r = getHeight(root->rchild);
	if (root->flag)
		return max(l, r) + 1;
	else
		return max(l, r);
}

bool isRbt1(node* root) {
	if (root->flag == false)
		return  false;
	else
		return true;
}

bool isRbt2(node* root) {
	bool flag = true;
	if (root == NULL)
		return true;
	if (root->flag == false) {
		if (root->lchild&&root->lchild->flag == false)
			return false;
		if (root->rchild&&root->rchild->flag == false)
			return false;
	}
	bool f1 = isRbt2(root->lchild);
	bool f2 = isRbt2(root->rchild);
	return flag && f1&&f2;
}

bool  isRbt3(node* root) {
	if (root == NULL)
		return true;
	bool flag = true;
	bool f1 = isRbt3(root->lchild);
	bool f2 = isRbt3(root->rchild);
	int l = getHeight(root->lchild);
	int r = getHeight(root->rchild);
	if (r != l)
		flag = false;
	return flag && f1&&f2;
}

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N;
		node* root = NULL;
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			insert(root, temp);
		}
		bool flag = isRbt1(root) && isRbt2(root) && isRbt3(root);
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}