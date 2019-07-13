/*
BOJ 1396 - 크루스칼의 공
https://www.acmicpc.net/problem/1396
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct edge {
	int v, u, c;
	bool operator <(const edge &a) const {
		return c < a.c;
	}
} arr[100001];
int l[100001], r[100001], p[100001], sz[100001];
int n, m, q;
pii Q[100001], ans[100001];
vector<int> vec[100001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[a] = b;
	sz[b] += sz[a];
}
void kru() {
	int ap = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = i, sz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (find(arr[i].v) != find(arr[i].u)) {
			merge(arr[i].v, arr[i].u);
		}
		for (int idx : vec[i]) {
			if (find(Q[idx].first) == find(Q[idx].second)) {
				ans[idx] = { i, sz[find(Q[idx].first)] };
				r[idx] = i - 1;
			}
			else {
				l[idx] = i + 1;
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &arr[i].v, &arr[i].u, &arr[i].c);
	sort(arr, arr + m);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		r[i] = m - 1;
		scanf("%d %d", &Q[i].first, &Q[i].second);
	}
	while (true) {
		for (int i = 0; i < m; i++) vec[i].clear();
		int cnt = 0;
		for (int i = 0; i < q; i++) {
			if (l[i] <= r[i]) {
				int mid = (l[i] + r[i]) / 2;
				vec[mid].push_back(i);
				cnt++;
			}
		}
		if (!cnt) break;
		kru();
	}
	for (int i = 0; i < q; i++) {
		if (ans[i].second == 0) printf("-1\n");
		else printf("%d %d\n", arr[ans[i].first].c, ans[i].second);
	}

	return 0;
}