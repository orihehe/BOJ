/*
BOJ 11967 - 불켜기
https://www.acmicpc.net/problem/11967
*/
#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int bb[101][101], n, m, cnt;
vector<pii> vec[101][101];
int rgo[4] = { 0,0,1,-1 };
int cgo[4] = { 1,-1,0,0 };
void dfs(int r, int c) {
	bb[r][c] = 2;
	// 스위치 보자
	for (pii v : vec[r][c]) {
		if (bb[v.first][v.second] == 0) {
			bb[v.first][v.second] = 1; // 불 켜주고,
			cnt++;
			// 불 켜준 위치 상하좌우가 방문된 정점이라면 방금 불 켜준 곳 갈 수 있다.
			for (int i = 0; i < 4; i++) {
				int nr = v.first + rgo[i], nc = v.second + cgo[i];
				if (nr <1 || nc<1 || nr>n || nc>n) continue;
				if (bb[nr][nc] == 2) {
					dfs(v.first, v.second);
					break;
				}

			}
		}
	}
	// 방문 안 한 불 켜준곳 가자
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr <1 || nc<1 || nr>n || nc>n) continue;
		if (bb[nr][nc] == 1) {
			dfs(nr, nc);
		}
	}
}
int main() {
	int x, y, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		vec[x][y].push_back({ a,b });
	}
	dfs(1, 1);

	printf("%d", cnt + 1);

	return 0;
}