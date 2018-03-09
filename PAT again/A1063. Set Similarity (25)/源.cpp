#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<int> a[51];
set<int> ans;
void compare(int x, int y) {
	int total = a[y].size(), sameNum = 0;
	for (auto it = a[x].begin(); it != a[x].end(); it++) {
		if (a[y].find(*it) != a[y].end()) {
			sameNum++;
		} else
			total++;
	}
	printf("%.1f%\n", (100 * 1.0*sameNum / total));
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int temp;
			scanf("%d", &temp);
			a[i].insert(temp);
		}
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		compare(x, y);
	}
	return 0;
}