/*
BOJ 16562 - 친구비
https://www.acmicpc.net/problem/16562

유니온 파인드로 친구의 친구끼리 묶어주고 그 친구 그룹의 최솟값만 더해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[10001], p[10001];
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	p[a] = b;
	arr[b] = min(arr[b], arr[a]);
}
int main() {
	int n, m, k, a, b, ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		p[i] = i;
	}
	while (m--) {
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) ans += arr[i];
	}
	if (ans > k) printf("Oh no");
	else printf("%d", ans);

	return 0;
}