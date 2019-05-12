/*
BOJ 14450 - Hoof, Paper, Scissors (Gold)
https://www.acmicpc.net/problem/14450

dp[현재 낸것][바꾼 횟수][상대가 낸것]
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[3][21][100001];
char q[100001], bs[3] = { 'H','S','P' };
int n, k;
bool vic(char a, char b) {
	if (a == 'H' && b == 'S') return true;
	if (a == 'S' && b == 'P') return true;
	if (a == 'P' && b == 'H') return true;
	return false;
}
int go(int w, int cur, int cnt) {
	if (cur == n) return 0;
	if (dp[w][cnt][cur] != -1) return dp[w][cnt][cur];
	int vv = vic(bs[w], q[cur]);
	int ret = go(w, cur + 1, cnt) + vv;
	if (cnt < k) {
		ret = max(ret, go((w + 1) % 3, cur + 1, cnt + 1) + vv);
		ret = max(ret, go((w + 2) % 3, cur + 1, cnt + 1) + vv);
	}
	return dp[w][cnt][cur] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf(" %c", &q[i]);
	printf("%d", max({ go(1,0,0),go(0,0,0),go(2,0,0) }));

	return 0;
}