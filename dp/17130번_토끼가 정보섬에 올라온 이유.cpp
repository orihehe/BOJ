/*
BOJ 17130 - 토끼가 정보섬에 올라온 이유
https://www.acmicpc.net/problem/17130

토끼의 위치를 먼저 찾아주고 그 열에서부터 탐색.
현재 위치는 <r-1,c-1>, <r,c-1>, <r+1,c-1> 세 부분에서의 가장 많은 당근 수가 된다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char b[1010][1010];
int dp[1010][1010];
int main() {
	int n, m, ans = -1, xx;
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 'R') {
				dp[i][j] = 0;
				xx = j;
			}
		}
	}
	for (int j = xx + 1; j < m; j++) {
		for (int i = 1; i <= n; i++) {
			if (b[i][j] != '#') {
				dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1] });
				if (b[i][j] == 'C' && dp[i][j] != -1) dp[i][j]++;
				if (b[i][j] == 'O') ans = max(dp[i][j], ans);
			}
		}
	}
	printf("%d", ans);

	return 0;
}