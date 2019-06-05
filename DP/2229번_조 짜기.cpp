/*
BOJ 2229 (https://www.acmicpc.net/problem/10835)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 2; i <= n; i++) {
		int minV = arr[i], maxV = arr[i];
		for (int j = 1; j < i; j++) { // i�� i�� j��� �Բ� ���� �ȴ�.
			minV = min(minV, arr[i-j]), maxV = max(maxV, arr[i-j]);
			// j�� ��ŭ�� ���� �Ǿ��� �� ���� ���� + j ������ �ִ�
			dp[i] = max(dp[i], dp[i - j-1] + maxV - minV); 
		}
	}
	printf("%d", dp[n]);

	return 0;
}