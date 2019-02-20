/*
BOJ 11975 (https://www.acmicpc.net/problem/11975)

울타리를 세운 부분을 1로 표시한다. 단, 울타리를 1칸이 아닌 2칸으로 세운다.
bfs로 0으로 이어져있는 부분을 탐색하여 구역을 세준다.
*/
#include <cstdio>
#include <cstring>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[4010][4010];
int rgo[4] = { 1,0,-1,0 };
int cgo[4] = { 0,1,0,-1 };
queue<pii> q;
void bfs(int r, int c) {
	arr[r][c] = 1;
	q.push({ r,c });
	while (!q.empty()) {
		r = q.front().first, c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + rgo[i], nc = c + cgo[i];
			if (nr < 0 || nc < 0 || nr >= 4008 || nc >= 4008) continue;
			if (arr[nr][nc] == 0) {
				arr[nr][nc] = 1;
				q.push({ nr,nc });
			}
		}
	}
}
int main() {
	int n, len, cnt = 0, d, x = 2000, y = 2000;
	char st[1001];
	scanf("%d %s", &n, st);
	len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (st[i] == 'N') d = 0;
		else if (st[i] == 'E') d = 1;
		else if (st[i] == 'S') d = 2;
		else if (st[i] == 'W') d = 3;
		x += rgo[d], y += cgo[d];
		arr[x][y] = 1;
		x += rgo[d], y += cgo[d];
		arr[x][y] = 1;
	}
	for (int i = 0; i < 4008; i++) {
		for (int j = 0; j < 4008; j++) {
			if (arr[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	printf("%d", cnt - 1);

	return 0;
}