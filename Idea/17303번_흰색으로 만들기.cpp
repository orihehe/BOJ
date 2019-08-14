/*
BOJ 17302 - 흰색으로 만들기
https://www.acmicpc.net/problem/17302

체스판의 검은 지점을 나중에 바꾼다고 생각한다.
그렇다면 검은 지점들 주위 흰 지점 개수를 알고
검은지점은 2,3번만 사용한다면 흰 지점을 어떤 색으로 만들어야 할 지가 정해진다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char b[2001][2001];
int ans[2001][2001], tmp[2001][2001];
int rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
int n, m;
void tog(int i, int j) {
	for (int k = 0; k < 4; k++) {
		int nr = i + rgo[k], nc = j + cgo[k];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m)
			continue;
		if (b[nr][nc] == 'W') b[nr][nc] = 'B';
		else b[nr][nc] = 'W';
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", b[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				for (int k = 0; k < 4; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= n || nc >= m)
						continue;
					tmp[nr][nc]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2) {
				if (tmp[i][j] % 2) {
					if (b[i][j] == 'W') {
						ans[i][j] = 3;
						tog(i, j);
					}
					else ans[i][j] = 1;
				}
				else {
					if (b[i][j] == 'W') ans[i][j] = 1;
					else {
						ans[i][j] = 3;
						tog(i, j);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				if (b[i][j] == 'W') ans[i][j] = 2;
				else ans[i][j] = 3;
			}
		}
	}
	printf("1\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}