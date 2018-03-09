#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, p;
int maxFacSum = -1;

vector<int> ans, temp, fac;

int powder(int x) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	return ans;
}

void init() {
	int i = 0, temp = 0;
	while (temp <= n) {
		fac.push_back(temp);
		temp = powder(++i);
	}
}
void dfs(int index, int nowK, int sum, int facSum) {
	if (nowK == k && sum == n) {
		if (facSum > maxFacSum) {
			maxFacSum = facSum;
			ans = temp;
		}
		return;
	}
	if (nowK > k || sum > n)
		return;
	if(index-1>=0) {
		temp.push_back(index);
		dfs(index, nowK + 1, sum + fac[index], facSum + index);
		temp.pop_back();
		dfs(index - 1, nowK, sum, facSum);
	}
}
int main() {
	cin >> n >> k >> p;
	init();
	dfs(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)
		printf("Impossible\n");
	else {
		printf("%d = %d^%d", n,ans[0],p);
		for (int i = 1; i<ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}