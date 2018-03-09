#include<iostream>
#include<queue>	
using namespace std;
struct Mouse {
	int weight;
	int r;
}mouse[1010];

queue<int> q;
int main() {
	int np, ng;
	cin >> np >> ng;
	for (int i = 0; i < np; i++) {
		scanf("%d", &mouse[i].weight);
	}
	for (int i = 0; i < np; i++) {
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}
	
	while (q.size() != 1) {
		int  temp,group;
		temp=q.size();
		if (temp%ng == 0)
			group = temp / ng;
		else
			group = temp / ng + 1;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				if (i*ng + j >= temp)
					break;
				int p = q.front();
				if (mouse[p].weight > mouse[k].weight) {
					k = p;
				}
				mouse[p].r = group + 1;
				q.pop();
			}
			q.push(k);
		}
	}
	mouse[q.front()].r = 1;
	for (int i = 0; i < np; i++) {
		printf("%d", mouse[i].r);
		if (i < np - 1)
			printf(" ");
	}
	return 0;
}