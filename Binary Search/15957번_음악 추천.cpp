/*
BOJ 15957 - 음악 추천
https://www.acmicpc.net/problem/15957
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct info {
	int v, u, c;
} Q[100001];
int ans[100001], l[100001], r[100001], idx[100001], ch[100001], ccc;
int song[100001];
ll tree[262144];
vector<int> my[100001], sg[100001];
int dfs(int cur) {
	idx[cur] = ccc++;
	int cn = 0;
	for (int v : my[cur]) {
		cn += dfs(v);
	}
	ch[cur] = cn;
	return cn + 1;
}
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
	int n, m, to, a;
	scanf("%d %d %d", &n, &m, &to);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		a--;
		my[a].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		sg[--a].push_back(i);
		song[i] = a;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &Q[i].v, &Q[i].u, &Q[i].c);
		Q[i].u--;
	}
	sort(Q, Q + m, [](info aa, info bb) {
		return aa.v < bb.v;
	});
	dfs(0);
	for (int i = 0; i < n; i++) r[i] = m - 1;
	while (true) {
		vector<int> vec[100001];
		memset(tree, 0, sizeof(tree));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (l[i] <= r[i]) {
				vec[(l[i] + r[i]) / 2].push_back(i);
				cnt++;
			}
		}
		if (!cnt) break;
		for (int i = 0; i < m; i++) {
			update(1, 0, m - 1, idx[Q[i].u], idx[Q[i].u] + ch[Q[i].u], Q[i].c / (ch[Q[i].u] + 1));
			for (int v : vec[i]) {
				ll h = 0;
				for (int mm : sg[v]) {
					h += hap(1, 0, m - 1, idx[mm]);
					if (h > 1LL * to*sg[v].size()) break;
				}
				if (h > 1LL * to*sg[v].size()) {
					ans[v] = Q[i].v;
					r[v] = i - 1;
				}
				else l[v] = i + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[song[i]]) printf("%d\n", ans[song[i]]);
		else printf("-1\n");
	}

	return 0;
}