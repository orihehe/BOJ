/*
BOJ 15990 (https://www.acmicpc.net/problem/15990)
*/
#include <cstdio>
#define mod 1000000009
using namespace std;

int dp[4][100001];
int main() {
	int t, n;
	dp[1][1] = dp[2][2] = dp[3][3] = 1;
	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j <= 3; j++) { // 추가할 수
			for (int k = 1; k <= 3; k++) { // 뒷자리 수
				if (j == k) continue;
				dp[j][i] = (dp[k][i - j] + dp[j][i]) % mod;
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		// int형이므로 중간에 mod연산이 없으면 오버플로
		printf("%d\n", ((dp[1][n]+dp[2][n]) % mod +dp[3][n])%mod);
	}

	return 0;
}