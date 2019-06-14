/*
BOJ 13470 - Programming Tutors
https://www.acmicpc.net/problem/13470

n^2로 모든 학생과 튜터의 거리를 구해둔다.
그리고나서 이분탐색으로 거리를 제한하여 이분매칭
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[101];
int n, B[101], vec[101][101], mid;
bool visited[101];
bool dfs(int cur) {
	visited[cur] = true;
	for (int i = 0; i < n; i++) {
		if (vec[cur][i] > mid) continue;
		if (B[i] == -1 || !visited[B[i]] && dfs(B[i])) {
			B[i] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int a, b, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = 0; j < n; j++) {
			vec[i][j] = abs(arr[j].first - a) + abs(arr[j].second - b);
		}
	}
	int l = 0, r = 400000000;
	while (l <= r) {
		mid = (l + r) / 2;
		int tmp = 0;
		memset(B, -1, sizeof(B));
		for (int i = 0; i < n; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) tmp++;
		}
		if (tmp == n) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	printf("%d", ans);

	return 0;
}