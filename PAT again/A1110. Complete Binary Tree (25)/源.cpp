#include<iostream>
#include<string>
#include<queue>
using namespace std;
const int maxn = 25;
struct Node {
	int left, right, id;
}node[maxn];
bool notRoot[maxn];
int n;

int a, b;
int strToNum(string str) {
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		ans = ans * 10 + str[i] - '0';
	}
	return ans;
}

queue<int> q;
int last;
bool bfs(int root) {
	int cnt = 0;
	q.push(root);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		cnt++;
		if (top == -1 && cnt <= n) {
			return false;
		}
		if (cnt == n) {
			last = top;
			break;
		}
		q.push(node[top].left);
		q.push(node[top].right);
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		if (str1[0] == '-')
			node[i].left = -1;
		else {
			node[i].left = strToNum(str1);
			notRoot[strToNum(str1)] = true;
		}
		if (str2[0] == '-')
			node[i].right = -1;
		else {
			node[i].right = strToNum(str2);
			notRoot[strToNum(str2)] = true;
		}
		node[i].id = i;
	}
	int root;
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			root = i;
			break;
		}
	}
	if (bfs(root)) {
		printf("YES %d\n", last);
	} else
		printf("NO %d\n", root);
	return 0;
}