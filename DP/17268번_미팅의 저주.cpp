/*
BOJ 17268 - 미팅의 저주
https://www.acmicpc.net/problem/17268

한 점을 기준으로 봤을 때 미팅이 성공 할 수 있는 곳으로 잇고 그 선 기준 양 옆을 봐준다.
양 옆 점 개수의 경우의 수를 곱한 것을 모두 더한것이 답이 된다.
*/
#include <cstdio>
#define mod 987654321
using namespace std;

/* 🐣🐥 */
int dp[50001];
int main() {
	int n;
	scanf("%d", &n);
	n /= 2;
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = 2 * dp[i - 1] % mod;
		for (int j = 1; j <= i - 1; j++) {
			dp[i] = (dp[i] + 1LL * dp[j] * dp[i - 1 - j] % mod) % mod;
		}
	}
	printf("%d", dp[n]);

	return 0;
}