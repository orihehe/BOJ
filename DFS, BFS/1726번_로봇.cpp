/*
BOJ 1726 - 로봇
https://www.acmicpc.net/problem/1726
*/
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int arr[102][102], dist[102][102][4];
int rgo[4] = { 0,0,1,-1 }, cgo[4] = { 1,-1,0,0 };
struct info {
	int r, c, d;
};
queue<info> q;
int main() {
	int n, m, sr, sc, sd, er, ec, ed;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 4; k++) dist[i][j][k] = INF;
	scanf("%d %d %d", &sr, &sc, &sd);
	scanf("%d %d %d", &er, &ec, &ed);
	sd--, ed--;
	q.push({ sr,sc,sd });
	dist[sr][sc][sd] = 0;
	while (!q.empty()) {
		info cur = q.front();
		q.pop();
		if (cur.r == er && cur.c == ec && cur.d == ed) {
			return !printf("%d", dist[er][ec][ed]);
		}
		for (int i = 1; i <= 3; i++) {
			int nr = rgo[cur.d] * i + cur.r, nc = cgo[cur.d] * i + cur.c;
			if (nr <= 0 || nc <= 0 || nr > n || nc > m) continue;
			if (arr[nr][nc]) break;
			if (dist[nr][nc][cur.d] == INF) {
				dist[nr][nc][cur.d] = dist[cur.r][cur.c][cur.d] + 1;
				q.push({ nr,nc,cur.d });
			}
		}
		if (dist[cur.r][cur.c][cur.d < 2 ? 2 : 0] == INF) {
			dist[cur.r][cur.c][cur.d < 2 ? 2 : 0] = dist[cur.r][cur.c][cur.d] + 1;
			q.push({ cur.r,cur.c,cur.d < 2 ? 2 : 0 });
		}
		if (dist[cur.r][cur.c][cur.d < 2 ? 3 : 1] == INF) {
			dist[cur.r][cur.c][cur.d < 2 ? 3 : 1] = dist[cur.r][cur.c][cur.d] + 1;
			q.push({ cur.r,cur.c,cur.d < 2 ? 3 : 1 });
		}
	}

	return 0;
}