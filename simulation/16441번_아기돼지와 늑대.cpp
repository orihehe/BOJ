/*
���� �� Ǯ�� ����� �����ε� ���� ����Ż��2 ������ Ǯ�� �������� ���� ó���� �ذ��ߴ�.
���� ����Ż��2 - https://www.acmicpc.net/problem/13460
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[101][101];
//�� �� �� ��
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
int n, m;
char map[101][101];
void dfs(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i];
		int nc = c + cgo[i];
		while (map[nr][nc] == '+') { // �������� �����̸� �� �̲�����
			nr += rgo[i];
			nc += cgo[i];
		}
		if (map[nr][nc] == '#') { // �̲������� ���̸� ��ĭ �ڷ�
			nr -= rgo[i];
			nc -= cgo[i];
		}
		if (!visited[nr][nc]) {
			dfs(nr, nc);
		}
	}
}

int main() {
	queue<pair<int, int>> q;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W') {
				q.push({ i,j });
			}
		}
	}
	pair<int, int> tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		dfs(tmp.first, tmp.second);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.') {
				if (!visited[i][j]) {
					printf("P");
				}
				else printf(".");
			}
			else printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}