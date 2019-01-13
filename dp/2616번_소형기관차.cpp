/*
BOJ 2616 (https://www.acmicpc.net/problem/2616)
이전 기관차 개수 까지 선택한 것의 최대값 + 현재 위치 값
현재 기관차에서는 이전 기관차가 선택한 칸들 다음것 부터 보면 된다
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[50001];
int dp[4][50001];
int main() {
	int n, s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}
	scanf("%d", &s);
	for (int i = 1; i <= 3; i++) { // 기관차 개수
		for (int j = i * s; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1],
				arr[j] - arr[j - s] + dp[i - 1][j - s]);
		}
	}
	printf("%d", dp[3][n]);

	return 0;
}