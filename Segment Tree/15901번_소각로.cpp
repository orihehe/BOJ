/*
BOJ 15901 - 소각로
https://www.acmicpc.net/problem/15901

lazy배열은 구간에 (소각 + 재활용 한 쓰레기 개수, L) 을 저장,
tree배열은 대기열의 구간 합을 저장해둔다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pli pair<ll,int>
#define MAX 1500000
using namespace std;

/* 🐣🐥 */
pli lazy[1048577];
ll tree[4194305], rm;
int wait[MAX];
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	tree[idx] += val;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
}
void up(int idx, int s, int e, int l, int r, pli w) {
	if (r<s || l>e) return;
	if (l <= s && e <= r) {
		lazy[idx] = w;
		return;
	}
	up(idx * 2, s, (s + e) / 2, l, r, w);
	up(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, w);
}
pli whr(int idx, int s, int e, int k) {
	if (k<s || k>e) return { 0,0 };
	pli a = lazy[idx];
	if (s == e) return a;
	pli b = whr(idx * 2, s, (s + e) / 2, k);
	pli c = whr(idx * 2 + 1, (s + e) / 2 + 1, e, k);
	b = max(b, c);
	return max(a, b);
}
int worm(int idx, int s, int e, ll val) {
	if (s == e) return wait[s];
	if (tree[idx * 2] >= val) return worm(idx * 2, s, (s + e) / 2, val);
	else return worm(idx * 2 + 1, (s + e) / 2 + 1, e, val - tree[idx * 2]);
}
int main() {
	int n, m, k, q, cm, a, b;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &wait[i]);
		update(1, 0, MAX, i, 1);
		if (i + 1 <= m) {
			up(1, 1, m, i + 1, i + 1, pli(i, i + 1));
		}
	}
	rm = min(m, n);
	while (q--) {
		scanf("%d", &cm);
		if (cm == 1) {
			scanf("%d %d", &a, &b);
			ll tmp = tree[1] - rm;
			if (tmp >= b - a + 1) {
				up(1, 1, m, a, b, pli(rm, a));
				rm += b - a + 1;
			}
			else {
				if (tmp > 0)
					up(1, 1, m, a, a + tmp - 1, pli(rm, a));
				up(1, 1, m, a + tmp, b, pli(rm, 0));

				rm = tree[1];
			}
		}
		else if (cm == 2) {
			scanf("%d", &a);
			pli tmp = whr(1, 1, m, a);
			if (tmp.second == 0) printf("0 ");
			else printf("%d ", worm(1, 0, MAX, tmp.first + a - tmp.second + 1));
		}
		else if (cm == 3) {
			scanf("%d %d", &a, &b);
			wait[n] = a;
			update(1, 0, MAX, n, b);
			n++;
		}
		else if (cm == 4) {
			ll tmp;
			scanf("%lld", &tmp);
			rm += tmp;
		}
	}
	printf("\n");
	for (int i = 1; i <= m; i++) {
		pli tmp = whr(1, 1, m, i);
		if (tmp.second == 0) printf("0 ");
		else printf("%d ", worm(1, 0, MAX, tmp.first + i - tmp.second + 1));
	}

	return 0;
}