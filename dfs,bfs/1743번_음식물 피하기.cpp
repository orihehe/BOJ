/*
BOJ 1743 (https://www.acmicpc.net/problem/1743)
연결되어있는 음식물 개수가 가장 많은 것을 출력하면 된다.
visited배열을 만드는 대신 탐색한 음식물은 0으로 바꾸어줬다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int rgo[4] = { 1,0,-1,0 };
int cgo[4] = { 0,1,0,-1 };
int road[101][101], big, cnt;
void dfs(int r, int c) {
	road[r][c] = 0;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (road[nr][nc]) {
			dfs(nr, nc);
		}
	}
}

int main() {
	int n, m, k, rr, cc;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &rr, &cc);
		road[rr][cc] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (road[i][j]) {
				cnt = 0;
				dfs(i, j);
				big = max(big, cnt);
			}
		}
	}
	printf("%d", big);

	return 0;
}