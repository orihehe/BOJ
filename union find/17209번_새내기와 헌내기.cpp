/*
BOJ 17209 - 새내기와 헌내기
https://www.acmicpc.net/problem/17209

적이 되어야 하는 참가자를 적으로 만들어준 뒤 두 팀중 사람이 많은 쪽을 헌내기로 한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char b[2002][2002];
int p[4001], sz[4001];
bool used[4001];
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[a] = b;
	sz[b] += sz[a];
}
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
		sz[i] = 1;
	}
	for (int i = 0; i < 2 * n; i++) p[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] - '0') {
				merge(i, j + n);
				merge(i + n, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int c = find(i), d = find(i + n);
		if (used[c]) continue;
		used[c] = used[d] = true;
		ans += max(sz[c], sz[d]);
	}
	printf("%d", ans);

	return 0;
}