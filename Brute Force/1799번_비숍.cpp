/*
BOJ 1799 (https://www.acmicpc.net/problem/1799)
n-queen문제에서는 좌우이동도 가능해서 가로나 세로 기준으로 한 말을 두고 dfs로 탐색하였다.
이번 문제는 대각선으로만 이동이 가능한 말 이므로 대각선을 기준으로 풀었다.
i번째 대각선에서 말을 놓을 여러곳중 한 곳에 놓았을 경우마다 탐색을 해줬다.
만약 이 대각선상에 놓을 곳이 없다면 놓지 않고 다음 대각선으로 넘어갔다. (740ms)

내 풀이가 시간이 많이 나와서 다른 사람 풀이를 찾아봤는데 대부분 흰칸, 검은칸을 나눠 생각해 풀었다.
나누지 않고 단순히 접근하면 O(2^(N*N)), 분리해서 풀면 O(2^(N/2*N/2))가 나온다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, board[11][11], maxN;
bool loc[11][11], visited[11][11];
void dfs(int cur,int cnt) {
	if (cur == 2*n-1) {
		maxN = max(maxN, cnt);
		return;
	}
	int r,c, gg = 0;
	if (cur < n) {
		r = 0, c = cur;
	}
	else {
		r = cur-n+1, c = n-1;
	}
	while (c >= 0 && r>=0 && c<n && r<n) {
		if (loc[r][c]) {
			int nr = r - 1, nc = c - 1;
			bool go = true;
			// 왼쪽위 대각 검사
			while (nr >= 0 && nc >= 0) {
				if (visited[nr][nc]) go = false;
				nr--, nc--;
			}
			if (go) {
				visited[r][c] = true;
				dfs(cur + 1, cnt + 1);
				visited[r][c] = false;
				gg++;
			}
		}
		c--; r++;
	}
	if (gg == 0) dfs(cur + 1, cnt);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) loc[i][j] = true;
		}
	}
	dfs(0, 0);
	printf("%d", maxN);

	return 0;
}