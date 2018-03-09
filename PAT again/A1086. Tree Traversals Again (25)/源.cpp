#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
struct node {
	int data;
	node *lchild, *rchild;
};

int n;
vector<int> pre, in;
stack<int> st;
node* creat(int preL, int preR, int inL, int inR) {
	if (preL > preR)
		return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k = inL;
	for (; k <= inR; k++) {
		if (in[k] == pre[preL])
			break;
	}
	int leftNum = k - inL;
	root->lchild = creat(preL + 1, preL + leftNum, inL, k - 1);
	root->rchild = creat(preL + leftNum + 1, preR, k + 1, inR);
	return root;
}

int cnt = 0;
void postOrder(node* root) {
	if (root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->data);
	cnt++;
	if (cnt < n)
		printf(" ");
}
int main() {
	cin >> n;
	getchar();
	for (int i = 0; i < 2 * n; i++) {
		string str;
		getline(cin, str);
		if (str[1] == 'u') {
			int ans = 0;
			for (int j = 5; j < str.length(); j++) {
				ans = ans * 10 + str[j] - '0';
			}
			pre.push_back(ans);
			st.push(ans);
		}
		else {
			in.push_back(st.top());
			st.pop();
		}
	}
	node* root = creat(0, n - 1, 0, n - 1);
	postOrder(root);
	return 0;
}