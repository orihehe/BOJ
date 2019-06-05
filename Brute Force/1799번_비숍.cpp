/*
BOJ 1799 (https://www.acmicpc.net/problem/1799)
n-queen���������� �¿��̵��� �����ؼ� ���γ� ���� �������� �� ���� �ΰ� dfs�� Ž���Ͽ���.
�̹� ������ �밢�����θ� �̵��� ������ �� �̹Ƿ� �밢���� �������� Ǯ����.
i��° �밢������ ���� ���� �������� �� ���� ������ ��츶�� Ž���� �����.
���� �� �밢���� ���� ���� ���ٸ� ���� �ʰ� ���� �밢������ �Ѿ��. (740ms)

�� Ǯ�̰� �ð��� ���� ���ͼ� �ٸ� ��� Ǯ�̸� ã�ƺôµ� ��κ� ��ĭ, ����ĭ�� ���� ������ Ǯ����.
������ �ʰ� �ܼ��� �����ϸ� O(2^(N*N)), �и��ؼ� Ǯ�� O(2^(N/2*N/2))�� ���´�.
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
			// ������ �밢 �˻�
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