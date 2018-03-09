#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10005;
struct car {
	char id[8];
	int time;
	char status[4];
}all[maxn], valid[maxn];
int num = 0;
map<string, int> parkTime;
int timeToInt(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}
bool cmpByIdAndTime(car a, car b) {
	if ((strcmp(a.id, b.id)))
		return strcmp(a.id, b.id) < 0;
	else
		return a.time < b.time;
}
bool cmpByTime(car a, car b) {
	return a.time < b.time;
}
int main() {
	int N, M;
	cin >> N >> M;
	int hh, mm, ss;
	for (int i=0)
		return 0;
}