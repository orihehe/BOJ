/*
BOJ 1300 (https://www.acmicpc.net/problem/1300)

mid���� k��° ���� �����Ͽ� �̺�Ž�����ش�.
k���� �̻��� �� mid���� ����
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	ll cnt, k, l, r, mid, ans, n;
	scanf("%lld %lld", &n, &k);
	l = 1, r = n * n;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(n, mid / i);
		}
		if (cnt >= k) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%lld", ans);

	return 0;
}