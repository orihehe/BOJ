/*
BOJ 15565 (https://www.acmicpc.net/problem/15565)

라이언 인형 개수를 만족할 때 최대 길이를 구하는 문제
라이언 개수가 부족하면 오른쪽을 늘리고, 아니라면 왼쪽을 줄여준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[1000000];
int main() {
	int k, n, ans = 987654321, cnt = 0, l, r;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	l = r = 0;
	while (l <= r) {
		if (r<n && cnt < k) { // 카운트 부족하면
			if (arr[r] == 1)cnt++;
			r++;
		}
		else {
			if (arr[l] == 1)cnt--;
			l++;
		}
		if (cnt == k) ans = min(ans, r - l);
	}
	if (ans == 987654321) printf("-1");
	else printf("%d", ans);

	return 0;
}