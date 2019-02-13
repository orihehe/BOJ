/*
BOJ 15763 (https://www.acmicpc.net/problem/15763)
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */

int n, solo, team;
char b[3][4];
bool vic(char x, char y) {
	int i, j;
	bool xt, yt;
	for (i = 0; i < 3; i++) {
		xt = false, yt = false;
		for (j = 0; j < 3; j++) {
			if (b[i][j] == x) xt = true;
			if (b[i][j] == y) yt = true;
			if (b[i][j] != x && b[i][j] != y) {
				xt = false; break;
			}
		}
		if (xt && yt) return true;
	}
	for (i = 0; i < 3; i++) {
		xt = false, yt = false;
		for (j = 0; j < 3; j++) {
			if (b[j][i] == x) xt = true;
			if (b[j][i] == y) yt = true;
			if (b[j][i] != x && b[j][i] != y) {
				xt = false; break;
			}
		}
		if (xt && yt) return true;
	}
	xt = false, yt = false;
	if (b[0][0] == x) xt = true;
	if (b[0][0] == y) yt = true;
	if (b[1][1] == x) xt = true;
	if (b[1][1] == y) yt = true;
	if (b[2][2] == x) xt = true;
	if (b[2][2] == y) yt = true;
	if (b[0][0] != x && b[0][0] != y) xt = false;
	if (b[1][1] != x && b[1][1] != y)  xt = false;
	if (b[2][2] != x && b[2][2] != y)  xt = false;
	if (xt && yt) return true;
	xt = false, yt = false;
	if (b[0][2] == x) xt = true;
	if (b[0][2] == y) yt = true;
	if (b[1][1] == x) xt = true;
	if (b[1][1] == y) yt = true;
	if (b[2][0] == x) xt = true;
	if (b[2][0] == y) yt = true;
	if (b[0][2] != x && b[0][2] != y)  xt = false;
	if (b[1][1] != x && b[1][1] != y)  xt = false;
	if (b[2][0] != x && b[2][0] != y)  xt = false;
	if (xt && yt) return true;

	return false;
}
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < 26; i++) {
		if (vic(i + 'A', i + 'A')) solo++;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (vic(i + 'A', j + 'A')) team++;
		}
	}
	printf("%d\n%d", solo, team);

	return 0;
}