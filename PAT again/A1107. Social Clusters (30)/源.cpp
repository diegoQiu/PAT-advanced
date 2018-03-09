#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = { 0 };
int course[maxn];

int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	int z = a;
	while (a != father[a]) {
		a = father[a];
		father[z] = x;
		z = a;
	}
	return x;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[faA] = faB;
}

void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, k, h;
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &h);
			if (course[h] == 0) {
				course[h] = i;
			}
			Union(i, findFather(course[h]));
		}
	}
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (isRoot[i] != 0)
			ans++;
	}
	printf("%d\n", ans);
	sort(isRoot, isRoot + n+1, cmp);
	for (int i = 0; i < ans; i++) {
		printf("%d", isRoot[i]);
		if (i < ans - 1)
			printf(" ");
	}
	return 0;
}