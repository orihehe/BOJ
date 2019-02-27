/*
BOJ 11998 (https://www.acmicpc.net/problem/11998)

3가지 행동을 했을 경우를 모두 탐색해준다. 
dp[x번째 행동][1번째 pail][2번째 pail]
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int a, b, k, m, ans = 987654321;
int dp[201][201][201];
void go(int cur, int l, int r) {
	if (dp[cur][l][r] != -1) return;
	if (cur > k) return;
	dp[cur][l][r] = 1;
	go(cur + 1, a, r);
	go(cur + 1, l, b);
	go(cur + 1, 0, r);
	go(cur + 1, l, 0);
	if (r > a - l) {
		go(cur + 1, a, r - (a - l));
	}
	else {
		go(cur + 1, l + r, 0);
	}
	if (l > b - r) {
		go(cur + 1, l - (b - r), b);
	}
	else {
		go(cur + 1, 0, l + r);
	}
}
int main() {
	scanf("%d %d %d %d", &a, &b, &k, &m);
	memset(dp, -1, sizeof(dp));
	go(0, 0, 0);
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= a; j++) {
			for (int k = 0; k <= b; k++) {
				if (dp[i][j][k] == 1) {
					ans = min(abs(m - (j + k)), ans);
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}