/*
BOJ 17207 - 돌려막기
https://www.acmicpc.net/problem/17207
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
char name[5][8] = { "Inseo","Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
pii w[5];
int main() {
	int a[5][5], b[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &b[i][j]);

	for (int i = 0; i < 5; i++) {
		w[i].second = i;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				w[i].first += a[i][k] * b[k][j];
			}
		}
	}
	sort(w, w + 5);
	int mn = w[0].first;
	for (int i = 4; i >= 0; i--)
		if (mn == w[i].first) {
			printf("%s", name[w[i].second]);
			break;
		}

	return 0;
}