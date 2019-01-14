/*
BOJ 14925 (https://www.acmicpc.net/problem/14925)
���� 0�̰� dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]���� xũ���� ���簢���� ���� �� �ִٸ�
���� ��ġ���� x+1ũ���� ���簢���� ���� �� �ִ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main() {
	int m, n, maxS=0, x;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x); 
			if (x == 0) {
				dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
			}
			maxS = max(maxS, dp[i][j]);
		}
	}
	printf("%d", maxS);

	return 0;
}