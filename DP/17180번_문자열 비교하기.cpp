/*
BOJ 17180 - 문자열 비교하기
https://www.acmicpc.net/problem/17180
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int n, m;
char a[302], b[302];
int dp[302][302];
int go(int ap, int bp) {
	if (dp[ap][bp] != -1) return dp[ap][bp];
	int ret = 987654321;
	// b[bp]문자 늘이기
	if (ap < n - 1) ret = min(ret, go(ap + 1, bp));
	// a[ap]문자 늘이기
	if (bp < m - 1) ret = min(ret, go(ap, bp + 1));
	// 늘이지 않기
	if (ap < n - 1 && bp < m - 1) ret = min(ret, go(ap + 1, bp + 1));
	return dp[ap][bp] = ret + abs(b[bp] - a[ap]);
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%s %s", a, b);
	memset(dp, -1, sizeof(dp));
	dp[n - 1][m - 1] = abs(a[n - 1] - b[m - 1]);
	printf("%d", go(0, 0));

	return 0;
}