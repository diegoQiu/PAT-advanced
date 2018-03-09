#include<iostream>
#include<queue>
using namespace std;
const int  maxn = 35;
int post[maxn], in[maxn];
int n;

struct node {
	int data;
	node *lchild, *rchild;
};

node* creat( int inL, int inR, int postL, int postR) {
	if (postL > postR)
		return NULL;
	node* root = new node;
	root->data = post[postR];
	int k = inL;
	for (; k <= inR; k++) {
		if (in[k] == post[postR])
			break;
	}
	int leftNum = k - inL;
	root->lchild = creat( inL, k - 1, postL, postL + leftNum - 1);
	root->rchild = creat( k + 1, inR, postL + leftNum, postR- 1);
	return root;
}

queue<node*> q;
void layerOrder(node* root) {
	q.push(root);
	int cnt = 0;
	while (!q.empty()) {
		node* top = q.front();
		q.pop();
		printf("%d", top->data);
		cnt++;
		if (cnt < n )
			printf(" ");
		if (top->lchild)
			q.push(top->lchild);
		if (top->rchild)
			q.push(top->rchild);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	node*  root = creat( 0, n - 1, 0, n - 1);
	layerOrder(root);
	return 0;
}