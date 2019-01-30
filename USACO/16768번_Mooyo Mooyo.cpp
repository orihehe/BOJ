/*
BOJ 16768 (https://www.acmicpc.net/problem/16768)

dfs로 같은 색을 가진 이어진 블럭 수를 센다.
만약 k이상의 블럭으로 구성되어있다면 rm에서 그 블럭들 자리를 0으로 바꾼다.
모두 탐색 후 아래서부터 0인 것을 찾으면 위로 올라가면서 0이아닌 블럭을 만나면 바꿔준다.
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