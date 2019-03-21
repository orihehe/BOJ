/*
BOJ 15352 - 욱제와 그의 팬들
https://www.acmicpc.net/problem/15352

원소들의 왼쪽 오른쪽을 가리키게 구조체를 만들어준다.
삭제연산시 내 왼쪽 원소의 오른쪽에 내 오른쪽을, 오른쪽 원소의 왼쪽에 내 왼쪽을 저장
사이즈에서 내가 빠지니 1감소, 만약 오른쪽 왼쪽이 같다면 merge해준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct wj {
	int l, r, val;
};
int sz[1000001], p[1000001];
wj arr[1000001];
int find(int a) {
	if (a == p[a])return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int main() {
	int k, n, q, cm, x;
	ll ans = 0;
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].val);
		arr[i].l = i - 1; arr[i].r = i + 1;
		sz[i] = 1;
		p[i] = i;
		if (arr[i - 1].val == arr[i].val) merge(i - 1, i);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &cm, &x);
		if (cm == 1) {
			sz[find(x)]--;
			arr[arr[x].l].r = arr[x].r;
			arr[arr[x].r].l = arr[x].l;
			if (arr[arr[x].r].val == arr[arr[x].l].val) merge(arr[x].l, arr[x].r);
		}
		else if (cm == 2) {
			ans += sz[find(x)];
		}
	}
	printf("%lld", ans);

	return 0;
}