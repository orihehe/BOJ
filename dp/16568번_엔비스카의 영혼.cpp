/*
BOJ 16568 - 엔비스카의 영혼
https://www.acmicpc.net/problem/16568

앞에 한 명이 간 후 새치기를 하거나 기다리니 a-1, b-1, -1 중 최솟값을 가져와 +1
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[1000001];
int n, a, b;
int go(int cur) {
	if (dp[cur] != -1) return dp[cur];
	int ret = go(cur - 1);
	if (cur - a - 1 >= 0) ret = min(ret, go(cur - a - 1));
	if (cur - b - 1 >= 0) ret = min(ret, go(cur - b - 1));
	return dp[cur] = ret + 1;
}
int main() {
	scanf("%d %d %d", &n, &a, &b);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	printf("%d", go(n));

	return 0;
}