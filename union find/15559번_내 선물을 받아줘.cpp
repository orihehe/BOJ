/*
BOJ 15559 - 내 선물을 받아줘
https://www.acmicpc.net/problem/15559

현재 칸에서의 방향으로 향한 칸과 merge
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char b[1001][1001];
int rgo[4] = { -1,0,1,0 }, cgo[4] = { 0,1,0,-1 };
int apb[150];
int p[1000002];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	p[b] = a;
}
int main() {
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < m*n; i++) p[i] = i;
	apb['S'] = 2;
	apb['W'] = 3;
	apb['E'] = 1;
	apb['N'] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int r = i + rgo[apb[b[i][j]]], c = j + cgo[apb[b[i][j]]];
			if (r < 0 || c < 0 || r >= n || c >= m) continue;
			merge(i*m + j % m, r*m + c % m);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (find(i*m + j % m) == i * m + j % m) cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}