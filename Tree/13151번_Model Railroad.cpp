/*
BOJ 13151 - Model Railroad
https://www.acmicpc.net/problem/13151
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
struct edge {
	int v, u, val;
} arr[250000];
int p[50001];
int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
int main() {
	int n, m, k, sum = 0;
	scanf("%d %d %d", &n, &m, &k);
	memset(p, -1, sizeof(p));
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].val);
		sum += arr[i].val;
	}
	for (int i = k; i < m; i++) {
		scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].val);
	}
	sort(arr, arr + m, [](edge a, edge b) { return a.val < b.val; });
	int cnt = 0, ss = 0;
	for (int i = 0; i < m; i++) {
		if (cnt == n - 1) break;
		if (find(arr[i].v) == find(arr[i].u)) continue;
		cnt++;
		ss += arr[i].val;
		merge(arr[i].v, arr[i].u);
	}
	if (cnt == n - 1 && sum >= ss) printf("possible");
	else printf("impossible");

	return 0;
}