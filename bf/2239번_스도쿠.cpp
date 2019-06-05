/*
BOJ 2239 (https://www.acmicpc.net/problem/2239)
0�� ��ġ(ä������ ���� ĭ)�� vec�迭�� ��� ����
���������� �ռ��� ���� ���ؾ� �ϹǷ� ��, ���ʿ������� ���ʷ� ���������� ����Ž��
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

vector<P> vec;
int board[9][9];
bool stop;
void dfs(int cur) {
	bool num[10];
	if (cur == vec.size()) {
		stop = true; return;
	}
	int r = vec[cur].first, c = vec[cur].second;
	int gcnt = 0;
	memset(num, false, sizeof(num));
	for (int k = 0; k < 9; k++) {
		// ����
		num[board[r][k]] = true;
		// ����
		num[board[k][c]] = true;
	}
	int nr = r / 3 * 3, nc = c / 3 * 3;
	// �׸�ĭ
	for (int k = nr; k < nr + 3; k++) {
		for (int h = nc; h < nc + 3; h++) {
			num[board[k][h]] = true;
		}
	}
	for (int k = 1; k <= 9; k++) {
		if (!num[k]) {
			board[r][c] = k;
			dfs(cur + 1);
			if (stop) return;
		}
	}
	board[r][c] = 0;
}
int main() {
	char x;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%c", &x);
			board[i][j] = x - '0';
			if (board[i][j] == 0) vec.push_back({ i,j });
		}
		getchar();
	}
	dfs(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) printf("%d", board[i][j]);
		printf("\n");
	}

	return 0;
}