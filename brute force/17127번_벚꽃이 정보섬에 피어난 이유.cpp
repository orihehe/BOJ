/*
BOJ 17127 - 벚꽃이 정보섬에 피어난 이유
https://www.acmicpc.net/problem/17127
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[10], mx, n;
void dfs(int cur, int ans, int cnt) {
	if (cur == n) {
		if (cnt == 4) mx = max(mx, ans);
		return;
	}
	int sum = 1;
	for (int i = cur; i < n; i++) {
		sum *= arr[i];
		dfs(i + 1, ans + sum, cnt + 1);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0, 0);
	printf("%d", mx);

	return 0;
}