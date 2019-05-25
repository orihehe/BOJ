/*
BOJ 14462 - 소가 길을 건너간 이유 8
https://www.acmicpc.net/problem/14462

횡단보도를 설치한 경우 x-1, y-1
설치하지 않은 경우 x-1,y   x,y-1 의 최댓값을 가져온다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int a[1000], b[1000], dp[1000][1000];
int go(int x, int y) {
	if (x<0 || y<0) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = max({ go(x - 1,y - 1) + (abs(a[x] - b[y]) <= 4),
		go(x,y - 1),go(x - 1,y) });
	return dp[x][y];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &a[i]);
	for (int i = 0; i<n; i++) scanf("%d", &b[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d", go(n - 1, n - 1));

	return 0;
}