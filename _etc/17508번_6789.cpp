/*
BOJ 17508 - 6789
https://www.acmicpc.net/problem/17508
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[501][501];
int main() {
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	bool flag = false;
	for (int i = 0; i < n; i++) scanf("%s", st[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int r = n - i - 1, c = m - j - 1;
			if (st[i][j] == '7') {
				if (st[r][c] != '7' || (r == i && c == j)) return !printf("-1");
				cnt++;
			}
			else if (st[i][j] == '6') {
				if (st[r][c] == '6') cnt++;
				else if (st[r][c] != '9') return !printf("-1");
				if (r == i && c == j) return !printf("-1");
			}
			else if (st[i][j] == '9') {
				if (st[r][c] == '9') cnt++;
				else if (st[r][c] != '6') return !printf("-1");
				if (r == i && c == j) return !printf("-1");
			}
			else {
				if (st[r][c] != '8') return !printf("-1");
			}
			if (n % 2 && i == n / 2) {
				if (m % 2 && j == m / 2) {
					flag = true;
					break;
				}
				else if (m % 2 == 0 && j == m / 2 - 1) {
					flag = true;
					break;
				}
			}
		}
		if (n % 2 == 0 && i == n / 2 - 1) break;
		if (flag) break;
	}
	printf("%d", cnt);

	return 0;
}