/*
BOJ 2688 - 줄어들지 않아
https://www.acmicpc.net/problem/2688

dp[자릿수][마지막 수] 는 이전 자리 수의 마지막 수가 현재 수 이하인 모든 수의 개수이다.
*/
#include <cstdio>
#define ll long long
using namespace std;

ll dp[65][11];
int main() {
	int n, t;
	for (int i = 1; i <= 10; i++) dp[0][i] = i;
	for (int i = 1; i <= 64; i++) {
		for (int j = 1; j <= 10; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n - 1][10]);
	}
	return 0;
}