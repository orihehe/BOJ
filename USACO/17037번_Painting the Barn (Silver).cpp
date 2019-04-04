/*
BOJ 17037 - Painting the Barn (Silver)
https://www.acmicpc.net/problem/17037

각 지점에 1, -1을 찍고 가로, 세로로 스위핑
*/
#include <cstdio>
#define MAX 10000
using namespace std;

/* 🐣🐥 */
int dp[1001][1001], arr[1001][1001];
int main() {
	int n, k, r1, c1, r2, c2, ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		arr[r1][c1] += 1;
		arr[r1][c2] += -1;
		arr[r2][c1] += -1;
		arr[r2][c2] += 1;
	}
	for (int i = 0; i < MAX; i++) {
		dp[i][0] = arr[i][0];
		for (int j = 1; j < MAX; j++) {
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			dp[j][i] += dp[j - 1][i];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (k == dp[i][j]) ans++;
		}
	}
	printf("%d", ans);

	return 0;
}