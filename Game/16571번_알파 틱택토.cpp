/*
BOJ 16571 - 알파 틱택토
https://www.acmicpc.net/problem/16571

보드의 상태를 3진수로 저장
나는 내가 이기도록 진행하고, 상대는 내가 지도록 진행해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int dp[19683], b[3][3];
int x, o, me;
int win(int num) {
	int tmp[3][3], t = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tmp[i][j] = num % 3;
			num /= 3;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (tmp[i][0] == tmp[i][1] && tmp[i][1] == tmp[i][2])
			t = max(t, tmp[i][0]);
		if (tmp[0][i] == tmp[1][i] && tmp[1][i] == tmp[2][i])
			t = max(t, tmp[0][i]);
	}
	if (tmp[0][0] == tmp[1][1] && tmp[1][1] == tmp[2][2])
		t = max(t, tmp[0][0]);
	if (tmp[2][0] == tmp[1][1] && tmp[1][1] == tmp[0][2])
		t = max(t, tmp[2][0]);
	if (t == me) return 2;
	else if (t == 0) return 1;
	else return 0;
}
int dfs(int cur, int tr, int w) {
	if (dp[cur] != -1) return dp[cur];
	int ret = win(cur), t = 1, tmp = cur;
	if (ret != 1) return ret;
	if (tr) {
		ret = INF;
		for (int i = 0; i < 9; i++) {
			if (tmp % 3 == 0) {
				ret = min(ret, dfs(cur + t * w, tr ^ 1, w == 2 ? 1 : 2));
			}
			tmp /= 3;
			t *= 3;
		}
		if (ret == INF) return dp[cur] = 1;
		else return dp[cur] = ret;
	}
	else {
		ret = -1;
		for (int i = 0; i < 9; i++) {
			if (tmp % 3 == 0) {
				ret = max(ret, dfs(cur + t * w, tr ^ 1, w == 2 ? 1 : 2));
			}
			tmp /= 3;
			t *= 3;
		}
		if (ret == -1) return dp[cur] = 1;
		else return dp[cur] = ret;
	}
}
int main() {
	int cur = 0, t = 1, ret;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &b[i][j]);
			cur += t * b[i][j];
			t *= 3;
			if (b[i][j] == 1) x++;
			else if (b[i][j] == 2) o++;
		}
	}
	if (o < x) me = 2;
	else me = 1;

	ret = dfs(cur, 0, me);
	if (ret == 2) printf("W");
	else if (ret == 1) printf("D");
	else printf("L");

	return 0;
}