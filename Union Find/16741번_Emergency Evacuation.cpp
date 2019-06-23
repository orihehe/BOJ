/*
BOJ 16741 - Emergency Evacuation
https://www.acmicpc.net/problem/16741

0번줄에서부터 출구 앞까지 가는 최소 시간을 구해 그 시간이 이미 차있다면
최대한 바로 뒤에 붙도록 배치해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
bool w[501][1001];
int p[500505];
int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int r, s, m, a, b, ri, tt, ans = 0, cur;
	scanf("%d %d %d", &r, &s, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		a--, b--;
		w[a][b] = true;
	}
	memset(p, -1, sizeof(p));
	for (int i = 0; i < r; i++) {
		ri = s;
		tt = 0;
		for (int j = s - 1; j >= 0; j--) {
			tt++;
			if (w[i][j]) {
				cur = find(r - i + tt);
				ans = max(ans, cur);
				merge(cur, cur + 1);
			}
			else if (w[i][ri]) {
				cur = find(r - i + tt);
				ans = max(ans, cur);
				merge(cur, cur + 1);
				w[i][ri] = false;
			}
			if (!w[i][ri]) ri++;
		}
		while (ri < 2 * s) {
			tt++;
			if (w[i][ri++]) {
				cur = find(r - i + tt);
				merge(cur, cur + 1);
				ans = max(ans, cur);
			}
		}
	}
	printf("%d", ans);

	return 0;
}