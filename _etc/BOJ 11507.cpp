/*
BOJ 11507 - 카드셋트
https://www.acmicpc.net/problem/11507
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char idx[128];
bool card[4][14];
int ans[4] = { 13,13,13,13 };
int main() {
	char x;
	int y;
	idx['P'] = 0, idx['K'] = 1, idx['H'] = 2, idx['T'] = 3;
	while (scanf("%c%2d", &x, &y) == 2) {
		if (card[idx[x]][y]) return !printf("GRESKA");
		else {
			card[idx[x]][y] = true;
			ans[idx[x]]--;
		}
	}
	for (int i = 0; i < 4; i++) printf("%d ", ans[i]);

	return 0;
}