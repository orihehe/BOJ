/*
BOJ 17499 - 수열과 시프트 쿼리
https://www.acmicpc.net/problem/17499
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[200001];
int main() {
	int n, q, loc = 0, x, cm;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	while (q--) {
		scanf("%d %d", &cm, &x);
		if (cm == 1) {
			int tt;
			scanf("%d", &tt);
			x--;
			arr[(loc + x) % n] += tt;
		}
		else if (cm == 2) {
			loc = (loc - x + n) % n;
		}
		else {
			loc = (loc + x + n) % n;
		}
	}
	for (int i = loc; i < n; i++) printf("%d ", arr[i]);
	for (int i = 0; i < loc; i++) printf("%d ", arr[i]);

	return 0;
}