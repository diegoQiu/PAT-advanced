#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10001;
int n, a[maxn];
bool flag[maxn];
vector<int> ans;
int toFriend(int x) {
	int ans = 0;
	while (x != 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int temp = toFriend(a[i]);
		if (flag[temp] == false) {
			ans.push_back(temp);
			flag[temp] = true;
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if (i < ans.size() - 1)
			printf(" ");
	}
	return 0;
}