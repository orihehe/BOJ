/*
���� �� �����ϴ� �κ� ���� ���� (���� 11053�� https://www.acmicpc.net/problem/11053) �� ����ߴ�.
�̹� �������� ���� �Ǿ��ִ� ���̵� ���� ���̵��� ��ġ���� �ٲ� �� �ּҰ� �ȴ�.
���� ���� �� ���������� ã�´�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[200];
int dp[200];
int main() 
{
	int n, maxC=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
		maxC = max(maxC, dp[i]);
	}
	printf("%d", n - maxC);

	return 0;
}