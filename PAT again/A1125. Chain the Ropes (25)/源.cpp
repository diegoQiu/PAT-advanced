#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

vector<int> vi;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vi.push_back(x);
	}
	sort(vi.begin(), vi.end());
	int result = vi[0];
	for (int i = 1; i < vi.size(); i++) {
		result = (result + vi[i]) / 2;
	}
	printf("%d", result);
	return 0;
}