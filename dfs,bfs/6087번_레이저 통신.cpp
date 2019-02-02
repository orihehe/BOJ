/*
BOJ 6087 (https://www.acmicpc.net/problem/6087)

���� ��ġ���� �����¿�� �� �ſ��� �� ������ ���� �� ������ �� Ž�����ش�.
�̹� �տ��� �湮 �Ǿ��ִ� ���� ť�� �ٽ� ���� �ʾƵ� �ǰ�, C�� ���������� Ž��
*/
#include <cstdio>
#include <queue>
#define pii pair<int,int>
using namespace std;

char b[101][101];
bool visited[101][101];
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
int main() {
	int n, m, cr, cc, cnt = 0, s = 1;
	queue<pii> q;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] == 'C') {
				cr = i, cc = j;
			}
		}
	}
	visited[cr][cc] = true;
	q.push({ cr, cc });
	b[cr][cc] = '.';
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
			cnt++;
		}
		pii nx = q.front(); q.pop();
		if (b[nx.first][nx.second] == 'C') break;
		for (int i = 0; i < 4; i++) {
			int nr = nx.first + rgo[i], nc = nx.second + cgo[i];
			while (nr < m && nc < n && nr >= 0 && nc >= 0 && b[nr][nc] != '*') {
				if (!visited[nr][nc]) {
					q.push({ nr,nc });
					visited[nr][nc] = true;
				}
				nr += rgo[i]; nc += cgo[i];
			}
		}
		s--;
	}
	printf("%d", cnt - 1);

	return 0;
}