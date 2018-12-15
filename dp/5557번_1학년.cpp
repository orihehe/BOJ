/*
���� 5557 1�г�(https://www.acmicpc.net/problem/5557)
���� �ڿ������� �����ߴ�. dp[i][0~20]�� dp[i+1][j]�� ���� ���� ��(arr[i])�� ���ų� ���� ����� ���� �����Ѵ�.
*/
#include <cstdio>
#define ll long long
using namespace std;

ll dp[100][21], arr[100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	dp[n - 1][arr[n-1]]++;
	for (int i = n - 2; i >= 1; i--) {
		for (int j = 0; j < 21; j++) {
			if (j + arr[i] <= 20) {
				dp[i][j + arr[i]] += dp[i + 1][j];
			}
			if (j - arr[i] >=0) {
				dp[i][j - arr[i]] += dp[i + 1][j];
			}
		}
	}
	printf("%lld", dp[1][arr[0]]);

	return 0;
}