/*
BOJ 16909 - 카드 구매하기 3
https://www.acmicpc.net/problem/16909
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[1000002];
int p[1000002], sz[1000002];
bool visited[1000002];
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
int main() {
	int n;
	ll mx = 0, mn = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) {
		int cur, l, r, ii;
		cur = arr[i].second, ii = arr[i].first;
		l = find(cur - 1), r = find(cur + 1);
		visited[cur] = true;
		if (visited[l] && visited[r]) {
			mx += 1LL * sz[l] * sz[r] * ii + 1LL * sz[l] * ii + 1LL * sz[r] * ii;
			merge(l, cur);
			merge(l, r);
		}
		else if (visited[l]) {
			mx += 1LL * sz[l] * ii;
			merge(l, cur);
		}
		else if (visited[r]) {
			mx += 1LL * sz[r] * ii;
			merge(cur, r);
		}
	}

	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1, visited[i] = false;
	for (int i = n; i >= 1; i--) {
		int cur = arr[i].second, l, r, ii = arr[i].first;
		l = find(cur - 1), r = find(cur + 1);
		visited[cur] = true;
		if (visited[l] && visited[r]) {
			mn += 1LL * sz[l] * sz[r] * ii + 1LL * sz[l] * ii + 1LL * sz[r] * ii;
			merge(l, cur);
			merge(l, r);
		}
		else if (visited[l]) {
			mn += 1LL * sz[l] * ii;
			merge(l, cur);
		}
		else if (visited[r]) {
			mn += 1LL * sz[r] * ii;
			merge(cur, r);
		}
	}

	printf("%lld", mx - mn);

	return 0;
}