#include<iostream>
#include<vector> 
#include<algorithm>
#include<queue>	
using namespace std;
const int maxn = 25;
int n;
struct node {
	int data,height;
	node *lchild, *rchild;
};

int getHeight(node* root) {
	if (root == NULL)
		return 0;
	else
		return root->height;
}

void updateHeight(node* root) {
	root->height= max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalance(node* root) {
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->height = 1;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->lchild) == 1) {
				R(root);
			}
			else if (getBalance(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, x);
		updateHeight(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->rchild) == -1) {
				L(root);
			}
			else if (getBalance(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
}

queue<node*> q;
bool bfs(node* root) {
	q.push(root);
	bool flag1=false, flag = true;
	int cnt = 0;
	while (!q.empty()) {
		node* top = q.front();
		q.pop();
		printf("%d", top->data);
		cnt++;
		if (cnt < n)
			printf(" ");
		if (top->lchild) {
			if (flag1)
				flag = false;
			q.push(top->lchild);
		}
		else {
			flag1 = true;
		}
		if (top->rchild) {
			if (flag1)
				flag = false;
			q.push(top->rchild);
		} else
			flag1 = true;
	}
	return flag;
}
int main() {
	node* root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		insert(root, x);
	}
	if (bfs(root))
		printf("\nYES");
	else
		printf("\nNO");
	return 0;
}