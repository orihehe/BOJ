/*
BOJ 14627 (https://www.acmicpc.net/problem/14627)
�̺�Ž���� �̿��Ͽ� �� ġŲ�� ���� ���� ���� ���� �ִ� ũ�⸦ ���Ѵ�.
���� ���� ���ϰ� �ĵ鿡�� �� ���� ���� � ������ �� �� 
��ǥġ���� ���� ���´ٸ� ���� ���� ���̰�, ���� ���´ٸ� ���� ���� �ø���.
�ִ� ũ��� �־��� �� ���� ���� ������ ġŲ�� ������ ���� �� �����Ƿ� ����ؼ� ������ش�. 
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[1000001];
int main() {
	ll s, c, left, right, mid, ramen = 0, cnt, ans, acnt;
	scanf("%lld %lld", &s, &c);
	for (int i = 0; i < s; i++) {
		scanf("%lld", &arr[i]);
	}
	acnt = c;
	sort(arr, arr + s);
	left = 1, right = arr[s - 1];
	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int i = 0; i < s; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < c) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid; acnt = cnt;
		}
	}
	for (int i = 0; i < s; i++) {
		ramen += arr[i] % ans;
	}
	printf("%lld", (acnt - c)*ans + ramen);
	return 0;
}