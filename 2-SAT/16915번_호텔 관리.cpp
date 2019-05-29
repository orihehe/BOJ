/*
BOJ 16915 - 호텔 관리
https://www.acmicpc.net/problem/16915

방이 열려있다면 스위치 둘 다 눌리거나, 둘 다 안 눌려야 함 (xor not - friend merge)
방이 닫혀있다면 스위치 두 개중 하나만 꼭 눌려야함 (xor - enemy merge)
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int n, m, p[200001], arr[100001];
pii swc[100001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
bool isValid() {
	for (int i = 1; i <= m; i++) {
		if (find(i) == find(i + m)) return false;
	}
	return true;
}
int main() {
	int k, x;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= 2 * m; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &x);
			if (!swc[x].first) swc[x].first = i;
			else swc[x].second = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i]) {
			merge(swc[i].first, swc[i].second);
			merge(swc[i].first + m, swc[i].second + m);
		}
		else {
			merge(swc[i].first, swc[i].second + m);
			merge(swc[i].first + m, swc[i].second);
		}
	}
	printf("%d\n", isValid() ? 1 : 0);

	return 0;
}