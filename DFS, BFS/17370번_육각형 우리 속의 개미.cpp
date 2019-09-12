/*
BOJ 17370 - 육각형 우리 속의 개미
https://www.acmicpc.net/problem/17370
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool vis[2500];
int ans = 0, n;
void dfs(int cur, int cnt, int p, bool w) {
	if (cnt == n + 1) {
		if (vis[cur])
			ans++;
		return;
	}
	if (vis[cur]) return;
	vis[cur] = true;
	cnt++;
	if (cur - 50 != p) dfs(cur - 50, cnt, cur, !w);
	if (cur + 50 != p) dfs(cur + 50, cnt, cur, !w);
	if (cur + (w ? 51 : -51) != p) dfs(cur + (w ? 51 : -51), cnt, cur, !w);
	vis[cur] = false;
}
int main() {
	scanf("%d", &n);
	dfs(1300, 0, 1300, true);
	printf("%d", ans/3);

	return 0;
}