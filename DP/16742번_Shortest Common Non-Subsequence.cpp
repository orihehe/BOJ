/*
BOJ 16742 - Shortest Common Non-Subsequence
https://www.acmicpc.net/problem/16742

A만 생각했을 때 최소 길이를 구하는 방법은
현재 위치에서 다음에 올 수를 0,1중 고르고 골라 원하는 수가 그 뒤에 없을 때 길이들 중 최솟값이다.

A와 B를 같은 방식으로 동시에 해주면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char A[4002], B[4002];
int dp[4002][4002], az, bz, a[4002][2], b[4002][2];
int go(int l, int r) {
	if (l == az + 1 && r == bz + 1) return 0;
	if (dp[l][r] != -1) return dp[l][r];

	return dp[l][r] = min(go(a[l][0], b[r][0]), go(a[l][1], b[r][1])) + 1;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s %s", A + 1, B + 1);
	az = strlen(A + 1), bz = strlen(B + 1);

	for (int i = 1; i <= az; i++) {
		for (int j = i - 1; j >= 0; j--) {
			a[j][A[i] - '0'] = i;
			if (A[j] == A[i]) break;
		}
	}
	for (int j = az + 1; j >= 0; j--) {
		for (int i = 0; i < 2; i++) {
			if (!a[j][i]) a[j][i] = az + 1;
		}
	}

	for (int i = 1; i <= bz; i++) {
		for (int j = i - 1; j >= 0; j--) {
			b[j][B[i] - '0'] = i;
			if (B[j] == B[i]) break;
		}
	}
	for (int j = bz + 1; j >= 0; j--) {
		for (int i = 0; i < 2; i++) {
			if (!b[j][i]) b[j][i] = bz + 1;
		}
	}

	go(0, 0);

	int l = 0, r = 0;
	while (l != az + 1 || r != bz + 1) {
		if (dp[a[l][0]][b[r][0]] <= dp[a[l][1]][b[r][1]]) {
			printf("0");
			l = a[l][0], r = b[r][0];
		}
		else {
			printf("1");
			l = a[l][1], r = b[r][1];
		}
	}

	return 0;
}