/*
백준 15685 (https://www.acmicpc.net/problem/15685)
다음 세대를 구하기 위해 문제에 나와있는 끝점에서부터 현재 세대의 드래곤 커브를 거꾸로 따라간다.
거꾸로 따라가며 구한 방향에 +1한 값은 시계방향 90도 돌린 것과 같다. 이 방향들이 새로 붙일 드래곤 커브와 같다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

//동 북 서 남
int cgo[4] = { 1,0,-1,0 };
int rgo[4] = { 0,-1,0,1 };
vector<int> dir;

int main() {
	int n, x, y, d, g, ans = 0;
	int board[101][101];
	scanf("%d", &n);
	memset(board, -1, sizeof(board));
	for (int i = 0; i < n; i++) {
		dir.clear();
		scanf("%d %d %d %d", &x, &y, &d, &g);
		// 0세대
		int nc = x + cgo[d], nr = y + rgo[d];
		board[x][y] = board[nc][nr] = i;
		dir.push_back((d + 1) % 4);
		// 1~g세대
		for (int j = 1; j <= g; j++) {
			// 저장된 방향들 뒤에서부터 값을 가져와 새 드래곤 커브 그려줌
			for (int k = dir.size() - 1; k >= 0; k--) {
				nc += cgo[dir[k]], nr += rgo[dir[k]];
				board[nc][nr] = i;
				dir.push_back((dir[k] + 1) % 4);
			}
		}
	}
	// -1이 아닌 값 드래곤 커브
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] != -1 && board[i + 1][j] != -1
				&& board[i][j + 1] != -1 && board[i + 1][j + 1] != -1) {
				ans++;
			}
		}
	}
	printf("%d", ans);

	return 0;
}