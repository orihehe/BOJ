/*
BOJ 16561 - 3의 배수
https://www.acmicpc.net/problem/16561

dp[수 개수][값] 으로 정의
*/
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[3][1001];
ll go(int cnt, int rm) {
	ll ret = 0;
	if (cnt == 3) {
		return rm == 0;
	}
	if (dp[cnt][rm] != -1) return dp[cnt][rm];
	for (int i = 1; i <= rm; i++) {
		ret += go(cnt + 1, rm - i);
	}
	return dp[cnt][rm] = ret;
}
int main() {
	int n;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	n /= 3;
	printf("%lld", go(0, n));

	return 0;
}