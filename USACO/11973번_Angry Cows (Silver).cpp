/*
BOJ 11973 (https://www.acmicpc.net/problem/11973)

mid를 R값(반지름)으로 잡고 이분탐색을 해서 k번 안에 모두 지울 수 있는지 확인
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[50000];
int main() {
	int n, l, r, mid, k, cnt, ans, ap;
	scanf("%d %d", &n, &k);
	l = 1, r = 1000000000;
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	sort(arr, arr + n);
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		ap = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[ap] > mid * 2) {
				cnt++;
				ap = i;
			}
		}
		if (cnt + 1 > k) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%d", ans);

	return 0;
}