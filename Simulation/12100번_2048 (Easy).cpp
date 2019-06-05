/*
네 가지 방향마다 먼저 움직여야하는 블록이 달라 for문을 따로 처리해줬다.
move함수에서 한 블럭씩 해당 방향으로 움직여준다
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, maxNum, s, cnt;
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
vector<vector<int>> board, cur, tmp;
bool no[20][20];
void move(int r, int c, int dir) {
	int nr=r, nc=c, num;
	num = tmp[r][c];
	while (true) {
		nr += rgo[dir], nc += cgo[dir];
		if (nr >= n || nc >= n || nr < 0 || nc < 0) {
			nr -= rgo[dir], nc -= cgo[dir];
			break;
		}
		if (tmp[nr][nc] != 0) break;
	}
	if (r == nr && c == nc) return; // 제자리
	//빈곳이라면
	if (tmp[nr][nc] == 0) {
		tmp[r][c] = 0;
		tmp[nr][nc] = num;
	}
	//같은 수가 있는데 합쳐진 수가 아니라면
	else if (tmp[nr][nc] == num && !no[nr][nc]) {
		no[nr][nc] = true;
		tmp[r][c] = 0;
		tmp[nr][nc] = num * 2;
	}
	//한칸 뒤로 이동
	else {
		tmp[r][c] = 0;
		tmp[nr - rgo[dir]][nc - cgo[dir]] = num;
	}
	maxNum = max(maxNum, tmp[nr][nc]);
}

int main() {
	int x;
	queue<vector<vector<int>>> q;
	scanf("%d", &n);
	board.resize(n), cur.resize(n), tmp.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			board[i].push_back(x);
		}
	}
	maxNum = board[0][0];
	q.push(board);
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
			cnt++;
		}
		if (cnt > 5)break;
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			tmp = cur;
			memset(no, false, sizeof(no));
			if (i == 0) {
				for (int r = 0; r < n; r++) {
					for (int c = 0; c < n; c++) {
						if (tmp[r][c] == 0) continue;
						move(r, c, i);
					}
				}
			}
			else if (i == 1) {
				for (int r = 0; r < n; r++) {
					for (int c = n-1; c >= 0; c--) {
						if (tmp[r][c] == 0) continue;
						move(r, c, i);
					}
				}
			}
			else if (i == 2) {
				for (int r = 0; r < n; r++) {
					for (int c = n - 1; c >= 0; c--) {
						if (tmp[c][r] == 0) continue;
						move(c, r, i);
					}
				}
			}
			else if (i == 3) {
				for (int r = 0; r < n; r++) {
					for (int c = 0; c < n; c++) {
						if (tmp[c][r] == 0) continue;
						move(c, r, i);
					}
				}
			}
		}
		s--;
	}
	printf("%d", maxNum);

	return 0;
}