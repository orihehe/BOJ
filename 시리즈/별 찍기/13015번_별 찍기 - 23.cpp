/*
BOJ 13015 - 별 찍기 - 23
https://www.acmicpc.net/problem/13015
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char prt[201][401];
int n;
void le(int i, int j) {
	for (int k = 0; k < n - 1; k++)
		prt[i++][j++] = '*';
	for (int k = 0; k < n - 1; k++)
		prt[i++][j--] = '*';
}
void ri(int i, int j, char x) {
	for (int k = 0; k < n - 1; k++)
		prt[i++][j--] = x;
	for (int k = 0; k < n - 1; k++)
		prt[i++][j++] = x;
}
int main() {
	memset(prt, ' ', sizeof(prt));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		prt[0][i] = prt[0][i + n * 3 - 3] = '*';
		prt[n * 2 - 2][i] = prt[n * 2 - 2][i + n * 3 - 3] = '*';
	}
	le(0, 0); le(0, n - 1);
	ri(0, n * 3 - 3, '*'); ri(0, n * 3 - 4 + n, '*');
	ri(0, n * 3 - 3 + n, '\0');
	prt[2 * n - 2][n * 3 - 3 + n] = '\0';
	for (int i = 0; i < 2 * n - 1; i++)
		printf("%s\n", prt[i]);

	return 0;
}