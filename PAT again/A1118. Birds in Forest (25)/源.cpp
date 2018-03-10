#include<iostream>
using namespace std;
const int maxn = 10010;

int N, Q, father[maxn];
bool vis[maxn], root[maxn];

int find(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA != faB)
		father[faA] = faB;
}

void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
}

int main() {
	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int k;
		scanf("%d", &k);
		int a, b;
		scanf("%d", &a);
		vis[a] = true;
		for (int i = 0; i < k - 1; i++) {
			scanf("%d", &b);
			vis[b] = true;
			Union(a, b);
		}
	}
	int tree = 0, bird = 0;
	for (int i = 0; i < maxn; i++) {
		if (vis[i]) {
			bird++;
			if (root[find(i)] == false) {
				tree ++ ;
				root[find(i)] = true;
			}
		}
	}
	printf("%d %d\n", tree, bird);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a) == find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}