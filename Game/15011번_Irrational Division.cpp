/*
BOJ 15011 - Irrational Division
https://www.acmicpc.net/problem/15011

턴 0 입장에서는 내 이익을 최대로,
턴 1 입장에서는 상대의 손해를 최대로
*/
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int dp[101][101][2];
int p, q;
int go(int l, int r, int tr) {
	int ret, tt;
	if (l == q || r == p) return 0;
	if (dp[l][r][tr] != -INF) return dp[l][r][tr];
	if (!tr) {
		ret = -1000;
		for (int i = l + 1; i <= q; i++) {
			if ((i - l) % 2 && (p - r) % 2) {
				if (l % 2) tt = -1;
				else tt = 1;
			}
			else tt = 0;
			ret = max(ret, go(i, r, 1) + tt);
		}
	}
	else {
		ret = INF;
		for (int i = r + 1; i <= p; i++) {
			if ((q - l) % 2 && (i - r) % 2) {
				if ((l + p - r - 1) % 2) tt = 1;
				else tt = -1;
			}
			else tt = 0;
			ret = min(ret, go(l, i, 0) + tt);
		}
	}
	return dp[l][r][tr] = ret;
}
int main() {
	scanf("%d %d", &p, &q);
	for (int i = 0; i < p; i++)
		for (int j = 0; j < q; j++)
			dp[j][i][0] = dp[j][i][1] = -INF;
	printf("%d", go(0, 0, 0));

	return 0;
}