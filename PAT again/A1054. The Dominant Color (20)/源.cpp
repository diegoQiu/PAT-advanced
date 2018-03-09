#include<iostream>
#include<map>
#include<string>
using namespace std;
map<int, int> Count;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			scanf("%d", &temp);
			if (Count.find(temp) != Count.end()) {
				Count[temp]++;
			} else {
				Count[temp] = 1;
			}
		}
	}
	int k, maxn = 0;
	for (auto it = Count.begin(); it != Count.end(); it++) {
		if(it->second > maxn) {
			k = it->first;
			maxn = it->second;
		}
	}
	printf("%d\n", k);
	return 0;
}