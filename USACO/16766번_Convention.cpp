/*
BOJ 16766 (https://www.acmicpc.net/problem/16766)

�ִ� ���� ���� mid�� �ΰ� �̺�Ž���� ������.
�׶� ���� �ִ��ο� ���ϸ�ŭ, mid���� ���ϸ�ŭ �¿��
���� ������ �ʰ����� �ʴ� ���� ū ���� ã���ش�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int cow[100001];
int main() {
	int n, m, c, ans, l, r, mid, cnt;
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cow[i]);
	}
	sort(cow, cow + n);
	l = 0; r = 1000000000;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 0; i < n; ) {
			int ti = i;
			while (ti - i + 1 <= c && cow[ti] - cow[i] <= mid)
				ti++;
			i = ti;
			cnt++;
		}
		if (cnt > m) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	printf("%d", ans);

	return 0;
}