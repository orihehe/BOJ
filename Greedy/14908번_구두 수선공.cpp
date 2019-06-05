/*
BOJ 14908 - 구두 수선공
https://www.acmicpc.net/problem/14908

a,b의 작업이 있을 때 어느 하나를 먼저 했을 때 돈을 더 많이 지불해야 하는 것을 앞으로 보낸다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
struct info {
	int t, s, idx;
};
info arr[1001];
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr[i] = { a,b,i + 1 };
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j].s*arr[j + 1].t < arr[j + 1].s*arr[j].t) swap(arr[j + 1], arr[j]);
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", arr[i].idx);

	return 0;
}