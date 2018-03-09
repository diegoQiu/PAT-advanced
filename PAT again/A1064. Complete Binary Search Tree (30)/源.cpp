#include<iostream>	
#include<algorithm>
using namespace std;
const int maxn = 1001;
int in[maxn], level[maxn];
int n;
int index = 0;
void inOrder(int root) {
	if (root > n)
		return;
	inOrder(root * 2);
	level[root] = in[index++];
	inOrder(root * 2 + 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in, in + n);
	inOrder(1);
	for (int i = 1; i <= n; i++) {
		printf("%d", level[i]);
		if (i < n )
			printf(" ");
	}
	return 0;
}