/*
BOJ 15989 (https://www.acmicpc.net/problem/15989)
*/
#include <cstdio>
using namespace std;

int dp[10001];
int main() {
	int t, n;
	for (int i = 1; i <= 3; i++) {
		dp[i]++;
		for (int j = i + 1; j <= 10000; j++) {
			dp[j] = (dp[j] + dp[j - i]);
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}