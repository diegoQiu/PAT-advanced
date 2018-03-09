#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int getID(char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + name[i] - 'A';
	}
	id = id * 10 + name[3] - '0';
	return id;
}
const int maxn = 26 * 26 * 26 * 10 + 1;
vector<int> course[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int lesson, num;
		scanf("%d %d", &lesson, &num);
		for (int i = 0; i < num; i++) {
			char name[5];
			scanf("%s", name);
			course[getID(name)].push_back(lesson);
		}
	}
	for (int i = 0; i < n; i++) {
		char name[5];
		scanf("%s", name);
		int cnt = course[getID(name)].size();
		if (cnt != 0) {
			sort(course[getID(name)].begin(), course[getID(name)].end());
			printf("%s %d", name, cnt);
			for (int j = 0; j < cnt; j++) {
				printf(" %d", course[getID(name)][j]);
			}
			printf("\n");
		} else
			printf("%s 0\n", name);
	}
	return 0;
}