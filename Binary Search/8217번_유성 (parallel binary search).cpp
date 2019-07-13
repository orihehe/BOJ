/*
BOJ 8217 - 유성
https://www.acmicpc.net/problem/8217
*/
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct info {
	int v, u, c;
} Q[300001];
int ans[300001], mx[300001], l[300001], r[300001];
ll tree[1048576];
vector<int> my[300001];
void update(int idx, int s, int e, int l, int r, int val) {
	if (e<l || s> r) return;
	if (l <= s && e <= r) {
		tree[idx] += val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, l, r, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
}
ll hap(int idx, int s, int e, int k) {
	if (k<s || k>e) return 0;
	if (s == e) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, k)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, k) + tree[idx];
}
int main() {
	int n, m, a, q;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		a--;
		my[a].push_back(i);
	}
	for (int i = 0; i < n; i++) scanf("%d", &mx[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &Q[i].v, &Q[i].u, &Q[i].c);
		Q[i].v--, Q[i].u--;
	}
	for (int i = 0; i < n; i++) r[i] = q - 1;
	while (true) {
		vector<int> vec[300001];
		memset(tree, 0, sizeof(tree));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (l[i] <= r[i]) {
				vec[(l[i] + r[i]) / 2].push_back(i);
				cnt++;
			}
		}
		if (!cnt) break;
		for (int i = 0; i < q; i++) {
			if (Q[i].v <= Q[i].u) {
				update(1, 0, m - 1, Q[i].v, Q[i].u, Q[i].c);
			}
			else {
				update(1, 0, m - 1, Q[i].v, m - 1, Q[i].c);
				update(1, 0, m - 1, 0 ,Q[i].u, Q[i].c);
			}
			for (int v : vec[i]) {
				ll h = 0;
				for (int mm : my[v]) {
					h += hap(1, 0, m - 1, mm);
					if (h >= mx[v]) break;
				}
				if (h >= mx[v]) {
					ans[v] = i + 1;
					r[v] = i - 1;
				}
				else l[v] = i + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i]) printf("%d\n", ans[i]);
		else printf("NIE\n");
	}

	return 0;
}