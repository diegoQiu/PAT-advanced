/*
这有个贼几把坑的地方，就是如果把couple初始化为0，那么如果数据中
出现了00000，但她今天没有来，这个人就会被当成别人的老婆而且来了
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100050;
int couple[maxn],guest[maxn];
bool come[maxn];
int n, m;
vector<int> lone;

int main() {
	cin >> n;
	fill(couple, couple + maxn, -1);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &guest[i]);
		come[guest[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		if (couple[guest[i]] == -1 || come[couple[guest[i]]] == false) {
			lone.push_back(guest[i]);
		}
	}
	sort(lone.begin(), lone.end());
	printf("%d\n", lone.size());
	for (int i = 0; i < lone.size(); i++) {
		printf("%05d", lone[i]);
		if (i < lone.size() - 1)
			printf(" ");
	}
	return 0;
}