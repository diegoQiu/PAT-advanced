#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 1000000000;
const int maxn = 1111;
int N, M, K, Q;
int ans[maxn], needTime[maxn];

struct Window {
	int endTime,popTime;
	queue<int> q;
}window[20];

int change(int h, int m) {
	return h * 60 + m;
}

int main() {
	int index = 0;
	cin >> N >> M >> K >> Q;
	for (int i = 0; i < K; i++) {
		scanf("%d",&needTime[i]);
	}
	for (int i = 0; i < N; i++) {
		window[i].popTime = window[i].endTime = change(8, 0);
	}
	for (int i = 0; i < min(N*M, K); i++) {
		window[index%N].q.push(index);
		window[index%N].endTime += needTime[index];
		if (index < N)
			window[index].popTime = needTime[index];
		ans[index] = window[index%N].endTime;
		index++;//勿缺
	}
	for (; index < K; index++) {
		int idx = -1, minPopTime = INF;
		for (int i = 0; i < N; i++) {//这里是对N个川口查询，切勿写成K，否则造成 
			//queue pop 但此时队列已为空
			if (window[i].popTime < minPopTime) {
				idx = i;
				minPopTime = window[i].popTime;
			}
		}
		Window& w = window[idx];
		w.q.pop();
		w.q.push(index);
		w.endTime += needTime[index];
		w.popTime += needTime[w.q.front()];
		ans[index] = w.endTime;
	}
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		if (ans[q - 1] - needTime[q - 1] >= change(17, 0))
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", ans[q - 1] / 60, ans[q - 1] % 60);
	}
	return 0;
}