/*
BOJ 17367 - 공교육 도박
https://www.acmicpc.net/problem/17367

dp[a][b][c][n] -> a,b,c는 최근 던진 세 눈, n은 남은 턴
dp[b][c][x][n-1], 1<=x<=6의 기댓값 합과 지금의 기댓값 중 큰 값을 선택
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
double dp[7][7][7][1001];
int won(int i, int j, int k) {
	if (i == j && j == k)
		return 10000 + i * 1000;
	else if (i == j)
		return 1000 + i * 100;
	else if (k == j)
		return 1000 + k * 100;
	else if (i == k)
		return 1000 + i * 100;
	else return max(max(i, j), k) * 100;
}
double dfs(int a, int b, int c, int cnt) {
	if (cnt < 0) return 0;
	if (dp[a][b][c][cnt] >= 0) return dp[a][b][c][cnt];
	double ret = 0, cur = won(a, b, c);
	for (int i = 1; i <= 6; i++) {
		ret += dfs(b, c, i, cnt - 1);
	}
	return dp[a][b][c][cnt] = max(cur, ret) / 6;
}
int main() {
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	double ans = 0;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			for (int k = 1; k <= 6; k++)
				ans += dfs(i, j, k, n - 3);
	printf("%.8lf", ans / 36);

	return 0;
}