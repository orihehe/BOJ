/*
BOJ 15991 (https://www.acmicpc.net/problem/15991)
��Ī�� �̷�� ���� ���ϱ� ���ؼ� j(1,2,3)*2 ���� ������ �� ���� j�� ���δ�.
-> dp[i]=dp[i]+dp[i-j*2]
*/
#include <cstdio>
#define mod 1000000009
using namespace std;

int dp[100001];
int main() {
	int t, n;
	dp[0] = dp[1] = 1;
	dp[2] = dp[3] = 2;
	dp[4] = dp[5] = 3;
	for (int i = 6; i <= 100000; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[i] = (dp[i - j * 2] + dp[i]) % mod;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}