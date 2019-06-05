/*
BOJ 15326 - Usmjeri
https://www.acmicpc.net/problem/15326

같은 간선을 이용하는 경로는 merge시켜주어 2^집합개수 를 출력하는 문제이다.

일단 한 정점에 대해 dfs를 돌려 깊이를 정해주고, 
각 정점에서 루트쪽으로 올라가는 간선은 하나이니 그 간선을 현재 정점으로 표현해준다.

a-lca, b-lca 경로는 다른 방향이어야하니
a,b에 대하여 a->lca, b->lca의 경로를 friend-merge시켜주고, 
a와 b를 enemy-merge 시켜준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
vector<int> vec[300001];
int n, sps[300001][20], dep[600001], p[600001], pp[300001];
int find(int a, int w[]) {
	if (a == w[a]) return a;
	return w[a] = find(w[a], w);
}
void merge(int a, int b, int w[]) {
	a = find(a, w), b = find(b, w);
	if (a == b) return;

	if (dep[a] > dep[b]) swap(a, b);
	w[b] = a;
}
bool valid() {
	for (int i = 1; i <= n; i++) {
		if (find(i, p) == find(i + n, p)) return false;
	}
	return true;
}
void dfs(int cur, int cnt) {
	dep[cur] = cnt;
	for (int i = 1; i < 20; i++) {
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	}
	for (int v : vec[cur]) {
		if (!dep[v]) {
			sps[v][0] = cur;
			dfs(v, cnt + 1);
		}
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 19; i >= 0; i--) {
		if (dep[a] <= dep[sps[b][i]]) {
			b = sps[b][i];
		}
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (sps[b][i] != sps[a][i]) {
			b = sps[b][i];
			a = sps[a][i];
		}
	}
	return sps[a][0];
}
void sol(int a, int b, int ca) {
	while (dep[ca] < dep[a]) {
		if (ca != sps[a][0]) {
			merge(a, sps[a][0], p);
			merge(a, sps[a][0], pp);
		}
		a = find(sps[a][0], p);
	}
	while (dep[ca] < dep[b]) {
		if (ca != sps[b][0]) {
			merge(b, sps[b][0], p);
			merge(b, sps[b][0], pp);
		}
		b = find(sps[b][0], p);
	}
}
int main() {
	int m, a, b;
	ll ans = 1;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) pp[i] = i;
	for (int i = n + 1; i <= 2 * n; i++) dep[i] = 300001;
	dfs(1, 1);
	while (m--) {
		scanf("%d %d", &a, &b);
		int ca = lca(a, b);
		sol(find(a,p), find(b,p), ca);
		if (ca != a && ca != b) {
			merge(a, b + n, p);
			merge(b, a + n, p);
			merge(a, b, pp);
		}
	}
	if (!valid()) return !printf("0");
	for (int i = 2; i <= n; i++) {
		if (find(i, pp) == i) ans = ans * 2 % mod;
	}
	printf("%lld", ans);

	return 0;
}