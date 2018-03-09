#include<iostream>
#include<vector>
#include<algorithm>	
using namespace std;

const int K = 111;
const int INF = 1000000000;
struct customer {
	int comeTime, serveTime;
}newCustomer;
vector<customer > custom;

int change(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}
bool cmp(customer a, customer b) {
	return a.comeTime < b.comeTime;
}
int stTime = change(8, 0, 0);
int endtime= change(17, 0, 0);
int endTime[K];

int main() {
	int c, w, totTime = 0;
	scanf("%d %d", &c, &w);
	for (int i = 0; i < w; i++)
		endTime[i] = stTime;
	for (int i = 0; i < c; i++) {
		int h, m, s, serveTime;
		scanf("%d:%d :%d %d", &h, &m, &s, &serveTime);
		int cometime = change(h, m, s);
		if (cometime > endtime)continue;
		newCustomer.comeTime = cometime;
		newCustomer.serveTime = serveTime <= 60 ? serveTime * 60 : 3600;
		custom.push_back(newCustomer);
	}
	sort(custom.begin(), custom.end(), cmp);
	for (int i = 0; i < custom.size(); i++) {
		int index = -1, minEndTime = INF;
		for (int j = 0; j < w; j++) {
			if (endTime[j] < minEndTime) {
				minEndTime = endTime[j];
				index = j;
			}
		}
		if (endTime[index] < custom[i].comeTime) {
			endTime[index] = custom[i].comeTime + custom[i].serveTime;
		}
		else {
			totTime += (endTime[index] - custom[i].comeTime);
			endTime[index] += custom[i].serveTime;
		}
	}
	if (custom.size() == 0)
		printf("0.0");
	else {
		printf("%.1f\n", totTime /60.0/ custom.size());
	}
	return 0;
}