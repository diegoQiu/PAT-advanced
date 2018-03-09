#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;
bool vis[maxn] = { false };
struct Node {
	int address, data, next;
	bool flag;
}node[maxn];
vector<Node> a, b;
int main() {
	int first, n;
	cin >> first >> n;
	for (int i = 0; i < n; i++) {
		int address;
		scanf("%d", &address);
		node[address].address = address;
		scanf("%d %d", &node[address].data, &node[address].next);
	}
	int p = first;
	int cnt = 0;
	while (p != -1) {
		if (vis[abs(node[p].data)] == false) {
			a.push_back(node[p]);
			vis[abs(node[p].data)] = true;
		}
		else {
			b.push_back(node[p]);
		}
		cnt++;
		p = node[p].next;
	}
	if (a.size() == 1) {
		printf("%05d %d -1\n", a[0].address, a[0].data);
	}
	else {
		printf("%05d %d ", a[0].address, a[0].data);
		for (int i = 1; i < a.size(); i++) {
			if (i != a.size() - 1) {
				printf("%05d\n%05d %d ", a[i].address, a[i].address, a[i].data);
			}
			else {
				printf("%05d\n%05d %d -1\n", a[i].address, a[i].address, a[i].data);
			}
		}
	}
	if (b.size()==1) {
		printf("%05d %d -1\n", b[0].address, b[0].data);
	}
	else if (b.size() > 1) {
		printf("%05d %d ", b[0].address, b[0].data);
		for (int i = 1; i < b.size(); i++) {
			if (i != b.size() - 1) {
				printf("%05d\n%05d %d ", b[i].address, b[i].address, b[i].data);
			} else {
				printf("%05d\n%05d %d -1", b[i].address, b[i].address, b[i].data);
			}
		}
	}
	return 0;
}