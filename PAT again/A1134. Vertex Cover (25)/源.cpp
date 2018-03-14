#include<iostream>
#include<set>
using namespace std;
const int maxn = 10010;
int N, M,K,Nv;
int father[maxn];

struct Edge {
	int a, b;
}edge[maxn];

int main() {
	cin >> N>>M;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[i].a = a;
		edge[i].b = b;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		scanf("%d", &Nv);
		set<int> s;
		bool flag = true;
		for (int j = 0; j < Nv; j++) {
			int temp;
			scanf("%d", &temp);
			s.insert(temp);
		}
		for (int j = 0; j < M; j++) {
			int a = edge[j].a;
			int b = edge[j].b;
			if (s.find(a) == s.end() && s.find(b) == s.end()) {
				flag = false;
				break;
			}	
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}