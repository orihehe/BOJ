/*
BOJ 17234 - Scoring Hack
https://www.acmicpc.net/problem/17234

dist[두 배로 올린 턴][전체 턴][점수]
두 배로 올린 횟수가 전체 횟수의 10% 이하이므로 전체 턴 또한 봐줘야한다.
*/
#include <cstdio>
#include <queue>
using namespace std;

/* 🐣🐥 */
bool dist[51][501][601];
struct info {
	int tw, num, sc;
};
queue<info> q;
int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	q.push({ 0,0 });
	while (!q.empty()) {
		info cur = q.front();
		q.pop();
		if (cur.sc >= n)
			return !printf("%d", cur.num);

		if (cur.sc * 2 < n + a && cur.tw + 1 <= (int)((cur.num + 1) / 10) 
			&& !dist[cur.tw][cur.num][cur.sc * 2]) {
			q.push({ cur.tw + 1,cur.num + 1,cur.sc * 2 });
			dist[cur.tw][cur.num][cur.sc * 2] = true;
		}
		if (!dist[cur.tw][cur.num][cur.sc + a]) {
			q.push({ cur.tw,cur.num + 1,cur.sc + a });
			dist[cur.tw][cur.num][cur.sc + a] = true;
		}
		if (!dist[cur.tw][cur.num][cur.sc + b]) {
			q.push({ cur.tw,cur.num + 1,cur.sc + b });
			dist[cur.tw][cur.num][cur.sc + b] = true;
		}
	}

	return 0;
}