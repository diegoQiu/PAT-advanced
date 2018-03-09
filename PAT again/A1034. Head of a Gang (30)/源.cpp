#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn = 1001;
int weight[maxn];
bool vis[maxn];
map<string, int> id, gang;
map<int, string> name;
int n, k,head,number,total,person;
int G[maxn][maxn];
void dfs(int now, int  &head, int &number, int &total) {
	vis[now] = true;
	number++;
	if (weight[now] > weight[head]) {
		head = now;
	}
	for (int i = 0; i < person; i++) {
		
		if (G[now][i] > 0) {
			total += G[now][i];
			G[i][now] = 0;
			G[now][i] = 0;
			if (vis[i] == false) {
				dfs(i, head, number, total);
			}
		}
		
	}
}

int gangs = 0;
void dfsTraval() {
	for (int i = 0; i < person; i++) {
		if (vis[i] == false) {
			head=i,number = total = 0;
			dfs(i, head,number ,total );
			if (number > 2 && total > k) {
				gang[name[head]] = number;
			}
		}
	}
}

int change(string str) {
	if (id.find(str) != id.end()) {
		return id[str];
	}
	else {
		id[str] = person;
		name[person] = str;
		return person++;
	}
}


int main() {
	int w;
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	dfsTraval();
	cout << gang.size() << endl;
	for (auto it = gang.begin(); it != gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}