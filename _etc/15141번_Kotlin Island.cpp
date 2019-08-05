/*
BOJ 15141 - Kotlin Island
https://www.acmicpc.net/problem/15141
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char ans[101][102];
int main() {
	int n, m, k, mx;
	scanf("%d %d %d", &n, &m, &k);
	memset(ans, '.', sizeof(ans));
	int nn = (n + 1) / 2, mm = (m + 1) / 2;
	if (k > nn*mm) return !printf("Impossible");
	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= mm; j++) {
			if (i*j == k) {
				i--, j--;
				bool fi = true, fj = true;
				for (int r = 0; r < n; r++) {
					if (i && !fi) {
						for (int c = 0; c < m; c++)
							ans[r][c] = '#';
						i--;
					}
					fi ^= true;
				}
				for (int c = 0; c < m; c++) {
					if (j && !fj) {
						for (int r = 0; r<n; r++)
							ans[r][c] = '#';
						j--;
					}
					fj ^= true;
				}
				for (int r = 0; r < n; r++) {
					for (int c = 0; c < m; c++) printf("%c", ans[r][c]);
					printf("\n");
				}
				return 0;
			}
		}
	}
	printf("Impossible");

	return 0;
}