/*
BOJ 14531 (https://www.acmicpc.net/problem/14531)
같은 포지션에서 Spotty와 Plain 소에게 겹치는 유전자가 없으면 카운트 해준다.
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
		// 모두 살펴봤지만 겹치는거 없을 때
		if (j == 26) cnt++;
	}
	printf("%d", cnt);

	return 0;
}