/*
BOJ 14457 (https://www.acmicpc.net/problem/14457)
맨 좌측 위를 포함한 직사각형 범위를 토글하는데, 횟수를 최소로 하여 모든 상태를 0으로 만들어야 한다.
거꾸로 ㄴ모양으로 0,0 에서 먼곳부터 1이 있는지 탐색하여 토글하였다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char b[11][11];
void cha(int r, int c) { // 0은 1로 1은 0으로 0,0 r,c범위 토글
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			if (b[i][j] == '0') b[i][j] = '1';
			else b[i][j] = '0';
		}
	}
}
int main() {
	int n, cur, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	cur = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (b[i][j] == '1') {
				cha(i, j);
				cnt++;
			}
		}
		for (int j = i - 1; j >= 0; j--) {
			if (b[j][i] == '1') {
				cha(j, i);
				cnt++;
			}
		}
	}
	printf("%d", cnt);

	return 0;
}