/*
BOJ 13913 (https://www.acmicpc.net/problem/13913)
현재위치에서 가능한 이동경우를 큐에 넣고, 그 위치는 현재위치에서 왔다는 정보를 loc배열에 저장
동생을 찾았을 때 큐를 나와 동생에서부터 경로를 역추적 한다.
가능한 위치가 0부터 이므로 loc배열을 -1로 초기화 해주었다.
*/
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int loc[100003];
int main() {
	int n, k, s = 1, cnt=0;
	queue<int> q;
	stack<int> sta;
	scanf("%d %d", &n, &k);
	q.push(n);
	memset(loc, -1, sizeof(loc));
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
			cnt++;
		}
		int cur = q.front(); q.pop();
		if (cur == k) {
			break;
		}
		if (cur > 0 && loc[cur-1]==-1) {
			q.push(cur - 1);
			loc[cur - 1] = cur;
		}
		if (cur < 100000 && loc[cur + 1]==-1) {
			q.push(cur + 1);
			loc[cur + 1] = cur;
		}
		if (cur * 2 <= 100001 && loc[cur * 2]==-1) {
			q.push(cur * 2);
			loc[cur * 2] = cur;
		}
		s--;
	}
	printf("%d\n", cnt);
	for (int i = k; i!= n; i = loc[i]) {
		sta.push(i);
	}
	sta.push(n);
	while (!sta.empty()) {
		printf("%d ", sta.top());
		sta.pop();
	}

	return 0;
}