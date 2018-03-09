#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 40001;
vector<int> pick[2501];
char name[maxn][5];
bool cmp(int a , int b) {
	return strcmp(name[a], name[b]) < 0;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%s", name[i]);
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int lesson;
			scanf("%d", &lesson);
			pick[lesson].push_back(i);
		}
		
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, pick[i].size());
		sort(pick[i].begin(), pick[i].end(),cmp);
		for (int j = 0; j < pick[i].size(); j++) {
			printf("%s\n", name[pick[i][j]]);
		}
	}
	return 0;
}