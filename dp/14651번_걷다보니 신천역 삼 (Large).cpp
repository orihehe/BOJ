/*
BOJ 14651 (https://www.acmicpc.net/problem/14651)
3�� ����� �ڸ��� ���� 3�� ����� �ȴ�.
���� �ڸ����� �������ִ� 0,1,2�θ� ǥ���� ���� 3���� ���� ������ ���� �����ϸ�
0,1,2 ������ ���� 0�� ���ϸ� �������� 0,1,2�� ��, 1�� ���ϸ� 1,2,0, 2�� ���ϸ� 2,0,1 �� ���´�.
n�ڸ��� ���� ��� ������ �� �������� 0�� n�ڸ� ���� ����ϸ� �ȴ�.
*/
#include <cstdio>
#define ll long long
#define mod 1000000009
using namespace std;

ll dp[3][33334];
int main() {
	int n;
	scanf("%d", &n);
	dp[1][1] = dp[2][1] = 1;
	for (int i = 2; i <= n; i++) {
		ll tmp = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1];
		for (int j = 0; j < 3; j++) {
			dp[j][i] = (dp[j][i] + tmp) % mod;
		}
	}
	printf("%lld", dp[0][n]);

	return 0;
}