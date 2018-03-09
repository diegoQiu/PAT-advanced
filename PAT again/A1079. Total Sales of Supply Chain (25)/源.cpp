#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn = 100010;
int n;
double p, r;
bool notRoot[maxn];
struct Node {
	double product;
	vector<int> child;
	int height;
}node[maxn];

queue<Node> q;

int findRoot() {
	int x;
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			x = i;
			break;
		}
	}
	return x;
}

double cal(int root, int height) {
	node[root].height = height;
	q.push(node[root]);
	double ans = 0;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		if (top.child.size() == 0)
			ans += top.product* pow(1 + r,top.height);
		for (int i = 0; i < top.child.size(); i++) {
			node[top.child[i]].height = top.height + 1;
			q.push(node[top.child[i]]);
		}
	}
	return ans;
}
int main() {
	cin >> n >> p >> r;
	r /= 100;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if (k != 0) {
			for (int j = 0; j < k; j++) {
				int temp;
				scanf("%d", &temp);
				notRoot[temp] = true;
				node[i].child.push_back(temp);
			}
		} else {
			double temp;
			scanf("%lf", &temp);
			node[i].product = temp;
		}
	}
	double  ans = cal(0, 0);
	printf("%.1f\n", ans*p);
	return 0;
}