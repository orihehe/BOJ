/*
BOJ 17232 - 생명 게임
https://www.acmicpc.net/problem/17232

시간이 지날 때마다 부분합을 구해주고, 조건에 맞춰 상태를 바꿔준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char ba[101][102];
int dp[101][101];
int main() {
	int n, m, t, k, a, b;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &k, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%s", ba[i] + 1);
	while (t--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
					- dp[i - 1][j - 1] + (ba[i][j] == '*');
			}
		}
		int ru, cu, rr, cr, tmp;
		for (int i = 1; i <= n; i++) {
			rr = min(n, i + k);
			ru = max(1, i - k);
			for (int j = 1; j <= m; j++) {
				cr = min(m, j + k);
				cu = max(1, j - k);
				tmp = dp[rr][cr] - dp[rr][cu - 1] - dp[ru - 1][cr] + dp[ru - 1][cu - 1];
				if (ba[i][j] == '*') {
					tmp--;
					if (a > tmp || tmp > b) ba[i][j] = '.';
				}
				else {
					if (a < tmp && tmp <= b) ba[i][j] = '*';
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%s\n", ba[i] + 1);

	return 0;
}