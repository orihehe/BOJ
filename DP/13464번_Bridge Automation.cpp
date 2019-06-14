/*
BOJ 13464 - Bridge Automation
https://www.acmicpc.net/problem/13464

dp[이 배를 1800초 기다리게 하겠다]로 설정
마지막 배가 다리를 건너는 시점과, 현재 배 + 1800 + 배 개수*20 중 큰 시간 에서
현재 배 + 1800 를 빼주고 + 120 을 한 값이 선택한 배들이 지나가는 동안 차가 이용하지 못하는 시간이다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[4001], arr[4001], n;
int go(int cur) {
	if (cur == n) return 0;
	if (dp[cur] != -1) return dp[cur];
	int ret = 987654321;
	for (int i = cur; i < n; i++) {
		ret = min(ret, max(arr[i] + 20, arr[cur] + 1800 + (i - cur + 1) * 20)
			- (arr[cur] + 1800) + 120 + go(i + 1));
	}
	return dp[cur] = ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));

	printf("%d", go(0));

	return 0;
}