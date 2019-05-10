/*
BOJ 17181 - 나랏말싸미 America와 different~
https://www.acmicpc.net/problem/17181

모음, 자음1, 자음2 로 구분하여 dist테이블을 만든다.
모음->자음
자음1->자음2 or 모음
자음2->모음 으로 이동이 가능, 글자 수는 모음의 개수로 세준다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int dist[3][51][51], arr[51][51], ans;
int n, m, rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
struct info {
	int w, r, c, d;
	bool operator < (const info &b) const {
		return d > b.d;
	}
};
priority_queue<info> pq;
int dijk() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 51; j++)
			fill(dist[i][j], dist[i][j] + 51, INF);
	dist[2][0][0] = 0;
	pq.push({ 2,0,0,0 });
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		if (cur.w != 2 && cur.r == n - 1 && cur.c == m - 1) {
			return cur.d;
		}
		if (dist[cur.w][cur.r][cur.c] > cur.d) continue;
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + rgo[i], nc = cur.c + cgo[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (!cur.w && arr[nr][nc] > 13) continue;
			if (cur.w == 2 && arr[nr][nc] <= 13) continue;

			int nw = cur.w + (arr[nr][nc] <= 13 ? 1 : -cur.w);
			int tmp = cur.d + (arr[nr][nc] > 13);
			if (tmp < dist[nw][nr][nc]) {
				dist[nw][nr][nc] = tmp;
				pq.push({ nw,nr,nc,tmp });
			}
		}
	}
	return INF;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	if (arr[0][0] > 13) return !printf("BAD");
	int ans = dijk();
	if (ans == INF) printf("BAD");
	else printf("%d", ans);

	return 0;
}