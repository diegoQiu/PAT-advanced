#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 35;
int N, in[maxn], post[maxn];

struct node {
	int data, layer;
	node *lchild, *rchild;
};

node* Creat(node* &root, int inL, int inR, int postL, int postR, int h) {
	if (postL > postR)
		return NULL;
	if (root == NULL) {
		root = new node;
		root->data = post[postR];
		root->layer = h;
		root->lchild = root->rchild = NULL;
	}
	int k = inL;
	while (in[k] != post[postR])k++;
	root->lchild = Creat(root->lchild, inL, k - 1, postL, postL + k - inL - 1, h + 1);
	root->rchild = Creat(root->rchild, k + 1, inR, postL + k - inL, postR - 1, h + 1);
	return root;
}

queue<node*> q;
vector<int> ans[maxn];
int maxH=0;
void zigzag(node* root) {
	q.push(root);
	while (!q.empty()) {
		node* top = q.front();
		q.pop();
		ans[top->layer].push_back(top->data);
		if (top->layer > maxH)
			maxH = top->layer;
		if (top->lchild)
			q.push(top->lchild);
		if (top->rchild)
			q.push(top->rchild);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &in[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &post[i]);
	}
	node* root = NULL;
	root = Creat(root, 0, N - 1, 0, N - 1, 1);
	zigzag(root);
	int cnt = 0;
	printf("%d", ans[1][0]);
	cnt++;
	if (cnt < N)
		printf(" ");
	for (int i = 2; i <= maxH; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < ans[i].size(); j++) {
				printf("%d", ans[i][j]);
				cnt++;
				if (cnt < N)
					printf(" ");
			}
		}
		else {
			for (int j = ans[i].size() - 1; j >= 0; j--) {
				printf("%d", ans[i][j]);
				cnt++;
				if (cnt < N)
					printf(" ");
			}
		}
	}
	return 0;
}