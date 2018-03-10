#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10001;
int father[maxn];
bool vis[maxn];
struct Data {
	int id, fid, mid, num, area;
	int cid[10];
}node[1005];

struct Family {
	int id,people;
	double area, num;
	bool flag;
}ans[maxn];

void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
}

bool cmp(Family a, Family b) {
	if (a.area != b.area) {
		return a.area > b.area;
	} else
		return a.id < b.id;
}

int find(int x){
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}

void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA < faB)
		father[faB] = faA;
	else if (faB < faA)
		father[faA] = faB;
}

int main() {
	init();
	int n,k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &node[i].id,
			&node[i].fid, &node[i].mid, &k);
		vis[node[i].id] = true;
		if (node[i].fid != -1) {
			Union(node[i].id, node[i].fid);
			vis[node[i].fid] = true;
		}
		if (node[i].mid != -1) {
			Union(node[i].id, node[i].mid);
			vis[node[i].mid] = true;
		}
		for (int j = 0; j < k; j++) {
			scanf("%d", &node[i].cid[j]);
			vis[node[i].cid[j]] = true;
			Union(node[i].id, node[i].cid[j]);
		}
		scanf("%d %d", &node[i].num, &node[i].area);
	}
	for (int i = 0; i < n; i++) {
		int id = find(node[i].id);
		ans[id].id = id;
		ans[id].num += node[i].num;
		ans[id].area += node[i].area;
		ans[id].flag = true;
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++) {
		if (vis[i]) {
			ans[find(i)].people++;
		}
		if (ans[i].flag)
			cnt++;
	}
	for (int i = 0; i < maxn; i++) {
		if (ans[i].flag) {
			ans[i].num = double(ans[i].num*1.0 / ans[i].people);
			ans[i].area = double(ans[i].area*1.0 / ans[i].people);
		}
	}
	sort(ans, ans + maxn, cmp);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people
			, ans[i].num, ans[i].area);
	}
	return 0;
}