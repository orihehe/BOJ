/*
BOJ 2698 - 인접한 비트의 개수
https://www.acmicpc.net/problem/2698

dp[자릿수][인접비트개수][끝비트] 로 설정
*/
#include <cstdio>
using namespace std;

int dp[101][101][2];
int main() {
	int n, t, k;
	dp[1][0][1] = dp[1][0][0] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j<i; j++) {
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
			dp[i][j][0] = dp[i - 1][j][1] + dp[i - 1][j][0];
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		printf("%d\n", dp[n][k][0] + dp[n][k][1]);
	}
	return 0;
}