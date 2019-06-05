/*
BOJ 17272 - 리그 오브 레전설 (Large)
https://www.acmicpc.net/problem/17272

dp[i] = dp[i-1] + dp[i-m] 을 행렬로 나타내어 빠른 제곱
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll arr[101][101], tmp[101][101], ret[101][101];
int m;
ll n;
void met(ll aa[][101], ll bb[][101]) {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				tmp[i][j] += aa[i][k] * bb[k][j] % mod;
			}
			tmp[i][j] %= mod;
		}
	}
	memcpy(aa, tmp, sizeof(tmp));
}
int calc(ll b) {
	arr[0][0] = arr[0][m - 1] = 1;
	for (int i = 1; i < m; i++) arr[i][i - 1] = 1;
	memcpy(ret, arr, sizeof(ret));
	while (b > 0) {
		if (b % 2) met(ret, arr);
		b /= 2;
		met(arr, arr);
	}
	return ret[1][0];
}
int main() {
	scanf("%lld %d", &n, &m);
	printf("%d", calc(n));

	return 0;
}