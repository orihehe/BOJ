/*
BOJ 16978 - 수열과 쿼리 22
https://www.acmicpc.net/problem/16978
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pil pair<int,ll>
using namespace std;

/* 🐣🐥 */
ll tree[262144];
void update(int idx, int s, int e, int k, int val) {
	if (k < s || e < k) return;
	if (s == e) {
		tree[idx] = val; 
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll find(int idx, int s, int e, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[idx];
	return find(idx * 2, s, (s + e) / 2, l, r)
		+ find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
struct query {
	int k, i, j, idx;
	bool operator<(const query a) const {
		return k < a.k;
	}
};
vector<query> Q, UP;
vector<pil> ans;
int main() {
	int n, x, q, cm, a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(1, 0, n - 1, i, x);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm == 1) {
			a--;
			UP.push_back({ a,b });
		}
		else {
			scanf("%d", &c);
			b--, c--;
			Q.push_back({ a,b,c, i });
		}
	}
	sort(Q.begin(), Q.end());
	int ap = 0;
	for (query v : Q) {
		while (ap < v.k) {
			update(1, 0, n - 1, UP[ap].k, UP[ap].i);
			ap++;
		}
		ans.push_back({ v.idx,find(1,0,n - 1,v.i,v.j) });
	}
	sort(ans.begin(), ans.end());
	for (pil v : ans) printf("%lld\n", v.second);

	return 0;
}