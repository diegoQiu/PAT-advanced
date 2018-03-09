#include<iostream>
using namespace std;
const int maxn = 100010;
struct Node {
	int address, next;
	int order;
	char data;
	bool flag;
}node[maxn];
int main() {
	int f1, f2, n;
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	cin >> f1 >> f2 >> n;
	for (int i = 0; i < n; i++) {
		int add;
		scanf("%d", &add);
		node[add].address = add;
		scanf(" %c %d", &node[add].data, &node[add].next);
	}
	int p;
	for ( p = f1; p != -1; p = node[p].next) {
		node[p].flag = true;
	}
	for (p = f2; p != -1; p = node[p].next) {
		if (node[p].flag == true)
			break;
	}
	if (p != -1)
		printf("%05d", p);
	else
		printf("-1\n");
	return 0;
}