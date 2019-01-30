/*
BOJ 16768 (https://www.acmicpc.net/problem/16768)

dfs�� ���� ���� ���� �̾��� �� ���� ����.
���� k�̻��� ������ �����Ǿ��ִٸ� rm���� �� ���� �ڸ��� 0���� �ٲ۴�.
��� Ž�� �� �Ʒ������� 0�� ���� ã���� ���� �ö󰡸鼭 0�̾ƴ� ���� ������ �ٲ��ش�.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int b[101][10];
int n, k, cnt, dcnt;
bool c[101][10];
bool c2[101][10];
int rgo[4] = { 0,1,0,-1 };
int cgo[4] = { 1,0,-1,0 };
void dfs(int rr, int cc) {
	c[rr][cc] = true;
	for (int i = 0; i < 4; i++) {
		int nr = rr + rgo[i], nc = cc + cgo[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= 10) continue;
		if (!c[nr][nc] && b[nr][nc] == b[rr][cc]) dfs(nr, nc);
	}
	dcnt++;
}
void rm(int rr, int cc) {
	c2[rr][cc] = true;
	for (int i = 0; i < 4; i++) {
		int nr = rr + rgo[i], nc = cc + cgo[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= 10) continue;
		if (!c2[nr][nc] && b[nr][nc] == b[rr][cc]) rm(nr, nc);
	}
	b[rr][cc] = 0;
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%1d", &b[i][j]);
		}
	}
	while (true) {
		dcnt = cnt = 0;
		memset(c, false, sizeof(c));
		memset(c2, false, sizeof(c2));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (!c[i][j] && b[i][j] != 0) {
					dcnt = 0;
					dfs(i, j);
					if (dcnt >= k) {
						rm(i, j);
						cnt++;
					}
				}
			}
		}
		for (int j = 0; j < 10; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (b[i][j] == 0) {
					int nr = i;
					while (true) {
						nr--;
						if (nr < 0 || b[nr][j] != 0) break;
					}
					if (nr >= 0) {
						b[i][j] = b[nr][j];
						b[nr][j] = 0;
					}
				}
			}
		}
		if (cnt == 0) break;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}