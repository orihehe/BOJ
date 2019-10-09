/*
BOJ 4883 - 삼각 그래프
https://www.acmicpc.net/problem/4883
*/
#include <cstdio>
#include <algorithm>
#define INF 1987654321
using namespace std;

/* 🐣🐥 */
int dp[100001][3];
int rgo[4] = { 1,1,1,0 }, cgo[4] = { -1,0,1,1 };
int main() {
	int n, x, y;
	for (int t = 1;; t++) {
		scanf("%d", &n);
		if (n == 0) break;
		dp[0][2] = INF;
		for (int i = 0; i < n; i++) {
			dp[i + 1][0] = dp[i + 1][1] = dp[i + 1][2] = INF;
			for (int j = 0; j < 3; j++) {
				scanf("%d", &x);
				if (i == n - 1 && j == 1) y = x;
				if (i == 0 && j == 0) continue;
				for (int k = 0; k < 4; k++) {
					int nr = rgo[k] + i, nc = cgo[k] + j;
					if (nr < 0 || nc < 0 || nr >= n || nc >= 3) continue;
					dp[nr][nc] = min(dp[nr][nc], dp[i][j] + x);
				}
			}
		}
		printf("%d. %d\n", t, dp[n - 1][1] + y);
	}

	return 0;
}