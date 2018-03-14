#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int P, M, N;
const int maxn = 10005;

struct student {
	int id;
	int gp, gm, gf, g;
	string name;
	student() {
		gp = gm = gf = g = -1;
	}
}stu[maxn];

map<string, int> nameToId;
map<int, string> idToName;
vector<student> ans;
bool cmp(student a, student b) {
	if (a.g != b.g)
		return a.g > b.g;
	else
		return a.name < b.name;
}

int main() {
	cin >> P >> M >> N;
	for (int i = 0; i < P; i++) {
		string name;
		int gp;
		cin >> name >> gp;
		if (gp >= 200) {
			nameToId[name] = i;
			idToName[i] = name;
			stu[i].id = i;
			stu[i].name = name;
			stu[i].gp = gp;
		}
	}
	for (int i = 0; i < M; i++) {
		string name;
		int gm;
		cin >> name >> gm;
		if (nameToId.find(name) != nameToId.end()) {
			int id = nameToId[name];
			stu[id].gm = gm;
		}
	}
	for (int i = 0; i < N; i++) {
		string name;
		int gf;
		cin >> name >> gf;
		if (nameToId.find(name) != nameToId.end()) {
			int id = nameToId[name];
			stu[id].gf = gf;
			if (stu[id].gp >= 200) {
				if (stu[id].gm > stu[id].gf) {
					stu[id].g = 0.4*stu[id].gm + 0.6*stu[id].gf+0.5;
				} else {
					stu[id].g = stu[id].gf;
				}
				if (stu[id].g >= 60)
					ans.push_back(stu[id]);
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].name << " " << ans[i].gp << " " << ans[i].gm << " " << ans[i].gf << " " << ans[i].g << endl;
	}
	return 0;
}