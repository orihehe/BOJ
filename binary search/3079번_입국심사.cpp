/*
BOJ 3079 (https://www.acmicpc.net/problem/3079)
입국 심사에 걸리는 시간을 이분탐색으로 찾는다.
r값은 시간 최댓값*명수로 걸릴 수 있는 최대 시간으로 설정한다.
mid값에 따라 심사를 할 수 있는 명수를 세서 심사해야 할 사람보다 크거나 같을 때의 시간 중 최소값 구해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[100001];
int main() {
	int n, m;
	ll l, r, mid, cnt, res;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	l = 1, r = arr[n - 1] * m;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / arr[i];
		}
		if (cnt >= m) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%lld", res);

	return 0;
}