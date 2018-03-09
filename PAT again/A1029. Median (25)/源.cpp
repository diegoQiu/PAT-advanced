#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
const int maxn = 2000005;
vector<long long> a;
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long  temp;
		scanf("%lld", &temp);
		a.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long temp;
		scanf("%lld", &temp);
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	printf("%lld", a[(a.size()-1) / 2]);
	return 0;
}