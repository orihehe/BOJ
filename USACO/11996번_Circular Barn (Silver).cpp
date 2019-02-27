/*
BOJ 11996 (https://www.acmicpc.net/problem/11996)
BOJ(11993) Gold번 풀이와 같다. 에너지 계산하는 부분 구현만 다름
*/
#include <cstdio>
#include <queue>
using namespace std;

/* 🐣🐥 */
int arr[1001];
bool one[1001];
int cnt, ap, sp, ans;
bool suc;
int main() {
	int n, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	do {
		if (!one[ap] && arr[ap] > 1) {
			cnt += arr[ap] - 1;
			one[ap] = true;
		}
		else if (arr[ap] == 0 && !one[ap] && cnt > 0) {
			cnt--;
			one[ap] = true;
		}
		ap = (++ap) % n;
		if (ap == 0) suc = true;
	} while (!suc || cnt > 0);
	end = ap--;
	if (ap < 0) ap = n - 1;
	while (ap != end) {
		sp = (ap - 1 + n) % n;
		cnt = 0;
		while (!arr[ap]) {
			cnt++;
			if (arr[sp] > 0) {
				arr[sp]--;
				arr[ap] = 1;
				break;
			}
			sp = (--sp + n) % n;
		}
		ans += cnt * cnt;
		ap = (--ap + n) % n;
	}
	printf("%d", ans);

	return 0;
}