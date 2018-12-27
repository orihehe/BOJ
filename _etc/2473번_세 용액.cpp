/*
���� 2473 (https://www.acmicpc.net/problem/2473)
�� ��� �������� �߰����� �߰��� �����ش�.
0~n�� ������ ������ �߰����� ���Ͽ� ������ ������ l,r���� �����ش�.
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
			// �߰����� �ƴ϶�� break
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