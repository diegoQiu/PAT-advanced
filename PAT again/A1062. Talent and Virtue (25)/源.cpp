#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

struct people {
	char id[9];
	int v, t;
}ans[100005];
vector<people> s, n, f, other;

bool cmp(people a, people b) {
	if (a.t + a.v != b.t + b.v)
		return a.t + a.v > b.t + b.v;
	else if (a.v != b.v)
		return a.v > b.v;
	else
		return strcmp(a.id, b.id) < 0;
}
int main() {
	int N, L, H;
	cin >> N>>L>>H;
	people temp;
	int cnt = 0;
	for (int i =0 ; i < N; i++) {
		scanf("%s %d %d	", temp.id, &temp.v, &temp.t);
		if (temp.v >= L && temp.t >= L) {
			ans[cnt++] = temp;
			if (temp.v >= H && temp.t >= H)
				s.push_back(temp);
			else if (temp.t < H && temp.v >= H)
				n.push_back(temp);

			else if (temp.t < H&&temp.v < H&&temp.v >= temp.t) {
				f.push_back(temp);
			} else
				other.push_back(temp);
		}
	}
	sort(s.begin(), s.end(), cmp);
	sort(n.begin(), n.end(), cmp);
	sort(f.begin(), f.end(), cmp);
	sort(other.begin(), other.end(), cmp);
	cout << cnt << endl;
	for (int i = 0; i < s.size();i++) {
		printf("%s %d %d\n", s[i].id, s[i].v, s[i].t);
	}
	for (int i = 0; i < n.size(); i++) {
		printf("%s %d %d\n", n[i].id, n[i].v, n[i].t);
	}
	for (int i = 0; i < f.size(); i++) {
		printf("%s %d %d\n", f[i].id, f[i].v, f[i].t);
	}
	for (int i = 0; i < other.size(); i++) {
		printf("%s %d %d\n", other[i].id, other[i].v, other[i].t);
	}
	return 0;	
}