/*
BOJ 2240 (https://www.acmicpc.net/problem/2240)
dp배열에 j번 이동했을 때 i초 당시의 최댓값을 저장한다.
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
		// 1번 나무에서 이동 안 했을 때
		dp[0][i] = dp[0][i - 1] + (arr[i] == 1 ? 1 : 0);
	}
	for (int j = 1; j <= w; j++) {
		int nx = j % 2 == 1 ? 2 : 1; // 이동 했을 때 서있는 자두나무 위치
		for (int i = j; i <= t; i++) {
			// dp[j][i-1]은 i 이전에 j번 이동했을 때 최댓값
			// dp[j-1][i-1]은 i에 j번째 이동했을 때 먹을 수있는 자두 개수
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