#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1001;
int n, l;
//1-N;

struct Node {
	int id, layer;
}node;
vector<int> follow[maxn];
bool inq[maxn] = { false };
queue<Node> q;

int Forward = 0;
void bfs(int index, int &forward) {
	node.id = index;
	node.layer = 0;
	q.push(node);
	inq[index] = true;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node.id != index)
			forward++;
		for (int i = 0; i < follow[node.id].size(); i++) {
			int k = follow[node.id][i];
			Node next;
			next.id = k;
			next.layer =  node.layer + 1;
			if (inq[next.id]==false&&next.layer <= l) {
				q.push(next);
				inq[next.id] = true;
			}
		}
	}
}
int main() {
	cin >> n >> l;
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int star;
			scanf("%d", &star);
			follow[star].push_back(i);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int query;
		memset(inq, false, sizeof(inq));
		scanf("%d", &query);
		Forward = 0;
		bfs(query,Forward);
		printf("%d\n", Forward);
	}
	return 0;
}