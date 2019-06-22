/*
BOJ 2449 - 전구
https://www.acmicpc.net/problem/2449

dp[l][r]을 현재 구간을 vec[l]색으로 만드는 최소 횟수로 둔다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
int dp[201][201], k;
vector<int> vec;
int go(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 0;
	int ret = 201;
	for (int i = l; i < r; i++) {
		ret = min(ret, go(l, i) + go(i + 1, r) + (vec[l] != vec[i + 1]));
	}
	return dp[l][r] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n, x, y;
	scanf("%d %d %d", &n, &k, &x);
	vec.push_back(x);
	for (int i = 1; i < n; i++) {
		scanf("%d", &y);
		if (x != y) {
			x = y;
			vec.push_back(x);
		}
	}
	printf("%d", go(0, vec.size() - 1));

	return 0;
}