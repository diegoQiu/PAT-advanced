#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 50005;
int N, K;
int frequncy[maxn];

struct node {

	int value, cnt;

	node(int a, int b) :value(a), cnt(b) {}

	bool operator < (const node &a) const {

		return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;

	}
};

set<node> s;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		if (i != 1) {
			printf("%d:", temp);
			int tempCnt = 0;
			for (auto it = s.begin(); it != s.end() && tempCnt < K; it++) {
				printf(" %d", it->value);
				tempCnt++;
			}
			printf("\n");
		}
		auto it = s.find(node(temp, frequncy[temp]));
		if (it != s.end())
			s.erase(it);
		frequncy[temp]++;
		s.insert(node(temp, frequncy[temp]));
	}
	return 0;
}