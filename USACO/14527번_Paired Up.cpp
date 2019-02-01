/*
BOJ 14527 (https://www.acmicpc.net/problem/14527)

�� ���� �յ� �� �ִ��� �ּҰ� �ǵ��� �ؾ���, �ð����� ���� �� �յڸ� ¦�����ش�.
�ҵ��� �� ���� 10���̹Ƿ� �Ѹ����� ������ �ʰ� �����̷� ���ش�.
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

pii arr[100001];
int main() {
	int n, a, b, l, r, lt, rt, maxT = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr[i] = { b,a };
	}
	sort(arr, arr + n);
	l = 0, r = n - 1, lt = arr[l].second, rt = arr[r].second;
	while (l <= r) {
		maxT = max(maxT, arr[l].first + arr[r].first);
		if (arr[l].second > arr[r].second) {
			arr[l].second -= arr[r].second;
			r--;
		}
		else if (arr[l].second == arr[r].second) {
			l++, r--;
		}
		else {
			arr[r].second -= arr[l].second;
			l++;
		}
	}
	printf("%d", maxT);

	return 0;
}