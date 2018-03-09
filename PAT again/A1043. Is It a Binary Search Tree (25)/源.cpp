#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1010;

vector<int> pre, mpre, post, mpost, origin;
struct node {
	int data;
	node *lchild, *rchild;
};

void insert(node* &root, int x) {
	if (root == NULL) {
	    root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
	}
	else {
		insert(root->rchild, x);
	}
}

void preOrder(node* root, vector<int> &vi) {
	if (root == NULL) {
		return;
	}
	vi.push_back(root->data);
	preOrder(root->lchild,vi);
	preOrder(root->rchild,vi);
}
void mirrorpreOrder(node* root, vector<int> &vi) {
	if (root == NULL) {
		return;
	}
	vi.push_back(root->data);
	mirrorpreOrder(root->rchild, vi);
	mirrorpreOrder(root->lchild, vi);
}

void postOrder(node* root, vector<int> &vi) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}
void mirrorpostOrder(node* root, vector<int> &vi) {
	if (root == NULL) {
		return;
	}
	mirrorpostOrder(root->rchild, vi);
	mirrorpostOrder(root->lchild, vi);
	vi.push_back(root->data);
}
int main() {
	int n;
	cin >> n;
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		origin.push_back(temp);
		insert(root, temp);
	}
	preOrder(root, pre);
	mirrorpreOrder(root, mpre);
	postOrder(root, post);
	mirrorpostOrder(root, mpost);
	if (pre == origin) {
		cout << "YES" << endl;
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1)
				printf(" ");
		}
	}
	else if (mpre == origin) {
		cout << "YES" << endl;
		for (int i = 0; i < mpost.size(); i++) {
			printf("%d", mpost[i]);
			if (i < mpost.size() - 1)
				printf(" ");
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}