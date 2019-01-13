/*
BOJ 2240 (https://www.acmicpc.net/problem/2240)
dp�迭�� j�� �̵����� �� i�� ����� �ִ��� �����Ѵ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[31][1001];
int arr[1001];
int main() {
	int t, w, x, maxS = 0;
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &arr[i]);
		// 1�� �������� �̵� �� ���� ��
		dp[0][i] = dp[0][i - 1] + (arr[i] == 1 ? 1 : 0);
	}
	for (int j = 1; j <= w; j++) {
		int nx = j % 2 == 1 ? 2 : 1; // �̵� ���� �� ���ִ� �ڵγ��� ��ġ
		for (int i = j; i <= t; i++) {
			// dp[j][i-1]�� i ������ j�� �̵����� �� �ִ�
			// dp[j-1][i-1]�� i�� j��° �̵����� �� ���� ���ִ� �ڵ� ����
			dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1]);
			if (arr[i] == nx) dp[j][i]++;
		}
	}
	for (int i = 0; i <= w; i++) {
		maxS = max(maxS, dp[i][t]);
	}
	printf("%d", maxS);

	return 0;
}