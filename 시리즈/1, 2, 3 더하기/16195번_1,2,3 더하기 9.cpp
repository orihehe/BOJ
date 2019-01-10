/*
BOJ 16195 (https://www.acmicpc.net/problem/16195)
*/
#include <cstdio>
#define mod 1000000009
using namespace std;

int dp[1001][1001];
int main() {
	int t, n, m;
	dp[1][1] = dp[1][2] = dp[1][3] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j < 1000; j++) { // 사용한 수 개수
			for (int k = 1; k <= 3; k++) { // 뒷자리 숫자
				dp[j+1][i] = (dp[j][i-k]+dp[j+1][i]) % mod;
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 2; j < 1000; j++) {
			dp[j][i] = (dp[j][i] + dp[j-1][i]) % mod;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		printf("%d\n", dp[m][n]);
	}

	return 0;
}