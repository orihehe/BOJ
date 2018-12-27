/*
백준 2473 (https://www.acmicpc.net/problem/2473)
두 용액 문제에서 중간값만 추가로 정해준다.
0~n의 각각의 고정된 중간값에 대하여 절댓값이 감소할 l,r값을 정해준다.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[5000], mix = 3000000001, m[3];
int main() {
	int l, r, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		l = 0; r = n - 1;
		while (l != r) {
			// 중간값이 아니라면 break
			if (i <= l || i >= r) break;
			ll tmp = arr[l] + arr[r] + arr[i];
			if (llabs(tmp) < mix) {
				mix = llabs(tmp);
				m[0] = arr[l], m[1] = arr[i], m[2] = arr[r];
			}
			if (tmp < 0) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	sort(m, m + 3);
	printf("%lld %lld %lld", m[0], m[1], m[2]);

	return 0;
}