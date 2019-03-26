/*
BOJ 14528 - Bovine Genomics (Silver)
https://www.acmicpc.net/problem/14528
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[1001][51];
int ap[128];
bool use[445];
int idx[3];
int n, m, ans;
void go(int cnt, int cur) {
	if (cnt == 3) {
		bool suc = true;
		memset(use, false, sizeof(use));
		for (int i = 0; i < n; i++) {
			use[ap[st[i][idx[0]]] + ap[st[i][idx[1]]] * 10 + ap[st[i][idx[2]]] * 100] = true;
		}
		for (int i = n; i < n * 2; i++) {
			if (use[ap[st[i][idx[0]]] + ap[st[i][idx[1]]] * 10 + ap[st[i][idx[2]]] * 100])
				suc = false;
		}
		if (suc) ans++;
		return;
	}
	for (int i = cur; i < m; i++) {
		idx[cnt] = i;
		go(cnt + 1, i + 1);
	}
}
int main() {
	ap['A'] = 1;
	ap['C'] = 2;
	ap['G'] = 3;
	ap['T'] = 4;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * 2; i++) {
		scanf("%s", st[i]);
	}
	go(0, 0);
	printf("%d", ans);

	return 0;
}