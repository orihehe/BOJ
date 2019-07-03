/*
BOJ 16358 - Cosmetic Survey
https://www.acmicpc.net/problem/16358

d(x,y) > d(y,x) 인 x->y간선을 추가해둔다.
그리고나서 모든 x,y쌍의 값을 플로이드워셜로 구해 문제를 푼다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int p[501], cm[501][501], d[501][501], grp[501][501];
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &cm[i][j]);
			if (!cm[i][j]) cm[i][j] = 1000001;
		}
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			a = b = 0;
			for (int k = 0; k < n; k++) {
				if (cm[k][i] < cm[k][j]) a++;
				if (cm[k][i] > cm[k][j]) b++;
			}
			if (a > b) d[i][j] = a;
			if (b > a) d[j][i] = b;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) d[i][i] = 501;
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));
			}
		}
	}

	for (int i = 0; i < m; i++) {
		bool suc = true;
		for (int j = 0; j < m; j++) {
			if (i == j) continue;
			if (d[j][i] > d[i][j]) {
				suc = false;
				break;
			}
		}
		if (suc)
			printf("%d ", i + 1);
	}

	return 0;
}