/*
BOJ 3079 (https://www.acmicpc.net/problem/3079)
�Ա� �ɻ翡 �ɸ��� �ð��� �̺�Ž������ ã�´�.
r���� �ð� �ִ�*����� �ɸ� �� �ִ� �ִ� �ð����� �����Ѵ�.
mid���� ���� �ɻ縦 �� �� �ִ� ����� ���� �ɻ��ؾ� �� ������� ũ�ų� ���� ���� �ð� �� �ּҰ� �����ش�.
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