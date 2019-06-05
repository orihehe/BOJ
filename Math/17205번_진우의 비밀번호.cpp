/*
BOJ 17205 - 진우의 비밀번호
https://www.acmicpc.net/problem/17205
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[11];
int main() {
	int n, len;
	ll ans = 0;
	char st[11];
	scanf("%d %s", &n, st);
	len = strlen(st);
	dp[1] = 26;
	for (int i = 2; i <= 10; i++) {
		dp[i] = dp[i - 1] * 26 + 26;
	}
	for (int i = 0; i < len; i++) {
		ans += (st[i] - 'a')*dp[n - i - 1] + (st[i] - 'a' + 1);
	}
	printf("%lld", ans);

	return 0;
}