#include<iostream>
#include<algorithm>	
using namespace std;
const int maxn = 100010;

struct Node {
	int address, data, next;
	int order;
}node[100010];

bool cmp(Node a, Node b) {
	return a.order < b.order;
}

int main() {
	int first, n, k;
	cin >> first >> n >> k;
	for (int i = 0; i < maxn; i++) {
		node[i].order = maxn;
	}
	for (int i = 0; i < n; i++) {
		int add;
		scanf("%d", &add);
		node[add].address = add;
		scanf("%d %d", &node[add].data, &node[add].next);
	}
	int p = first;
	int cnt = 0;
	while (p != -1) {
		node[p].order = cnt++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	for (int i = 0; i < cnt/k; i++) {
		for (int j = (1 + i)*k - 1; j > i*k; j--) {
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i*k].address, node[i*k].data);
		if (i < cnt / k - 1) {
			printf("%05d\n", node[(i + 2)*k - 1].address);
		}
		else {
			if (cnt%k == 0) {
				printf("-1\n");
			} else {
				printf("%05d\n", node[(i + 1)*k].address);
				for (int i = cnt / k*k; i<cnt; i++) {
					printf("%05d %d ", node[i].address, node[i].data);
					if (i < cnt - 1)
						printf("%05d\n", node[i+1].address);
					else
						printf("-1\n");
				}
			}
		}
	}
	return 0;
}