/*
BOJ 14461 - 소가 길을 건너간 이유 7
https://www.acmicpc.net/problem/14461

[세번][r위치][c위치]로 정의하여 다익을 돌리자
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

/* 🐣🐥 */
int arr[101][101];
int dist[3][101][101];
int n, t, rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
struct info {
	int r, c, w, val;
	bool operator <(const info &a) const {
		return val > a.val;
	}
};
priority_queue<info> pq;
void dijk() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				dist[i][j][k] = 987654321;
	dist[0][0][0] = 0;
	pq.push({ 0,0,0,0 });
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		if (dist[cur.w][cur.r][cur.c] < cur.val) continue;
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + rgo[i], nc = cur.c + cgo[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
			int tmp = cur.val + t;
			if (cur.w == 2) tmp += arr[nr][nc];
			if (dist[(cur.w + 1) % 3][nr][nc] > tmp) {
				dist[(cur.w + 1) % 3][nr][nc] = tmp;
				pq.push({ nr,nc,(cur.w + 1) % 3 ,tmp });
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	dijk();
	printf("%d", min({ dist[0][n - 1][n - 1],dist[1][n - 1][n - 1] ,dist[2][n - 1][n - 1] }));

	return 0;
}