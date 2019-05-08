/*
BOJ 13448 - SW 역량 테스트
https://www.acmicpc.net/problem/13448

cmp기준 정렬로 시험 순서를 정해준뒤 dp
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
int m[51], p[51], r[51], arr[51];
ll ans = 0, dp[51][100001];
int n, t;
bool cmp(int a, int b) {
	return 1LL * r[a] * p[b] < 1LL * r[b] * p[a];
}
ll dfs(int cur, int tm) {
	if (cur == n) return 0;
	if (dp[cur][tm] != -1) return dp[cur][tm];
	ll ret = dfs(cur + 1, tm);
	int idx = arr[cur];
	if (tm + r[idx] <= t && m[idx] - 1LL * (tm + r[idx])*p[idx] > 0)
		ret = max(ret, dfs(cur + 1, (tm + r[idx])) + m[idx] - 1LL * (tm + r[idx])*p[idx]);
	return dp[cur][tm] = ret;
}
int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) arr[i] = i;
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
	}
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < n; i++) scanf("%d", &r[i]);

	sort(arr, arr + n, cmp);
	memset(dp, -1, sizeof(dp));

	printf("%lld", dfs(0,0));

	return 0;
}