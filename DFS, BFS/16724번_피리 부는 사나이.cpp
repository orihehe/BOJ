/*
🐣🐥
BOJ 16724 (https://www.acmicpc.net/problem/16724)

방문되지 않은 곳을 탐색했을 때 모두 새롭다면 그 곳에 하나의 Safe Zone을 설치해야한다.
이미 방문되어있는데 현재 dfs에서 방문한게 아니라면 카운트하지 않는다.
*/
#include <cstdio>
using namespace std;

char b[1001][1001];
int vst[1001][1001];
bool suc;
void dfs(int r, int c, int v) {
	vst[r][c] = v;
	if (b[r][c] == 'D') {
		if (vst[r + 1][c] != 0 && vst[r + 1][c] != v) suc = true;
		if (suc) return;
		if (vst[r + 1][c] == 0)
			dfs(r + 1, c, v);
	}
	else if (b[r][c] == 'R') {
		if (vst[r][c + 1] != 0 && vst[r][c + 1] != v) suc = true;
		if (suc) return;
		if (vst[r][c + 1] == 0)
			dfs(r, c + 1, v);
	}
	else if (b[r][c] == 'L') {
		if (vst[r][c - 1] != 0 && vst[r][c - 1] != v) suc = true;
		if (suc) return;
		if (vst[r][c - 1] == 0)
			dfs(r, c - 1, v);
	}
	else if (b[r][c] == 'U') {
		if (vst[r - 1][c] != 0 && vst[r - 1][c] != v) suc = true;
		if (suc) return;
		if (vst[r - 1][c] == 0)
			dfs(r - 1, c, v);
	}
}
int main() {
	int n, m, cnt = 1, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vst[i][j]) {
				suc = false;
				dfs(i, j, cnt);
				if (!suc)
					ans++;
				cnt++;
			}
		}
	}
	printf("%d", ans);

	return 0;
}