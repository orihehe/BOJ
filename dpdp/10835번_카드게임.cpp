/*
BOJ 10835 (https://www.acmicpc.net/problem/10835)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[2000], b[2000], dp[2000][2000], n;
int go(int aa,int bb) {
	if (aa == n || bb == n) return 0;
	if (dp[aa][bb] != -1) {
		return dp[aa][bb];
	}
	int maxV = 0;
	maxV = max(maxV, go(aa + 1, bb)); // 왼쪽 카드를 버렸을 때
	maxV = max(maxV, go(aa + 1, bb + 1)); // 왼쪽, 오른쪽 카드를 버렸을 때 
	if (a[aa] > b[bb]) { // 오른쪽이 왼쪽보다 작을 경우
		maxV = max(maxV, go(aa, bb + 1) + b[bb]); // 오른쪽 카드를 버리며 점수 획득
	}
	// 위의 경우 중 최댓값 저장
	return dp[aa][bb] = maxV;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, 0));

	return 0;
}