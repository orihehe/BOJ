#include <cstdio>
#include <cstring>
using namespace std;

int n;
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
int board[20][20];
bool no[20][20];
void move(int r, int c, int dir) {
	int nr=r, nc=c, num;
	num = board[r][c];
	while (true) {
		nr += rgo[dir], nc += cgo[dir];
		if (nr >= n || nc >= n || nr < 0 || nc < 0) {
			nr -= rgo[dir], nc -= cgo[dir];
			break;
		}
		if (board[nr][nc] != 0) break;
	}
	if (r == nr && c == nc) return;
	if (board[nr][nc] == 0) {
		board[r][c] = 0;
		board[nr][nc] = num;
	}
	else if (board[nr][nc] == num && !no[nr][nc]) {
		no[nr][nc] = true;
		board[r][c] = 0;
		board[nr][nc] = num * 2;
	}
	else {
		board[r][c] = 0;
		board[nr - rgo[dir]][nc - cgo[dir]] = num;
	}
}

int main() {
	int t;
	char dir[6];
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %s", &n, dir);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		memset(no, false, sizeof(no));
		if (strcmp(dir, "up") == 0) {
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					if (board[r][c] == 0) continue;
					move(r, c, 0);
				}
			}
		}
		else if (strcmp(dir, "right") == 0) {
			for (int r = 0; r < n; r++) {
				for (int c = n - 1; c >= 0; c--) {
					if (board[r][c] == 0) continue;
					move(r, c, 1);
				}
			}
		}
		else if (strcmp(dir, "down") == 0) {
			for (int r = 0; r < n; r++) {
				for (int c = n - 1; c >= 0; c--) {
					if (board[c][r] == 0) continue;
					move(c, r, 2);
				}
			}
		}
		else if (strcmp(dir, "left") == 0) {
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					if (board[c][r] == 0) continue;
					move(c, r, 3);
				}
			}
		}

		printf("Case #%d:\n", tt);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) printf("%d ", board[i][j]);
			printf("\n");
		}
	}

	return 0;
}