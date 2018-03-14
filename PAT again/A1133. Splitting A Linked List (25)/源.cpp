#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100010;

struct Node {
	int data;
	int address, next;
}node[maxn];
vector<Node> a, b;

int main() {
	int first, N, K;
	cin >> first >> N >> K;
	for (int i = 0; i < N; i++) {
		int address;
		scanf("%d", &address);
		scanf("%d %d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = first;
	while (p != -1) {
		if (node[p].data < 0) {
			a.push_back(node[p]);
		}
		else if (node[p].data <= K) {
			b.push_back(node[p]);
		}
		p = node[p].next;
	}
	p = first;
	while (p != -1) {
		if (node[p].data > K)
			b.push_back(node[p]);
		p = node[p].next;
	}
	for (auto it = b.begin(); it != b.end(); it++) {
		a.push_back(*it);
	}
	for (int i = 0; i < a.size(); i++) {
		if (i == 0)
			printf("%05d %d ", a[i].address, a[i].data);
		else {
			printf("%05d\n%05d %d ", a[i].address, a[i].address, a[i].data);
		}
	}
	printf("-1");
	return 0;
}