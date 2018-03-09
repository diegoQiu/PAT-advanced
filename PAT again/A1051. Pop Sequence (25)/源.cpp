#include<iostream>
#include<stack>
using namespace std;
const int maxn = 1010;
int a[maxn];
stack<int> st;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	while (k--) {
		while (!st.empty())
			st.pop();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int current = 1;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			st.push(i);
			if (st.size() > m) {
				flag = false;
				break;
			}
			while (!st.empty() && st.top() == a[current]) {
				st.pop();
				current++;
			}
		}
		if (st.empty() == true && flag == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}