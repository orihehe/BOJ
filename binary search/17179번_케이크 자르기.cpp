/*
BOJ 17179 - 케이크 자르기
https://www.acmicpc.net/problem/17179

가장 작은 조각의 길이를 mid값으로 두고 이분탐색, q이상의 개수로 자를 수 있는지를 봐준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[1000];
int main() {
	int n, m, x, q, l, r, mid, dd, tmp, ans;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
	}
	while (n--) {
		scanf("%d", &q);
		l = 1, r = x;
		while (l <= r) {
			dd = 0, tmp = 0;
			mid = (l + r) / 2;
			for (int i = 0; i < m; i++) {
				if (arr[i] - dd >= mid && x - arr[i] >= mid) {
					tmp++;
					dd = arr[i];
				}
			}
			if (tmp >= q) {
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}