/*
BOJ 13549 (https://www.acmicpc.net/problem/13549)
순간이동을 하는 경우 0초의 시간이 걸린다.
loc배열에 몇 번 이동하여 현재 위치에 왔는지를 저장하여 
큐에 새 위치를 넣을 때 이동횟수가 더 많다면 넣지 않는 방식으로 했다.
나온 이동 횟수들중 최솟값 출력.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define P pair<int,int>
using namespace std;

int loc[100003];
int main() {
	int n, k, s = 1, cnt = 100000;
	queue<P> q;
	scanf("%d %d", &n, &k);
	q.push({ n,0 });
	fill(loc, loc + 100003, 100000);
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
		}
		int cur = q.front().first;
		int cc = q.front().second;
		q.pop();
		if (cur == k) {
			cnt = min(cnt, cc);
		}
		if (cur > 0 && loc[cur - 1] > cc + 1) {
			q.push({ cur - 1 , cc + 1 });
			loc[cur - 1] = cc + 1;
		}
		if (cur < 100000 && loc[cur + 1] > cc + 1) {
			q.push({ cur + 1 , cc + 1 });
			loc[cur + 1] = cc + 1;
		}
		if (cur * 2 <= 100001 && loc[cur * 2] > cc) {
			q.push({ cur * 2 , cc });
			loc[cur * 2] = cc;
		}
		s--;
	}
	printf("%d", cnt);

	return 0;
}