/*
BOJ 17175 - 피보나치는 지겨웡~
https://www.acmicpc.net/problem/17175

호출 횟수를 메모이제이션
*/
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
int dp[51];
int fibonacci(int n) { // 호출
	if (dp[n] != -1) return dp[n];
	return dp[n] = (1LL + fibonacci(n - 2) + fibonacci(n - 1)) % mod;
}
int main() {
	int n;
	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = 1;
	scanf("%d", &n);
	printf("%d", fibonacci(n));

	return 0;
}