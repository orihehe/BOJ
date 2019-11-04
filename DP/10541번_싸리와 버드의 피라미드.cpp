/*
BOJ 10541 - 싸리와 버드의 피라미드
https://www.acmicpc.net/problem/10541
*/
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
int dp[1000001][26];
char st[1000002];
int main() {
	int q, len;
	ll n, x;
	char c;
	scanf("%lld %s %d", &n, st + 1, &q);
	len = strlen(st + 1);
	for (int i = 1; i <= len; i++) {
		st[i] -= 'A';
		for (int j = 0; j < 26; j++)
			dp[i][j] += dp[i - 1][j];
		dp[i][st[i]]++;
	}
	n = len;
	while (q--) {
		scanf("%lld %c", &x, &c);
		c -= 'A';
		ll t1 = x, t2 = x - 1, dw, up;
		if (t1 % 2) t2 /= 2;
		else t1 /= 2;
		dw = (t1 % n) * (t2%n) % n;
		t1 = x, t2 = x + 1;
		if (t1 % 2) t2 /= 2;
		else t1 /= 2;
		up = t1 % n*(t2%n) % n;
		if (up >= dw)
			printf("%lld\n", dp[up][c] - dp[dw][c] + dp[n][c] * (x / n));
		else
			printf("%lld\n", dp[up][c] + dp[n][c] - dp[dw][c] + dp[n][c] * (x / n));
	}

	return 0;
}