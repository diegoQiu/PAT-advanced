#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int leftMax[100050], rightMin[100050];
int main() {
	vector<int> a,b;
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	vector<int> ans;
	int minn = 1e9 + 1;
	int maxn = (-minn);

	for (int i = 0; i < n; i++) {
		if (b[i] > maxn) {
			maxn = b[i];
			leftMax[i] = maxn;
		}
		else {
			leftMax[i] = leftMax[i - 1];
		}
	}
	 minn = 1e9 + 1;
	 maxn = (-minn);
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] < minn) {
			minn = b[i];
			rightMin[i] = minn;
		} else {
			rightMin[i] = rightMin[i + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == a[i]) {
			if (b[i] >=leftMax[i]&&b[i] <= rightMin[i])
				ans.push_back(b[i]);
		}
	}
	int cnt = ans.size();
	if (cnt == 0)
		cout << 0<<endl<<endl;
	else {
		int m = 0;
		cout << ans.size() << endl;
		sort(ans.begin(), ans.end());
		for (int i = 0; i< cnt; i++) {
			printf("%d", ans[i]);
			m++;
			if (m < cnt)
				printf(" ");
		}
	}
	return 0;
}