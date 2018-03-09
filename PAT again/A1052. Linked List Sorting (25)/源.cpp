#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Node {
	int address, key, next;
	bool flag;
}node[maxn];

bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false) {
		return a.flag > b.flag;
	} else
		return a.key < b.key;
}
int main() {
	int n, first;
	cin >> n >> first;
	for (int i = 0; i < maxn; i++) {
		node[i].key = maxn;
		node[i].flag = false;
	}
	for (int i = 0; i < n; i++) {
		int address;
		scanf("%d", &address);
		node[address].address = address;
		scanf("%d %d", &node[address].key, &node[address].next);
	}
	int p = first;
	int cnt = 0;
	while (p != -1) {
		cnt++;
		node[p].flag = true;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	if (cnt == 0) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", cnt, node[0].address);
	if (cnt == 1) {
		printf("%05d %d -1", node[0].address, node[0].key);
	}
	else {
		printf("%05d %d ", node[0].address, node[0].key);
		for (int i = 1; i < cnt - 1; i++) {
			printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].key);
		}
		printf("%05d\n%05d %d -1", node[cnt - 1].address, node[cnt - 1].address, node[cnt - 1].key);
	}
	return 0;
}