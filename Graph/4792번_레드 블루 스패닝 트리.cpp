/*
BOJ 4792 - 레드 블루 스패닝 트리
https://www.acmicpc.net/problem/4792

증명 : jh05013님 블로그 https://blog.naver.com/jh05013/221321532329
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
int p[1001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
struct edge {
	int v, u, col;
};
vector<edge> edg;
int main() {
	int n, m, k, a, b, aa, bb;
	char c;
	while (scanf("%d %d %d", &n, &m, &k)) {
		if (!n && !m && !k) break;
		for (int i = 1; i <= n; i++)
			p[i] = i;
		edg.clear();
		aa = bb = 0;
		while (m--) {
			scanf(" %c %d %d", &c, &a, &b);
			edg.push_back({ a,b,c == 'B' });
		}
		sort(edg.begin(), edg.end(), [](edge a, edge b) {
			return a.col < b.col;
		});
		for (edge v : edg) {
			if (find(v.u) != find(v.v)) {
				merge(v.u, v.v);
				aa += v.col;
			}
		}
		for (int i = 1; i <= n; i++)
			p[i] = i;
		sort(edg.begin(), edg.end(), [](edge a, edge b) {
			return a.col > b.col;
		});
		for (edge v : edg) {
			if (find(v.u) != find(v.v)) {
				merge(v.u, v.v);
				bb += v.col;
			}
		}
		if (aa <= k && k <= bb) printf("1\n");
		else printf("0\n");
	}

	return 0;
}