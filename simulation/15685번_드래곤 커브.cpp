/*
���� 15685 (https://www.acmicpc.net/problem/15685)
���� ���븦 ���ϱ� ���� ������ �����ִ� ������������ ���� ������ �巡�� Ŀ�긦 �Ųٷ� ���󰣴�.
�Ųٷ� ���󰡸� ���� ���⿡ +1�� ���� �ð���� 90�� ���� �Ͱ� ����. �� ������� ���� ���� �巡�� Ŀ��� ����.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

//�� �� �� ��
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
		// 0����
		int nc = x + cgo[d], nr = y + rgo[d];
		board[x][y] = board[nc][nr] = i;
		dir.push_back((d + 1) % 4);
		// 1~g����
		for (int j = 1; j <= g; j++) {
			// ����� ����� �ڿ������� ���� ������ �� �巡�� Ŀ�� �׷���
			for (int k = dir.size() - 1; k >= 0; k--) {
				nc += cgo[dir[k]], nr += rgo[dir[k]];
				board[nc][nr] = i;
				dir.push_back((dir[k] + 1) % 4);
			}
		}
	}
	// -1�� �ƴ� �� �巡�� Ŀ��
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