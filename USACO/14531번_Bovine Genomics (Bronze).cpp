/*
BOJ 14531 (https://www.acmicpc.net/problem/14531)
���� �����ǿ��� Spotty�� Plain �ҿ��� ��ġ�� �����ڰ� ������ ī��Ʈ ���ش�.
*/
#include <cstdio>
using namespace std;

bool s[100][26], p[100][26];
int main() {
	int n, m, cnt = 0;
	char spo[100][101], pla[100][101];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", spo[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", pla[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			s[i][spo[j][i] - 'A'] = true;
			p[i][pla[j][i] - 'A'] = true;
		}
	}
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < 26; j++) {
			if (s[i][j] && p[i][j]) break;
		}
		// ��� ��������� ��ġ�°� ���� ��
		if (j == 26) cnt++;
	}
	printf("%d", cnt);

	return 0;
}